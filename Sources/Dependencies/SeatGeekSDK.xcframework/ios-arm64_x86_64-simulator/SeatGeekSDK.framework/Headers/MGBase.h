//
//  Created by matt on 24/08/12.
//

#define CLAMP(x,low,high) (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/MGEvents.h>
#import <SeatGeekCore/UIView+MGEasyFrame.h>
#import <SeatGeekCore/UIResponder+FirstResponder.h>
#else
#import <SeatGeekSDK/MGEvents.h>
#import <SeatGeekSDK/UIView+MGEasyFrame.h>
#import <SeatGeekSDK/UIResponder+FirstResponder.h>
#endif
