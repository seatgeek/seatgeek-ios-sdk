//
//  SGCheckoutEditScreen.h
//  SeatGeek
//
//  Created by James Van-As on 20/11/14.
//  Copyright (c) 2014 SeatGeek. All rights reserved.
//

#import "SGPaymentControllerProtocol.h"
#import "SGCheckoutBaseScreen.h"

@class SGFadeLoadingView, SGCheckout, SGNavBarButton, SGBottomNavigatorChildControllerWrapper;

@protocol CheckoutViewModelProtocol;

@interface SGCheckoutEditScreen : SGCheckoutBaseScreen <SGPaymentControllerProtocol>

@property (nonatomic, assign) BOOL saveChangesOnBack;
@property (nonatomic, assign) BOOL hasChanged;
@property (nonatomic, assign) BOOL showNoButtons;

- (void)undoChanges;
- (void)saveChangesThenDo:(MGBlock)success fail:(SGAPIFailBlock)fail;
- (void)showLoadingView:(BOOL)show;

@property (nonatomic,strong) SGNavBarButton *backButton;
@property (nonatomic,strong) SGNavBarButton *cancelButton;
@property (nonatomic,strong) SGNavBarButton *doneButton;
@property (nonatomic,strong) SGFadeLoadingView *loadingView;
@property (nonatomic,weak) SGBottomNavigatorChildControllerWrapper *bottomNavigatorWrapper;

- (void)tappedBack;
- (void)tappedDone;
- (void)tappedCancel;

@property (nonatomic, strong) id <CheckoutViewModelProtocol>checkoutViewModel;

- (instancetype)initWithCheckoutViewModel:(id <CheckoutViewModelProtocol>)checkoutViewModel;

@end
