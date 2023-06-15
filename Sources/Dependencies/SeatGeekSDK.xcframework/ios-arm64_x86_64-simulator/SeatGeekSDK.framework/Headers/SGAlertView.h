//
//  SGAlertView.h
//  SeatGeek
//
//  Created by James Van-As on 7/04/17.
//  Copyright © 2017 SeatGeek. All rights reserved.
//

@import Foundation;

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import "MGBlockWrapper.h"
#endif

@class SGAlertView, SGStyledModalController, SGActionButton;

@protocol SGAlertViewDelegate <NSObject>
// Called when a button is clicked. The view will be automatically dismissed after this call returns
- (void)alertView:(SGAlertView *_Nonnull)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;
@end

@interface SGAlertView : NSObject

- (instancetype _Nonnull)initWithTitle:(NSString *_Nullable)title
                               message:(NSString *_Nullable)errorMessage
                              delegate:(id<SGAlertViewDelegate>_Nullable)delegate
                     cancelButtonTitle:(NSString *_Nullable)cancelButtonTitle
                     otherButtonTitles:(NSArray <NSString *> *_Nullable)otherButtonTitles;

- (instancetype _Nonnull)initWithTitle:(NSString *_Nullable)title
            message:(NSString *_Nullable)message
       buttonTitles:(NSArray *_Nullable)buttonTitles
       actionBlocks:(NSArray<MGBlock> *_Nullable)actionBlocks;

- (instancetype _Nonnull)initWithTitle:(NSString *_Nullable)title
            message:(NSString *_Nullable)message
   closeButtonTitle:(NSString *_Nullable)buttonTitle;

- (instancetype _Nonnull)initWithTitle:(NSString *_Nullable)title
            message:(NSString *_Nullable)message;

- (instancetype _Nonnull)initWithTitle:(NSString *_Nullable)title
            message:(NSString *_Nullable)message
       buttonTitles:(NSArray *_Nullable)buttonTitles;

- (void)addButtonWithName:(NSString *_Nonnull)name action:(void(^_Nullable)(void))block;
- (void)addButtonWithName:(NSString *_Nonnull)name isCancel:(BOOL)isCancel action:(void(^_Nullable)(void))block;

- (void)show;

@property (nonatomic, strong, nullable) NSString *title;
@property (nonatomic, strong, nullable) NSString *message;
@property (nonatomic) NSInteger cancelButtonIndex;
@property (nonatomic, weak, nullable) id <SGAlertViewDelegate> delegate;
/// Forces the layout of the buttons to be vertical.
@property (nonatomic, assign) BOOL layoutButtonsVertically;

/// An array of alerts which are currently visible
+ (NSArray <SGAlertView *> *_Nonnull)activeAlerts;
/// The modal that is being displayed
- (SGStyledModalController *_Nullable)modal;
@property (nonatomic, strong) NSMutableArray <SGActionButton *> * _Nonnull actionButtons;

@end
