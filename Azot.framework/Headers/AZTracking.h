//
//  ASTracking.h
//  Appstrack
//
//  Created by Thomas Carayol on 16/01/15.
//  Copyright (c) 2015 Appstud. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ASTracking : NSObject

#define AS_LOG(__FORMAT__, ...) ASNSLog((@"%s line %d $ " __FORMAT__), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

//START SESSION
+ (void)startTracking:(NSString*)userToken;

//TRACK PAGE
+ (void)trackPage: (NSString*)pageId;
+ (void)stopTrackPage: (NSString*)pageId;

//TRACK EVENT
+ (void)trackEvent: (NSString*)eventId;

//TRACK MESSAGE
+ (void)sendMessage: (NSString*)message;

//TRACK LOG
OBJC_EXTERN void ASNSLog(NSString *format, ...) NS_FORMAT_FUNCTION(1,2);

@end