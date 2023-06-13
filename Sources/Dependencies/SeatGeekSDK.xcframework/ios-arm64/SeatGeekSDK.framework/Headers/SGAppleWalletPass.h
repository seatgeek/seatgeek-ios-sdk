//
//  SGAppleWallet.h
//  Adjust
//
//  Created by Matt Baron on 10/16/17.
//

@import PassKit;

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGItem.h>
#else
#import <SeatGeekSDK/SGItem.h>
#endif

@interface SGAppleWalletPass : SGItem

@property (nullable, nonatomic, readonly, strong) PKPass *pkPass;
@property (nullable, nonatomic, readonly, strong) NSData *data;

@end
