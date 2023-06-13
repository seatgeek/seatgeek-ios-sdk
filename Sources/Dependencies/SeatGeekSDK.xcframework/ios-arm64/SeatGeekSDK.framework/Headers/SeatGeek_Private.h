//
//  SeatGeek_Private.h
//  SeatGeek
//
//  Created by Ed Paulosky on 10/12/17.
//  Copyright © 2017 SeatGeek. All rights reserved.
//

#import "SeatGeek.h"

/*

 Steps to Generate the framwork for distribution.
 1. sudo bash generate-universal-framework.sh Release
 NOTE: generate-universal-framework.sh is located in the root folder of the repo
 2. Compress SeatGeekSDK/Release-Framwork/SeatGeek.SDK.framework
 3. Upload

If you want to generate the framework for debugging so that you can properply step through code,
 then run sudo bash generate-universal-framework.sh Debug

 ***NOTE***
 - lipo -info SeatGeekSDK.framework/SeatGeekSDK should output i386 x86_64 armv7 arm64
 - SeatGeekSDK.framework must contain a strip-frameworks.sh file, which is a shell script to strip out the simulator architectures for app store release

 **/

@class SGKSDKAuth, SGKTicketFetchManager, SGModalCardHolder, SGKSDKUser;

@interface SeatGeek ()

@property (class, nonatomic, readonly) NSString *clientId;
@property (class, nonatomic, readonly) NSString *clientSecret;
@property (class, nonatomic, readonly) NSString *redirectURI;
@property (class, nonatomic, readonly) NSString *instanceName;

@property (class, nonatomic, readonly) SGKSDKAuth *auth;

@property (class, nonatomic, strong) SGModalCardHolder *cardHolder;
@property (class, nonatomic, strong) SGModalCardHolder *topCardHolder;

@property (assign) BOOL shouldRefreshTicketsWhenAppEntersForeground;
- (void)handleAppWillEnterForeground:(NSNotification *)notification;

+ (instancetype)sharedInstance;

// frames and sizes
+ (CGRect)screenBounds;
+ (CGRect)screenBoundsMinusOpaqueStatusBar;
+ (CGRect)screenBoundsMinusKeyboard;
+ (CGFloat)opaqueStatusBarHeight;
+ (CGFloat)statusBarHeight;
+ (CGFloat)keyboardHeight;

+ (BOOL)cameraPermissionDenied;



@property (class, nonatomic, strong, readonly) SGKSDKUser *currentUser;

@end
