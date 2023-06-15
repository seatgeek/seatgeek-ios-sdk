//
//  SGEligiblePayoutMethodType.h
//  SGAPIPrivate
//
//  Created by Hunter Mask on 3/18/19.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#import <SeatGeekCore/SGFunding.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#import <SeatGeekSDK/SGFunding.h>
#endif

@interface SGEligiblePayoutMethodType : SGPItem

@property (nonatomic, strong, nullable) NSString *summary;
@property (nonatomic, strong, nonnull) NSString *displayName;
@property (nonatomic, strong, nullable) NSString *imageURL;
@property (nonatomic) SGFundingType type;

@end
