//
//  SGConnectedService.h
//  SeatGeek
//
//  Created by David McNerney on 3/30/16.
//  Copyright © 2016 SeatGeek. All rights reserved.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

extern NSString * const SGConnectedServiceSpotify;
extern NSString * const SGConnectedServiceFacebook;
extern NSString * const SGConnectedServiceiTunes;

typedef enum SGConnectService {
    SGConnectFacebook,
    SGConnectiTunes,
    SGConnectSpotify,
    SGConnectUnknown
} SGConnectService;

/**
 * These objects represent the different services that we ingest
 * the user's musical tastes from, like Facebook, Spotify,
 * or their music library.
 */
@interface SGConnectedService : SGPItem

@property (nonatomic, copy) NSString *name;
- (NSString *)displayName;
@property (nonatomic, assign) BOOL isConnected;
@property (nonatomic, assign) NSUInteger importCount;

/// get the enum version of the service string
+ (SGConnectService)enumForService:(NSString *)service;
+ (NSString *)serviceNameForEnum:(SGConnectService)service;
+ (NSString *)displayNameForService:(NSString *)serviceName compact:(BOOL)compact;
- (SGConnectService)type;

@end
