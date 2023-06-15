//
//  SGBaseTransition.h
//  SeatGeek
//
//  Created by James Van-As on 25/10/13.
//  Copyright (c) 2013 SeatGeek. All rights reserved.
//

@import UIKit;

#define SGTransitonCancelled @"SGTransitonCancelled"

@class SGBaseTransition;

@protocol SGTransitionProtocol <NSObject>

- (SGBaseTransition *)transitionForOperation:(UINavigationControllerOperation)operation
                             otherController:(UIViewController *)otherController;

@optional
- (BOOL)noCustomTransitions;
/// if you want a custom nav bar background colour, return one from this method
- (UIColor *)customNavBarColor;

@end

@interface SGBaseTransition : UIPercentDrivenInteractiveTransition
                                            <UIViewControllerAnimatedTransitioning,
                                                UIViewControllerInteractiveTransitioning>

@property (weak) id<UIViewControllerContextTransitioning> transitionContext;
@property (assign) UINavigationControllerOperation operation;
@property (assign) CGRect leftRectStart, leftRectEnd, rightRectStart, rightRectEnd;

- (BOOL)isInteractive;  //default is yes.  return no if your animation can't be interactive

// if a custom gesture is interacting with this transition
@property (nonatomic, assign) BOOL interacting;

@property (nonatomic, assign) BOOL blockPans;

- (void)pan:(UIScreenEdgePanGestureRecognizer *)g;

// Always call updateNavBarContentForPercent at appropriate times in subclasses
- (void)updateNavBarContentForPercent:(float)percent;

//you sometimes might want to override these methods if you want other-than-default rect positions.
- (void)setupInitialConditionsFor:(id<UIViewControllerContextTransitioning>)transitionContext;
- (void)setRectsForPercent:(float)percent;

//which vc is on the left or right side of the screen
- (UIViewController *)leftVC;
- (UIViewController *)rightVC;
//which vc is on top of the other in the z direction
- (UIViewController *)topVC;
- (UIViewController *)bottomVC;

@end
