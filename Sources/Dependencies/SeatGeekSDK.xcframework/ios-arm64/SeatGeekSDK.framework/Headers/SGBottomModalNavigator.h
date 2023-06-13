//
//  SGBottomModalNavigator.h
//  SeatGeek
//
//  Created by James Van-As on 20/10/15.
//  Copyright © 2015 SeatGeek. All rights reserved.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import "MGBox.h"
#endif

#import "SGBottomModalController.h"
#import "SGNavigatorProtocol.h"

@class SGNavigatorChildController;
@class SGBottomModalNavigator;
@class SGTypestyle;

@protocol SGBottomModalNavigatorDelegate <NSObject>
@optional - (void)bottomModalNavigator:(SGBottomModalNavigator *)bottomModalNavigator scrollViewDidScroll:(UIScrollView*)scrollView;
@end

@interface SGBottomModalNavigator : SGBottomModalController <SGNavigatorProtocol,
                                                             UIScrollViewDelegate>

+ (instancetype)navigatorWithInitialVC:(SGNavigatorChildController *)initialController;

+ (instancetype)navigatorWithInitialVC:(SGNavigatorChildController *)initialController
                            hideHeader:(BOOL)shouldHideHeader;

- (void)removeControllersBelow:(SGNavigatorChildController *)controller;

@property (nonatomic, weak) id<SGBottomModalNavigatorDelegate> delegate;

@property (readonly, assign) UIEdgeInsets sgSafeAreaInsets;

/// open the modal on pushing it's first view controller
@property (nonatomic, assign) BOOL openOnPush;

// defaults to false
@property (nonatomic, assign) BOOL shouldDismissKeyboardOnScroll;

// Contains everything except the header
@property (nonatomic, strong) MGBox *innerContainerView;

@property (nonatomic, strong) UIView *header;
@property (nonatomic, strong) SGTypestyle *headerTypestyle;

@property (nonatomic, strong) UIView *footer;
@property (nonatomic, assign) BOOL leftAlignNavigationTitleIfPossible;
@property (nonatomic, strong) UIView *underlay; // stops gaps peeking through

+ (CGFloat)extraTopInset:(BOOL)isInterfaceThin;
@property (nonatomic, assign, readonly) CGFloat lastTopInset;

- (void)hideHeader;

@end
