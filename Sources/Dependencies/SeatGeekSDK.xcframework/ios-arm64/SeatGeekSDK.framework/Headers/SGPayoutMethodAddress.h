//
//  SGPayoutMethodAddress.h
//  Pods
//
//  Created by James Van-As on 19/10/15.
//
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGAddress.h>
#else
#import <SeatGeekSDK/SGAddress.h>
#endif

@interface SGPayoutMethodAddress : SGAddress

- (NSDictionary *)payload;  // used for sending to the server
@end
