//
//  Created by matt on 9/04/14.
//

#define SGUserEventsFetchingStarted     @"SGUserEventsFetchingStarted"
#define SGUserEventsFetchingFinished    @"SGUserEventsFetchingFinished"
#define SGUserEventsFetchingFailed      @"SGUserEventsFetchingFailed"
#define SGUserEventsLoaded       @"SGUserEventsLoaded"
#define SGUserEventsChanged      @"SGUserEventsChanged"
#define SGUserPerformersFetchingStarted     @"SGUserPerformersFetchingStarted"
#define SGUserPerformersFetchingFinished    @"SGUserPerformersFetchingFinished"
#define SGUserPerformersFetchingFailed      @"SGUserPerformersFetchingFailed"
#define SGUserPerformersLoaded   @"SGUserPerformersLoaded"
#define SGUserPerformersChanged  @"SGUserPerformersChanged"
#define SGUserVenuesFetchingStarted     @"SGUserVenuesFetchingStarted"
#define SGUserVenuesFetchingFinished    @"SGUserVenuesFetchingFinished"
#define SGUserVenuesFetchingFailed      @"SGUserVenuesFetchingFailed"
#define SGUserVenuesLoaded       @"SGUserVenuesLoaded"
#define SGUserVenuesChanged      @"SGUserVenuesChanged"

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGItemPrivate.h>
#else
#import <SeatGeekSDK/SGItemPrivate.h>
#endif

extern NSString *const SGUserTrackingUserPerformersChanged;
extern NSString *const SGUserTrackingUserPerformersFetchingFinished;
extern NSString *const SGUserTrackingUserPerformersFetchingFailed;
extern NSString *const SGUserTrackingUserEventsFetchingFinished;
extern NSString *const SGUserTrackingUserEventsFetchingFailed;
extern NSString *const SGUserTrackingUserVenuesFetchingFinished;
extern NSString *const SGUserTrackingUserVenuesFetchingFailed;

typedef NS_ENUM(NSUInteger, SGTrackerDeviceLocationLocationSource);
typedef NS_ENUM(NSUInteger, SGTrackerUserEventUIOrigin);
typedef NS_ENUM(NSUInteger, SGTrackerUserPerformerUIOrigin);
typedef NS_ENUM(NSUInteger, SGTrackerUserVenueUIOrigin);

@class SGUser, SGKEvent, SGPerformer, SGVenue, SGItem, SGPListMetadataItem;

@interface SGUserTracking : NSObject

@property (nonatomic, strong) NSMutableOrderedSet <SGPerformer *> *trackedPerformers;
@property (nonatomic, strong) NSMutableOrderedSet <SGKEvent *> *trackedEvents;
@property (nonatomic, strong) NSMutableOrderedSet <SGVenue *> *trackedVenues;

+ (instancetype)tracker;

- (void)fetchTrackedEvents;
- (void)fetchTrackedPerformers;
- (void)fetchTrackedVenues;

- (BOOL)fetchingEvents;
- (BOOL)fetchingPerformers;
- (BOOL)fetchingVenues;

- (BOOL)isTrackingEvent:(SGKEvent *)event;
- (BOOL)isTrackingEventWithID:(NSString *)eventID;

- (BOOL)isTrackingPerformer:(SGPerformer *)performer;
- (BOOL)isTrackingPerformerWithID:(NSString *)performerID;

- (BOOL)isTrackingVenue:(SGVenue *)venue;
- (BOOL)isTrackingVenueWithID:(NSString *)venueID;

- (BOOL)isTrackingItem:(SGItem *)item;

- (void)trackEvent:(SGKEvent *)event uiOrigin:(SGTrackerUserEventUIOrigin)uiOrigin;
- (void)trackEventWithID:(NSString *)eventID uiOrigin:(SGTrackerUserEventUIOrigin)uiOrigin;

- (void)trackPerformer:(SGPerformer *)performer uiOrigin:(SGTrackerUserPerformerUIOrigin)uiOrigin;
- (void)trackPerformerWithID:(NSString *)performerID uiOrigin:(SGTrackerUserPerformerUIOrigin)uiOrigin;

- (void)trackVenue:(SGVenue *)venue uiOrigin:(SGTrackerUserVenueUIOrigin)uiOrigin;
- (void)trackVenueWithID:(NSString *)venueID uiOrigin:(SGTrackerUserVenueUIOrigin)uiOrigin;

- (void)untrackEvent:(SGKEvent *)event uiOrigin:(SGTrackerUserEventUIOrigin)uiOrigin;
- (void)untrackEventWithID:(NSString *)eventID uiOrigin:(SGTrackerUserEventUIOrigin)uiOrigin;
- (void)untrackPerformer:(SGPerformer *)performer uiOrigin:(SGTrackerUserPerformerUIOrigin)uiOrigin;
- (void)untrackPerformerWithID:(NSString *)performerID uiOrigin:(SGTrackerUserPerformerUIOrigin)uiOrigin;
- (void)untrackVenue:(SGVenue *)venue uiOrigin:(SGTrackerUserVenueUIOrigin)uiOrigin;
- (void)untrackVenueWithID:(NSString *)venueID uiOrigin:(SGTrackerUserVenueUIOrigin)uiOrigin;

// TODO figure out how to use the interaction method enum for SGTracker instead of the BOOL
// even though we are in a Shared pod that needs to be compiled for targets that don't
// have the tracker-ios pod.
//
// Update: same for the browseListMetadata, which is for the ui_origin and other metadata.
// After this initial migration is done, we can design a better and more universal pattern
// for collecting the metadata upstream of the actual SGTracker call. - @lehrblogger
//
// Another update: same for isFromEventView. We want data about event view usage ASAP for
// the event page redesign, but the ugliness of this code shows the urgency of making time
// to implement a better approach... - @lehrblogger
- (void)trackEvent:(SGKEvent *)event listMetadata:(SGPListMetadataItem *)listMetadata uiOrigin:(SGTrackerUserEventUIOrigin)uiOrigin;
- (void)trackPerformer:(SGPerformer *)performer listMetadata:(SGPListMetadataItem *)listMetadata uiOrigin:(SGTrackerUserPerformerUIOrigin)uiOrigin;
- (void)trackVenue:(SGVenue *)venue listMetadata:(SGPListMetadataItem *)listMetadata uiOrigin:(SGTrackerUserVenueUIOrigin)uiOrigin;
- (void)untrackEvent:(SGKEvent *)event listMetadata:(SGPListMetadataItem *)listMetadata uiOrigin:(SGTrackerUserEventUIOrigin)uiOrigin;
- (void)untrackPerformer:(SGPerformer *)performer listMetadata:(SGPListMetadataItem *)listMetadata uiOrigin:(SGTrackerUserPerformerUIOrigin)uiOrigin;
- (void)untrackVenue:(SGVenue *)venue listMetadata:(SGPListMetadataItem *)listMetadata uiOrigin:(SGTrackerUserVenueUIOrigin)uiOrigin;
- (void)trackItem:(SGItem *)item listMetadata:(SGPListMetadataItem *)listMetadata uiOrigin:(int)uiOrigin;
- (void)untrackItem:(SGItem *)item listMetadata:(SGPListMetadataItem *)listMetadata uiOrigin:(int)uiOrigin;

@end
