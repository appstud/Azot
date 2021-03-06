//
//  AZTracking.h
//  Appstrack
//
//  Created by Thomas Carayol on 16/01/15.
//  Copyright (c) 2015 Appstud. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AZTracking : NSObject

#define AZLOG(__FORMAT__, ...) AZLog((@"%s line %d $ " __FORMAT__), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

/**
 *  Start analysis in the app. Call it in your app delegate.
 *  @param azotAppToken is the token generated by Azot for the developer to track his app
 *  @return void
 */
+ (void)startTracking:(NSString*)azotAppToken;

/**
 *  Start analysis of a page. Call it in your controller viewDidAppear. Tips: Use this function to analyse a "page", understood as what the user can see.
 *  @param pageId is the name you'll give to your page. It is the name we will use to refer to your page in your analysis dashboard.
 *  @return void
 */
+ (void)trackPage: (NSString*)pageId;

/**
 *  Stop a page analysis. Call it in your controller viewDidDisapear.
 *  @param pageId must be the name you gave to the page you've opened in viewDidAppear with function trackPage.
 *  @return void
 */
+ (void)stopTrackPage: (NSString*)pageId;

/**
 *  Track events you care about in your app.
 *  @param eventId is the name of the event you want to track, can be static or dynamic.
 *  @return void
 */
+ (void)trackEvent: (NSString*)eventId;

/**
 *  Used to get feedbacks from the user.
 *  @param message is your user feedback message.
 *  @return void
 */
+ (void)sendMessage: (NSString*)message;

/**
 *  Allow you to get your logs if a session ends on a crash, just use AZLog instead of NSLog.
 *  @param format string used to define the log format, same usage as NSLog.
 *  @return void
 */
OBJC_EXTERN void AZLog(NSString *format, ...) NS_FORMAT_FUNCTION(1,2);

@end