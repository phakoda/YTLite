#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import <objc/message.h>
#import "../../Utils/YTLUserDefaults.h"
#import "../source/Hooks/ConfigurationHost.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
#include <limits.h>

static NSUInteger checks,originalCalls,gateCalls;
static BOOL originalResult,lastSetterValue;
static __weak id lastSelf;
static SEL lastSelector;
static NSString *lastGateKey;
static NSMutableDictionary *preferences;
static NSUserDefaults *defaults;
#define CHECK(c) do {checks++;if(!(c)){fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#c);exit(1);}}while(0)
BOOL ytpBool(NSString *key) {gateCalls++;lastGateKey=key;return [preferences[key] boolValue];}
NSInteger ytpInt(NSString *key) {CHECK(NO);return 0;}
static BOOL OriginalBool(id object,SEL selector) {originalCalls++;lastSelf=object;lastSelector=selector;return originalResult;}
static void OriginalSetter(id object,SEL selector,BOOL value) {originalCalls++;lastSelf=object;lastSelector=selector;lastSetterValue=value;}
static int OriginalInt(id object,SEL selector) {originalCalls++;lastSelf=object;lastSelector=selector;return -7;}
@implementation YTLUserDefaults
+ (YTLUserDefaults *)standardUserDefaults {return (YTLUserDefaults *)defaults;}
@end
// HOST_IMPLEMENTATIONS

int main(int argc,const char **argv) {@autoreleasepool {
    CHECK(argc==2);
    YTLInstallConfigurationEarlyHooks();
    YTLInstallConfigurationHooks();
    NSData *data=[NSData dataWithContentsOfFile:[NSString stringWithUTF8String:argv[1]]];
    NSDictionary *classes=[NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
    CHECK(classes.count==5);preferences=[NSMutableDictionary new];
    NSString *suite=[@"ConfigurationFixture." stringByAppendingString:NSUUID.UUID.UUIDString];
    defaults=[[NSUserDefaults alloc]initWithSuiteName:suite];NSUInteger testedMethods=0;
    for(NSString *className in classes) {
        Class cls=NSClassFromString(className);CHECK(cls!=Nil);id object=[cls new];
        NSDictionary *methods=classes[className];
        for(NSString *method in methods) {
            testedMethods++;NSArray *rule=methods[method];NSString *kind=rule[0];SEL selector=NSSelectorFromString(method);
            CHECK([object respondsToSelector:selector]);Method runtime=class_getInstanceMethod(cls,selector);CHECK(runtime!=NULL);
            char *type=method_copyReturnType(runtime);
            CHECK(strcmp(type,[kind isEqual:@"setter"]?@encode(void):[kind isEqual:@"int"]?@encode(int):@encode(BOOL))==0);free(type);
            CHECK(method_getNumberOfArguments(runtime)==([kind isEqual:@"setter"]?3u:2u));
            for(NSNumber *orig in @[@NO,@YES])for(NSNumber *enabled in @[@NO,@YES]) {
                originalResult=orig.boolValue;originalCalls=0;gateCalls=0;lastSelf=nil;lastSelector=NULL;lastGateKey=nil;lastSetterValue=NO;
                [preferences removeAllObjects];preferences[@"unrelatedPreference"]=@YES;
                if([kind isEqual:@"gated"]||[kind isEqual:@"direct"])preferences[rule[1]]=enabled;
                if([kind isEqual:@"setter"]) {
                    char *argument=method_copyArgumentType(runtime,2);CHECK(strcmp(argument,@encode(BOOL))==0);free(argument);
                    ((void(*)(id,SEL,BOOL))objc_msgSend)(object,selector,enabled.boolValue);
                    CHECK(lastSetterValue==YES);CHECK(originalCalls==1);CHECK(lastSelf==object&&lastSelector==selector);CHECK(gateCalls==0);
                } else if([kind isEqual:@"int"]) {
                    CHECK(((int(*)(id,SEL))objc_msgSend)(object,selector)==INT_MAX);CHECK(originalCalls==0&&gateCalls==0);
                } else if([kind isEqual:@"startup"]) {
                    for(NSNumber *mode in @[@(NSIntegerMin),@(-1),@0,@1,@2,@3,@4,@5,@(0x100000001LL),@(0x100000002LL),@(NSIntegerMax)]) {
                        [defaults setInteger:mode.integerValue forKey:@"startupAnimation"];originalCalls=0;
                        BOOL expected=(mode.integerValue==1||mode.integerValue==4)?YES:mode.integerValue==2?NO:orig.boolValue;
                        CHECK(((BOOL(*)(id,SEL))objc_msgSend)(object,selector)==expected);
                        BOOL forwarded=!(mode.integerValue==1||mode.integerValue==2||mode.integerValue==4);
                        CHECK(originalCalls==(NSUInteger)forwarded);if(forwarded)CHECK(lastSelf==object&&lastSelector==selector);CHECK(gateCalls==0);
                    }
                } else {
                    BOOL expected=NO,forwarded=NO;
                    if([kind isEqual:@"gated"]){expected=enabled.boolValue?[rule[2]boolValue]:orig.boolValue;forwarded=!enabled.boolValue;}
                    else if([kind isEqual:@"direct"])expected=enabled.boolValue;
                    else expected=[rule[1]boolValue];
                    CHECK(((BOOL(*)(id,SEL))objc_msgSend)(object,selector)==expected);
                    CHECK(originalCalls==(NSUInteger)forwarded);if(forwarded)CHECK(lastSelf==object&&lastSelector==selector);
                    BOOL gated=[kind isEqual:@"gated"]||[kind isEqual:@"direct"];
                    CHECK(gateCalls==(NSUInteger)gated);if(gated)CHECK([lastGateKey isEqual:rule[1]]);
                }
            }
        }
    }
    CHECK(testedMethods==38);[defaults removePersistentDomainForName:suite];
    printf("Configuration hooks: %lu actual Logos/runtime assertions passed across %lu registrations\n",(unsigned long)checks,(unsigned long)testedMethods);
}return 0;}
