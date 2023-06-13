//
//  SGPromoCode.h
//  Pods
//
//  Created by James Van-As on 01/03/17.
//
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

#define SGUpdateUserPromoCodesWithDict @"SGUpdateUserPromoCodesWithDict"
#define SGShowLegacyPromoCodeSuccessMessage @"SGShowLegacyPromoCodeSuccessMessage"

typedef NS_ENUM(NSInteger, SGPromoCodeDiscountType) {
    SGPromoCodeDiscountTypeDollar,
    SGPromoCodeDiscountTypePercent,
    SGPromoCodeDiscountTypeUnkown
};

// Referred to as Discount Codes by the API team
@interface SGPromoCode : SGPItem

// This is the user facing code, aka BOXOFFICE
@property (nonatomic, copy)   NSString *name;
// This is a token representation of the promo code, used when we don't want the user to know the name
@property (nonatomic, copy)   NSString *token;

@property (nonatomic, copy)   NSString *codeDescription;
@property (nonatomic, assign) BOOL usableInThisContext;
@property (nonatomic, copy)   NSString *unusableReason;
@property (nonatomic, strong) NSDate *expiryDate;
@property (nonatomic, readonly) SGPromoCodeDiscountType discountType;
@property (nonatomic, readonly) BOOL isActive;
@property (nonatomic, readonly) NSNumber *discount;

- (NSString *)discountAsString;

// Call this when you want to submit the promocode
// Use saveChangesThenDo if you care about hasChanged affecting if the request gets sent or not
- (void)redeemThenDo:(MGBlock)success onFail:(SGAPIFailBlock)fail;

@end
