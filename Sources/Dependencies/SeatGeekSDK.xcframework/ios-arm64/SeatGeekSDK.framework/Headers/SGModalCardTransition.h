//
//  SGModalCardTransition.h
//  SeatGeek
//
//  Created by James Van-As on 29/06/17.
//  Copyright © 2017 SeatGeek. All rights reserved.
//

#import "SGBaseTransition.h"

@class SGModalCardTransition;

@protocol SGModalCardTransitionCard <NSObject>

/// The card portion of the view controller to be transitioned / panned on screen
@property (nonatomic, readonly, nullable) UIView *panView;

/// The center position of the pan view when it's in it's "natural" (non transitioning) state
@property (nonatomic, readonly) CGPoint panViewNaturalCenter;

/// Just make this property available and SGModalCardTransition will do the rest
@property (nonatomic, strong, nullable) SGModalCardTransition *transition;

/// Set to true if the transition has been initiated by a pan gesture
@property (nonatomic, assign) BOOL interactiveTransition;

/// The scale that the view behind this card is allowed to transform to
@property (nonatomic, readonly) CGFloat behindTransformScale;

/// Set to true if the behindBGView color is clear. This ensures previous view controllers are still visible when presenting a new one
@property (nonatomic, assign) BOOL clearBehindBGViewColor;

/// Set to true if the new spring animations from the event screen should be used
@property (nonatomic, assign) BOOL useNewSpringAnimations;
@end

@interface SGModalCardTransition : SGBaseTransition <UIViewControllerInteractiveTransitioning>
@property (nonatomic, assign) CGPoint panStartPoint;
@property (nonatomic, assign) BOOL grabPanOffset;
- (void)panUpdated:(UIPanGestureRecognizer *_Nullable)pan;

/// exposed for subclasses
@property (nonatomic, weak, nullable) UIView *behindTintView;
@property (nonatomic, readonly, nullable) UIViewController <SGModalCardTransitionCard> *cardController;
@property (nonatomic, readonly, nullable) UIViewController *behindController;

- (void)animateBehindViewForPercent:(float)percent;
- (void)setRectsForPercent:(float)percent;
- (void)additionalAnimationsForPercent:(float)percent;
- (void)setConstraintsForPercent:(float)percent;
- (void)updateBottomCardShadowForPercent:(float)percent;
- (void)transitionWillStart;
- (void)cleanup:(BOOL)transitionCompleted;    // called at the end

/// animation variables

/// the scale of the transform applied to the behind view
@property (nonatomic, readonly) CGFloat minBehindViewScale;
@property (nonatomic, readonly) BOOL springBasedAnimations;
@property (nonatomic, readonly) CGFloat springDamping;
@property (nonatomic, readonly) UIViewAnimationOptions animationOptions;
@property (nonatomic, readonly) NSTimeInterval springBasedDuration;
@property (nonatomic, readonly) UIViewAnimationOptions springAnimationOptions;

@end
