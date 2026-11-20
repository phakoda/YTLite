#import "MetadataAudit.h"
#import <objc/runtime.h>

static void require(BOOL condition, NSString *message, NSUInteger *assertions) {
    (*assertions)++;
    if (!condition) {
        fprintf(stderr, "Metadata mismatch: %s\n", message.UTF8String);
        abort();
    }
}

NSUInteger YTLAuditMetadata(NSString *metadataPath, NSArray<NSString *> *classNames, NSString *ivarPath) {
    NSUInteger assertions = 0, methodCount = 0, propertyCount = 0, found = 0;
    NSError *error = nil;
    NSData *data = [NSData dataWithContentsOfFile:metadataPath options:0 error:&error];
    require(data != nil && error == nil, @"class evidence unreadable", &assertions);
    NSArray *classes = [NSJSONSerialization JSONObjectWithData:data options:0 error:&error];
    require(classes != nil && error == nil, @"class evidence malformed", &assertions);
    NSDictionary *ivars = nil;
    if (ivarPath) {
        data = [NSData dataWithContentsOfFile:ivarPath options:0 error:&error];
        require(data != nil && error == nil, @"ivar evidence unreadable", &assertions);
        ivars = [NSJSONSerialization JSONObjectWithData:data options:0 error:&error];
        require(ivars != nil && error == nil, @"ivar evidence malformed", &assertions);
    }
    NSSet *selected = [NSSet setWithArray:classNames];
    for (NSDictionary *entry in classes) {
        NSString *name = entry[@"name"];
        if (![selected containsObject:name]) continue;
        Class cls = NSClassFromString(name);
        require(cls != Nil, [name stringByAppendingString:@" is missing"], &assertions);
        require([NSStringFromClass(class_getSuperclass(cls)) isEqual:entry[@"superclass"]],
                [name stringByAppendingString:@" superclass"], &assertions);
        found++;
        NSMutableSet *expectedMethods = [NSMutableSet set], *actualMethods = [NSMutableSet set];
        for (NSDictionary *spec in entry[@"methods"]) {
            BOOL isClassMethod = [spec[@"kind"] isEqual:@"+"];
            SEL selector = NSSelectorFromString(spec[@"selector"]);
            Method method = isClassMethod ? class_getClassMethod(cls, selector) : class_getInstanceMethod(cls, selector);
            NSString *identity = [spec[@"kind"] stringByAppendingString:spec[@"selector"]];
            [expectedMethods addObject:identity];
            require(method != NULL, [NSString stringWithFormat:@"%@ %@ missing", name, identity], &assertions);
            NSString *encoding = [NSString stringWithUTF8String:method_getTypeEncoding(method)];
            require([encoding isEqual:spec[@"encoding"]],
                    [NSString stringWithFormat:@"%@ %@: expected %@, got %@", name, identity, spec[@"encoding"], encoding], &assertions);
            methodCount++;
        }
        for (NSUInteger meta = 0; meta < 2; meta++) {
            unsigned int count = 0;
            Method *methods = class_copyMethodList(meta ? object_getClass(cls) : cls, &count);
            for (unsigned int index = 0; index < count; index++) {
                NSString *identity = [(meta ? @"+" : @"-") stringByAppendingString:NSStringFromSelector(method_getName(methods[index]))];
                [actualMethods addObject:identity];
            }
            free(methods);
        }
        require([expectedMethods isEqual:actualMethods],
                [NSString stringWithFormat:@"%@ own selector set: expected %@, got %@", name, expectedMethods, actualMethods], &assertions);
        for (NSDictionary *spec in entry[@"properties"]) {
            objc_property_t property = class_getProperty(cls, [spec[@"name"] UTF8String]);
            require(property != NULL, [NSString stringWithFormat:@"%@.%@ missing", name, spec[@"name"]], &assertions);
            NSString *attributes = [NSString stringWithUTF8String:property_getAttributes(property)];
            require([attributes isEqual:spec[@"attributes"]],
                    [NSString stringWithFormat:@"%@.%@: expected %@, got %@", name, spec[@"name"], spec[@"attributes"], attributes], &assertions);
            propertyCount++;
        }
        if (ivars) {
            unsigned int count = 0;
            Ivar *actual = class_copyIvarList(cls, &count);
            NSArray *specification = ivars[name][@"ivars"];
            require(specification != nil && count == specification.count, [name stringByAppendingString:@" ivar count"], &assertions);
            for (NSDictionary *spec in specification) {
                Ivar ivar = class_getInstanceVariable(cls, [spec[@"name"] UTF8String]);
                require(ivar != NULL, [NSString stringWithFormat:@"%@ %@ missing", name, spec[@"name"]], &assertions);
                require([[NSString stringWithUTF8String:ivar_getTypeEncoding(ivar)] isEqual:spec[@"encoding"]],
                        [NSString stringWithFormat:@"%@ %@ type", name, spec[@"name"]], &assertions);
                require(ivar_getOffset(ivar) == [spec[@"offset"] longLongValue],
                        [NSString stringWithFormat:@"%@ %@ offset", name, spec[@"name"]], &assertions);
            }
            free(actual);
        }
    }
    require(found == selected.count, @"not all requested classes were audited", &assertions);
    printf("Exact metadata: %lu classes, %lu methods, %lu properties%s.\n", (unsigned long)found,
           (unsigned long)methodCount, (unsigned long)propertyCount, ivars ? ", including ivar layouts" : "");
    return assertions;
}
