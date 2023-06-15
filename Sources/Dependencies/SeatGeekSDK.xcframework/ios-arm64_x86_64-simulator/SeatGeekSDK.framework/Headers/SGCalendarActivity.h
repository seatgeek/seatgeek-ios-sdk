//
//  Created by matt on 17/01/13.
//
@import UIKit;
#import <CoreLocation/CoreLocation.h>

@class SGKEvent, EKEvent, EKEventStore;

@interface SGCalendarActivity : UIActivity

typedef NS_ENUM(NSInteger, SGCalendarError) {
    SGCalendarErrorAccessDenied,
    SGCalendarErrorAddFailed
};

/// Add an event to the iOS calendar
+ (void)addEvent:(nonnull SGKEvent *)event
toCalendarWithSuccess:(nullable void(^)(EKEvent * _Nullable calEvent, EKEventStore * _Nullable store))successBlock
         failure:(nullable void(^)(SGCalendarError calendarError, NSError *_Nullable error))failureBlock;

/// Add an event to the iOS calendar

+ (void)addEventWithTitle:(nonnull NSString *)eventTitle
                venueName:(nullable NSString *)venueName
     venueDisplayLocation:(nullable NSString *)venueDisplayLocation
             startDateUTC:(nonnull NSDate *)startDateUTC
               endDateUTC:(nullable NSDate *)endDateUTC
             eventTimeTBD:(BOOL)eventTimeTBD
            venueLocation:(CLLocationCoordinate2D)venueLocation
    toCalendarWithSuccess:(nullable void(^)(EKEvent * _Nullable calEvent, EKEventStore * _Nullable store))successBlock
                  failure:(nullable void(^)(SGCalendarError calendarError, NSError *_Nullable error))failureBlock;

@end
