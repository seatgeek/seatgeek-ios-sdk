//
//  SGGetDirections.h
//  Pods
//
//  Created by James Van-As on 7/10/15.
//
//

@import Foundation;
@import MapKit;

@class SGAddress;

@interface SGDirections : NSObject

/// Get the ETA travel times for the given destination using MapKit.  This is relatively a cheap operation.
+ (void)getTravelTimesTo:(nullable SGAddress *)address
                location:(CLLocationCoordinate2D)location
              arrivingAt:(nullable NSDate *)arrivalDate
              completion:(void (^_Nonnull)(NSArray <MKETAResponse *> * _Nullable travelTimes, NSArray <NSError *> * _Nullable error))travelTimesReceived;

/// Get the route to the given destination using MapKit.  This is relatively a expensive operation.
+ (void)getRouteTo:(nullable SGAddress *)address
          location:(CLLocationCoordinate2D)location
        arrivingAt:(nullable NSDate *)arrivalDate
     transportType:(MKDirectionsTransportType)transportType
        completion:(void (^_Nonnull)(MKRoute * _Nullable route,                                     
                                     CLLocationCoordinate2D fixedLatLon,
                                     NSError * _Nullable error))routeReceived;

/// Ask the user if they'd like to get directions to the destination using their Directions app of choice
+ (void)getDirectionsTo:(nonnull NSString *)name
                address:(SGAddress * _Nullable)address
               location:(CLLocationCoordinate2D)location
            presentFrom:(UIViewController * _Nullable)presentFrom;

/// Ask the user if they'd like to get directions to the destination using their Directions app of choice
+ (void)getDirectionsTo:(nonnull NSString *)name
                address:(SGAddress * _Nullable)address
               location:(CLLocationCoordinate2D)location
          transportType:(MKDirectionsTransportType)transportType
            presentFrom:(UIViewController * _Nullable)presentFrom;

/// If true, directions location source is set to a random point nearby the destination target
@property (class, nonatomic, readonly) BOOL fakeLocationToNearby;

/// Returns the faked location given a destination. For use in conjunction with fakeLocationToNearby.
+ (CLLocationCoordinate2D)fakedNearbyLocationFor:(CLLocationCoordinate2D)destination;

@end
