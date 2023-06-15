
//
//  Copyright © 2023 SeatGeek. All rights reserved.
//

@class SGSDKTracker;
@protocol SGMParticleTracking;

@interface SDKTrackingProtocolWrapper : NSObject <SGMParticleTracking>
- (id)initWithClientID:(NSString *)clientID;
@property (nonatomic, strong) SGSDKTracker *sdkTracker;
@end
