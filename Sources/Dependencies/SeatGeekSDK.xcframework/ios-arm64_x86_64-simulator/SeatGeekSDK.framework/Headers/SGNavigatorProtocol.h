//
//  SGNavigatorProtocol.h
//  SeatGeek
//
//  Created by James Van-As on 21/10/15.
//  Copyright © 2015 SeatGeek. All rights reserved.
//

@import UIKit;

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import "MGBlockWrapper.h"
#endif

@class SGNavigationBar;

@protocol SGNavigatorProtocol <NSObject>

- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (UIViewController *)popViewController:(UIViewController *)controller animated:(BOOL)animated;
- (UIViewController *)popViewControllerAnimated:(BOOL)animated;
- (NSArray *)popToRootViewControllerAnimated:(BOOL)animated;
- (NSArray *)popToViewController:(UIViewController *)controller animated:(BOOL)animated;
- (NSArray *)popToViewControllerOfClass:(Class)class animated:(BOOL)animated;

- (void)close;
- (void)closeThen:(MGBlock)afterClose;

/// returns the SG Navigation bar if we have one, otherwise nil
@property (nonatomic, readonly) SGNavigationBar *sgNavigationBar;

@property (nonatomic, strong) NSArray <UIViewController *> *viewControllers;
@property (readonly, assign) UIEdgeInsets sgSafeAreaInsets;
@property (nonatomic, copy) MGBlock onClose;
@property (nonatomic, copy) MGBlock afterClose;

@optional

/// Scroll view backing this navigator. May be nil.
@property (nonatomic, readonly) UIScrollView *scrollView;

@end
