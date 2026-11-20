# Objective-C categories

The package's `__objc_catlist` contains three categories with six methods. These are separate from its 51 first-party classes and seven library classes. The earlier class-only inventory did not inspect category method names, which allowed two reconstructed bundle methods to compile under selectors their callers did not use.

`NSBundle(YTLite)` supplies `+ytl_defaultBundle` at `0x234910`, `-imageWithName:` at `0x2355c0`, `-originalImageWithName:` at `0x235628`, and `-imageWithName:tintColor:` at `0x235644`. The two latter selectors replace the reconstruction's mistaken `imageWithNameWithoutRendering:` and `imageWithName:color:` spellings. No production caller required those aliases. The tint method retains the recovered sequence: template image, tint, original rendering mode, then `ytp_%@_image` accessibility identifier.

`NSString(YTL)` supplies `-ytl_localized` at `0x211308`. It looks up the receiver as a localization key with nil fallback and table arguments. An empty result returns the original receiver. Its category name has also been restored to YTL.

`UIViewController(DVNPatreonContext)` supplies `-presentationAnchorForWebAuthenticationSession:` at `0x23e9c`. It returns `self.view.window` and ignores the session. The reconstructed category starts no authentication and does not change the local account-policy decision.

Run `python3 recovery/tools/verify_bundles.py`, then `python3 recovery/tools/verify_objc_categories.py`. The first executes actual bundle/localization code in five resource-layout cases and checks the original image-loading selectors with UIKit doubles. The second independently reads all original category method lists, compiles all three reconstructed categories for iOS and compares exact method sets and encodings. It also executes the actual window-anchor method with nil and changing views/windows. The inventory at `recovery/evidence/category-source-inventory.json` pins the original method intervals and selected source hashes. Host fixtures do not establish real device image rendering or web-authentication behavior.
