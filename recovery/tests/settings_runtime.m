#import "settings_fixture_hosts.h"
#import "../source/Settings/YTPSettingsBuilder.h"
#import "../source/Settings/TabbarVC.h"
#import "../source/Support/YTPDB.h"
#import "MetadataAudit.h"
#import <objc/message.h>
#import <objc/runtime.h>
#import <math.h>

void SettingsTestController(void);
void SettingsTestTabbarAndViews(void);

static id readJSON(NSString *path) {
    NSError *error=nil;NSData *data=[NSData dataWithContentsOfFile:path options:0 error:&error];SC(data && !error);
    id result=[NSJSONSerialization JSONObjectWithData:data options:0 error:&error];SC(result && !error);return result;
}
static NSArray<DVNCell *> *flatten(DVNTableModel *model) {
    NSMutableArray *cells=[NSMutableArray array];for(DVNSection *section in model.sections)[cells addObjectsFromArray:section.cells];return cells;
}
static id resolved(id value) {
    if([value isKindOfClass:NSDictionary.class]) {
        if(value[@"localized"])return [value[@"localized"] ytl_localized];
        if(value[@"host"]){SC([value[@"host"] isEqual:@"supportedLanguages"]);return [YTPDB supportedLanguages];}
        if(value[@"image"])return value[@"image"];
        SC(NO);return nil;
    }
    if([value isKindOfClass:NSArray.class]){NSMutableArray *array=[NSMutableArray array];for(id item in value)[array addObject:resolved(item)];return array;}
    return value;
}
static void equalObject(id actual,id expected,NSString *context) {
    BOOL equal=actual==expected || [actual isEqual:expected];
    if(!equal)fprintf(stderr,"%s: actual=%s expected=%s\n",context.UTF8String,[[actual description] UTF8String],[[expected description]UTF8String]);
    SC(equal);
}
static NSString *blockSignature(id block) {
    SC(block!=nil);
    struct Block { void *isa;int flags;int reserved;void *invoke;unsigned char *descriptor; };
    const struct Block *literal=(__bridge const struct Block *)block;
    SC((literal->flags & (1<<30))!=0);
    unsigned char *signature=literal->descriptor+sizeof(uintptr_t)*2;
    if(literal->flags & (1<<25))signature+=sizeof(void *)*2;
    return [NSString stringWithUTF8String:*(const char **)signature];
}
static void testRows(NSString *path) {
    NSDictionary *fixture=readJSON(path);YTPSettingsBuilder *builder=[YTPSettingsBuilder new];NSUInteger count=0;
    for(NSString *method in @[@"downloadingTable",@"navbarTable",@"feedTable",@"playerTable",@"shortsTable",@"interfaceTable",@"rpcTable"]) {
        DVNTableModel *model=((id(*)(id,SEL))objc_msgSend)(builder,NSSelectorFromString(method));
        NSArray *actual=flatten(model),*expected=fixture[method];SC(model.supportsSearching);SC(actual.count==expected.count);
        NSMutableSet *UUIDs=[NSMutableSet set];
        for(NSUInteger i=0;i<actual.count;i++) {
            DVNCell *cell=actual[i];NSDictionary *row=expected[i],*values=row[@"values"];NSString *factory=row[@"factory"];
            NSString *context=[NSString stringWithFormat:@"%@ row %lu %@",method,(unsigned long)i,row[@"address"]];
            NSInteger type=5;
            if(values[@"type"])type=[values[@"type"]integerValue];
            else if([factory isEqual:@"cellWithTitleIndexes:key:"])type=1;
            else if([factory hasPrefix:@"sliderCell"])type=6;
            else if([factory hasPrefix:@"timePicker"])type=7;
            else if([factory hasPrefix:@"textField"])type=10;
            if(cell.type!=type)fprintf(stderr,"%s: cell type %ld expected %ld\n",context.UTF8String,(long)cell.type,(long)type);
            SC(cell.type==type);SC(cell.reuseIdentifier.length>0);SC(![UUIDs containsObject:cell.reuseIdentifier]);[UUIDs addObject:cell.reuseIdentifier];
            for(NSString *key in values) {
                if([key isEqual:@"type"])continue;
                id value=values[key];
                if([key isEqual:@"handler"]){SC(cell.handler!=nil);continue;}
                if([@[@"minimum",@"maximum",@"divider",@"format"]containsObject:key]) {
                    NSString *property=@{@"minimum":@"minimumValue",@"maximum":@"maximumValue",@"divider":@"dividerValue",@"format":@"sliderFormat"}[key];
                    if(value==NSNull.null){SC([cell.key isEqual:@"gestWideness"] && [key isEqual:@"maximum"]);SC(cell.maximumValue==130);continue;}
                    equalObject([cell valueForKey:property],value,[context stringByAppendingFormat:@".%@",property]);continue;
                }
                id want=resolved(value);
                if([want isKindOfClass:NSNumber.class] && [want integerValue]==0)want=nil;
                id got=[cell valueForKey:key];
                if([key isEqual:@"icon"] || [key isEqual:@"accessoryIcon"] || [key isEqual:@"image"])got=[(UIImage *)got recoveredName];
                equalObject(got,want,[context stringByAppendingFormat:@".%@",key]);
            }
            count++;
        }
        for(DVNSection *section in model.sections) {
            BOOL appended=[@[@"playerInterfaceCell",@"shortsInterfaceCell",@"menuCell"] containsObject:section.identifier];
            for(DVNCell *cell in section.cells)equalObject(cell.identifier,appended?(cell.title?:section.identifier):section.identifier,@"identifier-stamping");
        }
    }
    SC(count==174);
    UIScreen.mainScreen.bounds=CGRectMake(0,0,844,390);
    DVNCell *width=nil;for(DVNCell *cell in flatten([builder playerTable]))if([cell.key isEqual:@"gestWideness"])width=cell;
    SC(width.maximumValue==130);
    UIScreen.mainScreen.bounds=CGRectMake(0,0,480,480);
    for(DVNCell *cell in flatten([builder playerTable]))if([cell.key isEqual:@"gestWideness"])width=cell;
    SC(width.maximumValue==160);UIScreen.mainScreen.bounds=CGRectMake(0,0,390,844);
    printf("Original ARM64 fixtures: 174 row factories, ordered titles/keys/options/types/ranges and identifiers verified.\n");
}

static void testTreeAndLinks(void) {
    YTPSettingsBuilder *builder=[YTPSettingsBuilder new];DVNTableModel *root=[builder rootTable];
    SC(root.sections.count==3);equalObject(root.title,@"YTLite",@"root.title");SC(root.supportsSearching);
    SC([root.footer hasPrefix:@"YouTube Plus: 5.2.2-local • YouTube: "]);
    SC(root.footerFont.pointSize==14 && root.footerFont.recoveredTestWeight==UIFontWeightLight && root.footerAlignment==NSTextAlignmentNatural);
    NSArray *sizes=@[@7,@2,@3];for(NSUInteger i=0;i<sizes.count;i++)SC([(DVNSection *)root.sections[i]cells].count==[sizes[i]unsignedIntegerValue]);
    for (DVNSection *section in root.sections) {
        SC(![section.identifier isEqual:@"patreonCell"]);
        SC(![section.identifier isEqual:@"devCell"]);
        SC(![section.header isEqual:@"Account"]);
        SC(![section.header isEqual:[@"Developer" ytl_localized]]);
    }
    NSArray *credits=[(DVNSection *)root.sections.lastObject cells];
    equalObject([credits valueForKey:@"title"],(@[@"L:Contributors",@"L:OpenSourceLibs",@"Preferences(YouTube Plus)"]),@"visible credits rows");
    for(DVNCell *cell in flatten(root))SC(![cell.controllerModel.viewController isKindOfClass:DVNSupportersVC.class]);
    NSArray *mainTitles=@[@"Downloading",@"Navbar",@"Feed",@"Player",@"Shorts",@"Tabbar",@"Interface"];
    NSArray *mainIcons=@[@"downloading",@"navbar",@"feed",@"player",@"FEshorts",@"tabbar",@"interface"];
    for(NSUInteger i=0;i<7;i++){
        DVNCell *cell=[(DVNSection *)root.sections[0]cells][i];SC(cell.type==4);equalObject(cell.title,[mainTitles[i]ytl_localized],@"main row");
        equalObject(cell.icon.recoveredName,mainIcons[i],@"main icon");SC(cell.controllerModel!=nil);
    }
    DVNCell *tabCell=[(DVNSection *)root.sections[0]cells][5];
    SC(!tabCell.controllerModel.supportsSearching && [tabCell.controllerModel.viewController isKindOfClass:TabbarVC.class]);
    DVNTableModel *thanks=[builder thanksTable];SC(!thanks.supportsSearching && [thanks.viewController isKindOfClass:DVNSupportersVC.class]);
    DVNTableModel *prefs=[builder prefsTable];SC(prefs.supportsSearching);equalObject(prefs.title,@"Preferences(YouTube Plus)",@"prefs.title");
    NSArray *contribURLs=@[@"https://github.com/danpashin/",@"https://t.me/mdfurman/",@"https://t.me/MagwaerTim/",@"https://github.com/xiangfeidexiaohuo",@"https://twitter.com/a100900900",@"https://github.com/Balackburn",@"https://github.com/Deci8BelioS",@"https://github.com/ichitaso",@"https://github.com/hiepvk",@"https://t.me/bvnsupport",@"https://twitter.com/r22i0",@"https://github.com/gototheskinny",@"https://github.com/basketshoe",@"https://github.com/pshyomin",@"https://github.com/marcinmajsc"];
    NSArray *libURLs=@[@"https://github.com/PoomSmart/YouTubeHeader",@"https://github.com/PoomSmart/YouTube-X",@"https://github.com/PoomSmart/YTClassicVideoQuality",@"https://github.com/PoomSmart/YTShortsProgress",@"https://github.com/PoomSmart/YTAutoFullScreen",@"https://github.com/dayanch96/YTLite/blob/main/YTLite.x#L310-L312",@"https://github.com/PoomSmart/YouAreThere",@"https://github.com/jkhsjdhjs/youtube-native-share",@"https://github.com/tanersener/mobile-ffmpeg"];
    NSArray *models=@[[builder contribsTable],[builder libsTable]],*URLSets=@[contribURLs,libURLs];
    for(NSUInteger m=0;m<2;m++){
        DVNTableModel *model=models[m];SC(!model.supportsSearching && model.showsThanksHeart);NSArray *cells=flatten(model),*urls=URLSets[m];SC(cells.count==urls.count);
        for(NSUInteger i=0;i<cells.count;i++){
            DVNCell *cell=cells[i];SC(cell.type==5 && cell.selfHandler==nil);equalObject(blockSignature(cell.handler),@"v8@?0",@"link invoke ABI");
            ((YTLSettingsHandler)cell.handler)();equalObject([UIApplication.sharedApplication.recoveredURLs.lastObject absoluteString],urls[i],@"link callback URL");
            equalObject(cell.accessoryIcon.recoveredName,@"open_new",@"link accessory");
        }
    }
    DVNSection *dev=[builder devSection];NSArray *devURLs=@[@"https://twitter.com/dayanch96",@"",@"https://github.com/dayanch96/YTLite",@"https://t.me/dvntms"];
    for(NSUInteger i=0;i<4;i++){
        DVNCell *cell=dev.cells[i];SC(cell.handler==nil && cell.selfHandler!=nil && cell.renderingMode==1);
        equalObject(blockSignature(cell.selfHandler),@"v16@?0@\"DVNCell\"8",@"developer callback ABI");
        if(i!=1){((YTLSettingsCellHandler)cell.selfHandler)(cell);equalObject([UIApplication.sharedApplication.recoveredURLs.lastObject absoluteString],devURLs[i],@"developer URL");}
    }
    NSUInteger count=UIApplication.sharedApplication.recoveredURLs.count;UIApplication.sharedApplication.recoveredCanOpen=NO;
    [builder openURL:@"https://example.invalid/blocked"];SC(UIApplication.sharedApplication.recoveredURLs.count==count);
    equalObject(UIApplication.sharedApplication.recoveredCanOpenURL.absoluteString,@"https://example.invalid/blocked",@"canOpenURL argument");UIApplication.sharedApplication.recoveredCanOpen=YES;
    DVNTableModel *interface=[builder interfaceTable];UIViewController *owner=[UIViewController new];interface.selfViewController=owner;
    DVNCell *animation=[(DVNSection *)interface.sections[1]cells][1];((YTLSettingsHandler)animation.handler)();SC(SettingsLastEvent(@"imagePicker")==owner);
    UIImage *image=[builder thanksImage:@"avatar"];SC(image.size.width==40 && image.size.height==40);equalObject(SettingsLastEvent(@"imageNamed"),@"avatar",@"thanks image");
    __weak UIViewController *weak;
    @autoreleasepool { UIViewController *presenter=[UIViewController new];weak=presenter;builder.presenter=presenter;SC(builder.presenter==presenter); }
    SC(weak==nil && builder.presenter==nil);
}

static void testSponsorAndAccount(void) {
    YTPSettingsBuilder *builder=[YTPSettingsBuilder new];DVNTableModel *sb=[builder sbTable];
    SC(sb.sections.count==10 && flatten(sb).count==28 && sb.supportsSearching);
    NSArray *descriptors=[builder sbSegments];SC(descriptors.count==8);
    NSArray *indexes=@[@"sbSponsorIndex",@"sbIntroIndex",@"sbOutroIndex",@"sbInteractionIndex",@"sbSelfPromoIndex",@"sbNonMusicIndex",@"sbPreviewIndex",@"sbTangentIndex"];
    NSArray *colors=@[@"sbSponsorColor",@"sbIntroColor",@"sbOutroColor",@"sbInteractionColor",@"sbSelfPromoColor",@"sbNonMusicColor",@"sbPreviewColor",@"sbTangentColor"];
    for(NSUInteger i=0;i<8;i++){
        NSArray *pair=[(DVNSection *)sb.sections[i+1]cells];SC(pair.count==2);DVNCell *menu=pair[0],*color=pair[1];
        SC(menu.type==3 && color.type==8);equalObject(menu.key,indexes[i],@"SB index");equalObject(color.key,colors[i],@"SB color");
        equalObject(menu.titleIndexes,(@[@"L:Sb.Disable",@"L:Sb.Skip",@"L:Sb.Ask",@"L:Sb.Display"]),@"SB options");
    }
    NSArray *main=[(DVNSection *)sb.sections[0]cells];SC(main.count==10);
    for(NSUInteger i=7;i<10;i++){DVNCell *cell=main[i];SC(cell.type==7 && cell.sliderFormat==2);SC(cell.minimumValue==(i==7?0:2));SC(cell.maximumValue==(i==7?60:20));}
    NSArray *users=[(DVNSection *)sb.sections.lastObject cells];DVNCell *public=users[0],*private=users[1];
    SC(!public.shouldHideDetail && private.shouldHideDetail);equalObject(private.detailText,@"L:TapToReveal",@"private detail");
    equalObject(blockSignature(public.validationHandler),@"@\"NSString\"16@?0@\"NSString\"8",@"validation signature");
    YTLSettingsValidationHandler publicValidator=(YTLSettingsValidationHandler)public.validationHandler,privateValidator=(YTLSettingsValidationHandler)private.validationHandler;
    NSString *s64=[@"!" stringByPaddingToLength:64 withString:@"!" startingAtIndex:0];
    SC(publicValidator(s64)==s64);SC(publicValidator([s64 substringToIndex:63])==nil);
    equalObject(publicValidator(@""),@"fixture-public",@"regenerated public ID");equalObject(SettingsDefaults.lastPublicIDInput,@"fixture-private",@"public helper input");
    equalObject(publicValidator(nil),@"fixture-public",@"nil public input");
    SC(privateValidator([s64 substringToIndex:31])==nil);SC(privateValidator(s64)==s64);
    SC(privateValidator([s64 substringToIndex:32])!=nil);equalObject(privateValidator(nil),@"fixture-private",@"nil private input");
    DVNTableModel *model=[DVNTableModel model];UIViewController *owner=[UIViewController new];model.selfViewController=owner;
    NSUInteger calls=SettingsLoginCalls+SettingsDeviceCalls+SettingsLogoutCalls;
    NSUInteger checksBefore=SettingsAuthChecks+SettingsLockChecks;
    for (NSNumber *authenticated in @[@NO,@YES]) {
        SettingsAuthenticated=authenticated.boolValue;
        SettingsLocked=YES;
        DVNSection *section=[builder patreonSection:model];
        equalObject(section.header,@"Local features",@"local-only compatibility section");
        SC(section.cells.count==1 && section.cellsProvider==nil);
        for (NSString *kind in @[@"activationButton",@"manageButton",@"logoutButton",@"unknown"]) {
            DVNCell *cell=[builder patreonButtonCellWithType:kind model:model];
            equalObject(cell.title,@"No sign-in required",@"no account actions");
            SC(cell.handler==nil && cell.selfHandler==nil && cell.handlerWithCompletion==nil);
            SC(cell.key==nil && cell.type==5);
        }
        DVNTableModel *root=[builder rootTable];
        for(DVNSection *part in root.sections)SC(![part.identifier isEqual:@"patreonCell"]);
    }
    SC(SettingsAuthChecks+SettingsLockChecks==checksBefore);
    SC(SettingsLoginCalls+SettingsDeviceCalls+SettingsLogoutCalls==calls);
    SettingsLocked=NO;
    SettingsLastLogin=nil;SettingsLastDevices=nil;SettingsLastAlert=nil;
}

static void writeFixture(NSString *relative,NSUInteger size) {
    NSString *path=[SettingsFixtureRoot stringByAppendingPathComponent:relative];
    SC([path hasPrefix:[SettingsFixtureRoot stringByAppendingString:@"/"]]);
    NSError *error=nil;SC([NSFileManager.defaultManager createDirectoryAtPath:path.stringByDeletingLastPathComponent withIntermediateDirectories:YES attributes:nil error:&error]);SC(!error);
    SC([[NSMutableData dataWithLength:size]writeToFile:path options:0 error:&error]);SC(!error);
}
static void testPreferencesAndCache(void) {
    YTPSettingsBuilder *builder=[YTPSettingsBuilder new];DVNTableModel *model=[builder prefsTable];NSArray *cells=flatten(model);SC(cells.count==5);
    DVNCell *import=cells[0],*export=cells[1],*reset=cells[2],*clear=cells[4];
    NSUInteger imports=SettingsImportCalls;((YTLSettingsHandler)import.handler)();SC(SettingsImportCalls==imports);
    equalObject(SettingsLastAlert.subtitle,@"L:PreImportMessage",@"import prompt");equalObject(SettingsLastAlert.actionTitle,@"L:Yes",@"import yes");
    SettingsImportSuccess=YES;SettingsLastAlert.confirmation();SC(SettingsImportCalls==imports+1);equalObject(SettingsLastEvent(@"toast"),(@{@"text":@"L:Done",@"success":@YES}),@"import success");
    SettingsImportSuccess=NO;SettingsLastAlert.confirmation();equalObject(SettingsLastEvent(@"toast"),(@{@"text":@"L:Error.FailedToImport",@"success":@NO}),@"import failure");
    UIView *source=[UIView new];export.sourceView=source;((YTLSettingsCellHandler)export.selfHandler)(export);SC(SettingsExportView==source);
    NSUInteger resets=SettingsResetCalls;((YTLSettingsHandler)reset.handler)();SC(SettingsResetCalls==resets);equalObject(SettingsLastAlert.subtitle,@"L:ResetMessage",@"reset prompt");
    SettingsLastAlert.confirmation();SC(SettingsResetCalls==resets+1);
    SC(clear.type==12 && clear.reloadsCell && !clear.reloadsTable && clear.handlerWithCompletion && clear.subtitleProvider);
    equalObject(blockSignature(clear.subtitleProvider),@"@\"NSString\"8@?0",@"cache subtitle signature");
    equalObject(blockSignature(clear.handlerWithCompletion),@"v16@?0@?<v@?>8",@"nested completion signature");
    writeFixture(@"cache/nested/data.bin",4097);writeFixture(@"cache/sibling.bin",1024);writeFixture(@"tmp/part.bin",517);
    unsigned long long total=0;
    for(NSString *name in @[@"cache",@"tmp"]){NSString *root=[SettingsFixtureRoot stringByAppendingPathComponent:name];for(NSString *entry in [NSFileManager.defaultManager subpathsOfDirectoryAtPath:root error:NULL])total += [[NSFileManager.defaultManager attributesOfItemAtPath:[root stringByAppendingPathComponent:entry] error:NULL]fileSize];}
    NSByteCountFormatter *formatter=[NSByteCountFormatter new];formatter.countStyle=NSByteCountFormatterCountStyleFile;
    equalObject(((YTLSettingsSubtitleProvider)clear.subtitleProvider)(),[formatter stringFromByteCount:(long long)total],@"cache size includes directories");
    SC(SettingsPending()==0);__block NSUInteger completions=0;
    ((YTLSettingsCompletionHandler)clear.handlerWithCompletion)(^{completions++;SC([SettingsLastEvent(@"executingMainQueue")boolValue]);});
    SC(completions==0 && SettingsPending()==1);
    SC([NSFileManager.defaultManager fileExistsAtPath:[SettingsFixtureRoot stringByAppendingPathComponent:@"tmp/part.bin"]]);
    SettingsDrainOne();SC(completions==0 && SettingsPending()==1);
    SC(![NSFileManager.defaultManager fileExistsAtPath:[SettingsFixtureRoot stringByAppendingPathComponent:@"tmp"]]);
    SC([[NSFileManager.defaultManager contentsOfDirectoryAtPath:[SettingsFixtureRoot stringByAppendingPathComponent:@"cache"]error:NULL]count]==0);
    SettingsDrain();SC(completions==1);
    SettingsLastAlert=nil;SettingsExportView=nil;
}

static void finishDonation(SettingsFixtureSession *session,NSData *data,NSError *error) {
    SC(session.task.resumed && session.handler);
    session.handler(data,nil,error);session.handler=nil;SC(SettingsPending()==1);SettingsDrain();
}
static void testDonation(void) {
    YTPSettingsBuilder *builder=[YTPSettingsBuilder new];UIViewController *presenter=[UIViewController new];builder.presenter=presenter;UIView *source=[UIView new];
    [builder showDonationSheet:source];SettingsFixtureSession *session=SettingsFixtureSession.sharedSession;
    equalObject(session.url.absoluteString,@"https://api.dvntm.com/api/getlinks",@"donation endpoint");
    finishDonation(session,nil,[NSError errorWithDomain:@"fixture" code:1 userInfo:nil]);
    YTDefaultSheetController *sheet=SettingsLastSheet;SC(sheet.actions.count==6 && sheet.sourceView==source && sheet.presentedFrom==presenter && sheet.animated);
    equalObject(sheet.message,@"L:SupportDevelopment",@"sheet title");SC([[sheet.headerView valueForKey:@"_subtitleLabel"] numberOfLines]==0);
    NSArray *titles=@[@"Patreon",@"Github Sponsors",@"Buy Me a Coffee",@"Boosty",@"USDT (TRC20)",@"BNB Smart Chain (BEP20)"];
    NSArray *icons=@[@"patreon",@"github",@"coffee",@"boosty",@"usdt",@"bnb"];
    NSArray *urls=@[@"https://www.patreon.com/dayanch96",@"https://github.com/sponsors/dayanch96",@"https://www.buymeacoffee.com/dayanch96",@"https://boosty.to/dayanch96"];
    NSArray *addresses=@[@"TEdKJdKwc1Bbu8Py4um8qPQ6MbproEqNJw",@"0xc6f9fddb30ce10d70e6497950f44c8e10b72bcd6"];
    for(NSUInteger i=0;i<6;i++){
        YTActionSheetAction *action=sheet.actions[i];equalObject(action.title,titles[i],@"donation title");equalObject(action.iconImage.recoveredName,icons[i],@"donation icon");
        equalObject(blockSignature(action.handler),@"v16@?0@\"YTActionSheetAction\"8",@"sheet callback signature");
        action.handler(action);
        if(i<4)equalObject([UIApplication.sharedApplication.recoveredURLs.lastObject absoluteString],urls[i],@"donation URL");
        else {equalObject(UIPasteboard.generalPasteboard.string,addresses[i-4],@"donation copied address");SC([SettingsLastEvent(@"toast")[@"success"]boolValue]);}
    }
    NSDictionary *overrides=@{@"sponsor_links":@[@{@"name":@"Fixture link",@"key":@"githubsp",@"url":@"https://example.invalid/donate"}],@"addresses":@[]};
    NSData *data=[NSJSONSerialization dataWithJSONObject:overrides options:0 error:NULL];
    [builder showDonationSheet:source];finishDonation(session,data,nil);SC(SettingsLastSheet.actions.count==1);equalObject(SettingsLastSheet.actions[0].title,@"Fixture link",@"network override");
    SettingsLastSheet.actions[0].handler(SettingsLastSheet.actions[0]);equalObject([UIApplication.sharedApplication.recoveredURLs.lastObject absoluteString],@"https://example.invalid/donate",@"override URL");
    [builder showDonationSheet:source];finishDonation(session,data,[NSError errorWithDomain:@"fixture" code:2 userInfo:nil]);SC(SettingsLastSheet.actions.count==6);
    data=[NSJSONSerialization dataWithJSONObject:@{@"sponsor_links":@"wrong type",@"addresses":@42}options:0 error:NULL];
    [builder showDonationSheet:nil];finishDonation(session,data,nil);SC(SettingsLastSheet.actions.count==6 && SettingsLastSheet.sourceView==nil);
    data=[NSJSONSerialization dataWithJSONObject:@{@"sponsor_links":@[],@"addresses":@[]} options:0 error:NULL];
    [builder showDonationSheet:source];finishDonation(session,data,nil);SC(SettingsLastSheet.actions.count==0);
    SettingsLastSheet=nil;
}

int main(int argc,const char *argv[]) {
    @autoreleasepool {
        @try {
            SC(argc==4);
            SettingsFixtureRoot=[[NSString stringWithUTF8String:argv[1]]stringByStandardizingPath];
            SC([SettingsFixtureRoot containsString:@"/.recovery-work/settings/"]);
            SettingsDefaults=[SettingsMemoryDefaults new];SettingsEvents=[NSMutableArray array];
            SettingsChecks+=YTLAuditMetadata([NSString stringWithUTF8String:argv[3]],@[@"DVNTableViewController",@"YTPSettingsBuilder",@"DVNPickerView",@"YTPTableViewCell",@"TabbarVC",@"DVNSupportersVC"],nil);
            testRows([NSString stringWithUTF8String:argv[2]]);testTreeAndLinks();testSponsorAndAccount();SettingsDrain();testPreferencesAndCache();testDonation();
            SettingsTestController();SettingsTestTabbarAndViews();SettingsDrain();
            printf("Settings runtime: %lu assertions passed; six production classes and canonical Models/YTPDB.\n",(unsigned long)SettingsChecks);
        } @catch(NSException *exception) {
            fprintf(stderr,"Fixture exception %s: %s\n",exception.name.UTF8String,exception.reason.UTF8String);return 1;
        }
    }
    return 0;
}
