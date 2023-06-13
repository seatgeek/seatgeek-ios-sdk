//
//  SGThirdPartyFulfillmentStatus.h
//  Pods
//
//  Created by Steven Lehrburger on 12/29/15.
//
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

#define SGKThirdPartyFulfillmentStatusPending     @"pending"
#define SGKThirdPartyFulfillmentStatusConfirmed   @"confirmed"
#define SGKThirdPartyFulfillmentStatusRejected    @"rejected"
#define SGKThirdPartyFulfillmentStatusFulfilled   @"fulfilled"
#define SGKThirdPartyFulfillmentStatusException   @"exception"
#define SGKThirdPartyFulfillmentStatusUnsupported @"unsupported"


@interface SGThirdPartyFulfillmentStatus : SGItem

@property (nonatomic, strong) NSString *type;

- (NSString *)displayStatus;

@end
