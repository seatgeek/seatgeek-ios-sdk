//
//  SGPaymentMethodForm.h
//  SeatGeek
//
//  Created by James Van-As on 4/09/14.
//  Copyright (c) 2014 SeatGeek. All rights reserved.
//

#import "SGPaymentControllerProtocol.h"
#import "SGCheckoutEditScreen.h"

typedef NS_ENUM(NSUInteger, SGTrackerUserPaymentUIOrigin);

@class SGPaymentMethodSpreedly, SGPaymentMethodBillingInfo;

@protocol CheckoutViewModelProtocol;

@interface SGPaymentMethodForm : SGCheckoutEditScreen
      <SGPaymentControllerProtocol, UITextFieldDelegate>

- (instancetype)initWithCheckoutViewModel:(id <CheckoutViewModelProtocol>)checkoutViewModel;
- (void)savePaymentMethodThenDo:(MGBlock)success onFail:(SGAPIFailBlock)fail;

@property (nonatomic, strong) SGPaymentMethodSpreedly *paymentMethod;

@property (nonatomic, strong) SGPaymentMethodBillingInfo *billingInfo;

@property (nonatomic,assign) BOOL showDeleteButton;
@property (nonatomic,assign) BOOL focusKeyboardOnOpen;
@property (nonatomic,assign) NSTimeInterval focusKeyboardOnOpenDelay;

@property (nonatomic) SGTrackerUserPaymentUIOrigin uIOrigin;

@end
