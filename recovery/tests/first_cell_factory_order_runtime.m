#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "../source/Models/DVNCell.h"
static NSMutableArray *events;
static NSMutableDictionary *originals;
static unsigned checks,failures;
static void record(id self,SEL sel,id value) {
    [events addObject:NSStringFromSelector(sel)];
    ((void (*)(id,SEL,id))[originals[NSStringFromSelector(sel)] pointerValue])(self,sel,value);
}
static void recordInteger(id self,SEL sel,NSInteger value) {
    [events addObject:NSStringFromSelector(sel)];
    ((void (*)(id,SEL,NSInteger))[originals[NSStringFromSelector(sel)] pointerValue])(self,sel,value);
}
static void recordDouble(id self,SEL sel,double value) {
    [events addObject:NSStringFromSelector(sel)];
    ((void (*)(id,SEL,double))[originals[NSStringFromSelector(sel)] pointerValue])(self,sel,value);
}
static void recordBool(id self,SEL sel,BOOL value) {
    [events addObject:NSStringFromSelector(sel)];
    ((void (*)(id,SEL,BOOL))[originals[NSStringFromSelector(sel)] pointerValue])(self,sel,value);
}
@interface FactorySubclass : DVNCell @end
@implementation FactorySubclass @end
int main(int argc,const char **argv) {
    @autoreleasepool {
        if (argc!=2) return 2;
        NSDictionary *manifest=[NSJSONSerialization JSONObjectWithData:[NSData dataWithContentsOfFile:@(argv[1])] options:0 error:NULL];
        if (!manifest) return 2;
        events=[NSMutableArray new];originals=[NSMutableDictionary new];
        unsigned count=0;Method *methods=class_copyMethodList([DVNCell class],&count);
        for (unsigned i=0;i<count;i++) {
            Method method=methods[i];SEL sel=method_getName(method);NSString *name=NSStringFromSelector(sel);
            if (![name hasPrefix:@"set"] || ![name hasSuffix:@":"]) continue;
            char *type=method_copyArgumentType(method,2);
            IMP replacement=type[0]=='d'?(IMP)recordDouble:type[0]=='q'?(IMP)recordInteger:type[0]=='B'?(IMP)recordBool:(IMP)record;
            free(type);originals[name]=[NSValue valueWithPointer:method_getImplementation(method)];
            method_setImplementation(method,replacement);
        }
        free(methods);
        NSArray *factories=manifest[@"factories"];
        for (NSDictionary *row in factories) {
            NSString *name=row[@"method"][@"selector"];
            NSArray *expected=[row[@"selectors"] valueForKey:@"name"];
            if (!expected.count) {
                for (NSDictionary *other in factories) if ([other[@"method"][@"selector"] isEqual:@"sliderCellWithMinimum:maximum:divider:format:key:"]) expected=[other[@"selectors"] valueForKey:@"name"];
            }
            for (Class receiver in @[[DVNCell class],[FactorySubclass class]]) for (unsigned nilArguments=0;nilArguments<2;nilArguments++) {
                @autoreleasepool {
                    SEL selector=NSSelectorFromString(name);
                    NSMethodSignature *signature=[receiver methodSignatureForSelector:selector];
                    NSInvocation *invocation=[NSInvocation invocationWithMethodSignature:signature];invocation.target=receiver;invocation.selector=selector;
                    NSMutableArray *keepAlive=[NSMutableArray new];
                    for (NSUInteger index=2;index<signature.numberOfArguments;index++) {
                        const char *type=[signature getArgumentTypeAtIndex:index];
                        if (type[0]=='d') { double v=(double)index+0.125;[invocation setArgument:&v atIndex:index]; }
                        else if (type[0]=='q') { NSInteger v=0x1234567800000000LL+index;[invocation setArgument:&v atIndex:index]; }
                        else {
                            id value=nil;
                            if (!nilArguments) {
                                if (type[1]=='?') { NSUInteger capture=index;value=[^{(void)capture;} copy]; }
                                else value=[NSString stringWithFormat:@"arg-%lu",(unsigned long)index];
                                [keepAlive addObject:value];
                            }
                            [invocation setArgument:&value atIndex:index];
                        }
                    }
                    [events removeAllObjects];[invocation invoke];
                    __unsafe_unretained id result;[invocation getReturnValue:&result];
                    checks++;if (![events isEqual:expected]) { failures++;fprintf(stderr,"FAIL %s: expected %s, got %s\n",name.UTF8String,expected.description.UTF8String,events.description.UTF8String); }
                    checks++;if (object_getClass(result)!=[DVNCell class]) { failures++;fprintf(stderr,"FAIL %s: concrete result class\n",name.UTF8String); }
                    (void)keepAlive;
                }
            }
        }
        printf("%s First_cell_factory_order: %u assertions, %u failures\n",failures?"FAIL":"PASS",checks,failures);
    }
    return failures?1:0;
}
