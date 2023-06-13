//
//  Created by matt on 25/07/14.
//

@import UIKit;
#import "SGNavigationBarContent.h"

#define SGNavBarBackgroundChanged @"SGNavBarBackgroundChanged"

@interface SGNavigationBar : UIView

/// The default navigation bar height of the "normal" navbar size
+ (CGFloat)defaultNavBarHeight;

/// The default navigation bar height of the "tall" navbar size
+ (CGFloat)tallNavBarHeight;

/// The height of a nav bar (varies by device)
- (CGFloat)navBarHeight;

/// Animate between normal and tall nav bars on Browse Lists
@property (nonatomic, assign) BOOL usesTallNavBar;
@property (nonatomic, assign) CGFloat usesTallNavBarProgress;

// The height the nav bar should assume (plus any applicable safe area insets) when the bar is in the non-tall state.
// This defaults to `[SGNavigationBar defaultNavBarHeight]`.
@property (nonatomic, assign) CGFloat collapsedNavBarHeight;

// The height the nav bar should assume (plus any applicable safe area insets) in the expanded/tall state.
// This defaults to `[SGNavigationBar tallNavBarHeight]`.
@property (nonatomic, assign) CGFloat expandedNavBarHeight;

// All content that sits on top of the nav bar's background.
@property (nonatomic, readonly) SGNavigationBarContent *content;

// YES if the bottom border should be shown. Defaults to YES.
@property (nonatomic, assign) BOOL showsBottomBorder;

/// Allow touches that aren't on buttons to pass through.  Defaults to NO.
@property (nonatomic, assign) BOOL allowTouchesToPassThrough;

/// If the navbar is transitioning between view controllers
@property (nonatomic, assign) BOOL isTransitioning;

/// If true, the nav bar ignores any safe area inset changes. Usually controlled by the SGNavigationController
@property (nonatomic) BOOL ignoreSafeAreaInsetChanges;

/// If the navbar is transparent or not
@property (nonatomic, assign) BOOL translucent;

/// the tint color of the background
@property (nonatomic) UIColor *barTintColor;

/// If the navbar has a hairline border at the bottom
- (void)setHasBottomBorder:(BOOL)hasBottomBorder animated:(BOOL)animated;

/// If the navbar uses margin insets for the hairline border at the bottom. defaults to YES
@property (nonatomic, assign) BOOL bottomBorderHasMargins;

/// set the background color
- (void)setBackgroundColor:navBarColor
        treatAsTransparent:(BOOL)transparencyInvolved;

/// the underlay which sits under notches
@property (nonatomic, readonly) UIView *underlay;

/// animate the background color
- (void)animateFrom:(UIColor *)fromColor to:(UIColor *)toColor;

- (UINavigationItem *)navigationItem;
- (void)setNavigationItem:(UINavigationItem *)item;
/// left and right navigation item is used for transitions
- (void)setTransitionToNavigationItem:(UINavigationItem *)item;
/// [0,1].  Transition progress from left navigation item to right navigation item
- (void)setTransitionProgress:(CGFloat)progress;

@end
