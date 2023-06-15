//
//  SGTracker.h
//  Pods
//
//  Version 18.27.2 created by the Tracker Service using ios_generate_classes.py.
//
//

@import Foundation;

#import "SGTrackerEnums.h"

/**
 *  mParticle tracking is abstracted out into an injectible protocol in order to avoid needing
 *  to pull the dependency into the SGTracker pod
 */
@protocol SGMParticleTracking
- (void)logMParticleEvent:(nonnull NSString *)eventName withEventMetadata:(nullable NSDictionary<NSString *, id> *)eventMetadata;
- (void)setMParticleUserAttributeForKey:(nonnull NSString *)key value:(nonnull id)value;
- (void)removeMParticleUserAttributeForKey:(nonnull NSString *)key;
@optional
- (void)logTrackerErrorWithFormat:(nonnull NSString *)format, ... NS_FORMAT_FUNCTION(1,2);
@end

@interface SGTracker : NSObject

@property (class, nonatomic, nullable) id<SGMParticleTracking> mParticleTracker;

/**
 * The globalUIOrigin is used whenever an action is tracked with a uIOrigin of
 * SGTracker[SomeAction]UIOriginGlobal. If no match is found between the strings
 * corresponding to the global and action-specific ui_origin enums, or if the
 * globalUIOrigin is SGTrackerGlobalUIOriginNone (the default) then the action
 * will be tracked with SGTracker[SomeAction]UIOriginNone.
 */
@property (class, nonatomic, assign) SGTrackerGlobalUIOrigin globalUIOrigin;


/**
 * Set the build_version as an mParticle user attribute for all future events.
 *
 * @param buildVersion Optional, must be NSString * or nil. The internal client version that changes more frequently than the app version.
*/
+ (void)setUserAttributeWithBuildVersion:(nullable NSString *)buildVersion;

/**
 * Set the user_saved_lat as an mParticle user attribute for all future events.
 *
 * @param userSavedLat Optional, must be NSNumber * or nil. Latitude for location currently saved in the SeatGeek settings.
*/
+ (void)setUserAttributeWithUserSavedLat:(nullable NSNumber *)userSavedLat;

/**
 * Set the user_saved_lon as an mParticle user attribute for all future events.
 *
 * @param userSavedLon Optional, must be NSNumber * or nil. Longitude for location currently saved in the SeatGeek settings.
*/
+ (void)setUserAttributeWithUserSavedLon:(nullable NSNumber *)userSavedLon;

/**
 * An account upgrade screen is shown.
*/
+ (void)trackAccountUpgradeShow;

/**
 * User is viewing a ticket and taps the Add to Apple Wallet button.
 *
 * @param displayType Required, must be SGTrackerApplewalletDisplayType. Whether the ticket was shown as a barcode or a PDF.
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param ticketGroupID Optional, must be NSString * or nil.
 * @param ticketID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerApplewalletUIOrigin or SGTrackerApplewalletUIOriginNone. Short identifier for the part of the UI on which the help link was shown.
 * @param userPurchaseID Optional, must be NSString * or nil.
*/
+ (void)trackApplewalletClickWithDisplayType:(SGTrackerApplewalletDisplayType)displayType domainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID ticketGroupID:(nullable NSString *)ticketGroupID ticketID:(nullable NSString *)ticketID uIOrigin:(SGTrackerApplewalletUIOrigin)uIOrigin userPurchaseID:(nullable NSString *)userPurchaseID;

/**
 * POST /user/single_use_token in order to authenticate a mobile web link that's being opened in the iOS app returns an error.
 *
 * @param errorCode Optional, must be NSInteger or NSNotFound.
 * @param errorMessage Optional, must be NSString * or nil.
 * @param target Required, must be NSString *. The target link that the user is going to; values: [account_manager, facebook_account_upgrade, flex_tickets_return].
 * @param uIOrigin Required, must be SGTrackerAuthenticatedLinkUIOrigin. Short identifier for the part of the UI from which the user tapped on a link to mobile web..
*/
+ (void)trackAuthenticatedLinkErrorWithErrorCode:(NSInteger)errorCode errorMessage:(nullable NSString *)errorMessage target:(nonnull NSString *)target uIOrigin:(SGTrackerAuthenticatedLinkUIOrigin)uIOrigin;

/**
 * POST /user/single_use_token in order to authenticate a mobile web link that's being opened in the iOS app.
 *
 * @param target Required, must be NSString *. The target link that the user is going to; values: [account_manager, facebook_account_upgrade, flex_tickets_return].
 * @param uIOrigin Required, must be SGTrackerAuthenticatedLinkUIOrigin. Short identifier for the part of the UI from which the user tapped on a link to mobile web..
*/
+ (void)trackAuthenticatedLinkSubmitWithTarget:(nonnull NSString *)target uIOrigin:(SGTrackerAuthenticatedLinkUIOrigin)uIOrigin;

/**
 * POST /user/single_use_token in order to authenticate a mobile web link that's being opened in the iOS app returns a success.
 *
 * @param target Required, must be NSString *. The target link that the user is going to; values: [account_manager, facebook_account_upgrade, flex_tickets_return].
 * @param uIOrigin Required, must be SGTrackerAuthenticatedLinkUIOrigin. Short identifier for the part of the UI from which the user tapped on a link to mobile web..
*/
+ (void)trackAuthenticatedLinkSuccessWithTarget:(nonnull NSString *)target uIOrigin:(SGTrackerAuthenticatedLinkUIOrigin)uIOrigin;

/**
 * A user applies a filter on the browse screen.
 *
 * @param datetimeLocalGte Optional, must be NSString * or nil.
 * @param datetimeLocalLte Optional, must be NSString * or nil.
 * @param filterLat Optional, must be NSNumber * or nil. Latitude of the geo filter the user applied.
 * @param filterLon Optional, must be NSNumber * or nil. Longitude of the geo filter the user applied.
 * @param filterType Required, must be SGTrackerBrowseFilterFilterType. Short identifier for which filter is applied.
*/
+ (void)trackBrowseFilterApplyWithDatetimeLocalGte:(nullable NSString *)datetimeLocalGte datetimeLocalLte:(nullable NSString *)datetimeLocalLte filterLat:(nullable NSNumber *)filterLat filterLon:(nullable NSNumber *)filterLon filterType:(SGTrackerBrowseFilterFilterType)filterType;

/**
 * A filter on the browse screen is cleared.
 *
 * @param filterType Required, must be SGTrackerBrowseFilterFilterType. Short identifier for which filter is shown.
*/
+ (void)trackBrowseFilterClearWithFilterType:(SGTrackerBrowseFilterFilterType)filterType;

/**
 * A filter on the browse screen is shown.
 *
 * @param filterType Required, must be SGTrackerBrowseFilterFilterType. Short identifier for which filter is shown.
*/
+ (void)trackBrowseFilterShowWithFilterType:(SGTrackerBrowseFilterFilterType)filterType;

/**
 * The main browse screen is shown.
*/
+ (void)trackBrowseShow;

/**
 * Error is returned from submitting checkout form to purchases API.
 *
 * @param clickID Optional, must be NSString * or nil.
 * @param deliveryMethod Optional, must be NSString * or nil.
 * @param errorCategory Optional, must be SGTrackerCheckoutErrorCategory or SGTrackerCheckoutErrorCategoryNone.
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param eventID Optional, must be NSString * or nil.
 * @param eventTitle Optional, must be NSString * or nil.
 * @param eventType Optional, must be NSString * or nil.
 * @param feeChoice Optional, must be SGTrackerCheckoutFeeChoice or SGTrackerCheckoutFeeChoiceNone. The user's choice for dispaying fees.
 * @param hasDealScore Optional, must be @(YES), @(NO), or nil. Is Deal Score enabled for this event..
 * @param hasMap Required, must be BOOL. Is the event mapped or not.  Note that this is not whether the listing is mapped..
 * @param hasPriceTypes Optional, must be @(YES), @(NO), or nil. Did we display price type information or not..
 * @param hasSeatInfo Optional, must be @(YES), @(NO), or nil. Does the listing have seat information or not..
 * @param isEticket Required, must be BOOL.
 * @param isGa Required, must be BOOL. Is the event General Admission.
 * @param isPciCompliant Optional, must be @(YES), @(NO), or nil. Is user entering sensitive credit card data in a Payment Card Industry compliant manner i.e. Spreedly iFrame.
 * @param marketApplePayEligible Required, must be BOOL. Is the market eligible for payment using Apple Pay, independent of whether the user has Apple Pay set up..
 * @param marketGooglePayEligible Optional, must be @(YES), @(NO), or nil. Is the market eligible for payment using Google Pay, independent of whether the user has Google Pay set up..
 * @param marketName Required, must be NSString *.
 * @param paymentMethodToken Optional, must be NSString * or nil. The token used to identify a user's payment method. Not required because this will not exist when using Apple Pay or Android Pay or Google pay..
 * @param paymentType Optional, must be SGTrackerCheckoutPaymentType or SGTrackerCheckoutPaymentTypeNone.
 * @param performerID Optional, must be NSString * or nil.
 * @param performerName Optional, must be NSString * or nil.
 * @param performerType Optional, must be NSString * or nil.
 * @param pricePerTicket Optional, must be NSNumber * or nil.
 * @param promocodeID Optional, must be NSString * or nil. The ID of the promocode applied to the order, if any.
 * @param promocodeType Optional, must be SGTrackerCheckoutPromocodeType or SGTrackerCheckoutPromocodeTypeNone. The type of promocode applied to the order, if any.
 * @param quantity Optional, must be NSInteger or NSNotFound.
 * @param totalPrice Optional, must be NSNumber * or nil.
 * @param userApplePayEligible Required, must be BOOL. Whether the device is capable and set up for using Apple Pay, independent of whetherthe market is Apple Pay compatible..
 * @param userGooglePayEligible Optional, must be @(YES), @(NO), or nil. Whether the device is capable and set up for using Google Pay, independent of whetherthe market is Google Pay compatible..
 * @param venueID Optional, must be NSString * or nil.
 * @param venueName Optional, must be NSString * or nil.
*/
+ (void)trackCheckoutErrorWithClickID:(nullable NSString *)clickID deliveryMethod:(nullable NSString *)deliveryMethod errorCategory:(SGTrackerCheckoutErrorCategory)errorCategory errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage eventID:(nullable NSString *)eventID eventTitle:(nullable NSString *)eventTitle eventType:(nullable NSString *)eventType feeChoice:(SGTrackerCheckoutFeeChoice)feeChoice hasDealScore:(nullable NSNumber *)hasDealScore hasMap:(BOOL)hasMap hasPriceTypes:(nullable NSNumber *)hasPriceTypes hasSeatInfo:(nullable NSNumber *)hasSeatInfo isEticket:(BOOL)isEticket isGa:(BOOL)isGa isPciCompliant:(nullable NSNumber *)isPciCompliant marketApplePayEligible:(BOOL)marketApplePayEligible marketGooglePayEligible:(nullable NSNumber *)marketGooglePayEligible marketName:(nonnull NSString *)marketName paymentMethodToken:(nullable NSString *)paymentMethodToken paymentType:(SGTrackerCheckoutPaymentType)paymentType performerID:(nullable NSString *)performerID performerName:(nullable NSString *)performerName performerType:(nullable NSString *)performerType pricePerTicket:(nullable NSNumber *)pricePerTicket promocodeID:(nullable NSString *)promocodeID promocodeType:(SGTrackerCheckoutPromocodeType)promocodeType quantity:(NSInteger)quantity totalPrice:(nullable NSNumber *)totalPrice userApplePayEligible:(BOOL)userApplePayEligible userGooglePayEligible:(nullable NSNumber *)userGooglePayEligible venueID:(nullable NSString *)venueID venueName:(nullable NSString *)venueName;

/**
 * User highlights a data field, changes its value, and then leaves (by clicking another field or exiting the screen).
 *
 * @param clickID Optional, must be NSString * or nil.
 * @param dataField Required, must be SGTrackerCheckoutFieldDataField.
 * @param editType Required, must be SGTrackerCheckoutFieldEditType. Whether this edit was for adding new data, or updating existing data.
 * @param promocode Optional, must be NSString * or nil. The promocode being added, edited, or removed from the order. Note that this is not necessarily changing it on the user's account..
*/
+ (void)trackCheckoutFieldEditWithClickID:(nullable NSString *)clickID dataField:(SGTrackerCheckoutFieldDataField)dataField editType:(SGTrackerCheckoutFieldEditType)editType promocode:(nullable NSString *)promocode;

/**
 * User taps on an item in checkout.
 *
 * @param clickID Optional, must be NSString * or nil.
 * @param eventID Optional, must be NSString * or nil.
 * @param itemType Required, must be SGTrackerCheckoutItemItemType. The item clicked in checkout.
 * @param stepName Optional, must be SGTrackerCheckoutItemStepName or SGTrackerCheckoutItemStepNameNone.
*/
+ (void)trackCheckoutItemClickWithClickID:(nullable NSString *)clickID eventID:(nullable NSString *)eventID itemType:(SGTrackerCheckoutItemItemType)itemType stepName:(SGTrackerCheckoutItemStepName)stepName;

/**
 * User is shown an item in checkout.
 *
 * @param clickID Optional, must be NSString * or nil.
 * @param eventID Optional, must be NSString * or nil.
 * @param itemType Required, must be SGTrackerCheckoutItemItemType. The item shown in checkout.
 * @param stepName Optional, must be SGTrackerCheckoutItemStepName or SGTrackerCheckoutItemStepNameNone.
*/
+ (void)trackCheckoutItemShowWithClickID:(nullable NSString *)clickID eventID:(nullable NSString *)eventID itemType:(SGTrackerCheckoutItemItemType)itemType stepName:(SGTrackerCheckoutItemStepName)stepName;

/**
 * Tap to buy tickets on checkout form.
 *
 * @param checkoutType Optional, must be SGTrackerCheckoutCheckoutType or SGTrackerCheckoutCheckoutTypeNone.
 * @param clickID Optional, must be NSString * or nil.
 * @param deliveryMethod Optional, must be NSString * or nil.
 * @param eventDatetimeLocal Optional, must be NSString * or nil. Date/time of the event in the local timezone of the venue.
 * @param eventID Required, must be NSString *.
 * @param eventShortTitle Optional, must be NSString * or nil. A shortened title for the event.
 * @param eventTaxonomyName Optional, must be NSString * or nil. Type of event (broad category).
 * @param eventTitle Optional, must be NSString * or nil.
 * @param eventType Optional, must be NSString * or nil.
 * @param feeChoice Optional, must be SGTrackerCheckoutFeeChoice or SGTrackerCheckoutFeeChoiceNone. The user's choice for dispaying fees.
 * @param hasDealScore Optional, must be @(YES), @(NO), or nil. Is Deal Score enabled for this event..
 * @param hasMap Required, must be BOOL. Is the event mapped or not.  Note that this is not whether the listing is mapped..
 * @param hasNotes Required, must be BOOL. Whether the listing has seller or SeatGeek notes.
 * @param hasPriceTypes Optional, must be @(YES), @(NO), or nil. Did we display price type information or not..
 * @param hasSeatInfo Optional, must be @(YES), @(NO), or nil. Does the listing have seat information or not..
 * @param hasViewFromSeat Optional, must be @(YES), @(NO), or nil.
 * @param isEticket Required, must be BOOL.
 * @param isGa Required, must be BOOL. Is the event General Admission.
 * @param listingID Required, must be NSString *.
 * @param marketApplePayEligible Required, must be BOOL. Is the market eligible for payment using Apple Pay, independent of whether the user has Apple Pay set up..
 * @param marketGooglePayEligible Optional, must be @(YES), @(NO), or nil. Is the market eligible for payment using Google Pay, independent of whether the user has Google Pay set up..
 * @param marketName Required, must be NSString *.
 * @param paymentMethodToken Optional, must be NSString * or nil. The token used to identify a user's payment method. Not required because this will not exist when using Apple Pay..
 * @param paymentType Required, must be SGTrackerCheckoutPaymentType. The payment type that the user is using for this purchase.  Required for this action since you can't attempt to pay without a payment type..
 * @param performerID Optional, must be NSString * or nil.
 * @param performerName Optional, must be NSString * or nil.
 * @param performerType Optional, must be NSString * or nil.
 * @param pricePerTicket Optional, must be NSNumber * or nil.
 * @param promocodeID Optional, must be NSString * or nil. The ID of the promocode applied to the order, if any.
 * @param promocodeType Optional, must be SGTrackerCheckoutPromocodeType or SGTrackerCheckoutPromocodeTypeNone. The type of promocode applied to the order, if any.
 * @param quantity Required, must be NSInteger.
 * @param sortType Optional, must be SGTrackerCheckoutSortType or SGTrackerCheckoutSortTypeNone. The user's choice for sorting listings.  Not sent if there is no sort option (eg. General Admission).
 * @param totalPrice Required, must be NSNumber *.
 * @param userApplePayEligible Required, must be BOOL. Whether the device is capable and set up for using Apple Pay, independent of whetherthe market is Apple Pay compatible..
 * @param userGooglePayEligible Optional, must be @(YES), @(NO), or nil. Whether the device is capable and set up for using Google Pay, independent of whetherthe market is Google Pay compatible..
 * @param venueCity Optional, must be NSString * or nil.
 * @param venueID Optional, must be NSString * or nil.
 * @param venueName Optional, must be NSString * or nil.
 * @param venueState Optional, must be NSString * or nil.
*/
+ (void)trackCheckoutPayWithCheckoutType:(SGTrackerCheckoutCheckoutType)checkoutType clickID:(nullable NSString *)clickID deliveryMethod:(nullable NSString *)deliveryMethod eventDatetimeLocal:(nullable NSString *)eventDatetimeLocal eventID:(nonnull NSString *)eventID eventShortTitle:(nullable NSString *)eventShortTitle eventTaxonomyName:(nullable NSString *)eventTaxonomyName eventTitle:(nullable NSString *)eventTitle eventType:(nullable NSString *)eventType feeChoice:(SGTrackerCheckoutFeeChoice)feeChoice hasDealScore:(nullable NSNumber *)hasDealScore hasMap:(BOOL)hasMap hasNotes:(BOOL)hasNotes hasPriceTypes:(nullable NSNumber *)hasPriceTypes hasSeatInfo:(nullable NSNumber *)hasSeatInfo hasViewFromSeat:(nullable NSNumber *)hasViewFromSeat isEticket:(BOOL)isEticket isGa:(BOOL)isGa listingID:(nonnull NSString *)listingID marketApplePayEligible:(BOOL)marketApplePayEligible marketGooglePayEligible:(nullable NSNumber *)marketGooglePayEligible marketName:(nonnull NSString *)marketName paymentMethodToken:(nullable NSString *)paymentMethodToken paymentType:(SGTrackerCheckoutPaymentType)paymentType performerID:(nullable NSString *)performerID performerName:(nullable NSString *)performerName performerType:(nullable NSString *)performerType pricePerTicket:(nullable NSNumber *)pricePerTicket promocodeID:(nullable NSString *)promocodeID promocodeType:(SGTrackerCheckoutPromocodeType)promocodeType quantity:(NSInteger)quantity sortType:(SGTrackerCheckoutSortType)sortType totalPrice:(nonnull NSNumber *)totalPrice userApplePayEligible:(BOOL)userApplePayEligible userGooglePayEligible:(nullable NSNumber *)userGooglePayEligible venueCity:(nullable NSString *)venueCity venueID:(nullable NSString *)venueID venueName:(nullable NSString *)venueName venueState:(nullable NSString *)venueState;

/**
 * User selects saved payment or shipping info, edits saved info, or taps to add new info.
 *
 * @param clickID Optional, must be NSString * or nil.
 * @param editType Required, must be SGTrackerCheckoutSectionEditType. Whether this edit was for adding new data, changing existing data, using existing data, or choosing to not use saved data (only applicable for promocodes).
 * @param formSection Required, must be SGTrackerCheckoutSectionFormSection.
*/
+ (void)trackCheckoutSectionEditWithClickID:(nullable NSString *)clickID editType:(SGTrackerCheckoutSectionEditType)editType formSection:(SGTrackerCheckoutSectionFormSection)formSection;

/**
 * User taps into a checkout form section.
 *
 * @param clickID Optional, must be NSString * or nil.
 * @param formSection Required, must be SGTrackerCheckoutSectionFormSection.
*/
+ (void)trackCheckoutSectionSelectWithClickID:(nullable NSString *)clickID formSection:(SGTrackerCheckoutSectionFormSection)formSection;

/**
 * When a user views the checkout screen on iOS..
 *
 * @param clickID Required, must be NSString *.
 * @param eventID Optional, must be NSString * or nil.
 * @param hasViewFromSeat Optional, must be @(YES), @(NO), or nil.
 * @param isAffirmEligible Required, must be BOOL. If user is eligible to select affirm as a payment method.
 * @param isBestAvailable Required, must be BOOL.
 * @param isDripPricing Required, must be BOOL.
 * @param isPciCompliant Optional, must be @(YES), @(NO), or nil. Is user entering sensitive credit card data in a Payment Card Industry compliant manner i.e. Spreedly iFrame.
 * @param isSgo Required, must be BOOL.
 * @param listingsDisplayOrientation Optional, must be SGTrackerCheckoutListingsDisplayOrientation or SGTrackerCheckoutListingsDisplayOrientationNone. Details if the listings shown were displayed in a horizontal list or vertical list.
 * @param numSteps Required, must be NSInteger.
 * @param salesMode Optional, must be SGTrackerCheckoutSalesMode or SGTrackerCheckoutSalesModeNone. The main sales mode that the inventory of this event is in (best available, hybrid best available, interactive seat mode). Mainly concerns primary inventory.
 * @param sortType Optional, must be SGTrackerCheckoutSortType or SGTrackerCheckoutSortTypeNone.
*/
+ (void)trackCheckoutStartWithClickID:(nonnull NSString *)clickID eventID:(nullable NSString *)eventID hasViewFromSeat:(nullable NSNumber *)hasViewFromSeat isAffirmEligible:(BOOL)isAffirmEligible isBestAvailable:(BOOL)isBestAvailable isDripPricing:(BOOL)isDripPricing isPciCompliant:(nullable NSNumber *)isPciCompliant isSgo:(BOOL)isSgo listingsDisplayOrientation:(SGTrackerCheckoutListingsDisplayOrientation)listingsDisplayOrientation numSteps:(NSInteger)numSteps salesMode:(SGTrackerCheckoutSalesMode)salesMode sortType:(SGTrackerCheckoutSortType)sortType;

/**
 * Successful response from POST /purchases.
 *
 * @param clickID Optional, must be NSString * or nil.
 * @param deliveryMethod Required, must be NSString *.
 * @param eventID Required, must be NSString *.
 * @param eventTitle Optional, must be NSString * or nil.
 * @param eventType Optional, must be NSString * or nil.
 * @param feeChoice Optional, must be SGTrackerCheckoutFeeChoice or SGTrackerCheckoutFeeChoiceNone. The user's choice for dispaying fees.
 * @param hasDealScore Optional, must be @(YES), @(NO), or nil. Is Deal Score enabled for this event..
 * @param hasMap Required, must be BOOL. Is the event mapped or not.  Note that this is not whether the listing is mapped..
 * @param hasNotes Required, must be BOOL. Whether the listing has seller or SeatGeek notes.
 * @param hasPriceTypes Optional, must be @(YES), @(NO), or nil. Did we display price type information or not..
 * @param hasSeatInfo Optional, must be @(YES), @(NO), or nil. Does the listing have seat information or not..
 * @param hasViewFromSeat Optional, must be @(YES), @(NO), or nil.
 * @param isDripPricing Optional, must be @(YES), @(NO), or nil. Did we hide fees until the end or not..
 * @param isGa Required, must be BOOL. Is the event General Admission.
 * @param listingID Required, must be NSString *.
 * @param listingsDisplayOrientation Optional, must be SGTrackerCheckoutListingsDisplayOrientation or SGTrackerCheckoutListingsDisplayOrientationNone. Details if the listings shown were displayed in a horizontal list or vertical list.
 * @param marketApplePayEligible Required, must be BOOL. Is the market eligible for payment using Apple Pay, independent of whether the user has Apple Pay set up..
 * @param marketGooglePayEligible Optional, must be @(YES), @(NO), or nil. Is the market eligible for payment using Google Pay, independent of whether the user has Google Pay set up..
 * @param marketName Required, must be NSString *.
 * @param orderID Required, must be NSString *.
 * @param paymentMethodToken Optional, must be NSString * or nil. The token used to identify a user's payment method. Not required because this will not exist when using Apple Pay or Android Pay or Google Pay..
 * @param paymentType Optional, must be SGTrackerCheckoutPaymentType or SGTrackerCheckoutPaymentTypeNone.
 * @param performerID Optional, must be NSString * or nil.
 * @param performerName Optional, must be NSString * or nil.
 * @param performerType Optional, must be NSString * or nil.
 * @param pricePerTicket Optional, must be NSNumber * or nil.
 * @param promocodeID Optional, must be NSString * or nil. The ID of the promocode applied to the order, if any.
 * @param promocodeType Optional, must be SGTrackerCheckoutPromocodeType or SGTrackerCheckoutPromocodeTypeNone. The type of promocode applied to the order, if any.
 * @param quantity Optional, must be NSInteger or NSNotFound.
 * @param sortType Optional, must be SGTrackerCheckoutSortType or SGTrackerCheckoutSortTypeNone. The user's choice for sorting listings.  Not sent if there is no sort option (eg. General Admission).
 * @param totalPrice Optional, must be NSNumber * or nil.
 * @param userApplePayEligible Required, must be BOOL. Whether the device is capable and set up for using Apple Pay, independent of whetherthe market is Apple Pay compatible..
 * @param userGooglePayEligible Optional, must be @(YES), @(NO), or nil. Whether the device is capable and set up for using Google Pay, independent of whetherthe market is Google Pay compatible..
 * @param userPurchaseID Required, must be NSString *.
 * @param venueConfigID Optional, must be NSString * or nil.
 * @param venueID Optional, must be NSString * or nil.
 * @param venueName Optional, must be NSString * or nil.
 * @param viewType Optional, must be SGTrackerCheckoutViewType or SGTrackerCheckoutViewTypeNone. The type of event page that the user viewed before hitting checkout.
*/
+ (void)trackCheckoutSuccessWithClickID:(nullable NSString *)clickID deliveryMethod:(nonnull NSString *)deliveryMethod eventID:(nonnull NSString *)eventID eventTitle:(nullable NSString *)eventTitle eventType:(nullable NSString *)eventType feeChoice:(SGTrackerCheckoutFeeChoice)feeChoice hasDealScore:(nullable NSNumber *)hasDealScore hasMap:(BOOL)hasMap hasNotes:(BOOL)hasNotes hasPriceTypes:(nullable NSNumber *)hasPriceTypes hasSeatInfo:(nullable NSNumber *)hasSeatInfo hasViewFromSeat:(nullable NSNumber *)hasViewFromSeat isDripPricing:(nullable NSNumber *)isDripPricing isGa:(BOOL)isGa listingID:(nonnull NSString *)listingID listingsDisplayOrientation:(SGTrackerCheckoutListingsDisplayOrientation)listingsDisplayOrientation marketApplePayEligible:(BOOL)marketApplePayEligible marketGooglePayEligible:(nullable NSNumber *)marketGooglePayEligible marketName:(nonnull NSString *)marketName orderID:(nonnull NSString *)orderID paymentMethodToken:(nullable NSString *)paymentMethodToken paymentType:(SGTrackerCheckoutPaymentType)paymentType performerID:(nullable NSString *)performerID performerName:(nullable NSString *)performerName performerType:(nullable NSString *)performerType pricePerTicket:(nullable NSNumber *)pricePerTicket promocodeID:(nullable NSString *)promocodeID promocodeType:(SGTrackerCheckoutPromocodeType)promocodeType quantity:(NSInteger)quantity sortType:(SGTrackerCheckoutSortType)sortType totalPrice:(nullable NSNumber *)totalPrice userApplePayEligible:(BOOL)userApplePayEligible userGooglePayEligible:(nullable NSNumber *)userGooglePayEligible userPurchaseID:(nonnull NSString *)userPurchaseID venueConfigID:(nullable NSString *)venueConfigID venueID:(nullable NSString *)venueID venueName:(nullable NSString *)venueName viewType:(SGTrackerCheckoutViewType)viewType;

/**
 * Whenever checkout data in the form is validated (a call to checkout API /purchases/summary is made).
 *
 * @param clickID Optional, must be NSString * or nil.
 * @param deliveryMethod Optional, must be NSString * or nil.
 * @param didBypassLogin Optional, must be @(YES), @(NO), or nil. true if the summary request bypassed login in anonymous checkout using the email of a registered user.
 * @param eventID Required, must be NSString *.
 * @param eventTitle Optional, must be NSString * or nil.
 * @param eventType Optional, must be NSString * or nil.
 * @param feeChoice Optional, must be SGTrackerCheckoutSummaryFeeChoice or SGTrackerCheckoutSummaryFeeChoiceNone. The user's choice for dispaying fees.
 * @param hasDealScore Optional, must be @(YES), @(NO), or nil. Is Deal Score enabled for this event..
 * @param hasMap Required, must be BOOL. Is the event mapped or not.  Note that this is not whether the listing is mapped..
 * @param hasNotes Required, must be BOOL. Whether the listing has seller or SeatGeek notes.
 * @param hasPriceTypes Optional, must be @(YES), @(NO), or nil. Did we display price type information or not..
 * @param hasSavedPayment Required, must be BOOL. True if the checkout session has an account or client saved payment method available..
 * @param hasSeatInfo Optional, must be @(YES), @(NO), or nil. Does the listing have seat information or not..
 * @param hasViewFromSeat Optional, must be @(YES), @(NO), or nil.
 * @param isEticket Required, must be BOOL.
 * @param isGa Required, must be BOOL. Is the event General Admission.
 * @param listingID Required, must be NSString *.
 * @param marketApplePayEligible Required, must be BOOL. Is the market eligible for payment using Apple Pay, independent of whether the user has Apple Pay set up..
 * @param marketGooglePayEligible Optional, must be @(YES), @(NO), or nil. Is the market eligible for payment using Google Pay, independent of whether the user has Google Pay set up..
 * @param marketName Required, must be NSString *.
 * @param performerID Optional, must be NSString * or nil.
 * @param performerName Optional, must be NSString * or nil.
 * @param performerType Optional, must be NSString * or nil.
 * @param pricePerTicket Optional, must be NSNumber * or nil.
 * @param promocodeID Optional, must be NSString * or nil. The ID of the promocode applied to the order, if any.
 * @param promocodeType Optional, must be SGTrackerCheckoutSummaryPromocodeType or SGTrackerCheckoutSummaryPromocodeTypeNone. The type of promocode applied to the order, if any.
 * @param quantity Required, must be NSInteger.
 * @param sortType Optional, must be SGTrackerCheckoutSummarySortType or SGTrackerCheckoutSummarySortTypeNone. The user's choice for sorting listings.  Not sent if there is no sort option (eg. General Admission).
 * @param totalPrice Required, must be NSNumber *.
 * @param userApplePayEligible Required, must be BOOL. Whether the device is capable and set up for using Apple Pay, independent of whetherthe market is Apple Pay compatible..
 * @param userGooglePayEligible Optional, must be @(YES), @(NO), or nil. Whether the device is capable and set up for using Google Pay, independent of whetherthe market is Google Pay compatible..
 * @param venueID Optional, must be NSString * or nil.
 * @param venueName Optional, must be NSString * or nil.
*/
+ (void)trackCheckoutSummaryShowWithClickID:(nullable NSString *)clickID deliveryMethod:(nullable NSString *)deliveryMethod didBypassLogin:(nullable NSNumber *)didBypassLogin eventID:(nonnull NSString *)eventID eventTitle:(nullable NSString *)eventTitle eventType:(nullable NSString *)eventType feeChoice:(SGTrackerCheckoutSummaryFeeChoice)feeChoice hasDealScore:(nullable NSNumber *)hasDealScore hasMap:(BOOL)hasMap hasNotes:(BOOL)hasNotes hasPriceTypes:(nullable NSNumber *)hasPriceTypes hasSavedPayment:(BOOL)hasSavedPayment hasSeatInfo:(nullable NSNumber *)hasSeatInfo hasViewFromSeat:(nullable NSNumber *)hasViewFromSeat isEticket:(BOOL)isEticket isGa:(BOOL)isGa listingID:(nonnull NSString *)listingID marketApplePayEligible:(BOOL)marketApplePayEligible marketGooglePayEligible:(nullable NSNumber *)marketGooglePayEligible marketName:(nonnull NSString *)marketName performerID:(nullable NSString *)performerID performerName:(nullable NSString *)performerName performerType:(nullable NSString *)performerType pricePerTicket:(nullable NSNumber *)pricePerTicket promocodeID:(nullable NSString *)promocodeID promocodeType:(SGTrackerCheckoutSummaryPromocodeType)promocodeType quantity:(NSInteger)quantity sortType:(SGTrackerCheckoutSummarySortType)sortType totalPrice:(nonnull NSNumber *)totalPrice userApplePayEligible:(BOOL)userApplePayEligible userGooglePayEligible:(nullable NSNumber *)userGooglePayEligible venueID:(nullable NSString *)venueID venueName:(nullable NSString *)venueName;

/**
 * When a user is shown the upsells screen.
 *
 * @param clickID Optional, must be NSString * or nil.
 * @param eventID Required, must be NSString *.
 * @param eventType Optional, must be NSString * or nil. Type of event (subcategory).
 * @param listingID Required, must be NSString *.
 * @param marketID Optional, must be NSString * or nil.
 * @param marketName Required, must be NSString *.
 * @param performerID Optional, must be NSString * or nil.
 * @param performerName Optional, must be NSString * or nil.
 * @param performerType Optional, must be NSString * or nil.
 * @param quantity Required, must be NSInteger.
 * @param venueConfigID Optional, must be NSString * or nil.
 * @param venueID Optional, must be NSString * or nil.
 * @param venueName Optional, must be NSString * or nil.
*/
+ (void)trackCheckoutUpsellShowWithClickID:(nullable NSString *)clickID eventID:(nonnull NSString *)eventID eventType:(nullable NSString *)eventType listingID:(nonnull NSString *)listingID marketID:(nullable NSString *)marketID marketName:(nonnull NSString *)marketName performerID:(nullable NSString *)performerID performerName:(nullable NSString *)performerName performerType:(nullable NSString *)performerType quantity:(NSInteger)quantity venueConfigID:(nullable NSString *)venueConfigID venueID:(nullable NSString *)venueID venueName:(nullable NSString *)venueName;

/**
 * First app launch.
*/
+ (void)trackDeviceInstall;

/**
 * The location being used for api requests on this device.  May come from sources such as GPS, GeoIP, user entry, account etc..
 *
 * @param locationSource Required, must be SGTrackerDeviceLocationLocationSource. The source of the new location.
 * @param uIOrigin Optional, must be SGTrackerDeviceLocationUIOrigin or SGTrackerDeviceLocationUIOriginNone. Short identifier for the part of the UI from which the user clicked to add/edit.
*/
+ (void)trackDeviceLocationChangeWithLocationSource:(SGTrackerDeviceLocationLocationSource)locationSource uIOrigin:(SGTrackerDeviceLocationUIOrigin)uIOrigin;

/**
 * An entrance to the app from a deeplink.
 *
 * @param channel Optional, must be NSString * or nil.
 * @param channelGroup Optional, must be NSString * or nil.
 * @param eventID Optional, must be NSString * or nil.
 * @param eventTitle Optional, must be NSString * or nil.
 * @param eventType Optional, must be NSString * or nil.
 * @param pageType Optional, must be SGTrackerEntrancePageType or SGTrackerEntrancePageTypeNone.
 * @param performerID Optional, must be NSString * or nil.
 * @param performerName Optional, must be NSString * or nil.
 * @param performerType Optional, must be NSString * or nil.
 * @param platform Optional, must be SGTrackerEntrancePlatform or SGTrackerEntrancePlatformNone. The platform where the deeplink originated from.
 * @param referrer Optional, must be NSString * or nil. Provenance of the deeplink. Could be a URL, an Android app e.g. com.google.android.keep or a browser e.g. com.android.chrome.
 * @param route Required, must be NSString *. Partial route of deeplink that triggered this tracker action e.g. e/events/2931517.
 * @param source Optional, must be SGTrackerEntranceSource or SGTrackerEntranceSourceNone. The source by which the deeplink was created.
 * @param venueConfigID Optional, must be NSString * or nil.
 * @param venueID Optional, must be NSString * or nil.
 * @param venueName Optional, must be NSString * or nil.
*/
+ (void)trackEntranceDeeplinkWithChannel:(nullable NSString *)channel channelGroup:(nullable NSString *)channelGroup eventID:(nullable NSString *)eventID eventTitle:(nullable NSString *)eventTitle eventType:(nullable NSString *)eventType pageType:(SGTrackerEntrancePageType)pageType performerID:(nullable NSString *)performerID performerName:(nullable NSString *)performerName performerType:(nullable NSString *)performerType platform:(SGTrackerEntrancePlatform)platform referrer:(nullable NSString *)referrer route:(nonnull NSString *)route source:(SGTrackerEntranceSource)source venueConfigID:(nullable NSString *)venueConfigID venueID:(nullable NSString *)venueID venueName:(nullable NSString *)venueName;

/**
 * An entrance from cold launching the SeatGeek app.
 *
 * @param launchCount Required, must be NSInteger.
 * @param uIOrigin Optional, must be SGTrackerEntranceUIOrigin or SGTrackerEntranceUIOriginNone.
*/
+ (void)trackEntranceLaunchWithLaunchCount:(NSInteger)launchCount uIOrigin:(SGTrackerEntranceUIOrigin)uIOrigin;

/**
 * An entrance to the app from a push notification.
 *
 * @param notificationTag Optional, must be NSString * or nil.
 * @param route Required, must be NSString *.
*/
+ (void)trackEntrancePushWithNotificationTag:(nullable NSString *)notificationTag route:(nonnull NSString *)route;

/**
 * User long presses or force presses on an event link or card.
 *
 * @param eventID Required, must be NSString *.
 * @param hasMap Required, must be BOOL.
 * @param isGa Required, must be BOOL.
 * @param uIOrigin Optional, must be SGTrackerEvent3DTouchUIOrigin or SGTrackerEvent3DTouchUIOriginNone. Short string identifier for where this peek occurred.
*/
+ (void)trackEvent3DTouchPeekWithEventID:(nonnull NSString *)eventID hasMap:(BOOL)hasMap isGa:(BOOL)isGa uIOrigin:(SGTrackerEvent3DTouchUIOrigin)uIOrigin;

/**
 * User long presses or force presses on an event link or card.
 *
 * @param eventID Required, must be NSString *.
 * @param hasMap Required, must be BOOL.
 * @param isGa Required, must be BOOL.
 * @param uIOrigin Optional, must be SGTrackerEvent3DTouchUIOrigin or SGTrackerEvent3DTouchUIOriginNone. Short string identifier for where this pop occurred.
*/
+ (void)trackEvent3DTouchPopWithEventID:(nonnull NSString *)eventID hasMap:(BOOL)hasMap isGa:(BOOL)isGa uIOrigin:(SGTrackerEvent3DTouchUIOrigin)uIOrigin;

/**
 * An access code modal is shown to the user, either via user interaction or business logic (i.e. event in presale mode).
 *
 * @param eventID Required, must be NSString *. The ID of the event for which the modal was shown.
 * @param isPresale Optional, must be @(YES), @(NO), or nil. Is the event in presale mode.
 * @param uIOrigin Required, must be SGTrackerEventAccessCodeModalUIOrigin. Short identifier for the part of the UI from which the modal is triggered.
*/
+ (void)trackEventAccessCodeModalShowWithEventID:(nonnull NSString *)eventID isPresale:(nullable NSNumber *)isPresale uIOrigin:(SGTrackerEventAccessCodeModalUIOrigin)uIOrigin;

/**
 * User taps box office ticket link.
 *
 * @param eventID Required, must be NSString *.
 * @param linkUrl Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerEventBoxOfficeUIOrigin or SGTrackerEventBoxOfficeUIOriginNone. Short identifier for the part of the UI from which the user opened the box office.
*/
+ (void)trackEventBoxOfficeClickWithEventID:(nonnull NSString *)eventID linkUrl:(nonnull NSString *)linkUrl uIOrigin:(SGTrackerEventBoxOfficeUIOrigin)uIOrigin;

/**
 * An event is tapped.
 *
 * @param absoluteRank Optional, must be NSInteger or NSNotFound. The absolute rank of the event within the parent..
 * @param autocompleteRequestID Optional, must be NSString * or nil. The unique id for the query sent to autocomplete that generated the result set..
 * @param eventID Required, must be NSString *.
 * @param hasPhoto Required, must be BOOL. An image is available for this event (usually via associated performer).
 * @param isRecentSearch Optional, must be @(YES), @(NO), or nil. Flag indicating whether or not the selected searchbar dropdown item was a recent search..
 * @param itemStyleType Optional, must be NSString * or nil. The event item's style type. This will come from the server and be things like 'event_normal'..
 * @param listID Optional, must be NSString * or nil. The event's parent container's list_id..
 * @param listKey Optional, must be NSString * or nil. The stable, human-readable identifier of the list containing this event..
 * @param listStyleType Optional, must be NSString * or nil. The style type of the list the event is in. This will come from the server and be things like 'list_horizontal' and 'list_vertical'..
 * @param listTitle Optional, must be NSString * or nil. The name of the list -- as the user sees it -- that contains the list item..
 * @param lowestPrice Optional, must be NSNumber * or nil.
 * @param maxItemsInView Optional, must be NSInteger or NSNotFound. The max number of items that can be shown in the event's parent at any time..
 * @param pageViewID Optional, must be NSString * or nil. The unique client-generated page identifier.
 * @param parentRank Optional, must be NSInteger or NSNotFound. The rank of the event's container relative to the other containers displayed with it..
 * @param performerID Optional, must be NSString * or nil. The performer id that was used to generate the contents of the list..
 * @param query Optional, must be NSString * or nil.
 * @param relativeRank Optional, must be NSInteger or NSNotFound. The rank of the event relative to the user's viewport..
 * @param score Optional, must be NSNumber * or nil.
 * @param uIOrigin Required, must be SGTrackerEventUIOrigin. Short identifier for the part of the UI from which the user clicked an event.
*/
+ (void)trackEventClickWithAbsoluteRank:(NSInteger)absoluteRank autocompleteRequestID:(nullable NSString *)autocompleteRequestID eventID:(nonnull NSString *)eventID hasPhoto:(BOOL)hasPhoto isRecentSearch:(nullable NSNumber *)isRecentSearch itemStyleType:(nullable NSString *)itemStyleType listID:(nullable NSString *)listID listKey:(nullable NSString *)listKey listStyleType:(nullable NSString *)listStyleType listTitle:(nullable NSString *)listTitle lowestPrice:(nullable NSNumber *)lowestPrice maxItemsInView:(NSInteger)maxItemsInView pageViewID:(nullable NSString *)pageViewID parentRank:(NSInteger)parentRank performerID:(nullable NSString *)performerID query:(nullable NSString *)query relativeRank:(NSInteger)relativeRank score:(nullable NSNumber *)score uIOrigin:(SGTrackerEventUIOrigin)uIOrigin;

/**
 * User taps an already open listings collection that results in a prompt for the user (e.g. quantity) to close.
 *
 * @param collectionDisplayName Required, must be NSString *.
 * @param collectionID Required, must be NSString *.
 * @param collectionType Optional, must be NSString * or nil.
 * @param eventID Required, must be NSString *.
 * @param uIOrigin Required, must be SGTrackerEventCollectionUIOrigin.
*/
+ (void)trackEventCollectionCollapseWithCollectionDisplayName:(nonnull NSString *)collectionDisplayName collectionID:(nonnull NSString *)collectionID collectionType:(nullable NSString *)collectionType eventID:(nonnull NSString *)eventID uIOrigin:(SGTrackerEventCollectionUIOrigin)uIOrigin;

/**
 * User deselects a listings collection.
 *
 * @param collectionDisplayName Required, must be NSString *.
 * @param collectionID Required, must be NSString *.
 * @param collectionType Required, must be NSString *.
 * @param eventID Required, must be NSString *.
 * @param uIOrigin Required, must be SGTrackerEventCollectionUIOrigin.
*/
+ (void)trackEventCollectionDeselectWithCollectionDisplayName:(nonnull NSString *)collectionDisplayName collectionID:(nonnull NSString *)collectionID collectionType:(nonnull NSString *)collectionType eventID:(nonnull NSString *)eventID uIOrigin:(SGTrackerEventCollectionUIOrigin)uIOrigin;

/**
 * User taps a listings collection that results in a prompt for the user (e.g. quantity).
 *
 * @param collectionDisplayName Required, must be NSString *.
 * @param collectionID Required, must be NSString *.
 * @param collectionType Optional, must be NSString * or nil.
 * @param eventID Required, must be NSString *.
 * @param uIOrigin Required, must be SGTrackerEventCollectionUIOrigin.
*/
+ (void)trackEventCollectionExpandWithCollectionDisplayName:(nonnull NSString *)collectionDisplayName collectionID:(nonnull NSString *)collectionID collectionType:(nullable NSString *)collectionType eventID:(nonnull NSString *)eventID uIOrigin:(SGTrackerEventCollectionUIOrigin)uIOrigin;

/**
 * User selects a listings collection.
 *
 * @param collectionDisplayName Required, must be NSString *.
 * @param collectionID Required, must be NSString *.
 * @param collectionType Required, must be NSString *.
 * @param eventID Required, must be NSString *.
 * @param uIOrigin Required, must be SGTrackerEventCollectionUIOrigin.
*/
+ (void)trackEventCollectionSelectWithCollectionDisplayName:(nonnull NSString *)collectionDisplayName collectionID:(nonnull NSString *)collectionID collectionType:(nonnull NSString *)collectionType eventID:(nonnull NSString *)eventID uIOrigin:(SGTrackerEventCollectionUIOrigin)uIOrigin;

/**
 * User clicks to call concierge on an event page.
 *
 * @param eventID Required, must be NSString *.
*/
+ (void)trackEventConciergeCallWithEventID:(nonnull NSString *)eventID;

/**
 * Concierge modal is dismissed on an event page.
 *
 * @param eventID Required, must be NSString *.
*/
+ (void)trackEventConciergeDismissWithEventID:(nonnull NSString *)eventID;

/**
 * Concierge modal is shown on an event page.
 *
 * @param eventID Required, must be NSString *.
*/
+ (void)trackEventConciergeShowWithEventID:(nonnull NSString *)eventID;

/**
 * User toggles the fee selector.
 *
 * @param eventID Required, must be NSString *.
 * @param feeChoice Required, must be SGTrackerEventFeeFeeChoice. The user's choice for dispaying fees.
 * @param feeDefault Required, must be SGTrackerEventFeeFeeDefault. The default, SeatGeek-chosen fee display.
 * @param isDripPricing Optional, must be @(YES), @(NO), or nil. Are fees being hidden or not..
 * @param uIOrigin Optional, must be SGTrackerEventFeeUIOrigin or SGTrackerEventFeeUIOriginNone. UI where the user selects show fees..
*/
+ (void)trackEventFeeSelectWithEventID:(nonnull NSString *)eventID feeChoice:(SGTrackerEventFeeFeeChoice)feeChoice feeDefault:(SGTrackerEventFeeFeeDefault)feeDefault isDripPricing:(nullable NSNumber *)isDripPricing uIOrigin:(SGTrackerEventFeeUIOrigin)uIOrigin;

/**
 * User closes the event info modal.
 *
 * @param eventID Required, must be NSString *.
 * @param hasMap Required, must be BOOL.
 * @param isGa Required, must be BOOL.
*/
+ (void)trackEventInfoModalCloseWithEventID:(nonnull NSString *)eventID hasMap:(BOOL)hasMap isGa:(BOOL)isGa;

/**
 * User opens the event info modal.
 *
 * @param eventID Required, must be NSString *.
 * @param hasMap Required, must be BOOL.
 * @param isGa Required, must be BOOL.
*/
+ (void)trackEventInfoModalShowWithEventID:(nonnull NSString *)eventID hasMap:(BOOL)hasMap isGa:(BOOL)isGa;

/**
 * User taps an item on the event page.
 *
 * @param eventID Required, must be NSString *.
 * @param itemType Required, must be SGTrackerEventItemItemType. The item clicked on the event page.
*/
+ (void)trackEventItemClickWithEventID:(nonnull NSString *)eventID itemType:(SGTrackerEventItemItemType)itemType;

/**
 * User sees an item shown on the event page.
 *
 * @param eventID Required, must be NSString *.
 * @param itemType Required, must be SGTrackerEventItemItemType. The item is shown on the event page.
*/
+ (void)trackEventItemShowWithEventID:(nonnull NSString *)eventID itemType:(SGTrackerEventItemItemType)itemType;

/**
 * Peek on a listing on an event screen.
 *
 * @param eventID Required, must be NSString *.
 * @param hasMap Required, must be BOOL.
 * @param isGa Required, must be BOOL.
 * @param listingID Required, must be NSString *.
*/
+ (void)trackEventListing3DTouchPeekWithEventID:(nonnull NSString *)eventID hasMap:(BOOL)hasMap isGa:(BOOL)isGa listingID:(nonnull NSString *)listingID;

/**
 * Pop into a listing on an event screen.
 *
 * @param eventID Required, must be NSString *.
 * @param hasMap Required, must be BOOL.
 * @param isGa Required, must be BOOL.
 * @param listingID Required, must be NSString *.
*/
+ (void)trackEventListing3DTouchPopWithEventID:(nonnull NSString *)eventID hasMap:(BOOL)hasMap isGa:(BOOL)isGa listingID:(nonnull NSString *)listingID;

/**
 * Clicking to SG checkout on a listing on an event page.
 *
 * @param bestDealOrLowestPriceListing Optional, must be SGTrackerEventListingBestDealOrLowestPriceListing or SGTrackerEventListingBestDealOrLowestPriceListingNone. Is the clicked listing the best deal or lowest price (not sent in if neither).
 * @param checkoutType Optional, must be SGTrackerEventListingCheckoutType or SGTrackerEventListingCheckoutTypeNone.
 * @param clickID Optional, must be NSString * or nil.
 * @param dQ Required, must be NSNumber *.
 * @param eventDatetimeLocal Optional, must be NSString * or nil. Date/time of the event in the local timezone of the venue.
 * @param eventID Required, must be NSString *.
 * @param eventShortTitle Optional, must be NSString * or nil. A shortened title for the event.
 * @param eventTaxonomyName Optional, must be NSString * or nil. Type of event (broad category).
 * @param eventTitle Optional, must be NSString * or nil.
 * @param eventType Optional, must be NSString * or nil.
 * @param feeChoice Optional, must be SGTrackerEventListingFeeChoice or SGTrackerEventListingFeeChoiceNone. The user's choice for dispaying fees.
 * @param feeDefault Optional, must be SGTrackerEventListingFeeDefault or SGTrackerEventListingFeeDefaultNone. The default, SeatGeek-chosen fee display.
 * @param hasDealScore Optional, must be @(YES), @(NO), or nil. Is Deal Score enabled for this event..
 * @param hasMap Required, must be BOOL. Is the event mapped or not.  Note that this is not whether the listing is mapped..
 * @param hasNotes Required, must be BOOL. Whether the listing has seller or SeatGeek notes.
 * @param hasSavedPayment Optional, must be @(YES), @(NO), or nil. True if the checkout session has an account or client saved payment method available..
 * @param hasViewFromSeat Optional, must be @(YES), @(NO), or nil.
 * @param interactionMethod Optional, must be SGTrackerEventListingInteractionMethod or SGTrackerEventListingInteractionMethodNone. Hardware-specific description of how the action was invoked if other than with the default tap or click.
 * @param isEticket Required, must be BOOL.
 * @param isGa Required, must be BOOL. Is the event General Admission.
 * @param isVerified Optional, must be @(YES), @(NO), or nil. is this listing verified.
 * @param listingID Required, must be NSString *.
 * @param listingsDisplayOrientation Optional, must be SGTrackerEventListingListingsDisplayOrientation or SGTrackerEventListingListingsDisplayOrientationNone. Details if the listings shown were displayed in a horizontal list or vertical list.
 * @param marketApplePayEligible Required, must be BOOL. Is the market eligible for payment using Apple Pay, independent of whether the user has Apple Pay set up..
 * @param marketName Required, must be NSString *.
 * @param paymentType Optional, must be SGTrackerEventListingPaymentType or SGTrackerEventListingPaymentTypeNone.
 * @param performerID Optional, must be NSString * or nil.
 * @param performerName Optional, must be NSString * or nil.
 * @param performerType Optional, must be NSString * or nil.
 * @param pricePerTicket Required, must be NSNumber *. The price the user saw and clicked on, regardless of all-in or base pricing settings.
 * @param promocodeEligible Required, must be BOOL. Whether the listing is eligible for purchase with promocodes.
 * @param quantity Required, must be NSInteger. The quantity selected before entering checkout. This may be from an explict user choice or a default..
 * @param salesMode Optional, must be SGTrackerEventListingSalesMode or SGTrackerEventListingSalesModeNone. The main sales mode that the inventory of this event is in (best available, hybrid best available, interactive seat mode). Mainly concerns primary inventory.
 * @param sortType Optional, must be SGTrackerEventListingSortType or SGTrackerEventListingSortTypeNone. The user's choice for sorting listings.  Not sent if there is no sort option (eg. General Admission).
 * @param uIOrigin Optional, must be SGTrackerEventListingUIOrigin or SGTrackerEventListingUIOriginNone. Short identifier for the part of the UI from which the user clicked to checkout on a listing from.
 * @param userApplePayEligible Required, must be BOOL. Whether the device is capable and set up for using Apple Pay, independent of whetherthe market is Apple Pay compatible..
 * @param venueCity Optional, must be NSString * or nil.
 * @param venueID Optional, must be NSString * or nil.
 * @param venueName Optional, must be NSString * or nil.
 * @param venueState Optional, must be NSString * or nil.
 * @param viewMode Optional, must be SGTrackerEventListingViewMode or SGTrackerEventListingViewModeNone.
 * @param viewType Optional, must be NSString * or nil. Distinguishes between primary and standard event pages.
*/
+ (void)trackEventListingCheckoutWithBestDealOrLowestPriceListing:(SGTrackerEventListingBestDealOrLowestPriceListing)bestDealOrLowestPriceListing checkoutType:(SGTrackerEventListingCheckoutType)checkoutType clickID:(nullable NSString *)clickID dQ:(nonnull NSNumber *)dQ eventDatetimeLocal:(nullable NSString *)eventDatetimeLocal eventID:(nonnull NSString *)eventID eventShortTitle:(nullable NSString *)eventShortTitle eventTaxonomyName:(nullable NSString *)eventTaxonomyName eventTitle:(nullable NSString *)eventTitle eventType:(nullable NSString *)eventType feeChoice:(SGTrackerEventListingFeeChoice)feeChoice feeDefault:(SGTrackerEventListingFeeDefault)feeDefault hasDealScore:(nullable NSNumber *)hasDealScore hasMap:(BOOL)hasMap hasNotes:(BOOL)hasNotes hasSavedPayment:(nullable NSNumber *)hasSavedPayment hasViewFromSeat:(nullable NSNumber *)hasViewFromSeat interactionMethod:(SGTrackerEventListingInteractionMethod)interactionMethod isEticket:(BOOL)isEticket isGa:(BOOL)isGa isVerified:(nullable NSNumber *)isVerified listingID:(nonnull NSString *)listingID listingsDisplayOrientation:(SGTrackerEventListingListingsDisplayOrientation)listingsDisplayOrientation marketApplePayEligible:(BOOL)marketApplePayEligible marketName:(nonnull NSString *)marketName paymentType:(SGTrackerEventListingPaymentType)paymentType performerID:(nullable NSString *)performerID performerName:(nullable NSString *)performerName performerType:(nullable NSString *)performerType pricePerTicket:(nonnull NSNumber *)pricePerTicket promocodeEligible:(BOOL)promocodeEligible quantity:(NSInteger)quantity salesMode:(SGTrackerEventListingSalesMode)salesMode sortType:(SGTrackerEventListingSortType)sortType uIOrigin:(SGTrackerEventListingUIOrigin)uIOrigin userApplePayEligible:(BOOL)userApplePayEligible venueCity:(nullable NSString *)venueCity venueID:(nullable NSString *)venueID venueName:(nullable NSString *)venueName venueState:(nullable NSString *)venueState viewMode:(SGTrackerEventListingViewMode)viewMode viewType:(nullable NSString *)viewType;

/**
 * Clicking to 3rd party checkout from a ticket listing.
 *
 * @param dQ Required, must be NSNumber *.
 * @param eventDatetimeLocal Optional, must be NSString * or nil. Date/time of the event in the local timezone of the venue.
 * @param eventID Required, must be NSString *.
 * @param eventShortTitle Optional, must be NSString * or nil. A shortened title for the event.
 * @param eventTaxonomyName Optional, must be NSString * or nil. Type of event (broad category).
 * @param eventTitle Optional, must be NSString * or nil. The title of the event.
 * @param eventType Optional, must be NSString * or nil. Type of event (subcategory).
 * @param hasViewFromSeat Required, must be BOOL.
 * @param interactionMethod Optional, must be SGTrackerEventListingInteractionMethod or SGTrackerEventListingInteractionMethodNone. Hardware-specific description of how the action was invoked if other than with the default tap or click.
 * @param isEticket Required, must be BOOL.
 * @param listingID Required, must be NSString *.
 * @param marketName Required, must be NSString *.
 * @param paymentType Optional, must be SGTrackerEventListingPaymentType or SGTrackerEventListingPaymentTypeNone.
 * @param performerName Optional, must be NSString * or nil. Performer name.
 * @param quantity Required, must be NSInteger.
 * @param totalPrice Optional, must be NSNumber * or nil.
 * @param uIOrigin Optional, must be SGTrackerEventListingUIOrigin or SGTrackerEventListingUIOriginNone. Short identifier for the part of the UI from which the checkout was initiated.
 * @param venueCity Optional, must be NSString * or nil.
 * @param venueName Optional, must be NSString * or nil.
 * @param venueState Optional, must be NSString * or nil.
*/
+ (void)trackEventListingCheckoutExternalWithDQ:(nonnull NSNumber *)dQ eventDatetimeLocal:(nullable NSString *)eventDatetimeLocal eventID:(nonnull NSString *)eventID eventShortTitle:(nullable NSString *)eventShortTitle eventTaxonomyName:(nullable NSString *)eventTaxonomyName eventTitle:(nullable NSString *)eventTitle eventType:(nullable NSString *)eventType hasViewFromSeat:(BOOL)hasViewFromSeat interactionMethod:(SGTrackerEventListingInteractionMethod)interactionMethod isEticket:(BOOL)isEticket listingID:(nonnull NSString *)listingID marketName:(nonnull NSString *)marketName paymentType:(SGTrackerEventListingPaymentType)paymentType performerName:(nullable NSString *)performerName quantity:(NSInteger)quantity totalPrice:(nullable NSNumber *)totalPrice uIOrigin:(SGTrackerEventListingUIOrigin)uIOrigin venueCity:(nullable NSString *)venueCity venueName:(nullable NSString *)venueName venueState:(nullable NSString *)venueState;

/**
 * User taps a listing on the event screen.
 *
 * @param displayPrice Required, must be NSInteger.
 * @param eventID Required, must be NSString *.
 * @param eventIndicatesResales Required, must be BOOL. Whether the event is disambiguating primary sales vs. resales (as per `listings.primary_listing_filter.mark_primary_listings`).
 * @param hasSeatDetails Required, must be BOOL.
 * @param hasVfs Required, must be BOOL.
 * @param inventoryType Required, must be SGTrackerEventListingInventoryType.
 * @param isPrimary Required, must be BOOL. Whether the listing's market is primary (as per `listings.market.characteristics.is_primary`).
 * @param listingID Required, must be NSString *.
 * @param listingsDisplayOrientation Required, must be SGTrackerEventListingListingsDisplayOrientation. Details if the listings shown were displayed in a horizontal list or vertical list.
 * @param row Optional, must be NSString * or nil.
 * @param salesMode Optional, must be SGTrackerEventListingSalesMode or SGTrackerEventListingSalesModeNone. The main sales mode that the inventory of this event is in (best available, hybrid best available, interactive seat mode). Mainly concerns primary inventory.
 * @param section Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerEventListingUIOrigin or SGTrackerEventListingUIOriginNone. Short identifier for the part of the UI from which the user clicked to a listing from.
*/
+ (void)trackEventListingClickWithDisplayPrice:(NSInteger)displayPrice eventID:(nonnull NSString *)eventID eventIndicatesResales:(BOOL)eventIndicatesResales hasSeatDetails:(BOOL)hasSeatDetails hasVfs:(BOOL)hasVfs inventoryType:(SGTrackerEventListingInventoryType)inventoryType isPrimary:(BOOL)isPrimary listingID:(nonnull NSString *)listingID listingsDisplayOrientation:(SGTrackerEventListingListingsDisplayOrientation)listingsDisplayOrientation row:(nullable NSString *)row salesMode:(SGTrackerEventListingSalesMode)salesMode section:(nullable NSString *)section uIOrigin:(SGTrackerEventListingUIOrigin)uIOrigin;

/**
 * Listing (not 'Buy' button) is tapped from a listing row.
 *
 * @param dQ Required, must be NSNumber *.
 * @param eventDatetimeLocal Optional, must be NSString * or nil. Date/time of the event in the local timezone of the venue.
 * @param eventID Required, must be NSString *.
 * @param eventShortTitle Optional, must be NSString * or nil. A shortened title for the event.
 * @param eventTaxonomyName Optional, must be NSString * or nil. Type of event (broad category).
 * @param eventTitle Optional, must be NSString * or nil. The title of the event.
 * @param eventType Optional, must be NSString * or nil. Type of event (subcategory).
 * @param feeChoice Optional, must be SGTrackerEventListingFeeChoice or SGTrackerEventListingFeeChoiceNone. The user's choice for dispaying fees.
 * @param hasDealScore Optional, must be @(YES), @(NO), or nil. Is Deal Score enabled for this event..
 * @param hasDealScoreHidden Optional, must be @(YES), @(NO), or nil. Is Deal Score hidden for this listing (eg: only showing amazing - good rating)..
 * @param hasMap Required, must be BOOL. Is the event mapped or not.  Note that this is not whether the listing is mapped..
 * @param hasNotes Required, must be BOOL. Whether the listing has seller or SeatGeek notes.
 * @param hasSeatInfo Optional, must be @(YES), @(NO), or nil.
 * @param hasViewFromSeat Required, must be BOOL.
 * @param inventoryType Required, must be SGTrackerEventListingInventoryType.
 * @param isEticket Required, must be BOOL.
 * @param isGa Required, must be BOOL. Is the event General Admission.
 * @param isVerified Optional, must be @(YES), @(NO), or nil. is this listing verified.
 * @param listingID Required, must be NSString *.
 * @param marketApplePayEligible Required, must be BOOL. Is the market eligible for payment using Apple Pay, independent of whether the user has Apple Pay set up..
 * @param marketGooglePayEligible Optional, must be @(YES), @(NO), or nil. Is the market eligible for payment using Google Pay, independent of whether the user has Google Pay set up..
 * @param marketName Required, must be NSString *. The market name.  Note that this is not the display_name used in client UIs..
 * @param numListings Optional, must be NSInteger or NSNotFound. The number of listings shown to the user..
 * @param performerName Optional, must be NSString * or nil. Performer name.
 * @param promocodeEligible Required, must be BOOL. Whether the listing is eligible for purchase with promocodes.
 * @param quantity Required, must be NSInteger.
 * @param sortType Optional, must be SGTrackerEventListingSortType or SGTrackerEventListingSortTypeNone. The user's choice for sorting listings.  Not sent if there is no sort option (eg. General Admission).
 * @param totalPrice Required, must be NSNumber *.
 * @param userApplePayEligible Required, must be BOOL. Whether the device is capable and set up for using Apple Pay, independent of whetherthe market is Apple Pay compatible..
 * @param userGooglePayEligible Optional, must be @(YES), @(NO), or nil. Whether the device is capable and set up for using Google Pay, independent of whetherthe market is Google Pay compatible..
 * @param venueCity Optional, must be NSString * or nil.
 * @param venueName Optional, must be NSString * or nil.
 * @param venueState Optional, must be NSString * or nil.
 * @param viewMode Optional, must be SGTrackerEventListingViewMode or SGTrackerEventListingViewModeNone.
 * @param viewType Optional, must be NSString * or nil. Distinguishes between primary and standard event pages.
*/
+ (void)trackEventListingShowWithDQ:(nonnull NSNumber *)dQ eventDatetimeLocal:(nullable NSString *)eventDatetimeLocal eventID:(nonnull NSString *)eventID eventShortTitle:(nullable NSString *)eventShortTitle eventTaxonomyName:(nullable NSString *)eventTaxonomyName eventTitle:(nullable NSString *)eventTitle eventType:(nullable NSString *)eventType feeChoice:(SGTrackerEventListingFeeChoice)feeChoice hasDealScore:(nullable NSNumber *)hasDealScore hasDealScoreHidden:(nullable NSNumber *)hasDealScoreHidden hasMap:(BOOL)hasMap hasNotes:(BOOL)hasNotes hasSeatInfo:(nullable NSNumber *)hasSeatInfo hasViewFromSeat:(BOOL)hasViewFromSeat inventoryType:(SGTrackerEventListingInventoryType)inventoryType isEticket:(BOOL)isEticket isGa:(BOOL)isGa isVerified:(nullable NSNumber *)isVerified listingID:(nonnull NSString *)listingID marketApplePayEligible:(BOOL)marketApplePayEligible marketGooglePayEligible:(nullable NSNumber *)marketGooglePayEligible marketName:(nonnull NSString *)marketName numListings:(NSInteger)numListings performerName:(nullable NSString *)performerName promocodeEligible:(BOOL)promocodeEligible quantity:(NSInteger)quantity sortType:(SGTrackerEventListingSortType)sortType totalPrice:(nonnull NSNumber *)totalPrice userApplePayEligible:(BOOL)userApplePayEligible userGooglePayEligible:(nullable NSNumber *)userGooglePayEligible venueCity:(nullable NSString *)venueCity venueName:(nullable NSString *)venueName venueState:(nullable NSString *)venueState viewMode:(SGTrackerEventListingViewMode)viewMode viewType:(nullable NSString *)viewType;

/**
 * User collapses the event listings bottomsheet.
 *
 * @param eventID Required, must be NSString *.
*/
+ (void)trackEventListingsBottomsheetCollapseWithEventID:(nonnull NSString *)eventID;

/**
 * User expands the event listings bottomsheet.
 *
 * @param eventID Required, must be NSString *.
*/
+ (void)trackEventListingsBottomsheetExpandWithEventID:(nonnull NSString *)eventID;

/**
 * Error retrieving listings from GET /event_listings_v2.
 *
 * @param errorCode Optional, must be NSInteger or NSNotFound.
 * @param errorMessage Optional, must be NSString * or nil.
 * @param eventID Required, must be NSString *.
*/
+ (void)trackEventListingsErrorWithErrorCode:(NSInteger)errorCode errorMessage:(nullable NSString *)errorMessage eventID:(nonnull NSString *)eventID;

/**
 * User changes the listings filters on the event screen.
 *
 * @param accessCode Optional, must be NSString * or nil.
 * @param appliedFromCollection Required, must be BOOL. Denotes if a filter was applied from a collection being selected.
 * @param deliveryMethod Optional, must be SGTrackerEventListingsDeliveryMethod or SGTrackerEventListingsDeliveryMethodNone. The delivery method chosen, if the delivery method filter changed.
 * @param eventID Required, must be NSString *.
 * @param feeChoice Optional, must be SGTrackerEventListingsFeeChoice or SGTrackerEventListingsFeeChoiceNone. The user's choice for displaying fees, if the price filter changed.
 * @param filterMultiSelection Optional, must be NSString * or nil. Contains all of the values a user applied in a multi-select filter (e.g ada, package filter types) comma delimited.
 * @param filterType Required, must be SGTrackerEventListingsFilterType.
 * @param isPrimeOnly Optional, must be @(YES), @(NO), or nil. Whether the user filtered for prime listings.
 * @param obstructedViewChoice Optional, must be SGTrackerEventListingsObstructedViewChoice or SGTrackerEventListingsObstructedViewChoiceNone. Whether the user filtered out obstructed views.
 * @param priceFilterChoice Optional, must be SGTrackerEventListingsPriceFilterChoice or SGTrackerEventListingsPriceFilterChoiceNone. Whether the user manually filtered price or used the slider.
 * @param priceLower Optional, must be NSNumber * or nil. The lower bound chosen for price, if the price filter changed.
 * @param priceUpper Optional, must be NSNumber * or nil. The upper bound chosen for price, if the price filter changed.
 * @param primaryResaleChoice Optional, must be SGTrackerEventListingsPrimaryResaleChoice or SGTrackerEventListingsPrimaryResaleChoiceNone. Whether the user filtered for primary tickets only or primary and official resale, if the primary_resale filter changed.
 * @param promocodeChoice Optional, must be SGTrackerEventListingsPromocodeChoice or SGTrackerEventListingsPromocodeChoiceNone. The user's choice for promo code eligibility, if the promo code filter changed.
 * @param quantity Optional, must be NSInteger or NSNotFound. The quantity chosen, if the quantity filter changed.
 * @param uIOrigin Required, must be SGTrackerEventListingsUIOrigin.
*/
+ (void)trackEventListingsFilterWithAccessCode:(nullable NSString *)accessCode appliedFromCollection:(BOOL)appliedFromCollection deliveryMethod:(SGTrackerEventListingsDeliveryMethod)deliveryMethod eventID:(nonnull NSString *)eventID feeChoice:(SGTrackerEventListingsFeeChoice)feeChoice filterMultiSelection:(nullable NSString *)filterMultiSelection filterType:(SGTrackerEventListingsFilterType)filterType isPrimeOnly:(nullable NSNumber *)isPrimeOnly obstructedViewChoice:(SGTrackerEventListingsObstructedViewChoice)obstructedViewChoice priceFilterChoice:(SGTrackerEventListingsPriceFilterChoice)priceFilterChoice priceLower:(nullable NSNumber *)priceLower priceUpper:(nullable NSNumber *)priceUpper primaryResaleChoice:(SGTrackerEventListingsPrimaryResaleChoice)primaryResaleChoice promocodeChoice:(SGTrackerEventListingsPromocodeChoice)promocodeChoice quantity:(NSInteger)quantity uIOrigin:(SGTrackerEventListingsUIOrigin)uIOrigin;

/**
 * Fires the first time a user scrolls through horizontal listings on the event page.
 *
 * @param eventID Required, must be NSString *.
*/
+ (void)trackEventListingsHorizontalScrollFirstWithEventID:(nonnull NSString *)eventID;

/**
 * Listings show in vertical or horizontal orientation.
 *
 * @param eventID Required, must be NSString *.
 * @param listingsDisplayOrientation Required, must be SGTrackerEventListingsListingsDisplayOrientation. Details if the listings shown were displayed in a horizontal list or vertical list.
 * @param showMethod Required, must be SGTrackerEventListingsShowMethod. Details how the listings show was triggered.
 * @param sortType Optional, must be SGTrackerEventListingsSortType or SGTrackerEventListingsSortTypeNone.
*/
+ (void)trackEventListingsShowWithEventID:(nonnull NSString *)eventID listingsDisplayOrientation:(SGTrackerEventListingsListingsDisplayOrientation)listingsDisplayOrientation showMethod:(SGTrackerEventListingsShowMethod)showMethod sortType:(SGTrackerEventListingsSortType)sortType;

/**
 * User changes the listings sort.
 *
 * @param eventID Required, must be NSString *.
 * @param sortOrder Required, must be SGTrackerEventListingsSortOrder.
 * @param sortType Required, must be SGTrackerEventListingsSortType.
 * @param uIOrigin Required, must be SGTrackerEventListingsUIOrigin. Short identifier for the part of the UI from which the user applied a listing sort order.
*/
+ (void)trackEventListingsSortWithEventID:(nonnull NSString *)eventID sortOrder:(SGTrackerEventListingsSortOrder)sortOrder sortType:(SGTrackerEventListingsSortType)sortType uIOrigin:(SGTrackerEventListingsUIOrigin)uIOrigin;

/**
 * Successful response from GET /event_listings_v2.
 *
 * @param eventID Required, must be NSString *.
 * @param primaryResaleChoice Optional, must be SGTrackerEventListingsPrimaryResaleChoice or SGTrackerEventListingsPrimaryResaleChoiceNone. Whether the user will see 1. primary tickets only or 2. primary and official resale upon initial view.
 * @param totalListings Required, must be NSInteger. Total number of listings returned in the listings response.
 * @param totalListingsWithSeatDetails Required, must be NSInteger. Total number of listings returned in the listings response that have at least one seat detail.
 * @param totalListingsWithVfs Required, must be NSInteger. Total number of listings returned in the listings response that have a view from seat image.
*/
+ (void)trackEventListingsSuccessWithEventID:(nonnull NSString *)eventID primaryResaleChoice:(SGTrackerEventListingsPrimaryResaleChoice)primaryResaleChoice totalListings:(NSInteger)totalListings totalListingsWithSeatDetails:(NSInteger)totalListingsWithSeatDetails totalListingsWithVfs:(NSInteger)totalListingsWithVfs;

/**
 * Fires the first time a user scrolls through vertical listings on the event page.
 *
 * @param eventID Required, must be NSString *.
*/
+ (void)trackEventListingsVerticalScrollFirstWithEventID:(nonnull NSString *)eventID;

/**
 * Fires the first time a user pans on the event page venue map. Panning is defined as a user moving their view of the venue map and does not include zooming.
 *
 * @param eventID Required, must be NSString *.
 * @param venueConfigID Required, must be NSString *.
*/
+ (void)trackEventMapPanFirstWithEventID:(nonnull NSString *)eventID venueConfigID:(nonnull NSString *)venueConfigID;

/**
 * Fires the first time a user zooms on the event page venue map.
 *
 * @param eventID Required, must be NSString *.
 * @param venueConfigID Required, must be NSString *.
*/
+ (void)trackEventMapZoomFirstWithEventID:(nonnull NSString *)eventID venueConfigID:(nonnull NSString *)venueConfigID;

/**
 * User toggles a premium package.
 *
 * @param activityType Required, must be NSString *. The updated state of the toggle.
 * @param displayValue Required, must be NSString *. The title of the package the user toggled.
 * @param eventID Required, must be NSString *.
 * @param itemType Required, must be NSString *. The type of premium package a user toggled.
*/
+ (void)trackEventPackageToggleWithActivityType:(nonnull NSString *)activityType displayValue:(nonnull NSString *)displayValue eventID:(nonnull NSString *)eventID itemType:(nonnull NSString *)itemType;

/**
 * Row marker is tapped on event map.
 *
 * @param dQ Required, must be NSNumber *.
 * @param eventID Required, must be NSString *.
 * @param hasPriceMarker Optional, must be @(YES), @(NO), or nil. Whether or not this row's map marker also had a price marker.
 * @param hasViewFromRow Required, must be BOOL.
 * @param interactionMethod Optional, must be SGTrackerEventRowInteractionMethod or SGTrackerEventRowInteractionMethodNone. Hardware-specific description of how the action was invoked if other than with the default tap or click.
 * @param inventoryType Optional, must be SGTrackerEventRowInventoryType or SGTrackerEventRowInventoryTypeNone. A row may have many types of inventory, but there is only one map marker (i.e. deal score dot or Prime sparkle) shown to summarize this row.
 * @param row Required, must be NSString *.
 * @param section Required, must be NSString *.
*/
+ (void)trackEventRowShowWithDQ:(nonnull NSNumber *)dQ eventID:(nonnull NSString *)eventID hasPriceMarker:(nullable NSNumber *)hasPriceMarker hasViewFromRow:(BOOL)hasViewFromRow interactionMethod:(SGTrackerEventRowInteractionMethod)interactionMethod inventoryType:(SGTrackerEventRowInventoryType)inventoryType row:(nonnull NSString *)row section:(nonnull NSString *)section;

/**
 * User opens the Seat Selection Modal from listing detail.
 *
 * @param eventID Required, must be NSString *.
*/
+ (void)trackEventSeatSelectionModalShowWithEventID:(nonnull NSString *)eventID;

/**
 * Section marker is tapped on event map.
 *
 * @param dQ Required, must be NSNumber *.
 * @param eventID Required, must be NSString *.
 * @param hasPriceMarker Optional, must be @(YES), @(NO), or nil. Whether or not this section's map marker also had a price marker.
 * @param hasViewFromSection Required, must be BOOL.
 * @param interactionMethod Optional, must be SGTrackerEventSectionInteractionMethod or SGTrackerEventSectionInteractionMethodNone. Hardware-specific description of how the action was invoked if other than with the default tap or click.
 * @param inventoryType Optional, must be SGTrackerEventSectionInventoryType or SGTrackerEventSectionInventoryTypeNone. A section may have many types of inventory, but there is only one map marker (i.e. deal score dot or Prime sparkle) shown to summarize the section.
 * @param section Required, must be NSString *.
*/
+ (void)trackEventSectionShowWithDQ:(nonnull NSNumber *)dQ eventID:(nonnull NSString *)eventID hasPriceMarker:(nullable NSNumber *)hasPriceMarker hasViewFromSection:(BOOL)hasViewFromSection interactionMethod:(SGTrackerEventSectionInteractionMethod)interactionMethod inventoryType:(SGTrackerEventSectionInventoryType)inventoryType section:(nonnull NSString *)section;

/**
 * User taps to share an event.
 *
 * @param eventID Required, must be NSString *.
 * @param listingID Optional, must be NSString * or nil. Included only if the share button was on a listing detail view.
 * @param uIOrigin Optional, must be SGTrackerEventShareUIOrigin or SGTrackerEventShareUIOriginNone. Short identifier for the part of the UI from which the user shared the event.
*/
+ (void)trackEventShareWithEventID:(nonnull NSString *)eventID listingID:(nullable NSString *)listingID uIOrigin:(SGTrackerEventShareUIOrigin)uIOrigin;

/**
 * User cancels sharing of an event.
 *
 * @param activityType Optional, must be NSString * or nil. Defined by third party apps or by the OS for built-in types, and ommitted if the user canceled sharing before making a selection.
 * @param eventID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerEventShareUIOrigin or SGTrackerEventShareUIOriginNone. Short identifier for the part of the UI from which the user shared the event.
*/
+ (void)trackEventShareCancelWithActivityType:(nullable NSString *)activityType eventID:(nonnull NSString *)eventID uIOrigin:(SGTrackerEventShareUIOrigin)uIOrigin;

/**
 * User finishes sharing of an event.
 *
 * @param activityType Required, must be NSString *. Defined by third party apps or by the OS for built-in types.
 * @param eventID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerEventShareUIOrigin or SGTrackerEventShareUIOriginNone. Short identifier for the part of the UI from which the user shared the event.
*/
+ (void)trackEventShareCreateWithActivityType:(nonnull NSString *)activityType eventID:(nonnull NSString *)eventID uIOrigin:(SGTrackerEventShareUIOrigin)uIOrigin;

/**
 * An event screen is shown.
 *
 * @param accessCode Optional, must be NSString * or nil.
 * @param daysUntilEvent Optional, must be NSInteger or NSNotFound.
 * @param eventDatetimeLocal Optional, must be NSString * or nil. Date/time of the event in the local timezone of the venue.
 * @param eventID Required, must be NSString *.
 * @param eventShortTitle Optional, must be NSString * or nil. A shortened title for the event.
 * @param eventTaxonomyName Optional, must be NSString * or nil. Type of event (broad category).
 * @param eventTitle Optional, must be NSString * or nil.
 * @param eventType Optional, must be NSString * or nil.
 * @param feeChoice Optional, must be SGTrackerEventFeeChoice or SGTrackerEventFeeChoiceNone. The user's choice for displaying fees, if the price filter changed.
 * @param hasDealScore Optional, must be @(YES), @(NO), or nil. Is Deal Score enabled for this event..
 * @param hasMap Required, must be BOOL.
 * @param isDripPricing Optional, must be @(YES), @(NO), or nil. Are fees being hidden or not..
 * @param isGa Required, must be BOOL.
 * @param isHybridUI Optional, must be @(YES), @(NO), or nil. This field is for tracking the hybrid event screen showing vertical and horizontal listings.
 * @param isSgo Optional, must be @(YES), @(NO), or nil.
 * @param numListings Optional, must be NSInteger or NSNotFound.
 * @param performerID Optional, must be NSString * or nil.
 * @param performerName Optional, must be NSString * or nil.
 * @param performerType Optional, must be NSString * or nil.
 * @param salesMode Optional, must be SGTrackerEventSalesMode or SGTrackerEventSalesModeNone. The main sales mode that the inventory of this event is in (best available, hybrid best available, interactive seat mode). Mainly concerns primary inventory.
 * @param venueCity Optional, must be NSString * or nil.
 * @param venueConfigID Optional, must be NSString * or nil.
 * @param venueID Optional, must be NSString * or nil.
 * @param venueName Optional, must be NSString * or nil.
 * @param venueState Optional, must be NSString * or nil.
 * @param viewType Optional, must be NSString * or nil. Distinguishes between primary and standard event pages.
*/
+ (void)trackEventShowWithAccessCode:(nullable NSString *)accessCode daysUntilEvent:(NSInteger)daysUntilEvent eventDatetimeLocal:(nullable NSString *)eventDatetimeLocal eventID:(nonnull NSString *)eventID eventShortTitle:(nullable NSString *)eventShortTitle eventTaxonomyName:(nullable NSString *)eventTaxonomyName eventTitle:(nullable NSString *)eventTitle eventType:(nullable NSString *)eventType feeChoice:(SGTrackerEventFeeChoice)feeChoice hasDealScore:(nullable NSNumber *)hasDealScore hasMap:(BOOL)hasMap isDripPricing:(nullable NSNumber *)isDripPricing isGa:(BOOL)isGa isHybridUI:(nullable NSNumber *)isHybridUI isSgo:(nullable NSNumber *)isSgo numListings:(NSInteger)numListings performerID:(nullable NSString *)performerID performerName:(nullable NSString *)performerName performerType:(nullable NSString *)performerType salesMode:(SGTrackerEventSalesMode)salesMode venueCity:(nullable NSString *)venueCity venueConfigID:(nullable NSString *)venueConfigID venueID:(nullable NSString *)venueID venueName:(nullable NSString *)venueName venueState:(nullable NSString *)venueState viewType:(nullable NSString *)viewType;

/**
 * User closes the Filters sheet (not when the Sort modal is closed).
 *
 * @param eventID Required, must be NSString *.
 * @param hasMap Required, must be BOOL.
 * @param isGa Required, must be BOOL.
*/
+ (void)trackEventSortAndFilterModalCloseWithEventID:(nonnull NSString *)eventID hasMap:(BOOL)hasMap isGa:(BOOL)isGa;

/**
 * User opens the Filters sheet (not when the Sort modal is opened).
 *
 * @param eventID Required, must be NSString *.
 * @param hasMap Required, must be BOOL.
 * @param isGa Required, must be BOOL.
*/
+ (void)trackEventSortAndFilterModalShowWithEventID:(nonnull NSString *)eventID hasMap:(BOOL)hasMap isGa:(BOOL)isGa;

/**
 * A user participates in an A/B test.
 *
 * @param bucket Required, must be NSString *. The experiment group into which the user was placed.
 * @param experiment Required, must be NSString *. The name of the experiment.
*/
+ (void)trackExperimentParticipateWithBucket:(nonnull NSString *)bucket experiment:(nonnull NSString *)experiment;

/**
 * A user participates in an A/B test.
 *
 * @param bucket Required, must be NSString *. The experiment group into which the user was placed.
 * @param clientID Optional, must be NSString * or nil. Identifies the client who made the server request.
 * @param eventID Optional, must be NSString * or nil. event id for event-based experiments.
 * @param experiment Required, must be NSString *. The name of the experiment.
 * @param scrapeUuid Optional, must be NSString * or nil. scrape uuid for listing-based experiments.
 * @param sixpackClientID Optional, must be NSString * or nil. Identifies this user, for a specific client in sevenpack experiments.
 * @param ticketGroupID Optional, must be NSString * or nil. ticket group for ticket group-based experiments.
 * @param userID Optional, must be NSNumber * or nil. Identifies this user.
*/
+ (void)trackExperimentParticipateServerWithBucket:(nonnull NSString *)bucket clientID:(nullable NSString *)clientID eventID:(nullable NSString *)eventID experiment:(nonnull NSString *)experiment scrapeUuid:(nullable NSString *)scrapeUuid sixpackClientID:(nullable NSString *)sixpackClientID ticketGroupID:(nullable NSString *)ticketGroupID userID:(nullable NSNumber *)userID;

/**
 * User taps to view information for contacting SG.
 *
 * @param uIOrigin Optional, must be SGTrackerHelpContactUIOrigin or SGTrackerHelpContactUIOriginNone.
*/
+ (void)trackHelpContactClickWithUIOrigin:(SGTrackerHelpContactUIOrigin)uIOrigin;

/**
 * The user loads the iMessage event sharing app extension.
*/
+ (void)trackiMessageShareShow;

/**
 * A user opens the initial screen of the iMessage app.
*/
+ (void)trackiMessageShow;

/**
 * The user loads the iMessage transfers app extension.
*/
+ (void)trackiMessageTransfersShow;

/**
 * User views the screen to enter seat and barcode values.
 *
 * @param eventID Required, must be NSString *.
 * @param eventTitle Optional, must be NSString * or nil.
 * @param performerID Optional, must be NSString * or nil.
 * @param performerName Optional, must be NSString * or nil.
 * @param quantity Optional, must be NSInteger or NSNotFound. The number of barcode values the user wishes to add.
 * @param row Optional, must be NSString * or nil. The row entered by the user in which the seats are located.
 * @param section Optional, must be NSString * or nil. The section selected by the user in which the seats are located.
 * @param ticketType Required, must be SGTrackerIngestionsBarcodesTicketType.
*/
+ (void)trackIngestionsBarcodesShowWithEventID:(nonnull NSString *)eventID eventTitle:(nullable NSString *)eventTitle performerID:(nullable NSString *)performerID performerName:(nullable NSString *)performerName quantity:(NSInteger)quantity row:(nullable NSString *)row section:(nullable NSString *)section ticketType:(SGTrackerIngestionsBarcodesTicketType)ticketType;

/**
 * Validation of seats and barcodes for a given event fails.
 *
 * @param errorMessage Required, must be NSString *.
 * @param eventID Required, must be NSString *.
 * @param eventTitle Optional, must be NSString * or nil.
 * @param performerID Optional, must be NSString * or nil.
 * @param performerName Optional, must be NSString * or nil.
 * @param quantity Optional, must be NSInteger or NSNotFound. The number of barcode values the user was attempting to add.
 * @param row Optional, must be NSString * or nil. The row entered by the user in which the seats are located.
 * @param section Optional, must be NSString * or nil. The section selected by the user in which the seats are located.
 * @param ticketType Required, must be SGTrackerIngestionsBarcodesTicketType.
*/
+ (void)trackIngestionsBarcodesValidateErrorWithErrorMessage:(nonnull NSString *)errorMessage eventID:(nonnull NSString *)eventID eventTitle:(nullable NSString *)eventTitle performerID:(nullable NSString *)performerID performerName:(nullable NSString *)performerName quantity:(NSInteger)quantity row:(nullable NSString *)row section:(nullable NSString *)section ticketType:(SGTrackerIngestionsBarcodesTicketType)ticketType;

/**
 * User submits seats and barcodes for validation for a given event.
 *
 * @param eventID Required, must be NSString *.
 * @param eventTitle Optional, must be NSString * or nil.
 * @param performerID Optional, must be NSString * or nil.
 * @param performerName Optional, must be NSString * or nil.
 * @param quantity Optional, must be NSInteger or NSNotFound. The number of barcode values the user is attempting to add.
 * @param row Optional, must be NSString * or nil. The row entered by the user in which the seats are located.
 * @param section Optional, must be NSString * or nil. The section selected by the user in which the seats are located.
 * @param ticketType Required, must be SGTrackerIngestionsBarcodesTicketType.
*/
+ (void)trackIngestionsBarcodesValidateSubmitWithEventID:(nonnull NSString *)eventID eventTitle:(nullable NSString *)eventTitle performerID:(nullable NSString *)performerID performerName:(nullable NSString *)performerName quantity:(NSInteger)quantity row:(nullable NSString *)row section:(nullable NSString *)section ticketType:(SGTrackerIngestionsBarcodesTicketType)ticketType;

/**
 * Validation of seats and barcodes for a given event is successful.
 *
 * @param eventID Required, must be NSString *.
 * @param eventTitle Optional, must be NSString * or nil.
 * @param performerID Optional, must be NSString * or nil.
 * @param performerName Optional, must be NSString * or nil.
 * @param quantity Optional, must be NSInteger or NSNotFound. The number of barcode values the user added.
 * @param row Optional, must be NSString * or nil. The row entered by the user in which the seats are located.
 * @param section Optional, must be NSString * or nil. The section selected by the user in which the seats are located.
 * @param ticketType Required, must be SGTrackerIngestionsBarcodesTicketType.
*/
+ (void)trackIngestionsBarcodesValidateSuccessWithEventID:(nonnull NSString *)eventID eventTitle:(nullable NSString *)eventTitle performerID:(nullable NSString *)performerID performerName:(nullable NSString *)performerName quantity:(NSInteger)quantity row:(nullable NSString *)row section:(nullable NSString *)section ticketType:(SGTrackerIngestionsBarcodesTicketType)ticketType;

/**
 * User views the events available for ingestion for a given performer.
 *
 * @param performerID Required, must be NSString *.
 * @param performerName Optional, must be NSString * or nil.
 * @param ticketType Required, must be SGTrackerIngestionsEventsTicketType.
 * @param totalEvents Required, must be NSInteger. The number of events selected for which the user will upload barcodes.
*/
+ (void)trackIngestionsEventsShowWithPerformerID:(nonnull NSString *)performerID performerName:(nullable NSString *)performerName ticketType:(SGTrackerIngestionsEventsTicketType)ticketType totalEvents:(NSInteger)totalEvents;

/**
 * Row for Safari/Mail/Desktop is tapped on help detail screen.
 *
 * @param ingestionMethod Required, must be NSString *.
 * @param ticketType Required, must be SGTrackerIngestionsHelpDetailTicketType. The type of ticket the user selected.
*/
+ (void)trackIngestionsHelpDetailShowWithIngestionMethod:(nonnull NSString *)ingestionMethod ticketType:(SGTrackerIngestionsHelpDetailTicketType)ticketType;

/**
 * Row for Safari/Mail/Desktop is tapped on detail screen.
*/
+ (void)trackIngestionsHelpShow;

/**
 * User selects sets events, quantity, row, or section for barcode ingestion.
 *
 * @param performerID Required, must be NSString *.
 * @param performerName Optional, must be NSString * or nil.
 * @param quantity Optional, must be NSInteger or NSNotFound. The number of barcode values the user wishes to add.
 * @param row Optional, must be NSString * or nil. The row entered by the user in which the seats are located.
 * @param section Optional, must be NSString * or nil. The section selected by the user in which the seats are located.
 * @param ticketType Required, must be SGTrackerIngestionsMetadataTicketType.
 * @param totalEvents Optional, must be NSInteger or NSNotFound. The number of events selected for which the user will upload barcodes.
*/
+ (void)trackIngestionsMetadataSelectWithPerformerID:(nonnull NSString *)performerID performerName:(nullable NSString *)performerName quantity:(NSInteger)quantity row:(nullable NSString *)row section:(nullable NSString *)section ticketType:(SGTrackerIngestionsMetadataTicketType)ticketType totalEvents:(NSInteger)totalEvents;

/**
 * User selects a performer from the ingestion performer search screen.
 *
 * @param performerID Required, must be NSString *.
 * @param performerName Optional, must be NSString * or nil.
 * @param ticketType Required, must be SGTrackerIngestionsPerformerTicketType.
*/
+ (void)trackIngestionsPerformerSearchSelectWithPerformerID:(nonnull NSString *)performerID performerName:(nullable NSString *)performerName ticketType:(SGTrackerIngestionsPerformerTicketType)ticketType;

/**
 * User views the performer search screen for barcode ingestion.
 *
 * @param ticketType Required, must be SGTrackerIngestionsPerformerTicketType.
*/
+ (void)trackIngestionsPerformerSearchShowWithTicketType:(SGTrackerIngestionsPerformerTicketType)ticketType;

/**
 * Server returns error where PDF failed to be successfully parsed by ticketparse.
 *
 * @param ingestionID Required, must be NSString *.
 * @param errorCode Optional, must be NSInteger or NSNotFound.
 * @param errorMessage Optional, must be NSString * or nil.
*/
+ (void)trackIngestionsProcessingErrorWithIngestionID:(nonnull NSString *)ingestionID errorCode:(NSInteger)errorCode errorMessage:(nullable NSString *)errorMessage;

/**
 * Server returns success where ticketparse successfully parses PDF.
 *
 * @param ingestionID Required, must be NSString *.
 * @param ticketGroupIDs Required, must be NSString *.
*/
+ (void)trackIngestionsProcessingSuccessWithIngestionID:(nonnull NSString *)ingestionID ticketGroupIDs:(nonnull NSString *)ticketGroupIDs;

/**
 * User views the barcode ingestion metadata screen.
 *
 * @param performerID Required, must be NSString *.
 * @param performerName Optional, must be NSString * or nil.
 * @param quantity Optional, must be NSInteger or NSNotFound.
 * @param row Optional, must be NSString * or nil.
 * @param section Optional, must be NSString * or nil.
 * @param ticketType Required, must be SGTrackerIngestionsSummaryTicketType.
 * @param totalEvents Optional, must be NSInteger or NSNotFound. The number of events selected for which the user will upload barcodes.
*/
+ (void)trackIngestionsSummaryShowWithPerformerID:(nonnull NSString *)performerID performerName:(nullable NSString *)performerName quantity:(NSInteger)quantity row:(nullable NSString *)row section:(nullable NSString *)section ticketType:(SGTrackerIngestionsSummaryTicketType)ticketType totalEvents:(NSInteger)totalEvents;

/**
 * Ticket failed to be uploaded to the server.
 *
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param ticketType Optional, must be SGTrackerIngestionsUploadTicketType or SGTrackerIngestionsUploadTicketTypeNone.
*/
+ (void)trackIngestionsUploadErrorWithErrorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage ticketType:(SGTrackerIngestionsUploadTicketType)ticketType;

/**
 * Ticket upload has begun.
 *
 * @param ticketType Required, must be SGTrackerIngestionsUploadTicketType.
*/
+ (void)trackIngestionsUploadStartWithTicketType:(SGTrackerIngestionsUploadTicketType)ticketType;

/**
 * Ticket upload has successfully completed.
 *
 * @param ingestionID Optional, must be NSString * or nil. The ingestion ID returned by the API. This is only expected to be present for PDF uploads..
 * @param ticketType Required, must be SGTrackerIngestionsUploadTicketType.
*/
+ (void)trackIngestionsUploadSuccessWithIngestionID:(nullable NSString *)ingestionID ticketType:(SGTrackerIngestionsUploadTicketType)ticketType;

/**
 * A landing page link is tapped.
 *
 * @param itemType Required, must be SGTrackerLandingPageItemItemType. The link or button that was clicked ie: find events, unlock promo code.
 * @param pageType Optional, must be NSString * or nil. Type of page action occurred on.
*/
+ (void)trackLandingPageItemClickWithItemType:(SGTrackerLandingPageItemItemType)itemType pageType:(nullable NSString *)pageType;

/**
 * A landing page is viewed.
 *
 * @param pageType Required, must be NSString *. Type of landing page action occurred on.
*/
+ (void)trackLandingPageShowWithPageType:(nonnull NSString *)pageType;

/**
 * DEPRECATED in favor of list_expand:click. User clicks to view a Buzzfeed list.
 *
 * @param listID Optional, must be NSString * or nil. The list id being clicked.
 * @param listQuery Optional, must be NSString * or nil. The query send to the Lists API.
 * @param listTag Optional, must be NSString * or nil. The list tag being clicked.
 * @param rank Optional, must be NSInteger or NSNotFound. The rank of the list being clicked.
 * @param searchQuery Optional, must be NSString * or nil. The search query.
 * @param totalResults Optional, must be NSInteger or NSNotFound. Size of the result set from which this list is being clicked.
 * @param uIOrigin Optional, must be SGTrackerListUIOrigin or SGTrackerListUIOriginNone. Short identifier for the part of the UI from which the user clicked to open the list.
*/
+ (void)trackListClickWithListID:(nullable NSString *)listID listQuery:(nullable NSString *)listQuery listTag:(nullable NSString *)listTag rank:(NSInteger)rank searchQuery:(nullable NSString *)searchQuery totalResults:(NSInteger)totalResults uIOrigin:(SGTrackerListUIOrigin)uIOrigin;

/**
 * User finishes scrolling a Buzzfeed list.
 *
 * @param endRank Required, must be NSInteger. The rank of the right most item in this list in the user's viewport.
 * @param isEnd Required, must be BOOL. Whether user has finished scrolling to the end of the list.
 * @param listID Required, must be NSString *. The list id being scrolled.
 * @param uIOrigin Optional, must be SGTrackerListUIOrigin or SGTrackerListUIOriginNone. Short identifier for the part of the UI from which the user viewed a list.
*/
+ (void)trackListEndScrollWithEndRank:(NSInteger)endRank isEnd:(BOOL)isEnd listID:(nonnull NSString *)listID uIOrigin:(SGTrackerListUIOrigin)uIOrigin;

/**
 * A list of SeatGeek events is shown, usually from the /events endpoint (not from Buzzfeed).
 *
 * @param filterType Optional, must be SGTrackerListEventsFilterType or SGTrackerListEventsFilterTypeNone. If the new list is being generated because of a filter, what filter was applied.
 * @param numberOfPaginations Required, must be NSInteger. The total number of paginations of events based on the response from the /events endpoint.
 * @param performerID Optional, must be NSString * or nil.
 * @param totalEvents Required, must be NSInteger. The total number of events available to show based on the 'total' field in the /events endpoints .
 * @param uIOrigin Required, must be SGTrackerListEventsUIOrigin. Short identifier for the part of the UI from which the user viewed a list.
 * @param viewType Optional, must be SGTrackerListEventsViewType or SGTrackerListEventsViewTypeNone. The viewing style for the list of events.
*/
+ (void)trackListEventsShowWithFilterType:(SGTrackerListEventsFilterType)filterType numberOfPaginations:(NSInteger)numberOfPaginations performerID:(nullable NSString *)performerID totalEvents:(NSInteger)totalEvents uIOrigin:(SGTrackerListEventsUIOrigin)uIOrigin viewType:(SGTrackerListEventsViewType)viewType;

/**
 * User interacts with a Buzzfeed list item..
 *
 * @param interactionMethod Required, must be SGTrackerListItemInteractionMethod. The kind of interaction with the list item. DEPRECATED interaction_method of 'click' in favor of event:click, performer:click, venue:click, and list_view:click; DEPRECATED interaction_method of 'scroll' in favor of list:scroll..
 * @param itemDataType Required, must be NSString *. The list item's data type.
 * @param itemID Optional, must be NSString * or nil. The list item's id.
 * @param itemStyleType Required, must be NSString *. The list item's style type.
 * @param itemType Required, must be NSString *. The list item's type.
 * @param listID Required, must be NSString *. The list id this item belongs to.
 * @param rank Required, must be NSInteger. The rank of the list item being interacted with.
 * @param uIOrigin Optional, must be SGTrackerListItemUIOrigin or SGTrackerListItemUIOriginNone. Short identifier for the part of the UI from which the user viewed a list.
*/
+ (void)trackListItemInteractWithInteractionMethod:(SGTrackerListItemInteractionMethod)interactionMethod itemDataType:(nonnull NSString *)itemDataType itemID:(nullable NSString *)itemID itemStyleType:(nonnull NSString *)itemStyleType itemType:(nonnull NSString *)itemType listID:(nonnull NSString *)listID rank:(NSInteger)rank uIOrigin:(SGTrackerListItemUIOrigin)uIOrigin;

/**
 * User scrolls a Buzzfeed list..
 *
 * @param endRank Required, must be NSInteger. The rank of the right most item in this list in the user's viewport.
 * @param isEnd Required, must be BOOL. Whether user has finished scrolling to the end of the list.
 * @param itemStyleType Required, must be NSString *. The list's style type. This will come from the server and be things like 'list_horizontal' and 'list_vertical'..
 * @param listID Required, must be NSString *. The list's ID'..
 * @param listKey Required, must be NSString *. The stable, human-readable identifier of the list..
 * @param listRank Optional, must be NSInteger or NSNotFound. The list's rank..
 * @param listTitle Required, must be NSString *. The name of the list as the user sees it..
 * @param maxItemsInView Required, must be NSInteger. The max number of items that can be shown in the list at any time..
*/
+ (void)trackListScrollWithEndRank:(NSInteger)endRank isEnd:(BOOL)isEnd itemStyleType:(nonnull NSString *)itemStyleType listID:(nonnull NSString *)listID listKey:(nonnull NSString *)listKey listRank:(NSInteger)listRank listTitle:(nonnull NSString *)listTitle maxItemsInView:(NSInteger)maxItemsInView;

/**
 * A Buzzfeed list is shown.
 *
 * @param absoluteRank Optional, must be NSInteger or NSNotFound. The absolute rank of the link within the parent..
 * @param listID Required, must be NSString *. The list id being shown.
 * @param listKey Optional, must be NSString * or nil. The stable, human-readable identifier of the list..
 * @param listStyleType Required, must be NSString *. The list style type being shown.
 * @param listTitle Optional, must be NSString * or nil. The name of the list as the user sees it..
 * @param performerID Optional, must be NSString * or nil. The performer id that was used to generate the contents of the list..
 * @param totalResults Required, must be NSInteger. The total number of items in the list being shown.
 * @param uIOrigin Optional, must be SGTrackerListUIOrigin or SGTrackerListUIOriginNone. Short identifier for the part of the UI from which the user viewed a list.
 * @param versionID Optional, must be NSString * or nil. The version id being shown.
*/
+ (void)trackListShowWithAbsoluteRank:(NSInteger)absoluteRank listID:(nonnull NSString *)listID listKey:(nullable NSString *)listKey listStyleType:(nonnull NSString *)listStyleType listTitle:(nullable NSString *)listTitle performerID:(nullable NSString *)performerID totalResults:(NSInteger)totalResults uIOrigin:(SGTrackerListUIOrigin)uIOrigin versionID:(nullable NSString *)versionID;

/**
 * User clicks to view a Buzzfeed list.
 *
 * @param absoluteRank Optional, must be NSInteger or NSNotFound. The absolute rank of the list item within the list..
 * @param itemListID Optional, must be NSString * or nil. The id of the list the user is expanding..
 * @param itemListKey Optional, must be NSString * or nil. The list key for the list the user is expanding..
 * @param itemListTitle Optional, must be NSString * or nil. The name of the list for the list the user is expanding..
 * @param itemStyleType Optional, must be NSString * or nil. Style type of the item. This will come from the server and be things like 'list_pointer_normal', 'list_horizontal', and 'list_vertical'..
 * @param listID Optional, must be NSString * or nil. The list item's parent's list_id..
 * @param listKey Optional, must be NSString * or nil. The stable, human-readable identifier of the list containing this list..
 * @param listQuery Optional, must be NSString * or nil. The query send to the Lists API.
 * @param listStyleType Optional, must be NSString * or nil. The item's parent's style type. This will come from the server and be things like 'list_horizontal' and 'list_vertical'..
 * @param listTitle Optional, must be NSString * or nil. The name of the list -- as the user sees it -- that contains the list item..
 * @param maxItemsInView Optional, must be NSInteger or NSNotFound. The max number of items that can be shown in the list item's list at any time..
 * @param parentRank Optional, must be NSInteger or NSNotFound. The rank of the list containing the item relative to the other lists displayed with it..
 * @param query Optional, must be NSString * or nil. The search query.
 * @param relativeRank Optional, must be NSInteger or NSNotFound. The rank of the list item relative to the user's viewport..
 * @param uIOrigin Required, must be SGTrackerListViewUIOrigin. Short identifier for the part of the UI from which the user clicked to open the list.
*/
+ (void)trackListViewClickWithAbsoluteRank:(NSInteger)absoluteRank itemListID:(nullable NSString *)itemListID itemListKey:(nullable NSString *)itemListKey itemListTitle:(nullable NSString *)itemListTitle itemStyleType:(nullable NSString *)itemStyleType listID:(nullable NSString *)listID listKey:(nullable NSString *)listKey listQuery:(nullable NSString *)listQuery listStyleType:(nullable NSString *)listStyleType listTitle:(nullable NSString *)listTitle maxItemsInView:(NSInteger)maxItemsInView parentRank:(NSInteger)parentRank query:(nullable NSString *)query relativeRank:(NSInteger)relativeRank uIOrigin:(SGTrackerListViewUIOrigin)uIOrigin;

/**
 * User taps on a button while on the lottery / daily tap screen.
 *
 * @param itemType Optional, must be SGTrackerLotteryItemType or SGTrackerLotteryItemTypeNone. The type of item being clicked on.
 * @param promotionID Required, must be NSString *. The powerball ID.
*/
+ (void)trackLotteryClickWithItemType:(SGTrackerLotteryItemType)itemType promotionID:(nonnull NSString *)promotionID;

/**
 * User dismisses the lottery / daily tap screen.
 *
 * @param promotionID Required, must be NSString *. The powerball ID.
*/
+ (void)trackLotteryDismissWithPromotionID:(nonnull NSString *)promotionID;

/**
 * User enables push notifications after clicking 'enable push' on the lottery / daily tap screen.
 *
 * @param promotionID Required, must be NSString *. The powerball ID.
*/
+ (void)trackLotteryNotificationSuccessWithPromotionID:(nonnull NSString *)promotionID;

/**
 * User sees the lottery / daily tap screen.
 *
 * @param promotionID Required, must be NSString *. The powerball ID.
 * @param uIOrigin Optional, must be SGTrackerLotteryUIOrigin or SGTrackerLotteryUIOriginNone. How the user got to the daily tap screen.
*/
+ (void)trackLotteryShowWithPromotionID:(nonnull NSString *)promotionID uIOrigin:(SGTrackerLotteryUIOrigin)uIOrigin;

/**
 * Called when something is shown to the user -- often for informational purposes, and often in a modal (bottom sheet, dialog, etc). This action is like user:prompt:show except it's for conveying information about something (e.g. Buyer Guarantee information or what "NFL Authenticated" means).
 *
 * @param modalType Required, must be SGTrackerModalModalType. The type of modal that is being shown to the user.
 * @param uIOrigin Required, must be SGTrackerModalUIOrigin. The UI origin where the modal was presented.
*/
+ (void)trackModalShowWithModalType:(SGTrackerModalModalType)modalType uIOrigin:(SGTrackerModalUIOrigin)uIOrigin;

/**
 * The music player becomes hidden offscreen.
 *
 * @param uIOrigin Required, must be SGTrackerMusicPlayerUIOrigin. Short identifier for the part of the UI where a user is viewing a Music Player.
*/
+ (void)trackMusicPlayerHideWithUIOrigin:(SGTrackerMusicPlayerUIOrigin)uIOrigin;

/**
 * User taps a UI element inside the Music Player.
 *
 * @param interactionMethod Required, must be SGTrackerMusicPlayerInteractionMethod. The UI element a user interacted with in the Music Player.
 * @param uIOrigin Required, must be SGTrackerMusicPlayerUIOrigin. Short identifier for the part of the UI where a user is viewing a Music Player.
*/
+ (void)trackMusicPlayerInteractWithInteractionMethod:(SGTrackerMusicPlayerInteractionMethod)interactionMethod uIOrigin:(SGTrackerMusicPlayerUIOrigin)uIOrigin;

/**
 * The music player becomes visible onscreen.
 *
 * @param uIOrigin Required, must be SGTrackerMusicPlayerUIOrigin. Short identifier for the part of the UI where a user is viewing a Music Player.
*/
+ (void)trackMusicPlayerShowWithUIOrigin:(SGTrackerMusicPlayerUIOrigin)uIOrigin;

/**
 * When a song is playing and reaches the end.
 *
 * @param duration Required, must be NSNumber *. The total duration of a song (in seconds) that just finished playing.
 * @param performerID Optional, must be NSString * or nil. The unique ID of the performer for the song that just ended.
 * @param songID Required, must be NSString *. The unique ID of the the song that just ended.
*/
+ (void)trackMusicPlayerSongEndWithDuration:(nonnull NSNumber *)duration performerID:(nullable NSString *)performerID songID:(nonnull NSString *)songID;

/**
 * When a song is playing and is paused.
 *
 * @param duration Required, must be NSNumber *. The current duration of a song (in seconds) when it is paused.
 * @param performerID Optional, must be NSString * or nil. The unique ID of the performer for the song that was just paused.
 * @param songID Required, must be NSString *. The unique ID of the the song that was just paused.
*/
+ (void)trackMusicPlayerSongPauseWithDuration:(nonnull NSNumber *)duration performerID:(nullable NSString *)performerID songID:(nonnull NSString *)songID;

/**
 * A song started playing from the beginning.
 *
 * @param performerID Optional, must be NSString * or nil. The unique ID of the performer for the song that's playing.
 * @param songID Required, must be NSString *. The unique ID of the the song that just started.
*/
+ (void)trackMusicPlayerSongStartWithPerformerID:(nullable NSString *)performerID songID:(nonnull NSString *)songID;

/**
 * User clicks on a navigation item (tab bar navigation).
 *
 * @param itemType Required, must be SGTrackerNavigationItemType. Which navigation item that was clicked.
*/
+ (void)trackNavigationClickWithItemType:(SGTrackerNavigationItemType)itemType;

/**
 * User taps or clicks a button underneath the custom UI content for a notification (viewed via 3D Touch or left/down swipes).
 *
 * @param contentAction Required, must be SGTrackerNotificationContentContentAction. The action corresponding to the button that was clicked or tapped.
 * @param notificationIsRemote Required, must be BOOL. Whether the notification was sent by a remote server/service or scheduled locally.
 * @param notificationType Required, must be SGTrackerNotificationContentNotificationType. The type of notification, which should correspond to the invoked UNNotificationExtensionCategory.
 * @param ticketGroupID Required, must be NSString *.
*/
+ (void)trackNotificationContentClickWithContentAction:(SGTrackerNotificationContentContentAction)contentAction notificationIsRemote:(BOOL)notificationIsRemote notificationType:(SGTrackerNotificationContentNotificationType)notificationType ticketGroupID:(nonnull NSString *)ticketGroupID;

/**
 * User views the custom UI content for a notification (via 3D Touch or left/down swipes).
 *
 * @param notificationIsRemote Required, must be BOOL. Whether the notification was sent by a remote server/service or scheduled locally.
 * @param notificationType Required, must be SGTrackerNotificationContentNotificationType. The type of notification, which should correspond to the invoked UNNotificationExtensionCategory.
 * @param ticketGroupID Required, must be NSString *.
 * @param eventID Optional, must be NSString * or nil.
 * @param quantity Optional, must be NSInteger or NSNotFound.
*/
+ (void)trackNotificationContentShowWithNotificationIsRemote:(BOOL)notificationIsRemote notificationType:(SGTrackerNotificationContentNotificationType)notificationType ticketGroupID:(nonnull NSString *)ticketGroupID eventID:(nullable NSString *)eventID quantity:(NSInteger)quantity;

/**
 * A user taps on a notification.
 *
 * @param notificationID Optional, must be NSString * or nil. The ID of an API driven local push notification.
 * @param notificationTag Optional, must be NSString * or nil.
 * @param notificationType Required, must be NSString *.
 * @param route Optional, must be NSString * or nil.
*/
+ (void)trackNotificationOpenWithNotificationID:(nullable NSString *)notificationID notificationTag:(nullable NSString *)notificationTag notificationType:(nonnull NSString *)notificationType route:(nullable NSString *)route;

/**
 * Device schedules an API driven local push notification.
 *
 * @param notificationID Required, must be NSString *. The ID of an API driven local push notification.
 * @param notificationTag Required, must be NSString *.
 * @param notificationType Required, must be NSString *.
 * @param route Required, must be NSString *.
 * @param timeToNotification Optional, must be NSInteger or NSNotFound. The duration of time between when the notification is scheduled, in seconds, and when it is supposed to appear on the user's device..
*/
+ (void)trackNotificationScheduleWithNotificationID:(nonnull NSString *)notificationID notificationTag:(nonnull NSString *)notificationTag notificationType:(nonnull NSString *)notificationType route:(nonnull NSString *)route timeToNotification:(NSInteger)timeToNotification;

/**
 * Peek on a performer.
 *
 * @param pageViewID Required, must be NSString *.
 * @param performerID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTracker3DTouchUIOrigin or SGTracker3DTouchUIOriginNone. Short identifier for the part of the UI from which the peek occurred.
*/
+ (void)trackPerformer3DTouchPeekWithPageViewID:(nonnull NSString *)pageViewID performerID:(nonnull NSString *)performerID uIOrigin:(SGTracker3DTouchUIOrigin)uIOrigin;

/**
 * Pop on a performer.
 *
 * @param pageViewID Required, must be NSString *.
 * @param performerID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTracker3DTouchUIOrigin or SGTracker3DTouchUIOriginNone. Short identifier for the part of the UI from which the pop occurred.
*/
+ (void)trackPerformer3DTouchPopWithPageViewID:(nonnull NSString *)pageViewID performerID:(nonnull NSString *)performerID uIOrigin:(SGTracker3DTouchUIOrigin)uIOrigin;

/**
 * A performer link is tapped.
 *
 * @param absoluteRank Optional, must be NSInteger or NSNotFound. The absolute rank of the performer within the parent..
 * @param autocompleteRequestID Optional, must be NSString * or nil. The unique id for the query sent to autocomplete that generated the result set..
 * @param hasPhoto Required, must be BOOL. An image is available for this performer.
 * @param isRecentSearch Optional, must be @(YES), @(NO), or nil. Flag indicating whether or not the selected searchbar dropdown item was a recent search..
 * @param itemStyleType Optional, must be NSString * or nil. The performer item's style type. This will come from the server and be things like 'performer_normal'..
 * @param listID Optional, must be NSString * or nil. The performer's parent container's list_id..
 * @param listKey Optional, must be NSString * or nil. The stable, human-readable identifier of the list containing this performer..
 * @param listStyleType Optional, must be NSString * or nil. The style type of the list the performer is in. This will come from the server and be things like 'list_horizontal' and 'list_vertical'..
 * @param listTitle Optional, must be NSString * or nil. The name of the list -- as the user sees it -- that contains the list item..
 * @param lowestPrice Optional, must be NSNumber * or nil.
 * @param maxItemsInView Optional, must be NSInteger or NSNotFound. The max number of items that can be shown in the performer's parent at any time..
 * @param pageViewID Required, must be NSString *.
 * @param parentRank Optional, must be NSInteger or NSNotFound. The rank of the performer's container relative to the other containers displayed with it..
 * @param passType Optional, must be NSString * or nil. The type of pass if applicable, e.g. parking, represented in the search result..
 * @param performerID Required, must be NSString *.
 * @param query Optional, must be NSString * or nil.
 * @param relativeRank Optional, must be NSInteger or NSNotFound. The rank of the performer relative to the user's viewport..
 * @param score Optional, must be NSNumber * or nil.
 * @param totalEvents Optional, must be NSInteger or NSNotFound. The number of events available for this performer..
 * @param uIOrigin Required, must be SGTrackerPerformerUIOrigin. Short identifier for the part of the UI from which the performer was clicked.
*/
+ (void)trackPerformerClickWithAbsoluteRank:(NSInteger)absoluteRank autocompleteRequestID:(nullable NSString *)autocompleteRequestID hasPhoto:(BOOL)hasPhoto isRecentSearch:(nullable NSNumber *)isRecentSearch itemStyleType:(nullable NSString *)itemStyleType listID:(nullable NSString *)listID listKey:(nullable NSString *)listKey listStyleType:(nullable NSString *)listStyleType listTitle:(nullable NSString *)listTitle lowestPrice:(nullable NSNumber *)lowestPrice maxItemsInView:(NSInteger)maxItemsInView pageViewID:(nonnull NSString *)pageViewID parentRank:(NSInteger)parentRank passType:(nullable NSString *)passType performerID:(nonnull NSString *)performerID query:(nullable NSString *)query relativeRank:(NSInteger)relativeRank score:(nullable NSNumber *)score totalEvents:(NSInteger)totalEvents uIOrigin:(SGTrackerPerformerUIOrigin)uIOrigin;

/**
 * User taps an item on the performer page.
 *
 * @param itemType Required, must be SGTrackerPerformerItemItemType. The item clicked on the performer page.
 * @param pageViewID Required, must be NSString *.
 * @param performerID Required, must be NSString *.
 * @param targetUrl Optional, must be NSString * or nil. The url that the click takes the user to.
*/
+ (void)trackPerformerItemClickWithItemType:(SGTrackerPerformerItemItemType)itemType pageViewID:(nonnull NSString *)pageViewID performerID:(nonnull NSString *)performerID targetUrl:(nullable NSString *)targetUrl;

/**
 * User sees an item on the performer page.
 *
 * @param itemType Required, must be SGTrackerPerformerItemItemType. The item seen on the performer page.
 * @param pageViewID Required, must be NSString *.
 * @param performerID Required, must be NSString *.
*/
+ (void)trackPerformerItemShowWithItemType:(SGTrackerPerformerItemItemType)itemType pageViewID:(nonnull NSString *)pageViewID performerID:(nonnull NSString *)performerID;

/**
 * User taps to buy media from a performer.
 *
 * @param mediaSeller Required, must be SGTrackerPerformerMediaMediaSeller.
 * @param mediaType Required, must be SGTrackerPerformerMediaMediaType.
 * @param pageViewID Required, must be NSString *.
 * @param performerID Required, must be NSString *.
*/
+ (void)trackPerformerMediaBuyWithMediaSeller:(SGTrackerPerformerMediaMediaSeller)mediaSeller mediaType:(SGTrackerPerformerMediaMediaType)mediaType pageViewID:(nonnull NSString *)pageViewID performerID:(nonnull NSString *)performerID;

/**
 * User taps to play media from a performer.
 *
 * @param mediaPlayer Required, must be SGTrackerPerformerMediaMediaPlayer.
 * @param mediaType Required, must be SGTrackerPerformerMediaMediaType.
 * @param pageViewID Required, must be NSString *.
 * @param performerID Required, must be NSString *.
*/
+ (void)trackPerformerMediaPlayWithMediaPlayer:(SGTrackerPerformerMediaMediaPlayer)mediaPlayer mediaType:(SGTrackerPerformerMediaMediaType)mediaType pageViewID:(nonnull NSString *)pageViewID performerID:(nonnull NSString *)performerID;

/**
 * A performer screen is shown.
 *
 * @param displayType Optional, must be SGTrackerPerformerDisplayType or SGTrackerPerformerDisplayTypeNone. Layout of performer page, whether its list or calendar view.
 * @param hasParkingCta Optional, must be @(YES), @(NO), or nil.
 * @param numberOfPaginations Optional, must be NSInteger or NSNotFound. Are the events shown on the page paginated or not, and how many pages.
 * @param pageType Optional, must be NSString * or nil. Which type of the performer page the user was shown. We send type = 'events' for :shows of the regular events screen , or a lowercased version of the `pass_type` that comes back from the Autocomplete response, i.e., parking screen comes from the `pass_type` of 'parking', and the club passes screen comes from the `pass_type` of 'club_passes'..
 * @param pageViewID Required, must be NSString *.
 * @param performerID Required, must be NSString *.
 * @param performerName Optional, must be NSString * or nil.
 * @param performerType Optional, must be NSString * or nil.
 * @param subtab Optional, must be SGTrackerPerformerSubtab or SGTrackerPerformerSubtabNone. Performer subtab shown on the Performer page.
 * @param totalEvents Required, must be NSInteger.
 * @param viewType Optional, must be NSString * or nil. Distinguishes between regular and AMP page types.
*/
+ (void)trackPerformerShowWithDisplayType:(SGTrackerPerformerDisplayType)displayType hasParkingCta:(nullable NSNumber *)hasParkingCta numberOfPaginations:(NSInteger)numberOfPaginations pageType:(nullable NSString *)pageType pageViewID:(nonnull NSString *)pageViewID performerID:(nonnull NSString *)performerID performerName:(nullable NSString *)performerName performerType:(nullable NSString *)performerType subtab:(SGTrackerPerformerSubtab)subtab totalEvents:(NSInteger)totalEvents viewType:(nullable NSString *)viewType;

/**
 * User clicks on the track button for a performer.
 *
 * @param pageViewID Optional, must be NSString * or nil.
 * @param performerID Required, must be NSString *.
*/
+ (void)trackPerformerTrackClickWithPageViewID:(nullable NSString *)pageViewID performerID:(nonnull NSString *)performerID;

/**
 * User clicks on the untrack button for a performer.
 *
 * @param pageViewID Optional, must be NSString * or nil.
 * @param performerID Required, must be NSString *.
*/
+ (void)trackPerformerUntrackClickWithPageViewID:(nullable NSString *)pageViewID performerID:(nonnull NSString *)performerID;

/**
 * User toggles view on performer page.
 *
 * @param itemName Required, must be SGTrackerPerformerViewItemName. The view the user toggles to.
 * @param itemType Required, must be SGTrackerPerformerViewItemType. The item seen on the performer page.
 * @param pageViewID Required, must be NSString *.
 * @param performerID Required, must be NSString *.
*/
+ (void)trackPerformerViewToggleWithItemName:(SGTrackerPerformerViewItemName)itemName itemType:(SGTrackerPerformerViewItemType)itemType pageViewID:(nonnull NSString *)pageViewID performerID:(nonnull NSString *)performerID;

/**
 * User clicks a promotion.
 *
 * @param absoluteRank Optional, must be NSInteger or NSNotFound. The absolute rank of the promotion within the parent..
 * @param displayType Optional, must be SGTrackerPromotionDisplayType or SGTrackerPromotionDisplayTypeNone. The type of promotion.
 * @param eventID Optional, must be NSString * or nil. The ID of the event for which the promotion was shown.
 * @param itemStyleType Optional, must be NSString * or nil. The promotion item's style type. This will come from the server and be things like 'performer_featured'..
 * @param linkUrl Optional, must be NSString * or nil. Some promotions link to pages that aren't performers or events, e.g., a Pelicans bundles page.
 * @param listID Optional, must be NSString * or nil. The promotion's parent container's list_id..
 * @param listKey Optional, must be NSString * or nil. The stable, human-readable identifier of the list containing this promotion..
 * @param listStyleType Optional, must be NSString * or nil. The style type of the list the promotion is in. This will come from the server and be things like 'list_horizontal_featured' and 'prompt_large_card'..
 * @param listTitle Optional, must be NSString * or nil. The name of the list -- as the user sees it -- that contains the promotion..
 * @param maxItemsInView Optional, must be NSInteger or NSNotFound. The max number of items that can be shown in the promotion's parent at any time..
 * @param parentRank Optional, must be NSInteger or NSNotFound. The rank of the promotion's container relative to the other containers displayed with it..
 * @param performerID Optional, must be NSString * or nil. The ID of the performer for which the promotion was shown.
 * @param promotionID Required, must be NSString *. The promotion ID.
 * @param rank Optional, must be NSInteger or NSNotFound. The promotion's index in a carousel of promotions (browse only). If a promotion is not in a carousel, this will be null..
 * @param relativeRank Optional, must be NSInteger or NSNotFound. The rank of the promotion relative to the user's viewport..
 * @param uIOrigin Optional, must be SGTrackerPromotionUIOrigin or SGTrackerPromotionUIOriginNone. Short identifier for the part of the UI from which the promotion action is taking place.
*/
+ (void)trackPromotionClickWithAbsoluteRank:(NSInteger)absoluteRank displayType:(SGTrackerPromotionDisplayType)displayType eventID:(nullable NSString *)eventID itemStyleType:(nullable NSString *)itemStyleType linkUrl:(nullable NSString *)linkUrl listID:(nullable NSString *)listID listKey:(nullable NSString *)listKey listStyleType:(nullable NSString *)listStyleType listTitle:(nullable NSString *)listTitle maxItemsInView:(NSInteger)maxItemsInView parentRank:(NSInteger)parentRank performerID:(nullable NSString *)performerID promotionID:(nonnull NSString *)promotionID rank:(NSInteger)rank relativeRank:(NSInteger)relativeRank uIOrigin:(SGTrackerPromotionUIOrigin)uIOrigin;

/**
 * User dismisses a promotion.
 *
 * @param displayType Optional, must be SGTrackerPromotionDisplayType or SGTrackerPromotionDisplayTypeNone. The type of promotion.
 * @param eventID Optional, must be NSString * or nil. The ID of the event for which the promotion was shown.
 * @param linkUrl Optional, must be NSString * or nil. Some promotions link to pages that aren't performers or events, e.g., a Pelicans bundles page.
 * @param performerID Optional, must be NSString * or nil. The ID of the performer for which the promotion was shown.
 * @param promotionID Required, must be NSString *. The promotion ID.
 * @param rank Optional, must be NSInteger or NSNotFound. The promotion's index in a carousel of promotions (browse only). If a promotion is not in a carousel, this will be null..
 * @param uIOrigin Optional, must be SGTrackerPromotionUIOrigin or SGTrackerPromotionUIOriginNone. Short identifier for the part of the UI from which the promotion action is taking place.
*/
+ (void)trackPromotionDismissWithDisplayType:(SGTrackerPromotionDisplayType)displayType eventID:(nullable NSString *)eventID linkUrl:(nullable NSString *)linkUrl performerID:(nullable NSString *)performerID promotionID:(nonnull NSString *)promotionID rank:(NSInteger)rank uIOrigin:(SGTrackerPromotionUIOrigin)uIOrigin;

/**
 * User sees a promotion.
 *
 * @param absoluteRank Optional, must be NSInteger or NSNotFound. The absolute rank of the promotion within the parent..
 * @param displayType Optional, must be SGTrackerPromotionDisplayType or SGTrackerPromotionDisplayTypeNone. The type of promotion.
 * @param eventID Optional, must be NSString * or nil. The ID of the event for which the promotion was shown.
 * @param itemStyleType Optional, must be NSString * or nil. The promotion item's style type. This will come from the server and be things like 'performer_featured'..
 * @param linkUrl Optional, must be NSString * or nil. Some promotions link to pages that aren't performers or events, e.g., a Pelicans bundles page.
 * @param listID Optional, must be NSString * or nil. The promotion's parent container's list_id..
 * @param listKey Optional, must be NSString * or nil. The stable, human-readable identifier of the list containing this promotion..
 * @param listStyleType Optional, must be NSString * or nil. The style type of the list the promotion is in. This will come from the server and be things like 'list_horizontal_featured' and 'prompt_large_card'..
 * @param listTitle Optional, must be NSString * or nil. The name of the list -- as the user sees it -- that contains the promotion..
 * @param maxItemsInView Optional, must be NSInteger or NSNotFound. The max number of items that can be shown in the promotion's parent at any time..
 * @param parentRank Optional, must be NSInteger or NSNotFound. The rank of the promotion's container relative to the other containers displayed with it..
 * @param performerID Optional, must be NSString * or nil. The ID of the performer for which the promotion was shown.
 * @param promotionID Required, must be NSString *. The promotion ID.
 * @param rank Optional, must be NSInteger or NSNotFound. The promotion's index in a carousel of promotions (browse only). If a promotion is not in a carousel, this will be null..
 * @param relativeRank Optional, must be NSInteger or NSNotFound. The rank of the promotion relative to the user's viewport..
 * @param uIOrigin Optional, must be SGTrackerPromotionUIOrigin or SGTrackerPromotionUIOriginNone. Short identifier for the part of the UI from which the promotion action is taking place.
*/
+ (void)trackPromotionShowWithAbsoluteRank:(NSInteger)absoluteRank displayType:(SGTrackerPromotionDisplayType)displayType eventID:(nullable NSString *)eventID itemStyleType:(nullable NSString *)itemStyleType linkUrl:(nullable NSString *)linkUrl listID:(nullable NSString *)listID listKey:(nullable NSString *)listKey listStyleType:(nullable NSString *)listStyleType listTitle:(nullable NSString *)listTitle maxItemsInView:(NSInteger)maxItemsInView parentRank:(NSInteger)parentRank performerID:(nullable NSString *)performerID promotionID:(nonnull NSString *)promotionID rank:(NSInteger)rank relativeRank:(NSInteger)relativeRank uIOrigin:(SGTrackerPromotionUIOrigin)uIOrigin;

/**
 * A point on the page is scrolled to.
 *
 * @param checkpoint Optional, must be SGTrackerScrollCheckpoint or SGTrackerScrollCheckpointNone. The part of the page the user scrolled to.
 * @param pageType Required, must be NSString *. Type of page action occurred on.
*/
+ (void)trackScrollCheckpointWithCheckpoint:(SGTrackerScrollCheckpoint)checkpoint pageType:(nonnull NSString *)pageType;

/**
 * The Search Tab is tapped.
*/
+ (void)trackSearchClick;

/**
 * A user taps on the search bar in the Search tab.
 *
 * @param uIOrigin Optional, must be SGTrackerSearchUIOrigin or SGTrackerSearchUIOriginNone. Short identifier for the part of the UI housing the search box which was focused.
*/
+ (void)trackSearchFocusWithUIOrigin:(SGTrackerSearchUIOrigin)uIOrigin;

/**
 * The 'See all results' item in autocomplete results is tapped.
 *
 * @param autocompleteRequestID Optional, must be NSString * or nil. The unique id for the query sent to autocomplete that generated the result set..
 * @param uIOrigin Required, must be SGTrackerSearchSeeAllResultsUIOrigin. Short identifier for the part of the UI from which the user clicked 'See all results'.
*/
+ (void)trackSearchSeeAllResultsClickWithAutocompleteRequestID:(nullable NSString *)autocompleteRequestID uIOrigin:(SGTrackerSearchSeeAllResultsUIOrigin)uIOrigin;

/**
 * Search results page, /search, is shown.
 *
 * @param query Required, must be NSString *.
 * @param totalResults Required, must be NSInteger.
 * @param uIOrigin Optional, must be SGTrackerSearchUIOrigin or SGTrackerSearchUIOriginNone. Short identifier for the part of the UI housing the search box which was searched.
*/
+ (void)trackSearchShowWithQuery:(nonnull NSString *)query totalResults:(NSInteger)totalResults uIOrigin:(SGTrackerSearchUIOrigin)uIOrigin;

/**
 * A link to the selling flow is clicked.
 *
 * @param marketName Optional, must be NSString * or nil. The human-readable unique identifier for the relevant marketplace.
 * @param uIOrigin Optional, must be SGTrackerSellUIOrigin or SGTrackerSellUIOriginNone. Short identifier for the part of the UI from which the sell link was clicked.
*/
+ (void)trackSellClickWithMarketName:(nullable NSString *)marketName uIOrigin:(SGTrackerSellUIOrigin)uIOrigin;

/**
 * /listings/:id/close returns error.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param eventID Optional, must be NSString * or nil.
 * @param listingID Required, must be NSString *.
 * @param marketName Optional, must be NSString * or nil. The human-readable unique identifier for the relevant marketplace.
 * @param ticketGroupID Required, must be NSString *.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackSellCloseErrorWithDomainSlug:(nullable NSString *)domainSlug errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage eventID:(nullable NSString *)eventID listingID:(nonnull NSString *)listingID marketName:(nullable NSString *)marketName ticketGroupID:(nonnull NSString *)ticketGroupID viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * POST /listings/:id/close.
 *
 * @param domainSlug Optional, must be SGTrackerOpenDomainSlug or SGTrackerOpenDomainSlugNone. The slug for the user's SG Open domain.
 * @param eventID Optional, must be NSString * or nil.
 * @param listingID Required, must be NSString *.
 * @param marketName Optional, must be NSString * or nil. The human-readable unique identifier for the relevant marketplace.
 * @param ticketGroupID Required, must be NSString *.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackSellCloseSubmitWithDomainSlug:(SGTrackerOpenDomainSlug)domainSlug eventID:(nullable NSString *)eventID listingID:(nonnull NSString *)listingID marketName:(nullable NSString *)marketName ticketGroupID:(nonnull NSString *)ticketGroupID viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * /listings/:id/close returns success.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Optional, must be NSString * or nil.
 * @param listingID Required, must be NSString *.
 * @param marketName Optional, must be NSString * or nil. The human-readable unique identifier for the relevant marketplace.
 * @param ticketGroupID Required, must be NSString *.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackSellCloseSuccessWithDomainSlug:(nullable NSString *)domainSlug eventID:(nullable NSString *)eventID listingID:(nonnull NSString *)listingID marketName:(nullable NSString *)marketName ticketGroupID:(nonnull NSString *)ticketGroupID viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * POST /listings returns error.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param eventID Required, must be NSString *.
 * @param marketName Optional, must be NSString * or nil. The human-readable unique identifier for the relevant marketplace.
 * @param pricePerTicket Required, must be NSNumber *.
 * @param quantity Required, must be NSInteger.
 * @param recommendedPrice Optional, must be NSNumber * or nil.
 * @param splitType Optional, must be NSString * or nil.
 * @param ticketGroupID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerSellCreateUIOrigin or SGTrackerSellCreateUIOriginNone. Short identifier for the part of the UI from which the user clicked to list.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackSellCreateErrorWithDomainSlug:(nullable NSString *)domainSlug errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage eventID:(nonnull NSString *)eventID marketName:(nullable NSString *)marketName pricePerTicket:(nonnull NSNumber *)pricePerTicket quantity:(NSInteger)quantity recommendedPrice:(nullable NSNumber *)recommendedPrice splitType:(nullable NSString *)splitType ticketGroupID:(nonnull NSString *)ticketGroupID uIOrigin:(SGTrackerSellCreateUIOrigin)uIOrigin viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * POST /listings.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param listingID Optional, must be NSString * or nil.
 * @param marketName Optional, must be NSString * or nil. The human-readable unique identifier for the relevant marketplace.
 * @param pricePerTicket Required, must be NSNumber *.
 * @param quantity Required, must be NSInteger.
 * @param recommendedPrice Optional, must be NSNumber * or nil.
 * @param splitType Optional, must be NSString * or nil.
 * @param ticketGroupID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerSellCreateUIOrigin or SGTrackerSellCreateUIOriginNone. Short identifier for the part of the UI from which the user clicked to list.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackSellCreateSubmitWithDomainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID listingID:(nullable NSString *)listingID marketName:(nullable NSString *)marketName pricePerTicket:(nonnull NSNumber *)pricePerTicket quantity:(NSInteger)quantity recommendedPrice:(nullable NSNumber *)recommendedPrice splitType:(nullable NSString *)splitType ticketGroupID:(nonnull NSString *)ticketGroupID uIOrigin:(SGTrackerSellCreateUIOrigin)uIOrigin viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * POST /listings returns success.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param listingID Required, must be NSString *.
 * @param marketName Optional, must be NSString * or nil. The human-readable unique identifier for the relevant marketplace.
 * @param pricePerTicket Required, must be NSNumber *.
 * @param quantity Required, must be NSInteger.
 * @param recommendedPrice Optional, must be NSNumber * or nil.
 * @param splitType Optional, must be NSString * or nil.
 * @param ticketGroupID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerSellCreateUIOrigin or SGTrackerSellCreateUIOriginNone. Short identifier for the part of the UI from which the user clicked to list.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackSellCreateSuccessWithDomainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID listingID:(nonnull NSString *)listingID marketName:(nullable NSString *)marketName pricePerTicket:(nonnull NSNumber *)pricePerTicket quantity:(NSInteger)quantity recommendedPrice:(nullable NSNumber *)recommendedPrice splitType:(nullable NSString *)splitType ticketGroupID:(nonnull NSString *)ticketGroupID uIOrigin:(SGTrackerSellCreateUIOrigin)uIOrigin viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * User interacts with a resale item.
 *
 * @param eventID Optional, must be NSString * or nil.
 * @param itemType Required, must be SGTrackerSellItemItemType. which resale item did we show to the user.
 * @param listingID Optional, must be NSString * or nil.
 * @param ticketGroupID Optional, must be NSString * or nil.
*/
+ (void)trackSellItemClickWithEventID:(nullable NSString *)eventID itemType:(SGTrackerSellItemItemType)itemType listingID:(nullable NSString *)listingID ticketGroupID:(nullable NSString *)ticketGroupID;

/**
 * User is shown a resale item.
 *
 * @param itemType Required, must be SGTrackerSellItemItemType. which resale item did we show to the user.
*/
+ (void)trackSellItemShowWithItemType:(SGTrackerSellItemItemType)itemType;

/**
 * Listing creation/edit flow is entered.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param editType Required, must be SGTrackerSellEditType. Whether this edit was for adding new data, or updating existing data.
 * @param eventID Required, must be NSString *.
 * @param hasPayoutMethod Required, must be BOOL. Whether or not the user had a saved payout method at the time of the action.
 * @param hasRecoupmentMethod Required, must be BOOL. Whether or not the user had a saved recoupment method at the time of the action.
 * @param listingID Optional, must be NSString * or nil.
 * @param marketName Optional, must be NSString * or nil. The human-readable unique identifier for the relevant marketplace.
 * @param ticketGroupID Required, must be NSString *.
 * @param viewMode Optional, must be SGTrackerSellViewMode or SGTrackerSellViewModeNone. The version of My Tickets the user is viewing.
*/
+ (void)trackSellLoadWithDomainSlug:(nullable NSString *)domainSlug editType:(SGTrackerSellEditType)editType eventID:(nonnull NSString *)eventID hasPayoutMethod:(BOOL)hasPayoutMethod hasRecoupmentMethod:(BOOL)hasRecoupmentMethod listingID:(nullable NSString *)listingID marketName:(nullable NSString *)marketName ticketGroupID:(nonnull NSString *)ticketGroupID viewMode:(SGTrackerSellViewMode)viewMode;

/**
 * PUT /listings/:id/pricing-strategy returns error.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param eventID Optional, must be NSString * or nil.
 * @param listingID Required, must be NSString *.
 * @param previousPricePerTicket Optional, must be NSNumber * or nil.
 * @param pricePerTicket Required, must be NSNumber *.
 * @param ticketGroupID Required, must be NSString *.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackSellPriceEditErrorWithDomainSlug:(nullable NSString *)domainSlug errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage eventID:(nullable NSString *)eventID listingID:(nonnull NSString *)listingID previousPricePerTicket:(nullable NSNumber *)previousPricePerTicket pricePerTicket:(nonnull NSNumber *)pricePerTicket ticketGroupID:(nonnull NSString *)ticketGroupID viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * PUT /listings/:id/pricing-strategy returns success for price change.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Optional, must be NSString * or nil.
 * @param listingID Required, must be NSString *.
 * @param previousPricePerTicket Optional, must be NSNumber * or nil.
 * @param pricePerTicket Required, must be NSNumber *.
 * @param ticketGroupID Required, must be NSString *.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackSellPriceEditSuccessWithDomainSlug:(nullable NSString *)domainSlug eventID:(nullable NSString *)eventID listingID:(nonnull NSString *)listingID previousPricePerTicket:(nullable NSNumber *)previousPricePerTicket pricePerTicket:(nonnull NSNumber *)pricePerTicket ticketGroupID:(nonnull NSString *)ticketGroupID viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * A call to the prelist-info endpoint fails or does not return a price recommendation.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param errorCode Optional, must be NSInteger or NSNotFound.
 * @param errorMessage Optional, must be NSString * or nil.
 * @param eventID Required, must be NSString *.
 * @param feePercentage Optional, must be NSNumber * or nil.
 * @param listingID Optional, must be NSString * or nil.
 * @param maxPricePerTicket Optional, must be NSNumber * or nil.
 * @param maxQuantity Optional, must be NSInteger or NSNotFound.
 * @param pricePerTicket Optional, must be NSNumber * or nil. The price_per_ticket sent by the client to the prelist info endpoint, which may not always be sen.
 * @param quantity Optional, must be NSInteger or NSNotFound.
 * @param recommendedPrice Optional, must be NSNumber * or nil.
 * @param ticketGroupID Required, must be NSString *.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackSellPriceRecommendErrorWithDomainSlug:(nullable NSString *)domainSlug errorCode:(NSInteger)errorCode errorMessage:(nullable NSString *)errorMessage eventID:(nonnull NSString *)eventID feePercentage:(nullable NSNumber *)feePercentage listingID:(nullable NSString *)listingID maxPricePerTicket:(nullable NSNumber *)maxPricePerTicket maxQuantity:(NSInteger)maxQuantity pricePerTicket:(nullable NSNumber *)pricePerTicket quantity:(NSInteger)quantity recommendedPrice:(nullable NSNumber *)recommendedPrice ticketGroupID:(nonnull NSString *)ticketGroupID viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * A call to the prelist-info endpoint returns a price recommendation.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param feePercentage Required, must be NSNumber *.
 * @param listingID Optional, must be NSString * or nil.
 * @param maxPricePerTicket Required, must be NSNumber *.
 * @param maxQuantity Required, must be NSInteger.
 * @param pricePerTicket Optional, must be NSNumber * or nil. The price_per_ticket sent by the client to the prelist info endpoint, which may not always be sent.
 * @param quantity Required, must be NSInteger.
 * @param recommendedPrice Required, must be NSNumber *.
 * @param ticketGroupID Required, must be NSString *.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackSellPriceRecommendSuccessWithDomainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID feePercentage:(nonnull NSNumber *)feePercentage listingID:(nullable NSString *)listingID maxPricePerTicket:(nonnull NSNumber *)maxPricePerTicket maxQuantity:(NSInteger)maxQuantity pricePerTicket:(nullable NSNumber *)pricePerTicket quantity:(NSInteger)quantity recommendedPrice:(nonnull NSNumber *)recommendedPrice ticketGroupID:(nonnull NSString *)ticketGroupID viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * User selects seats to sell.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param previousSelectedTicketsIDs Optional, must be NSString * or nil. Ticket ids separated by hyphen.
 * @param quantity Optional, must be NSInteger or NSNotFound.
 * @param selectedTicketIDs Required, must be NSString *. Ticket ids separated by hyphen.
 * @param ticketGroupID Required, must be NSString *.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackSellSeatEditWithDomainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID previousSelectedTicketsIDs:(nullable NSString *)previousSelectedTicketsIDs quantity:(NSInteger)quantity selectedTicketIDs:(nonnull NSString *)selectedTicketIDs ticketGroupID:(nonnull NSString *)ticketGroupID viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * POST to update listing returns error.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param eventID Required, must be NSString *.
 * @param marketName Optional, must be NSString * or nil. The human-readable unique identifier for the relevant marketplace.
 * @param pricePerTicket Required, must be NSNumber *.
 * @param quantity Required, must be NSInteger.
 * @param recommendedPrice Optional, must be NSNumber * or nil.
 * @param splitType Optional, must be NSString * or nil.
 * @param ticketGroupID Required, must be NSString *.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackSellUpdateErrorWithDomainSlug:(nullable NSString *)domainSlug errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage eventID:(nonnull NSString *)eventID marketName:(nullable NSString *)marketName pricePerTicket:(nonnull NSNumber *)pricePerTicket quantity:(NSInteger)quantity recommendedPrice:(nullable NSNumber *)recommendedPrice splitType:(nullable NSString *)splitType ticketGroupID:(nonnull NSString *)ticketGroupID viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * POST to update listing.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param listingID Required, must be NSString *.
 * @param marketName Optional, must be NSString * or nil. The human-readable unique identifier for the relevant marketplace.
 * @param pricePerTicket Required, must be NSNumber *.
 * @param quantity Required, must be NSInteger.
 * @param recommendedPrice Optional, must be NSNumber * or nil.
 * @param splitType Optional, must be NSString * or nil.
 * @param ticketGroupID Required, must be NSString *.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackSellUpdateSubmitWithDomainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID listingID:(nonnull NSString *)listingID marketName:(nullable NSString *)marketName pricePerTicket:(nonnull NSNumber *)pricePerTicket quantity:(NSInteger)quantity recommendedPrice:(nullable NSNumber *)recommendedPrice splitType:(nullable NSString *)splitType ticketGroupID:(nonnull NSString *)ticketGroupID viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * POST to update listing returns success.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param listingID Required, must be NSString *.
 * @param marketName Optional, must be NSString * or nil. The human-readable unique identifier for the relevant marketplace.
 * @param pricePerTicket Required, must be NSNumber *.
 * @param quantity Required, must be NSInteger.
 * @param recommendedPrice Optional, must be NSNumber * or nil.
 * @param splitType Optional, must be NSString * or nil.
 * @param ticketGroupID Required, must be NSString *.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackSellUpdateSuccessWithDomainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID listingID:(nonnull NSString *)listingID marketName:(nullable NSString *)marketName pricePerTicket:(nonnull NSNumber *)pricePerTicket quantity:(NSInteger)quantity recommendedPrice:(nullable NSNumber *)recommendedPrice splitType:(nullable NSString *)splitType ticketGroupID:(nonnull NSString *)ticketGroupID viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * User opens the today widget.
*/
+ (void)trackTodayShow;

/**
 * Events subtab shown on Tracking screen.
 *
 * @param totalResults Optional, must be NSInteger or NSNotFound. Total number of tracked events.
*/
+ (void)trackTrackingEventsShowWithTotalResults:(NSInteger)totalResults;

/**
 * Performers subtab shown on Tracking screen.
 *
 * @param totalResults Optional, must be NSInteger or NSNotFound. Total number of tracked performers.
*/
+ (void)trackTrackingPerformersShowWithTotalResults:(NSInteger)totalResults;

/**
 * Venues subtab shown on Tracking screen.
 *
 * @param totalResults Optional, must be NSInteger or NSNotFound. Total number of tracked venues.
*/
+ (void)trackTrackingVenuesShowWithTotalResults:(NSInteger)totalResults;

/**
 * PUT /transfers/:id/:signature/accept returns error.
 *
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param eventID Optional, must be NSString * or nil.
 * @param paymentType Optional, must be SGTrackerTransfersAcceptPaymentType or SGTrackerTransfersAcceptPaymentTypeNone. The type of payment method the user chose to pay for a paid transfer.
 * @param ticketGroupID Optional, must be NSString * or nil.
 * @param transferID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerTransfersUIOrigin or SGTrackerTransfersUIOriginNone. Short identifier for the part of the UI from which the user failed to accept the transfer.
*/
+ (void)trackTransfersAcceptErrorWithErrorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage eventID:(nullable NSString *)eventID paymentType:(SGTrackerTransfersAcceptPaymentType)paymentType ticketGroupID:(nullable NSString *)ticketGroupID transferID:(nonnull NSString *)transferID uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin;

/**
 * PUT /transfers/:id/:signature/accept returns success.
 *
 * @param eventID Optional, must be NSString * or nil.
 * @param paymentType Optional, must be SGTrackerTransfersAcceptPaymentType or SGTrackerTransfersAcceptPaymentTypeNone. The type of payment method the user chose to pay for a paid transfer.
 * @param ticketGroupID Optional, must be NSString * or nil.
 * @param transferID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerTransfersUIOrigin or SGTrackerTransfersUIOriginNone. Short identifier for the part of the UI from which the user accepted the transfer.
*/
+ (void)trackTransfersAcceptSuccessWithEventID:(nullable NSString *)eventID paymentType:(SGTrackerTransfersAcceptPaymentType)paymentType ticketGroupID:(nullable NSString *)ticketGroupID transferID:(nonnull NSString *)transferID uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin;

/**
 * PUT /transfers/:id/cancel returns error.
 *
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param eventID Optional, must be NSString * or nil.
 * @param ticketGroupID Optional, must be NSString * or nil.
 * @param transferID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerTransfersUIOrigin or SGTrackerTransfersUIOriginNone. Short identifier for the part of the UI from which the user failed to cancel the transfer.
*/
+ (void)trackTransfersCancelErrorWithErrorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage eventID:(nullable NSString *)eventID ticketGroupID:(nullable NSString *)ticketGroupID transferID:(nonnull NSString *)transferID uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin;

/**
 * PUT /transfers/:id/cancel returns success.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Optional, must be NSString * or nil.
 * @param ticketGroupID Optional, must be NSString * or nil.
 * @param transferID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerTransfersUIOrigin or SGTrackerTransfersUIOriginNone. Short identifier for the part of the UI from which the user canceled the transfer.
*/
+ (void)trackTransfersCancelSuccessWithDomainSlug:(nullable NSString *)domainSlug eventID:(nullable NSString *)eventID ticketGroupID:(nullable NSString *)ticketGroupID transferID:(nonnull NSString *)transferID uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin;

/**
 * POST /transfers returns error.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param eventID Required, must be NSString *.
 * @param pricePerTicket Required, must be NSNumber *.
 * @param quantity Required, must be NSInteger.
 * @param recipientType Optional, must be SGTrackerTransfersRecipientType or SGTrackerTransfersRecipientTypeNone. The type of recipient that the transfer is being sent to.
 * @param ticketGroupID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerTransfersUIOrigin or SGTrackerTransfersUIOriginNone. Short identifier for the part of the UI from which the user failed to send the transfer.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackTransfersCreateErrorWithDomainSlug:(nullable NSString *)domainSlug errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage eventID:(nonnull NSString *)eventID pricePerTicket:(nonnull NSNumber *)pricePerTicket quantity:(NSInteger)quantity recipientType:(SGTrackerTransfersRecipientType)recipientType ticketGroupID:(nullable NSString *)ticketGroupID uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * POST /transfers returns success.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param isLinkTransfer Optional, must be @(YES), @(NO), or nil.
 * @param pricePerTicket Required, must be NSNumber *.
 * @param quantity Required, must be NSInteger.
 * @param recipientType Optional, must be SGTrackerTransfersRecipientType or SGTrackerTransfersRecipientTypeNone. The type of recipient that the transfer is being sent to.
 * @param ticketGroupID Optional, must be NSString * or nil.
 * @param transferID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerTransfersUIOrigin or SGTrackerTransfersUIOriginNone. Short identifier for the part of the UI from which the user sent the transfer.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackTransfersCreateSuccessWithDomainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID isLinkTransfer:(nullable NSNumber *)isLinkTransfer pricePerTicket:(nonnull NSNumber *)pricePerTicket quantity:(NSInteger)quantity recipientType:(SGTrackerTransfersRecipientType)recipientType ticketGroupID:(nullable NSString *)ticketGroupID transferID:(nonnull NSString *)transferID uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * PUT /transfers/:id/:signature/decline returns error.
 *
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param eventID Optional, must be NSString * or nil.
 * @param ticketGroupID Optional, must be NSString * or nil.
 * @param transferID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerTransfersUIOrigin or SGTrackerTransfersUIOriginNone. Short identifier for the part of the UI from which the user failed to decline the transfer.
*/
+ (void)trackTransfersDeclineErrorWithErrorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage eventID:(nullable NSString *)eventID ticketGroupID:(nullable NSString *)ticketGroupID transferID:(nonnull NSString *)transferID uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin;

/**
 * PUT /transfers/:id/:signature/decline returns success.
 *
 * @param eventID Optional, must be NSString * or nil.
 * @param ticketGroupID Optional, must be NSString * or nil.
 * @param transferID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerTransfersUIOrigin or SGTrackerTransfersUIOriginNone. Short identifier for the part of the UI from which the user declined the transfer.
*/
+ (void)trackTransfersDeclineSuccessWithEventID:(nullable NSString *)eventID ticketGroupID:(nullable NSString *)ticketGroupID transferID:(nonnull NSString *)transferID uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin;

/**
 * a transfer details page is shown.
 *
 * @param status Required, must be SGTrackerTransfersStatus. The (server driven) transfer status of the item.
 * @param uIOrigin Optional, must be SGTrackerTransfersUIOrigin or SGTrackerTransfersUIOriginNone. Identifier of what brought the user to the transfer details page.
*/
+ (void)trackTransfersDetailsShowWithStatus:(SGTrackerTransfersStatus)status uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin;

/**
 * Showed a transfer cell in My Tickets.
 *
 * @param eventID Required, must be NSString *.
 * @param parentEventID Optional, must be NSString * or nil.
 * @param ticketGroupID Required, must be NSString *.
 * @param ticketType Optional, must be NSString * or nil.
 * @param transferID Required, must be NSString *.
 * @param transferType Required, must be SGTrackerTransfersIncomingTransferType.
 * @param uIOrigin Optional, must be SGTrackerTransfersIncomingUIOrigin or SGTrackerTransfersIncomingUIOriginNone. This can fire when a transfer card is visible in the Day of Event interface, or when a user views the standalone desktop and mobile web transfer acceptance flow..
*/
+ (void)trackTransfersIncomingShowWithEventID:(nonnull NSString *)eventID parentEventID:(nullable NSString *)parentEventID ticketGroupID:(nonnull NSString *)ticketGroupID ticketType:(nullable NSString *)ticketType transferID:(nonnull NSString *)transferID transferType:(SGTrackerTransfersIncomingTransferType)transferType uIOrigin:(SGTrackerTransfersIncomingUIOrigin)uIOrigin;

/**
 * the done/skip button is clicked on transfer initiation screen.
 *
 * @param activityType Required, must be SGTrackerTransfersInitiationActivityType.
*/
+ (void)trackTransfersInitiationClickWithActivityType:(SGTrackerTransfersInitiationActivityType)activityType;

/**
 * The transfer initiation screen is shown.
 *
 * @param source Optional, must be NSString * or nil. The ref query param that the user clicked (if existing) to open the initiation page.
 * @param uIOrigin Optional, must be SGTrackerTransfersUIOrigin or SGTrackerTransfersUIOriginNone. Identifier of what brought the user to the transfer initiation screen.
*/
+ (void)trackTransfersInitiationShowWithSource:(nullable NSString *)source uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin;

/**
 * a transfer item is clicked.
 *
 * @param activityType Required, must be SGTrackerTransfersItemActivityType.
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param pageType Required, must be SGTrackerTransfersItemPageType. The page on which the item is loaded.
 * @param quantity Required, must be NSInteger.
 * @param status Optional, must be SGTrackerTransfersStatus or SGTrackerTransfersStatusNone. The (server driven) transfer status of the item.
 * @param ticketType Required, must be SGTrackerTransfersTicketType.
 * @param uIOrigin Optional, must be SGTrackerTransfersUIOrigin or SGTrackerTransfersUIOriginNone. Identifier of what brought the user to the transfer initiation screen.
*/
+ (void)trackTransfersItemClickWithActivityType:(SGTrackerTransfersItemActivityType)activityType domainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID pageType:(SGTrackerTransfersItemPageType)pageType quantity:(NSInteger)quantity status:(SGTrackerTransfersStatus)status ticketType:(SGTrackerTransfersTicketType)ticketType uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin;

/**
 * a transfer item is loaded, visible or not.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param pageType Required, must be SGTrackerTransfersItemPageType. The page on which the item is loaded.
 * @param quantity Required, must be NSInteger.
 * @param status Optional, must be SGTrackerTransfersStatus or SGTrackerTransfersStatusNone. The (server driven) transfer status of the item.
 * @param ticketType Required, must be SGTrackerTransfersTicketType.
 * @param uIOrigin Optional, must be SGTrackerTransfersUIOrigin or SGTrackerTransfersUIOriginNone. Identifier of what brought the user to the transfer initiation screen.
*/
+ (void)trackTransfersItemLoadWithDomainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID pageType:(SGTrackerTransfersItemPageType)pageType quantity:(NSInteger)quantity status:(SGTrackerTransfersStatus)status ticketType:(SGTrackerTransfersTicketType)ticketType uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin;

/**
 * 50% of the item becomes visible to the user.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param pageType Required, must be SGTrackerTransfersItemPageType. The page on which the item is loaded.
 * @param quantity Required, must be NSInteger.
 * @param status Optional, must be SGTrackerTransfersStatus or SGTrackerTransfersStatusNone. The (server driven) transfer status of the item.
 * @param ticketType Required, must be SGTrackerTransfersTicketType.
 * @param uIOrigin Optional, must be SGTrackerTransfersUIOrigin or SGTrackerTransfersUIOriginNone. Identifier of what brought the user to the transfer initiation screen.
*/
+ (void)trackTransfersItemShowWithDomainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID pageType:(SGTrackerTransfersItemPageType)pageType quantity:(NSInteger)quantity status:(SGTrackerTransfersStatus)status ticketType:(SGTrackerTransfersTicketType)ticketType uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin;

/**
 * Transfer initiation screen is opened.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param ticketGroupID Required, must be NSString *.
 * @param viewMode Optional, must be SGTrackerTransfersViewMode or SGTrackerTransfersViewModeNone. The version of My Tickets the user is viewing.
*/
+ (void)trackTransfersLoadWithDomainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID ticketGroupID:(nonnull NSString *)ticketGroupID viewMode:(SGTrackerTransfersViewMode)viewMode;

/**
 * User selects seats to transfer.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param previousSelectedTicketsIDs Optional, must be NSString * or nil. Ticket ids separated by hyphen.
 * @param quantity Required, must be NSInteger.
 * @param selectedTicketIDs Required, must be NSString *. Ticket ids separated by hyphen.
 * @param ticketGroupID Required, must be NSString *.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackTransfersSeatEditWithDomainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID previousSelectedTicketsIDs:(nullable NSString *)previousSelectedTicketsIDs quantity:(NSInteger)quantity selectedTicketIDs:(nonnull NSString *)selectedTicketIDs ticketGroupID:(nonnull NSString *)ticketGroupID viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * an edit to the transfer summary is started.
 *
 * @param eventID Required, must be NSString *.
 * @param itemType Required, must be SGTrackerTransfersSummaryItemType. What part of the summary was being edited.
 * @param ticketType Required, must be SGTrackerTransfersTicketType.
*/
+ (void)trackTransfersSummaryEditStartWithEventID:(nonnull NSString *)eventID itemType:(SGTrackerTransfersSummaryItemType)itemType ticketType:(SGTrackerTransfersTicketType)ticketType;

/**
 * an edit to the transfer summary is completed and has changed value.
 *
 * @param eventID Required, must be NSString *.
 * @param isLinkRecipient Optional, must be @(YES), @(NO), or nil. Is recipient edited to be sent as a link (MW only).
 * @param itemType Required, must be SGTrackerTransfersSummaryItemType. What part of the summary was being edited.
 * @param ticketType Required, must be SGTrackerTransfersTicketType.
*/
+ (void)trackTransfersSummaryEditSuccessWithEventID:(nonnull NSString *)eventID isLinkRecipient:(nullable NSNumber *)isLinkRecipient itemType:(SGTrackerTransfersSummaryItemType)itemType ticketType:(SGTrackerTransfersTicketType)ticketType;

/**
 * a transfer summary page is shown.
 *
 * @param eventID Required, must be NSString *.
 * @param status Optional, must be SGTrackerTransfersStatus or SGTrackerTransfersStatusNone. The (server driven) transfer status of the item.
 * @param ticketType Required, must be SGTrackerTransfersTicketType.
 * @param uIOrigin Optional, must be SGTrackerTransfersUIOrigin or SGTrackerTransfersUIOriginNone. Identifier of what brought the user to the transfer details page.
*/
+ (void)trackTransfersSummaryShowWithEventID:(nonnull NSString *)eventID status:(SGTrackerTransfersStatus)status ticketType:(SGTrackerTransfersTicketType)ticketType uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin;

/**
 * An item is tapped on the account upgrade flow.
 *
 * @param itemType Required, must be SGTrackerUserAccountUpgradeItemType. A descriptor of what was tapped on.
*/
+ (void)trackUserAccountUpgradeItemClickWithItemType:(SGTrackerUserAccountUpgradeItemType)itemType;

/**
 * User fails to authenticate, regardless of whether 2FA is enabled.
 *
 * @param accountType Required, must be SGTrackerUserAccountType. The type of account this is.
 * @param credentialSource Required, must be SGTrackerUserAuthCredentialSource. The source from which the user's login information was filled.
 * @param emailUsername Optional, must be NSString * or nil. The email address or username used for logging in, if applicable (i.e. not FB login).
 * @param errorCode Required, must be NSInteger. The error code returned by the API, or other error code in the event of, e.g., network errors.
 * @param errorMessage Required, must be NSString *. The user-facing error message, if applicable.
 * @param uIOrigin Optional, must be SGTrackerUserAuthUIOrigin or SGTrackerUserAuthUIOriginNone. Short identifier for the part of the UI from which the user logged in.
*/
+ (void)trackUserAuthErrorWithAccountType:(SGTrackerUserAccountType)accountType credentialSource:(SGTrackerUserAuthCredentialSource)credentialSource emailUsername:(nullable NSString *)emailUsername errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage uIOrigin:(SGTrackerUserAuthUIOrigin)uIOrigin;

/**
 * User successfully authenticates, but may still need to complete 2FA before being gaining account access.
 *
 * @param accountType Required, must be SGTrackerUserAccountType. The type of account this is.
 * @param credentialSource Required, must be SGTrackerUserAuthCredentialSource. The source from which the user's login information was filled.
 * @param emailUsername Optional, must be NSString * or nil. The email address or username used for logging in, if applicable (i.e. not FB login).
 * @param uIOrigin Optional, must be SGTrackerUserAuthUIOrigin or SGTrackerUserAuthUIOriginNone. Short identifier for the part of the UI from which the user logged in.
*/
+ (void)trackUserAuthSuccessWithAccountType:(SGTrackerUserAccountType)accountType credentialSource:(SGTrackerUserAuthCredentialSource)credentialSource emailUsername:(nullable NSString *)emailUsername uIOrigin:(SGTrackerUserAuthUIOrigin)uIOrigin;

/**
 * Request to /users-email-verify OR /users-mobile-phone-verify returns with error.
 *
 * @param contactType Required, must be SGTrackerUserContactVerificationContactType.
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
*/
+ (void)trackUserContactVerificationResendErrorWithContactType:(SGTrackerUserContactVerificationContactType)contactType errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage;

/**
 * Request to /users-email-verify OR /users-mobile-phone-verify returns with success.
 *
 * @param contactType Required, must be SGTrackerUserContactVerificationContactType.
*/
+ (void)trackUserContactVerificationResendSuccessWithContactType:(SGTrackerUserContactVerificationContactType)contactType;

/**
 * Request to /users-email-verify OR /users-mobile-phone-verify returns with error.
 *
 * @param contactType Required, must be SGTrackerUserContactContactType.
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerUserContactUIOrigin or SGTrackerUserContactUIOriginNone. Short identifier for the part of the UI from which the user submitted a contact verification.
*/
+ (void)trackUserContactVerifyErrorWithContactType:(SGTrackerUserContactContactType)contactType errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage uIOrigin:(SGTrackerUserContactUIOrigin)uIOrigin;

/**
 * User is shown a screen asking for email or mobile phone verification.
 *
 * @param contactType Required, must be SGTrackerUserContactContactType.
 * @param uIOrigin Optional, must be SGTrackerUserContactUIOrigin or SGTrackerUserContactUIOriginNone. Short identifier for the part of the UI from which the user saw the verification screen.
*/
+ (void)trackUserContactVerifyShowWithContactType:(SGTrackerUserContactContactType)contactType uIOrigin:(SGTrackerUserContactUIOrigin)uIOrigin;

/**
 * Request submitted to /users-email-verify OR /users-mobile-phone-verify.
 *
 * @param contactType Required, must be SGTrackerUserContactContactType.
 * @param uIOrigin Optional, must be SGTrackerUserContactUIOrigin or SGTrackerUserContactUIOriginNone. Short identifier for the part of the UI from which the user submitted a contact verification.
*/
+ (void)trackUserContactVerifySubmitWithContactType:(SGTrackerUserContactContactType)contactType uIOrigin:(SGTrackerUserContactUIOrigin)uIOrigin;

/**
 * Request to /users-email-verify OR /users-mobile-phone-verify returns with success.
 *
 * @param contactType Required, must be SGTrackerUserContactContactType.
 * @param uIOrigin Optional, must be SGTrackerUserContactUIOrigin or SGTrackerUserContactUIOriginNone. Short identifier for the part of the UI from which the user successfully edited contact info.
*/
+ (void)trackUserContactVerifySuccessWithContactType:(SGTrackerUserContactContactType)contactType uIOrigin:(SGTrackerUserContactUIOrigin)uIOrigin;

/**
 * User clicks to track an event.
 *
 * @param eventDatetimeLocal Optional, must be NSString * or nil. Date/time of the event in the local timezone of the venue.
 * @param eventID Required, must be NSString *.
 * @param eventShortTitle Optional, must be NSString * or nil. A shortened title for the event.
 * @param eventTaxonomyName Optional, must be NSString * or nil. Type of event (broad category).
 * @param eventTitle Optional, must be NSString * or nil. The title of the event.
 * @param eventType Optional, must be NSString * or nil. Type of event (subcategory).
 * @param hasPhoto Optional, must be @(YES), @(NO), or nil. An image is available for this event (usually via associated performer).
 * @param interactionMethod Optional, must be SGTrackerUserEventInteractionMethod or SGTrackerUserEventInteractionMethodNone. Hardware-specific description of how the action was invoked if other than with the default tap or click.
 * @param listContentID Optional, must be NSString * or nil. ID for the version of the content in the list for a given list_id.
 * @param listID Optional, must be NSString * or nil.
 * @param lowestPrice Optional, must be NSNumber * or nil.
 * @param performerName Optional, must be NSString * or nil. Performer name.
 * @param rank Optional, must be NSInteger or NSNotFound.
 * @param score Optional, must be NSNumber * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserEventUIOrigin or SGTrackerUserEventUIOriginNone. Short identifier for the part of the UI from which the user tracked the event.
 * @param venueCity Optional, must be NSString * or nil.
 * @param venueName Optional, must be NSString * or nil.
 * @param venueState Optional, must be NSString * or nil.
*/
+ (void)trackUserEventTrackWithEventDatetimeLocal:(nullable NSString *)eventDatetimeLocal eventID:(nonnull NSString *)eventID eventShortTitle:(nullable NSString *)eventShortTitle eventTaxonomyName:(nullable NSString *)eventTaxonomyName eventTitle:(nullable NSString *)eventTitle eventType:(nullable NSString *)eventType hasPhoto:(nullable NSNumber *)hasPhoto interactionMethod:(SGTrackerUserEventInteractionMethod)interactionMethod listContentID:(nullable NSString *)listContentID listID:(nullable NSString *)listID lowestPrice:(nullable NSNumber *)lowestPrice performerName:(nullable NSString *)performerName rank:(NSInteger)rank score:(nullable NSNumber *)score uIOrigin:(SGTrackerUserEventUIOrigin)uIOrigin venueCity:(nullable NSString *)venueCity venueName:(nullable NSString *)venueName venueState:(nullable NSString *)venueState;

/**
 * User clicks to untrack an event.
 *
 * @param eventID Required, must be NSString *.
 * @param hasPhoto Optional, must be @(YES), @(NO), or nil. An image is available for this event (usually via associated performer).
 * @param interactionMethod Optional, must be SGTrackerUserEventInteractionMethod or SGTrackerUserEventInteractionMethodNone. Hardware-specific description of how the action was invoked if other than with the default tap or click.
 * @param listContentID Optional, must be NSString * or nil. ID for the version of the content in the list for a given list_id.
 * @param listID Optional, must be NSString * or nil.
 * @param lowestPrice Optional, must be NSNumber * or nil.
 * @param rank Optional, must be NSInteger or NSNotFound.
 * @param score Optional, must be NSNumber * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserEventUIOrigin or SGTrackerUserEventUIOriginNone. Short identifier for the part of the UI from which the user untracked the event.
*/
+ (void)trackUserEventUntrackWithEventID:(nonnull NSString *)eventID hasPhoto:(nullable NSNumber *)hasPhoto interactionMethod:(SGTrackerUserEventInteractionMethod)interactionMethod listContentID:(nullable NSString *)listContentID listID:(nullable NSString *)listID lowestPrice:(nullable NSNumber *)lowestPrice rank:(NSInteger)rank score:(nullable NSNumber *)score uIOrigin:(SGTrackerUserEventUIOrigin)uIOrigin;

/**
 * User dismisses the feedback screen.
 *
 * @param feedbackChoices Required, must be SGTrackerUserFeedbackFeedbackChoices. Short identifier of the set from which a user can choose an action.
 * @param uIOrigin Optional, must be SGTrackerUserFeedbackUIOrigin or SGTrackerUserFeedbackUIOriginNone. Short identifier for the part of the UI from which the dialog was triggered.
*/
+ (void)trackUserFeedbackDismissWithFeedbackChoices:(SGTrackerUserFeedbackFeedbackChoices)feedbackChoices uIOrigin:(SGTrackerUserFeedbackUIOrigin)uIOrigin;

/**
 * User chooses an option other than Dismiss/Cancel/Later in a feedback or support modal.
 *
 * @param feedbackChoice Required, must be SGTrackerUserFeedbackFeedbackChoice. Short identifier of which action a user chose.
 * @param uIOrigin Optional, must be SGTrackerUserFeedbackUIOrigin or SGTrackerUserFeedbackUIOriginNone. Short identifier for the part of the UI from which the dialog was triggered.
*/
+ (void)trackUserFeedbackNextWithFeedbackChoice:(SGTrackerUserFeedbackFeedbackChoice)feedbackChoice uIOrigin:(SGTrackerUserFeedbackUIOrigin)uIOrigin;

/**
 * Feedback screen is shown to user.
 *
 * @param feedbackChoices Required, must be SGTrackerUserFeedbackFeedbackChoices. Short identifier of the set from which a user can choose an action.
 * @param previouslyShownAppVersion Optional, must be NSString * or nil.
 * @param previouslyShownAt Optional, must be NSString * or nil.
 * @param timesShown Required, must be NSInteger. Count of times this has been shown, including this time.
 * @param uIOrigin Optional, must be SGTrackerUserFeedbackUIOrigin or SGTrackerUserFeedbackUIOriginNone. Short identifier for the part of the UI from which the dialog was triggered.
*/
+ (void)trackUserFeedbackShowWithFeedbackChoices:(SGTrackerUserFeedbackFeedbackChoices)feedbackChoices previouslyShownAppVersion:(nullable NSString *)previouslyShownAppVersion previouslyShownAt:(nullable NSString *)previouslyShownAt timesShown:(NSInteger)timesShown uIOrigin:(SGTrackerUserFeedbackUIOrigin)uIOrigin;

/**
 * User taps on a help button and it launches the native help center.
 *
 * @param helpType Optional, must be SGTrackerUserHelpHelpType or SGTrackerUserHelpHelpTypeNone. Used to determine if the user is navigating to the native help center or zendesk help center.
 * @param uIOrigin Required, must be SGTrackerUserHelpUIOrigin. Short identifier for the part of the UI from which the user selected help.
*/
+ (void)trackUserHelpClickWithHelpType:(SGTrackerUserHelpHelpType)helpType uIOrigin:(SGTrackerUserHelpUIOrigin)uIOrigin;

/**
 * User taps on the Contact Us button and it displays the available support options.
 *
 * @param uIOrigin Required, must be SGTrackerUserHelpUIOrigin. Short identifier for the part of the UI from which the user selected help.
*/
+ (void)trackUserHelpContactClickWithUIOrigin:(SGTrackerUserHelpUIOrigin)uIOrigin;

/**
 * User taps on a native support option.
 *
 * @param contactType Optional, must be SGTrackerUserHelpContactType or SGTrackerUserHelpContactTypeNone. The selected CX support option.
 * @param hasCallOption Required, must be BOOL. Is the call option available.
 * @param hasChatOption Required, must be BOOL. Is the chat option available.
 * @param hasEmailOption Required, must be BOOL. Is the email option available.
 * @param uIOrigin Required, must be SGTrackerUserHelpUIOrigin. Short identifier for the part of the UI from which the user selected help.
*/
+ (void)trackUserHelpContactSelectWithContactType:(SGTrackerUserHelpContactType)contactType hasCallOption:(BOOL)hasCallOption hasChatOption:(BOOL)hasChatOption hasEmailOption:(BOOL)hasEmailOption uIOrigin:(SGTrackerUserHelpUIOrigin)uIOrigin;

/**
 * DEPRECATED - see user:id_info:edit:success/error. User highlights an info field, changes its value, and then leaves (by clicking another field or exiting the screen).
 *
 * @param dataField Required, must be SGTrackerUserIDInfoDataField. The name of the field that the user edited.
 * @param editType Required, must be SGTrackerUserIDInfoEditType. Whether this edit was for adding new data, or updating existing data.
 * @param uIOrigin Optional, must be SGTrackerUserIDInfoUIOrigin or SGTrackerUserIDInfoUIOriginNone. Short identifier for the part of the UI from which the user edited personal information.
*/
+ (void)trackUserIDInfoEditWithDataField:(SGTrackerUserIDInfoDataField)dataField editType:(SGTrackerUserIDInfoEditType)editType uIOrigin:(SGTrackerUserIDInfoUIOrigin)uIOrigin;

/**
 * User fails to change personal or account information (including sync w/ API).
 *
 * @param dataField Optional, must be SGTrackerUserIDInfoDataField or SGTrackerUserIDInfoDataFieldNone. The name of the field that the user edited (only for single-field edits).
 * @param editType Required, must be SGTrackerUserIDInfoEditType. Whether this edit was for adding new data, or updating existing data.
 * @param errorCode Optional, must be NSInteger or NSNotFound. The error code returned by the API, if any.
 * @param errorMessage Required, must be NSString *. The error message shown to the user.
 * @param uIOrigin Optional, must be SGTrackerUserIDInfoUIOrigin or SGTrackerUserIDInfoUIOriginNone. Short identifier for the part of the UI from which the user edited personal information.
*/
+ (void)trackUserIDInfoEditErrorWithDataField:(SGTrackerUserIDInfoDataField)dataField editType:(SGTrackerUserIDInfoEditType)editType errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage uIOrigin:(SGTrackerUserIDInfoUIOrigin)uIOrigin;

/**
 * User successfully changes personal or account information (including sync w/ API).
 *
 * @param dataField Optional, must be SGTrackerUserIDInfoDataField or SGTrackerUserIDInfoDataFieldNone. The name of the field that the user edited (only for single-field edits).
 * @param editType Required, must be SGTrackerUserIDInfoEditType. Whether this edit was for adding new data, or updating existing data.
 * @param uIOrigin Optional, must be SGTrackerUserIDInfoUIOrigin or SGTrackerUserIDInfoUIOriginNone. Short identifier for the part of the UI from which the user edited personal information.
*/
+ (void)trackUserIDInfoEditSuccessWithDataField:(SGTrackerUserIDInfoDataField)dataField editType:(SGTrackerUserIDInfoEditType)editType uIOrigin:(SGTrackerUserIDInfoUIOrigin)uIOrigin;

/**
 * User loads screen showing personal information.
 *
 * @param dataField Optional, must be SGTrackerUserIDInfoDataField or SGTrackerUserIDInfoDataFieldNone. The name of the field that was loaded (only for single-field screens).
 * @param uIOrigin Optional, must be SGTrackerUserIDInfoUIOrigin or SGTrackerUserIDInfoUIOriginNone. Short identifier for the part of the UI from which the user edited personal information.
*/
+ (void)trackUserIDInfoLoadWithDataField:(SGTrackerUserIDInfoDataField)dataField uIOrigin:(SGTrackerUserIDInfoUIOrigin)uIOrigin;

/**
 * User clicks to submit additions or edits to personal or account information.
 *
 * @param dataField Optional, must be SGTrackerUserIDInfoDataField or SGTrackerUserIDInfoDataFieldNone. The name of the field that the user edited (only for single-field edits).
 * @param editType Required, must be SGTrackerUserIDInfoEditType. Whether this edit was for adding new data, or updating existing data.
 * @param uIOrigin Optional, must be SGTrackerUserIDInfoUIOrigin or SGTrackerUserIDInfoUIOriginNone. Short identifier for the part of the UI from which the user edited personal information.
*/
+ (void)trackUserIDInfoSubmitWithDataField:(SGTrackerUserIDInfoDataField)dataField editType:(SGTrackerUserIDInfoEditType)editType uIOrigin:(SGTrackerUserIDInfoUIOrigin)uIOrigin;

/**
 * User tries and fails to log in.
 *
 * @param accountType Required, must be SGTrackerUserAccountType. The type of account this is.
 * @param credentialSource Required, must be SGTrackerUserLoginCredentialSource. The source from which the user's login information was filled.
 * @param emailUsername Optional, must be NSString * or nil. The email address or username used for logging in, if applicable (i.e. not FB login).
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param eventID Optional, must be NSString * or nil.
 * @param twoFAMode Optional, must be SGTrackerUserTwoFAMode or SGTrackerUserTwoFAModeNone. The method used for 2FA, if any.
 * @param uIOrigin Optional, must be SGTrackerUserLoginUIOrigin or SGTrackerUserLoginUIOriginNone. Short identifier for the part of the UI from which the user tried to log in.
*/
+ (void)trackUserLoginErrorWithAccountType:(SGTrackerUserAccountType)accountType credentialSource:(SGTrackerUserLoginCredentialSource)credentialSource emailUsername:(nullable NSString *)emailUsername errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage eventID:(nullable NSString *)eventID twoFAMode:(SGTrackerUserTwoFAMode)twoFAMode uIOrigin:(SGTrackerUserLoginUIOrigin)uIOrigin;

/**
 * An item is tapped on the log in screen.
 *
 * @param itemType Required, must be SGTrackerUserLoginItemType. A descriptor of what was tapped on.
*/
+ (void)trackUserLoginItemClickWithItemType:(SGTrackerUserLoginItemType)itemType;

/**
 * User opens a "magic link" on their device.
*/
+ (void)trackUserLoginLinkOpen;

/**
 * User requests a "magic link" to log in.
*/
+ (void)trackUserLoginLinkRequest;

/**
 * Login form is shown.
 *
 * @param eventID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserLoginUIOrigin or SGTrackerUserLoginUIOriginNone. Short identifier for the part of the UI in which the login form was shown.
*/
+ (void)trackUserLoginShowWithEventID:(nullable NSString *)eventID uIOrigin:(SGTrackerUserLoginUIOrigin)uIOrigin;

/**
 * User selects an option from the login splash screen.
 *
 * @param loginChoice Required, must be SGTrackerUserLoginSplashLoginChoice. How the user chose to log in or register.
*/
+ (void)trackUserLoginSplashSelectWithLoginChoice:(SGTrackerUserLoginSplashLoginChoice)loginChoice;

/**
 * Interstitial screen for choosing how to sign up or log in is shown.
 *
 * @param uIOrigin Optional, must be SGTrackerUserLoginSplashUIOrigin or SGTrackerUserLoginSplashUIOriginNone. Short identifier for the part of the UI from which the user triggered the screen.
*/
+ (void)trackUserLoginSplashShowWithUIOrigin:(SGTrackerUserLoginSplashUIOrigin)uIOrigin;

/**
 * Login form is submitted.
 *
 * @param accountType Optional, must be SGTrackerUserAccountType or SGTrackerUserAccountTypeNone. The type of account this is.
 * @param credentialSource Required, must be SGTrackerUserLoginCredentialSource. The source from which the user's login information was filled.
 * @param emailUsername Optional, must be NSString * or nil. The email address or username used for logging in, if applicable (i.e. not FB login).
 * @param uIOrigin Optional, must be SGTrackerUserLoginUIOrigin or SGTrackerUserLoginUIOriginNone. Short identifier for the part of the UI in which the login form was submitted.
*/
+ (void)trackUserLoginSubmitWithAccountType:(SGTrackerUserAccountType)accountType credentialSource:(SGTrackerUserLoginCredentialSource)credentialSource emailUsername:(nullable NSString *)emailUsername uIOrigin:(SGTrackerUserLoginUIOrigin)uIOrigin;

/**
 * User logs in successfully.
 *
 * @param accountType Required, must be SGTrackerUserAccountType. The type of account this is.
 * @param credentialSource Required, must be SGTrackerUserLoginCredentialSource. The source from which the user's login information was filled.
 * @param emailUsername Optional, must be NSString * or nil. The email address or username used for logging in, if applicable (i.e. not FB login).
 * @param eventID Optional, must be NSString * or nil.
 * @param previousSgUuid Optional, must be NSString * or nil. The sg_uuid cookie value the user had before logging in.
 * @param twoFAMode Optional, must be SGTrackerUserTwoFAMode or SGTrackerUserTwoFAModeNone. The method used for 2FA, if any.
 * @param uIOrigin Optional, must be SGTrackerUserLoginUIOrigin or SGTrackerUserLoginUIOriginNone. Short identifier for the part of the UI from which the user logged in.
*/
+ (void)trackUserLoginSuccessWithAccountType:(SGTrackerUserAccountType)accountType credentialSource:(SGTrackerUserLoginCredentialSource)credentialSource emailUsername:(nullable NSString *)emailUsername eventID:(nullable NSString *)eventID previousSgUuid:(nullable NSString *)previousSgUuid twoFAMode:(SGTrackerUserTwoFAMode)twoFAMode uIOrigin:(SGTrackerUserLoginUIOrigin)uIOrigin;

/**
 * User tries and fails to log out.
 *
 * @param accountType Required, must be SGTrackerUserAccountType. The type of account this is.
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerUserLogoutUIOrigin or SGTrackerUserLogoutUIOriginNone. Short identifier for the part of the UI from which the user tried to log out.
*/
+ (void)trackUserLogoutErrorWithAccountType:(SGTrackerUserAccountType)accountType errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage uIOrigin:(SGTrackerUserLogoutUIOrigin)uIOrigin;

/**
 * User logs out successfully.
 *
 * @param accountType Required, must be SGTrackerUserAccountType. The type of account this is.
 * @param uIOrigin Optional, must be SGTrackerUserLogoutUIOrigin or SGTrackerUserLogoutUIOriginNone. Short identifier for the part of the UI from which the user logged out.
*/
+ (void)trackUserLogoutSuccessWithAccountType:(SGTrackerUserAccountType)accountType uIOrigin:(SGTrackerUserLogoutUIOrigin)uIOrigin;

/**
 * Tapped on an action button in a notice.
 *
 * @param activityType Required, must be SGTrackerUserNoticeActivityType. The type of action that was tapped or clicked.
 * @param noticeID Required, must be NSString *. The ID of the notice that was shown.
 * @param uIOrigin Required, must be SGTrackerUserNoticeUIOrigin. The UI origin where the notice was presented.
*/
+ (void)trackUserNoticeClickWithActivityType:(SGTrackerUserNoticeActivityType)activityType noticeID:(nonnull NSString *)noticeID uIOrigin:(SGTrackerUserNoticeUIOrigin)uIOrigin;

/**
 * Notice is shown.
 *
 * @param noticeID Required, must be NSString *. The ID of the notice that was shown.
 * @param uIOrigin Required, must be SGTrackerUserNoticeUIOrigin. The UI origin where the notice was presented.
*/
+ (void)trackUserNoticeShowWithNoticeID:(nonnull NSString *)noticeID uIOrigin:(SGTrackerUserNoticeUIOrigin)uIOrigin;

/**
 * User taps "enable notifications".
 *
 * @param settingsType Required, must be SGTrackerUserNotificationNagSettingsType.
 * @param timesShown Optional, must be NSInteger or NSNotFound. Count of times this has been shown, including this time.
 * @param uIOrigin Optional, must be SGTrackerUserNotificationNagUIOrigin or SGTrackerUserNotificationNagUIOriginNone.
*/
+ (void)trackUserNotificationNagAcceptWithSettingsType:(SGTrackerUserNotificationNagSettingsType)settingsType timesShown:(NSInteger)timesShown uIOrigin:(SGTrackerUserNotificationNagUIOrigin)uIOrigin;

/**
 * User taps "don't ask me again" on notification nag modal.
 *
 * @param dismissalLength Required, must be SGTrackerUserNotificationNagDismissalLength.
 * @param timesShown Optional, must be NSInteger or NSNotFound. Count of times this has been shown, including this time.
 * @param uIOrigin Optional, must be SGTrackerUserNotificationNagUIOrigin or SGTrackerUserNotificationNagUIOriginNone.
*/
+ (void)trackUserNotificationNagDismissWithDismissalLength:(SGTrackerUserNotificationNagDismissalLength)dismissalLength timesShown:(NSInteger)timesShown uIOrigin:(SGTrackerUserNotificationNagUIOrigin)uIOrigin;

/**
 * Nag modal to enable notifications is shown.
 *
 * @param modalType Required, must be SGTrackerUserNotificationNagModalType.
 * @param previouslyShownAppVersion Optional, must be NSString * or nil.
 * @param previouslyShownAt Optional, must be NSString * or nil.
 * @param timesShown Optional, must be NSInteger or NSNotFound. Count of times this has been shown, including this time.
 * @param uIOrigin Optional, must be SGTrackerUserNotificationNagUIOrigin or SGTrackerUserNotificationNagUIOriginNone.
*/
+ (void)trackUserNotificationNagShowWithModalType:(SGTrackerUserNotificationNagModalType)modalType previouslyShownAppVersion:(nullable NSString *)previouslyShownAppVersion previouslyShownAt:(nullable NSString *)previouslyShownAt timesShown:(NSInteger)timesShown uIOrigin:(SGTrackerUserNotificationNagUIOrigin)uIOrigin;

/**
 * User taps 'Back' on an onboarding screen/modal (onboarding actions track what we teach users, not what we ask them for).
 *
 * @param onboardingType Required, must be SGTrackerUserOnboardingOnboardingType.
 * @param ticketGroupID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserOnboardingUIOrigin or SGTrackerUserOnboardingUIOriginNone. Short identifier for the part of the UI from which the onboarding action is taking place.
*/
+ (void)trackUserOnboardingBackWithOnboardingType:(SGTrackerUserOnboardingOnboardingType)onboardingType ticketGroupID:(nullable NSString *)ticketGroupID uIOrigin:(SGTrackerUserOnboardingUIOrigin)uIOrigin;

/**
 * User taps 'No thanks' on an onboarding screen/modal (onboarding actions track what we teach users, not what we ask them for).
 *
 * @param onboardingType Required, must be SGTrackerUserOnboardingOnboardingType.
 * @param ticketGroupID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserOnboardingUIOrigin or SGTrackerUserOnboardingUIOriginNone. Short identifier for the part of the UI from which the onboarding action is taking place.
*/
+ (void)trackUserOnboardingCloseWithOnboardingType:(SGTrackerUserOnboardingOnboardingType)onboardingType ticketGroupID:(nullable NSString *)ticketGroupID uIOrigin:(SGTrackerUserOnboardingUIOrigin)uIOrigin;

/**
 * A user completes an onboarding flow (onboarding actions track what we teach users, not what we ask them for).
 *
 * @param uIOrigin Optional, must be SGTrackerUserOnboardingUIOrigin or SGTrackerUserOnboardingUIOriginNone. Short identifier for the part of the UI from which the onboarding screen or modal is being shown.
*/
+ (void)trackUserOnboardingCompleteWithUIOrigin:(SGTrackerUserOnboardingUIOrigin)uIOrigin;

/**
 * User taps 'Next', 'Got it', or 'OK' on an onboarding screen/modal (onboarding actions track what we teach users, not what we ask them for).
 *
 * @param onboardingType Required, must be SGTrackerUserOnboardingOnboardingType.
 * @param ticketGroupID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserOnboardingUIOrigin or SGTrackerUserOnboardingUIOriginNone. Short identifier for the part of the UI from which the onboarding action is taking place.
*/
+ (void)trackUserOnboardingNextWithOnboardingType:(SGTrackerUserOnboardingOnboardingType)onboardingType ticketGroupID:(nullable NSString *)ticketGroupID uIOrigin:(SGTrackerUserOnboardingUIOrigin)uIOrigin;

/**
 * An onboarding screen/modal is shown to the user (onboarding actions track what we teach users, not what we ask them for).
 *
 * @param onboardingType Required, must be SGTrackerUserOnboardingOnboardingType.
 * @param ticketGroupID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserOnboardingUIOrigin or SGTrackerUserOnboardingUIOriginNone. Short identifier for the part of the UI from which the onboarding screen or modal is being shown.
*/
+ (void)trackUserOnboardingShowWithOnboardingType:(SGTrackerUserOnboardingOnboardingType)onboardingType ticketGroupID:(nullable NSString *)ticketGroupID uIOrigin:(SGTrackerUserOnboardingUIOrigin)uIOrigin;

/**
 * An onboarding screen/modal is closed automatically, perhaps because the app loaded a deferred deep link (onboarding actions track what we teach users, not what we ask them for).
 *
 * @param uIOrigin Optional, must be SGTrackerUserOnboardingUIOrigin or SGTrackerUserOnboardingUIOriginNone. Short identifier for the part of the UI from which the onboarding screen or modal is being shown.
*/
+ (void)trackUserOnboardingSuppressWithUIOrigin:(SGTrackerUserOnboardingUIOrigin)uIOrigin;

/**
 * User receives an error when requesting a password reset.
 *
 * @param email Required, must be NSString *.
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
*/
+ (void)trackUserPasswordRequestResetErrorWithEmail:(nonnull NSString *)email errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage;

/**
 * User successfully requests a password reset.
 *
 * @param email Required, must be NSString *.
*/
+ (void)trackUserPasswordRequestResetSuccessWithEmail:(nonnull NSString *)email;

/**
 * DEPRECATED - see user:payment:info:edit. User highlights a payment field, changes its value, and then leaves (by clicking another field or exiting the screen).
 *
 * @param clickID Optional, must be NSString * or nil.
 * @param dataField Required, must be SGTrackerUserPaymentDataField. The name of the field that the user edited.
 * @param editType Required, must be SGTrackerUserPaymentEditType. Whether this edit was for adding new data, or updating existing data.
 * @param paymentMethodToken Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserPaymentUIOrigin or SGTrackerUserPaymentUIOriginNone. Short identifier for the part of the UI from which the user clicked to add/edit.
*/
+ (void)trackUserPaymentEditWithClickID:(nullable NSString *)clickID dataField:(SGTrackerUserPaymentDataField)dataField editType:(SGTrackerUserPaymentEditType)editType paymentMethodToken:(nullable NSString *)paymentMethodToken uIOrigin:(SGTrackerUserPaymentUIOrigin)uIOrigin;

/**
 * User submits payment method form and sees an error.
 *
 * @param editType Required, must be SGTrackerUserPaymentEditType. Whether this edit was for adding new data, or updating existing data.
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param isRecoupmentEligible Optional, must be @(YES), @(NO), or nil. Whether or not this payment method is being, or has already been, designated for recoupments by the user.
 * @param paymentMethodToken Optional, must be NSString * or nil. The payment method token if this was an exisitng payment method.
 * @param uIOrigin Optional, must be SGTrackerUserPaymentUIOrigin or SGTrackerUserPaymentUIOriginNone. Short identifier for the part of the UI from which the user tried editing payment info.
*/
+ (void)trackUserPaymentEditErrorWithEditType:(SGTrackerUserPaymentEditType)editType errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage isRecoupmentEligible:(nullable NSNumber *)isRecoupmentEligible paymentMethodToken:(nullable NSString *)paymentMethodToken uIOrigin:(SGTrackerUserPaymentUIOrigin)uIOrigin;

/**
 * User submits payment method form and sees success.
 *
 * @param editType Required, must be SGTrackerUserPaymentEditType. Whether this edit was for adding new data, or updating existing data.
 * @param isRecoupmentEligible Required, must be BOOL. Whether or not this payment method is being, or has already been, designated for recoupments by the user.
 * @param paymentMethodToken Optional, must be NSString * or nil. The payment method token if this was an exisitng payment method, or the new one created if this was new.
 * @param uIOrigin Optional, must be SGTrackerUserPaymentUIOrigin or SGTrackerUserPaymentUIOriginNone. Short identifier for the part of the UI from which the user edited payment info.
*/
+ (void)trackUserPaymentEditSuccessWithEditType:(SGTrackerUserPaymentEditType)editType isRecoupmentEligible:(BOOL)isRecoupmentEligible paymentMethodToken:(nullable NSString *)paymentMethodToken uIOrigin:(SGTrackerUserPaymentUIOrigin)uIOrigin;

/**
 * Formerly user:payment:edit. User highlights a payment field, changes its value, and then leaves (by clicking another field or exiting the screen).
 *
 * @param dataField Required, must be SGTrackerUserPaymentDataField. The name of the field that the user edited.
 * @param editType Required, must be SGTrackerUserPaymentEditType. Whether this edit was for adding new data, or updating existing data.
 * @param isRecoupmentEligible Optional, must be @(YES), @(NO), or nil. Whether or not the user is making the card eligible for recoupment with this edit.
 * @param paymentMethodToken Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserPaymentUIOrigin or SGTrackerUserPaymentUIOriginNone. Short identifier for the part of the UI from which the user clicked to add/edit.
*/
+ (void)trackUserPaymentInfoEditWithDataField:(SGTrackerUserPaymentDataField)dataField editType:(SGTrackerUserPaymentEditType)editType isRecoupmentEligible:(nullable NSNumber *)isRecoupmentEligible paymentMethodToken:(nullable NSString *)paymentMethodToken uIOrigin:(SGTrackerUserPaymentUIOrigin)uIOrigin;

/**
 * User loads screen for adding a payment method or editing an existing one.
 *
 * @param editType Required, must be SGTrackerUserPaymentEditType. Whether the screen was loaded to add a new payment method or update an existing one.
 * @param isAffirmEligible Optional, must be @(YES), @(NO), or nil. If user is eligible to select affirm as a payment method.
 * @param isRecoupmentEligible Optional, must be @(YES), @(NO), or nil. If an existing payment method, whether or not it was eligible for recoupments.
 * @param paymentMethodToken Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserPaymentUIOrigin or SGTrackerUserPaymentUIOriginNone. Short identifier for the part of the UI from which the user clicked to add/edit.
*/
+ (void)trackUserPaymentLoadWithEditType:(SGTrackerUserPaymentEditType)editType isAffirmEligible:(nullable NSNumber *)isAffirmEligible isRecoupmentEligible:(nullable NSNumber *)isRecoupmentEligible paymentMethodToken:(nullable NSString *)paymentMethodToken uIOrigin:(SGTrackerUserPaymentUIOrigin)uIOrigin;

/**
 * User submits add/edit payout method flow and gets error from server.
 *
 * @param editType Required, must be SGTrackerUserPayoutEditType. Whether this edit was for adding new data, or updating existing data.
 * @param errorCode Optional, must be NSInteger or NSNotFound.
 * @param errorMessage Optional, must be NSString * or nil.
 * @param payoutMethodID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserPayoutUIOrigin or SGTrackerUserPayoutUIOriginNone. Short identifier for the part of the UI from which the user tried editing payout method type info.
*/
+ (void)trackUserPayoutErrorWithEditType:(SGTrackerUserPayoutEditType)editType errorCode:(NSInteger)errorCode errorMessage:(nullable NSString *)errorMessage payoutMethodID:(nullable NSString *)payoutMethodID uIOrigin:(SGTrackerUserPayoutUIOrigin)uIOrigin;

/**
 * User gets (server) error after submitting payout info step.
 *
 * @param editType Required, must be SGTrackerUserPayoutEditType. Whether this edit was for adding new data, or updating existing data.
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param payoutMethodID Optional, must be NSString * or nil.
 * @param stepName Optional, must be SGTrackerUserPayoutStepName or SGTrackerUserPayoutStepNameNone. Step the user completes.
 * @param uIOrigin Optional, must be SGTrackerUserPayoutUIOrigin or SGTrackerUserPayoutUIOriginNone. Short identifier for the part of the UI from which the user tried editing payout method contact info.
*/
+ (void)trackUserPayoutInfoEditErrorWithEditType:(SGTrackerUserPayoutEditType)editType errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage payoutMethodID:(nullable NSString *)payoutMethodID stepName:(SGTrackerUserPayoutStepName)stepName uIOrigin:(SGTrackerUserPayoutUIOrigin)uIOrigin;

/**
 * User gets (server) success after submitting payout info step.
 *
 * @param editType Required, must be SGTrackerUserPayoutEditType. Whether this edit was for adding new data, or updating existing data.
 * @param payoutMethodID Optional, must be NSString * or nil.
 * @param stepName Optional, must be SGTrackerUserPayoutStepName or SGTrackerUserPayoutStepNameNone. Step the user completes.
 * @param uIOrigin Optional, must be SGTrackerUserPayoutUIOrigin or SGTrackerUserPayoutUIOriginNone. Short identifier for the part of the UI from which the user edited payout method contact info.
*/
+ (void)trackUserPayoutInfoEditSuccessWithEditType:(SGTrackerUserPayoutEditType)editType payoutMethodID:(nullable NSString *)payoutMethodID stepName:(SGTrackerUserPayoutStepName)stepName uIOrigin:(SGTrackerUserPayoutUIOrigin)uIOrigin;

/**
 * User opens add/edit payout method flow.
 *
 * @param editType Required, must be SGTrackerUserPayoutEditType. Whether this edit was for adding new data, or updating existing data.
 * @param payoutMethodID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserPayoutUIOrigin or SGTrackerUserPayoutUIOriginNone. Short identifier for the part of the UI from which the user opened the edit payout method flow.
*/
+ (void)trackUserPayoutLoadWithEditType:(SGTrackerUserPayoutEditType)editType payoutMethodID:(nullable NSString *)payoutMethodID uIOrigin:(SGTrackerUserPayoutUIOrigin)uIOrigin;

/**
 * User payout information messaged dismissed.
 *
 * @param errorCode Optional, must be NSInteger or NSNotFound.
 * @param errorMessage Required, must be NSString *.
 * @param payoutMethodID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserPayoutUIOrigin or SGTrackerUserPayoutUIOriginNone. Short identifier for the part of the UI from which the user tried editing payout method contact info.
*/
+ (void)trackUserPayoutMessageDismissWithErrorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage payoutMethodID:(nullable NSString *)payoutMethodID uIOrigin:(SGTrackerUserPayoutUIOrigin)uIOrigin;

/**
 * User payout information messaged shown.
 *
 * @param errorCode Optional, must be NSInteger or NSNotFound.
 * @param errorMessage Required, must be NSString *.
 * @param payoutMethodID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserPayoutUIOrigin or SGTrackerUserPayoutUIOriginNone. Short identifier for the part of the UI from which the user tried editing payout method contact info.
*/
+ (void)trackUserPayoutMessageShowWithErrorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage payoutMethodID:(nullable NSString *)payoutMethodID uIOrigin:(SGTrackerUserPayoutUIOrigin)uIOrigin;

/**
 * User submits payout type info and gets error from server.
 *
 * @param editType Required, must be SGTrackerUserPayoutEditType. Whether this edit was for adding new data, or updating existing data.
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param method Required, must be SGTrackerUserPayoutMethod.
 * @param payoutMethodID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserPayoutUIOrigin or SGTrackerUserPayoutUIOriginNone. Short identifier for the part of the UI from which the user tried editing payout method type info.
*/
+ (void)trackUserPayoutMethodEditErrorWithEditType:(SGTrackerUserPayoutEditType)editType errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage method:(SGTrackerUserPayoutMethod)method payoutMethodID:(nullable NSString *)payoutMethodID uIOrigin:(SGTrackerUserPayoutUIOrigin)uIOrigin;

/**
 * User taps payout type from method selection screen.
 *
 * @param editType Required, must be SGTrackerUserPayoutEditType. Whether this edit was for adding new data, or updating existing data.
 * @param method Required, must be SGTrackerUserPayoutMethod.
 * @param payoutMethodID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserPayoutUIOrigin or SGTrackerUserPayoutUIOriginNone. Short identifier for the part of the UI from which the user edited payout method type info.
*/
+ (void)trackUserPayoutMethodEditSelectWithEditType:(SGTrackerUserPayoutEditType)editType method:(SGTrackerUserPayoutMethod)method payoutMethodID:(nullable NSString *)payoutMethodID uIOrigin:(SGTrackerUserPayoutUIOrigin)uIOrigin;

/**
 * User submits payout type info and gets success from server.
 *
 * @param editType Required, must be SGTrackerUserPayoutEditType. Whether this edit was for adding new data, or updating existing data.
 * @param method Required, must be SGTrackerUserPayoutMethod.
 * @param payoutMethodID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserPayoutUIOrigin or SGTrackerUserPayoutUIOriginNone. Short identifier for the part of the UI from which the user edited payout method type info.
*/
+ (void)trackUserPayoutMethodEditSuccessWithEditType:(SGTrackerUserPayoutEditType)editType method:(SGTrackerUserPayoutMethod)method payoutMethodID:(nullable NSString *)payoutMethodID uIOrigin:(SGTrackerUserPayoutUIOrigin)uIOrigin;

/**
 * User taps payout type from sell flow.
 *
 * @param editType Required, must be SGTrackerUserPayoutEditType. Whether this edit was for adding new data, or updating existing data.
 * @param method Required, must be SGTrackerUserPayoutMethod.
 * @param payoutMethodID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserPayoutUIOrigin or SGTrackerUserPayoutUIOriginNone. Short identifier for the part of the UI from which the user edited payout method type info.
*/
+ (void)trackUserPayoutMethodSelectWithEditType:(SGTrackerUserPayoutEditType)editType method:(SGTrackerUserPayoutMethod)method payoutMethodID:(nullable NSString *)payoutMethodID uIOrigin:(SGTrackerUserPayoutUIOrigin)uIOrigin;

/**
 * User submits add/edit payout method flow and gets success from server.
 *
 * @param editType Required, must be SGTrackerUserPayoutEditType. Whether this edit was for adding new data, or updating existing data.
 * @param payoutMethodID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserPayoutUIOrigin or SGTrackerUserPayoutUIOriginNone. Short identifier for the part of the UI from which the user tried editing payout method type info.
*/
+ (void)trackUserPayoutSuccessWithEditType:(SGTrackerUserPayoutEditType)editType payoutMethodID:(nullable NSString *)payoutMethodID uIOrigin:(SGTrackerUserPayoutUIOrigin)uIOrigin;

/**
 * User picks whether they are a business or indivual seller. Defaults to individual.
 *
 * @param accountType Optional, must be SGTrackerUserPayoutAccountType or SGTrackerUserPayoutAccountTypeNone. Business or User seller.
 * @param uIOrigin Optional, must be SGTrackerUserPayoutUIOrigin or SGTrackerUserPayoutUIOriginNone. Short identifier for the part of the UI from which the user tried editing payout method type info.
*/
+ (void)trackUserPayoutTypeSelectWithAccountType:(SGTrackerUserPayoutAccountType)accountType uIOrigin:(SGTrackerUserPayoutUIOrigin)uIOrigin;

/**
 * User clicks to track a performer.
 *
 * @param interactionMethod Optional, must be SGTrackerUserPerformerInteractionMethod or SGTrackerUserPerformerInteractionMethodNone. Hardware-specific description of how the action was invoked if other than with the default tap or click.
 * @param performerID Required, must be NSString *.
 * @param performerName Optional, must be NSString * or nil. Performer name.
 * @param uIOrigin Optional, must be SGTrackerUserPerformerUIOrigin or SGTrackerUserPerformerUIOriginNone. Short identifier for the part of the UI from which the user tracked the performer.
*/
+ (void)trackUserPerformerTrackWithInteractionMethod:(SGTrackerUserPerformerInteractionMethod)interactionMethod performerID:(nonnull NSString *)performerID performerName:(nullable NSString *)performerName uIOrigin:(SGTrackerUserPerformerUIOrigin)uIOrigin;

/**
 * User clicks to untrack a performer.
 *
 * @param interactionMethod Optional, must be SGTrackerUserPerformerInteractionMethod or SGTrackerUserPerformerInteractionMethodNone. Hardware-specific description of how the action was invoked if other than with the default tap or click.
 * @param performerID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerUserPerformerUIOrigin or SGTrackerUserPerformerUIOriginNone. Short identifier for the part of the UI from which the user untracked the performer.
*/
+ (void)trackUserPerformerUntrackWithInteractionMethod:(SGTrackerUserPerformerInteractionMethod)interactionMethod performerID:(nonnull NSString *)performerID uIOrigin:(SGTrackerUserPerformerUIOrigin)uIOrigin;

/**
 * A user edits their push notification preferences.
 *
 * @param preferenceChoice Required, must be SGTrackerUserPreferencesPreferenceChoice. Whether the user chose to enable or disable the push notification.
 * @param preferenceType Required, must be SGTrackerUserPreferencesPreferenceType. The type of push notification for which the user edited preferences.
*/
+ (void)trackUserPreferencesPushEditWithPreferenceChoice:(SGTrackerUserPreferencesPreferenceChoice)preferenceChoice preferenceType:(SGTrackerUserPreferencesPreferenceType)preferenceType;

/**
 * User tries and fails to apply a promocode to their account.
 *
 * @param errorMessage Required, must be NSString *.
 * @param promocode Required, must be NSString *.
 * @param errorCode Optional, must be NSInteger or NSNotFound.
*/
+ (void)trackUserPromocodeApplyErrorWithErrorMessage:(nonnull NSString *)errorMessage promocode:(nonnull NSString *)promocode errorCode:(NSInteger)errorCode;

/**
 * User successfully applies a promocode to their account.
 *
 * @param promocodeID Required, must be NSString *.
 * @param promocodeType Required, must be SGTrackerUserPromocodePromocodeType. The type of promocode applied to the order, if any.
 * @param uIOrigin Optional, must be SGTrackerUserPromocodeUIOrigin or SGTrackerUserPromocodeUIOriginNone.
*/
+ (void)trackUserPromocodeApplySuccessWithPromocodeID:(nonnull NSString *)promocodeID promocodeType:(SGTrackerUserPromocodePromocodeType)promocodeType uIOrigin:(SGTrackerUserPromocodeUIOrigin)uIOrigin;

/**
 * User takes an 'Allow', 'Enable', or 'Connect' positive action in response to a prompt screen/modal (prompt actions track what we ask users to do, not what we teach them).
 *
 * @param activityType Optional, must be SGTrackerUserPromptActivityType or SGTrackerUserPromptActivityTypeNone. The type of acceptance that occured, if any..
 * @param displayValue Optional, must be NSString * or nil. The copy of the button that was clicked or tapped.
 * @param eventID Optional, must be NSString * or nil. The ID of the event for which a prompt was shown.
 * @param promptID Optional, must be NSString * or nil. The ID of the prompt, currently only used for buzzfeed prompts.
 * @param promptStyleType Optional, must be NSString * or nil. The style type of the prompt.
 * @param promptType Required, must be SGTrackerUserPromptPromptType. The type of action the prompt is trying to get the user to do.
 * @param uIOrigin Optional, must be SGTrackerUserPromptUIOrigin or SGTrackerUserPromptUIOriginNone. Short identifier for the part of the UI from which the prompt action is taking place.
*/
+ (void)trackUserPromptAcceptWithActivityType:(SGTrackerUserPromptActivityType)activityType displayValue:(nullable NSString *)displayValue eventID:(nullable NSString *)eventID promptID:(nullable NSString *)promptID promptStyleType:(nullable NSString *)promptStyleType promptType:(SGTrackerUserPromptPromptType)promptType uIOrigin:(SGTrackerUserPromptUIOrigin)uIOrigin;

/**
 * User takes a negative 'Maybe Later', 'Not Now', 'Don't Ask Me Again', or 'Skip' action based on a prompt  (prompt actions track what we ask users to do, not what we teach them).
 *
 * @param displayValue Optional, must be NSString * or nil. The copy of the button that was clicked or tapped.
 * @param eventID Optional, must be NSString * or nil. The ID of the event for which a prompt was shown.
 * @param promptID Optional, must be NSString * or nil. The ID of the prompt, currently only used for buzzfeed prompts.
 * @param promptStyleType Optional, must be NSString * or nil. The style type of the prompt.
 * @param promptType Required, must be SGTrackerUserPromptPromptType. The type of action the prompt is trying to get the user to do.
 * @param uIOrigin Optional, must be SGTrackerUserPromptUIOrigin or SGTrackerUserPromptUIOriginNone. Short identifier for the part of the UI from which the prompt action is taking place.
*/
+ (void)trackUserPromptDismissWithDisplayValue:(nullable NSString *)displayValue eventID:(nullable NSString *)eventID promptID:(nullable NSString *)promptID promptStyleType:(nullable NSString *)promptStyleType promptType:(SGTrackerUserPromptPromptType)promptType uIOrigin:(SGTrackerUserPromptUIOrigin)uIOrigin;

/**
 * A prompt screen/modal/list-item is hidden from a user without the user explicity taking an action to dismiss the prompt.
 *
 * @param eventID Optional, must be NSString * or nil. The ID of the event for which a prompt was shown.
 * @param promptID Optional, must be NSString * or nil. The ID of the prompt, currently only used for buzzfeed prompts.
 * @param promptStyleType Optional, must be NSString * or nil. The style type of the prompt.
 * @param promptType Required, must be SGTrackerUserPromptPromptType. The type of action the prompt is trying to get the user to do.
 * @param uIOrigin Optional, must be SGTrackerUserPromptUIOrigin or SGTrackerUserPromptUIOriginNone. Short identifier for the part of the UI from which the prompt is taking place.
*/
+ (void)trackUserPromptHideWithEventID:(nullable NSString *)eventID promptID:(nullable NSString *)promptID promptStyleType:(nullable NSString *)promptStyleType promptType:(SGTrackerUserPromptPromptType)promptType uIOrigin:(SGTrackerUserPromptUIOrigin)uIOrigin;

/**
 * A prompt screen/modal/list-item is shown to a user (prompt actions track what we ask users to do, not what we teach them).
 *
 * @param eventID Optional, must be NSString * or nil. The ID of the event for which a prompt was shown.
 * @param promptID Optional, must be NSString * or nil. The ID of the prompt, currently only used for buzzfeed prompts.
 * @param promptStyleType Optional, must be NSString * or nil. The style type of the prompt.
 * @param promptType Required, must be SGTrackerUserPromptPromptType. The type of action the prompt is trying to get the user to do.
 * @param uIOrigin Optional, must be SGTrackerUserPromptUIOrigin or SGTrackerUserPromptUIOriginNone. Short identifier for the part of the UI from which the prompt is taking place.
*/
+ (void)trackUserPromptShowWithEventID:(nullable NSString *)eventID promptID:(nullable NSString *)promptID promptStyleType:(nullable NSString *)promptStyleType promptType:(SGTrackerUserPromptPromptType)promptType uIOrigin:(SGTrackerUserPromptUIOrigin)uIOrigin;

/**
 * User selects a saved payment method to use for recoupments.
 *
 * @param hasRecoupmentMethod Required, must be BOOL. Whether or not the user has previously designated a payment method for recoupments.
 * @param paymentMethodToken Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserRecoupmentUIOrigin or SGTrackerUserRecoupmentUIOriginNone. Short identifier for the part of the UI from which the user selected the payment method.
*/
+ (void)trackUserRecoupmentSelectWithHasRecoupmentMethod:(BOOL)hasRecoupmentMethod paymentMethodToken:(nullable NSString *)paymentMethodToken uIOrigin:(SGTrackerUserRecoupmentUIOrigin)uIOrigin;

/**
 * User is shown a warning about changing their recoupment method.
 *
 * @param uIOrigin Optional, must be SGTrackerUserRecoupmentUIOrigin or SGTrackerUserRecoupmentUIOriginNone. Short identifier for the part of the UI from which the user selected the payment method.
*/
+ (void)trackUserRecoupmentWarningShowWithUIOrigin:(SGTrackerUserRecoupmentUIOrigin)uIOrigin;

/**
 * A user adds an email to potentially send a referral..
 *
 * @param email Required, must be NSString *.
*/
+ (void)trackUserReferralsCreateAddWithEmail:(nonnull NSString *)email;

/**
 * A user removes an email from the list of potential emails to send a referral..
 *
 * @param email Required, must be NSString *.
*/
+ (void)trackUserReferralsCreateRemoveWithEmail:(nonnull NSString *)email;

/**
 * A user views the send-referral-by-email flow..
*/
+ (void)trackUserReferralsCreateShow;

/**
 * A user dismisses the referrals view..
 *
 * @param displayType Optional, must be SGTrackerUserReferralsDisplayType or SGTrackerUserReferralsDisplayTypeNone.
*/
+ (void)trackUserReferralsDismissWithDisplayType:(SGTrackerUserReferralsDisplayType)displayType;

/**
 * A user viewed the redeem-referral error view.
 *
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
*/
+ (void)trackUserReferralsInviteErrorWithErrorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage;

/**
 * A user viewed the redeem-referral success view.
*/
+ (void)trackUserReferralsInviteSuccess;

/**
 * A user initiated a referral by email.
 *
 * @param numberOfInvites Required, must be NSInteger.
*/
+ (void)trackUserReferralsSendWithNumberOfInvites:(NSInteger)numberOfInvites;

/**
 * A user referral by email failed.
 *
 * @param errorCode Optional, must be NSInteger or NSNotFound.
 * @param errorMessage Optional, must be NSString * or nil.
 * @param numberOfInvites Required, must be NSInteger. If the request is sucessful, this is the number of failed emails. If the request fails, then this is the total number of emails we sent..
*/
+ (void)trackUserReferralsSendErrorWithErrorCode:(NSInteger)errorCode errorMessage:(nullable NSString *)errorMessage numberOfInvites:(NSInteger)numberOfInvites;

/**
 * A user sucessfully sent a referral by email.
 *
 * @param numberOfInvites Required, must be NSInteger.
*/
+ (void)trackUserReferralsSendSuccessWithNumberOfInvites:(NSInteger)numberOfInvites;

/**
 * A taps one of the referral options.
 *
 * @param displayValue Required, must be SGTrackerUserReferralsDisplayValue.
*/
+ (void)trackUserReferralsShareWithDisplayValue:(SGTrackerUserReferralsDisplayValue)displayValue;

/**
 * A user is shown the referrals view..
 *
 * @param advocateDiscount Required, must be NSNumber *.
 * @param displayType Optional, must be SGTrackerUserReferralsDisplayType or SGTrackerUserReferralsDisplayTypeNone.
 * @param prospectDiscount Required, must be NSNumber *.
*/
+ (void)trackUserReferralsShowWithAdvocateDiscount:(nonnull NSNumber *)advocateDiscount displayType:(SGTrackerUserReferralsDisplayType)displayType prospectDiscount:(nonnull NSNumber *)prospectDiscount;

/**
 * User tries and fails to register.
 *
 * @param accountType Required, must be SGTrackerUserAccountType. The type of account this is.
 * @param email Required, must be NSString *.
 * @param errorCode Required, must be NSInteger.
 * @param errorMessage Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTrackerUserRegisterUIOrigin or SGTrackerUserRegisterUIOriginNone. Short identifier for the part of the UI from which the user tried to register.
*/
+ (void)trackUserRegisterErrorWithAccountType:(SGTrackerUserAccountType)accountType email:(nonnull NSString *)email errorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage uIOrigin:(SGTrackerUserRegisterUIOrigin)uIOrigin;

/**
 * User registration form is shown.
 *
 * @param eventID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserRegisterUIOrigin or SGTrackerUserRegisterUIOriginNone. Short identifier for the part of the UI from which the user chose to register.
*/
+ (void)trackUserRegisterShowWithEventID:(nullable NSString *)eventID uIOrigin:(SGTrackerUserRegisterUIOrigin)uIOrigin;

/**
 * User registers successfully.
 *
 * @param accountType Required, must be SGTrackerUserAccountType. The type of account this is.
 * @param email Optional, must be NSString * or nil.
 * @param eventID Optional, must be NSString * or nil.
 * @param previousSgUuid Optional, must be NSString * or nil. The sg_uuid cookie value the user had before registering.
 * @param uIOrigin Optional, must be SGTrackerUserRegisterUIOrigin or SGTrackerUserRegisterUIOriginNone. Short identifier for the part of the UI from which the user tried to register.
*/
+ (void)trackUserRegisterSuccessWithAccountType:(SGTrackerUserAccountType)accountType email:(nullable NSString *)email eventID:(nullable NSString *)eventID previousSgUuid:(nullable NSString *)previousSgUuid uIOrigin:(SGTrackerUserRegisterUIOrigin)uIOrigin;

/**
 * A user takes a screenshot.
 *
 * @param uIOrigin Optional, must be SGTrackerUserUIOrigin or SGTrackerUserUIOriginNone. The screen that a user took the screenshot.
*/
+ (void)trackUserScreenshotWithUIOrigin:(SGTrackerUserUIOrigin)uIOrigin;

/**
 * User tries and fails to connect a service.
 *
 * @param serviceType Required, must be SGTrackerUserServiceServiceType.
*/
+ (void)trackUserServiceConnectErrorWithServiceType:(SGTrackerUserServiceServiceType)serviceType;

/**
 * User taps connect a service.
 *
 * @param serviceType Required, must be SGTrackerUserServiceServiceType.
*/
+ (void)trackUserServiceConnectSelectWithServiceType:(SGTrackerUserServiceServiceType)serviceType;

/**
 * User successfully connects a service.
 *
 * @param serviceType Required, must be SGTrackerUserServiceServiceType.
*/
+ (void)trackUserServiceConnectSuccessWithServiceType:(SGTrackerUserServiceServiceType)serviceType;

/**
 * User tries and fails to disconnect a service.
 *
 * @param serviceType Required, must be SGTrackerUserServiceServiceType.
*/
+ (void)trackUserServiceDisconnectErrorWithServiceType:(SGTrackerUserServiceServiceType)serviceType;

/**
 * User taps disconnect a service.
 *
 * @param serviceType Required, must be SGTrackerUserServiceServiceType.
*/
+ (void)trackUserServiceDisconnectSelectWithServiceType:(SGTrackerUserServiceServiceType)serviceType;

/**
 * User successfully disconnects a service.
 *
 * @param serviceType Required, must be SGTrackerUserServiceServiceType.
*/
+ (void)trackUserServiceDisconnectSuccessWithServiceType:(SGTrackerUserServiceServiceType)serviceType;

/**
 * User taps on an item on the Me screen.
 *
 * @param displayValue Required, must be SGTrackerUserSettingsDisplayValue. The item a user tapped on the Me screen.
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SeatGeek Open domain.
*/
+ (void)trackUserSettingsItemClickWithDisplayValue:(SGTrackerUserSettingsDisplayValue)displayValue domainSlug:(nullable NSString *)domainSlug;

/**
 * The settings screen is shown.
 *
 * @param hasAccountManager Required, must be BOOL.
*/
+ (void)trackUserSettingsShowWithHasAccountManager:(BOOL)hasAccountManager;

/**
 * A user cancels sharing after tapping to share from the custom share sheet.
 *
 * @param activityType Optional, must be NSString * or nil. Defined by third party apps or by the OS for built-in types, and ommitted if the user canceled sharing before making a selection.
 * @param eventID Optional, must be NSString * or nil. Included only if the item being shared is an event.
 * @param hasScreenshot Required, must be BOOL.
 * @param itemType Required, must be SGTrackerUserShareItemType. The type of link/content the user is sharing.
 * @param listingID Optional, must be NSString * or nil. Included only if the item being shared is a listing.
 * @param pageViewID Required, must be NSString *. The unique client-generated page identifier.
 * @param performerID Optional, must be NSString * or nil. Included only if the item being shared is a performer.
 * @param source Required, must be SGTrackerUserShareSource. The way the share sheet was initialized.
 * @param uIOrigin Required, must be SGTrackerUserShareUIOrigin. The screen that a user is sharing from.
 * @param venueID Optional, must be NSString * or nil. Included only if the item being shared is a venue.
*/
+ (void)trackUserShareCancelWithActivityType:(nullable NSString *)activityType eventID:(nullable NSString *)eventID hasScreenshot:(BOOL)hasScreenshot itemType:(SGTrackerUserShareItemType)itemType listingID:(nullable NSString *)listingID pageViewID:(nonnull NSString *)pageViewID performerID:(nullable NSString *)performerID source:(SGTrackerUserShareSource)source uIOrigin:(SGTrackerUserShareUIOrigin)uIOrigin venueID:(nullable NSString *)venueID;

/**
 * A user taps to share from the custom share sheet.
 *
 * @param activityType Required, must be NSString *. Defined by third party apps or by the OS for built-in types.
 * @param eventID Optional, must be NSString * or nil. Included only if the item being shared is an event.
 * @param hasScreenshot Required, must be BOOL.
 * @param itemType Required, must be SGTrackerUserShareItemType. The type of link/content the user is sharing.
 * @param listingID Optional, must be NSString * or nil. Included only if the item being shared is a listing.
 * @param performerID Optional, must be NSString * or nil. Included only if the item being shared is a performer.
 * @param source Required, must be SGTrackerUserShareSource. The way the share sheet was initialized.
 * @param uIOrigin Required, must be SGTrackerUserShareUIOrigin. The screen that a user is sharing from.
 * @param venueID Optional, must be NSString * or nil. Included only if the item being shared is a venue.
*/
+ (void)trackUserShareCreateWithActivityType:(nonnull NSString *)activityType eventID:(nullable NSString *)eventID hasScreenshot:(BOOL)hasScreenshot itemType:(SGTrackerUserShareItemType)itemType listingID:(nullable NSString *)listingID performerID:(nullable NSString *)performerID source:(SGTrackerUserShareSource)source uIOrigin:(SGTrackerUserShareUIOrigin)uIOrigin venueID:(nullable NSString *)venueID;

/**
 * A custom share sheet is shown to a user after they tap a share button or take a screenshot.
 *
 * @param eventID Optional, must be NSString * or nil. Included only if the item being shared is an event.
 * @param hasScreenshot Required, must be BOOL.
 * @param itemType Required, must be SGTrackerUserShareItemType. The type of link/content the user is sharing.
 * @param listingID Optional, must be NSString * or nil. Included only if the item being shared is a listing.
 * @param pageViewID Required, must be NSString *. The unique client-generated page identifier.
 * @param performerID Optional, must be NSString * or nil. Included only if the item being shared is an event.
 * @param source Required, must be SGTrackerUserShareSource. The way the share sheet was initialized.
 * @param uIOrigin Required, must be SGTrackerUserShareUIOrigin. The screen that a user is sharing from.
 * @param venueID Optional, must be NSString * or nil. Included only if the item being shared is a venue.
*/
+ (void)trackUserShareShowWithEventID:(nullable NSString *)eventID hasScreenshot:(BOOL)hasScreenshot itemType:(SGTrackerUserShareItemType)itemType listingID:(nullable NSString *)listingID pageViewID:(nonnull NSString *)pageViewID performerID:(nullable NSString *)performerID source:(SGTrackerUserShareSource)source uIOrigin:(SGTrackerUserShareUIOrigin)uIOrigin venueID:(nullable NSString *)venueID;

/**
 * User highlights a shipping field, changes its value, and then leaves (by clicking another field or exiting the screen).
 *
 * @param dataField Required, must be SGTrackerUserShippingDataField. The name of the field that the user edited.
 * @param editType Required, must be SGTrackerUserShippingEditType. Whether this edit was for adding new data, or updating existing data.
 * @param clickID Optional, must be NSString * or nil.
 * @param shippingMethodID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserShippingUIOrigin or SGTrackerUserShippingUIOriginNone. Short identifier for the part of the UI from which the user clicked to add/edit.
*/
+ (void)trackUserShippingEditWithDataField:(SGTrackerUserShippingDataField)dataField editType:(SGTrackerUserShippingEditType)editType clickID:(nullable NSString *)clickID shippingMethodID:(nullable NSString *)shippingMethodID uIOrigin:(SGTrackerUserShippingUIOrigin)uIOrigin;

/**
 * User loads screen for adding a shipping method or editing an existing one.
 *
 * @param editType Required, must be SGTrackerUserShippingEditType. Whether this edit was for adding new data, or updating existing data.
 * @param shippingMethodID Optional, must be NSString * or nil.
 * @param uIOrigin Optional, must be SGTrackerUserShippingUIOrigin or SGTrackerUserShippingUIOriginNone. Short identifier for the part of the UI from which the user clicked to add/edit.
*/
+ (void)trackUserShippingLoadWithEditType:(SGTrackerUserShippingEditType)editType shippingMethodID:(nullable NSString *)shippingMethodID uIOrigin:(SGTrackerUserShippingUIOrigin)uIOrigin;

/**
 * An item on a survey screen is tapped.
 *
 * @param itemType Required, must be SGTrackerUserSurveyItemType. The item tapped on the survey.
 * @param pageType Required, must be SGTrackerUserSurveyPageType. The specific survey screen that is show to a user.
*/
+ (void)trackUserSurveyItemClickWithItemType:(SGTrackerUserSurveyItemType)itemType pageType:(SGTrackerUserSurveyPageType)pageType;

/**
 * One of the survey screens is shown.
 *
 * @param pageType Required, must be SGTrackerUserSurveyPageType. The specific survey screen that is show to a user.
*/
+ (void)trackUserSurveyShowWithPageType:(SGTrackerUserSurveyPageType)pageType;

/**
 * User long presses or force presses on an ticket group.
 *
 * @param eventID Required, must be NSString *.
 * @param ticketGroupID Required, must be NSString *.
*/
+ (void)trackUserTickets3DTouchPeekWithEventID:(nonnull NSString *)eventID ticketGroupID:(nonnull NSString *)ticketGroupID;

/**
 * iOS pop on a ticket group.
 *
 * @param eventID Required, must be NSString *.
 * @param ticketGroupID Required, must be NSString *.
*/
+ (void)trackUserTickets3DTouchPopWithEventID:(nonnull NSString *)eventID ticketGroupID:(nonnull NSString *)ticketGroupID;

/**
 * User clicks an action button.
 *
 * @param configurationID Optional, must be NSString * or nil. ID of the rufus configuration.
 * @param configurationName Required, must be NSString *. Name of the rufus configuration.
 * @param domainSlug Optional, must be NSString * or nil. The client slug.
 * @param eventID Required, must be NSString *. ID of the event for which the button was shown.
 * @param linkCtaText Required, must be NSString *. Text in the button.
 * @param targetUrl Optional, must be NSString * or nil. The url that the click takes the user to.
 * @param uICategory Required, must be SGTrackerUserTicketsUICategory. Categorization of UI elements used by the fandom team.
 * @param uIOrigin Required, must be SGTrackerUserTicketsUIOrigin. Short identifier for the part of the UI from which the user clicked.
*/
+ (void)trackUserTicketsActionButtonClickWithConfigurationID:(nullable NSString *)configurationID configurationName:(nonnull NSString *)configurationName domainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID linkCtaText:(nonnull NSString *)linkCtaText targetUrl:(nullable NSString *)targetUrl uICategory:(SGTrackerUserTicketsUICategory)uICategory uIOrigin:(SGTrackerUserTicketsUIOrigin)uIOrigin;

/**
 * User sees an action button.
 *
 * @param configurationID Optional, must be NSString * or nil. ID of the rufus configuration.
 * @param configurationName Required, must be NSString *. Name of the rufus configuration.
 * @param domainSlug Optional, must be NSString * or nil. The client slug.
 * @param eventID Required, must be NSString *. ID of the event for which the button was shown.
 * @param linkCtaText Required, must be NSString *. Text in the button.
 * @param targetUrl Optional, must be NSString * or nil. The url that the click takes the user to.
 * @param uICategory Required, must be SGTrackerUserTicketsUICategory. Categorization of UI elements used by the fandom team.
 * @param uIOrigin Required, must be SGTrackerUserTicketsUIOrigin. Short identifier for the part of the UI from which the user clicked.
*/
+ (void)trackUserTicketsActionButtonShowWithConfigurationID:(nullable NSString *)configurationID configurationName:(nonnull NSString *)configurationName domainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID linkCtaText:(nonnull NSString *)linkCtaText targetUrl:(nullable NSString *)targetUrl uICategory:(SGTrackerUserTicketsUICategory)uICategory uIOrigin:(SGTrackerUserTicketsUIOrigin)uIOrigin;

/**
 * Tapped on a ticket-related item.
 *
 * @param activityType Required, must be SGTrackerUserTicketsActivityType.
 * @param domainSlug Optional, must be NSString * or nil.
 * @param eventID Optional, must be NSString * or nil.
 * @param itemType Required, must be SGTrackerUserTicketsItemType.
 * @param listingID Optional, must be NSString * or nil.
 * @param orderID Optional, must be NSString * or nil.
 * @param styleType Optional, must be NSString * or nil.
 * @param ticketGroupID Optional, must be NSString * or nil.
 * @param transferID Optional, must be NSString * or nil.
 * @param versionID Optional, must be NSString * or nil. The version of the widget.
 * @param widgetID Optional, must be NSString * or nil.
*/
+ (void)trackUserTicketsActionClickWithActivityType:(SGTrackerUserTicketsActivityType)activityType domainSlug:(nullable NSString *)domainSlug eventID:(nullable NSString *)eventID itemType:(SGTrackerUserTicketsItemType)itemType listingID:(nullable NSString *)listingID orderID:(nullable NSString *)orderID styleType:(nullable NSString *)styleType ticketGroupID:(nullable NSString *)ticketGroupID transferID:(nullable NSString *)transferID versionID:(nullable NSString *)versionID widgetID:(nullable NSString *)widgetID;

/**
 * Any time the detail screen for a card (season ticketholder/loyalty/etc) is shown.
 *
 * @param cardID Required, must be NSString *. The ID of the card being shown.
 * @param domainSlug Optional, must be NSString * or nil. The domain slug of the SGO organization this card belongs to.
 * @param performerID Required, must be NSString *. The performer ID associated with this card.
 * @param styleType Required, must be SGTrackerUserTicketsStyleType. The style type of card being shown.
*/
+ (void)trackUserTicketsCardDetailShowWithCardID:(nonnull NSString *)cardID domainSlug:(nullable NSString *)domainSlug performerID:(nonnull NSString *)performerID styleType:(SGTrackerUserTicketsStyleType)styleType;

/**
 * Any time a card (season ticketholder/loyalty/etc) is shown on the screen.
 *
 * @param cardID Required, must be NSString *. The ID of the card being shown.
 * @param domainSlug Optional, must be NSString * or nil. The domain slug of the SGO organization this card belongs to.
 * @param type Required, must be NSString *. The type of card being shown.
*/
+ (void)trackUserTicketsCardShowWithCardID:(nonnull NSString *)cardID domainSlug:(nullable NSString *)domainSlug type:(nonnull NSString *)type;

/**
 * User opens "info" tab in a ticket group.
 *
 * @param eventID Required, must be NSString *.
 * @param ticketGroupID Required, must be NSString *.
 * @param userPurchaseID Optional, must be NSString * or nil.
*/
+ (void)trackUserTicketsDetailShowWithEventID:(nonnull NSString *)eventID ticketGroupID:(nonnull NSString *)ticketGroupID userPurchaseID:(nullable NSString *)userPurchaseID;

/**
 * User opens a My Tickets Event.
 *
 * @param displayType Optional, must be SGTrackerUserTicketsDisplayType or SGTrackerUserTicketsDisplayTypeNone. Whether the event shown is in takeover mode.
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param numberOfActiveListings Required, must be NSInteger.
 * @param numberOfOrderStatuses Required, must be NSInteger.
 * @param numberOfPasses Required, must be NSInteger.
 * @param numberOfPendingTransfers Required, must be NSInteger.
 * @param sourceType Optional, must be SGTrackerUserTicketsSourceType or SGTrackerUserTicketsSourceTypeNone. Where the event was opened from.
 * @param totalTicketGroups Required, must be NSInteger.
*/
+ (void)trackUserTicketsEventShowWithDisplayType:(SGTrackerUserTicketsDisplayType)displayType domainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID numberOfActiveListings:(NSInteger)numberOfActiveListings numberOfOrderStatuses:(NSInteger)numberOfOrderStatuses numberOfPasses:(NSInteger)numberOfPasses numberOfPendingTransfers:(NSInteger)numberOfPendingTransfers sourceType:(SGTrackerUserTicketsSourceType)sourceType totalTicketGroups:(NSInteger)totalTicketGroups;

/**
 * User view the order details for an event.
 *
 * @param displayValue Required, must be NSString *. The order status's status text.
 * @param eventID Required, must be NSString *. The order status's event.
 * @param orderID Required, must be NSString *.
 * @param parentEventID Optional, must be NSString * or nil. The order status's event. This is the same value as event_id.
*/
+ (void)trackUserTicketsOrderDetailsShowWithDisplayValue:(nonnull NSString *)displayValue eventID:(nonnull NSString *)eventID orderID:(nonnull NSString *)orderID parentEventID:(nullable NSString *)parentEventID;

/**
 * User view the order status for an event.
 *
 * @param displayValue Required, must be NSString *. The order status's status text.
 * @param eventID Required, must be NSString *. The order status's event.
 * @param orderID Required, must be NSString *.
 * @param parentEventID Optional, must be NSString * or nil. The order status's event. This is the same value as event_id.
*/
+ (void)trackUserTicketsOrderStatusShowWithDisplayValue:(nonnull NSString *)displayValue eventID:(nonnull NSString *)eventID orderID:(nonnull NSString *)orderID parentEventID:(nullable NSString *)parentEventID;

/**
 * A user takes a screenshot of a ticket and an alert pops up.
 *
 * @param barcodeType Optional, must be SGTrackerUserTicketsBarcodeType or SGTrackerUserTicketsBarcodeTypeNone. The type of barcode that a user took a screenshot of. If there are multiple ticket groups, and no barcode is shown, the value should be 'none'..
 * @param displayType Optional, must be SGTrackerUserTicketsDisplayType or SGTrackerUserTicketsDisplayTypeNone. Whether the ticket was shown as a barcode or a PDF or something else.
 * @param viewType Required, must be SGTrackerUserTicketsViewType. The specific state of the screen where we displayed an alert after a user took a screenshot. If there are multiple ticket groups, and no barcode is shown, the value should be 'none'..
*/
+ (void)trackUserTicketsScreenshotAlertWithBarcodeType:(SGTrackerUserTicketsBarcodeType)barcodeType displayType:(SGTrackerUserTicketsDisplayType)displayType viewType:(SGTrackerUserTicketsViewType)viewType;

/**
 * My Tickets is loaded.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param pastTicketGroups Required, must be NSInteger.
 * @param pendingTicketGroups Required, must be NSInteger.
 * @param totalTicketGroups Required, must be NSInteger.
 * @param upcomingTicketGroups Required, must be NSInteger.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackUserTicketsShowWithDomainSlug:(nullable NSString *)domainSlug pastTicketGroups:(NSInteger)pastTicketGroups pendingTicketGroups:(NSInteger)pendingTicketGroups totalTicketGroups:(NSInteger)totalTicketGroups upcomingTicketGroups:(NSInteger)upcomingTicketGroups viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * User taps either a button or thumbnail to view a full PDF for ticket group or individual ticket.
 *
 * @param displayType Optional, must be SGTrackerUserTicketsDisplayType or SGTrackerUserTicketsDisplayTypeNone. Whether the ticket was shown as a barcode or a PDF.
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param quantity Required, must be NSInteger. The number of tickets in the PDF being downloaded or viewed.
 * @param ticketGroupID Required, must be NSString *.
 * @param ticketID Optional, must be NSString * or nil.
*/
+ (void)trackUserTicketsTicketDownloadWithDisplayType:(SGTrackerUserTicketsDisplayType)displayType domainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID quantity:(NSInteger)quantity ticketGroupID:(nonnull NSString *)ticketGroupID ticketID:(nullable NSString *)ticketID;

/**
 * User opens a ticket group.
 *
 * @param eventID Required, must be NSString *. The ticket group's event.
 * @param parentEventID Optional, must be NSString * or nil. The ticket group's event's parent event. This value will be different than event_id when the ticket is a pass or an add-on such as parking..
 * @param ticketGroupID Required, must be NSString *.
 * @param ticketType Optional, must be NSString * or nil. This value is the ticket group's pass_type if it exists, otherwise the value is `regular`.
*/
+ (void)trackUserTicketsTicketGroupNotesShowWithEventID:(nonnull NSString *)eventID parentEventID:(nullable NSString *)parentEventID ticketGroupID:(nonnull NSString *)ticketGroupID ticketType:(nullable NSString *)ticketType;

/**
 * User opens a ticket group.
 *
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param parentEventID Optional, must be NSString * or nil. The ticket group's event's parent event. This value will be different than event_id when the ticket is a pass or an add-on such as parking..
 * @param quantity Required, must be NSInteger.
 * @param ticketGroupID Required, must be NSString *.
 * @param ticketType Optional, must be NSString * or nil. This value is the ticket group's pass_type if it exists, otherwise the value is `regular`.
 * @param viewMode Optional, must be SGTrackerMyTicketsViewMode or SGTrackerMyTicketsViewModeNone. The version of My Tickets the user is viewing. Compact is for 'powerseller' mode..
*/
+ (void)trackUserTicketsTicketGroupShowWithDomainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID parentEventID:(nullable NSString *)parentEventID quantity:(NSInteger)quantity ticketGroupID:(nonnull NSString *)ticketGroupID ticketType:(nullable NSString *)ticketType viewMode:(SGTrackerMyTicketsViewMode)viewMode;

/**
 * Any time a ticket barcode is shown on the screen, including swiping back and forth through a list of barcodes.
 *
 * @param appleWalletButtonShown Optional, must be @(YES), @(NO), or nil. Whether the Apple Wallet button was shown for a ticket.
 * @param barcodeType Optional, must be SGTrackerUserTicketsBarcodeType or SGTrackerUserTicketsBarcodeTypeNone. This value is the ticket's barcode type.
 * @param displayType Required, must be SGTrackerUserTicketsDisplayType. Whether the ticket was shown as a barcode or a PDF.
 * @param domainSlug Optional, must be NSString * or nil. The slug for the user's SG Open domain.
 * @param eventID Required, must be NSString *.
 * @param googlePayPassButtonShown Optional, must be @(YES), @(NO), or nil. Whether the Google Pay Passes button was shown for a ticket.
 * @param parentEventID Optional, must be NSString * or nil. The ticket's event's parent event. This value will be different than event_id when the ticket is a pass or an add-on such as parking..
 * @param ticketGroupID Required, must be NSString *.
 * @param ticketID Required, must be NSString *.
 * @param ticketType Optional, must be NSString * or nil. This value is the ticket group's pass_type if it exists, otherwise the value is `regular`.
 * @param userPurchaseID Optional, must be NSString * or nil.
*/
+ (void)trackUserTicketsTicketShowWithAppleWalletButtonShown:(nullable NSNumber *)appleWalletButtonShown barcodeType:(SGTrackerUserTicketsBarcodeType)barcodeType displayType:(SGTrackerUserTicketsDisplayType)displayType domainSlug:(nullable NSString *)domainSlug eventID:(nonnull NSString *)eventID googlePayPassButtonShown:(nullable NSNumber *)googlePayPassButtonShown parentEventID:(nullable NSString *)parentEventID ticketGroupID:(nonnull NSString *)ticketGroupID ticketID:(nonnull NSString *)ticketID ticketType:(nullable NSString *)ticketType userPurchaseID:(nullable NSString *)userPurchaseID;

/**
 * User clicks on the widget hint in My Tickets.
 *
 * @param displayValue Optional, must be NSString * or nil. The hint text we show the user to notify them about widgets below the fold.
 * @param eventID Required, must be NSString *.
 * @param numberOfWidgets Required, must be NSInteger.
 * @param versionID Optional, must be NSString * or nil. The version of the widget that is driving the hint.
 * @param widgetID Required, must be NSString *. The id of the widget that is driving the hint.
*/
+ (void)trackUserTicketsWidgetHintClickWithDisplayValue:(nullable NSString *)displayValue eventID:(nonnull NSString *)eventID numberOfWidgets:(NSInteger)numberOfWidgets versionID:(nullable NSString *)versionID widgetID:(nonnull NSString *)widgetID;

/**
 * User is shown the widget hint in My Tickets.
 *
 * @param displayValue Optional, must be NSString * or nil. The hint text we show the user to notify them about widgets below the fold.
 * @param eventID Required, must be NSString *.
 * @param numberOfWidgets Required, must be NSInteger.
 * @param versionID Optional, must be NSString * or nil. The version of the widget that is driving the hint.
 * @param widgetID Required, must be NSString *. The id of the widget that is driving the hint.
*/
+ (void)trackUserTicketsWidgetHintShowWithDisplayValue:(nullable NSString *)displayValue eventID:(nonnull NSString *)eventID numberOfWidgets:(NSInteger)numberOfWidgets versionID:(nullable NSString *)versionID widgetID:(nonnull NSString *)widgetID;

/**
 * Widget is loaded in Event Tickets Screen.
 *
 * @param eventID Required, must be NSString *.
 * @param versionID Optional, must be NSString * or nil. The version of the widget.
 * @param widgetID Required, must be NSString *.
*/
+ (void)trackUserTicketsWidgetLoadWithEventID:(nonnull NSString *)eventID versionID:(nullable NSString *)versionID widgetID:(nonnull NSString *)widgetID;

/**
 * User is shown a widget in My Tickets.
 *
 * @param eventID Required, must be NSString *.
 * @param versionID Optional, must be NSString * or nil. The version of the widget.
 * @param widgetID Required, must be NSString *.
*/
+ (void)trackUserTicketsWidgetShowWithEventID:(nonnull NSString *)eventID versionID:(nullable NSString *)versionID widgetID:(nonnull NSString *)widgetID;

/**
 * User is shown the form to enter a backup code to disable 2FA.
*/
+ (void)trackUserTwoFABackupFormShow;

/**
 * User submits a backup code to disable 2FA.
 *
 * @param twoFAMode Optional, must be SGTrackerUserTwoFAMode or SGTrackerUserTwoFAModeNone. The method used for 2FA, if any.
*/
+ (void)trackUserTwoFABackupFormSubmitWithTwoFAMode:(SGTrackerUserTwoFAMode)twoFAMode;

/**
 * User tries and fails to disable 2FA.
 *
 * @param errorCode Required, must be NSInteger. The error code returned by the API, or other error code in the event of, e.g., network errors.
 * @param errorMessage Required, must be NSString *. The user-facing error message, if applicable.
 * @param twoFAMode Optional, must be SGTrackerUserTwoFAMode or SGTrackerUserTwoFAModeNone. The method used for 2FA, if any.
 * @param uIOrigin Optional, must be SGTrackerUserTwoFAUIOrigin or SGTrackerUserTwoFAUIOriginNone.
*/
+ (void)trackUserTwoFADisableErrorWithErrorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage twoFAMode:(SGTrackerUserTwoFAMode)twoFAMode uIOrigin:(SGTrackerUserTwoFAUIOrigin)uIOrigin;

/**
 * User is shown the screen to disable 2FA.
 *
 * @param twoFAMode Required, must be SGTrackerUserTwoFAMode. The method used for 2FA, if any.
*/
+ (void)trackUserTwoFADisableShowWithTwoFAMode:(SGTrackerUserTwoFAMode)twoFAMode;

/**
 * User submits a code in order to disable 2FA.
 *
 * @param twoFAMode Required, must be SGTrackerUserTwoFAMode. The method used for 2FA, if any.
*/
+ (void)trackUserTwoFADisableSubmitWithTwoFAMode:(SGTrackerUserTwoFAMode)twoFAMode;

/**
 * User successfully disables 2FA.
 *
 * @param twoFAMode Optional, must be SGTrackerUserTwoFAMode or SGTrackerUserTwoFAModeNone. The method used for 2FA, if any.
 * @param uIOrigin Optional, must be SGTrackerUserTwoFAUIOrigin or SGTrackerUserTwoFAUIOriginNone.
*/
+ (void)trackUserTwoFADisableSuccessWithTwoFAMode:(SGTrackerUserTwoFAMode)twoFAMode uIOrigin:(SGTrackerUserTwoFAUIOrigin)uIOrigin;

/**
 * User tries and fails to activate 2FA.
 *
 * @param errorCode Required, must be NSInteger. The error code returned by the API, or other error code in the event of, e.g., network errors.
 * @param errorMessage Required, must be NSString *. The user-facing error message, if applicable.
 * @param twoFAMode Required, must be SGTrackerUserTwoFAMode. The method used for 2FA, if any.
*/
+ (void)trackUserTwoFAEnableErrorWithErrorCode:(NSInteger)errorCode errorMessage:(nonnull NSString *)errorMessage twoFAMode:(SGTrackerUserTwoFAMode)twoFAMode;

/**
 * User is shown the app or SMS 2FA activation screen.
 *
 * @param twoFAMode Required, must be SGTrackerUserTwoFAMode. The method used for 2FA, if any.
*/
+ (void)trackUserTwoFAEnableShowWithTwoFAMode:(SGTrackerUserTwoFAMode)twoFAMode;

/**
 * User submits a code to activate 2FA.
 *
 * @param twoFAMode Required, must be SGTrackerUserTwoFAMode. The method used for 2FA, if any.
*/
+ (void)trackUserTwoFAEnableSubmitWithTwoFAMode:(SGTrackerUserTwoFAMode)twoFAMode;

/**
 * User successfully activates 2FA.
 *
 * @param twoFAMode Required, must be SGTrackerUserTwoFAMode. The method used for 2FA, if any.
*/
+ (void)trackUserTwoFAEnableSuccessWithTwoFAMode:(SGTrackerUserTwoFAMode)twoFAMode;

/**
 * The request to send a user a new 2FA verification code failed.
 *
 * @param errorCode Optional, must be NSInteger or NSNotFound. The error code returned by the API, or other error code in the event of, e.g., network errors.
 * @param errorMessage Optional, must be NSString * or nil. The user-facing error message, if applicable.
 * @param uIOrigin Optional, must be SGTrackerUserTwoFAUIOrigin or SGTrackerUserTwoFAUIOriginNone.
*/
+ (void)trackUserTwoFAResendErrorWithErrorCode:(NSInteger)errorCode errorMessage:(nullable NSString *)errorMessage uIOrigin:(SGTrackerUserTwoFAUIOrigin)uIOrigin;

/**
 * User taps to have their 2FA verification code resent.
 *
 * @param uIOrigin Optional, must be SGTrackerUserTwoFAUIOrigin or SGTrackerUserTwoFAUIOriginNone.
*/
+ (void)trackUserTwoFAResendSubmitWithUIOrigin:(SGTrackerUserTwoFAUIOrigin)uIOrigin;

/**
 * The request to send a user a new 2FA verification code succeeded.
 *
 * @param uIOrigin Optional, must be SGTrackerUserTwoFAUIOrigin or SGTrackerUserTwoFAUIOriginNone.
*/
+ (void)trackUserTwoFAResendSuccessWithUIOrigin:(SGTrackerUserTwoFAUIOrigin)uIOrigin;

/**
 * User is shown a screen asking to verify account ownership via 2FA.
*/
+ (void)trackUserTwoFAVerifyShow;

/**
 * User submits a 2FA code during the login flow.
*/
+ (void)trackUserTwoFAVerifySubmit;

/**
 * Modal shown telling user they need to verify their contact info every time the My Tickets list loads.
 *
 * @param contactType Required, must be SGTrackerUserUnverifiedContactAlertContactType.
*/
+ (void)trackUserUnverifiedContactAlertShowWithContactType:(SGTrackerUserUnverifiedContactAlertContactType)contactType;

/**
 * User interacts with in-venue commerce order status in Event Tickets view.
 *
 * @param eventID Required, must be NSString *.
 * @param productType Required, must be SGTrackerUserVenueCommerceProductType.
 * @param status Required, must be NSString *.
*/
+ (void)trackUserVenueCommerceOrderStatusActionWithEventID:(nonnull NSString *)eventID productType:(SGTrackerUserVenueCommerceProductType)productType status:(nonnull NSString *)status;

/**
 * User sees in-venue commerce order status in Event Tickets view.
 *
 * @param eventID Required, must be NSString *.
 * @param productType Required, must be SGTrackerUserVenueCommerceProductType.
 * @param status Required, must be NSString *.
*/
+ (void)trackUserVenueCommerceOrderStatusShowWithEventID:(nonnull NSString *)eventID productType:(SGTrackerUserVenueCommerceProductType)productType status:(nonnull NSString *)status;

/**
 * User adds item to cart in VenueNext SDK (trackAddToCart).
 *
 * @param domainSlug Required, must be NSString *.
 * @param eventID Required, must be NSString *.
 * @param itemCategory Optional, must be NSString * or nil.
 * @param itemID Required, must be NSString *.
 * @param itemName Optional, must be NSString * or nil.
 * @param price Optional, must be NSNumber * or nil.
 * @param quantity Optional, must be NSInteger or NSNotFound.
 * @param uIOrigin Required, must be SGTrackerVenueCommerceUIOrigin.
 * @param variant Optional, must be NSString * or nil.
*/
+ (void)trackUserVenueCommerceSdkAddToCartWithDomainSlug:(nonnull NSString *)domainSlug eventID:(nonnull NSString *)eventID itemCategory:(nullable NSString *)itemCategory itemID:(nonnull NSString *)itemID itemName:(nullable NSString *)itemName price:(nullable NSNumber *)price quantity:(NSInteger)quantity uIOrigin:(SGTrackerVenueCommerceUIOrigin)uIOrigin variant:(nullable NSString *)variant;

/**
 * User enters checkout flow in VenueNext SDK (trackBeginCheckout).
 *
 * @param domainSlug Required, must be NSString *.
 * @param eventID Required, must be NSString *.
 * @param uIOrigin Required, must be SGTrackerVenueCommerceUIOrigin.
*/
+ (void)trackUserVenueCommerceSdkBeginCheckoutWithDomainSlug:(nonnull NSString *)domainSlug eventID:(nonnull NSString *)eventID uIOrigin:(SGTrackerVenueCommerceUIOrigin)uIOrigin;

/**
 * User progresses to new state in checkout flow in VenueNext SDK (trackCheckoutProgress).
 *
 * @param domainSlug Required, must be NSString *.
 * @param eventID Required, must be NSString *.
 * @param orderState Required, must be NSString *.
 * @param uIOrigin Required, must be SGTrackerVenueCommerceUIOrigin.
*/
+ (void)trackUserVenueCommerceSdkCheckoutProgressWithDomainSlug:(nonnull NSString *)domainSlug eventID:(nonnull NSString *)eventID orderState:(nonnull NSString *)orderState uIOrigin:(SGTrackerVenueCommerceUIOrigin)uIOrigin;

/**
 * User selects a menu item in VenueNext SDK (trackMenuItemSelection).
 *
 * @param domainSlug Required, must be NSString *.
 * @param eventID Required, must be NSString *.
 * @param itemCategory Optional, must be NSString * or nil.
 * @param itemID Required, must be NSString *.
 * @param itemName Optional, must be NSString * or nil.
 * @param price Optional, must be NSNumber * or nil.
 * @param uIOrigin Required, must be SGTrackerVenueCommerceUIOrigin.
 * @param variant Optional, must be NSString * or nil.
*/
+ (void)trackUserVenueCommerceSdkMenuItemSelectionWithDomainSlug:(nonnull NSString *)domainSlug eventID:(nonnull NSString *)eventID itemCategory:(nullable NSString *)itemCategory itemID:(nonnull NSString *)itemID itemName:(nullable NSString *)itemName price:(nullable NSNumber *)price uIOrigin:(SGTrackerVenueCommerceUIOrigin)uIOrigin variant:(nullable NSString *)variant;

/**
 * User completes a purchase attempt in the VenueNext SDK (trackPurchase).
 *
 * @param discountAmount Optional, must be NSNumber * or nil.
 * @param domainSlug Required, must be NSString *.
 * @param eventID Required, must be NSString *.
 * @param orderID Required, must be NSString *.
 * @param quantity Optional, must be NSInteger or NSNotFound.
 * @param tax Optional, must be NSNumber * or nil.
 * @param tipAmount Optional, must be NSNumber * or nil.
 * @param totalPrice Optional, must be NSNumber * or nil.
 * @param uIOrigin Required, must be SGTrackerVenueCommerceUIOrigin.
*/
+ (void)trackUserVenueCommerceSdkPurchaseWithDiscountAmount:(nullable NSNumber *)discountAmount domainSlug:(nonnull NSString *)domainSlug eventID:(nonnull NSString *)eventID orderID:(nonnull NSString *)orderID quantity:(NSInteger)quantity tax:(nullable NSNumber *)tax tipAmount:(nullable NSNumber *)tipAmount totalPrice:(nullable NSNumber *)totalPrice uIOrigin:(SGTrackerVenueCommerceUIOrigin)uIOrigin;

/**
 * User removes an item from their cart in the VenueNext SDK (trackRemoveFromCart).
 *
 * @param domainSlug Required, must be NSString *.
 * @param eventID Required, must be NSString *.
 * @param itemCategory Optional, must be NSString * or nil.
 * @param itemID Required, must be NSString *.
 * @param itemName Optional, must be NSString * or nil.
 * @param price Optional, must be NSNumber * or nil.
 * @param quantity Optional, must be NSInteger or NSNotFound.
 * @param uIOrigin Required, must be SGTrackerVenueCommerceUIOrigin.
 * @param variant Optional, must be NSString * or nil.
*/
+ (void)trackUserVenueCommerceSdkRemoveFromCartWithDomainSlug:(nonnull NSString *)domainSlug eventID:(nonnull NSString *)eventID itemCategory:(nullable NSString *)itemCategory itemID:(nonnull NSString *)itemID itemName:(nullable NSString *)itemName price:(nullable NSNumber *)price quantity:(NSInteger)quantity uIOrigin:(SGTrackerVenueCommerceUIOrigin)uIOrigin variant:(nullable NSString *)variant;

/**
 * User views a screen in the VenueNext SDK (trackScreenView).
 *
 * @param domainSlug Required, must be NSString *.
 * @param eventID Required, must be NSString *.
 * @param screenName Required, must be NSString *.
 * @param uIOrigin Required, must be SGTrackerVenueCommerceUIOrigin.
*/
+ (void)trackUserVenueCommerceSdkScreenViewWithDomainSlug:(nonnull NSString *)domainSlug eventID:(nonnull NSString *)eventID screenName:(nonnull NSString *)screenName uIOrigin:(SGTrackerVenueCommerceUIOrigin)uIOrigin;

/**
 * User clicks to track a venue.
 *
 * @param interactionMethod Optional, must be SGTrackerUserVenueInteractionMethod or SGTrackerUserVenueInteractionMethodNone. Hardware-specific description of how the action was invoked if other than with the default tap or click.
 * @param uIOrigin Optional, must be SGTrackerUserVenueUIOrigin or SGTrackerUserVenueUIOriginNone. Short identifier for the part of the UI from which the user tracked the venue (e.g. event, performer).
 * @param venueID Required, must be NSString *.
*/
+ (void)trackUserVenueTrackWithInteractionMethod:(SGTrackerUserVenueInteractionMethod)interactionMethod uIOrigin:(SGTrackerUserVenueUIOrigin)uIOrigin venueID:(nonnull NSString *)venueID;

/**
 * User clicks to untrack a venue.
 *
 * @param interactionMethod Optional, must be SGTrackerUserVenueInteractionMethod or SGTrackerUserVenueInteractionMethodNone. Hardware-specific description of how the action was invoked if other than with the default tap or click.
 * @param uIOrigin Optional, must be SGTrackerUserVenueUIOrigin or SGTrackerUserVenueUIOriginNone. Short identifier for the part of the UI from which the user untracked the venue.
 * @param venueID Required, must be NSString *.
*/
+ (void)trackUserVenueUntrackWithInteractionMethod:(SGTrackerUserVenueInteractionMethod)interactionMethod uIOrigin:(SGTrackerUserVenueUIOrigin)uIOrigin venueID:(nonnull NSString *)venueID;

/**
 * iOS peek on a venue.
 *
 * @param venueID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTracker3DTouchUIOrigin or SGTracker3DTouchUIOriginNone. Short identifier for the part of the UI from which the peek occurred.
*/
+ (void)trackVenue3DTouchPeekWithVenueID:(nonnull NSString *)venueID uIOrigin:(SGTracker3DTouchUIOrigin)uIOrigin;

/**
 * iOS pop on a venue.
 *
 * @param venueID Required, must be NSString *.
 * @param uIOrigin Optional, must be SGTracker3DTouchUIOrigin or SGTracker3DTouchUIOriginNone. Short identifier for the part of the UI from which the peek occurred.
*/
+ (void)trackVenue3DTouchPopWithVenueID:(nonnull NSString *)venueID uIOrigin:(SGTracker3DTouchUIOrigin)uIOrigin;

/**
 * Link to venue screen is tapped.
 *
 * @param absoluteRank Optional, must be NSInteger or NSNotFound. The absolute rank of the venue within the parent..
 * @param autocompleteRequestID Optional, must be NSString * or nil. The unique id for the query sent to autocomplete that generated the result set..
 * @param isRecentSearch Optional, must be @(YES), @(NO), or nil. Flag indicating whether or not the selected searchbar dropdown item was a recent search..
 * @param itemStyleType Optional, must be NSString * or nil. The venue item's style type. This will come from the server and be things like 'venue_normal'..
 * @param listID Optional, must be NSString * or nil. The venue's parent container's list_id..
 * @param listKey Optional, must be NSString * or nil. The stable, human-readable identifier of the list containing this venue..
 * @param listStyleType Optional, must be NSString * or nil. The style type of the list the venue is in. This will come from the server and be things like 'list_horizontal' and 'list_vertical'..
 * @param listTitle Optional, must be NSString * or nil. The name of the list -- as the user sees it -- that contains the list item..
 * @param maxItemsInView Optional, must be NSInteger or NSNotFound. The max number of items that can be shown in the venue's parent at any time..
 * @param parentRank Optional, must be NSInteger or NSNotFound. The rank of the venue's container relative to the other containers displayed with it..
 * @param passType Optional, must be NSString * or nil. The type of pass if applicable, e.g. parking, represented in the search result..
 * @param query Optional, must be NSString * or nil.
 * @param relativeRank Optional, must be NSInteger or NSNotFound. The rank of the venue relative to the user's viewport..
 * @param score Optional, must be NSNumber * or nil.
 * @param uIOrigin Required, must be SGTrackerVenueUIOrigin. Short identifier for the part of the UI from which the user clicked the venue.
 * @param venueID Required, must be NSString *.
*/
+ (void)trackVenueClickWithAbsoluteRank:(NSInteger)absoluteRank autocompleteRequestID:(nullable NSString *)autocompleteRequestID isRecentSearch:(nullable NSNumber *)isRecentSearch itemStyleType:(nullable NSString *)itemStyleType listID:(nullable NSString *)listID listKey:(nullable NSString *)listKey listStyleType:(nullable NSString *)listStyleType listTitle:(nullable NSString *)listTitle maxItemsInView:(NSInteger)maxItemsInView parentRank:(NSInteger)parentRank passType:(nullable NSString *)passType query:(nullable NSString *)query relativeRank:(NSInteger)relativeRank score:(nullable NSNumber *)score uIOrigin:(SGTrackerVenueUIOrigin)uIOrigin venueID:(nonnull NSString *)venueID;

/**
 * User taps Get Directions button.
 *
 * @param directionMethod Optional, must be SGTrackerVenueDirectionsDirectionMethod or SGTrackerVenueDirectionsDirectionMethodNone. What kind of directions were requested if available.
 * @param uIOrigin Optional, must be SGTrackerVenueDirectionsUIOrigin or SGTrackerVenueDirectionsUIOriginNone. Short identifier for the part of the UI from which the user tapped the Get Directions button.
 * @param venueID Required, must be NSString *.
*/
+ (void)trackVenueDirectionsClickWithDirectionMethod:(SGTrackerVenueDirectionsDirectionMethod)directionMethod uIOrigin:(SGTrackerVenueDirectionsUIOrigin)uIOrigin venueID:(nonnull NSString *)venueID;

/**
 * Venue screen loads.
 *
 * @param pageType Optional, must be NSString * or nil. Which type of the venue page the user was shown. We send type = 'events' for :shows of the regular events screen , or a lowercased version of the `pass_type` that comes back from the Autocomplete response, i.e., parking screen comes from the `pass_type` of 'parking', and the club passes screen comes from the `pass_type` of 'club_passes'..
 * @param totalEvents Required, must be NSInteger.
 * @param venueCity Optional, must be NSString * or nil. Venue city.
 * @param venueID Required, must be NSString *.
 * @param venueName Optional, must be NSString * or nil.
 * @param venueState Optional, must be NSString * or nil. Venue state.
*/
+ (void)trackVenueShowWithPageType:(nullable NSString *)pageType totalEvents:(NSInteger)totalEvents venueCity:(nullable NSString *)venueCity venueID:(nonnull NSString *)venueID venueName:(nullable NSString *)venueName venueState:(nullable NSString *)venueState;


@end
