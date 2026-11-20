#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "../source/Models/DVNCell.h"
#include <stdint.h>
#include <string.h>
#include <limits.h>

static unsigned checks, failures;
static NSString *context;
#define CHECK(test, message) do { checks++; if (!(test)) { failures++; fprintf(stderr,"FAIL %s: %s\n",context.UTF8String,message); } } while(0)

@interface AccessorToken : NSObject <NSCopying>
@property(nonatomic, strong) id resultValue;
@property(nonatomic, copy) void (^onDealloc)(void);
@property(nonatomic) unsigned copies;
@end
@implementation AccessorToken
- (id)copyWithZone:(NSZone *)zone { (void)zone; self.copies++; return self.resultValue; }
- (void)dealloc { if (_onDealloc) _onDealloc(); }
@end

static uintptr_t rawSlot(uintptr_t owner, ptrdiff_t offset) {
    uintptr_t result; memcpy(&result,(const void *)(owner+offset),sizeof(result)); return result;
}
static id getObject(id cell, SEL sel) {
    return ((id (*)(id,SEL))class_getMethodImplementation([DVNCell class],sel))(cell,sel);
}
static void setObject(id cell, SEL sel, id value) {
    ((void (*)(id,SEL,id))class_getMethodImplementation([DVNCell class],sel))(cell,sel,value);
}
static void checkObject(id cell, SEL sel, id expected) {
    @autoreleasepool { CHECK(getObject(cell,sel)==expected,"object getter identity"); }
}

static void objectCases(id cell, SEL getter, SEL setter, NSString *operation, ptrdiff_t offset) {
    uintptr_t owner=(uintptr_t)(__bridge void *)cell;
    checkObject(cell,getter,nil);
    if (!setter) {
        NSObject *token=[NSObject new];
        [cell setValue:token forKey:@"_reuseIdentifier"];
        checkObject(cell,getter,token);
        [cell setValue:nil forKey:@"_reuseIdentifier"];
        checkObject(cell,getter,nil);
        return;
    }
    if ([operation isEqual:@"weak-set"]) {
        __weak id firstWeak, secondWeak;
        @autoreleasepool {
            NSObject *first=[NSObject new], *second=[NSObject new];
            firstWeak=first; secondWeak=second;
            setObject(cell,setter,first); checkObject(cell,getter,first);
            setObject(cell,setter,second); checkObject(cell,getter,second);
            first=nil; CHECK(firstWeak==nil,"weak replacement does not retain previous value");
            checkObject(cell,getter,second);
            second=nil;
        }
        CHECK(secondWeak==nil,"weak property does not retain value");
        checkObject(cell,getter,nil);
        setObject(cell,setter,nil); checkObject(cell,getter,nil);
        return;
    }
    if ([operation isEqual:@"copy-set"]) {
        __weak id sourceWeak, resultWeak;
        @autoreleasepool {
            AccessorToken *source=[AccessorToken new]; NSObject *result=[NSObject new];
            source.resultValue=result; sourceWeak=source; resultWeak=result;
            setObject(cell,setter,source);
            CHECK(source.copies==1,"copy setter invokes copy exactly once");
            checkObject(cell,getter,result);
            CHECK(rawSlot(owner,offset)==(uintptr_t)(__bridge void *)result,"copy result stored in original slot");
            source=nil; result=nil;
        }
        CHECK(sourceWeak==nil,"copy setter does not retain source");
        CHECK(resultWeak!=nil,"copy setter retains copied result");
        setObject(cell,setter,nil);
        CHECK(resultWeak==nil,"clearing copy property releases result");
        checkObject(cell,getter,nil);
        @autoreleasepool {
            AccessorToken *source=[AccessorToken new];
            setObject(cell,setter,source);
            CHECK(source.copies==1,"nil copy result still invokes copy");
            checkObject(cell,getter,nil);
        }
        // Test real block ownership without assuming or invoking recovered callback signatures.
        __weak id capturedWeak;
        @autoreleasepool {
            NSObject *captured=[NSObject new]; capturedWeak=captured;
            void (^block)(void)=^{ (void)[captured class]; };
            setObject(cell,setter,block);
            CHECK(getObject(cell,getter)!=nil,"real block is stored");
        }
        CHECK(capturedWeak!=nil,"stored block retains capture after scope exits");
        setObject(cell,setter,nil);
        CHECK(capturedWeak==nil,"clearing block releases capture");
        return;
    }
    __weak id oldWeak, newWeak;
    __block unsigned oldDeaths=0, newDeaths=0;
    AccessorToken *replacement=[AccessorToken new];
    uintptr_t next=(uintptr_t)(__bridge void *)replacement;
    @autoreleasepool {
        AccessorToken *old=[AccessorToken new]; oldWeak=old;
        old.onDealloc=^{ oldDeaths++; CHECK(rawSlot(owner,offset)==next,"new value stored before old value released"); };
        setObject(cell,setter,old); checkObject(cell,getter,old);
        CHECK(rawSlot(owner,offset)==(uintptr_t)(__bridge void *)old,"strong value stored in original slot");
        setObject(cell,setter,old); checkObject(cell,getter,old);
        old=nil;
    }
    CHECK(oldWeak!=nil && oldDeaths==0,"strong property owns value after local release");
    replacement.onDealloc=^{ newDeaths++; CHECK(rawSlot(owner,offset)==0,"nil stored before replacement released"); };
    newWeak=replacement;
    setObject(cell,setter,replacement);
    CHECK(oldWeak==nil && oldDeaths==1,"replacement releases old value");
    checkObject(cell,getter,replacement);
    replacement=nil;
    CHECK(newWeak!=nil && newDeaths==0,"strong property owns replacement");
    setObject(cell,setter,nil);
    CHECK(newWeak==nil && newDeaths==1,"nil releases replacement");
    checkObject(cell,getter,nil);
}

int main(int argc, const char **argv) {
    @autoreleasepool {
        if (argc!=2) return 2;
        NSDictionary *manifest=[NSJSONSerialization JSONObjectWithData:[NSData dataWithContentsOfFile:@(argv[1])] options:0 error:NULL];
        if (!manifest) return 2;
        NSArray *rows=manifest[@"accessors"];
        CHECK(rows.count==63,"expected complete accessor set");
        for (NSDictionary *row in rows) {
            NSString *selector=row[@"method"][@"selector"];
            if ([selector hasSuffix:@":"]) continue;
            context=row[@"property"][@"name"];
            NSDictionary *setterRow=nil;
            for (NSDictionary *candidate in rows) if ([candidate[@"property"][@"name"] isEqual:context] && [candidate[@"method"][@"selector"] hasSuffix:@":"]) setterRow=candidate;
            SEL getter=NSSelectorFromString(selector), setter=setterRow ? NSSelectorFromString(setterRow[@"method"][@"selector"]) : NULL;
            NSDictionary *ivar=row[@"ivar"];
            ptrdiff_t offset=[ivar[@"offset"] longLongValue];
            Ivar actual=class_getInstanceVariable([DVNCell class],[ivar[@"name"] UTF8String]);
            CHECK(actual && ivar_getOffset(actual)==offset,"original ivar offset");
            // alloc only: initializer and factory semantics are outside this audit.
            DVNCell *cell=[DVNCell alloc];
            NSString *type=ivar[@"encoding"];
            uint8_t *base=(uint8_t *)(__bridge void *)cell;
            if ([type isEqual:@"d"]) {
                double (*get)(id,SEL)=(void *)class_getMethodImplementation([DVNCell class],getter);
                void (*set)(id,SEL,double)=(void *)class_getMethodImplementation([DVNCell class],setter);
                const uint64_t patterns[]={0,0x8000000000000000ULL,0x7ff0000000000000ULL,0xfff0000000000000ULL,0x7ff8123456789abcULL,1,0x8000000000000001ULL,0x3ff0000000000001ULL,0x7fefffffffffffffULL,0xc00123456789abcdULL};
                for (unsigned i=0;i<sizeof(patterns)/sizeof(*patterns);i++) {
                    double value; uint64_t observed;
                    memcpy(&value,&patterns[i],8); set(cell,setter,value);
                    memcpy(&observed,base+offset,8); CHECK(observed==patterns[i],"double setter preserves bits at exact slot");
                    double got=get(cell,getter); memcpy(&observed,&got,8); CHECK(observed==patterns[i],"double getter preserves bits");
                    uint64_t independent=patterns[(i+1)%(sizeof(patterns)/sizeof(*patterns))];
                    memcpy(base+offset,&independent,8); got=get(cell,getter); memcpy(&observed,&got,8);
                    CHECK(observed==independent,"double getter reads independently seeded slot");
                }
            } else if ([type isEqual:@"q"]) {
                NSInteger (*get)(id,SEL)=(void *)class_getMethodImplementation([DVNCell class],getter);
                void (*set)(id,SEL,NSInteger)=(void *)class_getMethodImplementation([DVNCell class],setter);
                const NSInteger values[]={0,1,-1,INT_MAX,(NSInteger)INT_MAX+1,INT_MIN,(NSInteger)INT_MIN-1,LLONG_MAX,LLONG_MIN,0x123456789abcdefLL};
                for (unsigned i=0;i<sizeof(values)/sizeof(*values);i++) {
                    NSInteger observed; set(cell,setter,values[i]); memcpy(&observed,base+offset,8);
                    CHECK(observed==values[i],"integer setter preserves full signed width");
                    CHECK(get(cell,getter)==values[i],"integer getter value");
                    NSInteger independent=values[(i+1)%(sizeof(values)/sizeof(*values))]; memcpy(base+offset,&independent,8);
                    CHECK(get(cell,getter)==independent,"integer getter reads independently seeded slot");
                }
            } else if ([type isEqual:@"B"]) {
                BOOL (*get)(id,SEL)=(void *)class_getMethodImplementation([DVNCell class],getter);
                void (*set)(id,SEL,BOOL)=(void *)class_getMethodImplementation([DVNCell class],setter);
                for (unsigned i=0;i<4;i++) {
                    BOOL value=(i%2)!=0; set(cell,setter,value);
                    CHECK(base[offset]==value,"boolean setter stores canonical byte"); CHECK(get(cell,getter)==value,"boolean getter value");
                    base[offset]=!value; CHECK(get(cell,getter)==!value,"boolean getter reads independently seeded slot");
                }
            } else objectCases(cell,getter,setter,setterRow[@"contract"][@"operation"],offset);
        }
        printf("%s First_model_accessors: %u assertions, %u failures\n",failures?"FAIL":"PASS",checks,failures);
    }
    return failures ? 1 : 0;
}
