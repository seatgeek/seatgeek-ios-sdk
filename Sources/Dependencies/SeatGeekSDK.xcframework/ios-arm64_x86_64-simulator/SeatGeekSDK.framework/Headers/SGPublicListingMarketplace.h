//
//  SGPublicListingMarketplace.h
//  Pods
//
//  Created by Matt Baron on 3/6/18.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

typedef NS_ENUM(NSInteger, SGPublicListingMarketplaceDisplayType) {
    SGPublicListingMarketplaceDisplayTypeRequired,
    SGPublicListingMarketplaceDisplayTypeOptional,
    SGPublicListingMarketplaceDisplayTypeNone,
    SGPublicListingMarketplaceDisplayTypeUnknown
};

@interface SGPublicListingMarketplace : SGPItem

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *shortName;
@property (nonatomic, readonly) SGPublicListingMarketplaceDisplayType displayType;
@property (nonatomic, readonly) BOOL isSeatGeekMarket;
@property (nonatomic, readonly) BOOL isSeatGeekMarketExcludingOpen;

@end
