//
//  SGPromotion.h
//  Pods
//
//  Created by Hunter Mask on 1/24/19.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

typedef NS_ENUM(NSUInteger, SGKPromotionType) {
    SGKPromotionTypeRegular,
    SGKPromotionTypePriceDrop
};

@interface SGPromotion : SGPItem

@property (nonatomic, readonly, nonnull) NSString *headline;
@property (nonatomic, readonly, nullable) NSString *additionalInfo;
@property (nonatomic, readonly, nullable) NSString *iconURL;
@property (nonatomic, readonly) BOOL fromEventResponse;
@property (nonatomic, readonly) SGKPromotionType promotionType;

+ (nonnull id)itemForDict:(nullable NSDictionary *)dict fromEventResponse:(BOOL)fromEventResponse;

@end
