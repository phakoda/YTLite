#import "settings_fixture_hosts.h"
#import "../source/Settings/TabbarVC.h"
#import "../source/Settings/DVNPickerView.h"
#import "../source/Settings/YTPTableViewCell.h"
#import <math.h>

static NSIndexPath *indexPath(NSInteger row,NSInteger section) { return [NSIndexPath indexPathForRow:row inSection:section]; }
static NSArray *tabKeys(NSArray *tabs) { return [tabs valueForKey:@"key"]; }
static TabbarVC *tabController(NSArray *keys,NSString *startup) {
    [SettingsDefaults setObject:keys forKey:@"activeTabs"];[SettingsDefaults setObject:startup forKey:@"startupTab"];
    return [[TabbarVC alloc]initForSettings:YES];
}
static void testTabs(void) {
    SettingsDefaults=[SettingsMemoryDefaults new];SettingsResetEvents();
    NSArray *all=@[@"FEwhat_to_watch",@"FEshorts",@"FEsubscriptions",@"FElibrary",@"FEhistory",@"FEpost_home",@"VLWL",@"FEhype_leaderboard",@"UC-9-kyTW8ZkZNDHQJ6FgpwQ",@"UC4R8DWoMoI7CAwX8_LjQHig",@"UCOpNcN46UbXVtpKMrmU4Abg",@"UCEgdi0XIXXZ-qJOFPf4JSKw",@"FEnotifications_inbox",@"FEuploads"];
    TabbarVC *vc=tabController(@[@"FEsubscriptions",@"unknown",@"FEwhat_to_watch",@"FEsubscriptions",@"FEuploads"],@"FEwhat_to_watch");
    SC([tabKeys([vc valueForKey:@"_tabs"])isEqual:all]);
    SC([tabKeys([vc valueForKey:@"_activeTabs"])isEqual:@[@"FEsubscriptions",@"FEwhat_to_watch",@"FEuploads"]]);
    SC([[vc valueForKey:@"_inactiveTabs"]count]==11 && [[vc valueForKey:@"_sections"]count]==4);
    SC(vc.model==nil && vc.defaults==nil && vc.tableView.recoveredEditing && vc.tableView.allowsSelectionDuringEditing);
    SC(vc.navigationItem.rightBarButtonItem==nil);
    SC([vc numberOfSectionsInTableView:vc.tableView]==4 && [vc tableView:vc.tableView numberOfRowsInSection:0]==3);
    SC([vc tableView:vc.tableView numberOfRowsInSection:1]==1 && [vc tableView:vc.tableView numberOfRowsInSection:2]==3);
    SC([[vc tableView:vc.tableView titleForHeaderInSection:0]isEqual:@"Main"]);
    SC([[vc tableView:vc.tableView titleForHeaderInSection:1]isEqual:@"Startup"]);
    SC([[vc tableView:vc.tableView titleForHeaderInSection:2]isEqual:@"ActiveTabs"]);
    SC([[vc tableView:vc.tableView titleForHeaderInSection:3]isEqual:@"InactiveTabs"]);
    SC([vc tableView:vc.tableView titleForFooterInSection:2]==nil);
    SC([[vc tableView:vc.tableView titleForFooterInSection:3]isEqual:@"HideLibraryFooter"]);
    // Startup uses stored active keys rather than filtered tab rows. Test an
    // ordinary valid list here; unknown/duplicate behavior is tested separately.
    [SettingsDefaults setObject:@[@"FEsubscriptions",@"FEwhat_to_watch",@"FEuploads"] forKey:@"activeTabs"];
    UITableViewCell *startup=[vc tableView:vc.tableView cellForRowAtIndexPath:indexPath(0,1)];
    UISegmentedControl *segment=(id)startup.contentView.subviews.lastObject;
    SC([segment isKindOfClass:UISegmentedControl.class] && segment.numberOfSegments==2 && segment.selectedSegmentIndex==1);
    segment.selectedSegmentIndex=0;[vc setSegment:segment];SC([[SettingsDefaults objectForKey:@"startupTab"]isEqual:@"FEsubscriptions"]);
    UISegmentedControl *known=[vc segmentForItems:@[@"unknown",@"FEhistory",@"unknown",@"FEshorts"]];SC(known.numberOfSegments==2);
    SC([known.recoveredAttributes[@(UIControlStateSelected)]count]==1 && !known.translatesAutoresizingMaskIntoConstraints);
    UITableViewCell *row=[vc tableView:vc.tableView cellForRowAtIndexPath:indexPath(0,2)];SC([row.textLabel.text isEqual:@"FEsubscriptions"] && row.textLabel.adjustsFontSizeToFitWidth);
    SC(row.imageView.image.renderingMode==UIImageRenderingModeAlwaysTemplate && row.imageView.image.size.width==24);
    UITableViewCell *flag=[vc tableView:vc.tableView cellForRowAtIndexPath:indexPath(0,0)];vc.tableView.recoveredCells[indexPath(0,0)]=flag;
    SC([flag.textLabel.text isEqual:@"TranslucentBar"]);ABCSwitch *control=(id)flag.accessoryView;
    NSUInteger refreshes=SettingsEventCount(@"refreshPivotBar");[vc tableView:vc.tableView didSelectRowAtIndexPath:indexPath(0,0)];
    SC(control.isOn && [SettingsDefaults boolForKey:@"frostedPivot"] && SettingsEventCount(@"refreshPivotBar")==refreshes+2);
    SC([vc.tableView.recoveredDeselected isEqual:indexPath(0,0)]);
    SC(![vc tableView:vc.tableView canEditRowAtIndexPath:indexPath(0,0)] && [vc tableView:vc.tableView canEditRowAtIndexPath:indexPath(0,2)] && [vc tableView:vc.tableView canEditRowAtIndexPath:indexPath(0,3)]);
    SC([vc tableView:vc.tableView canMoveRowAtIndexPath:indexPath(0,2)] && ![vc tableView:vc.tableView canMoveRowAtIndexPath:indexPath(0,3)]);
    NSIndexPath *source=indexPath(0,2),*target=indexPath(2,2),*other=indexPath(0,3);
    SC([vc tableView:vc.tableView targetIndexPathForMoveFromRowAtIndexPath:source toProposedIndexPath:target]==target);
    SC([vc tableView:vc.tableView targetIndexPathForMoveFromRowAtIndexPath:source toProposedIndexPath:other]==source);
    SC([vc tableView:vc.tableView editingStyleForRowAtIndexPath:source]==UITableViewCellEditingStyleDelete);
    SC([vc tableView:vc.tableView editingStyleForRowAtIndexPath:other]==UITableViewCellEditingStyleInsert);
    // Original fallback checks inactive section INDEX != 0, even for section 0.
    SC([vc tableView:vc.tableView editingStyleForRowAtIndexPath:indexPath(0,0)]==UITableViewCellEditingStyleInsert);
    YTHeaderContentComboViewController *host=[YTHeaderContentComboViewController new];vc.parentViewController=host;
    [vc tableView:vc.tableView moveRowAtIndexPath:source toIndexPath:indexPath(99,2)];
    SC([[SettingsDefaults objectForKey:@"activeTabs"]isEqual:@[@"FEwhat_to_watch",@"FEuploads",@"FEsubscriptions"]]);
    SC([vc.tableView.recoveredReloadedSections isEqual:[NSIndexSet indexSetWithIndex:1]] && vc.tableView.recoveredAnimation==UITableViewRowAnimationAutomatic);
    SC(SettingsEventCount(@"hideHeaderButtons")>0);
    [vc tableView:vc.tableView moveRowAtIndexPath:indexPath(2,2) toIndexPath:indexPath(0,2)];
    SC([[SettingsDefaults objectForKey:@"activeTabs"]isEqual:@[@"FEsubscriptions",@"FEwhat_to_watch",@"FEuploads"]]);
    [SettingsDefaults setObject:@"FEsubscriptions" forKey:@"startupTab"];
    NSUInteger inactive=[[vc valueForKey:@"_inactiveTabs"]count];
    [vc tableView:vc.tableView commitEditingStyle:UITableViewCellEditingStyleDelete forRowAtIndexPath:indexPath(0,2)];
    SC([[SettingsDefaults objectForKey:@"activeTabs"]isEqual:@[@"FEwhat_to_watch",@"FEuploads"]]);
    SC([[SettingsDefaults objectForKey:@"startupTab"]isEqual:@"FEwhat_to_watch"]);
    SC([vc.tableView.recoveredMoveDestination isEqual:indexPath((NSInteger)inactive,3)]);
    [vc tableView:vc.tableView commitEditingStyle:UITableViewCellEditingStyleInsert forRowAtIndexPath:indexPath((NSInteger)inactive,3)];
    SC([[SettingsDefaults objectForKey:@"activeTabs"]isEqual:@[@"FEwhat_to_watch",@"FEuploads",@"FEsubscriptions"]]);
    SC([vc.tableView.recoveredMoveDestination isEqual:indexPath(2,2)]);
    vc=tabController(@[@"FEwhat_to_watch"],@"FEwhat_to_watch");
    [vc tableView:vc.tableView commitEditingStyle:UITableViewCellEditingStyleDelete forRowAtIndexPath:indexPath(0,2)];
    SC([[SettingsDefaults objectForKey:@"activeTabs"]count]==1 && SettingsLastAlert.shown && [SettingsLastAlert.subtitle isEqual:@"AtLeastOneTab"]);
    vc=tabController([all subarrayWithRange:NSMakeRange(0,6)],@"FEwhat_to_watch");
    [vc tableView:vc.tableView commitEditingStyle:UITableViewCellEditingStyleInsert forRowAtIndexPath:indexPath(0,3)];
    SC([[SettingsDefaults objectForKey:@"activeTabs"]count]==6 && [SettingsLastAlert.subtitle isEqual:@"TabsCountRestricted"]);
    vc=tabController([all subarrayWithRange:NSMakeRange(0,7)],@"FEwhat_to_watch");
    [vc tableView:vc.tableView commitEditingStyle:UITableViewCellEditingStyleInsert forRowAtIndexPath:indexPath(0,3)];SC([[SettingsDefaults objectForKey:@"activeTabs"]count]==8);
    vc=tabController(@[@"FEwhat_to_watch",@"FEuploads"],@"FEwhat_to_watch");
    [vc tableView:vc.tableView commitEditingStyle:UITableViewCellEditingStyleDelete forRowAtIndexPath:indexPath(0,2)];SC([[SettingsDefaults objectForKey:@"startupTab"]isEqual:@"FEuploads"]);
    vc=tabController(nil,nil);SC([[vc valueForKey:@"_activeTabs"]count]==0 && [[vc valueForKey:@"_inactiveTabs"]count]==14);
    TabbarVC *standalone=[[TabbarVC alloc]initForSettings:NO];SC([standalone.title isEqual:@"Tabbar"] && standalone.navigationItem.rightBarButtonItem.recoveredSystemItem==24);
    [standalone closeButtonTapped];SC([SettingsLastEvent(@"dismiss")boolValue]);
    TabbarVC *defaultInit=[TabbarVC new];SC([[defaultInit valueForKey:@"_isSettings"]boolValue]);
    SC([vc iconImageNamed:@"FEshorts"].size.width==24);SettingsLastAlert=nil;
}
static void testPickerAndCell(void) {
    DVNPickerView *picker=[[DVNPickerView alloc]initWithFrame:CGRectMake(4,9,123,60)];
    UIView *first=[[UIView alloc]initWithFrame:CGRectMake(11,7,40,1)],*second=[[UIView alloc]initWithFrame:CGRectMake(12,13,32,21)],*grandchild=[[UIView alloc]initWithFrame:CGRectMake(9,8,7,6)];
    [first addSubview:grandchild];[picker addSubview:first];[picker addSubview:second];[picker layoutSubviews];
    SC(picker.recoveredLayoutCalls==1);
    SC(CGRectEqualToRect(first.frame,CGRectMake(0,7,123,1)));SC(CGRectEqualToRect(second.frame,CGRectMake(0,13,123,21)));
    SC(CGRectEqualToRect(grandchild.frame,CGRectMake(9,8,7,6)));
    UIScreen.mainScreen.scale=3;YTPTableViewCell *cell=[[YTPTableViewCell alloc]initWithStyle:UITableViewCellStyleValue2 reuseIdentifier:@"test"];
    SC(cell.recoveredSelectionFade==0.3 && cell.backgroundColor.recoveredAlpha==0);
    SC(cell.selectedBackgroundView.backgroundColor.recoveredRed==0.75 && cell.selectedBackgroundView.backgroundColor.recoveredBlue==0.9 && cell.selectedBackgroundView.backgroundColor.recoveredAlpha==0.15);
    SC(cell.textLabel.font.pointSize==16 && cell.textLabel.adjustsFontSizeToFitWidth && cell.detailTextLabel.font.pointSize==12 && cell.detailTextLabel.numberOfLines==0);
    [cell setSelected:YES animated:NO];SC(cell.recoveredSelected && !cell.recoveredSelectionAnimated && cell.layer.borderWidth==1);
    const CGFloat *components=CGColorGetComponents(cell.layer.borderColor);SC(components[0]==0.75 && components[1]==0.5 && components[2]==0.9 && components[3]==0.5);
    [cell setSelected:NO animated:YES];SC(!cell.recoveredSelected && cell.recoveredSelectionAnimated && cell.layer.borderWidth==1 && CGColorGetAlpha(cell.layer.borderColor)==0);
    SC([SettingsLastEvent(@"animation")doubleValue]==0.5);
    UIScreen.mainScreen.scale=2;cell=[[YTPTableViewCell alloc]initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:nil];SC(cell.textLabel.font.pointSize==14);UIScreen.mainScreen.scale=3;
}
static void testSupporters(void) {
    SettingsResetEvents();DVNSupportersVC *vc=[DVNSupportersVC new];(void)vc.view;
    SC([vc.title isEqual:@"L:SpecialThanks"]);WKWebView *web=[vc valueForKey:@"_webView"];UIActivityIndicatorView *indicator=[vc valueForKey:@"_activityIndicator"];
    SC([web isKindOfClass:WKWebView.class] && web.navigationDelegate==vc && !web.opaque && !web.translatesAutoresizingMaskIntoConstraints);
    SC(web.scrollView.contentInsetAdjustmentBehavior==UIScrollViewContentInsetAdjustmentAutomatic);
    SC([web.recoveredRequest.URL.absoluteString isEqual:@"https://dvntm.com/patreon/specialthanks"]);
    SC(indicator.recoveredStyle==UIActivityIndicatorViewStyleMedium && SettingsEventCount(@"constraint")==6);
    NSArray *events=[SettingsEvents copy];BOOL correctBottom=NO,correctTop=NO;
    for(NSDictionary *event in events)if([event[@"kind"]isEqual:@"constraint"]){
        NSLayoutConstraint *constraint=event[@"value"];NSLayoutAnchor *first=constraint.firstAnchor,*second=constraint.secondAnchor;
        if(first.owner==web && [first.kind isEqual:@"bottom"])correctBottom=second.owner==vc.view;
        if(first.owner==web && [first.kind isEqual:@"top"])correctTop=second.owner==vc.view.safeAreaLayoutGuide;
    }
    SC(correctBottom && correctTop);
    [vc webView:web didStartProvisionalNavigation:nil];SC(indicator.recoveredAnimating);
    [vc webView:web didFinishNavigation:nil];SC(!indicator.recoveredAnimating);
    NSError *error=[NSError errorWithDomain:@"fixture" code:42 userInfo:@{NSLocalizedDescriptionKey:@"Network fixture failed"}];
    [vc webView:web didFailProvisionalNavigation:nil withError:error];UILabel *label=(id)vc.view.subviews.lastObject;
    SC([label.text isEqual:@"Network fixture failed"] && label.numberOfLines==0 && label.textAlignment==NSTextAlignmentCenter && !label.translatesAutoresizingMaskIntoConstraints);
    NSUInteger count=vc.view.subviews.count;[vc webView:web didFailProvisionalNavigation:nil withError:error];SC(vc.view.subviews.count==count+1);
    BOOL leading=NO,trailing=NO;for(NSDictionary *event in SettingsEvents)if([event[@"kind"]isEqual:@"constraint"]){NSLayoutConstraint *c=event[@"value"];NSLayoutAnchor *a=c.firstAnchor;if(a.owner==label){if([a.kind isEqual:@"leading"])leading=c.constant==32;if([a.kind isEqual:@"trailing"])trailing=c.constant==-32;}}
    SC(leading && trailing);
}
void SettingsTestTabbarAndViews(void) {
    testTabs();testPickerAndCell();testSupporters();
    printf("Tab/view fixtures: all 14 tabs, ordering/limits/startup, selection/picker layouts and supporters web delegates verified.\n");
}
