//
//  SGModalCardHolder.h
//  SeatGeek
//
//  Created by James Van-As on 13/01/14.
//  Copyright (c) 2014 SeatGeek. All rights reserved.
//

@import UIKit;
#import "SGSafeAreaInsetChangeBlockerProtocol.h"

#define SGPushedNewModalCard @"SGPushedNewModalCard"

@class SGModalCard;

@interface SGModalCardHolder : UIViewController <SGSafeAreaInsetChangeBlocker>

@property (nonatomic,strong) NSMutableArray <SGModalCard *> *cards;
@property (nonatomic,strong) UIViewController *rootLevelViewController; //the controller at the root of the stack

- (void)pushRootLevelViewCard:(UIViewController *)forController
                      thenDo:(void(^)(void))block;
- (void)animateOutBackgroundThenDo:(void (^)(void))completion;
- (void)animateInBackgroundThenDo:(void (^)(void))completion;
- (void)popController:(UIViewController *)controller;

- (void)pushViewCard:(UIViewController *)forController
         modalOrigin:(UIView *)modalOrigin
              thenDo:(void(^)(void))block;

- (void)popViewCard:(UIViewController *)forController thenDo:(void(^)(void))block;
- (void)popViewCardThenDo:(void(^)(void))block;

- (void)updateCardBoundsForOrientation:(UIInterfaceOrientation)orientation;

// Set this before and after a child controller preforms a transition
// animation to prevent rotation while the animation is in progress
- (void)setAnimationInProgress:(BOOL)animationInProgress;

- (SGModalCard *)cardForController:(UIViewController *)controller;

- (BOOL)viewControllerIsOnTop:(UIViewController *)controller;

@property (nonatomic) BOOL ignoreSafeAreaInsetChanges;
@property (nonatomic, readonly) BOOL isPresenting;

@end
