//
//  UIViewController+UIViewController_SeatGeek.h
//  SeatGeek
//
//  Created by James Van-As on 18/09/17.
//  Copyright © 2017 SeatGeek. All rights reserved.
//

@import UIKit;

@class SGNavigationController;

@interface UIViewController (SeatGeek)

@property (readonly, nullable) SGNavigationController *sgNavigationController;
@property (readonly) UIEdgeInsets sgSafeAreaInsets;
/// the top presented view controller in the stack, if any
@property (readonly, nullable) UIViewController *topPresentedController;

/// Present the view controller in an animated fashion on top of the top view controller wherever that may be
- (void)present;

/// Present the view controller on top of the top view controller wherever that may be
- (void)presentAnimated:(BOOL)animated;

@end
