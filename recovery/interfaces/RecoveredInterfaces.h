// Recovered from Objective-C runtime metadata in the supplied 5.2.2 package.
// Block signatures, generics and nullability are absent from method encodings.
// id represents an opaque object or block where metadata has no further type.
#pragma once
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@class InitWorkaround, WelcomeVC, DownloadMenuHelper, YTPTableViewCell, DVNPickerView, DVNTableViewController, TabbarVC, YTPSettingsBuilder, DVNTableModel, DVNSection, DVNCell, DVNSupportersVC, SBSegment, SBPlaybackController, SBManager, SBPlayerDecorator, SBPlayerDecorationData, DVNMediaPicker, YTPMedia, DVNHorizontalPanDelegate, ToastView, ToastWindow, ToastManager, YTPAPIHelper, Downloader, AudioManager, YTPDownloader, SbWhitelistVC, YTPTranslator, TranslatorVC, YTLUserDefaults, DVNSheetPresenter, PseudoDetentController, PseudoDetentTransitioningDelegate, DVNLongPressDelegate, YTPPlayerHelper, FFMpegHelper, SRTParser, YTPDB, YTPSleepTimer, RPCMedia, YTPDiscordRPC, DVNImageViewController, BlurButton, YTPSpeedMaster, Dvbug, YTLHelper, YTPSpeedPopupController, YTPSpeedControlView, PlayerToast, CustomHUD, ArchDetect, AtomicLong, FFmpegExecution, MobileFFmpeg, CallbackData, MobileFFmpegConfig, Statistics;

@interface InitWorkaround : UIViewController
// 0x14cc0; v16@0:8
- (void)viewDidLoad;
// 0x15148; @?16@0:8
- (id)completion;
// 0x15158; v24@0:8@?16
- (void)setCompletion:(id)arg1;
@end

@interface WelcomeVC : UIViewController
// 0x3c314; v16@0:8
- (void)viewDidLoad;
// 0x3f84c; v16@0:8
- (void)thanksButtonTapped;
// 0x3fa3c; v24@0:8@16
- (void)contactsButtonTapped:(id)arg1;
// 0x42c68; @24@0:8@16
- (id)imageNamed:(id)arg1;
// 0x42d00; d32@0:8@16@24
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
// 0x42d10; q24@0:8@16
- (long long)numberOfSectionsInTableView:(id)arg1;
// 0x42d18; q32@0:8@16q24
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
// 0x42d30; v40@0:8@16@24@32
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forRowAtIndexPath:(id)arg3;
// 0x42d44; @32@0:8@16@24
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
// 0x4343c; B32@0:8@16@24
- (BOOL)tableView:(id)arg1 shouldHighlightRowAtIndexPath:(id)arg2;
// 0x43444; v32@0:8@16@24
- (void)showAlertWithTitle:(id)arg1 imageName:(id)arg2;
// 0x441a8; @24@0:8@16
- (id)cellImageWithName:(id)arg1;
@end

@interface DownloadMenuHelper : NSObject
// 0xfb8a4; v32@0:8@16@24
- (void)showVideoSheet:(id)arg1 withSender:(id)arg2;
// 0xfd8cc; v32@0:8@16@24
- (void)showImagesSheet:(id)arg1 withSender:(id)arg2;
// 0xfeb1c; v32@0:8@16@24
- (void)showInformationSheet:(id)arg1 withSender:(id)arg2;
// 0x101144; v32@0:8@16@24
- (void)showExtPlayerSheet:(id)arg1 withSender:(id)arg2;
// 0x1030f8; @28@0:8@16B24
- (id)getVideoFormatsArray:(id)arg1 isShorts:(BOOL)arg2;
// 0x103a28; @24@0:8@16
- (id)getAudioFormatsArray:(id)arg1;
// 0x1040ec; @32@0:8@16@24
- (id)getBestAudioFormat:(id)arg1 playerVC:(id)arg2;
// 0x1048f4; @24@0:8@16
- (id)getDefaultAudioTrack:(id)arg1;
// 0x104bf8; @24@0:8@16
- (id)getEnglishAudioTrack:(id)arg1;
// 0x104ffc; @24@0:8@16
- (id)detailForMimeType:(id)arg1;
// 0x1054dc; q24@0:8@16
- (long long)getResoForQuality:(id)arg1;
// 0x1055f4; v72@0:8@16@24@32@40@48@56@64
- (void)downloadVideoWithFormat:(id)arg1 withAudioFormats:(id)arg2 fileName:(id)arg3 extension:(id)arg4 videoID:(id)arg5 playerVC:(id)arg6 sender:(id)arg7;
// 0x106840; v72@0:8@16@24@32@40@48@56@64
- (void)downloadVideoWithFormat:(id)arg1 audioFormat:(id)arg2 fileName:(id)arg3 extension:(id)arg4 videoID:(id)arg5 playerVC:(id)arg6 sender:(id)arg7;
// 0x106c80; v96@0:8@16@24@32@40@48Q56Q64Q72@80@88
- (void)downloadVideoWithUrl:(id)arg1 audioUrl:(id)arg2 fileName:(id)arg3 extension:(id)arg4 videoID:(id)arg5 videoSize:(unsigned long long)arg6 audioSize:(unsigned long long)arg7 duration:(unsigned long long)arg8 captions:(id)arg9 playerVC:(id)arg10;
// 0x107068; v24@0:8@16
- (void)getThumbnail:(id)arg1;
// 0x107a20; v32@0:8q16@?24
- (void)checkSpaceAvailabilityForMedia:(long long)arg1 completion:(id)arg2;
// 0x107f1c; v48@0:8@16@24@32@?40
- (void)showAudioTrackSelector:(id)arg1 sender:(id)arg2 playerVC:(id)arg3 completion:(id)arg4;
// 0x109374; B24@0:8@16
- (BOOL)hasCaptions:(id)arg1;
// 0x109acc; v32@0:8@16@24
- (void)showTranscriptSheet:(id)arg1 withSender:(id)arg2;
// 0x10a9c4; v32@0:8@16@24
- (void)showCaptionsSheet:(id)arg1 withSender:(id)arg2;
// 0x10b9a4; @24@0:8@16
- (id)captionsForDownloading:(id)arg1;
// 0x10c14c; @24@0:8@16
- (id)titleForCaption:(id)arg1;
// 0x10c720; v40@0:8@16@24@?32
- (void)getCaptionsUrlSheet:(id)arg1 sender:(id)arg2 completion:(id)arg3;
// 0x10da34; v32@0:8@16@24
- (void)shareSRT:(id)arg1 sourceView:(id)arg2;
// 0xf5b28; v32@0:8@16@24
+ (void)showDownloadSheetShorts:(id)arg1 withSender:(id)arg2;
// 0xf83b8; v32@0:8@16@24
+ (void)showDownloadSheet:(id)arg1 withSender:(id)arg2;
@end

@interface YTPTableViewCell : UITableViewCell
// 0x1153f4; v24@0:8B16B20
- (void)setSelected:(BOOL)arg1 animated:(BOOL)arg2;
// 0x115638; @32@0:8q16@24
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;
@end

@interface DVNPickerView : UIPickerView
// 0x11603c; v16@0:8
- (void)layoutSubviews;
@end

@interface DVNTableViewController : UITableViewController
// 0x1163f8; @32@0:8@16@24
- (id)initWithModel:(id)arg1 defaults:(id)arg2;
// 0x116764; v16@0:8
- (void)loadView;
// 0x1169e4; v16@0:8
- (void)viewDidLoad;
// 0x118008; v20@0:8B16
- (void)viewWillAppear:(BOOL)arg1;
// 0x118064; v24@0:8@16
- (void)traitCollectionDidChange:(id)arg1;
// 0x118178; v24@0:8@16
- (void)searchBarSearchButtonClicked:(id)arg1;
// 0x1181b0; v24@0:8@16
- (void)_removeSearchFieldCornerRadius:(id)arg1;
// 0x118500; v24@0:8@16
- (void)_performSearch:(id)arg1;
// 0x118ef0; v32@0:8@16@24
- (void)searchBar:(id)arg1 textDidChange:(id)arg2;
// 0x118f70; v24@0:8@16
- (void)searchBarCancelButtonClicked:(id)arg1;
// 0x119004; v24@0:8@16
- (void)searchBarTextDidBeginEditing:(id)arg1;
// 0x11941c; v24@0:8@16
- (void)searchBarTextDidEndEditing:(id)arg1;
// 0x1194e8; v24@0:8@16
- (void)_searchClearTapped:(id)arg1;
// 0x119580; v24@0:8@16
- (void)navigateToCell:(id)arg1;
// 0x119e58; B32@0:8@16@24
- (BOOL)cellExistsInModel:(id)arg1 target:(id)arg2;
// 0x11a490; v24@0:8@16
- (void)highlightRowAtIndexPath:(id)arg1;
// 0x11a718; v20@0:8B16
- (void)viewDidAppear:(BOOL)arg1;
// 0x11a830; v32@0:8@16@24
- (void)pushController:(id)arg1 withTitle:(id)arg2;
// 0x11afa0; v20@0:8B16
- (void)addDismissButton:(BOOL)arg1;
// 0x11b05c; v16@0:8
- (void)closeButtonTapped;
// 0x11b098; v40@0:8@16@24@?32
- (void)addLeftBarItem:(id)arg1 image:(id)arg2 handler:(id)arg3;
// 0x11b2fc; v40@0:8@16@24@?32
- (void)addRightBarItem:(id)arg1 image:(id)arg2 handler:(id)arg3;
// 0x11b560; v24@0:8@16
- (void)_barButtonTriggered:(id)arg1;
// 0x11b6d0; v16@0:8
- (void)setupThanksHeart;
// 0x11bd8c; d32@0:8@16@24
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
// 0x11bd9c; @32@0:8@16q24
- (id)tableView:(id)arg1 titleForHeaderInSection:(long long)arg2;
// 0x11be90; @32@0:8@16q24
- (id)tableView:(id)arg1 titleForFooterInSection:(long long)arg2;
// 0x11bf84; v40@0:8@16@24q32
- (void)tableView:(id)arg1 willDisplayHeaderView:(id)arg2 forSection:(long long)arg3;
// 0x11c4a4; v40@0:8@16@24q32
- (void)tableView:(id)arg1 willDisplayFooterView:(id)arg2 forSection:(long long)arg3;
// 0x11c698; d32@0:8@16q24
- (double)tableView:(id)arg1 heightForFooterInSection:(long long)arg2;
// 0x11c868; q24@0:8@16
- (long long)numberOfSectionsInTableView:(id)arg1;
// 0x11c924; q32@0:8@16q24
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
// 0x11ca5c; @24@0:8@16
- (id)_cellForIndexPath:(id)arg1;
// 0x11cc18; @32@0:8@16@24
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
// 0x11f264; v32@0:8@16@24
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
// 0x1202f4; @32@0:8d16q24
- (id)formatSliderValue:(double)arg1 format:(long long)arg2;
// 0x1205ac; @48@0:8@16q24q32@40
- (id)pickerView:(id)arg1 viewForRow:(long long)arg2 forComponent:(long long)arg3 reusingView:(id)arg4;
// 0x1207bc; q24@0:8@16
- (long long)numberOfComponentsInPickerView:(id)arg1;
// 0x1207c4; q32@0:8@16q24
- (long long)pickerView:(id)arg1 numberOfRowsInComponent:(long long)arg2;
// 0x120834; v40@0:8@16q24q32
- (void)pickerView:(id)arg1 didSelectRow:(long long)arg2 inComponent:(long long)arg3;
// 0x120a04; @24@0:8@16
- (id)headerImage:(id)arg1;
// 0x120c58; @40@0:8@16q24d32
- (id)iconImage:(id)arg1 mode:(long long)arg2 size:(double)arg3;
// 0x120ec8; @24@0:8@16
- (id)accessoryImage:(id)arg1;
// 0x121118; @24@0:8q16
- (id)_cellForTag:(long long)arg1;
// 0x12126c; @24@0:8@16
- (id)_cellsForSection:(id)arg1;
// 0x12137c; @24@0:8@16
- (id)switchForKey:(id)arg1;
// 0x1215f4; v24@0:8@16
- (void)toggleSwitch:(id)arg1;
// 0x12174c; v24@0:8@16
- (void)setSegment:(id)arg1;
// 0x121888; v24@0:8@16
- (void)sliderValueChanged:(id)arg1;
// 0x121bac; v24@0:8@16
- (void)stepperValueChanged:(id)arg1;
// 0x121e08; v24@0:8@16
- (void)colorWellTap:(id)arg1;
// 0x121fa8; B24@0:8@16
- (BOOL)textFieldShouldReturn:(id)arg1;
// 0x122008; v24@0:8@16
- (void)titleValue:(id)arg1;
// 0x122380; @28@0:8@16B24
- (id)segmentForItems:(id)arg1 isCompact:(BOOL)arg2;
// 0x122900; @40@0:8@16d24d32
- (id)sliderWithKey:(id)arg1 min:(double)arg2 max:(double)arg3;
// 0x122c48; @32@0:8@16@24
- (id)timePickerForCell:(id)arg1 indexPath:(id)arg2;
// 0x122e44; @32@0:8@16@24
- (id)stepperForCell:(id)arg1 indexPath:(id)arg2;
// 0x123038; @24@0:8@16
- (id)stepperLabelForCell:(id)arg1;
// 0x123394; @32@0:8@16@24
- (id)colorWellForKey:(id)arg1 title:(id)arg2;
// 0x123508; @24@0:8@16
- (id)textFieldForCell:(id)arg1;
// 0x1237ac; v24@0:8@16
- (void)editorForIndexPath:(id)arg1;
// 0x1245bc; @40@0:8@16@24@32
- (id)menuButtonWithTitle:(id)arg1 array:(id)arg2 key:(id)arg3;
// 0x1250e4; @32@0:8@16d24
- (id)systemImage:(id)arg1 withSize:(double)arg2;
// 0x12534c; B16@0:8
- (BOOL)isRTL;
// 0x1253b8; v16@0:8
- (void)_reloadSections;
// 0x1253f8; v16@0:8
- (void)dealloc;
// 0x125470; @16@0:8
- (id)model;
// 0x125480; v24@0:8@16
- (void)setModel:(id)arg1;
// 0x1254bc; @16@0:8
- (id)defaults;
// 0x1254cc; v24@0:8@16
- (void)setDefaults:(id)arg1;
// 0x125508; @16@0:8
- (id)pendingScrollCell;
// 0x125518; v24@0:8@16
- (void)setPendingScrollCell:(id)arg1;
@end

@interface TabbarVC : DVNTableViewController
// 0x12ea7c; @16@0:8
- (id)init;
// 0x12ea8c; @20@0:8B16
- (id)initForSettings:(BOOL)arg1;
// 0x130ce0; v16@0:8
- (void)loadView;
// 0x130f4c; v16@0:8
- (void)closeButtonTapped;
// 0x130f88; v16@0:8
- (void)initTabs;
// 0x1316d0; v16@0:8
- (void)saveTabsOrder;
// 0x131ee4; @32@0:8@16q24
- (id)tableView:(id)arg1 titleForHeaderInSection:(long long)arg2;
// 0x13248c; @32@0:8@16q24
- (id)tableView:(id)arg1 titleForFooterInSection:(long long)arg2;
// 0x1326e8; q24@0:8@16
- (long long)numberOfSectionsInTableView:(id)arg1;
// 0x132700; q32@0:8@16q24
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
// 0x13275c; @32@0:8@16@24
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
// 0x13379c; @24@0:8@16
- (id)iconImageNamed:(id)arg1;
// 0x133a1c; v32@0:8@16@24
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
// 0x134094; @24@0:8@16
- (id)switchForKey:(id)arg1;
// 0x13432c; v24@0:8@16
- (void)toggleSwitch:(id)arg1;
// 0x134788; @24@0:8@16
- (id)segmentForItems:(id)arg1;
// 0x134f50; v24@0:8@16
- (void)setSegment:(id)arg1;
// 0x135354; B32@0:8@16@24
- (BOOL)tableView:(id)arg1 canEditRowAtIndexPath:(id)arg2;
// 0x135464; B32@0:8@16@24
- (BOOL)tableView:(id)arg1 canMoveRowAtIndexPath:(id)arg2;
// 0x1354c0; @40@0:8@16@24@32
- (id)tableView:(id)arg1 targetIndexPathForMoveFromRowAtIndexPath:(id)arg2 toProposedIndexPath:(id)arg3;
// 0x135540; v40@0:8@16@24@32
- (void)tableView:(id)arg1 moveRowAtIndexPath:(id)arg2 toIndexPath:(id)arg3;
// 0x1356e4; q32@0:8@16@24
- (long long)tableView:(id)arg1 editingStyleForRowAtIndexPath:(id)arg2;
// 0x1357c4; v40@0:8@16q24@32
- (void)tableView:(id)arg1 commitEditingStyle:(long long)arg2 forRowAtIndexPath:(id)arg3;
@end

@interface YTPSettingsBuilder : NSObject
// 0x138f34; @16@0:8
- (id)rootTable;
// 0x13aa40; @16@0:8
- (id)downloadingTable;
// 0x13e384; @16@0:8
- (id)navbarTable;
// 0x13fec0; @16@0:8
- (id)feedTable;
// 0x14218c; @16@0:8
- (id)playerTable;
// 0x156a98; @16@0:8
- (id)shortsTable;
// 0x15f514; @16@0:8
- (id)interfaceTable;
// 0x1666b4; @16@0:8
- (id)tabBarTable;
// 0x166854; @16@0:8
- (id)sbTable;
// 0x16a3d4; @16@0:8
- (id)rpcTable;
// 0x16bfd8; @16@0:8
- (id)contribsTable;
// 0x170eec; @16@0:8
- (id)libsTable;
// 0x1744a0; @16@0:8
- (id)thanksTable;
// 0x174690; @16@0:8
- (id)prefsTable;
// 0x175934; @16@0:8
- (id)devSection;
// 0x177370; @16@0:8
- (id)creditsSection;
// 0x177f70; @24@0:8@16
- (id)patreonSection:(id)arg1;
// 0x178a68; @32@0:8@16@24
- (id)patreonButtonCellWithType:(id)arg1 model:(id)arg2;
// 0x179c84; v16@0:8
- (void)importPreferences;
// 0x17a478; v16@0:8
- (void)resetSettings;
// 0x17aa28; v24@0:8@16
- (void)showDonationSheet:(id)arg1;
// 0x17e400; v24@0:8@16
- (void)openURL:(id)arg1;
// 0x17e534; @24@0:8@16
- (id)thanksImage:(id)arg1;
// 0x17e8d4; @16@0:8
- (id)sbSegments;
// 0x1809f4; v24@0:8@?16
- (void)clearCacheWithCompletion:(id)arg1;
// 0x180ec0; @16@0:8
- (id)getCacheSize;
// 0x1814dc; @16@0:8
- (id)presenter;
// 0x1814f4; v24@0:8@16
- (void)setPresenter:(id)arg1;
@end

@interface DVNTableModel : NSObject
// 0x18b72c; @16@0:8
- (id)init;
// 0x18bbb0; v24@0:8@16
- (void)addSection:(id)arg1;
// 0x18bc0c; v24@0:8@16
- (void)addSections:(id)arg1;
// 0x18bc68; @24@0:8@16
- (id)cellForString:(id)arg1;
// 0x18c24c; @24@0:8@?16
- (id)cellsMatching:(id)arg1;
// 0x18c764; @24@0:8@?16
- (id)cellsMatchingRecursive:(id)arg1;
// 0x18c80c; v40@0:8@?16@24@32
- (void)_collectMatching:(id)arg1 into:(id)arg2 visited:(id)arg3;
// 0x18cef8; @16@0:8
- (id)title;
// 0x18cf00; v24@0:8@16
- (void)setTitle:(id)arg1;
// 0x18cf34; @16@0:8
- (id)header;
// 0x18cf3c; v24@0:8@16
- (void)setHeader:(id)arg1;
// 0x18cf70; @16@0:8
- (id)footer;
// 0x18cf78; v24@0:8@16
- (void)setFooter:(id)arg1;
// 0x18cfac; @16@0:8
- (id)headerFont;
// 0x18cfb4; v24@0:8@16
- (void)setHeaderFont:(id)arg1;
// 0x18cfe8; @16@0:8
- (id)footerFont;
// 0x18cff0; v24@0:8@16
- (void)setFooterFont:(id)arg1;
// 0x18cffc; q16@0:8
- (long long)headerAlignment;
// 0x18d004; v24@0:8q16
- (void)setHeaderAlignment:(long long)arg1;
// 0x18d024; q16@0:8
- (long long)footerAlignment;
// 0x18d02c; v24@0:8q16
- (void)setFooterAlignment:(long long)arg1;
// 0x18d04c; B16@0:8
- (BOOL)showsThanksHeart;
// 0x18d054; v20@0:8B16
- (void)setShowsThanksHeart:(BOOL)arg1;
// 0x18d074; B16@0:8
- (BOOL)supportsSearching;
// 0x18d07c; v20@0:8B16
- (void)setSupportsSearching:(BOOL)arg1;
// 0x18d09c; @16@0:8
- (id)sections;
// 0x18d0a4; v24@0:8@16
- (void)setSections:(id)arg1;
// 0x18d0d8; @16@0:8
- (id)viewController;
// 0x18d0e0; v24@0:8@16
- (void)setViewController:(id)arg1;
// 0x18d114; @16@0:8
- (id)selfViewController;
// 0x18d12c; v24@0:8@16
- (void)setSelfViewController:(id)arg1;
// 0x18b85c; @16@0:8
+ (id)model;
// 0x18b878; @32@0:8@16@24
+ (id)modelWithTitle:(id)arg1 sections:(id)arg2;
// 0x18b950; @48@0:8@16@24@32@40
+ (id)modelWithTitle:(id)arg1 header:(id)arg2 footer:(id)arg3 sections:(id)arg4;
// 0x18ba80; @48@0:8@16@24@32@40
+ (id)modelWithTitle:(id)arg1 header:(id)arg2 footer:(id)arg3 viewController:(id)arg4;
@end

@interface DVNSection : NSObject
// 0x18d94c; @16@0:8
- (id)init;
// 0x18d9f0; v24@0:8@16
- (void)_appendCells:(id)arg1;
// 0x18ef44; v24@0:8@16
- (void)addCell:(id)arg1;
// 0x18f018; v24@0:8@16
- (void)addCells:(id)arg1;
// 0x18f04c; @16@0:8
- (id)header;
// 0x18f054; v24@0:8@16
- (void)setHeader:(id)arg1;
// 0x18f088; @16@0:8
- (id)footer;
// 0x18f090; v24@0:8@16
- (void)setFooter:(id)arg1;
// 0x18f0c4; @16@0:8
- (id)identifier;
// 0x18f0cc; v24@0:8@16
- (void)setIdentifier:(id)arg1;
// 0x18f0d8; @16@0:8
- (id)headerIcon;
// 0x18f0e0; v24@0:8@16
- (void)setHeaderIcon:(id)arg1;
// 0x18f0ec; @16@0:8
- (id)cells;
// 0x18f0f4; v24@0:8@16
- (void)setCells:(id)arg1;
// 0x18f128; @?16@0:8
- (id)cellsProvider;
// 0x18f130; v24@0:8@?16
- (void)setCellsProvider:(id)arg1;
// 0x18dde4; @24@0:8@16
+ (id)sectionWithIdentifier:(id)arg1;
// 0x18de38; @32@0:8@16@24
+ (id)sectionWithCells:(id)arg1 identifier:(id)arg2;
// 0x18e15c; @40@0:8@16@24@32
+ (id)sectionWithHeader:(id)arg1 cells:(id)arg2 identifier:(id)arg3;
// 0x18e4a8; @48@0:8@16@24@32@40
+ (id)sectionWithHeader:(id)arg1 footer:(id)arg2 cells:(id)arg3 identifier:(id)arg4;
// 0x18e824; @48@0:8@16@24@32@40
+ (id)sectionWithHeader:(id)arg1 headerIcon:(id)arg2 cells:(id)arg3 identifier:(id)arg4;
// 0x18eba0; @56@0:8@16@24@32@40@48
+ (id)sectionWithHeader:(id)arg1 headerIcon:(id)arg2 footer:(id)arg3 cells:(id)arg4 identifier:(id)arg5;
@end

@interface DVNCell : NSObject
// 0x18f954; @16@0:8
- (id)init;
// 0x190a18; @16@0:8
- (id)identifier;
// 0x190a20; v24@0:8@16
- (void)setIdentifier:(id)arg1;
// 0x190a54; @16@0:8
- (id)reuseIdentifier;
// 0x190a5c; @16@0:8
- (id)title;
// 0x190a64; v24@0:8@16
- (void)setTitle:(id)arg1;
// 0x190a70; @16@0:8
- (id)subtitle;
// 0x190a78; v24@0:8@16
- (void)setSubtitle:(id)arg1;
// 0x190aac; @16@0:8
- (id)detailText;
// 0x190ab4; v24@0:8@16
- (void)setDetailText:(id)arg1;
// 0x190ae8; @16@0:8
- (id)key;
// 0x190af0; v24@0:8@16
- (void)setKey:(id)arg1;
// 0x190b24; @16@0:8
- (id)placeholder;
// 0x190b2c; v24@0:8@16
- (void)setPlaceholder:(id)arg1;
// 0x190b38; @16@0:8
- (id)titleIndexes;
// 0x190b40; v24@0:8@16
- (void)setTitleIndexes:(id)arg1;
// 0x190b74; @16@0:8
- (id)imageIndexes;
// 0x190b7c; v24@0:8@16
- (void)setImageIndexes:(id)arg1;
// 0x190b88; d16@0:8
- (double)dividerValue;
// 0x190b90; v24@0:8d16
- (void)setDividerValue:(double)arg1;
// 0x190bb0; d16@0:8
- (double)minimumValue;
// 0x190bb8; v24@0:8d16
- (void)setMinimumValue:(double)arg1;
// 0x190bd8; d16@0:8
- (double)maximumValue;
// 0x190be0; v24@0:8d16
- (void)setMaximumValue:(double)arg1;
// 0x190c00; q16@0:8
- (long long)sliderFormat;
// 0x190c08; v24@0:8q16
- (void)setSliderFormat:(long long)arg1;
// 0x190c28; B16@0:8
- (BOOL)reloadsCell;
// 0x190c30; v20@0:8B16
- (void)setReloadsCell:(BOOL)arg1;
// 0x190c50; B16@0:8
- (BOOL)reloadsTable;
// 0x190c58; v20@0:8B16
- (void)setReloadsTable:(BOOL)arg1;
// 0x190c78; B16@0:8
- (BOOL)shouldHideDetail;
// 0x190c80; v20@0:8B16
- (void)setShouldHideDetail:(BOOL)arg1;
// 0x190ca0; q16@0:8
- (long long)renderingMode;
// 0x190ca8; v24@0:8q16
- (void)setRenderingMode:(long long)arg1;
// 0x190cc8; @16@0:8
- (id)icon;
// 0x190cd0; v24@0:8@16
- (void)setIcon:(id)arg1;
// 0x190d04; @16@0:8
- (id)image;
// 0x190d0c; v24@0:8@16
- (void)setImage:(id)arg1;
// 0x190d40; @16@0:8
- (id)accessoryIcon;
// 0x190d48; v24@0:8@16
- (void)setAccessoryIcon:(id)arg1;
// 0x190d7c; q16@0:8
- (long long)type;
// 0x190d84; v24@0:8q16
- (void)setType:(long long)arg1;
// 0x190da4; @16@0:8
- (id)tintColor;
// 0x190dac; v24@0:8@16
- (void)setTintColor:(id)arg1;
// 0x190db8; @16@0:8
- (id)sourceView;
// 0x190dd0; v24@0:8@16
- (void)setSourceView:(id)arg1;
// 0x190e04; @16@0:8
- (id)controllerModel;
// 0x190e0c; v24@0:8@16
- (void)setControllerModel:(id)arg1;
// 0x190e40; @16@0:8
- (id)customData;
// 0x190e48; v24@0:8@16
- (void)setCustomData:(id)arg1;
// 0x190e54; @?16@0:8
- (id)handler;
// 0x190e5c; v24@0:8@?16
- (void)setHandler:(id)arg1;
// 0x190e8c; @?16@0:8
- (id)selfHandler;
// 0x190e94; v24@0:8@?16
- (void)setSelfHandler:(id)arg1;
// 0x190ec4; @?16@0:8
- (id)handlerWithCompletion;
// 0x190ecc; v24@0:8@?16
- (void)setHandlerWithCompletion:(id)arg1;
// 0x190efc; @?16@0:8
- (id)subtitleProvider;
// 0x190f04; v24@0:8@?16
- (void)setSubtitleProvider:(id)arg1;
// 0x190f34; @?16@0:8
- (id)titleIndexesProvider;
// 0x190f3c; v24@0:8@?16
- (void)setTitleIndexesProvider:(id)arg1;
// 0x190f6c; @?16@0:8
- (id)validationHandler;
// 0x190f74; v24@0:8@?16
- (void)setValidationHandler:(id)arg1;
// 0x190fa4; @16@0:8
- (id)errorText;
// 0x190fac; v24@0:8@16
- (void)setErrorText:(id)arg1;
// 0x18fa30; @48@0:8@16@24@32@40
+ (id)controllerCellWithModel:(id)arg1 title:(id)arg2 subtitle:(id)arg3 icon:(id)arg4;
// 0x18fb20; @32@0:8@16@24
+ (id)cellWithTitleIndexes:(id)arg1 key:(id)arg2;
// 0x18fbb8; @32@0:8@16@24
+ (id)cellWithImageIndexes:(id)arg1 key:(id)arg2;
// 0x18fc50; @40@0:8@16@24@?32
+ (id)cellWithTitle:(id)arg1 subtitle:(id)arg2 handler:(id)arg3;
// 0x18fd10; @40@0:8@16@24@?32
+ (id)cellWithTitle:(id)arg1 subtitle:(id)arg2 selfHandler:(id)arg3;
// 0x18fdd0; @48@0:8@16@24q32@40
+ (id)cellWithTitle:(id)arg1 subtitle:(id)arg2 type:(long long)arg3 key:(id)arg4;
// 0x18fe9c; @56@0:8@16@24@32q40@48
+ (id)cellWithTitle:(id)arg1 subtitle:(id)arg2 icon:(id)arg3 type:(long long)arg4 key:(id)arg5;
// 0x18ff90; @48@0:8@16@24@32@40
+ (id)cellWithTitle:(id)arg1 subtitle:(id)arg2 imageIndexes:(id)arg3 key:(id)arg4;
// 0x190080; @48@0:8@16@24@32@40
+ (id)cellWithTitle:(id)arg1 subtitle:(id)arg2 titleIndexes:(id)arg3 key:(id)arg4;
// 0x190170; @56@0:8@16@24@32q40@48
+ (id)cellWithTitle:(id)arg1 subtitle:(id)arg2 titleIndexes:(id)arg3 type:(long long)arg4 key:(id)arg5;
// 0x190264; @64@0:8@16@24@32@40q48@56
+ (id)cellWithTitle:(id)arg1 subtitle:(id)arg2 icon:(id)arg3 accessoryIcon:(id)arg4 type:(long long)arg5 key:(id)arg6;
// 0x190388; @64@0:8@16@24@32@40q48@?56
+ (id)cellWithTitle:(id)arg1 subtitle:(id)arg2 icon:(id)arg3 accessoryIcon:(id)arg4 type:(long long)arg5 handler:(id)arg6;
// 0x1904ac; @64@0:8@16@24@32@40q48@?56
+ (id)cellWithTitle:(id)arg1 subtitle:(id)arg2 image:(id)arg3 accessoryIcon:(id)arg4 type:(long long)arg5 handler:(id)arg6;
// 0x1905e4; @48@0:8d16d24d32@40
+ (id)sliderCellWithMinimum:(double)arg1 maximum:(double)arg2 divider:(double)arg3 key:(id)arg4;
// 0x1905f8; @56@0:8d16d24d32q40@48
+ (id)sliderCellWithMinimum:(double)arg1 maximum:(double)arg2 divider:(double)arg3 format:(long long)arg4 key:(id)arg5;
// 0x1906d8; @48@0:8@16@24@32@40
+ (id)textFieldCellWithTitle:(id)arg1 subtitle:(id)arg2 placeholder:(id)arg3 key:(id)arg4;
// 0x1907c8; @64@0:8@16@24d32d40q48@56
+ (id)timePickerWithTitle:(id)arg1 subtitle:(id)arg2 minimum:(double)arg3 maximum:(double)arg4 format:(long long)arg5 key:(id)arg6;
// 0x1908e0; @72@0:8@16@24d32d40d48q56@64
+ (id)stepperCellWithTitle:(id)arg1 subtitle:(id)arg2 minimum:(double)arg3 maximum:(double)arg4 step:(double)arg5 format:(long long)arg6 key:(id)arg7;
@end

@interface DVNSupportersVC : UIViewController
// 0x191f84; v16@0:8
- (void)viewDidLoad;
// 0x192ac0; v32@0:8@16@24
- (void)webView:(id)arg1 didStartProvisionalNavigation:(id)arg2;
// 0x192b00; v32@0:8@16@24
- (void)webView:(id)arg1 didFinishNavigation:(id)arg2;
// 0x192b40; v40@0:8@16@24@32
- (void)webView:(id)arg1 didFailProvisionalNavigation:(id)arg2 withError:(id)arg3;
@end

@interface SBSegment : NSObject
// 0x19435c; @16@0:8
- (id)uuid;
// 0x194364; v24@0:8@16
- (void)setUuid:(id)arg1;
// 0x194398; @16@0:8
- (id)category;
// 0x1943a0; v24@0:8@16
- (void)setCategory:(id)arg1;
// 0x1943d4; @16@0:8
- (id)actionType;
// 0x1943dc; v24@0:8@16
- (void)setActionType:(id)arg1;
// 0x194410; @16@0:8
- (id)segmentDescription;
// 0x194418; v24@0:8@16
- (void)setSegmentDescription:(id)arg1;
// 0x19444c; d16@0:8
- (double)start;
// 0x194454; v24@0:8d16
- (void)setStart:(double)arg1;
// 0x194474; d16@0:8
- (double)end;
// 0x19447c; v24@0:8d16
- (void)setEnd:(double)arg1;
// 0x19449c; d16@0:8
- (double)videoDuration;
// 0x1944a4; v24@0:8d16
- (void)setVideoDuration:(double)arg1;
// 0x1944c4; B16@0:8
- (BOOL)locked;
// 0x1944cc; v20@0:8B16
- (void)setLocked:(BOOL)arg1;
// 0x1944d4; q16@0:8
- (long long)votes;
// 0x1944dc; v24@0:8q16
- (void)setVotes:(long long)arg1;
// 0x193a60; @24@0:8@16
+ (id)segmentWithDictionary:(id)arg1;
@end

@interface SBPlaybackController : NSObject
// 0x194914; @24@0:8@16
- (id)initWithPlayer:(id)arg1;
// 0x194a04; v16@0:8
- (void)requestSbSegments;
// 0x194c24; B16@0:8
- (BOOL)shouldCheckSponsorBlock;
// 0x1956f8; v16@0:8
- (void)skipSegmentIfNeeded;
// 0x1964b8; B24@0:8@16
- (BOOL)segmentMeetsMinimumDuration:(id)arg1;
// 0x196834; v24@0:8@16
- (void)handleSkipSegment:(id)arg1;
// 0x196b54; v24@0:8@16
- (void)handleHighlightSegment:(id)arg1;
// 0x196e7c; v44@0:8d16@24d32i40
- (void)seekToTime:(double)arg1 forSegment:(id)arg2 undoTime:(double)arg3 attempts:(int)arg4;
// 0x197448; v32@0:8@16d24
- (void)showSkippedToast:(id)arg1 undoTime:(double)arg2;
// 0x197be0; v40@0:8@16d24d32
- (void)showSkipPromptToast:(id)arg1 timeBeforeSkip:(double)arg2 target:(double)arg3;
// 0x198608; v16@0:8
- (void)playSkipAudioIfNeeded;
// 0x1987ac; v16@0:8
- (void)dealloc;
@end

@interface SBManager : NSObject
// 0x199940; @16@0:8
- (id)init;
// 0x19a168; v24@0:8@16
- (void)getSegmentsForID:(id)arg1;
// 0x19b1cc; @16@0:8
- (id)segments;
// 0x19b1d4; v24@0:8@16
- (void)setSegments:(id)arg1;
// 0x199848; @16@0:8
+ (id)sharedManager;
@end

@interface SBPlayerDecorator : NSObject
// 0x19b714; v32@0:8@16@24
+ (void)addDurationWithoutSegments:(id)arg1 videoController:(id)arg2;
// 0x19c600; B24@0:8@16
+ (BOOL)shouldDrawRoundedForBarView:(id)arg1;
// 0x19ce04; @24@0:8@16
+ (id)_decorationDataForBarView:(id)arg1;
// 0x19d6c0; v24@0:8@16
+ (void)drawSegmentsDecorationView:(id)arg1;
// 0x19d77c; v24@0:8@16
+ (void)drawSegmentsOnActiveDecorationView:(id)arg1;
// 0x19db58; v24@0:8@16
+ (void)_drawSegmentsForData:(id)arg1;
// 0x19ee38; v40@0:8@16@24@32
+ (void)drawSegments:(id)arg1 layer:(id)arg2 playerVC:(id)arg3;
// 0x19fedc; v40@0:8@16@24@32
+ (void)drawSegmentableSegments:(id)arg1 playerBar:(id)arg2 playerVC:(id)arg3;
@end

@interface SBPlayerDecorationData : NSObject
// 0x1a30c4; @16@0:8
- (id)segments;
// 0x1a30cc; v24@0:8@16
- (void)setSegments:(id)arg1;
// 0x1a3100; d16@0:8
- (double)playerBarWidth;
// 0x1a3108; v24@0:8d16
- (void)setPlayerBarWidth:(double)arg1;
// 0x1a3128; d16@0:8
- (double)mediaDuration;
// 0x1a3130; v24@0:8d16
- (void)setMediaDuration:(double)arg1;
// 0x1a3150; @16@0:8
- (id)barView;
// 0x1a3168; v24@0:8@16
- (void)setBarView:(id)arg1;
@end

@interface DVNMediaPicker : NSObject
// 0x1a327c; v24@0:8@16
- (void)presentImagePickerForVC:(id)arg1;
// 0x1a3390; v32@0:8@16@24
- (void)picker:(id)arg1 didFinishPicking:(id)arg2;
// 0x1a39b8; v28@0:8@16B24
- (void)presentFilePickerForVC:(id)arg1 isMultipleSelection:(BOOL)arg2;
// 0x1a691c; v32@0:8@16@24
- (void)documentPicker:(id)arg1 didPickDocumentsAtURLs:(id)arg2;
// 0x1a6a20; @24@0:8@16
- (id)tempCopyOfURL:(id)arg1;
// 0x1a6c7c; v24@0:8@16
- (void)prepareMediaForUse:(id)arg1;
// 0x1a79a0; v24@0:8@16
- (void)prepareURLsForImport:(id)arg1;
// 0x1a31a0; @16@0:8
+ (id)sharedPicker;
@end

@interface YTPMedia : NSObject
// 0x1b6a04; v20@0:8B16
- (void)setCairo:(BOOL)arg1;
// 0x1b6d3c; B16@0:8
- (BOOL)isCairo;
// 0x1aa774; @16@0:8
+ (id)sharedMedia;
// 0x1aa86c; q16@0:8
+ (long long)pageStyle;
// 0x1aa9f0; @16@0:8
+ (id)adaptiveBackgroundColor;
// 0x1aacd4; @24@0:8@16
+ (id)oledForColor:(id)arg1;
// 0x1ab020; @24@0:8@16
+ (id)imageWithName:(id)arg1;
// 0x1ab254; @16@0:8
+ (id)historyTab;
// 0x1ab508; @16@0:8
+ (id)historyTabSelected;
// 0x1ab8b8; @16@0:8
+ (id)watchLaterTab;
// 0x1abadc; @16@0:8
+ (id)watchLaterTabSelected;
// 0x1abdf8; @16@0:8
+ (id)postsTab;
// 0x1ac0f4; @16@0:8
+ (id)postsTabSelected;
// 0x1ac4f0; @16@0:8
+ (id)hypeTab;
// 0x1ac8a8; @16@0:8
+ (id)hypeTabSelected;
// 0x1acd54; @16@0:8
+ (id)musicTab;
// 0x1ad1c0; @16@0:8
+ (id)musicTabSelected;
// 0x1ad724; @16@0:8
+ (id)liveTab;
// 0x1adb88; @16@0:8
+ (id)liveTabSelected;
// 0x1ae0d0; @16@0:8
+ (id)gamingTab;
// 0x1ae530; @16@0:8
+ (id)gamingTabSelected;
// 0x1aeaa4; @16@0:8
+ (id)sportsTab;
// 0x1aef00; @16@0:8
+ (id)sportsTabSelected;
// 0x1af460; @16@0:8
+ (id)notificationsTab;
// 0x1af858; @16@0:8
+ (id)notificationsTabSelected;
// 0x1afd64; @16@0:8
+ (id)ytPlus;
// 0x1affe0; @16@0:8
+ (id)ytPlusShorts;
// 0x1b025c; @16@0:8
+ (id)sponsorblock;
// 0x1b0558; @16@0:8
+ (id)lock;
// 0x1b0770; @16@0:8
+ (id)volumeOff;
// 0x1b09f0; @16@0:8
+ (id)volumeOn;
// 0x1b0c4c; @16@0:8
+ (id)moon;
// 0x1b0e28; @16@0:8
+ (id)downloading;
// 0x1b110c; @16@0:8
+ (id)credits;
// 0x1b137c; @16@0:8
+ (id)donor;
// 0x1b15c0; @16@0:8
+ (id)feed;
// 0x1b17e8; @16@0:8
+ (id)FEshorts;
// 0x1b1a78; @16@0:8
+ (id)interface;
// 0x1b1d30; @16@0:8
+ (id)libs;
// 0x1b1f50; @16@0:8
+ (id)localization;
// 0x1b2264; @16@0:8
+ (id)navbar;
// 0x1b24bc; @16@0:8
+ (id)open_new;
// 0x1b2758; @16@0:8
+ (id)player;
// 0x1b29ac; @16@0:8
+ (id)support;
// 0x1b2c1c; @16@0:8
+ (id)tabbar;
// 0x1b2e80; @16@0:8
+ (id)ytl_settings;
// 0x1b3188; @16@0:8
+ (id)captions;
// 0x1b3424; @16@0:8
+ (id)FElibrary;
// 0x1b36cc; @16@0:8
+ (id)FEsubscriptions;
// 0x1b3a3c; @16@0:8
+ (id)FEuploads;
// 0x1b3cf8; @16@0:8
+ (id)FEwhat_to_watch;
// 0x1b404c; @16@0:8
+ (id)link;
// 0x1b4280; @16@0:8
+ (id)x_prefs;
// 0x1b43cc; @16@0:8
+ (id)box_checkmark;
// 0x1b46f8; @16@0:8
+ (id)box_empty;
// 0x1b49a8; @16@0:8
+ (id)copy;
// 0x1b4bcc; @16@0:8
+ (id)image_library;
// 0x1b4eec; @16@0:8
+ (id)image;
// 0x1b5130; @16@0:8
+ (id)message;
// 0x1b53a4; @16@0:8
+ (id)music;
// 0x1b55d8; @16@0:8
+ (id)play_circle;
// 0x1b58ac; @16@0:8
+ (id)show_image;
// 0x1b5b7c; @16@0:8
+ (id)star_half;
// 0x1b5e28; @16@0:8
+ (id)youtube_logo;
// 0x1b6130; @16@0:8
+ (id)check;
// 0x1b636c; @16@0:8
+ (id)empty;
// 0x1b64a4; @16@0:8
+ (id)adaptiveDiscord;
@end

@interface DVNHorizontalPanDelegate : NSObject
// 0x1b9608; B24@0:8@16
- (BOOL)gestureRecognizerShouldBegin:(id)arg1;
@end

@interface ToastView : UIVisualEffectView
// 0x1ba6d8; @16@0:8
- (id)init;
// 0x1bbd94; v24@0:8@?16
- (void)enqueueCommand:(id)arg1;
// 0x1bbe2c; v16@0:8
- (void)processQueue;
// 0x1bbf68; v44@0:8@16f24B28B32B36B40
- (void)setupInterfaceWithText:(id)arg1 progress:(float)arg2 withStop:(BOOL)arg3 isStatus:(BOOL)arg4 isSuccess:(BOOL)arg5 withWait:(BOOL)arg6;
// 0x1bc8e4; v24@0:8@16
- (void)handlePanGesture:(id)arg1;
// 0x1bd9b4; v16@0:8
- (void)handleTap;
// 0x1be8a0; v16@0:8
- (void)updateLayout;
// 0x1be9d8; v48@0:8d16^d24^d32^d40
- (void)calculateToastParametersWithKeyboardHeight:(double)arg1 bottomOffset:(double *)arg2 topOffset:(double *)arg3 scale:(double *)arg4;
// 0x1bee14; v56@0:8d16d24d32d40d48
- (void)configureToastAppearanceWithBottomOffset:(double)arg1 topOffset:(double)arg2 scale:(double)arg3 width:(double)arg4 animationDuration:(double)arg5;
// 0x1bf098; v72@0:8d16d24d32d40d48d56@?64
- (void)configureToastAppearanceWithBottomOffset:(double)arg1 topOffset:(double)arg2 scale:(double)arg3 width:(double)arg4 alpha:(double)arg5 animationDuration:(double)arg6 completion:(id)arg7;
// 0x1bf368; v16@0:8
- (void)setupObservers;
// 0x1bf6d4; v16@0:8
- (void)removeObservers;
// 0x1bfa0c; v24@0:8@16
- (void)goodHeightDidChange:(id)arg1;
// 0x1bfba0; v24@0:8@16
- (void)keyboardWillShow:(id)arg1;
// 0x1bfc9c; v24@0:8@16
- (void)keyboardWillHide:(id)arg1;
// 0x1bfcdc; v16@0:8
- (void)cleanup;
// 0x1bfdd0; v16@0:8
- (void)cancelButtonTapped;
// 0x1bff34; v24@0:8@16
- (void)handleLongPress:(id)arg1;
// 0x1bffdc; v40@0:8@16f24B28@?32
- (void)showProgressWithText:(id)arg1 progress:(float)arg2 withStop:(BOOL)arg3 stopCompletion:(id)arg4;
// 0x1c033c; v28@0:8@16f24
- (void)updateText:(id)arg1 progress:(float)arg2;
// 0x1c03b4; v32@0:8@16f24B28
- (void)updateText:(id)arg1 progress:(float)arg2 animated:(BOOL)arg3;
// 0x1c0430; v28@0:8@16B24
- (void)showMessageWithText:(id)arg1 isSuccess:(BOOL)arg2;
// 0x1c0468; v36@0:8@16B24d28
- (void)showMessageWithText:(id)arg1 isSuccess:(BOOL)arg2 duration:(double)arg3;
// 0x1c0740; v24@0:8@16
- (void)showText:(id)arg1;
// 0x1c09b0; v24@0:8@16
- (void)showToast:(id)arg1;
// 0x1c0ccc; v36@0:8@16d24B32
- (void)showProgressiveToastWithText:(id)arg1 duration:(double)arg2 isSuccess:(BOOL)arg3;
// 0x1c0f78; v48@0:8@16d24@32@?40
- (void)showProgressiveToastWithText:(id)arg1 duration:(double)arg2 actionTitle:(id)arg3 actionCompletion:(id)arg4;
// 0x1c1644; v48@0:8@16d24@32@?40
- (void)showProgressiveToastWithText:(id)arg1 duration:(double)arg2 actionIcon:(id)arg3 actionCompletion:(id)arg4;
// 0x1c1680; v52@0:8@16d24@32B40@?44
- (void)showProgressiveToastWithText:(id)arg1 duration:(double)arg2 actionIcon:(id)arg3 ignoresPan:(BOOL)arg4 actionCompletion:(id)arg5;
// 0x1c1af8; v24@0:8@16
- (void)showDonationReminder:(id)arg1;
// 0x1c1d18; v24@0:8d16
- (void)startTimerCountdown:(double)arg1;
// 0x1c1fb4; v24@0:8@?16
- (void)hideAnimatedWithCompletion:(id)arg1;
// 0x1c2760; v16@0:8
- (void)hideImmediately;
// 0x1c27b0; v24@0:8d16
- (void)hideWithDelay:(double)arg1;
// 0x1c2840; v16@0:8
- (void)hide;
// 0x1c2878; B16@0:8
- (BOOL)isHidden;
// 0x1c2944; v24@0:8@?16
- (void)hideWithCompletion:(id)arg1;
// 0x1c2b1c; B16@0:8
- (BOOL)isLandscape;
// 0x1c2be4; B16@0:8
- (BOOL)isFullscreen;
// 0x1c2c38; B16@0:8
- (BOOL)isPinnedTop;
// 0x1c2c8c; d16@0:8
- (double)bottomOffset;
// 0x1c2d78; v16@0:8
- (void)dealloc;
// 0x1c2ddc; @?16@0:8
- (id)completion;
// 0x1c2dec; v24@0:8@?16
- (void)setCompletion:(id)arg1;
// 0x1b9d50; v16@0:8
+ (void)initialize;
// 0x1b9e04; @16@0:8
+ (id)toastWindow;
@end

@interface ToastWindow : UIWindow
// 0x1c7e28; @40@0:8{CGPoint=dd}16@32
- (id)hitTest:(CGPoint)arg1 withEvent:(id)arg2;
// 0x1c8b10; @24@0:8@16
- (id)initWithWindowScene:(id)arg1;
// 0x1c8c00; B16@0:8
- (BOOL)canBecomeKeyWindow;
// 0x1c8c08; v16@0:8
- (void)makeKeyAndVisible;
// 0x1c8cc4; B16@0:8
- (BOOL)shouldAffectStatusBarAppearance;
// 0x1c8ccc; B16@0:8
- (BOOL)_windowControlsStatusBarOrientation;
// 0x1c8cd4; B16@0:8
- (BOOL)_canBecomeKeyWindow;
// 0x1c8cdc; @16@0:8
- (id)appKeyWindow;
// 0x1c8fb4; v16@0:8
+ (void)initialize;
@end

@interface ToastManager : NSObject
// 0x1c9bd0; @16@0:8
- (id)init;
// 0x1c9d98; v24@0:8@16
- (void)registerToast:(id)arg1;
// 0x1c9ee0; v24@0:8@16
- (void)unregisterToast:(id)arg1;
// 0x1c9fd8; v16@0:8
- (void)updateAllToasts;
// 0x1ca260; @16@0:8
- (id)toasts;
// 0x1ca268; v24@0:8@16
- (void)setToasts:(id)arg1;
// 0x1ca29c; @16@0:8
- (id)offsetController;
// 0x1ca2a4; v24@0:8@16
- (void)setOffsetController:(id)arg1;
// 0x1ca2d8; B16@0:8
- (BOOL)isPinnedTop;
// 0x1ca2e0; v20@0:8B16
- (void)setIsPinnedTop:(BOOL)arg1;
// 0x1ca300; B16@0:8
- (BOOL)isFullscreen;
// 0x1ca308; v20@0:8B16
- (void)setIsFullscreen:(BOOL)arg1;
// 0x1c9b1c; @16@0:8
+ (id)sharedManager;
// 0x1c9c8c; v28@0:8@16B24
+ (void)showMessageWithText:(id)arg1 isSuccess:(BOOL)arg2;
@end

@interface YTPAPIHelper : NSObject
// 0x1ca6dc; v32@0:8@16@?24
+ (void)fetchChannelImageWithChannelID:(id)arg1 completion:(id)arg2;
@end

@interface Downloader : NSObject
// 0x1cce24; @16@0:8
- (id)init;
// 0x1ccf54; v40@0:8@16@24Q32
- (void)downloadFileWithURL:(id)arg1 fileName:(id)arg2 fileSize:(unsigned long long)arg3;
// 0x1cd570; v16@0:8
- (void)downloadNextChunk;
// 0x1cd81c; v16@0:8
- (void)cancelDownload;
// 0x1cd9f8; @16@0:8
- (id)getFilePath;
// 0x1cdf18; v56@0:8@16@24q32q40q48
- (void)URLSession:(id)arg1 downloadTask:(id)arg2 didWriteData:(long long)arg3 totalBytesWritten:(long long)arg4 totalBytesExpectedToWrite:(long long)arg5;
// 0x1ce018; v40@0:8@16@24@32
- (void)URLSession:(id)arg1 downloadTask:(id)arg2 didFinishDownloadingToURL:(id)arg3;
// 0x1ce31c; v40@0:8@16@24@32
- (void)URLSession:(id)arg1 task:(id)arg2 didCompleteWithError:(id)arg3;
// 0x1ce4c4; @16@0:8
- (id)delegate;
// 0x1ce4dc; v24@0:8@16
- (void)setDelegate:(id)arg1;
@end

@interface AudioManager : NSObject
// 0x1cee84; @16@0:8
- (id)init;
// 0x1cf770; v16@0:8
- (void)playAudio;
// 0x1cf858; v16@0:8
- (void)stopAudio;
// 0x1cf970; v28@0:8@16B24
- (void)audioPlayerDidFinishPlaying:(id)arg1 successfully:(BOOL)arg2;
// 0x1cf98c; @16@0:8
- (id)audioPlayer;
// 0x1cf994; v24@0:8@16
- (void)setAudioPlayer:(id)arg1;
// 0x1ced8c; @16@0:8
+ (id)sharedInstance;
@end

@interface YTPDownloader : NSObject
// 0x1cfddc; @16@0:8
- (id)init;
// 0x1cff34; v16@0:8
- (void)cancelDownload;
// 0x1cffa8; v16@0:8
- (void)cleanup;
// 0x1d01c0; v48@0:8@16@24@32Q40
- (void)downloadFileWithURL:(id)arg1 fileName:(id)arg2 videoID:(id)arg3 fileSize:(unsigned long long)arg4;
// 0x1d0b6c; @32@0:8@16Q24
- (id)hashForFile:(id)arg1 fileSize:(unsigned long long)arg2;
// 0x1d0d50; @16@0:8
- (id)createTempDirectoryIfNeeded;
// 0x1d124c; @16@0:8
- (id)getFilePath;
// 0x1d1324; @16@0:8
- (id)getChunkMapPath;
// 0x1d1528; v16@0:8
- (void)saveChunkMap;
// 0x1d1b4c; B16@0:8
- (BOOL)loadChunkMap;
// 0x1d2a48; v24@0:8@16
- (void)continueDownloadingForURL:(id)arg1;
// 0x1d3924; v40@0:8@16@24@32
- (void)URLSession:(id)arg1 dataTask:(id)arg2 didReceiveData:(id)arg3;
// 0x1d42d4; v40@0:8@16@24@32
- (void)URLSession:(id)arg1 task:(id)arg2 didCompleteWithError:(id)arg3;
// 0x1d4e28; @16@0:8
- (id)delegate;
// 0x1d4e40; v24@0:8@16
- (void)setDelegate:(id)arg1;
@end

@interface SbWhitelistVC : DVNTableViewController
// 0x1d662c; @16@0:8
- (id)init;
// 0x1d6770; v16@0:8
- (void)setupWhitelist;
// 0x1d7eb0; v16@0:8
- (void)loadView;
// 0x1d838c; v16@0:8
- (void)closeButtonTapped;
// 0x1d83c8; @32@0:8@16q24
- (id)tableView:(id)arg1 titleForHeaderInSection:(long long)arg2;
// 0x1d85d0; v40@0:8@16@24q32
- (void)tableView:(id)arg1 willDisplayHeaderView:(id)arg2 forSection:(long long)arg3;
// 0x1d8efc; @16@0:8
- (id)getSortActions;
// 0x1da52c; v16@0:8
- (void)updateSortMenu;
// 0x1da7cc; q24@0:8@16
- (long long)numberOfSectionsInTableView:(id)arg1;
// 0x1da7e4; q32@0:8@16q24
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
// 0x1da840; @32@0:8@16@24
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
// 0x1db004; B32@0:8@16@24
- (BOOL)tableView:(id)arg1 shouldHighlightRowAtIndexPath:(id)arg2;
// 0x1db00c; v32@0:8@16@24
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
// 0x1db400; @32@0:8@16@24
- (id)tableView:(id)arg1 trailingSwipeActionsConfigurationForRowAtIndexPath:(id)arg2;
// 0x1db9c8; v24@0:8@16
- (void)removeChannelWithLink:(id)arg1;
// 0x1dc018; @24@0:8@16
- (id)ytlImageWithName:(id)arg1;
// 0x1dc0d8; @24@0:8@16
- (id)channelImage:(id)arg1;
@end

@interface YTPTranslator : NSObject
// 0x1de550; v48@0:8@16@24@32@?40
+ (void)translateText:(id)arg1 fromLanguage:(id)arg2 toLanguage:(id)arg3 completion:(id)arg4;
// 0x1defc8; v48@0:8@16@24@32@?40
+ (void)translateSingleText:(id)arg1 fromLanguage:(id)arg2 toLanguage:(id)arg3 completion:(id)arg4;
@end

@interface TranslatorVC : UITableViewController
// 0x1e06b4; @24@0:8@16
- (id)initWithText:(id)arg1;
// 0x1e13ac; v16@0:8
- (void)viewDidLoad;
// 0x1e1964; v16@0:8
- (void)closeButtonTapped;
// 0x1e19a0; v40@0:8@16@24q32
- (void)tableView:(id)arg1 willDisplayHeaderView:(id)arg2 forSection:(long long)arg3;
// 0x1e1bd4; d32@0:8@16@24
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
// 0x1e1c44; q24@0:8@16
- (long long)numberOfSectionsInTableView:(id)arg1;
// 0x1e1c5c; q32@0:8@16q24
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
// 0x1e1cb8; @32@0:8@16@24
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
// 0x1e3458; @32@0:8@16@24
- (id)menuButtonWithTitle:(id)arg1 array:(id)arg2;
// 0x1e3d38; @32@0:8@16d24
- (id)systemImage:(id)arg1 withSize:(double)arg2;
// 0x1e3fa0; B16@0:8
- (BOOL)isRTL;
// 0x1e400c; v16@0:8
- (void)translateText;
// 0x1e46fc; B32@0:8@16@24
- (BOOL)tableView:(id)arg1 shouldHighlightRowAtIndexPath:(id)arg2;
// 0x1e4704; v32@0:8@16@24
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
@end

@interface YTLUserDefaults : NSUserDefaults
// 0x1e6a08; v16@0:8
- (void)reset;
// 0x1e6b88; v16@0:8
- (void)registerDefaults;
// 0x1eb10c; @24@0:8@16
- (id)colorForSegment:(id)arg1;
// 0x1ebdbc; @16@0:8
- (id)sbPrivateUserID;
// 0x1ec5dc; @24@0:8@16
- (id)sbPublicUserID:(id)arg1;
// 0x1ed5cc; v24@0:8@?16
- (void)presentDocumentPicker:(id)arg1;
// 0x1ed9d0; v32@0:8@16@24
- (void)documentPicker:(id)arg1 didPickDocumentAtURL:(id)arg2;
// 0x1ee4c4; @?16@0:8
- (id)prefsPickerCompletion;
// 0x1ee4d4; v24@0:8@?16
- (void)setPrefsPickerCompletion:(id)arg1;
// 0x1e677c; @16@0:8
+ (id)standardUserDefaults;
// 0x1ec890; v24@0:8@?16
+ (void)importYtlSettings:(id)arg1;
// 0x1edac4; v24@0:8@16
+ (void)exportYtlSettings:(id)arg1;
// 0x1ee158; v16@0:8
+ (void)resetUserDefaults;
// 0x1ee1b4; B24@0:8@16
+ (BOOL)boolForKey:(id)arg1;
// 0x1ee22c; q24@0:8@16
+ (long long)integerForKey:(id)arg1;
// 0x1ee2a4; d24@0:8@16
+ (double)floatForKey:(id)arg1;
// 0x1ee328; v28@0:8B16@20
+ (void)setBool:(BOOL)arg1 forKey:(id)arg2;
// 0x1ee3b8; v32@0:8q16@24
+ (void)setInteger:(long long)arg1 forKey:(id)arg2;
// 0x1ee42c; v32@0:8d16@24
+ (void)setFloat:(double)arg1 forKey:(id)arg2;
@end

@interface DVNSheetPresenter : NSObject
// 0x1efae4; v32@0:8@16@24
+ (void)presentCustomHeightViewController:(id)arg1 fromViewController:(id)arg2;
// 0x1effd4; v32@0:8@16@24
+ (void)presentHalfScreenViewController:(id)arg1 fromViewController:(id)arg2;
// 0x1f0364; v40@0:8@16@24d32
+ (void)presentViewController:(id)arg1 fromViewController:(id)arg2 withHeight:(double)arg3;
@end

@interface PseudoDetentController : UIPresentationController
// 0x1f0df0; @32@0:8@16@24
- (id)initWithPresentedViewController:(id)arg1 presentingViewController:(id)arg2;
// 0x1f0fec; v16@0:8
- (void)dismissController;
// 0x1f1050; {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
- (CGRect)frameOfPresentedViewInContainerView;
// 0x1f118c; v16@0:8
- (void)containerViewWillLayoutSubviews;
// 0x1f1254; v16@0:8
- (void)presentationTransitionWillBegin;
// 0x1f15b8; v16@0:8
- (void)dismissalTransitionWillBegin;
// 0x1f1740; @?16@0:8
- (id)heightCalculator;
// 0x1f1750; v24@0:8@?16
- (void)setHeightCalculator:(id)arg1;
// 0x1f1784; d16@0:8
- (double)customHeight;
// 0x1f1794; v24@0:8d16
- (void)setCustomHeight:(double)arg1;
// 0x1f17a4; @16@0:8
- (id)dimmingView;
// 0x1f17b4; v24@0:8@16
- (void)setDimmingView:(id)arg1;
@end

@interface PseudoDetentTransitioningDelegate : NSObject
// 0x1f1f7c; @40@0:8@16@24@32
- (id)presentationControllerForPresentedViewController:(id)arg1 presentingViewController:(id)arg2 sourceViewController:(id)arg3;
// 0x1f204c; @?16@0:8
- (id)heightCalculator;
// 0x1f2054; v24@0:8@?16
- (void)setHeightCalculator:(id)arg1;
// 0x1f2084; d16@0:8
- (double)customHeight;
// 0x1f208c; v24@0:8d16
- (void)setCustomHeight:(double)arg1;
@end

@interface DVNLongPressDelegate : NSObject
// 0x1f21c0; B32@0:8{CGPoint=dd}16
- (BOOL)isTouchInSpeedZone:(CGPoint)arg1;
// 0x1f2444; B32@0:8@16@24
- (BOOL)gestureRecognizer:(id)arg1 shouldReceiveTouch:(id)arg2;
// 0x1f24dc; @16@0:8
- (id)view;
// 0x1f24f4; v24@0:8@16
- (void)setView:(id)arg1;
// 0x1f2528; q16@0:8
- (long long)mode;
// 0x1f2530; v24@0:8q16
- (void)setMode:(long long)arg1;
@end

@interface YTPPlayerHelper : NSObject
// 0x1f2660; @24@0:8@16
+ (id)getVideoID:(id)arg1;
// 0x1f2a1c; v24@0:8@16
+ (void)openVideoWithID:(id)arg1;
// 0x1f2dfc; v32@0:8@16@24
+ (void)openVideoWithID:(id)arg1 handler:(id)arg2;
// 0x1f3740; v32@0:8@16@24
+ (void)openVideoWithID:(id)arg1 viewController:(id)arg2;
@end

@interface FFMpegHelper : NSObject
// 0x1f4248; @16@0:8
- (id)init;
// 0x1f4510; v24@0:8@16
- (void)statisticsCallback:(id)arg1;
// 0x1f4600; v56@0:8@16@24@32q40@?48
- (void)mergeVideo:(id)arg1 withAudio:(id)arg2 captions:(id)arg3 duration:(long long)arg4 completion:(id)arg5;
// 0x1f5d58; @64@0:8@16@24@32@40q48@56
- (id)getCommandWithVideoURL:(id)arg1 audioURL:(id)arg2 captionsURL:(id)arg3 thumbnailURL:(id)arg4 duration:(long long)arg5 outputURL:(id)arg6;
// 0x1f7cd8; v40@0:8@16q24@?32
- (void)cutAudio:(id)arg1 duration:(long long)arg2 completion:(id)arg3;
// 0x1f912c; v36@0:8q16i24@28
- (void)logCallback:(long long)arg1 :(int)arg2 :(id)arg3;
// 0x1f9148; v24@0:8@16
- (void)getCleanLog:(id)arg1;
// 0x1f9854; v16@0:8
- (void)setActive;
// 0x1f98b4; v16@0:8
- (void)updateProgressDialog;
// 0x1f9c44; @24@0:8@16
- (id)codeForCaps:(id)arg1;
// 0x1f4150; @16@0:8
+ (id)sharedInstance;
@end

@interface SRTParser : NSObject
// 0x1fdf2c; @16@0:8
- (id)init;
// 0x1fe01c; v48@0:8@16@24@32@?40
- (void)parseXMLFromURL:(id)arg1 forLanguage:(id)arg2 videoID:(id)arg3 completion:(id)arg4;
// 0x1fe570; @40@0:8@16@24^@32
- (id)srtForLanguage:(id)arg1 videoID:(id)arg2 error:(id *)arg3;
// 0x1fefb8; v32@0:8@16@?24
- (void)parseTranscriptFromURL:(id)arg1 completion:(id)arg2;
// 0x1ff5b4; v56@0:8@16@24@32@40@48
- (void)parser:(id)arg1 didStartElement:(id)arg2 namespaceURI:(id)arg3 qualifiedName:(id)arg4 attributes:(id)arg5;
// 0x1ff874; v32@0:8@16@24
- (void)parser:(id)arg1 foundCharacters:(id)arg2;
// 0x1ff8b0; v48@0:8@16@24@32@40
- (void)parser:(id)arg1 didEndElement:(id)arg2 namespaceURI:(id)arg3 qualifiedName:(id)arg4;
// 0x1ffa9c; v24@0:8@16
- (void)generateSRTWithText:(id)arg1;
// 0x1ffd74; v24@0:8@16
- (void)generateTranscriptWithText:(id)arg1;
// 0x1fff08; @24@0:8d16
- (id)formatTime:(double)arg1;
// 0x200164; @24@0:8@16
- (id)decodeHTMLСhars:(id)arg1;
@end

@interface YTPDB : NSObject
// 0x201410; @16@0:8
+ (id)thanks;
// 0x20398c; @16@0:8
+ (id)clip;
// 0x205768; @16@0:8
+ (id)report;
// 0x2083f4; @16@0:8
+ (id)hype;
// 0x20b47c; @16@0:8
+ (id)stopAds;
// 0x2104c4; @16@0:8
+ (id)supportedLanguages;
// 0x21079c; @24@0:8q16
+ (id)langCodeForIndex:(long long)arg1;
// 0x210c88; Q16@0:8
+ (unsigned long long)indexOfPreferredLanguage;
@end

@interface YTPSleepTimer : NSObject
// 0x2114fc; @16@0:8
- (id)timerQueue;
// 0x2117cc; B16@0:8
- (BOOL)isRunning;
// 0x211844; v24@0:8@16
- (void)showOptions:(id)arg1;
// 0x212c38; v16@0:8
- (void)showTimeSelector;
// 0x21320c; v24@0:8d16
- (void)startForSeconds:(double)arg1;
// 0x213300; v16@0:8
- (void)startForEndOfVideo;
// 0x2133d4; v16@0:8
- (void)startTimer;
// 0x213ac8; v24@0:8d16
- (void)stopWithFadeIfNeeded:(double)arg1;
// 0x213c18; v32@0:8d16d24
- (void)stopWithFadeDuration:(double)arg1 stopAfter:(double)arg2;
// 0x213fd0; v16@0:8
- (void)stop;
// 0x213fe0; v16@0:8
- (void)cancel;
// 0x214014; v16@0:8
- (void)cancelIfPlayerClosed;
// 0x21409c; d16@0:8
- (double)remainingSeconds;
// 0x214200; d16@0:8
- (double)remainingSecondsForCurrentVideo;
// 0x2143f8; d24@0:8@16
- (double)secondsForDate:(id)arg1;
// 0x21462c; @24@0:8d16
- (id)formattedTime:(double)arg1;
// 0x214758; @16@0:8
- (id)getPlayerIfAvailable;
// 0x214a90; @16@0:8
- (id)globalSlimBar;
// 0x214d78; @16@0:8
- (id)playerSlimBar;
// 0x2150ac; v16@0:8
- (void)globalSlimBarVisibilityChange;
// 0x2151c8; v16@0:8
- (void)playerSlimBarVisibilityChange;
// 0x215554; @24@0:8Q16
- (id)slimBarForStyle:(unsigned long long)arg1;
// 0x21558c; @24@0:8Q16
- (id)barsForStyle:(unsigned long long)arg1;
// 0x215718; @32@0:8@16@24
- (id)attributedTitle:(id)arg1 image:(id)arg2;
// 0x2159b8; v48@0:8@16@24@32@40
- (void)applyTitle:(id)arg1 image:(id)arg2 color:(id)arg3 toBar:(id)arg4;
// 0x215b20; v24@0:8@16
- (void)attachTapHandlerToBar:(id)arg1;
// 0x215fe8; v24@0:8@16
- (void)removeTapHandlerOnBar:(id)arg1;
// 0x2163fc; v24@0:8@16
- (void)onSlimBarTap:(id)arg1;
// 0x216d8c; v24@0:8Q16
- (void)slimBarVisibilityChange:(unsigned long long)arg1;
// 0x216e14; v48@0:8@16@24@32Q40
- (void)showSlimBarWithTitle:(id)arg1 image:(id)arg2 color:(id)arg3 style:(unsigned long long)arg4;
// 0x217198; v32@0:8@16Q24
- (void)updateSlimBarTitle:(id)arg1 style:(unsigned long long)arg2;
// 0x217570; v24@0:8Q16
- (void)hideSlimBarWithStyle:(unsigned long long)arg1;
// 0x217cfc; B16@0:8
- (BOOL)pausePlayback;
// 0x218070; v16@0:8
- (void)finishTimerAndCleanup;
// 0x2181a8; v16@0:8
- (void)cleanup;
// 0x211404; @16@0:8
+ (id)sharedTimer;
@end

@interface RPCMedia : NSObject
// 0x21af10; @16@0:8
- (id)videoID;
// 0x21af18; v24@0:8@16
- (void)setVideoID:(id)arg1;
// 0x21af20; @16@0:8
- (id)title;
// 0x21af28; v24@0:8@16
- (void)setTitle:(id)arg1;
// 0x21af58; @16@0:8
- (id)author;
// 0x21af60; v24@0:8@16
- (void)setAuthor:(id)arg1;
// 0x21af90; B16@0:8
- (BOOL)isPaused;
// 0x21af98; v20@0:8B16
- (void)setIsPaused:(BOOL)arg1;
// 0x21afb8; d16@0:8
- (double)totalTime;
// 0x21afc0; v24@0:8d16
- (void)setTotalTime:(double)arg1;
// 0x21afe0; d16@0:8
- (double)currentTime;
// 0x21afe8; v24@0:8d16
- (void)setCurrentTime:(double)arg1;
// 0x21b008; @16@0:8
- (id)thumbnailURL;
// 0x21b010; v24@0:8@16
- (void)setThumbnailURL:(id)arg1;
// 0x21aaf0; @24@0:8@16
+ (id)mediaWithPlayer:(id)arg1;
@end

@interface YTPDiscordRPC : NSObject
// 0x21b934; v24@0:8@16
- (void)setServerURL:(id)arg1;
// 0x21bf88; v16@0:8
- (void)startIfPossible;
// 0x21cb00; v16@0:8
- (void)startRPC;
// 0x21ce10; v16@0:8
- (void)updateTime;
// 0x21cf58; v16@0:8
- (void)updateState;
// 0x21d0a0; v16@0:8
- (void)clearPlayback;
// 0x21d340; @16@0:8
- (id)buildBody;
// 0x21dc68; v16@0:8
- (void)sendBody;
// 0x21dde0; v24@0:8@16
- (void)_send:(id)arg1;
// 0x21e488; v28@0:8@16B24
- (void)showAlertWithMessage:(id)arg1 showSettingsButton:(BOOL)arg2;
// 0x21eac8; @16@0:8
- (id)media;
// 0x21ead0; v24@0:8@16
- (void)setMedia:(id)arg1;
// 0x21eb04; @16@0:8
- (id)serverURL;
// 0x21b498; @16@0:8
+ (id)sharedPresence;
// 0x21b590; v24@0:8@?16
+ (void)checkLocalNetworkPermission:(id)arg1;
@end

@interface DVNImageViewController : UIViewController
// 0x21fa6c; v16@0:8
- (void)viewDidLoad;
// 0x21fae4; v16@0:8
- (void)setupNavbar;
// 0x220864; v16@0:8
- (void)setupViewer;
// 0x221048; @24@0:8@16
- (id)viewForZoomingInScrollView:(id)arg1;
// 0x221058; v16@0:8
- (void)viewDidLayoutSubviews;
// 0x221160; v24@0:8@16
- (void)handleDoubleTap:(id)arg1;
// 0x2212e4; v24@0:8@16
- (void)scrollViewDidZoom:(id)arg1;
// 0x2212f0; v40@0:8@16@24d32
- (void)scrollViewDidEndZooming:(id)arg1 withView:(id)arg2 atScale:(double)arg3;
// 0x221324; v32@0:8@16@24
- (void)scrollViewWillBeginZooming:(id)arg1 withView:(id)arg2;
// 0x221358; v16@0:8
- (void)adjustScrollViewInsets;
// 0x221458; v24@0:8d16
- (void)adjustHorizontalInsetsWithImageWidth:(double)arg1;
// 0x22156c; v24@0:8d16
- (void)adjustVerticalInsetsWithImageHeight:(double)arg1;
// 0x221680; v16@0:8
- (void)hapticFeedback;
// 0x2216d8; v16@0:8
- (void)closeButtonTapped;
// 0x221730; v16@0:8
- (void)share;
// 0x221a60; @16@0:8
- (id)fullImage;
// 0x221a70; v24@0:8@16
- (void)setFullImage:(id)arg1;
@end

@interface BlurButton : UIButton
// 0x223460; v20@0:8B16
- (void)setHighlighted:(BOOL)arg1;
// 0x22311c; @48@0:8@16@24:32@40
+ (id)createButtonWithImage:(id)arg1 target:(id)arg2 action:(SEL)arg3 menu:(id)arg4;
@end

@interface YTPSpeedMaster : NSObject
// 0x223960; v32@0:8@16@24
- (void)manageSpeedMaster:(id)arg1 playerOverlayVC:(id)arg2;
// 0x2250cc; @16@0:8
- (id)speedArray;
// 0x22545c; q24@0:8d16
- (long long)nearestIndexForRate:(double)arg1;
// 0x225900; d16@0:8
- (double)currentPlaybackRate;
// 0x225a20; v24@0:8d16
- (void)setPlaybackRate:(double)arg1;
// 0x223868; @16@0:8
+ (id)sharedMaster;
// 0x2255cc; @16@0:8
+ (id)getPlayerIfAvailable;
// 0x225f20; d16@0:8
+ (double)currentPlaybackRate;
// 0x22608c; d24@0:8@16
+ (double)playbackRateForPlayer:(id)arg1;
// 0x226204; v32@0:8d16@24
+ (void)setPlaybackRate:(double)arg1 forPlayer:(id)arg2;
// 0x2265dc; v24@0:8@16
+ (void)_applyPendingRateForPlayer:(id)arg1;
@end

@interface Dvbug : NSObject
// 0x227b88; @32@0:8@16@24
+ (id)instanceForObject:(id)arg1 name:(id)arg2;
// 0x228038; v32@0:8@16@24
+ (void)observeIvar:(id)arg1 name:(id)arg2;
// 0x228948; @32@0:8@16@24
+ (id)getObservedIvar:(id)arg1 name:(id)arg2;
// 0x228e60; v40@0:8@16@24@32
+ (void)setObservedIvar:(id)arg1 name:(id)arg2 value:(id)arg3;
// 0x229350; q32@0:8@16@24
+ (long long)getObservedIntIvar:(id)arg1 name:(id)arg2;
// 0x22990c; q32@0:8@16@24
+ (long long)getObservedIvarLongLong:(id)arg1 name:(id)arg2;
// 0x229e2c; B32@0:8@16@24
+ (BOOL)getObservedBoolIvar:(id)arg1 name:(id)arg2;
// 0x22a380; v36@0:8@16@24B32
+ (void)setObservedBoolIvar:(id)arg1 name:(id)arg2 value:(BOOL)arg3;
@end

@interface YTLHelper : NSObject
// 0x22b24c; @16@0:8
- (id)init;
// 0x22b424; v88@0:8@16@24@32@40@48Q56Q64Q72@80
- (void)downloadVideoWithUrl:(id)arg1 audioUrl:(id)arg2 fileName:(id)arg3 format:(id)arg4 videoID:(id)arg5 videoSize:(unsigned long long)arg6 audioSize:(unsigned long long)arg7 duration:(unsigned long long)arg8 captions:(id)arg9;
// 0x22b9a4; v56@0:8@16@24@32Q40Q48
- (void)downloadAudioWithUrl:(id)arg1 fileName:(id)arg2 videoID:(id)arg3 audioSize:(unsigned long long)arg4 duration:(unsigned long long)arg5;
// 0x22bf60; v20@0:8f16
- (void)downloadProgress:(float)arg1;
// 0x22c3a4; v32@0:8@16@24
- (void)downloadDidFinish:(id)arg1 fileName:(id)arg2;
// 0x22dcbc; v24@0:8@16
- (void)downloadDidFailureWithError:(id)arg1;
// 0x22df30; v24@0:8@16
- (void)saveMedia:(id)arg1;
// 0x22e4ac; v24@0:8@16
- (void)shareMedia:(id)arg1;
// 0x22e998; v16@0:8
- (void)cleanup;
// 0x22eb5c; v24@0:8@16
- (void)askForAction:(id)arg1;
// 0x22f724; @32@0:8@16d24
- (id)resizeImage:(id)arg1 toSize:(double)arg2;
// 0x22f9bc; @24@0:8@16
- (id)imageNamed:(id)arg1;
// 0x22fc70; @24@0:8@16
+ (id)YTImageNamed:(id)arg1;
// 0x22fe70; @24@0:8@16
+ (id)YTLImageNamed:(id)arg1;
// 0x230064; B16@0:8
+ (BOOL)isConnectedToWiFi;
// 0x2300f8; @56@0:8@16@24@32@40:48
+ (id)createYTQTMButton:(id)arg1 accessibilityLabel:(id)arg2 buttonLabel:(id)arg3 icon:(id)arg4 selector:(SEL)arg5;
// 0x2301d0; @72@0:8@16@24@32@40{CGSize=dd}48:64
+ (id)createYTQTMButton:(id)arg1 accessibilityLabel:(id)arg2 buttonLabel:(id)arg3 icon:(id)arg4 size:(CGSize)arg5 selector:(SEL)arg6;
// 0x230598; @56@0:8@16@24@32@40:48
+ (id)createOverlayButton:(id)arg1 accessibilityLabel:(id)arg2 buttonLabel:(id)arg3 icon:(id)arg4 selector:(SEL)arg5;
// 0x230a44; v28@0:8@16B24
+ (void)downloadImageFromURL:(id)arg1 download:(BOOL)arg2;
// 0x231990; v40@0:8@16@24@?32
+ (void)genImageFromLayer:(id)arg1 backgroundColor:(id)arg2 completionHandler:(id)arg3;
// 0x231b28; @32@0:8@16d24
+ (id)resizeImage:(id)arg1 toSize:(double)arg2;
@end

@interface YTPSpeedPopupController : UIViewController
// 0x235bc4; v24@0:8@16
- (void)presentFromViewController:(id)arg1;
// 0x235c0c; v20@0:8B16
- (void)viewDidAppear:(BOOL)arg1;
// 0x235d64; v16@0:8
- (void)viewDidLoad;
// 0x236564; d16@0:8
- (double)calculateWidth;
// 0x236634; d16@0:8
- (double)bottomConstant;
// 0x236660; B16@0:8
- (BOOL)isiPad;
// 0x236994; B16@0:8
- (BOOL)hasNotch;
// 0x236a38; v16@0:8
- (void)dismiss;
// 0x236c70; v24@0:8@16
- (void)handlePan:(id)arg1;
// 0x23719c; B32@0:8@16@24
- (BOOL)gestureRecognizer:(id)arg1 shouldReceiveTouch:(id)arg2;
// 0x23720c; @16@0:8
- (id)speedView;
// 0x23721c; v24@0:8@16
- (void)setSpeedView:(id)arg1;
// 0x237258; @16@0:8
- (id)bottomConstraint;
// 0x237268; v24@0:8@16
- (void)setBottomConstraint:(id)arg1;
// 0x235b74; @16@0:8
+ (id)speedController;
@end

@interface YTPSpeedControlView : UIView
// 0x238398; @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
- (id)initWithFrame:(CGRect)arg1;
// 0x2385a0; v16@0:8
- (void)setupUI;
// 0x239460; @24@0:8@16
- (id)makeStepButton:(id)arg1;
// 0x23973c; @24@0:8@16
- (id)makePresetButton:(id)arg1;
// 0x239ae0; v24@0:8@16
- (void)sliderChanged:(id)arg1;
// 0x239b8c; v24@0:8@16
- (void)sliderTapped:(id)arg1;
// 0x239c94; v16@0:8
- (void)minusTapped;
// 0x239d48; v16@0:8
- (void)plusTapped;
// 0x239de0; v24@0:8@16
- (void)presetTapped:(id)arg1;
// 0x239e70; v20@0:8f16
- (void)updateLabel:(float)arg1;
// 0x238360; @16@0:8
+ (id)speedControls;
@end

@interface PlayerToast : UIView
// 0x23b560; @16@0:8
- (id)init;
// 0x23bd28; v44@0:8@16d24q32B40
- (void)showPlayerToastWithText:(id)arg1 value:(double)arg2 style:(long long)arg3 isCompact:(BOOL)arg4;
// 0x23c1e0; v16@0:8
- (void)prepareForPresentation;
// 0x23c264; v32@0:8@16d24
- (void)updateToastText:(id)arg1 value:(double)arg2;
// 0x23c52c; v24@0:8d16
- (void)setProgress:(double)arg1;
// 0x23c67c; v16@0:8
- (void)hideToast;
// 0x23c7cc; v16@0:8
- (void)setupConstraints;
// 0x23d138; v16@0:8
- (void)clearConstraints;
// 0x23d180; @24@0:8d16
- (id)imgForVal:(double)arg1;
// 0x23dc90; @32@0:8d16q24
- (id)subLabelForVal:(double)arg1 style:(long long)arg2;
// 0x23decc; v24@0:8q16
- (void)setupSubForStyle:(long long)arg1;
// 0x23df50; v32@0:8d16q24
- (void)setValue:(double)arg1 forEventWithStyle:(long long)arg2;
// 0x23e19c; @16@0:8
- (id)sourceView;
// 0x23e220; B16@0:8
- (BOOL)isLandscape;
// 0x23b468; @16@0:8
+ (id)sharedToast;
@end

@interface CustomHUD : NSObject
// 0x23fcf8; @16@0:8
- (id)init;
// 0x23fdac; v16@0:8
- (void)addToController;
// 0x23fe18; v16@0:8
- (void)removeFromController;
// 0x23fe84; v20@0:8f16
- (void)setVolumeLevel:(float)arg1;
// 0x23febc; f16@0:8
- (float)volumeLevel;
// 0x23fecc; @16@0:8
- (id)windowSceneForVolumeDisplay;
// 0x23ff50; @16@0:8
- (id)volumeAudioCategory;
// 0x23ff60; @16@0:8
- (id)controller;
@end

@interface ArchDetect : NSObject
// 0xab3914; v16@0:8
+ (void)initialize;
// 0xab3950; @16@0:8
+ (id)getCpuArch;
// 0xab3c14; @16@0:8
+ (id)getArch;
// 0xab3c68; i16@0:8
+ (int)isLTSBuild;
@end

@interface AtomicLong : NSObject
// 0xab3c70; @24@0:8q16
- (id)initWithInitialValue:(long long)arg1;
// 0xab3cbc; q16@0:8
- (long long)incrementAndGet;
@end

@interface FFmpegExecution : NSObject
// 0xaddc80; @32@0:8q16@24
- (id)initWithExecutionId:(long long)arg1 andArguments:(id)arg2;
// 0xaddd64; @16@0:8
- (id)getStartTime;
// 0xaddd74; q16@0:8
- (long long)getExecutionId;
// 0xaddd84; @16@0:8
- (id)getCommand;
@end

@interface MobileFFmpeg : NSObject
// 0xadddd4; v16@0:8
+ (void)initialize;
// 0xaddf5c; i32@0:8q16@24
+ (int)executeWithId:(long long)arg1 andArguments:(id)arg2;
// 0xade1f8; i24@0:8@16
+ (int)executeWithArguments:(id)arg1;
// 0xade210; i32@0:8@16@24
+ (int)executeWithArgumentsAsync:(id)arg1 withCallback:(id)arg2;
// 0xade2a8; i40@0:8@16@24@32
+ (int)executeWithArgumentsAsync:(id)arg1 withCallback:(id)arg2 andDispatchQueue:(id)arg3;
// 0xade464; i24@0:8@16
+ (int)execute:(id)arg1;
// 0xade4bc; i32@0:8@16@24
+ (int)executeAsync:(id)arg1 withCallback:(id)arg2;
// 0xade554; i40@0:8@16@24@32
+ (int)executeAsync:(id)arg1 withCallback:(id)arg2 andDispatchQueue:(id)arg3;
// 0xade618; i32@0:8@16@24
+ (int)execute:(id)arg1 delimiter:(id)arg2;
// 0xade6ac; v16@0:8
+ (void)cancel;
// 0xade6b4; v24@0:8q16
+ (void)cancel:(long long)arg1;
// 0xade6bc; @24@0:8@16
+ (id)parseArguments:(id)arg1;
// 0xade944; @24@0:8@16
+ (id)argumentsToString:(id)arg1;
// 0xadea64; @16@0:8
+ (id)listExecutions;
@end

@interface CallbackData : NSObject
// 0xadead0; @36@0:8q16i24@28
- (id)initWithId:(long long)arg1 logLevel:(int)arg2 data:(id)arg3;
// 0xadeb90; @64@0:8q16i24f28f32q36i44d48d56
- (id)initWithId:(long long)arg1 videoFrameNumber:(int)arg2 fps:(float)arg3 quality:(float)arg4 size:(long long)arg5 time:(int)arg6 bitrate:(double)arg7 speed:(double)arg8;
// 0xadec74; i16@0:8
- (int)getType;
// 0xadec84; q16@0:8
- (long long)getExecutionId;
// 0xadec94; i16@0:8
- (int)getLogLevel;
// 0xadeca4; @16@0:8
- (id)getLogData;
// 0xadecb4; i16@0:8
- (int)getStatisticsFrameNumber;
// 0xadecc4; f16@0:8
- (float)getStatisticsFps;
// 0xadecd4; f16@0:8
- (float)getStatisticsQuality;
// 0xadece4; q16@0:8
- (long long)getStatisticsSize;
// 0xadecf4; i16@0:8
- (int)getStatisticsTime;
// 0xaded04; d16@0:8
- (double)getStatisticsBitrate;
// 0xaded14; d16@0:8
- (double)getStatisticsSpeed;
@end

@interface MobileFFmpegConfig : NSObject
// 0xadf8f0; v16@0:8
+ (void)initialize;
// 0xadfd38; v16@0:8
+ (void)enableRedirection;
// 0xadfde8; v16@0:8
+ (void)disableRedirection;
// 0xadfe68; i16@0:8
+ (int)getLogLevel;
// 0xadfe74; v20@0:8i16
+ (void)setLogLevel:(int)arg1;
// 0xadfe80; @20@0:8i16
+ (id)logLevelToString:(int)arg1;
// 0xadff74; v24@0:8@16
+ (void)setLogDelegate:(id)arg1;
// 0xadff84; v24@0:8@16
+ (void)setStatisticsDelegate:(id)arg1;
// 0xadff94; @16@0:8
+ (id)getLastReceivedStatistics;
// 0xadffa0; v16@0:8
+ (void)resetStatistics;
// 0xadffe0; v24@0:8@16
+ (void)setFontconfigConfigurationPath:(id)arg1;
// 0xae0048; v32@0:8@16@24
+ (void)setFontDirectory:(id)arg1 with:(id)arg2;
// 0xae0664; @16@0:8
+ (id)getBuildConf;
// 0xae0680; @16@0:8
+ (id)getPackageName;
// 0xae0fac; @16@0:8
+ (id)getExternalLibraries;
// 0xae1184; @16@0:8
+ (id)registerNewFFmpegPipe;
// 0xae12bc; v24@0:8@16
+ (void)closeFFmpegPipe:(id)arg1;
// 0xae133c; @16@0:8
+ (id)getFFmpegVersion;
// 0xae1358; @16@0:8
+ (id)getVersion;
// 0xae13d4; @16@0:8
+ (id)getBuildDate;
// 0xae1450; i16@0:8
+ (int)getLastReturnCode;
// 0xae145c; @16@0:8
+ (id)getLastCommandOutput;
// 0xae1468; v20@0:8i16
+ (void)ignoreSignal:(int)arg1;
@end

@interface Statistics : NSObject
// 0xae14d4; @16@0:8
- (id)init;
// 0xae1568; @64@0:8q16i24f28f32q36i44d48d56
- (id)initWithId:(long long)arg1 videoFrameNumber:(int)arg2 fps:(float)arg3 quality:(float)arg4 size:(long long)arg5 time:(int)arg6 bitrate:(double)arg7 speed:(double)arg8;
// 0xae163c; v24@0:8@16
- (void)update:(id)arg1;
// 0xae17fc; q16@0:8
- (long long)getExecutionId;
// 0xae180c; i16@0:8
- (int)getVideoFrameNumber;
// 0xae181c; f16@0:8
- (float)getVideoFps;
// 0xae182c; f16@0:8
- (float)getVideoQuality;
// 0xae183c; q16@0:8
- (long long)getSize;
// 0xae184c; i16@0:8
- (int)getTime;
// 0xae185c; d16@0:8
- (double)getBitrate;
// 0xae186c; d16@0:8
- (double)getSpeed;
@end
