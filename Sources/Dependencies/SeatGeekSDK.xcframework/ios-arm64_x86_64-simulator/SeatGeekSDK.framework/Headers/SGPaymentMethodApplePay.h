//
//  Created by matt on 20/01/15.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/MGBlockWrapper.h>
#import <SeatGeekCore/SGPaymentMethod.h>
#else
#import <SeatGeekSDK/MGBlockWrapper.h>
#import <SeatGeekSDK/SGPaymentMethod.h>
#endif

@import PassKit;

@interface SGPaymentMethodApplePay : SGPaymentMethod

@property (nonatomic) PKPayment *payment;
@property (nonatomic) PKPaymentRequest *paymentRequest;

/** We have two; our legacy braintree type and the normal one. */
+ (NSArray *)applePayPaymentTypes;

/**
 * This dictionary is sent to the server under payment.data.apple_pay.
 * It includes the raw Apple Pay payment data, as well as some supporting
 * metadata that the server may need.
 */
- (NSDictionary *)payload;

/**
 * Returns a list of the merchant IDs that we support. These are simply the
 * IDs found under the com.apple.developer.in-app-payments key in the
 * SeatGeek.entitlements plist.
 */
+ (NSArray<NSString *> *)supportedMerchantIDs;

/// Whether the device can make apple pay payments (has a supported credit card set up in Wallet)
+ (BOOL)deviceCanApplePay;

/// The list of networks that we support for apple pay
+ (NSArray<PKPaymentNetwork> *)supportedNetworks;

- (void)sendToSpreedlyThenDo:(MGBlock)success onFail:(SGAPIFailBlock)fail;

@end
