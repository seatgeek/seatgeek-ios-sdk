//
//  Created by matt on 3/05/13.
//

@import CoreLocation;

typedef NS_ENUM(NSUInteger, SGTrackerDeviceLocationLocationSource);

extern NSString *SGLocationDidUpdate;

typedef enum {
    SGLocationModeUnknown = 0, SGLocationModeCurrent = 1, SGLocationModeFixed = 2, SGLocationModeIPAddress = 3
} SGLocationMode;

@class SGPLocation;

@interface SGLocationCenter : NSObject <CLLocationManagerDelegate>

@property (nonatomic, class, readonly) SGLocationCenter *instance;

@property (nonatomic, strong, readonly) SGPLocation *currentLocation;
@property (nonatomic, readonly) SGTrackerDeviceLocationLocationSource currentLocationSource;
@property (nonatomic, strong, readonly) NSArray *previousLocations;

@property (nonatomic, strong) CLLocationManager *manager;
@property (nonatomic, assign) SGLocationMode mode;
@property (nonatomic, assign) CLLocationAccuracy locationAccuracy;

- (void)locationFromAddress:(NSArray *)addressComponents
                 completion:(CLGeocodeCompletionHandler)completion;

- (void)updateLocationToGPSAndSaveToAccount:(BOOL)saveToAccount;
- (void)updateLocationToGPS;
- (void)checkForGPSLocationChange;

- (void)setFixedLocation:(SGPLocation *)location saveToAccount:(BOOL)saveToAccount;
- (void)setFixedLocation:(SGPLocation *)location;
- (void)setFixedLocation:(SGPLocation *)location saveToAccount:(BOOL)saveToAccount source:(SGTrackerDeviceLocationLocationSource)source;
- (void)addPreviousLocation:(SGPLocation *)location;
- (void)setFixedLocationWithCoordinates:(CLLocationCoordinate2D)coordinates source:(SGTrackerDeviceLocationLocationSource)source;

- (BOOL)permissionUndetermined;
- (BOOL)permissionGranted;
- (BOOL)permissionDenied;
- (BOOL)noLocationAvailable;

@end
