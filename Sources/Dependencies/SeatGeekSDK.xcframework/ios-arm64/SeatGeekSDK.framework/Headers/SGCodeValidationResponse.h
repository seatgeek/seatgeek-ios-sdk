//
//  SGCodeValidationResponse.h
//  Pods
//
//  Created by Hunter Mask on 12/10/18.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGAccessCode.h>
#import <SeatGeekCore/SGPromoCode.h>
#else
#import <SeatGeekSDK/SGAccessCode.h>
#import <SeatGeekSDK/SGPromoCode.h>
#endif

NS_SWIFT_NAME(CodeValidationResponse)
@interface SGCodeValidationResponse : NSObject

@property (nonatomic, readonly, nullable) SGAccessCode *accessCode;
@property (nonatomic, readonly, nullable) SGPromoCode *discountCode;

/**
 General-level errors
 */
@property (nonatomic, readonly, nonnull) NSArray<SGAPIError *> *generalErrors;

/**
 Access code errors, plus any general-level errors
 */
@property (nonatomic, readonly, nonnull) NSArray<SGAPIError *> *accessCodeErrors;

/**
 Discount code errors, plus any general-level errors
 */
@property (nonatomic, readonly, nonnull) NSArray<SGAPIError *> *discountCodeErrors;

/**
 All errors that were returned
 */
@property (nonatomic, readonly, nonnull) NSArray<SGAPIError *> *allErrors;

- (nonnull instancetype)initWithRequest:(nonnull SGHTTPRequest *)request;

@end
