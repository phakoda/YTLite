#import <Foundation/Foundation.h>
void SettingsBridgeLog(NSString *format, ...);
#define NSLog SettingsBridgeLog
