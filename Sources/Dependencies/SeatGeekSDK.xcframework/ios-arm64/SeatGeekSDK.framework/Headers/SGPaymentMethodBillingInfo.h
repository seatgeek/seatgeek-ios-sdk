//
//  SGPaymentMethodBillingInfo.h
//  Pods
//
//  Created by Matt Baron on 6/19/18.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

@class SGPaymentMethodBillingInfoField;

@interface SGPaymentMethodBillingInfo : SGPItem

@property (nonatomic, strong) NSArray <SGPaymentMethodBillingInfoField *> *billingInfoFields;
@property (nonatomic, copy) NSString *country;
@property (nonatomic, copy) NSString *countryLabel;
@property (nonatomic, copy) NSString *streetAddress1Label; // The placeholder for the street address field

- (void)fetchBillingInfoForCountry:(NSString *)countryCode
                           eventId:(NSNumber *)eventId
                            thenDo:(MGBlock)success
                            onFail:(SGAPIFailBlock)fail;
@end
