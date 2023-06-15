//
//  SGPurchaseTimelineEntry.h
//  Pods
//
//  Created by Steven Lehrburger on 10/24/16.
//
//

@import Foundation;

typedef NS_ENUM(NSUInteger, SGKPurchaseTimelineEntryStatusMood) {
    SGKPurchaseTimelineEntryStatusMoodBad,
    SGKPurchaseTimelineEntryStatusMoodGood,
    SGKPurchaseTimelineEntryStatusMoodPending,
    SGKPurchaseTimelineEntryStatusMoodUnknown  // client-side catch all for status moods we don't recognize
};

typedef enum SGKPurchaseTimelineEntryStatus {
    SGKPurchaseTimelineEntryStatusPending,
    SGKPurchaseTimelineEntryStatusConfirmed,
    SGKPurchaseTimelineEntryStatusFulfilled,
    SGKPurchaseTimelineEntryStatusRejected,
    SGKPurchaseTimelineEntryStatusUnsupported,
    SGKPurchaseTimelineEntryStatusUnknown  // client-side catch all for statuses we don't recognize
} SGKPurchaseTimelineEntryStatus;

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

@interface SGPurchaseTimelineEntry : SGItem

@property (nonatomic, readonly, assign) BOOL isSpeculative;
@property (nonatomic, readonly, assign) SGKPurchaseTimelineEntryStatusMood statusMood;
@property (nonatomic, readonly, assign) SGKPurchaseTimelineEntryStatus status;
@property (nonatomic, readonly, copy) NSString *relativeTime;
@property (nonatomic, readonly, copy) NSString *displayTitle;
@property (nonatomic, readonly, copy) NSString *displayMessage;

@end
