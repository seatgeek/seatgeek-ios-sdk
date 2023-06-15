//
//  SGPayoutStatus.h
//  Pods
//
//  Created by Steven Lehrburger on 11/19/15.
//
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

#define SGKPayoutStatusPending @"pending"
#define SGKPayoutStatusIssued  @"issued"

@interface SGPayoutStatus : NSObject

+ (id)itemForString:(NSString *)string;

- (NSString *)type;
- (NSString *)displayStatus;

@end
