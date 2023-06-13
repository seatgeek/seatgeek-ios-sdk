//
//  Created by matt on 9/04/14.
//

@class SGUser, SGConnectedService;

@interface SGUserConnections : NSObject

extern NSString *const SGUserConnectionsUserConnectingServiceStarted;
extern NSString *const SGUserConnectionsUserConnectingServiceFinished;

#pragma mark - Setup
@property (nonatomic, weak) SGUser *user;
/// Use SGUser -connector rather than this method
+ (instancetype)connectorForUser:(SGUser *)user;
- (void)setServicesArray:(NSArray *)servicesArray;

#pragma mark - Connected Services
- (SGConnectedService *)connectedServiceWithName:(NSString *)name;
/// Display name for the given service
- (NSString *)displayNameForService:(NSString *)serviceName compact:(BOOL)compact;
/// Toggle the connected service on or off, using confirmation prompt for disconnect
- (void)toggleConnectedService:(NSString *)serviceName compact:(BOOL)compact;
/// Whether the user can disconnect the given service (eg. can't disconnect FB)
- (BOOL)canDisconnectService:(NSString *)serviceName;
/// Connect the user account to the service.  May trigger a prompt (last.fm)
- (void)connectToService:(NSString *)serviceName;
/// Whether the user account is in the connected to the service
- (BOOL)connectedToService:(NSString *)serviceName;
/// Whether the user account is in the process of connecting to the service
- (BOOL)connectingToService:(NSString *)serviceName;
/// Ask user to confirm if they want to disconnect before disconnecting
- (void)disconnectServiceWithPrompt:(NSString *)serviceName compact:(BOOL)compact;
/// Disconnect the service without asking the user
- (void)disconnectService:(NSString *)serviceName;
/// The service is in the process of disconnecting
- (BOOL)disconnectingService:(NSString *)serviceName;

/// User is connected to every available service
- (BOOL)connectedToAllServices;
/// User is connecting to at least one service
- (BOOL)connectingToAService;
/// User is connected to at least one service
- (BOOL)connectedToAService;

#pragma mark - Spotify Specific

/**
 * Sends the user to the Spotify auth page in Safari. After they log in, they'll be
 * redirected back to the SeatGeek app, and the app delegate will call our
 * +handleAuthenticationCallbackWithURL: method below.
 */

- (BOOL)isSpotifyAuthenticationCallbackURL:(NSURL *)url;
- (void)handleSpotifyAuthenticationCallbackWithURL:(NSURL *)url;

#pragma mark - iTunes Specific
- (void)ingestiTunes:(NSMutableArray *)performers thenDo:(void(^)(void))completion;

#pragma mark - Legacy API

- (void)connectToFacebook;
- (void)connectToiTunes;
- (void)connectToSpotify;

- (BOOL)connectedToFacebook;
- (BOOL)connectedToiTunes;
- (BOOL)connectedToSpotify;             /// not set until SGUser -fetchConnectServices completes sometime after login succeeds

@property (nonatomic, assign) BOOL connectingToFacebook;
@property (nonatomic, assign) BOOL connectingToiTunes;
@property (nonatomic, assign) BOOL connectingToSpotify;

// YES when the user is about to jump out to an external app to perform Spotify auth.
// This is different from `connectingToSpotify` as it does not include the post-authorization ingestion we perform.
@property (nonatomic, assign) BOOL authorizingWithSpotify;

- (void)disconnectiTunes;
- (void)disconnectSpotify;
- (void)disconnectFacebook;

@end
