//
//  Created by matt on 9/06/14.
//


#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/NSObject+MGEvents.h>
#import <SeatGeekCore/UIControl+MGEvents.h>
#else
#import <SeatGeekSDK/NSObject+MGEvents.h>
#import <SeatGeekSDK/UIControl+MGEvents.h>
#endif
