//
//  Created by matt on 9/04/14.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import "MGBlockWrapper.h"
#endif

extern NSString *const SGUserAccountLoginSucceeded;
extern NSString *const SGUserAccountLoginFailed;
extern NSString *const SGUserAccountLoggedOut;

typedef void (^SGKeychainCompletion)(NSString *username, NSString *password);

typedef NS_ENUM(NSInteger, SGAuthMode) {
    SGAuthModeFacebook,
    SGAuthModeSignUp,
    SGAuthModeLogIn,
    SGAuthModeTwoFA,
    SGAuthModeOneTimePassword
};

@class SGUserLoginState;

@interface SGUserAccount : NSObject

#pragma mark - Logging In / Out
+ (void)resumeSession;
+ (void)resendTwoFAVerificationSuccess:(MGBlock)success fail:(SGAPIFailBlock)fail;
+ (void)disableTwoFAWithBackup:(NSString *)code success:(MGBlock)success fail:(SGAPIFailBlock)fail;
+ (void)logout;

+ (void)loginAfterTokenExchangeWithAccessToken:(NSString *)accessToken;

#pragma mark - Protected Network rerouting support
+ (void)handleAuthSuccessWithResponseData:(NSData *)responseData
                       responseStatusCode:(NSInteger)statusCode
                        requestParameters:(NSDictionary *)requestParameters
                         requestUrlString:(NSString *)requestUrlString
                                 authMode:(SGAuthMode)mode;

+ (void)handleAuthFailureWithSGAPIError:(SGAPIError *)apiError
                           responseData:(NSData *)responseData
                        responseStatusCode:(NSInteger)statusCode
                   requestParameters:(NSDictionary *)requestParameters
                    requestUrlString:(NSString *)requestUrlString
                               authMode:(SGAuthMode)mode;

+ (void)setIsFacebookSession:(BOOL)isFacebookSession;

#pragma mark - Safari Keychain
+ (void)saveCredentialsToSafariKeychainWithUserName:(NSString *)username
                                           password:(NSString *)password;

/**
 Evaluates whether or not we should manually prompt a user to save their credentials to iCloud keychain.
 There are certain scenarios where we shouldn't do this, such as when the system does it automatically
 or when one or both of the credentials is blank or nil.

 @param username The username used
 @param password The password used
 @return YES if we should manually prompt a user to save their credentials to iCloud keychain.
 */
+ (BOOL)shouldPromptToSaveCredentialsToKeychainWithUserName:(NSString *)username
                                                   password:(NSString *)password;

#pragma mark - Password Reset
+ (void)sendPasswordResetRequestFor:(NSString *)email onSuccessDo:(void (^)(void))success
                           onFailDo:(void (^)(void))fail;

#pragma mark - Login States
+ (BOOL)loggedIn;
+ (BOOL)loggingIn;
+ (BOOL)isWaitingToRestoreSession;
+ (BOOL)sessionExists;
+ (SGUserLoginState *)loginState;
+ (void)setLoginState:(SGUserLoginState *)state;

#pragma mark - Session type

/**
 * true if user logged in via FB, false if not. Note that currently, this
 * method will return true after a failed FB login attempt, even though not
 * logged in at all.
 */
+ (BOOL)isFacebookSession;

@end
