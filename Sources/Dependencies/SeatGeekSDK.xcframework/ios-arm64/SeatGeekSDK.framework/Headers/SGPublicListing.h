//
//  Created by james on 11/11/15.
//

@import UIKit;

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGAPIError.h>
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGAPIError.h>
#import <SeatGeekSDK/SGPItem.h>
#endif

typedef NS_ENUM(NSUInteger, SGTrackerSellCreateUIOrigin);

typedef NS_ENUM(NSInteger, SGPublicListingPricePerTicketType) {
    SGPublicListingPricePerTicketTypeNotAvailable, // this is the default value and meant to be overridden by the API
    SGPublicListingPricePerTicketTypeSellingPrice,
    SGPublicListingPricePerTicketTypePayoutAmount,
    SGPublicListingPricePerTicketTypeBasePrice,
};

typedef NS_ENUM(NSInteger, SGPublicListingPayoutMethodStatus) {
    SGPublicListingPayoutMethodStatusNotAvailable, // This mean the api didnt return us a status for w/e reason or returned a status we don't support
    SGPublicListingPayoutMethodStatusNone,
    SGPublicListingPayoutMethodStatusOk,
};

#define SGPublicListingStateChangeBegan @"SGPublicListingStateChangeBegan"
#define SGPublicListingStateChangeEnded @"SGPublicListingStateChangeEnded"
#define SGPublicListingSucceeded @"SGPublicListingSucceeded"

@class SGTicketGroup, SGPEvent, SGTicket;
@class SGAPIError, SGPayoutMethod, SGPurchaseLineItem, SGListingSplit, SGPublicListingMarketplace, SGEligiblePayoutMethodType;

@interface SGPublicListing : SGPItem

@property (nonatomic, assign) BOOL hasPreListingInfo;
@property (nonatomic, assign) BOOL recoupmentEnabled;
@property (nonatomic, assign, readonly) BOOL isUsingRecommendedPrice;
@property (nonatomic, readonly) BOOL isActive;

/// Is this listing currently on offer on the SeatGeek Marketplace
@property (nonatomic, readonly) BOOL onOfferOnSeatGeekMarketplace;

/// Returns false if SG marketplace isn't enabled for this listing at all
@property (nonatomic, readonly) BOOL canListOnSeatGeekMarketplace;
@property (nonatomic, readonly) BOOL canListOnSeatGeekMarketplaceExcludingOpen;

@property (nonatomic, strong, readonly) NSString *status;
@property (nonatomic, strong, readonly) UIColor *statusColor;
@property (nonatomic, strong) NSNumber *minQuantity;
@property (nonatomic, strong) NSNumber *maxQuantity;
@property (nonatomic, strong) NSNumber *quantity;
@property (nonatomic, strong) NSNumber *maxPricePerTicket;
@property (nonatomic, strong) NSNumber *priceRecommendation;
@property (nonatomic, strong) NSNumber *pricePerTicket;
@property (nonatomic, strong) NSNumber *pricePaidPerTicket;
@property (nonatomic, strong) NSNumber *total;
@property (nonatomic, strong) NSNumber *feePercentage;
@property (nonatomic, strong) NSDate *createdAt;
@property (nonatomic, strong) NSString *currencyCode;
@property (nonatomic, readonly) SGTicketGroup *ticketGroup;
@property (nonatomic, weak) SGTicketGroup *weakTicketGroup;
@property (nonatomic, strong) SGTicketGroup *strongTicketGroup;
@property (nonatomic, strong) NSArray <SGAPIError *> *errors;
@property (nonatomic, strong) SGPayoutMethod *payoutMethod;
@property (nonatomic, strong) NSArray <SGPurchaseLineItem *> *lineItems;
@property (nonatomic, strong) NSArray <SGListingSplit *> *splitOptions;
@property (nonatomic, strong) SGListingSplit *splitOption;
@property (nonatomic, strong) NSArray <NSNumber *> *availableSplits;
@property (nonatomic) BOOL seatSelectionEnabled;
@property (nonatomic, strong) NSString *seatSelectionMessage;
@property (nonatomic, strong) NSString *listingDescriptionHeaderText;
@property (nonatomic, strong) NSString *listingDescriptionExplanationText;
/// The marketplaces which this listing is currently on
@property (nonatomic) NSArray <NSString *> *currentlyListedMarketplaceIDs;
/// The marketplaces which are available for this listing, but not currently on
@property (nonatomic) NSArray <SGPublicListingMarketplace *> *nonListedMarketplaces;
@property (nonatomic, readonly) NSArray <SGPublicListingMarketplace *> *currentlyListedMarketplaces;
@property (nonatomic, assign) SGPublicListingPricePerTicketType pricePerTicketType;
@property (nonatomic) NSString *payoutAdvisory;

@property (nonatomic) NSArray<SGPayoutMethod *> *availablePayoutMethods;

@property (nonatomic) NSArray<SGEligiblePayoutMethodType *> *eligiblePayoutMethodTypes;

- (BOOL)hasEligiblePreconfiguredPayoutMethods;

// NSArray <NSArray <SGTicket>>
@property (nonatomic, strong) NSArray <NSArray *> *availableSeatSelections;

@property (nonatomic, readonly) SGPublicListingPayoutMethodStatus payoutMethodStatus;
@property (nonatomic, strong, readonly) NSString *payoutMethodStatusMessage;
@property (nonatomic, strong, readonly) NSString *payoutMethodDisplayName;

+ (instancetype)listingWithTicketGroup:(SGTicketGroup *)group;
+ (instancetype)listingWithID:(NSString *)ID;

- (void)fetchPrelistingInfo:(void(^)(void))success onFail:(SGAPIFailBlock)fail;
- (void)submitWithTickets:(NSArray <SGTicket *>*)tickets
                 uiOrigin:(SGTrackerSellCreateUIOrigin)uiOrigin
                     then:(void(^)(void))success onFail:(SGAPIFailBlock)fail;
- (void)submitPriceChangeThen:(void(^)(void))success onFail:(SGAPIFailBlock)fail;
- (void)cancelThen:(void(^)(void))success onFail:(SGAPIFailBlock)fail;
- (void)listOnMarketplaces:(NSArray <SGPublicListingMarketplace *> *)marketplaces
                  uiOrigin:(SGTrackerSellCreateUIOrigin)uiOrigin
                      then:(void(^)(void))success onFail:(SGAPIFailBlock)fail;
- (void)delistFromMarketplaces:(NSArray <SGPublicListingMarketplace *> *)marketplaces
                      uiOrigin:(SGTrackerSellCreateUIOrigin)uiOrigin
                          then:(void(^)(void))success
                        onFail:(SGAPIFailBlock)fail;

- (NSArray *)errorsForCategory:(NSString *)errorCategory;
- (NSString *)readableMarketplacesDescription;
/// For use in partner strings - eg. NFL partners
- (NSString *)readableMarketplacePartnersDescription;
- (NSString *)readableDescriptionWithPronoun:(BOOL)usePronoun;
- (NSString *)readableDescriptionWithPronoun:(BOOL)usePronoun forceCurrency:(BOOL)useCurrency;
- (NSString *)subjectForHelpEmail;
- (NSString *)bodyForHelpEmail;

@end


