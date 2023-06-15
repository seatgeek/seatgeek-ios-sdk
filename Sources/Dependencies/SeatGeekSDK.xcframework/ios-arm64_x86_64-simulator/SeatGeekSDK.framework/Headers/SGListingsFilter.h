//
//  Created by matt on 15/02/13.
//

@import Foundation;

extern NSString *SGListingFiltersDidChange;
extern NSString *SGListingFiltersWithPillsDidChange;
extern NSString *SGListingFiltersPackageWasToggled;
extern NSString *SGListingFiltersShouldSuppressUpdateToMatchFilters;

typedef NS_ENUM(NSUInteger, SGListingsFilterType) {
    SGListingsFilterTypePriceRange, SGListingsFilterTypeQuantity, SGListingsFilterTypePackages, SGListingsFilterTypePrimeSeats, SGListingsFilterTypeVIP, SGListingsFilterTypeAccessCode, SGListingsFilterTypePromoCode, SGListingsFilterTypeLowPrices, SGListingsFilterTypeBestSeats, SGListingsFilterTypeOffers, SGListingsFilterTypeAccessibility, SGListingsFilterTypeResale, SGListingsFilterTypeSpatialCollection, SGListingsFilterTypeBundles, SGListingsFilterTypeAccessibleSeatTypes, SGListingsFilterTypePromoCodesOnly, SGListingsFilterTypeExcludeLimitedView,
};

#define SGNumberOfTicketsChanged @"SGNumberOfTicketsChanged"
#define SGDefaultIncludeFeesChanged @"SGDefaultIncludeFeesChanged"
#define SGDefaultListingSortOrderChanged @"SGDefaultListingSortOrderChanged"

typedef NS_ENUM(NSUInteger, SGListingSort) {
    SGListingSortDealQuality = 0, SGListingSortPrice = 1, SGListingSortBestSeats = 2
};

typedef NS_ENUM(NSUInteger, SGListingSellerType) {
    SGListingSellerTypeAll = 0, SGListingSellerTypePrimary = 1, SGListingSellerTypeSecondary = 2
};

@class SGAccessCode;

@interface SGListingsFilter : NSObject

+ (void)resetAdaFilters;
+ (void)resetAllFilters;
+ (void)resetPriceBounds;
+ (void)resetFiltersExceptAdaFilter;
+ (void)resetFiltersExceptNumberOfTicketsAndAdaFilter;
+ (void)resetFiltersAndCachePreviousNumberOfTickets;

+ (SGListingSort)sortOrder;
+ (void)setSortOrder:(SGListingSort)order;
+ (BOOL)promoCodesOnly;
+ (BOOL)eTicketsOnly;
+ (BOOL)bestSeats;
+ (BOOL)lowPrices;
+ (BOOL)includeAccessibleWithNonAccessibleListings;

+ (BOOL)canSetSortOrderAsDefault:(SGListingSort)order;

+ (BOOL)hasAppliedFilters;
+ (BOOL)hasAppliedFilter:(SGListingsFilterType)type;
+ (void)setHasAppliedFilters:(SGListingsFilterType)type applied:(BOOL)applied;

// Related to Quantity Selection
+ (int)numberOfTickets;
+ (BOOL)hasCachedNumberOfTickets;
+ (void)resetToCachedNumberOfTickets;
+ (BOOL)shouldUpdateQuantityFilter;
+ (void)setShouldUpdateQuantityFilter:(BOOL)shouldUpdateQuantityFilter;

+ (BOOL)includeFeesInPrice;
+ (BOOL)defaultIncludeFeesInPrice;
+ (BOOL)hasSetIncludeFeesInPriceFilter;
+ (SGAccessCode *)accessCode;

+ (SGListingSort)defaultSortOrder;
+ (void)setDefaultSortOrder:(SGListingSort)order;
+ (BOOL)hasSetDefaultSortOrder;
+ (void)setPromoCodesOnly:(BOOL)promoCodesOnly;
+ (void)setETicketsOnly:(BOOL)eTicketsOnly;
+ (void)setBestSeats:(BOOL)bestSeats;
+ (void)setLowPrices:(BOOL)lowPrices;
+ (void)setNumberOfTickets:(int)tickets;

+ (int)lowerPriceThreshold;
+ (int)lowerPriceThresholdExcludingFees;
+ (int)priceThreshold;
+ (int)priceThresholdExcludingFees;
+ (BOOL)hasSetPriceThreshold;
+ (BOOL)hasSetPriceThresholdExcludingFees;
+ (int)lowerBestSeatsThreshold;
+ (int)upperBestSeatsThreshold;

+ (void)setLowerPriceThreshold:(int)price;
+ (void)setLowerPriceThresholdExcludingFees:(int)price;
+ (void)setPriceThreshold:(int)price;
+ (void)setPriceThresholdExcludingFees:(int)price;
+ (void)setLowerBestSeatsThreshold:(int)price;
+ (void)setUpperBestSeatsThreshold:(int)price;

+ (void)setIncludeFeesInPrice:(BOOL)include;
+ (void)setDefaultIncludeFeesInPrice:(BOOL)include;
+ (void)setAccessCode:(SGAccessCode *)accessCode;
+ (BOOL)hasSetSellerType;
+ (SGListingSellerType)sellerType;
+ (void)setSellerType:(SGListingSellerType)sellerType;
// ADA
+ (NSArray <NSString *> *)accessibilitySeatTypes;
+ (void)setAccessibilitySeatTypes:(NSArray <NSString *> *)accessibilitySeatTypes;
+ (BOOL)excludeLimitedView;
+ (void)setExcludeLimitedView:(BOOL)excludeLimitedView;
+ (void)setIncludeAccessibleWithNonAccessibleListings:(BOOL)includeAccessibleWithNonAccessibleListings;
// Spatial Collections
@property (class, nonatomic, readonly, copy) NSSet <NSNumber *> *spatialCollectionTypes;
+ (void)addSpatialCollectionType:(NSNumber *)spatialCollection;
+ (void)removeSpatialCollectionType:(NSNumber *)spatialCollection;
+ (BOOL)hasAppliedSpatialCollectionType: (NSNumber *)spatialCollection;
+ (void)clearAllSpatialCollectionTypes;
@end
