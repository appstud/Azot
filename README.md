<p align="center" >
  <img src="https://board.azot.io/img/icons/logo_azot.svg" alt="Azot" title="Azot" width="300" height="300">
</p>

![Platform](https://img.shields.io/badge/platform-ios-blue.svg)
[![CocoaPods](https://img.shields.io/badge/Pod-0.3.36-red.svg)](https://cocoapods.org/pods/Azot)
[![Facebook](https://img.shields.io/badge/Facebook-Azot%20Ltd-blue.svg)](https://www.facebook.com/uxanalysis)
![Carthage](https://img.shields.io/badge/Carthage-compatible-green.svg)

Azot is a mobile analysis SDK that runs directly inside phones or tablets. This repository holds the framework for the iOS version of Azot written in Objective-C.

## Features

- [x] User sessions videos
- [x] Gesture analysis
- [x] Embed feedback
- [x] Crashs analysis
- [x] Sessions analysis
- [x] Heatmaps
- [x] Remote settings

##Supported OS & SDK Versions

* Supported build target - iOS 8.3
* Earliest supported deployment target - iOS 9.3.2
* Earliest compatible deployment target - iOS 7.0

**NOTE**: 'Supported' means that the library has been tested with this version. 'Compatible' means that the library should work on this OS version (i.e. it doesn't rely on any unavailable SDK features) but is no longer being tested for compatibility.

##Thread Safety

Azot uses threading internally to avoid blocking the UI, but none of the Azot external interfaces are thread safe and you should not call any methods on Azot except from the main thread.

##Installation

Use CocoaPods by adding this line to your podfile :

    pod 'Azot'

**Or**

Install Azot manually into your app by dragging the Azot.framework into your project.

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

##Start

Add the following code to your appDelegate :

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
       
  **NOTE**: To get your "AZOT_APP_TOKEN", register <a href="https://board.azot.io" target="_blank">here</a> and create an app.
    
##Important notes

The SDK does not generate videos on simulator.

If you are running from Xcode do not stop the app, press the "home" button in order to upload datas.

##Confidentiality

The confidentiality level of screenshots and vidéos have three levels:

Confidentiality level   |   Hidden elements 
------------------------|-------------------- 
AZConfidentialityMedium |   Keyboard + TextFields + Capture Video PreviewLayer
AZConfidentialityHigh   |   AZConfidentialityMedium + Images + Labels

The default confidentiality level is medium.

##Methods

####start:

  **objC**
  
    + (void)start:(NSString*)azotAppToken;
  
  **swift**

    static func start(azotAppToken:String)

Start analysis in the app with video and medium confidentiality level. Call it in your app delegate.
It is the only mandatory function that has to be used.

####startPage: 

  **objC**

    + (void)startPage:(NSString *)pageId
  
  **swift**

    static func startPage(pageId:String)

Start analysis of a page. Call it in your controller viewDidAppear.
Tips: Use this function to analyse a “page”, understood as what the user can see.

####stopPage: 

  **objC**

    + (void)stopPage:(NSString *)pageId

  **swift**

    static func stopPage(pageId:String)

Stop a page analysis. Call it in your controller viewDidDisapear.

####event: 

  **objC**

    + (void)event:(NSString *)eventId
  
  **swift**

    static func event(eventId:String)

Track events you care about in your app.
    
####feedback:

  **objC**

    + (void)feedback:(NSString*)message forCategory:(NSString*)category;
  
  **swift**

    static func feedback(message:String, category:String)

This function is used to collect user feedbacks. The feedbacks will be saved in the session report.
It is the one used in our feedback feature.

####show feedback:

  **objC**
  
    + (void)showFeedbackView;
  
  **swift**
  
    static func showFeedbackView()

Shows the Azot feedback page. This function can be used in a feedback button action.

####AZLog:

    OBJC_EXTERN void AZLog(NSString *format, ...) NS_FORMAT_FUNCTION(1,2);

This function prints and saves your logs, simply use AZLog instead of NSLog. (Only available with ObjectiveC)

##Configuration

You can acces sdk parameters through your dashboard on https://board.azot.io

###General Parameters
___

####Use feedback
Activate or desactivate the "shake for feedback" functionality. (Activated by default)

####Session recording
Activate or desactivate session recording. (Activated by default)

####Location recording
Activate or desactivate location tracking. (Activated by default)

####Record on debug mode
If activated only session from apps downloaded through the Appstore will be retrieved. (Activated by default)

####Only upload on wifi
If activated datas will only be sent when the user is connected to wifi. (Desactivated by default)

####Use auto pages tracking
If activated pages will be automatically tracked. (Activated by default)

####Use date range
Allows you to set a date range in which the SDK will be on. (Desactivated by default)

###Video Parameters
___

####Video recording
Activate or desactivate the video. (Desactivated by default)

####Only upload on wifi
If activated videos will only be sent when the user is connected to wifi. (Activated by default)

####Confidentiality
Set the video confidentiality level. (MEDIUM by default)

####Use date range
Allows you to set a date range in which the Video will be on. (Desactivated by default)

###Feedback Parameters
___

####Use feedback
Activate or Desactivate the "Shake for feedback" gesture. (Activated by default)

####Question for your users
Define the question you want us to ask your users on the top of the feedback page.

####Categories
Define different feedback categories. (Max. 5)
