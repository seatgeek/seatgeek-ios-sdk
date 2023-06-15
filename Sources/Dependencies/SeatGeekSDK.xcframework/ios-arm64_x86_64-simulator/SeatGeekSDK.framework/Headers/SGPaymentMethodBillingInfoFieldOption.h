//
//  SGPaymentMethodBillingInfoFieldOption.h
//  Pods
//
//  Created by Matt Baron on 6/19/18.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

@interface SGPaymentMethodBillingInfoFieldOption : SGPItem

@property (nonatomic, copy) NSString *value;
@property (nonatomic, copy) NSString *label;
@property (nonatomic, copy) NSString *shortLabel;

@end
