//
//  Created by matt on 31/08/14.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGKEvent.h>
#import <SeatGeekCore/SGItemPrivate.h>
#import <SeatGeekCore/SGPhoneImageURLProviding.h>
#else
#import <SeatGeekSDK/SGKEvent.h>
#import <SeatGeekSDK/SGItemPrivate.h>
#import <SeatGeekSDK/SGPhoneImageURLProviding.h>
#endif

@class SGPPerformer, SGPVenue, SGPurchase, SGSocialRelationship, MKETAResponse, SGPromotion, SGAudioTrack;

// forward declaration of the enum to avoid importing mapkit
typedef NS_OPTIONS(NSUInteger, MKDirectionsTransportType);

@interface SGPEvent : SGKEvent <SGItemPrivate, SGPhoneImageURLProviding>

@property (nullable, nonatomic, strong) SGPVenue *pVenue;
@property (nullable, nonatomic, strong) SGPPerformer *pPrimaryPerformer;
@property (nullable, nonatomic, strong) NSDictionary *relatedEvents;
@property (nullable, nonatomic, readonly) NSArray <SGSocialRelationship *>* socialRelationships;
// A convenience getter for the name of the first taxonomy in the taxonomies array
@property (nullable, nonatomic, readonly) NSString *taxonomy;
@property (nonnull, nonatomic, copy) NSString *dataKeyPrefix;
@property (nullable, nonatomic, strong) SGPurchase *purchase;
@property (nonatomic, assign) BOOL mobileEntryEnabled;
/// Whether this event is an "add on" event (Taxonomy 4000000) - eg. a parking event.
@property (nonatomic, assign) BOOL isAddOnEvent;
@property (nonatomic, assign) BOOL accessCodeEnabled;
@property (nonatomic, assign) BOOL isSGO;
@property (nonatomic, assign) BOOL isParkingEvent;
@property (nonatomic, assign, readonly) BOOL isInBestAvailableMode;
@property (nonatomic, assign, readonly) BOOL showAllInPriceBeforeCheckout;

@property (nullable, nonatomic, copy) NSString *currencyCode;

/// Whether tracking is allowed for this event
@property (readonly) BOOL isTrackingEnabled;

@property (nullable, nonatomic, readonly) NSString *urlWithDeeplinkQueryParams;
@property (nullable, nonatomic, strong) NSDictionary *deeplinkQueryParams;

// This is declared as a separate property because `promotions` currently requires a separate fetch to retrieve.
@property (nonatomic, assign) BOOL hasPromotions;

@property (nonnull, nonatomic) NSArray<SGPromotion *> *promotions;

/// Returns a route string suitable for passing to SGURLRouter to take the user to view this event
- (nonnull NSString *)internalRoute;

#pragma mark - Hidden Events

/// Whether this event is a "hidden" event - only available from deep links or web urls
@property (readonly) BOOL isHiddenEvent;
/// An optional preview token associated with this event - used in hidden events, parsed from app routes / urls
@property (nullable, nonatomic) NSString *previewToken;

#pragma mark - Hybrid UI

/// Whether this event is a "hybrid" event for Event Screen 2.0
@property (readonly) BOOL isHybridUI;

#pragma mark - Images

- (nullable NSString *)imageURL;

#pragma mark - Prices

- (nullable NSNumber *)lowestPriceExcludingFees;
- (nullable NSNumber *)lowestPriceIncludingFees;

/// the lowest price in the event taking into account the all in pricing setting
@property (nullable, nonatomic, readonly) NSNumber *displayLowestPrice;

#pragma mark - Taxonomies

- (nonnull NSSet *)flattenedTaxonomies;
- (nullable NSString *)type;
- (BOOL)isSports;
- (BOOL)isFestival;
- (BOOL)isConcert;
- (BOOL)isComedy;
- (BOOL)isTheater;
- (BOOL)isBroadway;
- (BOOL)isGolf;

#pragma mark - Event Maps

- (BOOL)hasMap;
- (nullable NSString *)mapID;
- (nullable NSString *)retinaMapID;

#pragma mark - Concierge

- (BOOL)showConciergeModal;

#pragma mark - Date Time Helpers
/**
 * Returns true when the event is happening soon, so that
 * we know to make certain adjustments to prepare the screen
 * for barcode scanning, such as brightening the screen,
 * and disabling Apple Pay.
 */
- (BOOL)isTimeToEnter;
- (BOOL)isWithin24Hours;
/// If it makes sense to show a date on this event.  eg. if the event is next year + 8 months away
+ (BOOL)shouldShowYearForDate:(nonnull NSDate *)date;

/// Date/time strings of various length and verbosity. Most include the year if it is ambiguous.
/// Many places in the app need these, but it's easy to make mistakes using localDate directly,
/// so format them all here to ensure proper handling of years, as well as TBD dates and times.
- (nonnull NSString *)shortDateOnlyString:(BOOL)compact;  // "Wed, Apr 12", or just "Apr 12" when `compact` is true
- (nonnull NSString *)shortDateTimeString:(BOOL)compact;  // shortDateOnlyString followed by ", 13:05pm"
- (nonnull NSString *)mediumDateOnlyString; // "Wed, Apr 12" on both normal and thin phones
- (nonnull NSString *)mediumDateTimeString; // mediumDateTimeString followed by " at 13:05pm"
- (nonnull NSString *)mediumDateTimeStringWithYear:(BOOL)forceYear; // mediumDateTimeString with option to always show the year
- (nonnull NSString *)longDateTimeString;   // "Wednesday, April 12, 2007 at 13:05pm" on both normal and thin phones
+ (nonnull NSString *)timeStringForDate:(nonnull NSDate *)date;
+ (nonnull NSDateFormatter *)shortDateFormatterWithoutYear:(BOOL)compact;
+ (nonnull NSDateFormatter *)shortDateFormatterWithYear:(BOOL)compact;
+ (nonnull NSDateFormatter *)dayNameMonthDayNumberFormatter;

// A convenience getter for getting the local date in the format required by SGTracker
@property (nullable, nonatomic, readonly) NSString *localDateString;
@property (readonly) BOOL shouldBeConsideredFinished;

// Event A/B Test Date Time Formatting Functions
+ (nonnull NSString *)dayNameMonthDayNumberStringForEvent:(nonnull SGPEvent *)event;
+ (nonnull NSString *)dayNameMonthDayNumberStringForUTCDate:(nullable NSDate *)utcDate andLocalDate:(nullable NSDate *)localDate;
+ (nonnull NSString *)monthDayStringForDate:(nullable NSDate *)date;

@end
