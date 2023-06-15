//
//  SGAPIError.h
//  SeatGeek
//
//  Created by James Van-As on 8/01/15.
//  Copyright (c) 2015 SeatGeek. All rights reserved.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGHTTPRequest.h>
#else
#import <SeatGeekSDK/SGHTTPRequest.h>
#endif

/**
 for full list of possible checkout related API error codes see here:
 https://github.com/seatgeek/api/tree/master/api/checkout/errors
*/
typedef NS_ENUM(NSInteger, SGAPIErrorCode) {
    SGAPIErrorUnknown = -1,
    SGAPIErrorSpreedlyRedacted = -2,
    SGAPIErrorInvalidSpreedlyToken = 40006,
    SGAPIErrorPaymentMethodRejected = 40010,
    SGAPIErrorSpreedlyRejected = 422,
    SGAPIErrorTransactionFailure = 40016,
    SGAPIErrorTransferAlreadyAccepted = 400245,
    SGAPIErrorTransferStopSendingToYourself = 400604,
    SGAPIErrorTransferPaymentMethodTokenRequired = 400229,
    SGAPIErrorCVVRecacheNeeded = 40031,
    SGAPIErrorBadCVV = 40034,
    SGAPIErrorMarketTimout = 40075,
    SGAPIErrorLoginRequired = 40081,

    SGAPIErrorLoginFailedBadCredentials = 40301,
    SGAPIErrorLoginFailedTwoFACodeRequired = 40199,
    SGAPIErrorSignupFailedBadEmail = 40001,
    SGAPIErrorSignupFailedBadPassword = 40004,
    SGAPIErrorSignupFailedExistingUser = 40002,
    SGAPIErrorSignupFailedExistingFacebookUser = 40003,
    SGAPIErrorSignupFailedEmailRequired = 400117,

    SGAPIErrorQuantityNotValidInCurrentContext = 40132,
    SGAPIErrorCodeNotUsableInCurrentContext = 40133,

    SGAPIErrorAccountVerificationInvalid = 400105,
    SGAPIErrorPayoutMethodVerifying = 400249,

    SGAPIErrorAccessCodeInvalid = 400916,
    SGAPIErrorPromoCodeInvalid = 4001304,
    
    SGAPIErrorEventNotFound = 4040011,
    
    // The below codes are not received from the server
    SGAPIErrorSignupFailedEmailVerificationRequired = -4001,
    
    SGAPIErrorClientTimeOut = NSURLErrorTimedOut
};

// checkout error categories

#define SGAPIErrorCategoryProduct   @"product"
#define SGAPIErrorCategoryContact   @"contact"
#define SGAPIErrorCategoryPayment   @"payment"
#define SGAPIErrorCategoryAffirm    @"affirm"
#define SGAPIErrorCategoryDeliveryMethod  @"delivery_method"
#define SGAPIErrorCategoryDelivery        @"shipping_address"
#define SGAPIErrorCategoryPromoCode @"discount"
#define SGAPIErrorCategoryAccessCode @"access_code"
#define SGAPIErrorCategoryAcknowledgement @"acknowledgement"

// general error categories
#define SGAPIErrorCategoryGeneral   @"general"
#define SGAPIErrorCategoryFatal     @"fatal"
#define SGAPIErrorCategoryUnknown   @"unknown" // misc network issues
#define SGAPIErrorCategoryClientTimeOut @"client_timeout" // client timeouts

// payout method error categories
#define SGAPIErrorCategoryIdentity   @"identity"
#define SGAPIErrorCategoryBank       @"bank"

// sign up / log in error categories
#define SGAPIErrorCategorySignUp      @"sign_up"

// apple wallet error categories
#define SGAPIErrorPKPassCreation      @"pkPass_creation"

@class SGHTTPRequest;

NS_ASSUME_NONNULL_BEGIN
@interface SGAPIError : NSObject

#pragma mark - Construction

+ (instancetype)errorWith:(SGHTTPRequest *)request;

+ (instancetype)errorWith:(SGHTTPRequest *)request
                   error:(NSError *)error
              statusCode:(NSInteger)statusCode;

+ (instancetype)errorWithURL:(NSString *)url
               requestMethod:(SGHTTPRequestMethod)requestMethod
                       error:(NSError *)error
                  statusCode:(NSInteger)statusCode;

+ (nonnull instancetype)errorWithRequest:(SGHTTPRequest *)request sgErrorDict:(nullable NSDictionary *)dict;

+ (nonnull instancetype)errorWithSpreedlyRequest:(SGHTTPRequest *)request;

+ (nonnull instancetype)errorWithNSError:(NSError *)error;

- (void)setSgErrorDict:(NSDictionary *)dict;

#pragma mark Properties

@property (nullable, nonatomic, strong) SGHTTPRequest *request;

@property (nullable, nonatomic, strong) NSString *url;
@property (nonatomic, assign) SGHTTPRequestMethod requestMethod;

@property (nonatomic, assign) NSInteger statusCode; // HTTP status code
@property (nonatomic, assign) SGAPIErrorCode errorCode; // SG API error code

/// property to keep track of whether this error has been seen by the user, to help avoid duplicates.
@property (nonatomic) BOOL userHasSeen;

/// returns true if this error represents a network related error
@property (nonatomic, readonly) BOOL isNetworkRelated;

/// returns true if this error represents a server error (5xx)
@property (nonatomic, readonly) BOOL isServerError;

@property (nonatomic, strong) NSString *message; // "Delivery Details Required"
@property (nonatomic, strong) NSString *shortMessage; // "Required"
@property (nonatomic, strong) NSString *verboseMessage; // "Delivery address is required"
@property (nonatomic, strong) NSString *internalMessage; // defaults to message
@property (nonatomic, strong) NSString *category; // "payment", "delivery", "user", "cvv"
@property (nullable, nonatomic, strong) NSString *resolveHintMessage; // "Edit Delivery Details"

/**
 * Returns the name of the field affected by the error. Note that this class
 * translates field names to our names. For example, "email" becomes "shippingEmail".
 */
@property (nullable, nonatomic, strong) NSString *parameter; // eg "shippingEmail"

/**
 * The server's name for the field, untransformed.
 */
@property (nullable, nonatomic, strong) NSString *property; // eg "email"

@property (nullable, nonatomic, strong) NSError *error;

@end
NS_ASSUME_NONNULL_END

typedef void(^SGAPIFailBlock)(NSArray <SGAPIError *> * _Nullable errors);

