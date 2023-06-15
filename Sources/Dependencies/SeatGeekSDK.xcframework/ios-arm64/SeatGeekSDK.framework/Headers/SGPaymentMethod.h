//
//  SGPaymentMethod.h
//  Pods
//
//  Created by James Van-As on 31/08/15.
//
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGAddress.h>
#else
#import <SeatGeekSDK/SGAddress.h>
#endif

#define SpreedlyTestEnvironmentKey       @"aC2Z0pfkds5zuIJZg2dE8rDi5jp"
#define SpreedlyProductionEnvironmentKey @"NUxn0YygG6PaIBtvNsWGB3VKWt4"

#define SGPaymentMethodTypeSpreedly @"creditcard"
#define SGPaymentMethodTypeBraintreeApplePayLegacy @"braintree_apple_pay"
#define SGPaymentMethodTypeApplePay @"apple_pay"
#define SGPaymentMethodTypeAndroidPay @"android_pay"
#define SGPaymentMethodTypeGooglePay @"google_pay"
#define SGPaymentMethodTypeAffirmVirtualCard @"affirm_virtual_card"

/** Currently, instances of this SGPaymentMethod base class are found in SGPurchase objects
 * contained in SGTicketGroupHistory objects received from the server about past purchases.
 * We create instances of the appropriate child class (SGPaymentMethodSpreedly or
 * SGPaymentMethodApplePay) when doing a new purchase. methodType should always return the
 * correct string.
 */
@interface SGPaymentMethod : SGAddress

@property (nonatomic, strong) NSString *methodType;

@property (nonatomic, copy) NSString *cardType;
@property (nonatomic, copy) NSString *cardNumber;
@property (nonatomic, copy) NSString *prettyCardNumber;
@property (nonatomic, copy) NSString *expirationMonth;
@property (nonatomic, copy) NSString *expirationYear;
@property (nonatomic, copy) NSString *expirationDate;
@property (nonatomic, copy) NSString *lastFourDigits;
@property (nonatomic, copy) NSString *cvv;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, assign) BOOL sandbox;
@property (nonatomic, readonly) NSString *spreedlyEnvironmentKey;
@property (nonatomic, readonly) NSString *spreedlyURL;

- (NSString *)maskedLastFourDigits;
- (UIImage *)cardTypeImage;
- (UIImage *)cardTypeLargeImage;
- (NSArray *)testCardNumbers;

@end
