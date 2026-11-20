#import "settings_fixture_hosts.h"
#import "../source/Settings/DVNPickerView.h"
#import "../source/Settings/YTPTableViewCell.h"
#import <math.h>

static NSIndexPath *path(NSInteger row,NSInteger section) { return [NSIndexPath indexPathForRow:row inSection:section]; }
static DVNTableViewController *controller(NSArray *cells) {
    DVNSection *section=[DVNSection sectionWithHeader:@"Header" footer:@"Footer" cells:cells identifier:@"fixture"];
    DVNTableModel *model=[DVNTableModel modelWithTitle:@"Fixture" sections:@[section]];
    DVNTableViewController *vc=[[DVNTableViewController alloc]initWithModel:model defaults:(id)SettingsDefaults];
    (void)vc.tableView;SC(model.selfViewController==vc);return vc;
}
static UITableViewCell *render(DVNTableViewController *vc,NSIndexPath *indexPath) {
    UITableViewCell *cell=[vc tableView:vc.tableView cellForRowAtIndexPath:indexPath];vc.tableView.recoveredCells[indexPath]=cell;return cell;
}
static void runAlertAction(NSUInteger index) {
    SC(index<SettingsLastAlert.actions.count);id action=SettingsLastAlert.actions[index];SC(action!=NSNull.null);((void(^)(void))action)();
}
static BOOL containsCell(DVNTableViewController *vc,DVNCell *cell) {
    for(NSInteger i=0;i<[vc tableView:vc.tableView numberOfRowsInSection:0];i++)if([vc _cellForIndexPath:path(i,0)]==cell)return YES;
    return NO;
}

@interface SettingsSequencedCell : DVNCell
@property(nonatomic,strong) NSArray<NSNumber *> *dividerReads,*minimumReads;
@property(nonatomic) NSUInteger dividerCalls,minimumCalls;
@end
@implementation SettingsSequencedCell
- (double)dividerValue {
    if(!self.dividerReads.count)return [super dividerValue];
    NSUInteger index=MIN(self.dividerCalls,self.dividerReads.count-1);self.dividerCalls++;
    return self.dividerReads[index].doubleValue;
}
- (double)minimumValue {
    if(!self.minimumReads.count)return [super minimumValue];
    NSUInteger index=MIN(self.minimumCalls,self.minimumReads.count-1);self.minimumCalls++;
    return self.minimumReads[index].doubleValue;
}
@end

// Independent native-instruction oracles, compiled from this fixture source.
// No bytes or executable mappings from the original image are involved.
static NSInteger nativeTruncate(double value) {
    NSInteger result;
    __asm__ volatile("fcvtzs %x0, %d1" : "=r"(result) : "w"(value));
    return result;
}
static float nativePickerSelection(float value,double minimum) {
    float result;
    __asm__ volatile("fcmp %d1, %d2\n\tfcsel %s0, %s3, %s4, lt"
                     : "=w"(result) : "w"((double)value),"w"(minimum),"w"((float)minimum),"w"(value) : "cc");
    return result;
}
static BOOL sameFP(double actual,double expected) {
    if(isnan(expected))return isnan(actual);
    return actual==expected && (expected!=0 || !!signbit(actual)==!!signbit(expected));
}
static double nativeFooterHeight(double height) {
    double result;
    __asm__ volatile("frintp %d0, %d1\n\tfadd %d0, %d0, %d2" : "=&w"(result) : "w"(height),"w"(10.0));
    return result;
}
static float nativeSliderRound(float value,double divisor,double multiplier) {
    double rounded;
    __asm__ volatile("frinta %d0, %d1" : "=w"(rounded) : "w"((double)value/divisor));
    return (float)(rounded*multiplier);
}
static void testOriginalRounding(void) {
    SettingsSequencedCell *cell=[SettingsSequencedCell new];cell.key=@"rounding";cell.type=6;
    DVNTableViewController *vc=controller(@[cell]);
    const double heights[]={13.9,12.25,-12.25,0.0,-0.0,NAN,INFINITY,-INFINITY,0x1p63,-0x1p63,0x1.fffffffffffffp1023};
    for(NSUInteger i=0;i<sizeof(heights)/sizeof(*heights);i++) {
        SettingsMeasuredFooterHeight=heights[i];
        SC(sameFP([vc tableView:vc.tableView heightForFooterInSection:0],nativeFooterHeight(heights[i])));
    }
    SettingsMeasuredFooterHeight=13.9;
    UISlider *slider=[UISlider new];slider.tag=0;
    const float values[]={.375f,-.375f,.125f,-.125f,0.0f,-0.0f,NAN,INFINITY,-INFINITY,0x1p63f,-0x1p63f,0x1.fffffep127f,0x1p-126f};
    const double divisors[]={.25,.5,1.0,0x1p-1022,NAN};
    for(NSUInteger i=0;i<sizeof(values)/sizeof(*values);i++)for(NSUInteger j=0;j<sizeof(divisors)/sizeof(*divisors);j++) {
        cell.dividerReads=@[@1,@(divisors[j]),@.25];cell.dividerCalls=0;slider.value=values[i];
        [vc sliderValueChanged:slider];float expected=nativeSliderRound(values[i],divisors[j],.25);
        SC(sameFP(slider.value,expected));SC(sameFP(SettingsDefaults.lastFloat,expected));SC(cell.dividerCalls==3);
    }
    for(NSNumber *gate in @[@0,@-1,@(NAN)]) {
        cell.dividerReads=@[gate,@.25,@.25];cell.dividerCalls=0;slider.value=-.375f;[vc sliderValueChanged:slider];
        SC(slider.value==-.375f && SettingsDefaults.lastFloat==-.375f && cell.dividerCalls==1);
    }
}
static void testNativeNumericsAndGetterOrder(void) {
    SettingsSequencedCell *cell=[SettingsSequencedCell new];cell.key=@"numeric";cell.type=7;
    DVNTableViewController *vc=controller(@[cell]);UIPickerView *picker=[UIPickerView new];picker.tag=0;
    const double maxima[]={-INFINITY,-0x1p63,-2.8,-1,0,0.9,42.9,0x1p63,INFINITY,NAN};
    for(NSUInteger i=0;i<sizeof(maxima)/sizeof(maxima[0]);i++) {
        cell.maximumValue=maxima[i];
        SC([vc pickerView:picker numberOfRowsInComponent:0]==nativeTruncate(maxima[i]+1));
    }
    const float values[]={NAN,1,INFINITY,-INFINITY,12.7f,16777216,4,4};
    const double minima[]={2,NAN,2,2,10,16777217.9,INFINITY,-INFINITY};
    for(NSUInteger i=0;i<sizeof(values)/sizeof(values[0]);i++) {
        cell.minimumValue=minima[i];[SettingsDefaults setFloat:values[i]forKey:cell.key];
        UIPickerView *result=[vc timePickerForCell:cell indexPath:path(0,0)];
        SC(result.recoveredSelectedRow==nativeTruncate((double)nativePickerSelection(values[i],minima[i])));
    }
    cell.minimumReads=@[@2,@40];cell.minimumCalls=0;[SettingsDefaults setFloat:1 forKey:cell.key];
    UIPickerView *result=[vc timePickerForCell:cell indexPath:path(0,0)];SC(result.recoveredSelectedRow==2 && cell.minimumCalls==1);
    cell.minimumReads=nil;cell.type=6;cell.dividerReads=@[@0.5,@1,@2];cell.dividerCalls=0;
    UISlider *slider=[UISlider new];slider.tag=0;slider.value=4.2f;
    [vc sliderValueChanged:slider];SC(cell.dividerCalls==3 && slider.value==8.0f && SettingsDefaults.lastFloat==8.0f);
    cell.dividerReads=@[@1,@(NAN),@3];cell.dividerCalls=0;slider.value=4.2f;
    [vc sliderValueChanged:slider];SC(cell.dividerCalls==3 && isnan(slider.value));
}

static void testRenderingAndControls(void) {
    SettingsDefaults=[SettingsMemoryDefaults new];
    DVNCell *sw=[DVNCell cellWithTitle:@"Switch" subtitle:@"sub" type:0 key:@"k0"];
    sw.icon=[UIImage systemImageNamed:@"symbol"];sw.customData=@{@"iconTintColor":UIColor.redColor};
    DVNCell *seg=[DVNCell cellWithTitleIndexes:@[@"A",@"B"] key:@"k1"];
    DVNCell *compact=[DVNCell cellWithTitle:@"Compact" subtitle:nil titleIndexes:@[@"A",@"B"] key:@"k2"];
    DVNCell *menu=[DVNCell cellWithTitle:@"Menu" subtitle:@"Information" titleIndexes:@[@"one",@"two"] type:3 key:@"k3"];
    DVNCell *child=[DVNCell controllerCellWithModel:[DVNTableModel model] title:@"Child" subtitle:nil icon:nil];
    DVNCell *button=[DVNCell cellWithTitle:@"Button" subtitle:@"base" handler:nil];
    button.subtitleProvider=(DVNStoredBlock)^NSString * { return @"provider"; };
    button.image=[UIImage systemImageNamed:@"photo"];button.accessoryIcon=[UIImage systemImageNamed:@"accessory"];
    DVNCell *slider=[DVNCell sliderCellWithMinimum:1 maximum:10 divider:0.25 format:1 key:@"k6"];
    DVNCell *picker=[DVNCell timePickerWithTitle:@"Time" subtitle:nil minimum:2 maximum:20 format:2 key:@"k7"];
    DVNCell *color=[DVNCell cellWithTitle:@"Color" subtitle:nil type:8 key:@"k8"];
    DVNCell *stepper=[DVNCell stepperCellWithTitle:@"Step" subtitle:nil minimum:1 maximum:10 step:0.5 format:0 key:@"k9"];
    DVNCell *text=[DVNCell textFieldCellWithTitle:@"Text" subtitle:nil placeholder:@"placeholder" key:@"k10"];
    DVNCell *editor=[DVNCell cellWithTitle:@"Editor" subtitle:nil type:11 key:@"k11"];editor.detailText=@"fallback";
    DVNCell *generic=[DVNCell cellWithTitle:@"Generic" subtitle:@"detail" type:12 key:nil];
    NSArray *models=@[sw,seg,compact,menu,child,button,slider,picker,color,stepper,text,editor,generic];
    [SettingsDefaults setObject:@1 forKey:@"k0"];[SettingsDefaults setInteger:1 forKey:@"k1"];[SettingsDefaults setInteger:0 forKey:@"k2"];
    [SettingsDefaults setInteger:1 forKey:@"k3"];[SettingsDefaults setFloat:3.6f forKey:@"k6"];[SettingsDefaults setFloat:1 forKey:@"k7"];
    [SettingsDefaults setFloat:2.5f forKey:@"k9"];[SettingsDefaults setObject:@"12345678901234567890" forKey:@"k11"];
    NSData *archive=[NSKeyedArchiver archivedDataWithRootObject:[UIColor colorWithRed:0.2 green:0.3 blue:0.4 alpha:0.5] requiringSecureCoding:NO error:NULL];
    [SettingsDefaults setObject:archive forKey:@"k8"];
    DVNTableViewController *vc=controller(models);NSMutableArray *views=[NSMutableArray array];
    SC([vc numberOfSectionsInTableView:vc.tableView]==1);SC([vc tableView:vc.tableView numberOfRowsInSection:0]==13);
    for(NSInteger i=0;i<13;i++){
        UITableViewCell *cell=render(vc,path(i,0));DVNCell *model=models[(NSUInteger)i];[views addObject:cell];
        SC([cell isKindOfClass:YTPTableViewCell.class]);SC(model.sourceView==cell);SC([cell.reuseIdentifier isEqual:model.reuseIdentifier]);
        SC(cell.recoveredStyle==((i==6 || i==11 || i==12)?UITableViewCellStyleSubtitle:UITableViewCellStyleValue2));
    }
    SC(SettingsEventCount(@"dequeue")==0);
    UITableViewCell *switchView=views[0];ABCSwitch *switchControl=(id)switchView.accessoryView;
    SC([switchControl isKindOfClass:ABCSwitch.class] && switchControl.isOn && switchControl.tag==0);
    SC(switchControl.offTrackColor.recoveredAlpha==0.5);SC(switchView.imageView.image.renderingMode==UIImageRenderingModeAlwaysTemplate);
    SC(switchView.imageView.tintColor.recoveredRed==1);SC(switchView.imageView.image.size.width==24);
    UITableViewCell *full=views[1];UISegmentedControl *fullSegment=(id)full.contentView.subviews.lastObject;
    SC([fullSegment isKindOfClass:UISegmentedControl.class] && !fullSegment.translatesAutoresizingMaskIntoConstraints && fullSegment.selectedSegmentIndex==1);
    SC([[(UITableViewCell *)views[2]accessoryView]isKindOfClass:UISegmentedControl.class]);
    SC([(UISegmentedControl *)[(UITableViewCell *)views[2]accessoryView]translatesAutoresizingMaskIntoConstraints]);
    UITableViewCell *menuView=views[3];UIButton *menuButton=(id)menuView.accessoryView;
    SC(menuView.detailTextLabel.text==nil);SC([menuButton.recoveredTitle isEqual:@"two "]);SC(menuButton.showsMenuAsPrimaryAction);
    SC([(UITableViewCell *)views[4]accessoryType]==UITableViewCellAccessoryDisclosureIndicator);
    UITableViewCell *buttonView=views[5];SC([buttonView.detailTextLabel.text isEqual:@"provider"]);
    SC(buttonView.imageView.image.renderingMode==UIImageRenderingModeAlwaysOriginal && buttonView.imageView.image.size.width==32);
    SC([(UIImageView *)buttonView.accessoryView image].size.width==20 && buttonView.accessoryView.tintColor.recoveredAlpha==0.75);
    UITableViewCell *sliderView=views[6];UISlider *sliderControl=(id)sliderView.contentView.subviews.lastObject;
    SC(sliderControl.minimumValue==1 && sliderControl.maximumValue==10 && sliderControl.value==3.6f && sliderControl.tag==6);
    SC([sliderView.detailTextLabel.text isEqual:@"3.60x"]);SC(sliderControl.recoveredThumb.size.width==12 && sliderControl.recoveredThumb.size.height==15);
    DVNPickerView *pickerControl=(id)[(UITableViewCell *)views[7]accessoryView];SC([pickerControl isKindOfClass:DVNPickerView.class]);
    SC(pickerControl.recoveredSelectedRow==2 && pickerControl.frame.size.width==80 && pickerControl.frame.size.height==60);
    SC(pickerControl.delegate==vc && pickerControl.dataSource==vc);
    UIColorWell *well=(id)[(UITableViewCell *)views[8]accessoryView];SC(well.supportsAlpha && [well.title isEqual:@"Color"]);
    SC(well.selectedColor.recoveredBlue==0.4 && well.selectedColor.recoveredAlpha==0.5);
    UIStepper *stepControl=(id)[(UITableViewCell *)views[9]accessoryView];SC(stepControl.value==2.5 && stepControl.stepValue==0.5);
    SC([[(UITableViewCell *)views[9]textLabel].text isEqual:@"Step • 2.5"]);
    UITextField *field=(id)[(UITableViewCell *)views[10]contentView].subviews.lastObject;
    SC(field.tag==10 && field.delegate==vc && field.font.pointSize==14 && [field.placeholder isEqual:@"placeholder"]);
    SC([[(UITableViewCell *)views[11]detailTextLabel].text isEqual:@"123456789012345..."]);
    SC([(UITableViewCell *)views[11]detailTextLabel].numberOfLines==1);
    UITableViewCell *fresh=[vc tableView:vc.tableView cellForRowAtIndexPath:path(0,0)];SC(fresh!=switchView && sw.sourceView==fresh);
    sw.sourceView=switchView;
    [vc tableView:vc.tableView didSelectRowAtIndexPath:path(0,0)];SC(!switchControl.isOn && ![SettingsDefaults boolForKey:@"k0"]);
    SC(SettingsEventCount(@"haptic")==3);SC([vc.tableView.recoveredDeselected isEqual:path(0,0)]);
    [vc tableView:vc.tableView didSelectRowAtIndexPath:path(3,0)];SC(SettingsLastAlert.shown && [SettingsLastAlert.subtitle isEqual:@"Information"]);
    [vc tableView:vc.tableView didSelectRowAtIndexPath:path(8,0)];SC(SettingsEventCount(@"colorPicker")==1);
    fullSegment.selectedSegmentIndex=((NSInteger)1<<45)+7;[vc setSegment:fullSegment];SC([SettingsDefaults integerForKey:@"k1"]==fullSegment.selectedSegmentIndex);
    sliderControl.value=3.74f;[vc sliderValueChanged:sliderControl];SC(sliderControl.value==3.75f && SettingsDefaults.lastFloat==3.75f);
    SC([sliderView.detailTextLabel.text isEqual:@"3.75x"]);
    sliderControl.value=-3.74f;[vc sliderValueChanged:sliderControl];SC(sliderControl.value==-3.75f);
    stepControl.value=1.234567890123;[vc stepperValueChanged:stepControl];SC(SettingsDefaults.lastFloat==(float)stepControl.value);
    SC([[(UITableViewCell *)views[9]textLabel].text isEqual:@"Step • 1.2"]);
    [vc pickerView:pickerControl didSelectRow:0 inComponent:0];SC(SettingsDefaults.lastFloat==2 && pickerControl.recoveredSelectedRow==2 && pickerControl.recoveredSelectedAnimated);
    SC([vc numberOfComponentsInPickerView:pickerControl]==1 && [vc pickerView:pickerControl numberOfRowsInComponent:0]==21);
    UILabel *pickerLabel=(id)[vc pickerView:pickerControl viewForRow:9 forComponent:0 reusingView:nil];SC(pickerLabel.font.pointSize==13 && pickerLabel.textAlignment==NSTextAlignmentCenter);
    SC([vc pickerView:pickerControl viewForRow:10 forComponent:0 reusingView:pickerLabel]==pickerLabel);
    well.selectedColor=[UIColor colorWithRed:0.8 green:0.7 blue:0.6 alpha:0.4];[vc colorWellTap:well];
    UIColor *decoded=[NSKeyedUnarchiver unarchivedObjectOfClass:UIColor.class fromData:[SettingsDefaults objectForKey:@"k8"]error:NULL];SC(decoded.recoveredRed==0.8 && decoded.recoveredAlpha==0.4);
    field.text=@" \t ";[vc titleValue:field];SC([SettingsDefaults objectForKey:@"k10"]==nil && [field.text isEqual:@""] && [field.placeholder isEqual:@"placeholder"]);
    field.text=@"\n";[vc titleValue:field];SC([[SettingsDefaults objectForKey:@"k10"]isEqual:@"\n"]);
    field.text=@"new value";[vc titleValue:field];SC([[SettingsDefaults objectForKey:@"k10"]isEqual:@"new value"]);
    NSUInteger reloads=vc.tableView.recoveredReloads;SC([vc textFieldShouldReturn:field]);SC(field.recoveredResignCalls==1 && vc.tableView.recoveredReloads==reloads+1);
    SC([[vc formatSliderValue:1.235 format:1]isEqual:@"1.24x"]);SC([[vc formatSliderValue:1.235 format:0]isEqual:@"1.2"]);
    NSDateComponentsFormatter *formatter=[NSDateComponentsFormatter new];formatter.unitsStyle=(NSDateComponentsFormatterUnitsStyle)2;SC([[vc formatSliderValue:73 format:2]isEqual:[formatter stringFromTimeInterval:73]]);
    SC([[vc formatSliderValue:1.235 format:99]isEqual:@"1.2"]);
    SC([vc tableView:vc.tableView heightForRowAtIndexPath:path(0,0)]==UITableViewAutomaticDimension);
    SC([vc tableView:vc.tableView heightForFooterInSection:0]==24);
    SC([SettingsLastEvent(@"boundingRect")[@"width"]doubleValue]==350);
    UITableViewHeaderFooterView *header=[UITableViewHeaderFooterView new],*footer=[UITableViewHeaderFooterView new];
    [(DVNSection *)vc.model.sections[0]setHeaderIcon:[UIImage systemImageNamed:@"head"]];
    [vc tableView:vc.tableView willDisplayHeaderView:header forSection:0];SC(header.textLabel.font.pointSize==14 && header.textLabel.font.recoveredTestWeight==UIFontWeightLight);
    SC([header.textLabel.text hasSuffix:@" Header"] && header.textLabel.numberOfLines==0);
    [vc tableView:vc.tableView willDisplayFooterView:footer forSection:0];SC(footer.textLabel.font.pointSize==13 && [footer.textLabel.text isEqual:@"Footer"]);
    UIImage *image=[UIImage systemImageNamed:@"render"];SC([vc headerImage:image].size.width==16);SC([vc accessoryImage:image].size.width==20);
    SC([vc iconImage:image mode:UIImageRenderingModeAlwaysOriginal size:0].size.width==24);
    SC([vc iconImage:image mode:UIImageRenderingModeAlwaysTemplate size:31].size.width==31);SC([vc systemImage:@"close" withSize:17].size.width==17);
    __block NSUInteger barCalls=0;[vc addLeftBarItem:@"left" image:image handler:^{barCalls++;}];[vc addRightBarItem:@"right" image:nil handler:^{barCalls+=2;}];
    [vc _barButtonTriggered:vc.navigationItem.leftBarButtonItem];[vc _barButtonTriggered:vc.navigationItem.rightBarButtonItem];SC(barCalls==3);
    SC(vc.navigationItem.leftBarButtonItem.image==image);[vc addDismissButton:YES];SC(vc.navigationItem.leftBarButtonItem.recoveredSystemItem==24);
    [vc addDismissButton:NO];SC(vc.navigationItem.rightBarButtonItem.recoveredSystemItem==24);[vc closeButtonTapped];SC([SettingsLastEvent(@"dismiss")boolValue]);
    reloads=vc.tableView.recoveredReloads;[NSNotificationCenter.defaultCenter postNotificationName:@"DVNAccStatusChanged" object:nil];SC(vc.tableView.recoveredReloads==reloads+1);
    SettingsLastAlert=nil;
}

static void testSelectionAndEditor(void) {
    DVNCell *button=[DVNCell cellWithTitle:@"Action" subtitle:nil handler:nil];DVNTableViewController *vc=controller(@[button]);UITableViewCell *view=render(vc,path(0,0));
    __block NSUInteger regular=0,selfCalls=0,completionCalls=0;__block void(^completion)(void);
    button.handler=(DVNStoredBlock)^{regular++;};button.selfHandler=(DVNStoredBlock)^(DVNCell *cell){SC(cell==button && cell.sourceView==view);selfCalls++;};
    button.handlerWithCompletion=(DVNStoredBlock)^(void(^done)(void)){completionCalls++;completion=[done copy];};button.reloadsCell=YES;button.reloadsTable=YES;
    NSUInteger reloads=vc.tableView.recoveredReloads;[vc tableView:vc.tableView didSelectRowAtIndexPath:path(0,0)];
    SC(regular==1 && selfCalls==0 && completionCalls==0 && vc.tableView.recoveredReloads==reloads+1 && SettingsPending()==1);
    SettingsDrain();SC([vc.tableView.recoveredReloadedRows isEqual:@[path(0,0)]] && vc.tableView.recoveredAnimation==UITableViewRowAnimationNone);
    button.handler=nil;[vc tableView:vc.tableView didSelectRowAtIndexPath:path(0,0)];SC(selfCalls==1 && completionCalls==0);SettingsDrain();
    button.selfHandler=nil;view.detailTextLabel.text=@"previous";[vc tableView:vc.tableView didSelectRowAtIndexPath:path(0,0)];
    SC(completionCalls==1 && completion && [view.accessoryView isKindOfClass:UIActivityIndicatorView.class] && view.detailTextLabel.text==nil);
    SC([(UIActivityIndicatorView *)view.accessoryView recoveredAnimating]);reloads=vc.tableView.recoveredReloads;
    completion();completion=nil;SC(view.accessoryView==nil && vc.tableView.recoveredReloads==reloads+1 && SettingsPending()==1);SettingsDrain();button.handlerWithCompletion=nil;
    DVNCell *editor=[DVNCell cellWithTitle:@"Editable" subtitle:nil type:11 key:@"edit"];
    editor.errorText=@"Invalid";editor.detailText=@"Hidden";[SettingsDefaults setObject:@"original" forKey:@"edit"];
    vc=controller(@[editor]);[vc editorForIndexPath:path(0,0)];
    SC([SettingsLastAlert.actionTitles isEqual:@[@"L:Copy",@"L:Save",@"L:Cancel"]]);SC(SettingsLastAlert.actions[2]==NSNull.null);
    UITextView *text=(id)SettingsLastAlert.customContentView.subviews[0];SC([text.text isEqual:@"original"] && text.editable && text.scrollEnabled);
    SC(text.frame.size.width==270 && text.frame.size.height==75 && text.layer.cornerRadius==3);
    text.text=@"copied";runAlertAction(0);SC([UIPasteboard.generalPasteboard.string isEqual:@"copied"]);
    editor.validationHandler=(DVNStoredBlock)^NSString *(NSString *input){return [@"validated:" stringByAppendingString:input];};
    NSUInteger syncs=SettingsDefaults.synchronizations;reloads=vc.tableView.recoveredReloads;runAlertAction(1);
    SC([[SettingsDefaults objectForKey:@"edit"]isEqual:@"validated:copied"] && SettingsDefaults.synchronizations==syncs+1 && vc.tableView.recoveredReloads==reloads);
    SettingsDrain();SC(vc.tableView.recoveredReloads==reloads+1);
    editor.validationHandler=(DVNStoredBlock)^NSString *(NSString *input){(void)input;return nil;};runAlertAction(1);
    SC(SettingsPending()==0 && SettingsDefaults.synchronizations==syncs+1);SC([SettingsLastEvent(@"toast")[@"text"]isEqual:@"Invalid"] && ![SettingsLastEvent(@"toast")[@"success"]boolValue]);
    editor.validationHandler=nil;text.text=@"plain";runAlertAction(1);SC([[SettingsDefaults objectForKey:@"edit"]isEqual:@"plain"]);SettingsDrain();
    editor.shouldHideDetail=YES;view=render(vc,path(0,0));SC([view.detailTextLabel.text isEqual:@"Hidden"]);
    editor.shouldHideDetail=NO;[SettingsDefaults removeObjectForKey:@"edit"];view=render(vc,path(0,0));SC([view.detailTextLabel.text isEqual:@"Hidden"]);
    [SettingsDefaults setObject:@"" forKey:@"edit"];view=render(vc,path(0,0));SC([view.detailTextLabel.text isEqual:@""]);
    [SettingsDefaults setInteger:-4 forKey:@"menu"];syncs=SettingsDefaults.synchronizations;
    UIButton *menu=[vc menuButtonWithTitle:@"title" array:@[@"same",@"same",@"last"] key:@"menu"];
    SC([SettingsDefaults integerForKey:@"menu"]==0 && SettingsDefaults.synchronizations==syncs+1);
    SC(menu.menu.children.count==3 && [(UIAction *)menu.menu.children[0]state]==UIMenuElementStateOn && [(UIAction *)menu.menu.children[1]state]==UIMenuElementStateOn);
    UIAction *duplicate=menu.menu.children[1];duplicate.recoveredHandler(duplicate);SC([SettingsDefaults integerForKey:@"menu"]==0);
    UIAction *last=menu.menu.children[2];last.recoveredHandler(last);SC([SettingsDefaults integerForKey:@"menu"]==2);
    vc.view.semanticContentAttribute=UISemanticContentAttributeForceRightToLeft;SC([vc isRTL]);
    menu=[vc menuButtonWithTitle:@"title" array:@[@"a"] key:@"menu"];SC(menu.semanticContentAttribute==UISemanticContentAttributeForceLeftToRight);
    BOOL raised=NO;@try{(void)[vc menuButtonWithTitle:@"empty" array:@[] key:@"empty"];}@catch(NSException *e){(void)e;raised=YES;}SC(raised);
    SettingsLastAlert=nil;
}

static void testSearchProvidersAndPresentation(void) {
    DVNCell *title=[DVNCell cellWithTitle:@"Alphabet" subtitle:nil type:0 key:@"a"];
    DVNCell *sub=[DVNCell cellWithTitle:@"No" subtitle:@"Beta" type:0 key:@"b"];
    DVNCell *identifier=[DVNCell cellWithTitle:@"None" subtitle:nil type:0 key:@"c"];
    DVNCell *options=[DVNCell cellWithTitleIndexes:@[@"Choice"] key:@"d"];
    DVNCell *provider=[DVNCell cellWithTitle:@"Provider" subtitle:nil type:3 key:@"e"];
    __block NSUInteger titleProviders=0;provider.titleIndexesProvider=(DVNStoredBlock)^NSArray *{titleProviders++;return @[@"Dynamic"];};
    DVNCell *nested=[DVNCell cellWithTitle:@"Nested" subtitle:nil type:0 key:@"n"];
    DVNTableModel *child=[DVNTableModel modelWithTitle:@"Child" sections:@[[DVNSection sectionWithCells:@[nested] identifier:@"child"]]];child.supportsSearching=YES;
    DVNCell *controllerCell=[DVNCell controllerCellWithModel:child title:@"NeverControllerSearch" subtitle:nil icon:nil];
    DVNTableViewController *vc=controller(@[title,sub,identifier,options,provider,controllerCell]);identifier.identifier=@"IdentifierNeedle";
    vc.model.supportsSearching=YES;vc.model.header=@"head";vc.model.footer=@"foot";[vc viewDidLoad];SettingsDrain();
    UISearchBar *bar=[vc valueForKey:@"_searchBar"];SC(bar==vc.tableView.tableHeaderView && bar.frame.size.height==45 && vc.tableView.tableFooterView!=nil);
    SC(!bar.searchTextField.enablesReturnKeyAutomatically && !bar.searchTextField.translatesAutoresizingMaskIntoConstraints);
    NSArray *queries=@[@"ALPH",@"beta",@"identifierneedle",@"CHOICE",@"DYNAMIC",@"nested"];
    NSArray *found=@[title,sub,identifier,options,provider,nested];
    for(NSUInteger i=0;i<queries.count;i++){[vc _performSearch:queries[i]];SC([vc numberOfSectionsInTableView:vc.tableView]==1);SC(containsCell(vc,found[i]));SC([vc tableView:vc.tableView titleForHeaderInSection:0]==nil);SC([vc tableView:vc.tableView titleForFooterInSection:0]==nil);}
    SC(titleProviders>0);[vc _performSearch:@"NeverControllerSearch"];SC([vc tableView:vc.tableView numberOfRowsInSection:0]==0);
    child.supportsSearching=NO;[vc _performSearch:@"nested"];SC([vc tableView:vc.tableView numberOfRowsInSection:0]==0);child.supportsSearching=YES;
    [vc _performSearch:@""];SC([vc tableView:vc.tableView numberOfRowsInSection:0]==6);
    __block NSUInteger providers=0;DVNCell *dynamic=[DVNCell cellWithTitle:@"LiveOnly" subtitle:nil type:0 key:@"live"];
    DVNSection *section=vc.model.sections[0];NSArray *stored=section.cells;section.cellsProvider=^NSArray *{providers++;return @[dynamic];};
    SC([vc _cellsForSection:section][0]==dynamic && [vc _cellsForSection:section][0]==dynamic && providers==2);
    [vc _performSearch:@"LiveOnly"];SC([vc tableView:vc.tableView numberOfRowsInSection:0]==0);
    [vc _performSearch:@"alphabet"];SC(containsCell(vc,title));[vc _performSearch:@""];SC([vc _cellForTag:0]==dynamic);
    section.cellsProvider=^NSArray *{return nil;};SC([vc _cellsForSection:section]==nil && section.cells==stored);section.cellsProvider=nil;
    UIView *corner=[UIView new],*grandchild=[UIView new];corner.layer.cornerRadius=7;grandchild.layer.cornerRadius=9;[corner addSubview:grandchild];[bar.searchTextField addSubview:corner];
    [vc _removeSearchFieldCornerRadius:bar];SC(corner.layer.cornerRadius==7);SettingsDrain();SC(corner.layer.cornerRadius==0 && grandchild.layer.cornerRadius==9);
    [vc searchBarTextDidBeginEditing:bar];SC(bar.searchTextField.rightViewMode==UITextFieldViewModeAlways && [bar.searchTextField.rightView isKindOfClass:YTQTMButton.class]);SettingsDrain();
    [vc searchBarTextDidEndEditing:bar];SC(bar.searchTextField.rightView==nil && bar.searchTextField.rightViewMode==UITextFieldViewModeNever);SettingsDrain();
    [vc searchBar:bar textDidChange:@"alphabet"];SC(containsCell(vc,title));SettingsDrain();
    [vc searchBarCancelButtonClicked:bar];SC([bar.text isEqual:@""] && [vc tableView:vc.tableView numberOfRowsInSection:0]==6);
    NSUInteger resigned=bar.recoveredResignCalls;[vc searchBarSearchButtonClicked:bar];SC(bar.recoveredResignCalls==resigned+1);
    bar.text=@"alpha";[vc _searchClearTapped:nil];SC([bar.text isEqual:@""]);SettingsDrain();
    vc.navigationController=[UINavigationController new];UIViewController *host=[UIViewController new];vc.parentViewController=host;
    UITableViewCell *titleView=render(vc,path(0,0));[vc navigateToCell:title];SC([vc.tableView.recoveredScrolled isEqual:path(0,0)] && vc.tableView.recoveredScrollPosition==UITableViewScrollPositionMiddle);
    SC(SettingsPending()==1);SettingsDrain();SC(titleView.backgroundColor.recoveredAlpha==0 && [SettingsLastEvent(@"animation")doubleValue]==1);
    SC([vc cellExistsInModel:vc.model target:nested]);DVNCell *different=[DVNCell cellWithTitle:@"Nested" subtitle:nil type:0 key:@"n"];SC(![vc cellExistsInModel:vc.model target:different]);
    [vc navigateToCell:nested];YTWrapperFlatViewController *flat=(id)vc.navigationController.recoveredPushedController;
    SC([flat isKindOfClass:YTWrapperFlatViewController.class] && [flat.title isEqual:@"NeverControllerSearch"] && flat.content!=nil && flat.headerViewController.buttons.count==0);
    DVNTableViewController *nestedVC=(id)flat.content;SC(nestedVC.pendingScrollCell==nested && nestedVC.defaults==vc.defaults && nestedVC.model==child);
    (void)nestedVC.tableView;render(nestedVC,path(0,0));[nestedVC viewDidAppear:YES];SC(nestedVC.pendingScrollCell==nil);SettingsDrain();
    UIViewController *destination=[UIViewController new];YTWrapperSplitViewController *split=[[YTWrapperSplitViewController alloc]initWithParentResponder:nil];
    split.secondViewController=[UIViewController new];host.parentViewController=split;[vc pushController:destination withTitle:@"split"];
    SC([split.secondViewController isKindOfClass:YTWrapperSplitViewController.class]);YTWrapperSplitViewController *replacement=(id)split.secondViewController;
    SC(replacement.content==destination && [replacement.title isEqual:@"split"] && replacement.recoveredResponder==host);
    split.secondViewController=nil;[vc pushController:destination withTitle:@"flat"];SC([vc.navigationController.recoveredPushedController isKindOfClass:YTWrapperFlatViewController.class]);
    [vc _performSearch:@"alphabet"];[vc tableView:vc.tableView didSelectRowAtIndexPath:path(0,0)];SC([bar.text isEqual:@""] && [vc.tableView.recoveredScrolled isEqual:path(0,0)]);SettingsDrain();
    [vc setupThanksHeart];UILabel *heart=(id)vc.tableView.subviews.lastObject;SC([heart.text isEqual:@"💜"] && heart.font.pointSize==35);
    CABasicAnimation *animation=(id)[heart.layer animationForKey:@"scaleAnimation"];SC([animation.fromValue doubleValue]==0.7 && [animation.toValue doubleValue]==1 && animation.duration==0.5 && animation.autoreverses && isinf(animation.repeatCount));
    __weak DVNTableViewController *weak;DVNTableModel *weakModel=[DVNTableModel model];
    @autoreleasepool { DVNTableViewController *temporary=[[DVNTableViewController alloc]initWithModel:weakModel defaults:(id)SettingsDefaults];weak=temporary;SC(weakModel.selfViewController==temporary); }
    SC(weak==nil && weakModel.selfViewController==nil);
    [vc viewWillAppear:NO];SettingsDrain();UITraitCollection *traits=[UITraitCollection new];vc.traitCollection.recoveredDifferentAppearance=NO;
    [vc traitCollectionDidChange:traits];SC(SettingsPending()==0);vc.traitCollection.recoveredDifferentAppearance=YES;[vc traitCollectionDidChange:traits];SC(SettingsPending()==1);SettingsDrain();
}

void SettingsTestController(void) {
    SettingsDrain();SettingsResetEvents();testOriginalRounding();testNativeNumericsAndGetterOrder();SettingsResetEvents();testRenderingAndControls();SettingsDrain();testSelectionAndEditor();SettingsDrain();testSearchProvidersAndPresentation();SettingsDrain();
    printf("Controller fixtures: all 13 cell types, callbacks, search/providers, numeric widths, menus/editors and presentation verified.\n");
}
