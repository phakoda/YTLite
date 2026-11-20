#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "../source/Models/DVNCell.h"
static unsigned checks,failures,initializations;
static BOOL watching,nilResult;
static NSMutableArray *events,*keepers;
static NSDictionary *values;
static id replacement;
static NSString *context;
static IMP oldInit;
static void Check(BOOL ok,NSString *label) {checks++;if(!ok){failures++;fprintf(stderr,"FAIL %s: %s\n",context.UTF8String,label.UTF8String);}}
@interface FactoryArgument : NSObject
@property(nonatomic) NSUInteger index;
@end
@implementation FactoryArgument
- (void)dealloc {if(watching)[events addObject:@[@"release",@(_index)]];}
@end
@interface FactoryRecorder : NSObject @end
@implementation FactoryRecorder @end
@interface FactoryChild : DVNCell @end
@implementation FactoryChild @end
static void Record(SEL sel,uint64_t bits) {[events addObject:@[@"set",NSStringFromSelector(sel),@(bits)]];}
static void ObjectSetter(id self,SEL sel,id arg) {(void)self;Record(sel,(uintptr_t)(__bridge void *)arg);}
static void BoolSetter(id self,SEL sel,BOOL arg) {(void)self;Record(sel,(uint64_t)arg);}
static void IntegerSetter(id self,SEL sel,NSInteger arg) {(void)self;Record(sel,(uint64_t)arg);}
static void DoubleSetter(id self,SEL sel,double arg) {(void)self;uint64_t bits;memcpy(&bits,&arg,8);Record(sel,bits);}
typedef id (*InitFunction)(id __attribute__((ns_consumed)),SEL) __attribute__((ns_returns_retained));
static id FactoryInit(id self __attribute__((ns_consumed)),SEL sel) __attribute__((ns_returns_retained));
static id FactoryInit(id self __attribute__((ns_consumed)),SEL sel) {
    if(!watching)return ((InitFunction)oldInit)(self,sel);
    initializations++;Check(object_getClass(self)==DVNCell.class,@"factory allocates concrete DVNCell");
    [events addObject:@[@"construct"]];
    // Input references held by the caller disappear during construction. The
    // actual factory must retain them until each corresponding setter returns.
    [keepers removeAllObjects];
    return nilResult?nil:replacement;
}
static id Evaluate(NSArray *value) {return [value[0] isEqual:@"constant"]?value[1]:values[value[1]];}
static NSArray *Expected(NSDictionary *contract,BOOL nilArguments) {
    NSMutableArray *result=[NSMutableArray new];
    for(NSArray *event in contract[@"events"]) {
        if([event[0] isEqual:@"construct"]) [result addObject:@[@"construct"]];
        else if([event[0] isEqual:@"set"]&&!nilResult) [result addObject:@[@"set",event[1],Evaluate(event[2])]];
        else if([event[0] isEqual:@"release"]&&!nilArguments) [result addObject:@[@"release",event[1][1]]];
    }
    return result;
}
@interface ForwardingChild : DVNCell @end
@implementation ForwardingChild
+ (instancetype)sliderCellWithMinimum:(double)minimum maximum:(double)maximum divider:(double)divider format:(NSInteger)format key:(NSString *)key {
    uint64_t a,b,c;memcpy(&a,&minimum,8);memcpy(&b,&maximum,8);memcpy(&c,&divider,8);
    [events addObject:@[@"forward",@(a),@(b),@(c),@((uint64_t)format),@((uintptr_t)(__bridge void *)key)]];
    return nilResult?nil:replacement;
}
@end
static uint64_t ScalarBits(NSUInteger index,unsigned pattern,BOOL floating) {
    if(!floating)return pattern?((uint64_t)LLONG_MIN+index):0x1234567800000000ULL+index;
    const uint64_t patterns[]={0x8000000000000000ULL,0x7ff8123456789abcULL,1,0xfff0000000000000ULL,0x3ff0000000000001ULL,0x7fefffffffffffffULL};
    return patterns[(index+pattern)%6];
}
int main(int argc,const char **argv) {
    @autoreleasepool {
        if(argc!=2)return 2;
        NSDictionary *manifest=[NSJSONSerialization JSONObjectWithData:[NSData dataWithContentsOfFile:@(argv[1])] options:0 error:NULL];if(!manifest)return 2;
        events=[NSMutableArray new];keepers=[NSMutableArray new];
        unsigned count;Method *methods=class_copyMethodList(DVNCell.class,&count);
        for(unsigned i=0;i<count;i++) {
            SEL sel=method_getName(methods[i]);NSString *name=NSStringFromSelector(sel);
            if(![name hasPrefix:@"set"]||![name hasSuffix:@":"])continue;
            char *type=method_copyArgumentType(methods[i],2);
            IMP imp=type[0]=='d'?(IMP)DoubleSetter:type[0]=='q'?(IMP)IntegerSetter:type[0]=='B'?(IMP)BoolSetter:(IMP)ObjectSetter;
            class_addMethod(FactoryRecorder.class,sel,imp,method_getTypeEncoding(methods[i]));free(type);
        }
        free(methods);Method init=class_getInstanceMethod(DVNCell.class,@selector(init));oldInit=method_setImplementation(init,(IMP)FactoryInit);
        for(NSDictionary *row in manifest[@"factories"]) {
            context=row[@"method"][@"selector"];NSDictionary *contract=row[@"contract"];
            if([context isEqual:@"sliderCellWithMinimum:maximum:divider:key:"])continue;
            for(Class receiver in @[DVNCell.class,FactoryChild.class]) for(unsigned empty=0;empty<2;empty++) for(unsigned pattern=0;pattern<2;pattern++) for(unsigned nilInit=0;nilInit<2;nilInit++) {
                @autoreleasepool {
                    watching=NO;nilResult=nilInit;initializations=0;[events removeAllObjects];[keepers removeAllObjects];replacement=[FactoryRecorder new];
                    NSInvocation *call=[NSInvocation invocationWithMethodSignature:[receiver methodSignatureForSelector:NSSelectorFromString(context)]];
                    call.target=receiver;call.selector=NSSelectorFromString(context);
                    NSMutableDictionary *argumentBits=[NSMutableDictionary new];
                    for(NSUInteger index=2;index<call.methodSignature.numberOfArguments;index++) {
                        const char *type=[call.methodSignature getArgumentTypeAtIndex:index];
                        if(type[0]=='d'||type[0]=='q') {
                            uint64_t bits=ScalarBits(index,pattern,type[0]=='d');argumentBits[@(index)]=@(bits);[call setArgument:&bits atIndex:index];
                        } else {
                            id argument=nil;
                            if(!empty) {
                                FactoryArgument *token=[FactoryArgument new];token.index=index;
                                if(type[1]=='?') {FactoryArgument *captured=token;argument=[^{(void)[captured class];} copy];}
                                else argument=token;
                                [keepers addObject:argument];token=nil;
                            }
                            argumentBits[@(index)]=@((uintptr_t)(__bridge void *)argument);[call setArgument:&argument atIndex:index];argument=nil;
                        }
                    }
                    values=argumentBits;NSArray *expected=Expected(contract,empty);
                    watching=YES;[call invoke];watching=NO;
                    __unsafe_unretained id rawResult;[call getReturnValue:&rawResult];
                    Check(initializations==1,@"one initializer call");Check(nilInit?rawResult==nil:rawResult==replacement,@"initializer result forwarded unchanged");
                    Check([events isEqual:expected],[NSString stringWithFormat:@"exact argument and release trace; expected %@, got %@",expected,events]);
                    Check(keepers.count==0,@"caller references released during construction");replacement=nil;values=nil;
                }
            }
        }
        // A subclass override must receive the short factory's receiver and all
        // forwarded arguments. Its nil or nonnil result passes through unchanged.
        context=@"slider forwarding override";
        for(unsigned empty=0;empty<2;empty++) for(unsigned pattern=0;pattern<6;pattern++) for(unsigned nilReturn=0;nilReturn<2;nilReturn++) {
            [events removeAllObjects];nilResult=nilReturn;replacement=[FactoryRecorder new];id key=empty?nil:[NSObject new];
            uint64_t a=ScalarBits(2,pattern,YES),b=ScalarBits(3,pattern,YES),c=ScalarBits(4,pattern,YES);double minimum,maximum,divider;
            memcpy(&minimum,&a,8);memcpy(&maximum,&b,8);memcpy(&divider,&c,8);
            id result=[ForwardingChild sliderCellWithMinimum:minimum maximum:maximum divider:divider key:key];
            Check(nilReturn?result==nil:result==replacement,@"forwarded nil or replacement result");
            Check([events isEqual:@[@[@"forward",@(a),@(b),@(c),@0,@((uintptr_t)(__bridge void *)key)]]],@"receiver override, exact doubles, zero format and key identity");replacement=nil;
        }
        method_setImplementation(init,oldInit);
        printf("%s First_cell_factories: %u assertions, %u failures\n",failures?"FAIL":"PASS",checks,failures);
    }
    return failures?1:0;
}
