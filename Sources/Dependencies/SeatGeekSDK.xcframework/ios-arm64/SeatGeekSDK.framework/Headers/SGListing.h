//
//  Listing.h
//  SeatGeek
//
//  Created by Devin Ross on 10/11/12.
//  Copyright (c) 2012 Devin7 Software. All rights reserved.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import "SGItem.h"
#endif

@import UIKit;

typedef NS_ENUM(NSInteger, SGListingColor) {
    SGListingColorDeepGreen = 0,
    SGListingColorGreen = 1,
    SGListingColorGreenYellow = 2,
    SGListingColorYellow = 3,
    SGListingColorOrange = 4,
    SGListingColorOrangeRed = 5,
    SGListingColorRed = 6,
    SGListingColorBlue = 7
} NS_SWIFT_NAME(ListingColor);

@class SGPEvent, SGHTTPRequest, SGMarket, SGSeat, SGKReturnPolicyEligible, SGListingPackage, SGSeatInfo, SGKPrimaryListingsFilter;

@interface SGListing : SGItem

@property (nonatomic, strong) NSString *section;
@property (nonatomic, strong) NSString *row;
@property (nonatomic, strong) NSArray<SGSeat *> *seats;
@property (nonatomic, readonly) BOOL hasSeats;
@property (nonatomic, readonly) BOOL seatSelectionIsEnabled;

/// user friendly section, use if not nil
@property (nonatomic, strong) NSString *sectionFormatted;
/// user friendly row, use if not nil
@property (nonatomic, strong) NSString *rowFormatted;
@property (nonatomic, copy) NSString *mapKey;
@property (nonatomic, copy) NSString *verifiedPrimaryLogoURL;
@property (nonatomic, copy) NSString *brokerNotes;
@property (nonatomic, copy) NSString *seatgeekNotes;
@property (nonatomic, strong) NSString *stockType;
- (NSString *)combinedNotes;
- (BOOL)hasNotes;
@property (nonatomic, copy) NSNumber *brokerOrder;
@property (nonatomic, copy) NSString *groupingKey;
@property (nonatomic, strong) NSNumber *quantity;
/// display price will returm seatGeekBasePrice or priceFees depending on the AIP setting
@property (nonatomic, strong, readonly) NSNumber *displayPrice;
@property (nonatomic, strong) NSNumber *price;
@property (nonatomic, strong) NSNumber *priceFees;
@property (nonatomic, strong) NSNumber *displayFees;
@property (nonatomic, readonly) NSString *currencyCode;

/// Price with fees added and rounded for display from the API
@property (nonatomic, strong) NSNumber *serverDisplayPrice;
@property (nonatomic, strong) NSNumber *seatGeekBasePrice;
@property (nonatomic, strong) NSNumber *seatGeekFees;
/// SeatGeek base price rounded for display
@property (nonatomic, strong) NSNumber *seatGeekDisplayPrice;
@property (nonatomic, strong) NSNumber *sellerFees;
@property (nonatomic, strong) NSNumber *shipping;


/// An integer rounded deal quality (rounded api side)
@property (nonatomic, strong) NSNumber *dealQuality;

/// The deal quality to display to the user. This may be artificially adjusted and have a different value than `dealQuality`.
/// Note: this value is on a 0-10 scale, whereas `dealQuality` is on a 0-100 scale.
/// It may also be a string value without any numbers.
@property (nonatomic, strong) NSString *visibleDealQuality;

@property (nonatomic, assign) BOOL eticket;
@property (nonatomic, assign) BOOL promoCodeEligible;
@property (nonatomic, assign) BOOL verifiedPrimary;
@property (nonatomic, assign) BOOL pickupOnly;
@property (nonatomic, strong) NSNumber *bucket;
@property (nonatomic, strong) NSString *bucketLabel;

/// Expected value of the listing
@property (nonatomic, strong) NSNumber *expectedValue;

/// shipping and fees total assumes the current SeatGeek fee setting (20%)
@property (nonatomic, strong) NSNumber *shippingAndFees;
@property (nonatomic, copy) NSString *region;
@property (nonatomic, strong) NSArray <NSNumber *> *splits;
@property (nonatomic, assign) CGPoint location;

@property (nonatomic, strong) SGMarket *market;
@property (nonatomic, readonly) BOOL isSellerDirect;

@property (nonatomic, assign) BOOL ambiguousSectionWarning;
@property (nonatomic, assign) BOOL ambiguousRowWarning;

@property (nonatomic, strong) NSNumber *chosenQuantity;
@property (nonatomic, strong) NSNumber *defaultChosenQuantity;

@property (nonatomic, strong) SGPEvent *event;

@property (nonatomic, strong, readonly) NSDate *inHandDate;

@property (nonatomic, strong) SGListingPackage *package;

@property (nonatomic, readonly) NSString *mapIconImageName;
@property (nonatomic, readonly) NSString *mapSelectedIconImageName;
@property (nonatomic, readonly) UIColor *color;
@property (nonatomic, readonly) CGFloat mapIconRadius;

// Will be nil if the listing is ineligible for return
@property (nonatomic) NSInteger returnPolicyID;
@property (nonatomic, strong) SGKReturnPolicyEligible *returnPolicy;

// Seat Views
@property (nonatomic, readonly) BOOL hasSeatView;
@property (nonatomic, strong) NSString *smallSeatViewURL;
@property (nonatomic, strong) NSString *bigSeatViewURL;

@property (nonatomic, strong) SGSeatInfo *seatInfo;

@property (nonatomic, assign) BOOL showsDealScore;
@property (nonatomic, strong) SGKPrimaryListingsFilter *primaryListingFilter;

// Event Screen 2.0 Seat Details
@property (nonatomic, strong) NSArray<NSNumber *> *seatDetailIds;
@property (nonatomic, strong) NSArray<NSNumber *> *spatialCollectionIds;

@property (nonatomic, readonly) BOOL affirmEligible;

// TODO: - Factor these two out. The case of the string also defines using E-
- (NSString *)quantityString;   //showE = NO
- (NSString *)lowerQuantityString;  // showE = YES

// MARK: - Quantity string formats
// show e- format if applicable, quantity from listing
- (NSString *)quantityStringShowingE:(BOOL)showE;
- (NSString *)lowerQuantityStringShowingE:(BOOL)showE;

- (NSString *)quantityStringForQuantity:(int)quantity showE:(BOOL)showE;
- (NSString *)lowerQuantityStringForQuantity:(int)quantity showE:(BOOL)showE;

- (BOOL)hasDealScore;
- (BOOL)supportsApplePay;

- (BOOL)shouldShowDeliveryInfo;

- (BOOL)shouldShowDeliveryEstimate;

- (NSDictionary *)mapKeyDict;

- (NSString *)listingsTableSectionOrRowString:(BOOL)compact;
- (NSString *)sublistingsTableSectionOrRowString:(BOOL)compact;
- (NSString *)sectionAndRowString;
- (NSString *)newEventScreenListingDetailsSectionAndRowString;
- (NSString *)accessibleSectionAndRowString;

- (NSString *)remoteID;

+ (NSString *)prettyZoneName:(NSString *)raw;

+ (NSString *)titleForListingColor:(SGListingColor)color plural:(BOOL)plural;

+ (NSDictionary *)parseMapKey:(NSString *)mapKey;

@end
