//
//  Copyright © 2017 SeatGeek. All rights reserved.
//

@import UIKit;

// A protocol defining the user properties that are available
@protocol SGKUserInfo

/// The user's SeatGeek ID
@property (nonatomic, copy, readonly, nullable) NSString *ID;

/// The account ID in the CRM management tool that the team is using
@property (nonatomic, copy, readonly, nullable) NSString *crmId;

/// The user's email address
@property (nonatomic, copy, readonly, nullable) NSString *email;

/// The user's mobile phone number
@property (nonatomic, copy, readonly, nullable) NSString *mobilePhone;

/// The user's first name
@property (nonatomic, copy, readonly, nullable) NSString *firstName;

/// The user's last name
@property (nonatomic, copy, readonly, nullable) NSString *lastName;

@end

@class SGKSDKTicketGroup;
@class SGKUpcomingEvent;

@interface SeatGeek : NSObject


#pragma mark - Configuration

/**
 * Configures the SeatGeek client.
 * Call this at the start of your AppDelegate's didFinishLaunching...
 */
+ (void)configure;

+ (void)configureWithClientId:(nonnull NSString *)clientId
                 instanceName:(nonnull NSString *)instanceName
                  redirectURI:(nonnull NSString *)redirectURI;

#pragma mark - Authentication

/// The access token used to authenticate with SeatGeek
@property (class, nonatomic, nullable) NSString *accessToken;

/// Initiates an oAuth login flow from the provided view controller
+ (void)logInFromViewController:(nonnull UIViewController *)fromViewController;

/// A block that will be called every time the user logs in successfully
/// This will also get called when an existing user session is sucessfully resumed.
@property (class, nonatomic, copy, nullable) void (^onLoginSuccessful)(void);

/// A block that will be called every time the user log in attempt fails.
/// errorMessage is a user friendly error message
@property (class, nonatomic, copy, nullable) void (^onLoginFailed)(NSString * _Nullable errorMessage);

/**
 * Resumes an existing user's session.
 * This only needs to be called once per app launch and must be called before fetchAllTickets
 *
 * @note We will handle this automatically unless you opt out of this behavior by setting
 * SuppressAppBecameActiveRequests to YES under SeatGeek in your info.plist
 *
 */
+ (void)resumeSession;

/**
 * Resumes an existing user's session.
 * This allows a client to authenticate a user when the client already has the user's access token.
 *
 * @note If access token is nil this will trigger onLoginFailed
 * @note Upon success this will trigger onLoginSuccessful
 *
 */
+ (void)resumeSessionWithAccessToken:(nonnull NSString *)accessToken;

/**
 * Logs out the current user.
 */
+ (void)logOut;

#pragma mark - Tickets

/**
 * Fetches the next event for the user
 *
 * Queries for the next event for the user and reports the result using the block provided in the method +[SeatGeek onFetchUpcomingTicket:]
 */
+ (void)fetchUpcomingEvent;

/**
 * A block that will be called to inform about the next user event
 *
 * This block can be called multiple times. Some of the situations when it is called include:
 *  * The user logged in
 *  * The user logged out
 *  * The user refreshed the list of tickets when displaying the My Tickets View Controller
 *
 *  This block will be called with an error in the following situations:
 *  * The user is not logged in (or just performed the log out
 *  * The user has no upcoming event
 *  * And general error (network failure, for example)
 *
 *  @param completionBlock  The block that will be executed
 */
+ (void)onFetchUpcomingEventFinished:(void (^ _Nonnull)(SGKUpcomingEvent * _Nullable, NSError * _Nullable))completionBlock;

#pragma mark - User

// The current logged in user. This will be nil if no user is logged in.
// This user object will be missing data upon app launch after termination, until resumeSession finishes.
@property (class, nonatomic, strong, readonly, nullable) id <SGKUserInfo> currentUserInfo;


#pragma mark - Customization

/// The primary color used throughout the SeatGeek UI.
/// Default value is SeatGeek's blue.
@property (class, nonatomic, strong, nullable) UIColor *primaryColor;

@end
