//
//  Created by matt on 28/11/14.
//

#define SGPaymentDeliveryMethodElectronic @"electronic"
#define SGPaymentDeliveryMethodPhysical   @"ship"
#define SGPaymentDeliveryMethodMobile @"mobile"

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGItem.h>
#else
#import <SeatGeekSDK/SGItem.h>
#endif

@class PKShippingMethod;

@interface SGPurchaseDeliveryMethod : SGItem

@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSNumber *price;

- (NSString *)displayString;
- (BOOL)requiresShippingAddress;
#if !TARGET_OS_WATCH
- (PKShippingMethod *)pkShippingMethod;
#endif

@end
