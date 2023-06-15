//
//  SGPurchase.h
//  Pods
//
//  Created by James Van-As on 14/04/15.
//
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGItem.h>
#else
#import <SeatGeekSDK/SGItem.h>
#endif

@class SGMarketDetails, SGPurchaseDeliveryMethod, SGPEvent, SGPurchaseTimelineEntry, SGTicketGroup, SGQuery, SGAddress, SGPaymentMethod;

@interface SGPurchase : SGItem

@property (nonatomic, copy)   NSString *orderId;
@property (nonatomic, strong) NSString *clickId;
@property (nonatomic, strong) NSNumber *eventId;

/**
 ID of the parent/container event, if any.
 */
@property (nonatomic, strong) NSNumber *parentEventId;
@property (nonatomic, strong) NSArray *lineItems;
@property (nonatomic, copy)   NSString *row;
@property (nonatomic, copy)   NSString *section;
@property (nonatomic, copy)   NSString *notes;
@property (nonatomic, copy)   NSString *market;
@property (nonatomic, strong) SGMarketDetails *marketDetails;
@property (nonatomic, strong) NSString *currencyCode;
@property (nonatomic, strong) SGPurchaseDeliveryMethod *deliveryMethod;
@property (nonatomic, strong) SGPEvent *event;
@property (nonatomic, strong) SGTicketGroup *ticketGroup;
@property (nonatomic, strong) NSArray<SGPurchaseTimelineEntry *>* timelineEntries;
@property (nonatomic, strong) NSDate *createdAt;
@property (nonatomic, strong, readonly) NSNumber *quantity;
@property (nonatomic, strong) SGAddress *shippingAddress;
@property (nonatomic, strong) SGPaymentMethod *paymentMethod;
@property (nonatomic, copy) NSNumber *commission;

// from client
@property (nonatomic, copy) NSString *shippingEmail;
@property (nonatomic, copy) NSString *shippingPhone;
@property (nonatomic, copy) NSString *prettyShippingPhone;
@property (nonatomic, copy) NSString *confirmationStatus;

- (SGPurchaseTimelineEntry *)currentTimelineEntry;
- (BOOL)shouldShowStatusTimeline;
- (NSNumber *)tax;
- (NSNumber *)totalPrice;
- (NSString *)readableDescription;
- (NSString *)subjectForHelpEmail;
- (NSString *)bodyForHelpEmail;

@end
