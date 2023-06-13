//
//  SGSeatOption.h
//  SeatGeek
//
//  Created by James Van-As on 1/06/18.
//  Copyright © 2018 SeatGeek. All rights reserved.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import "SGItem.h"
#endif

@class SGSeat;

@interface SGSeatOption : SGItem

@property (nonatomic, copy) NSString *formattedName;
@property (nonatomic, assign) BOOL isDefault;
@property (nonatomic, assign) BOOL isAisle;
@property (nonatomic, copy) NSArray<SGSeat *> *seats;

@property (nonatomic, readonly) NSString *title;

/**
 Denotes if we generated this object from local data or if we generated it from the server. We might create SeatOptions
 before we get a summary response, in that case this would be true.
 Defaults to false
 */
@property (nonatomic, assign) BOOL isClientGenerated;

/**
 This will return 2 seat options where on will have n (where n = quantity) seats starting from the front of the seats array.
 The other will have n (where n = quantity) seats starting from the end of the seats array.
 Both seat options will have isClientGenerated true
 */
+ (NSArray<SGSeatOption *> *)seatOptionsForQuantity:(NSInteger)quantity seats:(NSArray<SGSeat *> *)seats;

@end
