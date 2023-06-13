//
//  Created by matt on 28/05/14.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGQuery.h>
#else
#import <SeatGeekSDK/SGQuery.h>
#endif

#define SGAPI_STAGING_BASEDOMAIN @"tixcast.com"
#define SGAPI_PERF_BASEDOMAIN @"service.seatgeek.perf"
#define SGAPI_PERF_BASEFORMAT @"http://api.%@"

#define SGShowStagingAPIWarning @"SGShowStagingAPIWarning"

typedef enum {
    SGQueryTicketGroupTimeframePast,
    SGQueryTicketGroupTimeframeUpcoming
} SGQueryTicketGroupTimeframe;

typedef NS_OPTIONS(NSUInteger, SGAutosuggestType) {
    SGAutosuggestTypeEvent                = 1 << 0,
    SGAutosuggestTypePerformer            = 1 << 1,
    SGAutosuggestTypePerformerPass        = 1 << 2,
    SGAutosuggestTypeVenue                = 1 << 3,
    SGAutosuggestTypeVenuePass            = 1 << 4,
    SGAutosuggestTypeAutocompleteLocation = 1 << 5,
    SGAutosuggestTypePage                 = 1 << 6,
    SGAutosuggestTypeTaxonomy             = 1 << 7,
    SGAutosuggestTypeGenre                = 1 << 8,
    SGAutosuggestTypeList                 = 1 << 9,
} NS_SWIFT_NAME(AutosuggestType);

@class SGPEvent, SGTicketGroup, SGVenueConfig, SGAccessCode, SGPrompt, SGPPerformer, SGPaymentMethod;

typedef NS_ENUM(NSUInteger, SGTrackerDeviceLocationLocationSource);

@interface SGQuery (Private)
// authedQueryWithPath will authorize with the current logged in user
+ (nonnull SGQuery *)authedQueryWithPath:(nonnull NSString *)path;

// note: this will keep all query params
+ (nonnull SGQuery *)queryWithFullUrl:(nonnull NSString *)url;

#pragma mark - Recommendations/Performers

+ (nonnull SGQuery *)recommendedPerformersQueryForPerformerId:(nonnull id)performerId
                                              perPage:(NSUInteger)perPage;
+ (nonnull SGQuery *)recommendedPerformersQuery;
+ (nonnull SGQuery *)sectionsQueryForPerformerId:(nonnull NSString *)performerId;

#pragma mark - Search

+ (nonnull SGQuery *)autocompleteQueryForSearch:(nonnull NSString *)search
                                  types:(SGAutosuggestType)types
                           wasUserInput:(BOOL)wasUserInput;
+ (nonnull SGQuery *)autosuggestQueryForSearch:(nonnull NSString *)search
                                  types:(SGAutosuggestType)types
                           wasUserInput:(BOOL)wasUserInput;
+ (nonnull SGQuery *)locationsQueryForSearch:(nullable NSString *)search perPage:(NSUInteger)perPage;
+ (nonnull SGQuery *)autosuggestLocationsQueryForSearch:(nullable NSString *)search perPage:(NSUInteger)perPage;
+ (nonnull SGQuery *)otherUsersQueryForSearch:(nullable NSString *)search;

#pragma mark - Events and Listings
+ (nonnull SGQuery *)venueConfigQueryForEvent:(nonnull SGPEvent *)event;
+ (nonnull SGQuery *)listingsQueryForEvent:(nonnull SGPEvent *)event;
+ (nonnull SGQuery *)listingsV2QueryForEvent:(nonnull SGPEvent *)event;
+ (nonnull SGQuery *)seatGeekDirectMarketsQuery;
+ (nonnull SGQuery *)accessCodeValidationQueryForCode:(nonnull SGAccessCode *)accessCode;
+ (nonnull SGQuery *)codeValidationQuery;
+ (nonnull SGQuery *)emptyCartQueryForCartID:(nonnull NSString *)cartID;
+ (nonnull SGQuery *)billingInfoQueryForCountryCode:(NSString *_Nullable)countryCode eventId:(NSNumber *_Nullable)eventId;
+ (nonnull SGQuery *)promotionsQueryForEvent:(nonnull SGPEvent *)event;

#pragma mark - Ticket Groups

+ (nonnull SGQuery *)listingInfoQueryForTicketGroup:(nonnull SGTicketGroup *)ticketGroup;
+ (nonnull SGQuery *)ticketGroupsQueryForTimeframe:(SGQueryTicketGroupTimeframe)timeframe;
+ (nonnull SGQuery *)transferInfoQueryForTicketGroup:(nonnull SGTicketGroup *)ticketGroup;

+ (nonnull SGQuery *)cancelTransferQuery:(nonnull NSString *)transferID;

#pragma mark - Prompts

+ (nonnull SGQuery *)dismissPromptQueryForPrompt:(nonnull SGPrompt *)prompt;
+ (nonnull SGQuery *)promptsQueryForPostPurchase:(nonnull SGPEvent *)event;
+ (nonnull SGQuery *)promptsQueryForBrowse;
+ (nonnull SGQuery *)promptsQueryForSettings;
+ (nonnull SGQuery *)promptsQueryForMyTickets;
+ (nonnull SGQuery *)promptsQueryForTracking:(nonnull SGPPerformer *)performer;

#pragma mark - Venue Services

+ (nonnull SGQuery *)venueServicesAvailabilityQuery;
+ (nonnull SGQuery *)venueServicesPaymentMethodQueryForPaymentMethod:(nonnull SGPaymentMethod *)paymentMethod;
+ (nonnull SGQuery *)venueServicesPurchaseReportingQuery;
+ (nonnull SGQuery *)venueServicesConfigurationFetchQueryWithParameters:(nonnull NSDictionary *)parameters;

#pragma mark - Facebook Account Upgrade

+ (nonnull SGQuery *)facebookAccountUpgradeQuery;

#pragma mark - Tracker service location
+ (void)setLocationSource:(SGTrackerDeviceLocationLocationSource)source;
+ (SGTrackerDeviceLocationLocationSource)locationSource;

#pragma mark - Global Settings
+ (void)setAppVersion:(nonnull NSString *)version;
+ (void)setDefaultBaseDomain:(nonnull NSString *)baseDomain;
+ (void)setBaseFormat:(nonnull NSString *)baseFormat;

@end
