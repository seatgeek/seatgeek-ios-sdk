//
//  SGPaymentMethodBillingInfoField.h
//  Pods
//
//  Created by Matt Baron on 6/19/18.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#import <SeatGeekCore/SGAPICustomValidator.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#import <SeatGeekSDK/SGAPICustomValidator.h>
#endif

@class SGPaymentMethodBillingInfoFieldOption;

@interface SGPaymentMethodBillingInfoField : SGPItem

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *label;
@property (nonatomic, assign) BOOL required;
@property (nonatomic, strong) NSArray <SGPaymentMethodBillingInfoFieldOption *> *billingInfoFieldOptions;
@property (nonatomic, strong) NSArray <SGAPICustomValidator *> *customRegexValidators;

- (NSArray<SGPaymentMethodBillingInfoFieldOption *> *)filteredBillingInfoFieldOptionsByLabelForQuery:(NSString *)query;
- (SGPaymentMethodBillingInfoFieldOption *)matchingBillingInfoFieldOptionForQuery:(NSString *)query;

- (BOOL)supportsOptions;
@end
