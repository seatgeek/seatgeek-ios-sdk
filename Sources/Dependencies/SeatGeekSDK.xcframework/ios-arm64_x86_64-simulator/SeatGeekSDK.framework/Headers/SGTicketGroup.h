//
//  Created by matt on 9/07/15.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGItem.h>
#import <SeatGeekCore/MGBlockWrapper.h>
#else
#import <SeatGeekSDK/SGItem.h>
#import <SeatGeekSDK/MGBlockWrapper.h>
#endif

typedef NS_ENUM(NSInteger, SGTicketGroupEmptyStateType) {
    SGTicketGroupEmptyStateTypeHide,
    SGTicketGroupEmptyStateTypeFetching,
    SGTicketGroupEmptyStateTypeTimeline,
    SGTicketGroupEmptyStateTypeMessage,
};

typedef NS_ENUM(NSInteger, SGTicketGroupDisplayMethod) {
    SGTicketGroupDisplayMethodBarcode,
    SGTicketGroupDisplayMethodMobileOnly,
    SGTicketGroupDisplayMethodUnsupported,
    SGTicketGroupDisplayMethodPrintAtHome,
};

@class SGPEvent, SGPurchase, SGPDF, SGTicket, SGPublicListingMarketplace;

@interface SGTicketGroup : SGItem

@property (nonatomic, copy) NSString *section;
@property (nonatomic, copy) NSString *row;

@property (nonatomic, strong) NSNumber *totalQuantity;
@property (nonatomic, strong) NSNumber *ownershipQuantity;
@property (nonatomic, assign, readonly) NSInteger numberOfTicketsWithAppleWalletPasses;

@property (nonatomic, assign) BOOL generalAdmission;
@property (nonatomic, assign) BOOL electronic;
@property (nonatomic, assign) BOOL fulfillmentEnabled;
@property (nonatomic, assign, readonly) BOOL inAppDelivery;
@property (nonatomic, assign, readonly) SGTicketGroupDisplayMethod displayMethod;
@property (nonatomic, readonly) BOOL barcodesAreAvailable;
@property (nonatomic, assign) BOOL pending;

@property (nonatomic, strong) SGPEvent *event;
/// used for analytics purposes.  Uses event dict if present, otherwise extracts it from the embedded tickets
@property (nonatomic, strong, readonly) NSString *eventID;
@property (nonatomic, strong) SGPDF *PDF;
/// market places which are available for listing on
@property (nonatomic, strong) NSArray <SGPublicListingMarketplace *> *availablePublicListingMarketplaces;
/// market places which have been seen with this listing, enabled or not
@property (nonatomic, strong) NSArray <SGPublicListingMarketplace *> *allPublicListingMarketplaces;
@property (nonatomic, readonly) NSString *availablePublicListingMarketPlacesDescription;
@property (nonatomic, assign) BOOL showPartnerCodes;
@property (nonatomic, strong) NSArray <SGTicket *> *tickets;
@property (nonatomic, strong) NSArray *history;
@property (nonatomic, assign, readonly) BOOL fetchingAppleWalletPasses;


+ (NSString *)extractIDFromURL:(NSString *)url;

- (BOOL)allTicketsTransferredOrSold;
- (BOOL)areAnyTicketsPendingTransferOrOnOffer;
- (BOOL)shouldPreventPrinting;
- (NSArray <SGTicket *> *)onOfferTickets;
- (NSArray <SGTicket *> *)ownedTickets;
- (NSArray <SGTicket *> *)transferableTickets;
- (NSArray <SGTicket *> *)sellableTickets;
- (NSArray <SGTicket *> *)ticketsToDisplay;

// Public listing marketplaces helpers
- (NSArray <SGPublicListingMarketplace *> *)requiredPublicListingMarketplaces;
- (NSArray <NSString *> *)requiredPublicListingMarketplacesIDs;
- (SGPublicListingMarketplace *)publicListingMarketplaceForID:(NSString *)ID; // Note: this returns nil if no matching marketplace is found


// technically there *might* be more than one purchase object, but can deal with that
// later if needed.  Purchase can definitely be nil if it was transferred to you.
- (SGPurchase *)purchase;

- (BOOL)couldIncludePDF;
- (SGTicketGroupEmptyStateType)emptyStateType;
- (NSString *)displayStatus;
- (NSString *)sectionAndRowString;
- (NSString *)bodyForHelpEmail;

/// Returns a route string suitable for passing to SGURLRouter to take the user to view this ticket group.
- (NSString *)internalRoute;

/// Returns an array containing all the cache keys that make up the content of this ticket group.
/// This includes the ticket group, pdf, and barcode cache keys
- (NSArray *)allCacheKeys;

@end
