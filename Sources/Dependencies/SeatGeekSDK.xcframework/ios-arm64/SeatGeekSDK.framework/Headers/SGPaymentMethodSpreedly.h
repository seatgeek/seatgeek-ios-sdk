//
//  Created by matt on 20/01/15.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPaymentMethod.h>
#else
#import <SeatGeekSDK/SGPaymentMethod.h>
#endif

#define SGUpdatePaymentMethodsWithDict  @"SGUpdatePaymentMethodsWithDict"
#define SGDeletePaymentMethod           @"SGDeletePaymentMethod"
#define SGRefreshCreditCardFields       @"SGRefreshCreditCardFields"

@interface SGPaymentMethodSpreedly : SGPaymentMethod
      <NSCopying>

@property (nonatomic, copy) NSString *storageState;
@property (nonatomic, assign) BOOL cvvRecacheNeeded;
@property (nonatomic, assign) BOOL eligibleForRecoupment;

- (void)deleteFromServerOnFail:(SGAPIFailBlock)fail;
- (void)setIsDefault:(BOOL)isDefault tellServer:(BOOL)tellServer;
- (void)setIsEligibleRecoupmentMethodThenDo:(void(^)(NSDictionary *responseJSON))success
                                    failure:(void(^)(void))failure;

- (BOOL)needToSendToSpreedly;
- (BOOL)needToCopyAndDeletePaymentMethod;
- (void)sendToSpreedlyThenDo:(void(^)(void))success onFail:(SGAPIFailBlock)fail;
- (void)recacheCVVThenDo:(void(^)(void))success onFail:(SGAPIFailBlock)fail wasUI:(BOOL)wasUI;
- (void)saveNewCopyDeleteThen:(MGBlock)success onFail:(SGAPIFailBlock)fail;

@end
