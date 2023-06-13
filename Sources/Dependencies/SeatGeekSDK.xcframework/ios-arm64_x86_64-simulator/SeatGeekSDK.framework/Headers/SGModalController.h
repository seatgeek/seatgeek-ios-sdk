//
//  SGModalController.h
//  SeatGeek
//
//  Created by Matt Greenfield on 4/03/13.
//  Copyright (c) 2013 SeatGeek. All rights reserved.
//

#import "SGViewController.h"
#import "SGModalCard.h"

extern NSString *kResetModalPhysicsNotification;

@interface SGModalController : SGViewController <UIGestureRecognizerDelegate, SGModalCardCustomAnimation>

@property (nonatomic, copy) void(^onClose)(void);
@property (nonatomic, copy) void(^afterClose)(void);
@property (nonatomic, copy) void(^afterOpen)(void);  // called at the end of the open animation
//specify if you can tap anywhere on the background to close the modal
@property (nonatomic, assign) BOOL tapOffModalToClose;
//min number of pixels away from any on screen elements to register the close tap
@property (nonatomic, assign) float tapToCloseLeniency;

//add all of your popover contents to this contentView
@property (nonatomic,strong) UIView *contentView;
//views inside the content view that should have the "bounce" animation applied
@property (nonatomic, strong) NSMutableArray *animationAttachmentItems;
@property (nonatomic, strong) UIMotionEffectGroup *contentEffectsGroup;

@property (nonatomic, assign) BOOL disableMotionEffects;
@property (nonatomic,strong) UIButton *bgModalCloseButton;

//public methods
+ (instancetype)controller;
- (void)open;
- (void)openInController:(UIViewController *)controller fromView:(UIView *)fromView;
- (void)openInController:(UIViewController *)controller fromView:(UIView *)fromView onClose:(void(^)(void))onClose;
- (void)openInController:(UIViewController *)controller fromView:(UIView *)fromView afterClose:(void (^)(void))afterClose;
- (void)close;

- (void)layoutForOrientation:(UIInterfaceOrientation)orient visibleRect:(CGRect)visibleRect;

@end
