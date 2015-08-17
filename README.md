# Azot
Azot is a mobile analysis SDK that runs directly inside phones or tablets. This repository holds the source code for the iOS version of Azot, for Objective-C.

##Supported OS & SDK Versions

* Supported build target - iOS 8.3
* Earliest supported deployment target - iOS 8.3
* Earliest compatible deployment target - iOS 7.1
* 
**NOTE**: 'Supported' means that the library has been tested with this version. 'Compatible' means that the library should work on this OS version (i.e. it doesn't rely on any unavailable SDK features) but is no longer being tested for compatibility and may require tweaking or bug fixes to run correctly.


##Thread Safety

Azot uses threading internally to avoid blocking the UI, but none of the Azot external interfaces are thread safe and you should not call any methods on Azot except from the main thread.

##Installation

To install Azot into your app, drag the Azot.framework into your project.

**Or**

Use CocoaPods using the line :

    pod 'Azot'


To start Azot basic analysis add the following code in your appDelegate :

    #import <Azot/AZTracking.h>
        
    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
         [AZTracking startTracking:@"AZOT_APP_TOKEN"];
         return YES;
    }
    
##Dependencies

To run azot you also need to install:

    Realm
    AFNetworking

##Confidentiality

The confidentiality level of screenshots and vidéos have three levels:

Confidentiality level   |   Hidded elements 
------------------------------------------- 
AZConfidentialityLow    |   Nothing 
AZConfidentialityMedium |   Text fields
AZConfidentialityHigh   |   Text fiels + Images + keybords + labels

##Methods

Azot has the following methods:

start:

    + (void)start:(NSString*)azotAppToken;

Start analysis in the app. Call it in your app delegate.

start:withVideo:andConfidentiality: 

    + (void)start:(NSString *)azotAppToken withVideo:(bool)video andConfidentiality:(AZConfidentiality)confidentialityLevel

Start analysis in the app. Call it in your app delegate.

startPage: 

    + (void)startPage:(NSString *)pageId

Start analysis of a page. Call it in your controller viewDidAppear. Tips: Use this function to analyse a “page”, understood as what the user can see.

stopPage: 

    + (void)stopPage:(NSString *)pageId

Stop a page analysis. Call it in your controller viewDidDisapear.

event: 

    + (void)event:(NSString *)eventId

Track events you care about in your app.
    
message:

    + (void)message: (NSString*)message;

This function is used to collect user feedbacks. The feedbacks will be saved in the session report.

AZLog:

    OBJC_EXTERN void AZLog(NSString *format, ...) NS_FORMAT_FUNCTION(1,2);

This function collects your logs if a session ends on a crash, just use AZLog instead of NSLog.

confidentiality:

    + (void)confidentiality:(AZConfidentiality)confidentiality
    
Allow you to set the confidentiality level of both video and screenshots.
    
video: 

    + (void)video:(bool)video

Allow you not to use video.
