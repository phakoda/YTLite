#import "Dvbug.h"
#import <objc/runtime.h>
#include <string.h>

static Ivar DVNFindIvar(id object, NSString *name) {
    return class_getInstanceVariable([object class], name.UTF8String);
}
// The original two integer methods both load eight bytes, despite their names.
static long long DVNReadInteger(id object, Ivar ivar) {
    if (!ivar) return 0;
    long long value;
    memcpy(&value, (const char *)(__bridge const void *)object + ivar_getOffset(ivar), sizeof(value));
    return value;
}
@implementation Dvbug
// 0x227b88 uses KVC, which can invoke an accessor or box a scalar.
+ (id)instanceForObject:(id)object name:(NSString *)name {
    if (!object || name.length == 0) {
        NSLog(@"DVN --- senderObject (%@) or name (%@) is nil", object, name);
        return nil;
    }
    return DVNFindIvar(object, name) ? [object valueForKey:name] : nil;
}
// 0x228038 and 0x228948 use direct object-ivar access, not KVC.
+ (void)observeIvar:(id)object name:(NSString *)name {
    Ivar ivar = DVNFindIvar(object, name);
    if (!ivar) {
        NSLog(@"DVN --- ivar %@ not found in class %@", name, NSStringFromClass([object class]));
        return;
    }
    id value = object_getIvar(object, ivar);
    if (value) NSLog(@"DVN --- %@: %@", name, value);
    else NSLog(@"DVN --- %@: (null)", name);
}
+ (id)getObservedIvar:(id)object name:(NSString *)name {
    Ivar ivar = DVNFindIvar(object, name);
    return ivar ? object_getIvar(object, ivar) : nil;
}
// 0x228e60.
+ (void)setObservedIvar:(id)object name:(NSString *)name value:(id)value {
    Ivar ivar = DVNFindIvar(object, name);
    if (ivar) object_setIvar(object, ivar, value);
}
// 0x229350 / 0x22990c.
+ (long long)getObservedIntIvar:(id)object name:(NSString *)name { return DVNReadInteger(object, DVNFindIvar(object, name)); }
+ (long long)getObservedIvarLongLong:(id)object name:(NSString *)name { return DVNReadInteger(object, DVNFindIvar(object, name)); }
// 0x229e2c loads one unsigned byte and returns whether it is nonzero.
+ (BOOL)getObservedBoolIvar:(id)object name:(NSString *)name {
    Ivar ivar = DVNFindIvar(object, name);
    return ivar && *((const unsigned char *)(__bridge const void *)object + ivar_getOffset(ivar)) != 0;
}
// 0x22a380 stores one byte.
+ (void)setObservedBoolIvar:(id)object name:(NSString *)name value:(BOOL)value {
    Ivar ivar = DVNFindIvar(object, name);
    if (ivar) *((unsigned char *)(__bridge void *)object + ivar_getOffset(ivar)) = value;
}
@end
