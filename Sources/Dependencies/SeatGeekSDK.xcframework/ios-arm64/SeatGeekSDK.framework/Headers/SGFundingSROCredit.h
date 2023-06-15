//
//  SGFundingSROCredit.h
//  Pods
//
//  Created by Matt Baron on 7/24/18.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGFunding.h>
#else
#import <SeatGeekSDK/SGFunding.h>
#endif

@interface SGFundingSROCredit : SGFunding

@end
