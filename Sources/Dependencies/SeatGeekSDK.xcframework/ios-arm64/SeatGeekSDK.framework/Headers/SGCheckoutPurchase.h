//
//  Created by matt on 16/01/15.
//

@import Foundation;

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import <SeatGeekSDK/SGAPIError.h>
#import <SeatGeekSDK/MGBlockWrapper.h>
#import <SeatGeekSDK/SGPurchase.h>
#endif

#define SGCheckoutPurchaseSummaryFetchStarted       @"SGCheckoutPurchaseSummaryFetchStarted"
#define SGCheckoutPurchaseSummaryFetchFinished      @"SGCheckoutPurchaseSummaryFetchFinished"
#define SGCheckoutPurchaseAffirmPromotionalMessagingFetchFinished      @"SGCheckoutPurchaseAffirmPromotionalMessagingFetchFinished"
#define SGCheckoutPurchaseSummaryFetchFailed        @"SGCheckoutPurchaseSummaryFetchFailed"
#define SGCheckoutPurchaseUserSecurityCheckRequired @"SGCheckoutPurchaseUserSecurityCheckRequired"
#define SGCheckoutPurchaseSucceeded                 @"SGCheckoutPurchaseSucceeded"
#define SGVibrateSummaryErrors @"SGVibrateSummaryErrors"
#define SGOpenedWebCheckout @"SGOpenedWebCheckout"

#import "SGTracker.h"

@class SGUser, SGUserShippingAddress, SGUserPaymentMethod, SGPurchaseDeliveryMethod, SGListing, SGPromoCode, SGAccessCode, SGCartLevelCoupon, SGAcknowledgement, SGKReturnPolicy, SGKPaymentAffirm, SGKPaymentSpreedlyAffirmHandler, SGKAffirmPromotionalMessagingHelper;
@class SGSeatOption;

@protocol CheckoutViewModelProtocol;

@interface SGCheckoutPurchase : SGPurchase

+ (instancetype)purchaseForListing:(SGListing *)listing;

@property (nonatomic, copy) NSString *transactionId;

// from server
@property (nonatomic, strong) NSArray *availableSplits;
@property (nonatomic, strong) NSArray <SGSeatOption *> *availableSeats;
@property (nonatomic, strong) SGSeatOption *selectedSeat;
@property (nonatomic, strong) NSArray <NSDictionary *> *selectedAddOns;
@property (nonatomic, strong) SGKReturnPolicy *returnPolicy;

/// optional array of dictionaries that we just bounce back to the server
@property (nonatomic, copy) NSString *statefulCartID;
@property (nonatomic, strong) NSArray *bundleItems;
@property (nonatomic, strong) NSArray *availableDeliveryMethods;
@property (nonatomic, strong) NSArray *priceTypes;
@property (nonatomic, readonly) BOOL hasPriceTypes;
@property (nonatomic, strong) NSString *ineligibleListingMessage;
@property (nonatomic) BOOL showSwapsExperience;
@property (nonatomic, strong) NSArray <SGPromoCode *> *availablePromoCodes;
@property (nonatomic, strong) NSArray <SGAcknowledgement *> *acknowledgements;
@property (nonatomic, assign) BOOL promoCodeEligible;
@property (nonatomic, assign) BOOL requiresPaymentMethod;
@property (nonatomic, strong) SGPromoCode *promoCode;
@property (nonatomic, strong) SGKPaymentAffirm *paymentAffirm;
@property (nonatomic, strong) SGAccessCode *accessCode;
@property (nonatomic, strong) SGCartLevelCoupon *cartLevelCoupon;
@property (nonatomic, copy) NSString *accessToken;
@property (nonatomic, strong) NSArray <SGAPIError *> *errors;
@property (nonatomic, readonly) NSNumber *totalPriceInCents;
@property (nonatomic, assign) BOOL priceTypesNeedReselection;
@property (nonatomic, assign) BOOL shouldLaunchTransfers;
@property (nonatomic, assign) BOOL isHorizontal;
@property (nonatomic, strong) NSString *taxTransactionCode;
@property (nonatomic, strong) NSString *cartID;

@property (nonatomic, assign) BOOL cvvRecacheNeeded;
@property (nonatomic, assign) BOOL affirmInitialIsEligible;
@property (nonatomic, assign) BOOL hasErrorsFromAffirm;
@property (nonatomic, assign) BOOL fetchingAffirmPromotionMessage;
@property (nonatomic, assign) BOOL beforeSummaryCanApplePay;

- (BOOL)allowSeatSelection;
// Allow for visually refreshing the selected seat grouping for the new SGE design
- (void)setDefaultSeats;

// from client
@property (nonatomic, strong) SGUser *user;
@property (nonatomic, strong) SGListing *listing; // Note: Removed readonly for testing purposes
@property (nonatomic, weak) UIViewController *affirmPresentingViewController;
@property (nonatomic, strong) SGKAffirmPromotionalMessagingHelper *affirmPromotionalMessagingHelper;
- (NSString *)combinedNotes;

// from client and server
@property (nonatomic, strong) NSMutableDictionary *marketSpecificFields;

// getting chatty with the server
- (void)hitClickTrackerThenDo:(MGBlock)completion onFail:(SGAPIFailBlock)onFail;
- (void)fetchSummaryThenDo:(MGBlock)success onFail:(SGAPIFailBlock)fail;
- (void)submitThenDo:(MGBlock)success onFail:(SGAPIFailBlock)fail;
#ifndef SEATGEEK_SDK
- (void)submitWithAffirm:(SGKPaymentSpreedlyAffirmHandler *)paymentSpreedlyAffirm onSuccess:(MGBlock)success onFail:(SGAPIFailBlock)fail;
#endif
- (void)parseErrorsIn:(NSDictionary *)response request:(SGHTTPRequest *)request;
- (void)validatePriceTypesReceived:(NSArray *)priceTypesReceived withPriceTypesSent:(NSArray *)priceTypesSent;
- (void)trackCheckoutErrorIncludesAffirm:(BOOL)affirm;
- (void)trackCheckoutSuccessIncludesAffirm:(BOOL)affirm;

// request states
- (BOOL)fetchingClickID;
- (BOOL)submitting;
- (BOOL)submitSucceeded;

- (NSString *)displayStringForQuantity;
- (NSString *)displayStringForQuantityNoE;

- (BOOL)allowDeliveryMethodSelect;

/// Sets if the summary exists
@property (nonatomic,assign) BOOL hasSummary;
/// Sets if the summary is currently being fetched
@property (nonatomic,assign) BOOL fetchingSummary;
/// Sets if fethcing the summary failed permanently
@property (nonatomic,assign) BOOL failedPermanently;
/// Flag remotely operated by the server which dictates whether we show any promo code UI or not
@property (nonatomic, assign) BOOL showPromoCodeUI;
/// Sets if apple pay was initially selected
@property (nonatomic, assign) BOOL doneInitialApplePaySelect;
/// Sets if the device is able to apple pay
@property (nonatomic, assign) BOOL canApplePay;
/// Doesn't guarantee that apple pay is being used, but that apple pay is the option currently presented to the user
@property (nonatomic,assign) BOOL applePaySelected;
/// Doesn't guarantee that affirm is being used, but that affirm payment is the option currently presented to the user
@property (nonatomic,assign) BOOL affirmSelected;
/// true if the user had the choice of using apple pay, but explicitly changed to a credit card
@property (nonatomic,assign) BOOL userDoesntWantApplePay;
// This var stores the state of the is_eligible flag on the affirm object. The comparison of the incoming in_eligible flag with the initial one determines if affirm is shown or hidden
@property (nonatomic,assign) BOOL didSetAffirmInitialIsEligible;
/// Sets if the purchase is being submitted
@property (nonatomic,assign) BOOL submitting;
/// Sets if the purchase was successfully submitted
@property (nonatomic,assign) BOOL submitSucceeded;
- (BOOL)isApplePay;

- (BOOL)useSandbox;

- (NSArray *)errorsForCategory:(NSString *)errorCategory;
- (NSArray *)localValidationErrors; // note this actually performs local validation
- (NSArray *)localValidationErrorsForCategory:(NSString *)errorCategory;  // note this actually performs local validation
- (BOOL)hasFatalErrors;
- (BOOL)hasGeneralErrors;
- (BOOL)hasErrors;
- (BOOL)hasNonPaymentRelatedErrors;

/// returns true if the errors array contains the "account exists / login required error".
@property (nonatomic, readonly) BOOL loginRequired;

@property (nonatomic, strong) id <CheckoutViewModelProtocol> checkoutViewModel;

// Cart mode
- (BOOL)cartModeEnabled;
- (void)clearCartInformation;

// affirm
- (void)parseAffirmEligibilityErrors;
- (void)fetchAffirmPromotionalMessaging;

// tracker
+ (SGTrackerCheckoutErrorCategory)trackerErrorCategoryFor:(NSString *)category;
@end
