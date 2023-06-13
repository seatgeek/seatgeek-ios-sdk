//
//  Created by matt on 27/01/15.
//

@import PassKit;

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGItem.h>
#else
#import <SeatGeekSDK/SGItem.h>
#endif

@interface SGPurchaseLineItem : SGItem

@property (nonatomic, copy) NSNumber *quantity;
@property (nonatomic, copy) NSNumber *unitPrice;
@property (nonatomic, copy) NSNumber *totalPrice;
@property (nonatomic, copy) NSString *label;
@property (nonatomic, copy) NSString *role;

- (NSString *)labelWithEachString;
- (NSString *)labelWithEaString;
- (NSString *)eachString;
- (NSString *)quantityAndEachString;

#if !TARGET_OS_WATCH
- (PKPaymentSummaryItem *)pkSummaryItem;
#endif

@end
