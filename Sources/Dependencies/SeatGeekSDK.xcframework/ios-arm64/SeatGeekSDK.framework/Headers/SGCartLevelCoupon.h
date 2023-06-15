//
//  SGCartLevelCoupon.h
//  Pods
//
//  Created by Hunter Mask on 11/16/18.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

/**
 A coupon that applies to an entire cart (multiple items).
 */
@interface SGCartLevelCoupon : SGPItem

/**
 The coupon code.
 */
@property (nonatomic, strong, nonnull) NSString *code;

/**
 YES if the code can be removed.
 */
@property (nonatomic, assign) BOOL removable;

/**
 YES if the code should be applied to the corresponding purchase. Defaults to YES.
 */
@property (nonatomic, assign) BOOL isEnabled;

/**
 Human-readable description of the code, if any.
 */
@property (nonatomic, strong, nullable) NSString *couponDescription;

@end
