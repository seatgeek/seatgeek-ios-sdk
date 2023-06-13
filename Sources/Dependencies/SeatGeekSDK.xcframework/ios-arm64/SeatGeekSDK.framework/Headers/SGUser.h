//
//  Created by matt on 24/10/13.
//

@import CoreLocation;

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import "MGBlockWrapper.h"
#import "SGPerson.h"
#endif

#import "SGUserAccount.h"

@protocol SGItemPrivate;

@class SGHTTPRequest, SGAddress, SGPaymentMethodSpreedly, SGPayoutMethod;
@class SGIncomingTransfersManager, SGIngestionsManager;
@class SGConnectedService, SGPLocation, SGPromoCode, SGReferral, SGUserDomain;
@class SGUserTracking, SGUserConnections, SGPListMetadataItem, SGUserLoginState;

@protocol CheckoutViewModelProtocol;


#define SGUserLoginStarted @"SGUserLoginStarted"
#define SGUserLoginSucceeded @"SGUserLoginSucceeded"
#define SGUserLoginCanceled @"SGUserLoginCanceled"
#define SGUserLoginFailed @"SGUserLoginFailed"
#define SGUserOneTimePasswordLoginFailed @"SGUserOneTimePasswordLoginFailed"
#define SGUserLoggedOut @"SGUserLoggedOut"
#define SGUserSignupFailed @"SGUserSignupFailed"
#define SGUserResetSucceeded @"SGUserResetSucceeded"
#define SGUserResetFailed @"SGUserResetFailed"
#define SGUserVerificationRequired @"SGUserVerificationRequired"
#define SGUserHasChanged @"SGUserHasChanged"
#define SGUserProfilePhotoChanged @"SGUserProfilePhotoChanged"

#define SGUserImageGridPerformersLoaded @"SGUserImageGridPerformersLoaded"
#define SGUserSignedUpToExistingAccount @"SGUserSignedUpToExistingAccount"

#define SGUserConnectToFacebookSucceeded @"SGUserConnectToFacebookSucceeded"
#define SGUserConnectToFacebookFailed @"SGUserConnectToFacebookFailed"
#define SGUserConnectToSpotifySucceeded @"SGUserConnectToSpotifySucceeded"
#define SGUserConnectToSpotifyFailed @"SGUserConnectToSpotifyFailed"
#define SGUserConnectingServiceStarted @"SGUserConnectingServiceStarted"
#define SGUserConnectingServiceFinished @"SGUserConnectingServiceFinished"
#define SGUserConnectingServiceFinishedContextKeyCount @"count"
#define SGUserConnectingServiceFinishedContextKeyListKey @"list_key"
#define SGUserDisconnectingServiceStarted @"SGUserDisconnectingServiceStarted"
#define SGUserDisconnectingServiceFinished @"SGUserDisconnectingServiceFinished"
#define SGUserDisconnectingServiceFailed @"SGUserDisconnectingServiceFailed"

#define SGUserShippingMethodsFetching @"SGUserFetchingShippingInfo"
#define SGUserShippingMethodsFetchFailed @"SGUserFetchingShippingInfoFailed"
#define SGUserShippingMethodsFetchFinished @"SGUserShippingMethodsFetchFinished"

#define SGUserPaymentMethodsFetching @"SGUserFetchingBillingInfo"
#define SGUserPaymentMethodsFetchFailed @"SGUserFetchingBillingInfoFailed"
#define SGUserPaymentMethodsFetchFinished @"SGUserFinishedFetchingBillingInfo"
#define SGUserPaymentMethodsUpdated @"SGUserPaymentMethodsUpdated"

#define SGUserPayoutMethodsFetching @"SGUserPayoutMethodFetching"
#define SGUserPayoutMethodsFetchFailed @"SGUserPayoutMethodFetchFailed"
#define SGUserPayoutMethodsFetchFinished @"SGUserPayoutMethodFetchFinished"

#define SGUserPromoCodesFetching @"SGUserPromoCodesFetching"
#define SGUserPromoCodesFetchFailed @"SGUserPromoCodesFetchFailed"
#define SGUserPromoCodesFetchFinished @"SGUserPromoCodesFetchFinished"

#define SGUserShippingMethodsNeedsRefetch @"SGUserShippingMethodsNeedsRefetch"
#define SGUserPaymentMethodsNeedsRefetch @"SGUserPaymentMethodsNeedsRefetch"
#define SGUserPayoutMethodsNeedsRefetch @"SGUserPayoutMethodNeedsRefetch"
#define SGUserPromoCodesNeedsRefetch @"SGUserPromoCodesNeedsRefetch"

#define SGUserDeletedPaymentMethod @"SGUserDeletedPaymentMethod"
#define SGUserDeletedShippingAddress @"SGUserDeletedShippingAddress"

#define SGFlushTicketCache @"SGUserFlushTicketCache"

#define SGUserFacebookAccountUpgradePromptShownDate @"SGUserFacebookAccountUpgradePromptShownDate"

typedef NS_ENUM(NSUInteger, SGTrackerUserContactUIOrigin);
typedef NS_ENUM(NSUInteger, SGTrackerUserTwoFAMode);
typedef NS_ENUM(NSUInteger, SGTrackerAuthenticatedLinkUIOrigin);
typedef NS_ENUM(NSUInteger, SGTrackerUserEventUIOrigin);

@interface SGUser : SGPerson

#pragma mark - Data managers

@property (nonatomic, readonly, nullable) SGIncomingTransfersManager *incomingTransfersManager;
@property (nonatomic, readonly, nullable) SGIngestionsManager *ingestionsManager;

#pragma mark - Other objects/properties

- (SGUserTracking * _Nullable)tracker;
#ifndef SEATGEEK_SDK
- (SGUserConnections * _Nullable)connector;
#endif
@property (nonatomic) SGTrackerUserContactUIOrigin trackerContactUIOrigin;

#pragma mark - Globals

@property (class, nonatomic, nullable) SGUser *currentUser;
@property (class, nonatomic, nullable) SGUser *anonUser;

#pragma mark - Initalization

/**
 * This intializer is used only by code in SGUserAccount that needs to create a SGUser
 * at the start of session restore, when a logged in user cold launches the app. At that
 * time only a user ID and access token are available, and after login succeeds,
 * -setDict: will be invoked with the server response to fill in the rest. This
 * initalizer gives us a SGUser with the ID set, but without triggering other
 * behaviors in our -setDict: method that we only want to trigger when the session restore
 * is complete.
 *
 * This method calls -setUpDataManagersIfNecessary.
 */
- (instancetype _Nonnull)initRestoreSessionUserWithID:(NSString * _Nonnull)userID accessToken:(NSString * _Nonnull)accessToken;

#pragma mark - Properties

@property (nonatomic, copy, nullable) NSString *facebookId;
@property (nonatomic, copy, nullable) NSString *spotifyId;
@property (nonatomic, copy, nullable) NSString *accessToken;  // only to be set once
@property (nonatomic, copy, nullable) NSString *city;
@property (nonatomic, copy, nullable) NSString *state;
@property (nonatomic, copy, nullable) NSString *zipCode;
@property (nonatomic, copy, nullable) NSString *displayLocation;
@property (nonatomic, readonly) BOOL accountHasLocationSet;
@property (nonatomic, copy, nullable) NSString *phone;
@property (nonatomic, copy, nullable) NSString *prettyPhone;
@property (nonatomic, copy, nullable) NSDictionary *verifiedContactMethods;
@property (nonatomic, copy, nullable) NSNumber *hasPassword;
@property (nonatomic, assign) SGTrackerUserTwoFAMode twoFAMode;
@property (nonatomic, assign) BOOL twoFAIsActive;


/* The password property is used only when the user changes their email, but it makes the form validation
 * and address book keyboard accessory logic much simpler if we can treat it like other properties.
 * It's best to clear it and remove previousValues[@"email"] when you're done with it.
 */
@property (nonatomic, copy, nullable) NSString *password;

/**
 * True if the SGUser has been set up with properties received from the server, false
 * if still waiting for server response (during resume session after cold launch).
 */
@property (nonatomic, readonly) BOOL isComplete;

#pragma mark - Shipping Addresses
@property (nonatomic, strong, nullable) NSArray *shippingAddresses;
@property (nonatomic, strong, nullable) SGAddress *defaultShippingAddress;
- (void)setDefaultShippingAddress:(SGAddress * _Nullable)address
                       tellServer:(BOOL)tellServer;
- (void)deleteShippingAddress:(SGAddress * _Nonnull)address;
- (void)fetchShippingAddressesThenDo:(MGBlock _Nullable)success onFail:(SGAPIFailBlock _Nullable)onFail
                             onRetry:(MGBlock _Nullable)onRetry;
- (void)updateShippingAddressesWithDict:(NSDictionary * _Nullable)dict;
- (NSString * _Nullable)shippingAddressesStatus;
- (SGAPIError * _Nullable)shippingAddressesError;

#pragma mark - Payment Methods
@property (nonatomic, strong, nullable) SGPaymentMethodSpreedly *defaultPaymentMethod;
- (void)setDefaultPaymentMethod:(SGPaymentMethodSpreedly * _Nullable)paymentMethod
                     tellServer:(BOOL)tellServer;
@property (nonatomic, assign, readonly) BOOL hasEligibleRecoupmentMethod;
@property (nonatomic, strong, readonly, nullable) SGPaymentMethodSpreedly *eligibleRecoupmentMethod;
@property (nonatomic, strong, nullable) NSArray <SGPaymentMethodSpreedly *> *paymentMethods;
- (void)deletePaymentMethod:(SGPaymentMethodSpreedly * _Nonnull)paymentMethod checkoutViewModel:(id <CheckoutViewModelProtocol>  _Nonnull)checkoutViewModel;
- (void)fetchPaymentMethodsThenDo:(MGBlock _Nullable)success onFail:(SGAPIFailBlock _Nullable)onFail
                          onRetry:(MGBlock _Nullable)onRetry;
- (void)updatePaymentMethodsWithDict:(NSDictionary * _Nullable)dict;
- (NSString * _Nullable)paymentMethodsStatus;
- (SGAPIError * _Nullable)paymentMethodsError;

#pragma mark - Domains
@property (nonatomic, strong, readonly, nullable) NSArray <SGUserDomain *> *subscribedDomains;

#pragma mark - Payout Methods
@property (nonatomic, strong, nullable) NSArray <SGPayoutMethod *> *payoutMethods;
- (void)refreshPayoutMethod:(SGPayoutMethod * _Nonnull)payoutMethod thenDo:(MGBlock _Nullable)success onFail:(SGAPIFailBlock _Nullable)onFail;
- (void)fetchPayoutMethodsThenDo:(MGBlock _Nullable)success onFail:(SGAPIFailBlock _Nullable)onFail onRetry:(MGBlock _Nullable)onRetry;

// The default payout method for use in contexts where the user is unable to see or choose between all available methods.
@property (nonatomic, strong, readonly, nullable) SGPayoutMethod *defaultPayoutMethod;
- (NSString * _Nullable)payoutMethodsStatus;
- (SGAPIError * _Nullable)payoutMethodsError;

#pragma mark - Promo Codes
@property (nonatomic, strong, nullable) NSArray <SGPromoCode *> *promoCodes;
- (void)updatePromoCodesWithDict:(NSDictionary * _Nullable)dict;
- (NSString * _Nullable)promoCodesStatus;
- (SGAPIError * _Nullable)promoCodesError;

#pragma mark - Logging In/Out
+ (void)resumeSession;
+ (void)resendTwoFAVerificationSuccess:(MGBlock _Nullable)success fail:(SGAPIFailBlock _Nullable)fail;
+ (void)disableTwoFAWithBackup:(NSString * _Nonnull)code success:(MGBlock _Nullable)success fail:(SGAPIFailBlock _Nullable)fail;
+ (void)logout;

#pragma mark - Update To Server
- (void)forceSaveChangesThenDo:(MGBlock _Nullable)success onFail:(SGAPIFailBlock _Nullable)fail;
- (void)saveChangeToEmailThenDo:(MGBlock _Nullable)success onFail:(SGAPIFailBlock _Nullable)fail;
- (void)saveLocation:(SGPLocation * _Nullable)location toServerThenDo:(MGBlock _Nullable)success onFail:(SGAPIFailBlock _Nullable)fail;
- (void)updateToServerThenDo:(MGBlock _Nullable)success onFail:(SGAPIFailBlock _Nullable)fail;
- (void)updatePhoneNumber:(NSString * _Nullable)phone onSuccess:(MGBlock _Nullable)success onFail:(SGAPIFailBlock _Nullable)fail;

#pragma mark - Fetch single use authentication token
- (void)fetchSingleUseTokenForLinkTarget:(NSString * _Nonnull)target
                                uiOrigin:(SGTrackerAuthenticatedLinkUIOrigin)uiOrigin
                                 success:(nullable void(^)(NSString * _Nullable token))successBlock
                                 failure:(nullable void(^)(SGAPIError * _Nonnull apiError))failureBlock;

#pragma mark - Easy Tracking
+ (BOOL)canTrackItem:(SGItem <SGItemPrivate> * _Nullable)item;
+ (BOOL)isTrackingItem:(SGItem <SGItemPrivate> * _Nullable)item;
+ (void)toggleTrackingOfItem:(SGItem <SGItemPrivate> * _Nullable)item uiOrigin:(SGTrackerUserEventUIOrigin)uiOrigin;
+ (void)toggleTrackingOfItem:(SGItem <SGItemPrivate> * _Nullable)item browseMetadata:(SGPListMetadataItem * _Nullable)metadata;

#pragma mark - Tracking with only IDs
+ (BOOL)canTrackItemOfClass:(Class _Nonnull)type;
+ (BOOL)isTrackingItemWithID:(NSString * _Nonnull)ID class:(Class _Nonnull)type;
+ (void)toggleTrackingOfItemWithID:(NSString * _Nonnull)ID class:(Class _Nonnull)type uiOrigin:(SGTrackerUserEventUIOrigin)uiOrigin;

#pragma mark - Password Reset
+ (void)sendPasswordResetRequestFor:(NSString * _Nonnull)email onSuccessDo:(MGBlock _Nullable)success
                           onFailDo:(MGBlock _Nullable)fail;

#pragma mark - Login States
+ (BOOL)loggedIn;
+ (BOOL)loggingIn;

/** true when a session exists but we are waiting to get internet back before logging in */
+ (BOOL)isWaitingToRestoreSession;

/// Called when login has been completed by the /me endpoint




/**
 * true whenever a session exists. From the user's perspective, this is "logged in", but we
 * can be in any of the states listed below internally:
 *   - waiting to restore session (have a saved access token, waiting for network availability to log in)
 *   - restore session in progress (logging in with a saved access token)
 *   - logged in
 */
+ (BOOL)sessionExists;

+ (SGUserLoginState * _Nullable)loginState;

#pragma mark - Metadata
- (CLLocationCoordinate2D)location;

#pragma mark - Profile Photo Handling
- (void)setProfileImage:(UIImage * _Nullable)image
               cropRect:(CGRect)cropRect
              onSuccess:(MGBlock _Nullable)success
                 onFail:(SGAPIFailBlock _Nullable)fail;
- (void)deleteProfileImageThen:(MGBlock _Nullable)success
                        onFail:(SGAPIFailBlock _Nullable)fail;
- (BOOL)canDeleteProfilePhoto;

#pragma mark - Verification
- (void)verifyMobilePhoneNumberWithCode:(NSString * _Nullable)code success:(nullable void(^)(void))successBlock failure:(nullable void(^)(SGAPIError * _Nullable apiError))failureBlock;
- (void)resendEmailVerificationThen:(MGBlock _Nullable)successBlock failure:(nullable void(^)(SGAPIError * _Nullable apiError))failureBlock;
- (void)resendPhoneVerificationThen:(MGBlock _Nullable)successBlock failure:(nullable void(^)(SGAPIError * _Nullable apiError))failureBlock;
@property (readonly) BOOL isEmailVerified;
@property (readonly) BOOL isMobilePhoneVerified;
@property (assign) BOOL requestedEmailVerificationThisSession;
@property (readonly, assign) BOOL requestedPhoneVerificationThisSession;

#pragma mark - Notifications / Device endpoint
+ (void)sendNotificationInfo;

@property (class, nullable, nonatomic) NSString *APSDeviceToken;

#pragma mark - Validators
+ (BOOL)validEmail:(NSString * _Nullable)email;
+ (BOOL)validLoginPassword:(NSString * _Nullable)password;
+ (BOOL)validSignupPassword:(NSString * _Nullable)password;


#pragma mark - Referrals
// The referral information for the user
@property (nonatomic, strong, nullable) SGReferral *referral;

#pragma mark - Attendance Survey
// The ID for a pending attendance survey to be shown to the user.
@property (nonatomic, strong, nullable) NSString *pendingSurveyId;

@end

