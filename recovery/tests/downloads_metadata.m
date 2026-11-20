#import "downloads_doubles.h"
#import <objc/runtime.h>
static NSUInteger count;
static void Require(BOOL ok,NSString *message) { ++count;if(!ok){fprintf(stderr,"DOWNLOADS METADATA: %s\n",message.UTF8String);exit(2);} }
NSUInteger DownloadsAudit(NSString *repository) {
    NSString *base=[repository stringByAppendingPathComponent:@"recovery/evidence"];
    NSArray *classes=[NSJSONSerialization JSONObjectWithData:[NSData dataWithContentsOfFile:[base stringByAppendingPathComponent:@"arm-classes.json"]] options:0 error:nil];
    NSDictionary *ivars=[NSJSONSerialization JSONObjectWithData:[NSData dataWithContentsOfFile:[base stringByAppendingPathComponent:@"ivars.json"]] options:0 error:nil];
    NSSet *names=[NSSet setWithArray:@[@"YTPMedia",@"YTPDownloader",@"Downloader",@"AudioManager",@"YTPAPIHelper",@"FFMpegHelper",@"DownloadMenuHelper"]];
    NSUInteger found=0,methodCount=0,propertyCount=0,ivarCount=0;
    for(NSDictionary *entry in classes){
        NSString *name=entry[@"name"];if(![names containsObject:name])continue;
        Class cls=NSClassFromString(name);Require(cls!=Nil,name);++found;
        Require([NSStringFromClass(class_getSuperclass(cls)) isEqual:entry[@"superclass"]],[name stringByAppendingString:@" superclass"]);
        NSMutableSet *expected=[NSMutableSet set],*actual=[NSMutableSet set];
        for(NSDictionary *method in entry[@"methods"]){
            NSString *identity=[method[@"kind"] stringByAppendingString:method[@"selector"]];[expected addObject:identity];
            Method m=[method[@"kind"] isEqual:@"+"]?class_getClassMethod(cls,NSSelectorFromString(method[@"selector"])):class_getInstanceMethod(cls,NSSelectorFromString(method[@"selector"]));
            Require(m!=NULL,[name stringByAppendingString:identity]);
            NSString *encoding=@(method_getTypeEncoding(m));Require([encoding isEqual:method[@"encoding"]],[NSString stringWithFormat:@"%@ %@ expected %@ got %@",name,identity,method[@"encoding"],encoding]);++methodCount;
        }
        for(int meta=0;meta<2;++meta){unsigned int n=0;Method *list=class_copyMethodList(meta?object_getClass(cls):cls,&n);for(unsigned int i=0;i<n;++i)[actual addObject:[(meta?@"+":@"-") stringByAppendingString:NSStringFromSelector(method_getName(list[i]))]];free(list);}
        Require([expected isEqual:actual],[NSString stringWithFormat:@"%@ exact method set: %@ versus %@",name,expected,actual]);
        [expected removeAllObjects];[actual removeAllObjects];
        for(NSDictionary *prop in entry[@"properties"]){[expected addObject:prop[@"name"]];objc_property_t p=class_getProperty(cls,[prop[@"name"] UTF8String]);Require(p!=NULL,[name stringByAppendingString:prop[@"name"]]);NSString *attributes=@(property_getAttributes(p));Require([attributes isEqual:prop[@"attributes"]],[NSString stringWithFormat:@"%@.%@: expected %@ got %@",name,prop[@"name"],prop[@"attributes"],attributes]);++propertyCount;}
        unsigned int n=0;objc_property_t *props=class_copyPropertyList(cls,&n);for(unsigned int i=0;i<n;++i)[actual addObject:@(property_getName(props[i]))];free(props);Require([expected isEqual:actual],[NSString stringWithFormat:@"%@ exact own properties: %@ versus %@",name,expected,actual]);
        NSArray *spec=ivars[name][@"ivars"];Ivar *list=class_copyIvarList(cls,&n);Require(n==spec.count,[name stringByAppendingString:@" ivar count"]);free(list);
        NSUInteger end=8;
        for(NSDictionary *v in spec){Ivar i=class_getInstanceVariable(cls,[v[@"name"] UTF8String]);Require(i!=NULL,[name stringByAppendingString:v[@"name"]]);Require([@(ivar_getTypeEncoding(i)) isEqual:v[@"encoding"]],[NSString stringWithFormat:@"%@ %@ encoding %@ versus %@",name,v[@"name"],@(ivar_getTypeEncoding(i)),v[@"encoding"]]);Require(ivar_getOffset(i)==[v[@"offset"] longLongValue],[name stringByAppendingString:v[@"name"]]);end=MAX(end,[v[@"offset"] unsignedIntegerValue]+[v[@"size"] unsignedIntegerValue]);++ivarCount;}
        Require(end==[ivars[name][@"instance_size"] unsignedIntegerValue],[name stringByAppendingString:@" raw instance byte extent"]);
        Require(class_getInstanceSize(cls)==((end+7)&~(NSUInteger)7),[name stringByAppendingString:@" runtime aligned instance size"]);
    }
    Require(found==names.count,@"class count");Require(methodCount==141,@"141 methods");
    printf("Exact Downloads ABI: %lu classes, %lu methods, %lu properties, %lu ivars; %lu assertions.\n",(unsigned long)found,(unsigned long)methodCount,(unsigned long)propertyCount,(unsigned long)ivarCount,(unsigned long)count);
    return count;
}
