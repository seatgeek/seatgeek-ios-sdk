//
//  Created by matt on 15/07/15.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

typedef NS_ENUM(NSUInteger, SGTrackerTransfersUIOrigin);

typedef NS_ENUM(NSInteger, SGTransferState) {
    SGTransferStateNothing,
    SGTransferStateLoading,
    SGTransferStateCompleted,
    SGTransferStateFailed,
};

typedef NS_ENUM(NSInteger, SGTransferActionType) {
    SGTransferActionTypeSend,
    SGTransferActionTypeCancel,
    SGTransferActionTypeDecline,
    SGTransferActionTypeAccept,
};


#define SGTransferStateChangeBegan @"SGTransferStateChangeBegan"  //MGEvent.  Context is the transfer object.
#define SGTransferStateChangeEnded @"SGTransferStateChangeEnded"  //MGEvent.  Context is the transfer object.
#define SGTransferSent @"SGTransferSent"  //Triggered when a transfer is sent successfully
#define SGTransferCancelled @"SGTransferCancelled"

//TODO consolidate these into the above
#define SGTransferActionSucceeded @"SGTransferActionSucceeded"    //MGEvent.  No context.
#define SGTransferActionFailed @"SGTransferActionFailed"          //MGEvent.  No context.

@class SGTransferPerson, SGTicketGroup, SGTransferStatus, SGPEvent, SGTicket;
@class SGPaymentMethod, SGPaymentMethodSpreedly, SGPaymentMethodApplePay;
@class SGAPIError, SGPayout, SGPurchaseLineItem;

@interface SGTransfer : SGPItem

@property (nonatomic, strong) SGPEvent *event;
@property (nonatomic, strong) NSNumber *quantity;
@property (nonatomic, strong) NSNumber *pricePerTicket;
@property (nonatomic) BOOL canApplePay;
@property (nonatomic,assign) BOOL applePaySelected;
@property (nonatomic, strong) NSNumber *total;
@property (nonatomic, copy) NSString *signature;
@property (nonatomic, strong) SGTransferPerson *sender;
@property (nonatomic, strong) SGTransferPerson *recipient;
@property (nonatomic, strong) SGTicketGroup *ticketGroup;
@property (nonatomic, strong) SGTransferStatus *status;
@property (nonatomic, strong) NSArray <SGAPIError *> *errors;
@property (nonatomic, assign) SGTransferState state;
@property (nonatomic, strong) SGPaymentMethod *paymentMethod;
@property (nonatomic, strong) SGPayout *payout;
@property (nonatomic) BOOL seatSelectionEnabled;
@property (nonatomic, strong) NSString *seatSelectionMessage;
@property (nonatomic, strong) NSArray <NSArray *> *availableSeatSelections;
@property (nonatomic, strong) NSNumber *maxQuantity;

+ (instancetype)transferWithTicketGroup:(SGTicketGroup *)group recipient:(SGTransferPerson *)recipient;

- (BOOL)currentUserIsSender;
- (BOOL)currentUserIsRecipient;
- (BOOL)isPaid;
- (NSString *)readableDescriptionWithNumericQuantity:(BOOL)useNumericQuantity;
- (NSString *)readableShortDescriptionForAction:(SGTransferActionType)action;
- (NSString *)readableLongDescriptionForAction:(SGTransferActionType)action;
- (NSString *)subjectForHelpEmail;
- (NSString *)bodyForHelpEmail;

// Convenience properties; return nil if the payment method is not of that type
@property (readonly, nonatomic) SGPaymentMethodSpreedly *spreedlyPaymentMethod;
@property (readonly, nonatomic) SGPaymentMethodApplePay *applePayPaymentMethod;

+ (void)getCountPendingIncomingTransfersWithSuccess:(void(^)(NSInteger count))successBlock
                                            failure:(void(^)(SGAPIError *apiError))failureBlock;

- (void)performAction:(SGTransferActionType)action uIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin
            onSuccess:(void(^)(void))success onFail:(SGAPIFailBlock)fail;

- (void)fetchPretransferInfo:(void(^)(void))success onFail:(SGAPIFailBlock)fail;

- (void)sendWithUIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin
                 tickets:(NSArray <SGTicket *>*)tickets
                    then:(void(^)(void))success
                  onFail:(SGAPIFailBlock)fail;

+ (void)sendTransfer:(SGTransfer *)transfer
        withUIOrigin:(SGTrackerTransfersUIOrigin)uIOrigin
           ticketIDs:(NSArray *)ticketIDs
             eventID:(NSString *)eventID
                then:(void(^)(void))success
              onFail:(SGAPIFailBlock)fail;

// These are to be used by MyTickets.Transfer
- (void)acceptTransferWithQueryPath:(NSString *)queryPath
                            success:(void(^)(void))success
                             onFail:(SGAPIFailBlock)fail
NS_SWIFT_NAME(accept(queryPath:success:failure:));

- (void)declineTransferWithQueryPath:(NSString *)queryPath
                             success:(void(^)(void))success
                              onFail:(SGAPIFailBlock)fail
NS_SWIFT_NAME(decline(queryPath:success:failure:));


/**
 * This method is currently only used when paying with Apple Pay.
 *
 * For Apple Pay, we tell the server what merchant IDs we support in the app, and the server then
 * tells us which merchant ID it would like us to use. For checkout, this conversation
 * is built into the checkout summary endpoint, and for transfers it occurs here.
 */
- (void)doPreRequestForAcceptPaidWithSuccess:(void(^)(NSString *applePayMerchantID))successBlock
                                        fail:(void(^)(SGAPIError *apiError))failBlock;

+ (NSArray<SGAPIError *> *)errorsIn:(NSDictionary *)response request:(SGHTTPRequest *)request;

- (NSArray *)errorsForCategory:(NSString *)errorCategory;
- (NSArray *)localValidationErrorsForCategory:(NSString *)errorCategory;
- (NSArray *)localValidationErrors;

@end
