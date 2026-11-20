#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "../source/Models/DVNCell.h"
static unsigned checks,failures,parentMode,uuidMode,superCalls,uuidCalls,stringCalls;
static BOOL watching,destructing;
static void *expectedParent;
static IMP oldInit,oldUUID;
static id replacement;
static __weak id lastUUID,lastString;
static uintptr_t owner,newString;
static NSMutableArray *trace;
static NSArray *ownedOffsets;
static NSUInteger destroyed;
static void Check(BOOL ok,NSString *message) { checks++;if(!ok){failures++;fprintf(stderr,"FAIL %s\n",message.UTF8String);} }
static uintptr_t Raw(NSUInteger offset) { uintptr_t value;memcpy(&value,(const void *)(owner+offset),sizeof(value));return value; }
static void Event(NSString *event) { if(watching)[trace addObject:event]; }
@interface CellLifeToken : NSObject <NSCopying>
@property(nonatomic,copy) NSString *tag;
@property(nonatomic) BOOL oldIdentifier;
@property(nonatomic) BOOL ownedSlot;
@property(nonatomic) NSUInteger offset;
@end
@implementation CellLifeToken
- (id)copyWithZone:(NSZone *)zone { (void)zone;return self; }
- (void)dealloc {
    Event(_tag);
    if(watching&&_oldIdentifier) { Check(Raw(24)==newString,@"new identifier stored before old value released");Check(uuidMode==1||lastUUID!=nil,@"UUID receiver alive through old identifier release"); }
    if(destructing&&_ownedSlot) {
        Check(destroyed<ownedOffsets.count&&[ownedOffsets[destroyed] unsignedIntegerValue]==_offset,@"owned fields released in original order");
        for(NSUInteger i=0;i<ownedOffsets.count;i++) {
            NSUInteger offset=[ownedOffsets[i] unsignedIntegerValue];
            Check(i<=destroyed?Raw(offset)==0:Raw(offset)!=0,@"destructor clears each slot before release without clearing later slots");
        }
        destroyed++;
    }
}
@end
@interface CellLifeUUID : NSObject @end
@implementation CellLifeUUID
- (NSString *)UUIDString {
    stringCalls++;Event(@"UUIDString");
    CellLifeToken *value=uuidMode==2?nil:[CellLifeToken new];value.tag=@"string.release";
    lastString=value;newString=(uintptr_t)(__bridge void *)value;return (id)value;
}
- (void)dealloc { Event(@"UUID.release"); }
@end
static id UUIDFactory(id cls,SEL sel) {
    if(!watching)return ((id(*)(id,SEL))oldUUID)(cls,sel);
    Check(cls==NSUUID.class,@"UUID sent to concrete NSUUID class");uuidCalls++;Event(@"UUID");
    CellLifeUUID *value=uuidMode==1?nil:[CellLifeUUID new];lastUUID=value;return value;
}
typedef id (*InitFunction)(id __attribute__((ns_consumed)),SEL) __attribute__((ns_returns_retained));
static id ParentInit(id self __attribute__((ns_consumed)),SEL sel) __attribute__((ns_returns_retained));
static id ParentInit(id self __attribute__((ns_consumed)),SEL sel) {
    if(!(watching&&(__bridge void *)self==expectedParent))return ((InitFunction)oldInit)(self,sel);
    expectedParent=NULL;superCalls++;Event(@"super");
    if(parentMode==1)return nil;
    if(parentMode==2)return replacement;
    return ((InitFunction)oldInit)(self,sel);
}
@interface CellLifeSubclass : DVNCell @end
@implementation CellLifeSubclass @end
static void Reset(void) {
    watching=NO;destructing=NO;owner=0;newString=0;replacement=nil;parentMode=0;uuidMode=0;expectedParent=NULL;
    superCalls=uuidCalls=stringCalls=0;lastUUID=nil;lastString=nil;[trace removeAllObjects];
}
static id Initialize(id value) {
    expectedParent=(__bridge void *)value;watching=YES;id result=[value init];watching=NO;return result;
}
int main(int argc,const char **argv) {
    @autoreleasepool {
        if(argc!=2)return 2;
        NSDictionary *manifest=[NSJSONSerialization JSONObjectWithData:[NSData dataWithContentsOfFile:@(argv[1])] options:0 error:NULL];
        if(!manifest)return 2;
        trace=[NSMutableArray new];
        Method init=class_getInstanceMethod(NSObject.class,@selector(init));oldInit=method_setImplementation(init,(IMP)ParentInit);
        Method uuid=class_getClassMethod(NSUUID.class,@selector(UUID));oldUUID=method_setImplementation(uuid,(IMP)UUIDFactory);
        for(Class cls in @[DVNCell.class,CellLifeSubclass.class]) for(unsigned mode=0;mode<3;mode++) {
            Reset();uuidMode=mode;__weak id weakOwner;
            @autoreleasepool {
                DVNCell *cell=[cls alloc];weakOwner=cell;DVNCell *result=Initialize(cell);
                Check(result==cell&&object_getClass(result)==cls,@"normal init preserves receiver class and identity");
                Check(superCalls==1&&uuidCalls==1&&stringCalls==(mode!=1),@"one superclass, UUID and conditional UUIDString call");
                Check(mode==0?result.reuseIdentifier==lastString&&lastString!=nil:result.reuseIdentifier==nil,@"UUIDString result including nil stored without substitution");
                NSArray *prefix=mode==1?@[@"super",@"UUID"]:@[@"super",@"UUID",@"UUIDString"];
                Check(trace.count>=prefix.count&&[[trace subarrayWithRange:NSMakeRange(0,prefix.count)] isEqual:prefix],@"initializer call sequence");
                result=nil;cell=nil;
            }
            Check(weakOwner==nil&&lastUUID==nil&&lastString==nil,@"initialized receiver and temporaries released");
        }
        Reset();parentMode=1;__weak id failed;
        @autoreleasepool {
            DVNCell *cell=[DVNCell alloc];failed=cell;id result=Initialize(cell);
            Check(result==nil,@"nil superclass result returned");cell=nil;
        }
        Check(superCalls==1&&uuidCalls==0&&stringCalls==0,@"nil superclass skips UUID work");Check(failed==nil,@"failed receiver released");
        Reset();parentMode=2;DVNCell *other=[CellLifeSubclass alloc];replacement=other;__weak id discarded;DVNCell *result;
        @autoreleasepool { DVNCell *cell=[DVNCell alloc];discarded=cell;result=Initialize(cell);cell=nil; }
        Check(discarded==nil&&result==other,@"replacement superclass result becomes receiver");Check(result.reuseIdentifier==lastString&&lastString!=nil,@"identifier stored on replacement");
        Check(superCalls==1&&uuidCalls==1&&stringCalls==1,@"replacement follows successful init sequence");replacement=nil;other=nil;result=nil;
        // Existing identifier, unrelated object and numeric fields survive or
        // change exactly as the original initializer dictates.
        for(unsigned mode=0;mode<3;mode++) {
            Reset();uuidMode=mode;DVNCell *cell=[DVNCell alloc];
            NSObject *title=[NSObject new];cell.title=(id)title;cell.minimumValue=-0.0;cell.type=LLONG_MIN+7;cell.reloadsCell=YES;
            __weak id old;
            @autoreleasepool { CellLifeToken *token=[CellLifeToken new];token.tag=@"old.release";token.oldIdentifier=YES;old=token;[cell setValue:token forKey:@"_reuseIdentifier"]; }
            owner=(uintptr_t)(__bridge void *)cell;result=Initialize(cell);owner=0;
            Check(result==cell&&old==nil,@"repeat init replaces and releases prior identifier");
            Check(cell.title==(id)title&&cell.type==LLONG_MIN+7&&cell.reloadsCell,@"unrelated object integer and boolean fields preserved");
            uint64_t bits;double minimum=cell.minimumValue;memcpy(&bits,&minimum,8);Check(bits==0x8000000000000000ULL,@"unrelated double bits preserved");
            Check(mode==0?cell.reuseIdentifier==lastString&&lastString!=nil:cell.reuseIdentifier==nil,@"repeat init stores nil or returned identifier");
            NSArray *expected=mode==1?@[@"super",@"UUID",@"old.release"]:@[@"super",@"UUID",@"UUIDString",@"old.release"];
            Check(trace.count>=expected.count&&[[trace subarrayWithRange:NSMakeRange(0,expected.count)] isEqual:expected],@"old identifier release follows UUIDString");
            result=nil;cell=nil;
        }
        Reset();NSMutableArray *offsets=[NSMutableArray new];for(NSDictionary *entry in manifest[@"destruction"]) if([entry[@"operation"] isEqual:@"strong"]) [offsets addObject:entry[@"offset"]];ownedOffsets=offsets;
        DVNCell *cell=[DVNCell alloc];NSObject *view=[NSObject new];__weak id weakView=view;cell.sourceView=(id)view;
        @autoreleasepool {
            for(NSDictionary *entry in manifest[@"destruction"]) if([entry[@"operation"] isEqual:@"strong"]) {
                CellLifeToken *token=[CellLifeToken new];token.tag=entry[@"name"];token.ownedSlot=YES;token.offset=[entry[@"offset"] unsignedIntegerValue];[cell setValue:token forKey:entry[@"name"]];
            }
        }
        owner=(uintptr_t)(__bridge void *)cell;for(NSNumber *offset in ownedOffsets)Check(Raw(offset.unsignedIntegerValue)!=0,@"owned field populated before destruction");
        destroyed=0;destructing=YES;cell=nil;destructing=NO;owner=0;
        Check(destroyed==22,@"all owned fields destroyed once");Check(weakView!=nil,@"destroying weak slot does not destroy its referent");view=nil;Check(weakView==nil,@"former weak referent releases after owner destruction");
        method_setImplementation(uuid,oldUUID);method_setImplementation(init,oldInit);
        printf("%s First_cell_lifecycle: %u assertions, %u failures\n",failures?"FAIL":"PASS",checks,failures);
    }
    return failures?1:0;
}
