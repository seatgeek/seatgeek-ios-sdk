//
//  SGPriceType.h
//  SeatGeek
//
//  Created by Steven Diaz on 2/15/19.
//  Copyright © 2019 SeatGeek. All rights reserved.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import "SGItem.h"
#endif

typedef NS_ENUM(NSInteger, SGPriceTypePackageType) {
    SGPriceTypePackageTypeUnknown,
    SGPriceTypePackageTypeVIP,
    SGPriceTypePackageTypeBundle,
    SGPriceTypePackageTypePrime
};

@interface SGPriceType : SGItem <NSCopying>

@property (nonatomic, retain) NSString *typeName;
@property (nonatomic, retain) NSString *typeDescription;
@property (nonatomic, retain) NSNumber *price;
@property (nonatomic, retain) NSNumber *quantity;
@property (nonatomic, retain) NSNumber *fees;
@property (nonatomic) BOOL isDefault;
@property (nonatomic) SGPriceTypePackageType packageType;

@end
