#pragma once
#import <Foundation/Foundation.h>
void FirstAudioLog(NSString *format, ...);
#define NSLog FirstAudioLog
