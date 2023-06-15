//
//  SGIngestion.h
//  SeatGeek
//
//  Created by David McNerney on 11/27/15.
//  Copyright © 2015 SeatGeek. All rights reserved.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import "SGItem.h"
#endif

@class SGTicketGroup;


// Server statuses
extern NSString *SGIngestionServerStatusPending;
extern NSString *SGIngestionServerStatusProcessing;
extern NSString *SGIngestionServerStatusFailed;
extern NSString *SGIngestionServerStatusPurgatory;
extern NSString *SGIngestionServerStatusCondemned;
extern NSString *SGIngestionServerStatusSuccess;

// Client statuses
typedef NS_ENUM(NSInteger, SGIngestionClientStatus) {
    SGIngestionClientStatusUndefined = 0,
    SGIngestionClientStatusWaitingToUpload,
    SGIngestionClientStatusUploading,
    SGIngestionClientStatusOnServer
    // we don't have an upload failed client status currently; we just pop an alert and the ingestion vanishes
};


/**
 * Ingestions bring PDFs of tickets external to the SeatGeek system into SeatGeek.
 * SGIngestion objects represent ingestions in either of two phases:
 *    - pre-server: local PDF files on device, uniquely identified by their clientFile. clientStatus
 *                  is anything other than SGIngestionClientStatusOnServer, and there is
 *                  no serverStatus.
 *    - on server:  the ingestion is queued on SeatGeek's server and obtained from the
 *                  /ingestions endpoint. clientStatus is SGIngestionClientStatusOnServer.
 */
@interface SGIngestion : SGItem

#pragma mark - Initialization

/**
 * Creates an ingestion object based on a locally stored PDF file. SGIngestion objects created
 * in this way represent ingestions until they are accepted by the server, at which point
 * we get them from the server and construct with -itemForDict:.
 *
 * Client code is responsible for setting clientStatus appropriately.
 */
+ (instancetype)ingestionFromFile:(NSString *)file;

#pragma mark - SGItem properties

/**
 * The original filename of the PDF file; does not include path information.
 */
@property (nonatomic, copy) NSString *pdfFilename;

/**
 * Only defined for clientStatus == SGIngestionClientStatusOnServer
 */
@property (nonatomic, copy) NSString *serverStatus;

@property (nonatomic) NSDate *dateCreated;

@property (nonatomic) NSArray<SGTicketGroup *> *ticketGroups;

#pragma mark - Other properties

@property (nonatomic) SGIngestionClientStatus clientStatus;

- (BOOL)isOnServer;

/**
 * For clientStatus != SGIngestionClientStatusOnServer, the ingestion does not
 * exist on the server yet, but only as a local file. This property holds the path
 * to that file. It's also defined transiently after an ingestion is successfully
 * uploaded, so that client code can cross-reference the old ingestion object
 * with the new one returned from the server.
 */
@property (nonatomic, copy) NSString *clientFile;

/**
 * Defined transiently on server ingestions that result from uploads that we've done
 * in this session of the app
 */
@property (nonatomic) NSDate *timeUploadFinished;

#pragma mark - Helpers

/**
 * Comma-separated list of the ticket group IDs, or the empty string
 */
- (NSString *)ticketGroupIDs;

/**
 * Short one or two word summary of current status, taking into account client and server status both
 */
- (NSString *)statusShort;

/**
 * We have more detailed information for the users for some of our statuses, but not all, so sometimes
 * this method returns nil.
 */
- (NSString *)statusDetail:(BOOL)compact;

/**
 * True if uploading on client, or processing / purgatory on server. False if waiting
 * to upload on client or succeeded / failed on server
 */
- (BOOL)isInProgress;

/**
 * True for succeeded and failed ingestions both, whenever the ingestion has reached a terminal
 * state and can't progress more.
 */
- (BOOL)didComplete;

- (BOOL)didSucceed;

- (BOOL)didFail;

+ (NSString *)extractIDFromRoute:(NSString *)route;

@end
