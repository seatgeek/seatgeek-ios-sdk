//
//  SGTrackerEnums.h
//  Pods
//
//  Version 18.27.2 created by the Tracker Service using ios_generate_classes.py.
//
//

typedef NS_ENUM(NSUInteger, SGTrackerGlobalUIOrigin) {
    SGTrackerGlobalUIOriginAccessCodeModal,
    SGTrackerGlobalUIOriginAccountSettings,
    SGTrackerGlobalUIOriginAllEvents,
    SGTrackerGlobalUIOriginAllSearchResults,
    SGTrackerGlobalUIOriginAppForeground,
    SGTrackerGlobalUIOriginBestAvailableForm,
    SGTrackerGlobalUIOriginBrowse,
    SGTrackerGlobalUIOriginBrowseSearch,
    SGTrackerGlobalUIOriginBrowseSearchDefaultSuggestion,
    SGTrackerGlobalUIOriginCategory,
    SGTrackerGlobalUIOriginCategorySidebar,
    SGTrackerGlobalUIOriginCheckout,
    SGTrackerGlobalUIOriginCheckoutPromocode,
    SGTrackerGlobalUIOriginCity,
    SGTrackerGlobalUIOriginClubPasses,
    SGTrackerGlobalUIOriginCollectionsBar,
    SGTrackerGlobalUIOriginContextualPushPrompt,
    SGTrackerGlobalUIOriginDebug,
    SGTrackerGlobalUIOriginDeeplink,
    SGTrackerGlobalUIOriginDrawer,
    SGTrackerGlobalUIOriginEmailModal,
    SGTrackerGlobalUIOriginEvent,
    SGTrackerGlobalUIOriginEventBanner,
    SGTrackerGlobalUIOriginEventCollectionsBar,
    SGTrackerGlobalUIOriginEventEmptyStateScreen,
    SGTrackerGlobalUIOriginEventFilters,
    SGTrackerGlobalUIOriginEventFiltersMenu,
    SGTrackerGlobalUIOriginEventInfo,
    SGTrackerGlobalUIOriginEventInitialLoad,
    SGTrackerGlobalUIOriginEventListingsHeader,
    SGTrackerGlobalUIOriginEventNav,
    SGTrackerGlobalUIOriginEventPage,
    SGTrackerGlobalUIOriginEventPreOnsale,
    SGTrackerGlobalUIOriginEventSidebar,
    SGTrackerGlobalUIOriginEventTickets,
    SGTrackerGlobalUIOriginEventTicketsHelpPill,
    SGTrackerGlobalUIOriginEventTitle,
    SGTrackerGlobalUIOriginEventsNearby,
    SGTrackerGlobalUIOriginExchangeModal,
    SGTrackerGlobalUIOriginFacebookAccountUpgrade,
    SGTrackerGlobalUIOriginFilterModal,
    SGTrackerGlobalUIOriginFilterSortModal,
    SGTrackerGlobalUIOriginForgotPassword,
    SGTrackerGlobalUIOriginHbaModal,
    SGTrackerGlobalUIOriginHelpCenter,
    SGTrackerGlobalUIOriginHome,
    SGTrackerGlobalUIOriginHomeSearch,
    SGTrackerGlobalUIOriginHomeSidebar,
    SGTrackerGlobalUIOriginHomepage,
    SGTrackerGlobalUIOriginHorizontalList,
    SGTrackerGlobalUIOriginiMessage,
    SGTrackerGlobalUIOriginInitialOnboarding,
    SGTrackerGlobalUIOriginiOSToday,
    SGTrackerGlobalUIOriginList,
    SGTrackerGlobalUIOriginListingDetail,
    SGTrackerGlobalUIOriginLocationSearch,
    SGTrackerGlobalUIOriginLogIn,
    SGTrackerGlobalUIOriginLogin,
    SGTrackerGlobalUIOriginLogin2Fa,
    SGTrackerGlobalUIOriginLottery,
    SGTrackerGlobalUIOriginMatchup,
    SGTrackerGlobalUIOriginModal,
    SGTrackerGlobalUIOriginMyTickets,
    SGTrackerGlobalUIOriginMyTicketsTicket,
    SGTrackerGlobalUIOriginNag,
    SGTrackerGlobalUIOriginNavBarButton,
    SGTrackerGlobalUIOriginNavBarDropdown,
    SGTrackerGlobalUIOriginNavBarSearch,
    SGTrackerGlobalUIOriginNavBarTrackTickets,
    SGTrackerGlobalUIOriginNflListSeatgeekUpsell,
    SGTrackerGlobalUIOriginNotification,
    SGTrackerGlobalUIOriginOnboarding,
    SGTrackerGlobalUIOriginPaidTransfer,
    SGTrackerGlobalUIOriginParking,
    SGTrackerGlobalUIOriginPerformer,
    SGTrackerGlobalUIOriginPerformerAllEvents,
    SGTrackerGlobalUIOriginPerformerCalendar,
    SGTrackerGlobalUIOriginPerformerClubPasses,
    SGTrackerGlobalUIOriginPerformerNearbyEvents,
    SGTrackerGlobalUIOriginPerformerParking,
    SGTrackerGlobalUIOriginPerformerPremiumSeats,
    SGTrackerGlobalUIOriginPerformerSidebar,
    SGTrackerGlobalUIOriginPerformerSimilarEvents,
    SGTrackerGlobalUIOriginPostPurchase,
    SGTrackerGlobalUIOriginPremiumSeats,
    SGTrackerGlobalUIOriginPromocodeLandingPage,
    SGTrackerGlobalUIOriginPublicSale,
    SGTrackerGlobalUIOriginRecurringEvent,
    SGTrackerGlobalUIOriginReferralInvites,
    SGTrackerGlobalUIOriginRegister,
    SGTrackerGlobalUIOriginResaleFlow,
    SGTrackerGlobalUIOriginSearch,
    SGTrackerGlobalUIOriginSeatingChartBestDeal,
    SGTrackerGlobalUIOriginSeatingChartFtEvents,
    SGTrackerGlobalUIOriginSeatingChartLowestPrice,
    SGTrackerGlobalUIOriginSeatingChartNextEvent,
    SGTrackerGlobalUIOriginSellLanding,
    SGTrackerGlobalUIOriginSellTickets,
    SGTrackerGlobalUIOriginSettings,
    SGTrackerGlobalUIOriginSettingsDisable,
    SGTrackerGlobalUIOriginSettingsEnable,
    SGTrackerGlobalUIOriginSettingsPromocode,
    SGTrackerGlobalUIOriginShortcutDynamicRecommendedEvent,
    SGTrackerGlobalUIOriginShortcutDynamicTicket,
    SGTrackerGlobalUIOriginShortcutDynamicTrackedEvent,
    SGTrackerGlobalUIOriginShortcutMyTickets,
    SGTrackerGlobalUIOriginShortcutSearch,
    SGTrackerGlobalUIOriginShortcutTracking,
    SGTrackerGlobalUIOriginStandalone,
    SGTrackerGlobalUIOriginTabSearch,
    SGTrackerGlobalUIOriginTickets,
    SGTrackerGlobalUIOriginTracking,
    SGTrackerGlobalUIOriginTrackingDashboard,
    SGTrackerGlobalUIOriginTransfer,
    SGTrackerGlobalUIOriginVenue,
    SGTrackerGlobalUIOriginVenueSeatingChart,
    SGTrackerGlobalUIOriginVenueSidebar,
    SGTrackerGlobalUIOriginVenuenext,
    SGTrackerGlobalUIOriginVerticalList,
    SGTrackerGlobalUIOriginZendeskSupportSdk,
    SGTrackerGlobalUIOriginNone,
};


typedef NS_ENUM(NSUInteger, SGTrackerApplewalletDisplayType) {
    SGTrackerApplewalletDisplayTypeBarcode,
    SGTrackerApplewalletDisplayTypePDF,
    SGTrackerApplewalletDisplayTypeScreenshot,
    SGTrackerApplewalletDisplayTypePlaceholder,
    SGTrackerApplewalletDisplayTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerApplewalletUIOrigin) {
    SGTrackerApplewalletUIOriginMyTicketsTicket,
    SGTrackerApplewalletUIOriginGlobal,
    SGTrackerApplewalletUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerAuthenticatedLinkUIOrigin) {
    SGTrackerAuthenticatedLinkUIOriginAccountSettings,
    SGTrackerAuthenticatedLinkUIOriginLogIn,
    SGTrackerAuthenticatedLinkUIOriginFacebookAccountUpgrade,
    SGTrackerAuthenticatedLinkUIOriginEventTickets,
    SGTrackerAuthenticatedLinkUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerBrowseFilterFilterType) {
    SGTrackerBrowseFilterFilterTypeCalendar,
    SGTrackerBrowseFilterFilterTypeLocation,
    SGTrackerBrowseFilterFilterTypeQuickDate,
    SGTrackerBrowseFilterFilterTypeOuter,
    SGTrackerBrowseFilterFilterTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutErrorCategory) {
    SGTrackerCheckoutErrorCategoryAffirm,
    SGTrackerCheckoutErrorCategoryContact,
    SGTrackerCheckoutErrorCategoryDeliveryMethod,
    SGTrackerCheckoutErrorCategoryFatal,
    SGTrackerCheckoutErrorCategoryGeneral,
    SGTrackerCheckoutErrorCategoryPayment,
    SGTrackerCheckoutErrorCategoryProduct,
    SGTrackerCheckoutErrorCategoryShippingAddress,
    SGTrackerCheckoutErrorCategoryUnknown,
    SGTrackerCheckoutErrorCategoryNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutFeeChoice) {
    SGTrackerCheckoutFeeChoiceHideFees,
    SGTrackerCheckoutFeeChoiceShowFees,
    SGTrackerCheckoutFeeChoiceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutPaymentType) {
    SGTrackerCheckoutPaymentTypeAffirm,
    SGTrackerCheckoutPaymentTypeApplePay,
    SGTrackerCheckoutPaymentTypeCreditCard,
    SGTrackerCheckoutPaymentTypeGooglePay,
    SGTrackerCheckoutPaymentTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutPromocodeType) {
    SGTrackerCheckoutPromocodeTypeDiscount,
    SGTrackerCheckoutPromocodeTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutFieldDataField) {
    SGTrackerCheckoutFieldDataFieldBillingFirstName,
    SGTrackerCheckoutFieldDataFieldBillingLastName,
    SGTrackerCheckoutFieldDataFieldBillingAddress1,
    SGTrackerCheckoutFieldDataFieldBillingAddress2,
    SGTrackerCheckoutFieldDataFieldBillingCity,
    SGTrackerCheckoutFieldDataFieldBillingState,
    SGTrackerCheckoutFieldDataFieldBillingZip,
    SGTrackerCheckoutFieldDataFieldCardCvv,
    SGTrackerCheckoutFieldDataFieldCardExpMonth,
    SGTrackerCheckoutFieldDataFieldCardExpYear,
    SGTrackerCheckoutFieldDataFieldCardNumber,
    SGTrackerCheckoutFieldDataFieldDeliveryOption,
    SGTrackerCheckoutFieldDataFieldEmail,
    SGTrackerCheckoutFieldDataFieldNflOptIn,
    SGTrackerCheckoutFieldDataFieldPhone,
    SGTrackerCheckoutFieldDataFieldPromocode,
    SGTrackerCheckoutFieldDataFieldQuantity,
    SGTrackerCheckoutFieldDataFieldSeat,
    SGTrackerCheckoutFieldDataFieldShippingFirstName,
    SGTrackerCheckoutFieldDataFieldShippingLastName,
    SGTrackerCheckoutFieldDataFieldShippingAddress1,
    SGTrackerCheckoutFieldDataFieldShippingAddress2,
    SGTrackerCheckoutFieldDataFieldShippingCity,
    SGTrackerCheckoutFieldDataFieldShippingState,
    SGTrackerCheckoutFieldDataFieldShippingZip,
    SGTrackerCheckoutFieldDataFieldTerms,
    SGTrackerCheckoutFieldDataFieldNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutFieldEditType) {
    SGTrackerCheckoutFieldEditTypeAdd,
    SGTrackerCheckoutFieldEditTypeRemove,
    SGTrackerCheckoutFieldEditTypeUpdate,
    SGTrackerCheckoutFieldEditTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutItemItemType) {
    SGTrackerCheckoutItemItemTypeAccountCreditButton,
    SGTrackerCheckoutItemItemTypeAffirmButton,
    SGTrackerCheckoutItemItemTypeAffirmLearnMore,
    SGTrackerCheckoutItemItemTypeBuyersGuaranteeDetails,
    SGTrackerCheckoutItemItemTypeFaqItem,
    SGTrackerCheckoutItemItemTypeFeeTooltip,
    SGTrackerCheckoutItemItemTypeMiniMap,
    SGTrackerCheckoutItemItemTypeUpsellSkip,
    SGTrackerCheckoutItemItemTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutItemStepName) {
    SGTrackerCheckoutItemStepNameContact,
    SGTrackerCheckoutItemStepNameDelivery,
    SGTrackerCheckoutItemStepNameAddOns,
    SGTrackerCheckoutItemStepNameTicketTypes,
    SGTrackerCheckoutItemStepNameBilling,
    SGTrackerCheckoutItemStepNameReview,
    SGTrackerCheckoutItemStepNameNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutCheckoutType) {
    SGTrackerCheckoutCheckoutTypeAffirm,
    SGTrackerCheckoutCheckoutTypeApplePay,
    SGTrackerCheckoutCheckoutTypeCheckout,
    SGTrackerCheckoutCheckoutTypeGooglePay,
    SGTrackerCheckoutCheckoutTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutSortType) {
    SGTrackerCheckoutSortTypeBestSeat,
    SGTrackerCheckoutSortTypeDealScore,
    SGTrackerCheckoutSortTypePrice,
    SGTrackerCheckoutSortTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutSectionEditType) {
    SGTrackerCheckoutSectionEditTypeAdd,
    SGTrackerCheckoutSectionEditTypeEditSaved,
    SGTrackerCheckoutSectionEditTypeUseNone,
    SGTrackerCheckoutSectionEditTypeUseSaved,
    SGTrackerCheckoutSectionEditTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutSectionFormSection) {
    SGTrackerCheckoutSectionFormSectionContact,
    SGTrackerCheckoutSectionFormSectionDeliveryAddress,
    SGTrackerCheckoutSectionFormSectionDeliveryOption,
    SGTrackerCheckoutSectionFormSectionNotes,
    SGTrackerCheckoutSectionFormSectionPayment,
    SGTrackerCheckoutSectionFormSectionPriceBreakdown,
    SGTrackerCheckoutSectionFormSectionPriceTypes,
    SGTrackerCheckoutSectionFormSectionPromocode,
    SGTrackerCheckoutSectionFormSectionQuantity,
    SGTrackerCheckoutSectionFormSectionSeats,
    SGTrackerCheckoutSectionFormSectionUpsells,
    SGTrackerCheckoutSectionFormSectionUpsellQuantity,
    SGTrackerCheckoutSectionFormSectionNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutListingsDisplayOrientation) {
    SGTrackerCheckoutListingsDisplayOrientationHorizontal,
    SGTrackerCheckoutListingsDisplayOrientationVertical,
    SGTrackerCheckoutListingsDisplayOrientationNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutSalesMode) {
    SGTrackerCheckoutSalesModeBa,
    SGTrackerCheckoutSalesModeHba,
    SGTrackerCheckoutSalesModeIsm,
    SGTrackerCheckoutSalesModeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutViewType) {
    SGTrackerCheckoutViewTypeNflPrimaryPage,
    SGTrackerCheckoutViewTypeStandardEventPage,
    SGTrackerCheckoutViewTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutSummaryFeeChoice) {
    SGTrackerCheckoutSummaryFeeChoiceHideFees,
    SGTrackerCheckoutSummaryFeeChoiceShowFees,
    SGTrackerCheckoutSummaryFeeChoiceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutSummaryPromocodeType) {
    SGTrackerCheckoutSummaryPromocodeTypeDiscount,
    SGTrackerCheckoutSummaryPromocodeTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerCheckoutSummarySortType) {
    SGTrackerCheckoutSummarySortTypeBestSeat,
    SGTrackerCheckoutSummarySortTypeDealScore,
    SGTrackerCheckoutSummarySortTypePrice,
    SGTrackerCheckoutSummarySortTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerDeviceLocationLocationSource) {
    SGTrackerDeviceLocationLocationSourcePreviousSession,
    SGTrackerDeviceLocationLocationSourceGps,
    SGTrackerDeviceLocationLocationSourceGeoIp,
    SGTrackerDeviceLocationLocationSourceInitialGeoIp,
    SGTrackerDeviceLocationLocationSourceLocationSearch,
    SGTrackerDeviceLocationLocationSourceAccount,
    SGTrackerDeviceLocationLocationSourceRoute,
    SGTrackerDeviceLocationLocationSourceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerDeviceLocationUIOrigin) {
    SGTrackerDeviceLocationUIOriginBrowse,
    SGTrackerDeviceLocationUIOriginSettings,
    SGTrackerDeviceLocationUIOriginSearch,
    SGTrackerDeviceLocationUIOriginGlobal,
    SGTrackerDeviceLocationUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEntrancePageType) {
    SGTrackerEntrancePageTypeAccount,
    SGTrackerEntrancePageTypeAccountManager,
    SGTrackerEntrancePageTypeAmpPerformer,
    SGTrackerEntrancePageTypeCategory,
    SGTrackerEntrancePageTypeCityPage,
    SGTrackerEntrancePageTypeEventPage,
    SGTrackerEntrancePageTypeHomepage,
    SGTrackerEntrancePageTypeListPage,
    SGTrackerEntrancePageTypeMatchupPage,
    SGTrackerEntrancePageTypeMyTickets,
    SGTrackerEntrancePageTypeOther,
    SGTrackerEntrancePageTypePerformerPage,
    SGTrackerEntrancePageTypeRecurringEventPage,
    SGTrackerEntrancePageTypeSearch,
    SGTrackerEntrancePageTypeSeatView,
    SGTrackerEntrancePageTypeSeatingChart,
    SGTrackerEntrancePageTypeTba,
    SGTrackerEntrancePageTypeVenuePage,
    SGTrackerEntrancePageTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEntrancePlatform) {
    SGTrackerEntrancePlatformAndroid,
    SGTrackerEntrancePlatformiOS,
    SGTrackerEntrancePlatformMobileWeb,
    SGTrackerEntrancePlatformWeb,
    SGTrackerEntrancePlatformNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEntranceSource) {
    SGTrackerEntranceSourceCopy,
    SGTrackerEntranceSourceEmail,
    SGTrackerEntranceSourceNativeemail,
    SGTrackerEntranceSourceFacebook,
    SGTrackerEntranceSourceMlb,
    SGTrackerEntranceSourceOther,
    SGTrackerEntranceSourceSiri,
    SGTrackerEntranceSourceSms,
    SGTrackerEntranceSourceTwitter,
    SGTrackerEntranceSourceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEntranceUIOrigin) {
    SGTrackerEntranceUIOriginShortcutMyTickets,
    SGTrackerEntranceUIOriginShortcutSearch,
    SGTrackerEntranceUIOriginShortcutTracking,
    SGTrackerEntranceUIOriginShortcutDynamicTicket,
    SGTrackerEntranceUIOriginShortcutDynamicTrackedEvent,
    SGTrackerEntranceUIOriginShortcutDynamicRecommendedEvent,
    SGTrackerEntranceUIOriginGlobal,
    SGTrackerEntranceUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEvent3DTouchUIOrigin) {
    SGTrackerEvent3DTouchUIOriginBrowse,
    SGTrackerEvent3DTouchUIOriginBrowseSearch,
    SGTrackerEvent3DTouchUIOriginCategory,
    SGTrackerEvent3DTouchUIOriginList,
    SGTrackerEvent3DTouchUIOriginPerformer,
    SGTrackerEvent3DTouchUIOriginTabSearch,
    SGTrackerEvent3DTouchUIOriginTracking,
    SGTrackerEvent3DTouchUIOriginVenue,
    SGTrackerEvent3DTouchUIOriginGlobal,
    SGTrackerEvent3DTouchUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventAccessCodeModalUIOrigin) {
    SGTrackerEventAccessCodeModalUIOriginEventCollectionsBar,
    SGTrackerEventAccessCodeModalUIOriginEventFiltersMenu,
    SGTrackerEventAccessCodeModalUIOriginEventEmptyStateScreen,
    SGTrackerEventAccessCodeModalUIOriginEventInitialLoad,
    SGTrackerEventAccessCodeModalUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventBoxOfficeUIOrigin) {
    SGTrackerEventBoxOfficeUIOriginEvent,
    SGTrackerEventBoxOfficeUIOriginEventInfo,
    SGTrackerEventBoxOfficeUIOriginGlobal,
    SGTrackerEventBoxOfficeUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventUIOrigin) {
    SGTrackerEventUIOriginAllSearchResults,
    SGTrackerEventUIOriginBrowse,
    SGTrackerEventUIOriginBrowseSearch,
    SGTrackerEventUIOriginCategory,
    SGTrackerEventUIOriginCategorySidebar,
    SGTrackerEventUIOriginCity,
    SGTrackerEventUIOriginEventSidebar,
    SGTrackerEventUIOriginHome,
    SGTrackerEventUIOriginHomeSearch,
    SGTrackerEventUIOriginiMessage,
    SGTrackerEventUIOriginiOSToday,
    SGTrackerEventUIOriginMatchup,
    SGTrackerEventUIOriginList,
    SGTrackerEventUIOriginMyTicketsTicket,
    SGTrackerEventUIOriginNavBarSearch,
    SGTrackerEventUIOriginNotification,
    SGTrackerEventUIOriginPerformer,
    SGTrackerEventUIOriginPerformerAllEvents,
    SGTrackerEventUIOriginPerformerCalendar,
    SGTrackerEventUIOriginPerformerClubPasses,
    SGTrackerEventUIOriginPerformerNearbyEvents,
    SGTrackerEventUIOriginPerformerParking,
    SGTrackerEventUIOriginPerformerPremiumSeats,
    SGTrackerEventUIOriginPerformerSidebar,
    SGTrackerEventUIOriginPerformerSimilarEvents,
    SGTrackerEventUIOriginPromocodeLandingPage,
    SGTrackerEventUIOriginPublicSale,
    SGTrackerEventUIOriginRecurringEvent,
    SGTrackerEventUIOriginSeatingChartBestDeal,
    SGTrackerEventUIOriginSeatingChartFtEvents,
    SGTrackerEventUIOriginSeatingChartLowestPrice,
    SGTrackerEventUIOriginSeatingChartNextEvent,
    SGTrackerEventUIOriginTabSearch,
    SGTrackerEventUIOriginTracking,
    SGTrackerEventUIOriginTrackingDashboard,
    SGTrackerEventUIOriginTransfer,
    SGTrackerEventUIOriginVenue,
    SGTrackerEventUIOriginVenueSeatingChart,
    SGTrackerEventUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventCollectionUIOrigin) {
    SGTrackerEventCollectionUIOriginCollectionsBar,
    SGTrackerEventCollectionUIOriginEventFiltersMenu,
    SGTrackerEventCollectionUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventFeeFeeChoice) {
    SGTrackerEventFeeFeeChoiceHideFees,
    SGTrackerEventFeeFeeChoiceShowFees,
    SGTrackerEventFeeFeeChoiceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventFeeFeeDefault) {
    SGTrackerEventFeeFeeDefaultHideFees,
    SGTrackerEventFeeFeeDefaultShowFees,
    SGTrackerEventFeeFeeDefaultNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventFeeUIOrigin) {
    SGTrackerEventFeeUIOriginCollectionsBar,
    SGTrackerEventFeeUIOriginEventListingsHeader,
    SGTrackerEventFeeUIOriginFilterModal,
    SGTrackerEventFeeUIOriginSettings,
    SGTrackerEventFeeUIOriginGlobal,
    SGTrackerEventFeeUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventItemItemType) {
    SGTrackerEventItemItemTypeAccessCodeToast,
    SGTrackerEventItemItemTypeAffirmLearnMore,
    SGTrackerEventItemItemTypeBlueListingButton,
    SGTrackerEventItemItemTypeChangeSeats,
    SGTrackerEventItemItemTypePackageToast,
    SGTrackerEventItemItemTypePriceBreakdown,
    SGTrackerEventItemItemTypeRemediationVisitWebsite,
    SGTrackerEventItemItemTypeSellerNotesInfo,
    SGTrackerEventItemItemTypeSellerNotesFaqArticle,
    SGTrackerEventItemItemTypeViewSeatInfo,
    SGTrackerEventItemItemTypeSeatSelectionZoomIn,
    SGTrackerEventItemItemTypeSeatSelectionZoomOut,
    SGTrackerEventItemItemTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingBestDealOrLowestPriceListing) {
    SGTrackerEventListingBestDealOrLowestPriceListingBestDeal,
    SGTrackerEventListingBestDealOrLowestPriceListingLowestPrice,
    SGTrackerEventListingBestDealOrLowestPriceListingNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingCheckoutType) {
    SGTrackerEventListingCheckoutTypeApplePay,
    SGTrackerEventListingCheckoutTypeCheckout,
    SGTrackerEventListingCheckoutTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingFeeChoice) {
    SGTrackerEventListingFeeChoiceHideFees,
    SGTrackerEventListingFeeChoiceShowFees,
    SGTrackerEventListingFeeChoiceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingFeeDefault) {
    SGTrackerEventListingFeeDefaultHideFees,
    SGTrackerEventListingFeeDefaultShowFees,
    SGTrackerEventListingFeeDefaultNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingInteractionMethod) {
    SGTrackerEventListingInteractionMethod3DTouchPeek,
    SGTrackerEventListingInteractionMethodNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingListingsDisplayOrientation) {
    SGTrackerEventListingListingsDisplayOrientationHorizontal,
    SGTrackerEventListingListingsDisplayOrientationVertical,
    SGTrackerEventListingListingsDisplayOrientationNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingPaymentType) {
    SGTrackerEventListingPaymentTypeApplePay,
    SGTrackerEventListingPaymentTypeCreditCard,
    SGTrackerEventListingPaymentTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingSalesMode) {
    SGTrackerEventListingSalesModeBa,
    SGTrackerEventListingSalesModeHba,
    SGTrackerEventListingSalesModeIsm,
    SGTrackerEventListingSalesModeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingSortType) {
    SGTrackerEventListingSortTypeBestSeat,
    SGTrackerEventListingSortTypeDealScore,
    SGTrackerEventListingSortTypePrice,
    SGTrackerEventListingSortTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingUIOrigin) {
    SGTrackerEventListingUIOriginCheckout,
    SGTrackerEventListingUIOriginEventPage,
    SGTrackerEventListingUIOriginHbaModal,
    SGTrackerEventListingUIOriginListingDetail,
    SGTrackerEventListingUIOriginGlobal,
    SGTrackerEventListingUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingViewMode) {
    SGTrackerEventListingViewModeAllNflVerified,
    SGTrackerEventListingViewModeSomeNflVerified,
    SGTrackerEventListingViewModeNoNflVerified,
    SGTrackerEventListingViewModeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingInventoryType) {
    SGTrackerEventListingInventoryTypeAisle,
    SGTrackerEventListingInventoryTypeBundle,
    SGTrackerEventListingInventoryTypeDefault,
    SGTrackerEventListingInventoryTypePackage,
    SGTrackerEventListingInventoryTypePrime,
    SGTrackerEventListingInventoryTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingsDeliveryMethod) {
    SGTrackerEventListingsDeliveryMethodAll,
    SGTrackerEventListingsDeliveryMethodEticket,
    SGTrackerEventListingsDeliveryMethodInAppEticket,
    SGTrackerEventListingsDeliveryMethodInstantEticket,
    SGTrackerEventListingsDeliveryMethodNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingsFeeChoice) {
    SGTrackerEventListingsFeeChoiceHideFees,
    SGTrackerEventListingsFeeChoiceShowFees,
    SGTrackerEventListingsFeeChoiceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingsFilterType) {
    SGTrackerEventListingsFilterTypeAccessCodes,
    SGTrackerEventListingsFilterTypeAda,
    SGTrackerEventListingsFilterTypeAisle,
    SGTrackerEventListingsFilterTypeBundle,
    SGTrackerEventListingsFilterTypeDeliveryMethod,
    SGTrackerEventListingsFilterTypeObstructedView,
    SGTrackerEventListingsFilterTypePackage,
    SGTrackerEventListingsFilterTypePrice,
    SGTrackerEventListingsFilterTypePrimaryResale,
    SGTrackerEventListingsFilterTypePrime,
    SGTrackerEventListingsFilterTypePromocode,
    SGTrackerEventListingsFilterTypeQuantity,
    SGTrackerEventListingsFilterTypeSeatRow,
    SGTrackerEventListingsFilterTypeSeatQuality,
    SGTrackerEventListingsFilterTypeSeatSection,
    SGTrackerEventListingsFilterTypeSpatialCollection,
    SGTrackerEventListingsFilterTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingsObstructedViewChoice) {
    SGTrackerEventListingsObstructedViewChoiceAll,
    SGTrackerEventListingsObstructedViewChoiceUnobstructedView,
    SGTrackerEventListingsObstructedViewChoiceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingsPriceFilterChoice) {
    SGTrackerEventListingsPriceFilterChoiceManual,
    SGTrackerEventListingsPriceFilterChoiceSlider,
    SGTrackerEventListingsPriceFilterChoiceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingsPrimaryResaleChoice) {
    SGTrackerEventListingsPrimaryResaleChoicePrimaryOnly,
    SGTrackerEventListingsPrimaryResaleChoicePrimaryAndOfficialResale,
    SGTrackerEventListingsPrimaryResaleChoiceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingsPromocodeChoice) {
    SGTrackerEventListingsPromocodeChoiceSupportsPromoCodeOnly,
    SGTrackerEventListingsPromocodeChoiceAll,
    SGTrackerEventListingsPromocodeChoiceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingsUIOrigin) {
    SGTrackerEventListingsUIOriginAccessCodeModal,
    SGTrackerEventListingsUIOriginHorizontalList,
    SGTrackerEventListingsUIOriginVerticalList,
    SGTrackerEventListingsUIOriginCollectionsBar,
    SGTrackerEventListingsUIOriginFilterSortModal,
    SGTrackerEventListingsUIOriginSettings,
    SGTrackerEventListingsUIOriginBestAvailableForm,
    SGTrackerEventListingsUIOriginEventListingsHeader,
    SGTrackerEventListingsUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingsListingsDisplayOrientation) {
    SGTrackerEventListingsListingsDisplayOrientationHorizontal,
    SGTrackerEventListingsListingsDisplayOrientationVertical,
    SGTrackerEventListingsListingsDisplayOrientationNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingsShowMethod) {
    SGTrackerEventListingsShowMethodBottomsheetExpand,
    SGTrackerEventListingsShowMethodCollectionsBar,
    SGTrackerEventListingsShowMethodFilterModal,
    SGTrackerEventListingsShowMethodMapInteraction,
    SGTrackerEventListingsShowMethodMapModeButton,
    SGTrackerEventListingsShowMethodPageLoad,
    SGTrackerEventListingsShowMethodNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingsSortType) {
    SGTrackerEventListingsSortTypeBestSeat,
    SGTrackerEventListingsSortTypeDQ,
    SGTrackerEventListingsSortTypePrice,
    SGTrackerEventListingsSortTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventListingsSortOrder) {
    SGTrackerEventListingsSortOrderAsc,
    SGTrackerEventListingsSortOrderDesc,
    SGTrackerEventListingsSortOrderNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventRowInteractionMethod) {
    SGTrackerEventRowInteractionMethodLongPressDrag,
    SGTrackerEventRowInteractionMethodNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventRowInventoryType) {
    SGTrackerEventRowInventoryTypeDefault,
    SGTrackerEventRowInventoryTypePackage,
    SGTrackerEventRowInventoryTypePrime,
    SGTrackerEventRowInventoryTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventSectionInteractionMethod) {
    SGTrackerEventSectionInteractionMethodLongPressDrag,
    SGTrackerEventSectionInteractionMethodNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventSectionInventoryType) {
    SGTrackerEventSectionInventoryTypeDefault,
    SGTrackerEventSectionInventoryTypePackage,
    SGTrackerEventSectionInventoryTypePrime,
    SGTrackerEventSectionInventoryTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventShareUIOrigin) {
    SGTrackerEventShareUIOriginEvent,
    SGTrackerEventShareUIOriginEventInfo,
    SGTrackerEventShareUIOriginListingDetail,
    SGTrackerEventShareUIOriginGlobal,
    SGTrackerEventShareUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventFeeChoice) {
    SGTrackerEventFeeChoiceHideFees,
    SGTrackerEventFeeChoiceShowFees,
    SGTrackerEventFeeChoiceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerEventSalesMode) {
    SGTrackerEventSalesModeBa,
    SGTrackerEventSalesModeHba,
    SGTrackerEventSalesModeIsm,
    SGTrackerEventSalesModeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerHelpContactUIOrigin) {
    SGTrackerHelpContactUIOriginLogin2Fa,
    SGTrackerHelpContactUIOriginGlobal,
    SGTrackerHelpContactUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerIngestionsBarcodesTicketType) {
    SGTrackerIngestionsBarcodesTicketTypeBarcode,
    SGTrackerIngestionsBarcodesTicketTypePDF,
    SGTrackerIngestionsBarcodesTicketTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerIngestionsEventsTicketType) {
    SGTrackerIngestionsEventsTicketTypeBarcode,
    SGTrackerIngestionsEventsTicketTypePDF,
    SGTrackerIngestionsEventsTicketTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerIngestionsHelpDetailTicketType) {
    SGTrackerIngestionsHelpDetailTicketTypePDF,
    SGTrackerIngestionsHelpDetailTicketTypeScreenshot,
    SGTrackerIngestionsHelpDetailTicketTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerIngestionsMetadataTicketType) {
    SGTrackerIngestionsMetadataTicketTypeBarcode,
    SGTrackerIngestionsMetadataTicketTypePDF,
    SGTrackerIngestionsMetadataTicketTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerIngestionsPerformerTicketType) {
    SGTrackerIngestionsPerformerTicketTypeBarcode,
    SGTrackerIngestionsPerformerTicketTypePDF,
    SGTrackerIngestionsPerformerTicketTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerIngestionsSummaryTicketType) {
    SGTrackerIngestionsSummaryTicketTypeBarcode,
    SGTrackerIngestionsSummaryTicketTypePDF,
    SGTrackerIngestionsSummaryTicketTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerIngestionsUploadTicketType) {
    SGTrackerIngestionsUploadTicketTypeBarcode,
    SGTrackerIngestionsUploadTicketTypePDF,
    SGTrackerIngestionsUploadTicketTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerLandingPageItemItemType) {
    SGTrackerLandingPageItemItemTypeFindEvents,
    SGTrackerLandingPageItemItemTypeUnlockPromoCode,
    SGTrackerLandingPageItemItemTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerListUIOrigin) {
    SGTrackerListUIOriginBrowse,
    SGTrackerListUIOriginBrowseSearch,
    SGTrackerListUIOriginBrowseSearchDefaultSuggestion,
    SGTrackerListUIOriginHome,
    SGTrackerListUIOriginList,
    SGTrackerListUIOriginMyTickets,
    SGTrackerListUIOriginNotification,
    SGTrackerListUIOriginPerformer,
    SGTrackerListUIOriginPromocodeLandingPage,
    SGTrackerListUIOriginTabSearch,
    SGTrackerListUIOriginGlobal,
    SGTrackerListUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerListEventsFilterType) {
    SGTrackerListEventsFilterTypeBundles,
    SGTrackerListEventsFilterTypeCalendar,
    SGTrackerListEventsFilterTypeClubPasses,
    SGTrackerListEventsFilterTypeDate,
    SGTrackerListEventsFilterTypeDayNight,
    SGTrackerListEventsFilterTypeEntitlements,
    SGTrackerListEventsFilterTypeEvents,
    SGTrackerListEventsFilterTypeGame,
    SGTrackerListEventsFilterTypeHomeAway,
    SGTrackerListEventsFilterTypeLocation,
    SGTrackerListEventsFilterTypeMonth,
    SGTrackerListEventsFilterTypeOpponent,
    SGTrackerListEventsFilterTypeParking,
    SGTrackerListEventsFilterTypePreseasonTickets,
    SGTrackerListEventsFilterTypePrice,
    SGTrackerListEventsFilterTypeQuickDate,
    SGTrackerListEventsFilterTypeSeason,
    SGTrackerListEventsFilterTypeTicketPackages,
    SGTrackerListEventsFilterTypeWeekdayWeekend,
    SGTrackerListEventsFilterTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerListEventsUIOrigin) {
    SGTrackerListEventsUIOriginAllEvents,
    SGTrackerListEventsUIOriginClubPasses,
    SGTrackerListEventsUIOriginEventsNearby,
    SGTrackerListEventsUIOriginParking,
    SGTrackerListEventsUIOriginPremiumSeats,
    SGTrackerListEventsUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerListEventsViewType) {
    SGTrackerListEventsViewTypePerformerCalendar,
    SGTrackerListEventsViewTypePerformerList,
    SGTrackerListEventsViewTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerListItemInteractionMethod) {
    SGTrackerListItemInteractionMethodClick,
    SGTrackerListItemInteractionMethodDismiss,
    SGTrackerListItemInteractionMethodScroll,
    SGTrackerListItemInteractionMethodTrack,
    SGTrackerListItemInteractionMethodUntrack,
    SGTrackerListItemInteractionMethod3DTouchPeek,
    SGTrackerListItemInteractionMethod3DTouchPop,
    SGTrackerListItemInteractionMethodPlaySong,
    SGTrackerListItemInteractionMethodPauseSong,
    SGTrackerListItemInteractionMethodNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerListItemUIOrigin) {
    SGTrackerListItemUIOriginBrowse,
    SGTrackerListItemUIOriginBrowseSearch,
    SGTrackerListItemUIOriginBrowseSearchDefaultSuggestion,
    SGTrackerListItemUIOriginHome,
    SGTrackerListItemUIOriginList,
    SGTrackerListItemUIOriginMyTickets,
    SGTrackerListItemUIOriginNotification,
    SGTrackerListItemUIOriginPerformer,
    SGTrackerListItemUIOriginPromocodeLandingPage,
    SGTrackerListItemUIOriginTabSearch,
    SGTrackerListItemUIOriginGlobal,
    SGTrackerListItemUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerListViewUIOrigin) {
    SGTrackerListViewUIOriginBrowse,
    SGTrackerListViewUIOriginBrowseSearch,
    SGTrackerListViewUIOriginBrowseSearchDefaultSuggestion,
    SGTrackerListViewUIOriginHome,
    SGTrackerListViewUIOriginList,
    SGTrackerListViewUIOriginMyTickets,
    SGTrackerListViewUIOriginNotification,
    SGTrackerListViewUIOriginPerformer,
    SGTrackerListViewUIOriginTabSearch,
    SGTrackerListViewUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerLotteryItemType) {
    SGTrackerLotteryItemTypeEnter,
    SGTrackerLotteryItemTypeTrackPerformer,
    SGTrackerLotteryItemTypeEnableNotifications,
    SGTrackerLotteryItemTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerLotteryUIOrigin) {
    SGTrackerLotteryUIOriginBrowse,
    SGTrackerLotteryUIOriginDeeplink,
    SGTrackerLotteryUIOriginGlobal,
    SGTrackerLotteryUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerModalModalType) {
    SGTrackerModalModalTypeBuyerGuarantee,
    SGTrackerModalModalTypeNflAuthenticated,
    SGTrackerModalModalTypeSsnRequirement,
    SGTrackerModalModalTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerModalUIOrigin) {
    SGTrackerModalUIOriginCheckout,
    SGTrackerModalUIOriginPerformer,
    SGTrackerModalUIOriginMyTickets,
    SGTrackerModalUIOriginPublicSale,
    SGTrackerModalUIOriginSettings,
    SGTrackerModalUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerMusicPlayerUIOrigin) {
    SGTrackerMusicPlayerUIOriginBrowse,
    SGTrackerMusicPlayerUIOriginMyTicketsTicket,
    SGTrackerMusicPlayerUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerMusicPlayerInteractionMethod) {
    SGTrackerMusicPlayerInteractionMethodNext,
    SGTrackerMusicPlayerInteractionMethodPause,
    SGTrackerMusicPlayerInteractionMethodPlay,
    SGTrackerMusicPlayerInteractionMethodPrevious,
    SGTrackerMusicPlayerInteractionMethodOpenSpotify,
    SGTrackerMusicPlayerInteractionMethodNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerNavigationItemType) {
    SGTrackerNavigationItemTypeBrowse,
    SGTrackerNavigationItemTypeSearch,
    SGTrackerNavigationItemTypeMyTickets,
    SGTrackerNavigationItemTypeAccountSettings,
    SGTrackerNavigationItemTypeTracking,
    SGTrackerNavigationItemTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerNotificationContentContentAction) {
    SGTrackerNotificationContentContentActionTicketGroupTransfer,
    SGTrackerNotificationContentContentActionTicketGroupView,
    SGTrackerNotificationContentContentActionNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerNotificationContentNotificationType) {
    SGTrackerNotificationContentNotificationTypeTicketsAvailable,
    SGTrackerNotificationContentNotificationTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTracker3DTouchUIOrigin) {
    SGTracker3DTouchUIOriginBrowse,
    SGTracker3DTouchUIOriginBrowseSearch,
    SGTracker3DTouchUIOriginCategory,
    SGTracker3DTouchUIOriginList,
    SGTracker3DTouchUIOriginTabSearch,
    SGTracker3DTouchUIOriginTracking,
    SGTracker3DTouchUIOriginGlobal,
    SGTracker3DTouchUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerPerformerUIOrigin) {
    SGTrackerPerformerUIOriginBrowse,
    SGTrackerPerformerUIOriginBrowseSearch,
    SGTrackerPerformerUIOriginCategory,
    SGTrackerPerformerUIOriginCategorySidebar,
    SGTrackerPerformerUIOriginEventBanner,
    SGTrackerPerformerUIOriginEventEmptyStateScreen,
    SGTrackerPerformerUIOriginEventInfo,
    SGTrackerPerformerUIOriginEventNav,
    SGTrackerPerformerUIOriginEventTitle,
    SGTrackerPerformerUIOriginHomeSearch,
    SGTrackerPerformerUIOriginHomeSidebar,
    SGTrackerPerformerUIOriginList,
    SGTrackerPerformerUIOriginNavBarButton,
    SGTrackerPerformerUIOriginNavBarSearch,
    SGTrackerPerformerUIOriginPerformerSidebar,
    SGTrackerPerformerUIOriginTabSearch,
    SGTrackerPerformerUIOriginTracking,
    SGTrackerPerformerUIOriginTrackingDashboard,
    SGTrackerPerformerUIOriginVenueSidebar,
    SGTrackerPerformerUIOriginNotification,
    SGTrackerPerformerUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerPerformerItemItemType) {
    SGTrackerPerformerItemItemTypeAccolades,
    SGTrackerPerformerItemItemTypeBuyerGuaranteeCallout,
    SGTrackerPerformerItemItemTypeClubPasses,
    SGTrackerPerformerItemItemTypeDealScorePromo,
    SGTrackerPerformerItemItemTypeEntitlements,
    SGTrackerPerformerItemItemTypeEventListAll,
    SGTrackerPerformerItemItemTypeEventListLocal,
    SGTrackerPerformerItemItemTypeExternalReview,
    SGTrackerPerformerItemItemTypeLearnMore,
    SGTrackerPerformerItemItemTypeLoadMore,
    SGTrackerPerformerItemItemTypeMlbPartnership,
    SGTrackerPerformerItemItemTypeMobileAppPromo,
    SGTrackerPerformerItemItemTypeNflAuthenticatedCallout,
    SGTrackerPerformerItemItemTypeOfficialTicketingPartner,
    SGTrackerPerformerItemItemTypeParking,
    SGTrackerPerformerItemItemTypeParkingCta,
    SGTrackerPerformerItemItemTypePremiumSeats,
    SGTrackerPerformerItemItemTypeSeoShowMore,
    SGTrackerPerformerItemItemTypeSeoLink,
    SGTrackerPerformerItemItemTypeShowDetails,
    SGTrackerPerformerItemItemTypeShowDescription,
    SGTrackerPerformerItemItemTypeTestimonials,
    SGTrackerPerformerItemItemTypeTbaNews,
    SGTrackerPerformerItemItemTypeViewPhotos,
    SGTrackerPerformerItemItemTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerPerformerMediaMediaSeller) {
    SGTrackerPerformerMediaMediaSellerItunes,
    SGTrackerPerformerMediaMediaSellerNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerPerformerMediaMediaType) {
    SGTrackerPerformerMediaMediaTypeMusic,
    SGTrackerPerformerMediaMediaTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerPerformerMediaMediaPlayer) {
    SGTrackerPerformerMediaMediaPlayerItunes,
    SGTrackerPerformerMediaMediaPlayerNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerPerformerDisplayType) {
    SGTrackerPerformerDisplayTypeListView,
    SGTrackerPerformerDisplayTypeCalendarView,
    SGTrackerPerformerDisplayTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerPerformerSubtab) {
    SGTrackerPerformerSubtabOffers,
    SGTrackerPerformerSubtabClubPasses,
    SGTrackerPerformerSubtabEvents,
    SGTrackerPerformerSubtabParking,
    SGTrackerPerformerSubtabPlayoffTickets,
    SGTrackerPerformerSubtabPreseasonTickets,
    SGTrackerPerformerSubtabSuites,
    SGTrackerPerformerSubtabTicketPackages,
    SGTrackerPerformerSubtabNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerPerformerViewItemName) {
    SGTrackerPerformerViewItemNameCalendarView,
    SGTrackerPerformerViewItemNameListView,
    SGTrackerPerformerViewItemNameNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerPerformerViewItemType) {
    SGTrackerPerformerViewItemTypePerformerCalendar,
    SGTrackerPerformerViewItemTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerPromotionDisplayType) {
    SGTrackerPromotionDisplayTypeCustomImage,
    SGTrackerPromotionDisplayTypeDailyTap,
    SGTrackerPromotionDisplayTypeFeaturedEvent,
    SGTrackerPromotionDisplayTypeFeaturedPerformer,
    SGTrackerPromotionDisplayTypePriceDrop,
    SGTrackerPromotionDisplayTypeReferral,
    SGTrackerPromotionDisplayTypeStaticList,
    SGTrackerPromotionDisplayTypeEventDetail,
    SGTrackerPromotionDisplayTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerPromotionUIOrigin) {
    SGTrackerPromotionUIOriginBrowse,
    SGTrackerPromotionUIOriginEvent,
    SGTrackerPromotionUIOriginEventInfo,
    SGTrackerPromotionUIOriginHomepage,
    SGTrackerPromotionUIOriginMyTickets,
    SGTrackerPromotionUIOriginPostPurchase,
    SGTrackerPromotionUIOriginSettings,
    SGTrackerPromotionUIOriginGlobal,
    SGTrackerPromotionUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerScrollCheckpoint) {
    SGTrackerScrollCheckpointFaq,
    SGTrackerScrollCheckpointNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerSearchUIOrigin) {
    SGTrackerSearchUIOriginHome,
    SGTrackerSearchUIOriginBrowse,
    SGTrackerSearchUIOriginList,
    SGTrackerSearchUIOriginPerformer,
    SGTrackerSearchUIOriginEvent,
    SGTrackerSearchUIOriginVenue,
    SGTrackerSearchUIOriginMyTickets,
    SGTrackerSearchUIOriginTrackingDashboard,
    SGTrackerSearchUIOriginTracking,
    SGTrackerSearchUIOriginSettings,
    SGTrackerSearchUIOriginSearch,
    SGTrackerSearchUIOriginZendeskSupportSdk,
    SGTrackerSearchUIOriginHomeSearch,
    SGTrackerSearchUIOriginNavBarSearch,
    SGTrackerSearchUIOriginGlobal,
    SGTrackerSearchUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerSearchSeeAllResultsUIOrigin) {
    SGTrackerSearchSeeAllResultsUIOriginHome,
    SGTrackerSearchSeeAllResultsUIOriginBrowse,
    SGTrackerSearchSeeAllResultsUIOriginList,
    SGTrackerSearchSeeAllResultsUIOriginPerformer,
    SGTrackerSearchSeeAllResultsUIOriginEvent,
    SGTrackerSearchSeeAllResultsUIOriginVenue,
    SGTrackerSearchSeeAllResultsUIOriginMyTickets,
    SGTrackerSearchSeeAllResultsUIOriginTrackingDashboard,
    SGTrackerSearchSeeAllResultsUIOriginTracking,
    SGTrackerSearchSeeAllResultsUIOriginSettings,
    SGTrackerSearchSeeAllResultsUIOriginSearch,
    SGTrackerSearchSeeAllResultsUIOriginZendeskSupportSdk,
    SGTrackerSearchSeeAllResultsUIOriginHomeSearch,
    SGTrackerSearchSeeAllResultsUIOriginNavBarSearch,
    SGTrackerSearchSeeAllResultsUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerSellUIOrigin) {
    SGTrackerSellUIOriginHomeSidebar,
    SGTrackerSellUIOriginMyTickets,
    SGTrackerSellUIOriginMyTicketsTicket,
    SGTrackerSellUIOriginNavBarButton,
    SGTrackerSellUIOriginPerformerSidebar,
    SGTrackerSellUIOriginSellLanding,
    SGTrackerSellUIOriginGlobal,
    SGTrackerSellUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerMyTicketsViewMode) {
    SGTrackerMyTicketsViewModeClassic,
    SGTrackerMyTicketsViewModeCompact,
    SGTrackerMyTicketsViewModeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerOpenDomainSlug) {
    SGTrackerOpenDomainSlugSportingkc,
    SGTrackerOpenDomainSlugNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerSellCreateUIOrigin) {
    SGTrackerSellCreateUIOriginResaleFlow,
    SGTrackerSellCreateUIOriginExchangeModal,
    SGTrackerSellCreateUIOriginNflListSeatgeekUpsell,
    SGTrackerSellCreateUIOriginGlobal,
    SGTrackerSellCreateUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerSellItemItemType) {
    SGTrackerSellItemItemTypeExchangeModal,
    SGTrackerSellItemItemTypeDelistModal,
    SGTrackerSellItemItemTypeListButton,
    SGTrackerSellItemItemTypeCloseButton,
    SGTrackerSellItemItemTypeEditButton,
    SGTrackerSellItemItemTypeDelistButton,
    SGTrackerSellItemItemTypeListSeatgeekButton,
    SGTrackerSellItemItemTypeMorePartnersButton,
    SGTrackerSellItemItemTypeToken,
    SGTrackerSellItemItemTypeViewPrices,
    SGTrackerSellItemItemTypeViewListing,
    SGTrackerSellItemItemTypeNflListSeatgeekButtonUpsell,
    SGTrackerSellItemItemTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerSellEditType) {
    SGTrackerSellEditTypeAdd,
    SGTrackerSellEditTypeUpdate,
    SGTrackerSellEditTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerSellViewMode) {
    SGTrackerSellViewModeAccountmanager,
    SGTrackerSellViewModeClassic,
    SGTrackerSellViewModeCompact,
    SGTrackerSellViewModeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerTransfersAcceptPaymentType) {
    SGTrackerTransfersAcceptPaymentTypeApplePay,
    SGTrackerTransfersAcceptPaymentTypeCreditCard,
    SGTrackerTransfersAcceptPaymentTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerTransfersUIOrigin) {
    SGTrackerTransfersUIOriginEventTickets,
    SGTrackerTransfersUIOriginCheckout,
    SGTrackerTransfersUIOriginNotification,
    SGTrackerTransfersUIOriginiMessage,
    SGTrackerTransfersUIOriginStandalone,
    SGTrackerTransfersUIOriginGlobal,
    SGTrackerTransfersUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerTransfersRecipientType) {
    SGTrackerTransfersRecipientTypeEmail,
    SGTrackerTransfersRecipientTypeLink,
    SGTrackerTransfersRecipientTypeLocalContact,
    SGTrackerTransfersRecipientTypePhoneNumber,
    SGTrackerTransfersRecipientTypeSeatgeek,
    SGTrackerTransfersRecipientTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerTransfersStatus) {
    SGTrackerTransfersStatusAvailable,
    SGTrackerTransfersStatusPending,
    SGTrackerTransfersStatusAccepted,
    SGTrackerTransfersStatusUnavailable,
    SGTrackerTransfersStatusNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerTransfersIncomingTransferType) {
    SGTrackerTransfersIncomingTransferTypeFree,
    SGTrackerTransfersIncomingTransferTypePaid,
    SGTrackerTransfersIncomingTransferTypeUnverified,
    SGTrackerTransfersIncomingTransferTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerTransfersIncomingUIOrigin) {
    SGTrackerTransfersIncomingUIOriginMyTickets,
    SGTrackerTransfersIncomingUIOriginStandalone,
    SGTrackerTransfersIncomingUIOriginGlobal,
    SGTrackerTransfersIncomingUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerTransfersInitiationActivityType) {
    SGTrackerTransfersInitiationActivityTypeSkip,
    SGTrackerTransfersInitiationActivityTypeDone,
    SGTrackerTransfersInitiationActivityTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerTransfersItemActivityType) {
    SGTrackerTransfersItemActivityTypeMore,
    SGTrackerTransfersItemActivityTypeQuestion,
    SGTrackerTransfersItemActivityTypeSend,
    SGTrackerTransfersItemActivityTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerTransfersItemPageType) {
    SGTrackerTransfersItemPageTypeEventTickets,
    SGTrackerTransfersItemPageTypeTransferInitiation,
    SGTrackerTransfersItemPageTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerTransfersTicketType) {
    SGTrackerTransfersTicketTypePass,
    SGTrackerTransfersTicketTypeTicket,
    SGTrackerTransfersTicketTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerTransfersViewMode) {
    SGTrackerTransfersViewModeAccountmanager,
    SGTrackerTransfersViewModeClassic,
    SGTrackerTransfersViewModeCompact,
    SGTrackerTransfersViewModeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerTransfersSummaryItemType) {
    SGTrackerTransfersSummaryItemTypePrice,
    SGTrackerTransfersSummaryItemTypeQuantity,
    SGTrackerTransfersSummaryItemTypeRecipient,
    SGTrackerTransfersSummaryItemTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserAccountUpgradeItemType) {
    SGTrackerUserAccountUpgradeItemTypeComplete,
    SGTrackerUserAccountUpgradeItemTypeEditEmail,
    SGTrackerUserAccountUpgradeItemTypeNeedHelp,
    SGTrackerUserAccountUpgradeItemTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserAccountType) {
    SGTrackerUserAccountTypeEmail,
    SGTrackerUserAccountTypeFacebook,
    SGTrackerUserAccountTypeLegacyUnknown,
    SGTrackerUserAccountTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserAuthCredentialSource) {
    SGTrackerUserAuthCredentialSourceGoogleSmartLock,
    SGTrackerUserAuthCredentialSourceManualInput,
    SGTrackerUserAuthCredentialSourceMagicLink,
    SGTrackerUserAuthCredentialSourceFacebookAccountUpgrade,
    SGTrackerUserAuthCredentialSourceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserAuthUIOrigin) {
    SGTrackerUserAuthUIOriginBrowse,
    SGTrackerUserAuthUIOriginCategory,
    SGTrackerUserAuthUIOriginCheckout,
    SGTrackerUserAuthUIOriginCheckoutPromocode,
    SGTrackerUserAuthUIOriginDrawer,
    SGTrackerUserAuthUIOriginEvent,
    SGTrackerUserAuthUIOriginHome,
    SGTrackerUserAuthUIOriginHomeSidebar,
    SGTrackerUserAuthUIOriginList,
    SGTrackerUserAuthUIOriginMyTickets,
    SGTrackerUserAuthUIOriginNavBarButton,
    SGTrackerUserAuthUIOriginOnboarding,
    SGTrackerUserAuthUIOriginPerformer,
    SGTrackerUserAuthUIOriginSettings,
    SGTrackerUserAuthUIOriginSettingsPromocode,
    SGTrackerUserAuthUIOriginTracking,
    SGTrackerUserAuthUIOriginVenue,
    SGTrackerUserAuthUIOriginGlobal,
    SGTrackerUserAuthUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserContactVerificationContactType) {
    SGTrackerUserContactVerificationContactTypeEmail,
    SGTrackerUserContactVerificationContactTypeMobilePhone,
    SGTrackerUserContactVerificationContactTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserContactContactType) {
    SGTrackerUserContactContactTypeAddress,
    SGTrackerUserContactContactTypeBusinessAddress,
    SGTrackerUserContactContactTypeEmail,
    SGTrackerUserContactContactTypeMobilePhone,
    SGTrackerUserContactContactTypePersonalInformation,
    SGTrackerUserContactContactTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserContactUIOrigin) {
    SGTrackerUserContactUIOriginMyTickets,
    SGTrackerUserContactUIOriginPublicSale,
    SGTrackerUserContactUIOriginPaidTransfer,
    SGTrackerUserContactUIOriginSettings,
    SGTrackerUserContactUIOriginTransfer,
    SGTrackerUserContactUIOriginGlobal,
    SGTrackerUserContactUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserEventInteractionMethod) {
    SGTrackerUserEventInteractionMethod3DTouchPeek,
    SGTrackerUserEventInteractionMethodNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserEventUIOrigin) {
    SGTrackerUserEventUIOriginBrowse,
    SGTrackerUserEventUIOriginCategory,
    SGTrackerUserEventUIOriginEvent,
    SGTrackerUserEventUIOriginEventInfo,
    SGTrackerUserEventUIOriginHome,
    SGTrackerUserEventUIOriginHomeSidebar,
    SGTrackerUserEventUIOriginList,
    SGTrackerUserEventUIOriginMyTicketsTicket,
    SGTrackerUserEventUIOriginNotification,
    SGTrackerUserEventUIOriginPerformer,
    SGTrackerUserEventUIOriginPromocodeLandingPage,
    SGTrackerUserEventUIOriginTracking,
    SGTrackerUserEventUIOriginVenue,
    SGTrackerUserEventUIOriginGlobal,
    SGTrackerUserEventUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserFeedbackFeedbackChoices) {
    SGTrackerUserFeedbackFeedbackChoicesCallDismiss,
    SGTrackerUserFeedbackFeedbackChoicesEmailDismiss,
    SGTrackerUserFeedbackFeedbackChoicesEmailCallDismiss,
    SGTrackerUserFeedbackFeedbackChoicesEmailRateDismiss,
    SGTrackerUserFeedbackFeedbackChoicesRateDismiss,
    SGTrackerUserFeedbackFeedbackChoicesPositiveNegative,
    SGTrackerUserFeedbackFeedbackChoicesPositiveNegativeDismiss,
    SGTrackerUserFeedbackFeedbackChoicesPositiveNeutralNegativeDismiss,
    SGTrackerUserFeedbackFeedbackChoicesNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserFeedbackUIOrigin) {
    SGTrackerUserFeedbackUIOriginCheckout,
    SGTrackerUserFeedbackUIOriginDebug,
    SGTrackerUserFeedbackUIOriginNag,
    SGTrackerUserFeedbackUIOriginPublicSale,
    SGTrackerUserFeedbackUIOriginSettings,
    SGTrackerUserFeedbackUIOriginTransfer,
    SGTrackerUserFeedbackUIOriginMyTicketsTicket,
    SGTrackerUserFeedbackUIOriginGlobal,
    SGTrackerUserFeedbackUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserFeedbackFeedbackChoice) {
    SGTrackerUserFeedbackFeedbackChoicePositive,
    SGTrackerUserFeedbackFeedbackChoiceNeutral,
    SGTrackerUserFeedbackFeedbackChoiceNegative,
    SGTrackerUserFeedbackFeedbackChoiceRate,
    SGTrackerUserFeedbackFeedbackChoiceEmail,
    SGTrackerUserFeedbackFeedbackChoiceCall,
    SGTrackerUserFeedbackFeedbackChoiceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserHelpHelpType) {
    SGTrackerUserHelpHelpTypeNative,
    SGTrackerUserHelpHelpTypeZendesk,
    SGTrackerUserHelpHelpTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserHelpUIOrigin) {
    SGTrackerUserHelpUIOriginAccountSettings,
    SGTrackerUserHelpUIOriginCheckout,
    SGTrackerUserHelpUIOriginSellTickets,
    SGTrackerUserHelpUIOriginEventTickets,
    SGTrackerUserHelpUIOriginEventTicketsHelpPill,
    SGTrackerUserHelpUIOriginMyTickets,
    SGTrackerUserHelpUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserHelpContactType) {
    SGTrackerUserHelpContactTypeChat,
    SGTrackerUserHelpContactTypeCall,
    SGTrackerUserHelpContactTypeEmail,
    SGTrackerUserHelpContactTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserIDInfoDataField) {
    SGTrackerUserIDInfoDataFieldEmail,
    SGTrackerUserIDInfoDataFieldPassword,
    SGTrackerUserIDInfoDataFieldFirstName,
    SGTrackerUserIDInfoDataFieldLastName,
    SGTrackerUserIDInfoDataFieldUsername,
    SGTrackerUserIDInfoDataFieldMobilePhone,
    SGTrackerUserIDInfoDataFieldPhoto,
    SGTrackerUserIDInfoDataFieldNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserIDInfoEditType) {
    SGTrackerUserIDInfoEditTypeAdd,
    SGTrackerUserIDInfoEditTypeUpdate,
    SGTrackerUserIDInfoEditTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserIDInfoUIOrigin) {
    SGTrackerUserIDInfoUIOriginSettings,
    SGTrackerUserIDInfoUIOriginTransfer,
    SGTrackerUserIDInfoUIOriginPaidTransfer,
    SGTrackerUserIDInfoUIOriginPublicSale,
    SGTrackerUserIDInfoUIOriginOnboarding,
    SGTrackerUserIDInfoUIOriginGlobal,
    SGTrackerUserIDInfoUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserLoginCredentialSource) {
    SGTrackerUserLoginCredentialSourceGoogleSmartLock,
    SGTrackerUserLoginCredentialSourceManualInput,
    SGTrackerUserLoginCredentialSourceMagicLink,
    SGTrackerUserLoginCredentialSourceMagicCode,
    SGTrackerUserLoginCredentialSourceFacebookAccountUpgrade,
    SGTrackerUserLoginCredentialSourceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserTwoFAMode) {
    SGTrackerUserTwoFAModeApp,
    SGTrackerUserTwoFAModeSms,
    SGTrackerUserTwoFAModeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserLoginUIOrigin) {
    SGTrackerUserLoginUIOriginBrowse,
    SGTrackerUserLoginUIOriginCategory,
    SGTrackerUserLoginUIOriginCheckout,
    SGTrackerUserLoginUIOriginCheckoutPromocode,
    SGTrackerUserLoginUIOriginDrawer,
    SGTrackerUserLoginUIOriginEvent,
    SGTrackerUserLoginUIOriginEventPreOnsale,
    SGTrackerUserLoginUIOriginForgotPassword,
    SGTrackerUserLoginUIOriginHome,
    SGTrackerUserLoginUIOriginHomeSidebar,
    SGTrackerUserLoginUIOriginList,
    SGTrackerUserLoginUIOriginMyTickets,
    SGTrackerUserLoginUIOriginNavBarButton,
    SGTrackerUserLoginUIOriginNavBarTrackTickets,
    SGTrackerUserLoginUIOriginOnboarding,
    SGTrackerUserLoginUIOriginPerformer,
    SGTrackerUserLoginUIOriginSettings,
    SGTrackerUserLoginUIOriginSettingsPromocode,
    SGTrackerUserLoginUIOriginTracking,
    SGTrackerUserLoginUIOriginTransfer,
    SGTrackerUserLoginUIOriginVenue,
    SGTrackerUserLoginUIOriginHelpCenter,
    SGTrackerUserLoginUIOriginGlobal,
    SGTrackerUserLoginUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserLoginItemType) {
    SGTrackerUserLoginItemTypeForgotPassword,
    SGTrackerUserLoginItemTypeContinueWithPassword,
    SGTrackerUserLoginItemTypeUseMagicLink,
    SGTrackerUserLoginItemTypeUseMagicCode,
    SGTrackerUserLoginItemTypeRequestNewLink,
    SGTrackerUserLoginItemTypeRequestNewCode,
    SGTrackerUserLoginItemTypeUsedToSignInWithFacebook,
    SGTrackerUserLoginItemTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserLoginSplashLoginChoice) {
    SGTrackerUserLoginSplashLoginChoiceLoginFacebook,
    SGTrackerUserLoginSplashLoginChoiceLoginEmail,
    SGTrackerUserLoginSplashLoginChoiceRegisterEmail,
    SGTrackerUserLoginSplashLoginChoiceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserLoginSplashUIOrigin) {
    SGTrackerUserLoginSplashUIOriginBrowse,
    SGTrackerUserLoginSplashUIOriginCategory,
    SGTrackerUserLoginSplashUIOriginCheckout,
    SGTrackerUserLoginSplashUIOriginCheckoutPromocode,
    SGTrackerUserLoginSplashUIOriginDrawer,
    SGTrackerUserLoginSplashUIOriginEvent,
    SGTrackerUserLoginSplashUIOriginEventPreOnsale,
    SGTrackerUserLoginSplashUIOriginHome,
    SGTrackerUserLoginSplashUIOriginHomeSidebar,
    SGTrackerUserLoginSplashUIOriginiMessage,
    SGTrackerUserLoginSplashUIOriginList,
    SGTrackerUserLoginSplashUIOriginMyTickets,
    SGTrackerUserLoginSplashUIOriginNavBarButton,
    SGTrackerUserLoginSplashUIOriginOnboarding,
    SGTrackerUserLoginSplashUIOriginPerformer,
    SGTrackerUserLoginSplashUIOriginSettings,
    SGTrackerUserLoginSplashUIOriginSettingsPromocode,
    SGTrackerUserLoginSplashUIOriginTracking,
    SGTrackerUserLoginSplashUIOriginVenue,
    SGTrackerUserLoginSplashUIOriginHelpCenter,
    SGTrackerUserLoginSplashUIOriginGlobal,
    SGTrackerUserLoginSplashUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserLogoutUIOrigin) {
    SGTrackerUserLogoutUIOriginNavBarButton,
    SGTrackerUserLogoutUIOriginSettings,
    SGTrackerUserLogoutUIOriginGlobal,
    SGTrackerUserLogoutUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserNoticeActivityType) {
    SGTrackerUserNoticeActivityTypeDismiss,
    SGTrackerUserNoticeActivityTypeLink,
    SGTrackerUserNoticeActivityTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserNoticeUIOrigin) {
    SGTrackerUserNoticeUIOriginMyTickets,
    SGTrackerUserNoticeUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserNotificationNagSettingsType) {
    SGTrackerUserNotificationNagSettingsTypeAlertModal,
    SGTrackerUserNotificationNagSettingsTypeSettingsApp,
    SGTrackerUserNotificationNagSettingsTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserNotificationNagUIOrigin) {
    SGTrackerUserNotificationNagUIOriginOnboarding,
    SGTrackerUserNotificationNagUIOriginSettings,
    SGTrackerUserNotificationNagUIOriginPostPurchase,
    SGTrackerUserNotificationNagUIOriginAppForeground,
    SGTrackerUserNotificationNagUIOriginContextualPushPrompt,
    SGTrackerUserNotificationNagUIOriginPerformer,
    SGTrackerUserNotificationNagUIOriginTracking,
    SGTrackerUserNotificationNagUIOriginBrowse,
    SGTrackerUserNotificationNagUIOriginSearch,
    SGTrackerUserNotificationNagUIOriginGlobal,
    SGTrackerUserNotificationNagUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserNotificationNagDismissalLength) {
    SGTrackerUserNotificationNagDismissalLengthForever,
    SGTrackerUserNotificationNagDismissalLengthForNow,
    SGTrackerUserNotificationNagDismissalLengthNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserNotificationNagModalType) {
    SGTrackerUserNotificationNagModalTypeNativeiOS,
    SGTrackerUserNotificationNagModalTypeCustom,
    SGTrackerUserNotificationNagModalTypeContextualPushPrompt,
    SGTrackerUserNotificationNagModalTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserOnboardingOnboardingType) {
    SGTrackerUserOnboardingOnboardingTypeConnectServices,
    SGTrackerUserOnboardingOnboardingTypeConnectServicesDetail,
    SGTrackerUserOnboardingOnboardingTypeDealScore,
    SGTrackerUserOnboardingOnboardingTypeInAppDelivery,
    SGTrackerUserOnboardingOnboardingTypeLocation,
    SGTrackerUserOnboardingOnboardingTypeMap,
    SGTrackerUserOnboardingOnboardingTypeMobileEntry,
    SGTrackerUserOnboardingOnboardingTypePush,
    SGTrackerUserOnboardingOnboardingTypeSell,
    SGTrackerUserOnboardingOnboardingTypeTransfer,
    SGTrackerUserOnboardingOnboardingTypeIntro,
    SGTrackerUserOnboardingOnboardingTypeSearch,
    SGTrackerUserOnboardingOnboardingTypeReferral,
    SGTrackerUserOnboardingOnboardingTypeTracking,
    SGTrackerUserOnboardingOnboardingTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserOnboardingUIOrigin) {
    SGTrackerUserOnboardingUIOriginBrowse,
    SGTrackerUserOnboardingUIOriginEvent,
    SGTrackerUserOnboardingUIOriginHome,
    SGTrackerUserOnboardingUIOriginInitialOnboarding,
    SGTrackerUserOnboardingUIOriginTickets,
    SGTrackerUserOnboardingUIOriginGlobal,
    SGTrackerUserOnboardingUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPaymentDataField) {
    SGTrackerUserPaymentDataFieldCardCvv,
    SGTrackerUserPaymentDataFieldCardExpMonth,
    SGTrackerUserPaymentDataFieldCardExpYear,
    SGTrackerUserPaymentDataFieldCardExpCombined,
    SGTrackerUserPaymentDataFieldCardNumber,
    SGTrackerUserPaymentDataFieldBillFirst,
    SGTrackerUserPaymentDataFieldBillLast,
    SGTrackerUserPaymentDataFieldBillStreet1,
    SGTrackerUserPaymentDataFieldBillStreet2,
    SGTrackerUserPaymentDataFieldBillCity,
    SGTrackerUserPaymentDataFieldBillState,
    SGTrackerUserPaymentDataFieldBillCountry,
    SGTrackerUserPaymentDataFieldBillZip,
    SGTrackerUserPaymentDataFieldNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPaymentEditType) {
    SGTrackerUserPaymentEditTypeAdd,
    SGTrackerUserPaymentEditTypeUpdate,
    SGTrackerUserPaymentEditTypeEntry,
    SGTrackerUserPaymentEditTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPaymentUIOrigin) {
    SGTrackerUserPaymentUIOriginCheckout,
    SGTrackerUserPaymentUIOriginSettings,
    SGTrackerUserPaymentUIOriginPaidTransfer,
    SGTrackerUserPaymentUIOriginPublicSale,
    SGTrackerUserPaymentUIOriginVenuenext,
    SGTrackerUserPaymentUIOriginGlobal,
    SGTrackerUserPaymentUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPayoutEditType) {
    SGTrackerUserPayoutEditTypeAdd,
    SGTrackerUserPayoutEditTypeUpdate,
    SGTrackerUserPayoutEditTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPayoutUIOrigin) {
    SGTrackerUserPayoutUIOriginMyTickets,
    SGTrackerUserPayoutUIOriginPublicSale,
    SGTrackerUserPayoutUIOriginPaidTransfer,
    SGTrackerUserPayoutUIOriginSettings,
    SGTrackerUserPayoutUIOriginTransfer,
    SGTrackerUserPayoutUIOriginGlobal,
    SGTrackerUserPayoutUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPayoutStepName) {
    SGTrackerUserPayoutStepNamePersonalInfo,
    SGTrackerUserPayoutStepNameAddress,
    SGTrackerUserPayoutStepNamePayoutMethod,
    SGTrackerUserPayoutStepNameNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPayoutMethod) {
    SGTrackerUserPayoutMethodBank,
    SGTrackerUserPayoutMethodCaBank,
    SGTrackerUserPayoutMethodSroCredit,
    SGTrackerUserPayoutMethodUsBank,
    SGTrackerUserPayoutMethodVenmo,
    SGTrackerUserPayoutMethodVenmoEmail,
    SGTrackerUserPayoutMethodVenmoPhone,
    SGTrackerUserPayoutMethodNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPayoutAccountType) {
    SGTrackerUserPayoutAccountTypeBusiness,
    SGTrackerUserPayoutAccountTypeIndividual,
    SGTrackerUserPayoutAccountTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPerformerInteractionMethod) {
    SGTrackerUserPerformerInteractionMethod3DTouchPeek,
    SGTrackerUserPerformerInteractionMethodNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPerformerUIOrigin) {
    SGTrackerUserPerformerUIOriginBrowse,
    SGTrackerUserPerformerUIOriginCategory,
    SGTrackerUserPerformerUIOriginHomeSidebar,
    SGTrackerUserPerformerUIOriginList,
    SGTrackerUserPerformerUIOriginMyTicketsTicket,
    SGTrackerUserPerformerUIOriginPerformer,
    SGTrackerUserPerformerUIOriginTracking,
    SGTrackerUserPerformerUIOriginGlobal,
    SGTrackerUserPerformerUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPreferencesPreferenceChoice) {
    SGTrackerUserPreferencesPreferenceChoiceEnable,
    SGTrackerUserPreferencesPreferenceChoiceDisable,
    SGTrackerUserPreferencesPreferenceChoiceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPreferencesPreferenceType) {
    SGTrackerUserPreferencesPreferenceTypeAll,
    SGTrackerUserPreferencesPreferenceTypeEventReminder,
    SGTrackerUserPreferencesPreferenceTypeNewEvent,
    SGTrackerUserPreferencesPreferenceTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPromocodePromocodeType) {
    SGTrackerUserPromocodePromocodeTypeDiscount,
    SGTrackerUserPromocodePromocodeTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPromocodeUIOrigin) {
    SGTrackerUserPromocodeUIOriginCheckout,
    SGTrackerUserPromocodeUIOriginRegister,
    SGTrackerUserPromocodeUIOriginSettings,
    SGTrackerUserPromocodeUIOriginGlobal,
    SGTrackerUserPromocodeUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPromptActivityType) {
    SGTrackerUserPromptActivityTypeConfirmEmail,
    SGTrackerUserPromptActivityTypeEditEmail,
    SGTrackerUserPromptActivityTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPromptPromptType) {
    SGTrackerUserPromptPromptTypeAppStoreRating,
    SGTrackerUserPromptPromptTypeBuzzfeed,
    SGTrackerUserPromptPromptTypeConnectServices,
    SGTrackerUserPromptPromptTypeContactPermission,
    SGTrackerUserPromptPromptTypeFacebookAccountUpgrade,
    SGTrackerUserPromptPromptTypeLocationPermission,
    SGTrackerUserPromptPromptTypeLocationPushPermission,
    SGTrackerUserPromptPromptTypePushPermission,
    SGTrackerUserPromptPromptTypeSpotify,
    SGTrackerUserPromptPromptTypeCreateAccount,
    SGTrackerUserPromptPromptTypeDownloadApp,
    SGTrackerUserPromptPromptTypePriceDrop,
    SGTrackerUserPromptPromptTypeAda,
    SGTrackerUserPromptPromptTypeMusicPlayerSpotify,
    SGTrackerUserPromptPromptTypeReturnPolicy,
    SGTrackerUserPromptPromptTypeEmailConfirmation,
    SGTrackerUserPromptPromptTypePromotion,
    SGTrackerUserPromptPromptTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserPromptUIOrigin) {
    SGTrackerUserPromptUIOriginAppForeground,
    SGTrackerUserPromptUIOriginBrowse,
    SGTrackerUserPromptUIOriginHomepage,
    SGTrackerUserPromptUIOriginInitialOnboarding,
    SGTrackerUserPromptUIOriginLogin,
    SGTrackerUserPromptUIOriginMyTickets,
    SGTrackerUserPromptUIOriginNavBarDropdown,
    SGTrackerUserPromptUIOriginPostPurchase,
    SGTrackerUserPromptUIOriginSettings,
    SGTrackerUserPromptUIOriginLocationSearch,
    SGTrackerUserPromptUIOriginReferralInvites,
    SGTrackerUserPromptUIOriginEvent,
    SGTrackerUserPromptUIOriginModal,
    SGTrackerUserPromptUIOriginCheckout,
    SGTrackerUserPromptUIOriginVerticalList,
    SGTrackerUserPromptUIOriginHorizontalList,
    SGTrackerUserPromptUIOriginEventTickets,
    SGTrackerUserPromptUIOriginGlobal,
    SGTrackerUserPromptUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserRecoupmentUIOrigin) {
    SGTrackerUserRecoupmentUIOriginPublicSale,
    SGTrackerUserRecoupmentUIOriginGlobal,
    SGTrackerUserRecoupmentUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserReferralsDisplayType) {
    SGTrackerUserReferralsDisplayTypeModal,
    SGTrackerUserReferralsDisplayTypePage,
    SGTrackerUserReferralsDisplayTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserReferralsDisplayValue) {
    SGTrackerUserReferralsDisplayValueCopy,
    SGTrackerUserReferralsDisplayValueEmail,
    SGTrackerUserReferralsDisplayValueFacebook,
    SGTrackerUserReferralsDisplayValueMore,
    SGTrackerUserReferralsDisplayValueSms,
    SGTrackerUserReferralsDisplayValueTwitter,
    SGTrackerUserReferralsDisplayValueNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserRegisterUIOrigin) {
    SGTrackerUserRegisterUIOriginBrowse,
    SGTrackerUserRegisterUIOriginCategory,
    SGTrackerUserRegisterUIOriginCheckout,
    SGTrackerUserRegisterUIOriginCheckoutPromocode,
    SGTrackerUserRegisterUIOriginDrawer,
    SGTrackerUserRegisterUIOriginEmailModal,
    SGTrackerUserRegisterUIOriginEvent,
    SGTrackerUserRegisterUIOriginEventPreOnsale,
    SGTrackerUserRegisterUIOriginForgotPassword,
    SGTrackerUserRegisterUIOriginHome,
    SGTrackerUserRegisterUIOriginHomeSidebar,
    SGTrackerUserRegisterUIOriginList,
    SGTrackerUserRegisterUIOriginMyTickets,
    SGTrackerUserRegisterUIOriginNavBarButton,
    SGTrackerUserRegisterUIOriginOnboarding,
    SGTrackerUserRegisterUIOriginPerformer,
    SGTrackerUserRegisterUIOriginPromocodeLandingPage,
    SGTrackerUserRegisterUIOriginSettings,
    SGTrackerUserRegisterUIOriginSettingsPromocode,
    SGTrackerUserRegisterUIOriginTracking,
    SGTrackerUserRegisterUIOriginTransfer,
    SGTrackerUserRegisterUIOriginVenue,
    SGTrackerUserRegisterUIOriginGlobal,
    SGTrackerUserRegisterUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserUIOrigin) {
    SGTrackerUserUIOriginAccountSettings,
    SGTrackerUserUIOriginBrowse,
    SGTrackerUserUIOriginBrowseSearch,
    SGTrackerUserUIOriginCheckout,
    SGTrackerUserUIOriginEvent,
    SGTrackerUserUIOriginEventFilters,
    SGTrackerUserUIOriginEventInfo,
    SGTrackerUserUIOriginEventTickets,
    SGTrackerUserUIOriginInitialOnboarding,
    SGTrackerUserUIOriginListingDetail,
    SGTrackerUserUIOriginLogin,
    SGTrackerUserUIOriginLottery,
    SGTrackerUserUIOriginModal,
    SGTrackerUserUIOriginMyTickets,
    SGTrackerUserUIOriginMyTicketsTicket,
    SGTrackerUserUIOriginOnboarding,
    SGTrackerUserUIOriginPaidTransfer,
    SGTrackerUserUIOriginPerformer,
    SGTrackerUserUIOriginPostPurchase,
    SGTrackerUserUIOriginReferralInvites,
    SGTrackerUserUIOriginRegister,
    SGTrackerUserUIOriginResaleFlow,
    SGTrackerUserUIOriginSearch,
    SGTrackerUserUIOriginSellLanding,
    SGTrackerUserUIOriginSellTickets,
    SGTrackerUserUIOriginSettings,
    SGTrackerUserUIOriginSettingsPromocode,
    SGTrackerUserUIOriginTabSearch,
    SGTrackerUserUIOriginTickets,
    SGTrackerUserUIOriginTracking,
    SGTrackerUserUIOriginTrackingDashboard,
    SGTrackerUserUIOriginTransfer,
    SGTrackerUserUIOriginVenue,
    SGTrackerUserUIOriginGlobal,
    SGTrackerUserUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserServiceServiceType) {
    SGTrackerUserServiceServiceTypeFacebook,
    SGTrackerUserServiceServiceTypeLastFm,
    SGTrackerUserServiceServiceTypeMusicLibrary,
    SGTrackerUserServiceServiceTypeSpotify,
    SGTrackerUserServiceServiceTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserSettingsDisplayValue) {
    SGTrackerUserSettingsDisplayValueAbout,
    SGTrackerUserSettingsDisplayValueAccountSettings,
    SGTrackerUserSettingsDisplayValueAccountManager,
    SGTrackerUserSettingsDisplayValueConnectedServices,
    SGTrackerUserSettingsDisplayValueCreditCard,
    SGTrackerUserSettingsDisplayValueDeliveryAddress,
    SGTrackerUserSettingsDisplayValueFeedback,
    SGTrackerUserSettingsDisplayValueFaq,
    SGTrackerUserSettingsDisplayValueLocationServices,
    SGTrackerUserSettingsDisplayValueNotifications,
    SGTrackerUserSettingsDisplayValuePayoutMethod,
    SGTrackerUserSettingsDisplayValuePricesWithFees,
    SGTrackerUserSettingsDisplayValuePromoCodes,
    SGTrackerUserSettingsDisplayValueReferral,
    SGTrackerUserSettingsDisplayValueSetLocation,
    SGTrackerUserSettingsDisplayValueSortBy,
    SGTrackerUserSettingsDisplayValueSupport,
    SGTrackerUserSettingsDisplayValueTerms,
    SGTrackerUserSettingsDisplayValueNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserShareItemType) {
    SGTrackerUserShareItemTypeEvent,
    SGTrackerUserShareItemTypeListing,
    SGTrackerUserShareItemTypePerformer,
    SGTrackerUserShareItemTypeVenue,
    SGTrackerUserShareItemTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserShareSource) {
    SGTrackerUserShareSourceShareButton,
    SGTrackerUserShareSourceScreenshot,
    SGTrackerUserShareSourceNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserShareUIOrigin) {
    SGTrackerUserShareUIOriginEvent,
    SGTrackerUserShareUIOriginEventInfo,
    SGTrackerUserShareUIOriginListingDetail,
    SGTrackerUserShareUIOriginPerformer,
    SGTrackerUserShareUIOriginVenue,
    SGTrackerUserShareUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserShippingDataField) {
    SGTrackerUserShippingDataFieldShipFirst,
    SGTrackerUserShippingDataFieldShipLast,
    SGTrackerUserShippingDataFieldShipStreet1,
    SGTrackerUserShippingDataFieldShipStreet2,
    SGTrackerUserShippingDataFieldShipCity,
    SGTrackerUserShippingDataFieldShipState,
    SGTrackerUserShippingDataFieldShipCountry,
    SGTrackerUserShippingDataFieldShipZip,
    SGTrackerUserShippingDataFieldNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserShippingEditType) {
    SGTrackerUserShippingEditTypeAdd,
    SGTrackerUserShippingEditTypeUpdate,
    SGTrackerUserShippingEditTypeEntry,
    SGTrackerUserShippingEditTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserShippingUIOrigin) {
    SGTrackerUserShippingUIOriginCheckout,
    SGTrackerUserShippingUIOriginSettings,
    SGTrackerUserShippingUIOriginGlobal,
    SGTrackerUserShippingUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserSurveyItemType) {
    SGTrackerUserSurveyItemTypeBack,
    SGTrackerUserSurveyItemTypeComment,
    SGTrackerUserSurveyItemTypeDismiss,
    SGTrackerUserSurveyItemTypeRating,
    SGTrackerUserSurveyItemTypeResearch,
    SGTrackerUserSurveyItemTypeSubmit,
    SGTrackerUserSurveyItemTypeTag,
    SGTrackerUserSurveyItemTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserSurveyPageType) {
    SGTrackerUserSurveyPageTypeInitialRating,
    SGTrackerUserSurveyPageTypeDidAttend,
    SGTrackerUserSurveyPageTypeDidNotAttend,
    SGTrackerUserSurveyPageTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserTicketsUICategory) {
    SGTrackerUserTicketsUICategoryApp,
    SGTrackerUserTicketsUICategoryDirections,
    SGTrackerUserTicketsUICategoryEvent,
    SGTrackerUserTicketsUICategoryFood,
    SGTrackerUserTicketsUICategoryGiveaway,
    SGTrackerUserTicketsUICategoryInternal,
    SGTrackerUserTicketsUICategoryOther,
    SGTrackerUserTicketsUICategoryParking,
    SGTrackerUserTicketsUICategoryPolicy,
    SGTrackerUserTicketsUICategoryStmRenewal,
    SGTrackerUserTicketsUICategoryTicket,
    SGTrackerUserTicketsUICategoryUpsellEvent,
    SGTrackerUserTicketsUICategoryUpsellFood,
    SGTrackerUserTicketsUICategoryUpsellMerch,
    SGTrackerUserTicketsUICategoryUpsellParking,
    SGTrackerUserTicketsUICategoryUpsellStm,
    SGTrackerUserTicketsUICategoryUpsellTicket,
    SGTrackerUserTicketsUICategoryVenue,
    SGTrackerUserTicketsUICategoryNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserTicketsUIOrigin) {
    SGTrackerUserTicketsUIOriginBrowse,
    SGTrackerUserTicketsUIOriginEventTickets,
    SGTrackerUserTicketsUIOriginMyTickets,
    SGTrackerUserTicketsUIOriginNotification,
    SGTrackerUserTicketsUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserTicketsActivityType) {
    SGTrackerUserTicketsActivityTypeAccept,
    SGTrackerUserTicketsActivityTypeAppInstallWidget,
    SGTrackerUserTicketsActivityTypeAppleWallet,
    SGTrackerUserTicketsActivityTypeCalendar,
    SGTrackerUserTicketsActivityTypeCall,
    SGTrackerUserTicketsActivityTypeCancel,
    SGTrackerUserTicketsActivityTypeChat,
    SGTrackerUserTicketsActivityTypeCopy,
    SGTrackerUserTicketsActivityTypeDecline,
    SGTrackerUserTicketsActivityTypeDelist,
    SGTrackerUserTicketsActivityTypeDirections,
    SGTrackerUserTicketsActivityTypeDismiss,
    SGTrackerUserTicketsActivityTypeEdit,
    SGTrackerUserTicketsActivityTypeEmail,
    SGTrackerUserTicketsActivityTypeEnableNotifications,
    SGTrackerUserTicketsActivityTypeFaq,
    SGTrackerUserTicketsActivityTypeGooglePayPass,
    SGTrackerUserTicketsActivityTypeLink,
    SGTrackerUserTicketsActivityTypeList,
    SGTrackerUserTicketsActivityTypeLyft,
    SGTrackerUserTicketsActivityTypeNext,
    SGTrackerUserTicketsActivityTypeOpenSpotify,
    SGTrackerUserTicketsActivityTypeOptions,
    SGTrackerUserTicketsActivityTypePause,
    SGTrackerUserTicketsActivityTypePlay,
    SGTrackerUserTicketsActivityTypePrevious,
    SGTrackerUserTicketsActivityTypeReturnTickets,
    SGTrackerUserTicketsActivityTypeRoute,
    SGTrackerUserTicketsActivityTypeSell,
    SGTrackerUserTicketsActivityTypeSend,
    SGTrackerUserTicketsActivityTypeShare,
    SGTrackerUserTicketsActivityTypeSnapchat,
    SGTrackerUserTicketsActivityTypeSupport,
    SGTrackerUserTicketsActivityTypeTrack,
    SGTrackerUserTicketsActivityTypeUntrack,
    SGTrackerUserTicketsActivityTypeVenueCommerceConcessions,
    SGTrackerUserTicketsActivityTypeVenueCommerceExperience,
    SGTrackerUserTicketsActivityTypeVenueCommerceFood,
    SGTrackerUserTicketsActivityTypeVenueCommerceMerchandise,
    SGTrackerUserTicketsActivityTypeVerifyEmail,
    SGTrackerUserTicketsActivityTypeVerifyPhone,
    SGTrackerUserTicketsActivityTypeViewListing,
    SGTrackerUserTicketsActivityTypeViewMore,
    SGTrackerUserTicketsActivityTypeViewPDF,
    SGTrackerUserTicketsActivityTypeWebview,
    SGTrackerUserTicketsActivityTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserTicketsItemType) {
    SGTrackerUserTicketsItemTypeEvent,
    SGTrackerUserTicketsItemTypeIncomingTransfer,
    SGTrackerUserTicketsItemTypeIngestion,
    SGTrackerUserTicketsItemTypeListing,
    SGTrackerUserTicketsItemTypeLocationPermission,
    SGTrackerUserTicketsItemTypeLocationPushPermission,
    SGTrackerUserTicketsItemTypeNote,
    SGTrackerUserTicketsItemTypePushPermission,
    SGTrackerUserTicketsItemTypeOrderStatus,
    SGTrackerUserTicketsItemTypeOutgoingTransfer,
    SGTrackerUserTicketsItemTypeTicketGroup,
    SGTrackerUserTicketsItemTypeTransferManager,
    SGTrackerUserTicketsItemTypeWidget,
    SGTrackerUserTicketsItemTypeCard,
    SGTrackerUserTicketsItemTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserTicketsStyleType) {
    SGTrackerUserTicketsStyleTypeCardWithAdditionalNotes,
    SGTrackerUserTicketsStyleTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserTicketsDisplayType) {
    SGTrackerUserTicketsDisplayTypeBarcode,
    SGTrackerUserTicketsDisplayTypePDF,
    SGTrackerUserTicketsDisplayTypeScreenshot,
    SGTrackerUserTicketsDisplayTypePlaceholder,
    SGTrackerUserTicketsDisplayTypeDoeTakeover,
    SGTrackerUserTicketsDisplayTypePending,
    SGTrackerUserTicketsDisplayTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserTicketsSourceType) {
    SGTrackerUserTicketsSourceTypeAmPastEvents,
    SGTrackerUserTicketsSourceTypeAmUpcomingEvents,
    SGTrackerUserTicketsSourceTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserTicketsBarcodeType) {
    SGTrackerUserTicketsBarcodeTypeQrcode,
    SGTrackerUserTicketsBarcodeTypePdf417,
    SGTrackerUserTicketsBarcodeTypeSecureEntry,
    SGTrackerUserTicketsBarcodeTypeQrcodeTm,
    SGTrackerUserTicketsBarcodeTypeFortressClientRotating,
    SGTrackerUserTicketsBarcodeTypeRotating,
    SGTrackerUserTicketsBarcodeTypeEnhancedRotating,
    SGTrackerUserTicketsBarcodeTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserTicketsViewType) {
    SGTrackerUserTicketsViewTypeEventTickets,
    SGTrackerUserTicketsViewTypeFullScreenTickets,
    SGTrackerUserTicketsViewTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserTwoFAUIOrigin) {
    SGTrackerUserTwoFAUIOriginLogin,
    SGTrackerUserTwoFAUIOriginSettingsDisable,
    SGTrackerUserTwoFAUIOriginSettingsEnable,
    SGTrackerUserTwoFAUIOriginGlobal,
    SGTrackerUserTwoFAUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserUnverifiedContactAlertContactType) {
    SGTrackerUserUnverifiedContactAlertContactTypeEmail,
    SGTrackerUserUnverifiedContactAlertContactTypeMobilePhone,
    SGTrackerUserUnverifiedContactAlertContactTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserVenueCommerceProductType) {
    SGTrackerUserVenueCommerceProductTypeExperience,
    SGTrackerUserVenueCommerceProductTypeFood,
    SGTrackerUserVenueCommerceProductTypeMerchandise,
    SGTrackerUserVenueCommerceProductTypeNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerVenueCommerceUIOrigin) {
    SGTrackerVenueCommerceUIOriginBrowse,
    SGTrackerVenueCommerceUIOriginEventTickets,
    SGTrackerVenueCommerceUIOriginMyTickets,
    SGTrackerVenueCommerceUIOriginNotification,
    SGTrackerVenueCommerceUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserVenueInteractionMethod) {
    SGTrackerUserVenueInteractionMethod3DTouchPeek,
    SGTrackerUserVenueInteractionMethodNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerUserVenueUIOrigin) {
    SGTrackerUserVenueUIOriginList,
    SGTrackerUserVenueUIOriginMyTicketsTicket,
    SGTrackerUserVenueUIOriginTracking,
    SGTrackerUserVenueUIOriginVenue,
    SGTrackerUserVenueUIOriginGlobal,
    SGTrackerUserVenueUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerVenueUIOrigin) {
    SGTrackerVenueUIOriginBrowseSearch,
    SGTrackerVenueUIOriginCategorySidebar,
    SGTrackerVenueUIOriginEventInfo,
    SGTrackerVenueUIOriginEventSidebar,
    SGTrackerVenueUIOriginHomeSearch,
    SGTrackerVenueUIOriginNavBarSearch,
    SGTrackerVenueUIOriginPerformer,
    SGTrackerVenueUIOriginTabSearch,
    SGTrackerVenueUIOriginTracking,
    SGTrackerVenueUIOriginTrackingDashboard,
    SGTrackerVenueUIOriginList,
    SGTrackerVenueUIOriginNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerVenueDirectionsDirectionMethod) {
    SGTrackerVenueDirectionsDirectionMethodDrive,
    SGTrackerVenueDirectionsDirectionMethodTransit,
    SGTrackerVenueDirectionsDirectionMethodWalk,
    SGTrackerVenueDirectionsDirectionMethodNone,
};

typedef NS_ENUM(NSUInteger, SGTrackerVenueDirectionsUIOrigin) {
    SGTrackerVenueDirectionsUIOriginEvent,
    SGTrackerVenueDirectionsUIOriginEventInfo,
    SGTrackerVenueDirectionsUIOriginTracking,
    SGTrackerVenueDirectionsUIOriginGlobal,
    SGTrackerVenueDirectionsUIOriginNone,
};
