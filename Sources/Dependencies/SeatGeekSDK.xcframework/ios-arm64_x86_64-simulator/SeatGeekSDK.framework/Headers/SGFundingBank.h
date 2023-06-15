//
//  SGFundingBank.h
//  Pods
//
//  Created by James Van-As on 19/10/15.
//
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGFunding.h>
#else
#import <SeatGeekSDK/SGFunding.h>
#endif

@interface SGFundingBank : SGFunding
@property (nonatomic, strong) NSString *accountNumber;
@property (nonatomic, strong) NSString *routingNumber;
@property (nonatomic, strong) NSString *transitNumber;
@property (nonatomic, strong) NSString *institutionNumber;
@property (nonatomic, strong) NSString *accountNumberLast4Digits;
@end
