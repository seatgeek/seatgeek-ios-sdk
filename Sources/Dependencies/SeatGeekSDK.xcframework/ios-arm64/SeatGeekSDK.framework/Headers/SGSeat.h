//
//  SGSeat.h
//  SeatGeek
//
//  Created by Matt Baron on 7/23/18.
//  Copyright © 2018 SeatGeek. All rights reserved.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import "SGItem.h"
#endif

@interface SGSeat : SGItem

@property (nonatomic, copy) NSString *name;
@end
