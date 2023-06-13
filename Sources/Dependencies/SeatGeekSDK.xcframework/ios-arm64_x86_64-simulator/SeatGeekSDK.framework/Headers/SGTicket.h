//
//  Created by matt on 24/04/15.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGItem.h>
#else
#import <SeatGeekSDK/SGItem.h>
#endif

@class SGPEvent, SGTransfer, SGBarcode, SGPDF, SGScreenshot, SGAppleWalletPass, SGPublicListing, SGTicketGroup;

@interface SGTicket : SGItem

@property (nonatomic, copy) NSString *eventId;
@property (nonatomic, copy) NSString *rawSection;
@property (nonatomic, copy) NSString *section;
@property (nonatomic, copy) NSString *rawRow;
@property (nonatomic, copy) NSString *row;
@property (nonatomic, copy) NSString *seat;
@property (nonatomic, copy) NSString *notes;
@property (nonatomic, copy) NSString *owner;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, assign) BOOL owned;
@property (nonatomic, assign) BOOL transferable;
@property (nonatomic, assign) BOOL sellable;
@property (nonatomic, assign) BOOL obstructedView;
@property (nonatomic, assign) BOOL wheelchairAccessible;
@property (nonatomic, assign) BOOL generalAdmission;
@property (nonatomic, strong) SGBarcode *barcode;
@property (nonatomic, strong) SGPDF *PDF;
@property (nonatomic, strong) SGScreenshot *screenshot;
@property (nonatomic, strong) SGAppleWalletPass *appleWalletPass;
@property (nonatomic, copy) NSArray *currentOffers;           // currently array of NSDictionaries, but soon SGOffer objects or some such
@property (nonatomic, copy) NSArray <SGPublicListing *> *currentSales;
@property (nonatomic, strong) SGTransfer *currentTransfer;    // this is currently generated from the ticket group history
@property (nonatomic, strong) SGPublicListing *currentSale;   // this is currently generated from the ticket group history and modified by current_offers
@property (nonatomic, readonly) SGTicketGroup *ticketGroup;

@property (nonatomic, assign, readonly) BOOL pendingTransfer;
@property (nonatomic, readonly) BOOL isOnOffer;

/** Returns "1 ticket", "2 tickets" etc */
+ (NSString *)countTickets:(NSInteger)count;

/** Returns "ticket", "2 tickets" etc */
+ (NSString *)shorterCountTickets:(NSInteger)count;

- (BOOL)shouldShowAppleWallet;
- (BOOL)isViewable;
- (NSString *)cacheKeyToBeShown;

- (NSString *)seatString;
- (NSString *)rawSectionAndRawRowString;

@end
