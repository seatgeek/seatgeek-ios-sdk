//
//  Created by matt on 20/07/15.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

#define SGKTransferStatusPending  @"pending"
#define SGKTransferStatusAccepted @"accepted"
#define SGKTransferStatusCanceled @"canceled"
#define SGKTransferStatusDeclined @"declined"

@interface SGTransferStatus : SGItem

@property (nonatomic, strong) NSDate *utcDate;
@property (nonatomic, copy) NSString *type;

@end
