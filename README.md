# Azot
Azot is a mobile analysis SDK that runs directly inside phones or tablets. This repository holds the framework for the iOS version of Azot written in Objective-C.

##Supported OS & SDK Versions

* Supported build target - iOS 8.3
* Earliest supported deployment target - iOS 9.2.1
* Earliest compatible deployment target - iOS 7.1
* 
**NOTE**: 'Supported' means that the library has been tested with this version. 'Compatible' means that the library should work on this OS version (i.e. it doesn't rely on any unavailable SDK features) but is no longer being tested for compatibility and may require tweaking or bug fixes to run correctly.


##Thread Safety

Azot uses threading internally to avoid blocking the UI, but none of the Azot external interfaces are thread safe and you should not call any methods on Azot except from the main thread.

##Installation

To install Azot into your app, drag the Azot.framework into your project.

Add those native dependencies to your project:

- AddressBook.framework
- AssetsLibrary.framework
- CoreBluetooth.framework
- CoreMedia.framework
- CoreLocation.framework
- SystemConfiguration.framework
- AVFoundation.framework

Then add the compile flags following those steps:

1. In Xcode, choose View > Navigators > Show Project Navigator.
2. Select your project under the PROJECT heading in the Project Navigator, then select the Build Settings tab.
3. Scroll down to the Other Linker Flags build setting under the Linking collection, or type "Other Linker Flags" into the search bar.
4. Set the value of the Other Linker Flags build setting to $(OTHER_LDFLAGS) -ObjC.



**Or**

Use CocoaPods by adding this to your podfile :

    pod 'Azot'


To start Azot analysis add the following code in your appDelegate :

#####Objective C

    #import <Azot/Azot.h>
        
    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
         [Azot start:@"AZOT_APP_TOKEN"];
         return YES;
    }
    
#####Swift

Import \<Azot/Azot.h\> in your bridging header.

    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
       Azot.start("AZOT_APP_TOKEN")
       return true
       }
    
##Important notes

The SDK does not generate videos on simulator.

If you are running from XCode do not stop the app, press the "home" button in order for data to be uploaded.

##Confidentiality

The confidentiality level of screenshots and vidéos have three levels:

Confidentiality level   |   Hidden elements 
------------------------|--------------------
AZConfidentialityLow    |   Nothing 
AZConfidentialityMedium |   UITextFields + AVCaptureVideoPreviewLayer
AZConfidentialityHigh   |   AZConfidentialityMedium + UIImages + UILabels

The default confidentiality level is medium.

##Methods

Azot has the following methods:

####start:

    + (void)start:(NSString*)azotAppToken;

Start analysis in the app with video and medium confidentiality level. Call it in your app delegate.
It is the only mandatory function that has to be used.

####startPage: 

    + (void)startPage:(NSString *)pageId

Start analysis of a page. Call it in your controller viewDidAppear.
Tips: Use this function to analyse a “page”, understood as what the user can see.

####stopPage: 

    + (void)stopPage:(NSString *)pageId

Stop a page analysis. Call it in your controller viewDidDisapear.

####event: 

    + (void)event:(NSString *)eventId

Track events you care about in your app.
    
####message:

    + (void)message: (NSString*)message;

This function is used to collect user feedbacks. The feedbacks will be saved in the session report.
It is the one used in our feedback feature.

####AZLog:

    OBJC_EXTERN void AZLog(NSString *format, ...) NS_FORMAT_FUNCTION(1,2);

This function prints and saves your logs, simply use AZLog instead of NSLog.

##Configuration

You can acces sdk parameters through your dashboard on http://board.azot.io

###General Parameters
___

####Use feedback
Activate or desactivate the "shake for feedback" functionality.

####Session recording
Activate or desactivate session recording.

####Location recording
Activate or desactivate location tracking.

####Record on debug mode
If activated only session from apps downloaded through the Appstore will be retrieved.

####Only upload on wifi
If activated datas will only be sent when the user is connected to wifi.

####Use auto pages tracking
If activated pages will be automatically tracked.

####Use date range
Allows you to set a date range in which the SDK will be on.

###Video Parameters
___

####Video recording
Activate or desactivate the video.

####Only upload on wifi
If activated videos will only be sent when the user is connected to wifi.

####Confidentiality
Set the video confidentiality level.

####Use date range
Allows you to set a date range in which the Video will be on.
