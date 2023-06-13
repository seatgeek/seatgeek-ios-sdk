//
//  SGModalCard.h
//  SeatGeek
//
//  Created by James Van-As on 13/01/14.
//  Copyright (c) 2014 SeatGeek. All rights reserved.
//
@import UIKit;

@class SGModalCard, SGTransitionHandler;

typedef void(^SGCustomModalAnimationCompleteBlock)(void);
typedef void(^SGCustomModalAnimationBlock)(SGModalCard *modalCard,
                                           SGCustomModalAnimationCompleteBlock complete);

@protocol SGModalCardCustomAnimation <NSObject>
@property (strong, nonatomic) SGTransitionHandler *transitionHandler;
@optional
- (SGCustomModalAnimationBlock)customZoomInAnimation;
- (SGCustomModalAnimationBlock)customZoomOutAnimation;
- (SGCustomModalAnimationBlock)customParentFallAnimation;
- (SGCustomModalAnimationBlock)customParentStandUpAnimation;
- (BOOL)usePerspectiveView; //defaults to YES
@end

@interface SGModalCard : UIView

@property (nonatomic,weak) UIViewController *viewController;
@property (nonatomic,strong) UIView *contentView;   //usually the view controller's view
@property (nonatomic,assign) BOOL lyingFlat;
@property (nonatomic,assign) BOOL topLevel;
@property (nonatomic, assign) BOOL allowCloseOnAppOpenFromURL;
@property (nonatomic,weak)  UIView *modalOrigin;
@property (nonatomic,assign) CGPoint cachedModalOriginPos; //backup position in case modalOrigin is gone later

- (id)initWithViewController:(UIViewController *)viewController
                       frame:(CGRect)frame;

- (void)animateFallThenDo:(void(^)(void))block;
- (void)animateStandUpThenDo:(void(^)(void))block;
- (void)animateZoomInThenDo:(void(^)(void))block;
- (void)animateZoomOutThenDo:(void(^)(void))block;

- (void)updateTransform;
- (BOOL)usePerspectiveView;
/// used by the modal card holder
@property (nonatomic,strong) NSMutableArray *associatedManualViews;

@end
