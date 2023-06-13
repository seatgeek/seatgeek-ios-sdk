//
//  SGUserIngestionStatus.h
//  Pods
//
//  Created by Steven Lehrburger on 11/20/15.
//
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

#define SGKUserIngestionStatusProcessing @"processing"
#define SGKUserIngestionStatusFailed     @"failed"
#define SGKUserIngestionStatusPurgatory  @"purgatory"
#define SGKUserIngestionStatusCondemned  @"condemned"
#define SGKUserIngestionStatusSuccess    @"success"


@interface SGUserIngestionStatus : SGItem

@property (nonatomic, copy) NSString *type;

- (NSString *)displayStatus;

@end
