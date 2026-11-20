# First-package audit index

218 of 864 first-party named methods have current focused first-package evidence catalogued here.
This is an evidence index, not a parity score. All 51 first-party classes already have reconstructed implementations.

Run `python3 recovery/tools/first_package_audit_inventory.py` to check input hashes and regenerate this index.

| Class | Named methods | With focused evidence | Different raw length from arm |
| --- | ---: | ---: | ---: |
| [AudioManager](../recovery/source/Downloads/AudioManager.m) | 8 | 8 | 5 |
| [BlurButton](../recovery/source/Presentation/BlurButton.m) | 3 | 0 | 2 |
| [CustomHUD](../recovery/source/Presentation/CustomHUD.m) | 9 | 0 | 0 |
| [DVNCell](../recovery/source/Models/DVNCell.m) | 83 | 83 | 7 |
| [DVNHorizontalPanDelegate](../recovery/source/Controls/DVNHorizontalPanDelegate.m) | 1 | 0 | 1 |
| [DVNImageViewController](../recovery/source/Presentation/DVNImageViewController.m) | 18 | 0 | 6 |
| [DVNLongPressDelegate](../recovery/source/Controls/DVNLongPressDelegate.m) | 7 | 0 | 1 |
| [DVNMediaPicker](../recovery/source/Media/DVNMediaPicker.m) | 9 | 0 | 3 |
| [DVNPickerView](../recovery/source/Settings/DVNPickerView.m) | 1 | 0 | 0 |
| [DVNSection](../recovery/source/Models/DVNSection.m) | 23 | 0 | 3 |
| [DVNSheetPresenter](../recovery/source/Presentation/DVNSheetPresenter.m) | 3 | 0 | 2 |
| [DVNSupportersVC](../recovery/source/Settings/DVNSupportersVC.m) | 5 | 0 | 1 |
| [DVNTableModel](../recovery/source/Models/DVNTableModel.m) | 36 | 0 | 7 |
| [DVNTableViewController](../recovery/source/Settings/DVNTableViewController.m) | 73 | 0 | 24 |
| [DownloadMenuHelper](../recovery/source/Downloads/DownloadMenuHelper.m) | 26 | 26 | 21 |
| [Downloader](../recovery/source/Downloads/Downloader.m) | 11 | 0 | 5 |
| [Dvbug](../recovery/source/Support/Dvbug.m) | 8 | 0 | 8 |
| [FFMpegHelper](../recovery/source/Downloads/FFMpegHelper.m) | 12 | 12 | 4 |
| [InitWorkaround](../recovery/source/Runtime/InitWorkaround.m) | 4 | 0 | 0 |
| [PlayerToast](../recovery/source/Presentation/PlayerToast.m) | 16 | 0 | 3 |
| [PseudoDetentController](../recovery/source/Presentation/PseudoDetentController.m) | 13 | 0 | 1 |
| [PseudoDetentTransitioningDelegate](../recovery/source/Presentation/PseudoDetentTransitioningDelegate.m) | 6 | 0 | 0 |
| [RPCMedia](../recovery/source/Models/RPCMedia.m) | 16 | 0 | 2 |
| [SBManager](../recovery/source/Playback/SBManager.m) | 6 | 0 | 2 |
| [SBPlaybackController](../recovery/source/Playback/SBPlaybackController.m) | 13 | 0 | 11 |
| [SBPlayerDecorationData](../recovery/source/Models/SBPlayerDecorationData.m) | 9 | 0 | 3 |
| [SBPlayerDecorator](../recovery/source/Playback/SBPlayerDecorator.m) | 8 | 0 | 8 |
| [SBSegment](../recovery/source/Models/SBSegment.m) | 20 | 0 | 3 |
| [SRTParser](../recovery/source/Subtitles/SRTParser.m) | 12 | 0 | 6 |
| [SbWhitelistVC](../recovery/source/Whitelist/SbWhitelistVC.m) | 18 | 0 | 11 |
| [TabbarVC](../recovery/source/Settings/TabbarVC.m) | 24 | 0 | 14 |
| [ToastManager](../recovery/source/Presentation/ToastManager.m) | 15 | 0 | 2 |
| [ToastView](../recovery/source/Presentation/ToastView.m) | 47 | 0 | 18 |
| [ToastWindow](../recovery/source/Presentation/ToastWindow.m) | 9 | 0 | 3 |
| [TranslatorVC](../recovery/source/Subtitles/TranslatorVC.m) | 15 | 0 | 7 |
| [WelcomeVC](../recovery/source/Welcome/WelcomeVC.m) | 13 | 0 | 6 |
| [YTLHelper](../recovery/source/Helpers/YTLHelper.m) | 22 | 22 | 13 |
| [YTLUserDefaults](../Utils/YTLUserDefaults.m) | 20 | 0 | 10 |
| [YTPAPIHelper](../recovery/source/Downloads/YTPAPIHelper.m) | 1 | 0 | 1 |
| [YTPDB](../recovery/source/Support/YTPDB.m) | 8 | 0 | 4 |
| [YTPDiscordRPC](../recovery/source/Discord/YTPDiscordRPC.m) | 16 | 0 | 7 |
| [YTPDownloader](../recovery/source/Downloads/YTPDownloader.m) | 16 | 0 | 12 |
| [YTPMedia](../recovery/source/Downloads/YTPMedia.m) | 67 | 67 | 53 |
| [YTPPlayerHelper](../recovery/source/Helpers/YTPPlayerHelper.m) | 4 | 0 | 3 |
| [YTPSettingsBuilder](../recovery/source/Settings/YTPSettingsBuilder.m) | 29 | 0 | 24 |
| [YTPSleepTimer](../recovery/source/SleepTimer/YTPSleepTimer.m) | 37 | 0 | 16 |
| [YTPSpeedControlView](../recovery/source/Controls/YTPSpeedControlView.m) | 12 | 0 | 4 |
| [YTPSpeedMaster](../recovery/source/Controls/YTPSpeedMaster.m) | 12 | 0 | 6 |
| [YTPSpeedPopupController](../recovery/source/Controls/YTPSpeedPopupController.m) | 16 | 0 | 1 |
| [YTPTableViewCell](../recovery/source/Settings/YTPTableViewCell.m) | 2 | 0 | 2 |
| [YTPTranslator](../recovery/source/Subtitles/YTPTranslator.m) | 2 | 0 | 2 |

## Interpretation

- Focused evidence indexes pinned named-method bytes and current scoped tests. It does not prove all behavior of any method or class.
- Uncatalogued methods may have reconstructed source and other-package runtime tests; absence from this index is not evidence that source is missing or wrong.
- Category/resource audits, anonymous callbacks, registrations, initializers and live-device behavior are not counted as named methods here.
- Raw byte or length differences are investigation cues, not semantic differences or a parity percentage.
- Known source differences and excluded behavior remain in FIRST_PACKAGE_PARITY.md and per-method provenance.
