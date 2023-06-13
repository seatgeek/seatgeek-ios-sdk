//
//  SGModalNavigator.h
//  SeatGeek
//
//  Created by James Van-As on 20/04/18.
//  Copyright © 2018 SeatGeek. All rights reserved.
//

@import UIKit;
#import "SGModalController.h"
#import "SGModalCardHolder.h"
#import "SGNavigatorChildController.h"
#import "SGModalCard.h"
#import "SGModalNavigatorTransition.h"

@class SGNavigationController;

@interface SGModalNavigator : SGModalController <SGNavigatorProtocol, SGModalCardCustomAnimation,
                                                 SGModalNavigatorTransitionProtocol>

+ (nonnull instancetype)navigatorWithInitialVC:(SGNavigatorChildController * _Nonnull)initialController;

- (void)pushViewController:(UIViewController * _Nonnull)viewController animated:(BOOL)animated;
- (nullable UIViewController *)popViewController:(UIViewController * _Nonnull)controller animated:(BOOL)animated;
- (nullable UIViewController *)popViewControllerAnimated:(BOOL)animated;
- (nullable NSArray *)popToRootViewControllerAnimated:(BOOL)animated;
- (nullable NSArray *)popToViewController:(SGNavigatorChildController * _Nullable)controller animated:(BOOL)animated;
- (nullable NSArray *)popToViewControllerOfClass:(Class _Nullable )class animated:(BOOL)animated;

/// The navigation controller contained in this modal
@property (nonatomic, readonly, nonnull) SGNavigationController *childNavigationController;
@property (nonatomic, readonly, nonnull) SGNavigationBar *sgNavigationBar;

@property (nonatomic, readonly, nonnull) UIView *behindTintView;

@property (nonatomic, strong, nullable) SGModalNavigatorTransition *transition;
@property (nonatomic, readonly, nonnull) UIView *navBarUnderlay;

@end
