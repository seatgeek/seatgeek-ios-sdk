//
//  SGBottomModalChildController.h
//  SeatGeek
//
//  Created by James Van-As on 20/10/15.
//  Copyright © 2015 SeatGeek. All rights reserved.
//

@import UIKit;
#import "SGNavigatorProtocol.h"
#import "SGViewController.h"
#import "SGTransitionGestureProtocol.h"

#define SGScrollNavigatorToShowView @"SGScrollNavigatorToShowView"

typedef enum SGTransitionDirection {
    SGTransitionDirectionNone,
    SGTransitionDirectionPop,
    SGTransitionDirectionPush
} SGTransitionDirection;

typedef enum SGNavigatorAnimation {
    SGNavigatorAnimationPush,
    SGNavigatorAnimationFade
} SGNavigatorAnimation;

@class SGBottomModalNavigator, SGTypestyle;

@interface SGNavigatorChildController : SGViewController <SGTransitionGestureProtocol>
/// set to non zero to force the width of this controller's view at construction time
@property (nonatomic, assign) CGFloat forcedWidth;
@property (nonatomic, assign) CGFloat contentHeight;
@property (nonatomic, assign) BOOL automaticallyResizeWithKeyboard; // defaults to YES
@property (nonatomic, assign) CGFloat extraTopInset; // The space between the content and the 'card'

@property (nonatomic, assign) CGFloat topWindowInset; // The space between the card and the top of the window/superview

// YES if the header's bottom border should always be shown. Defaults to YES.
@property (nonatomic, assign) BOOL showsHeaderBottomBorder;

// YES if the header's bottom border should be shown once the header reaches the top of the screen. Defaults to NO.
@property (nonatomic, assign) BOOL showsHeaderBottomBorderWhenScrolling;

// Height to use for the header. Defaults to 52.
@property (nonatomic, assign) CGFloat headerHeight;

// Height to use when the header is scrolled to the top of the screen. Defaults to 52.
@property (nonatomic, assign) CGFloat scrolledHeaderHeight;

// Typestyle to use for header titles. Defaults to `headline3`.
@property (nonatomic, strong) SGTypestyle *headerTypestyle;

@property (nonatomic, assign) CGFloat topInsetPercentage; // The desired percentage of space between the card and the top of the window/superview

- (BOOL)matchHeightOfPrevController;
- (SGNavigatorAnimation)transitionAnimation;    // defaults to SGPush
- (UIView *)footer; // optional
- (UIViewController<SGNavigatorProtocol> *)navigator;

#pragma mark - UIViewController navigation overrides
- (void)dismissViewControllerAnimated:(BOOL)flag completion:(void (^)(void))completion;
- (void)pushViewController:(UIViewController *)controller animated:(BOOL)animated;
- (void)popViewController:(SGNavigatorChildController *)controller animated:(BOOL)animated;
- (void)popViewControllerAnimated:(BOOL)animated;
- (void)popViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion;
- (void)popToRootViewControllerAnimated:(BOOL)animated;
- (void)popToViewController:(SGNavigatorChildController *)controller animated:(BOOL)animated;
- (void)popToViewController:(SGNavigatorChildController *)controller animated:(BOOL)animated completion:(void (^)(void))completion;
- (void)popToViewControllerOfClass:(Class)class animated:(BOOL)animated;

- (void)performUIViewControllerDismissAnimated:(BOOL)animated completion:(void (^)(void))completion;


@end
