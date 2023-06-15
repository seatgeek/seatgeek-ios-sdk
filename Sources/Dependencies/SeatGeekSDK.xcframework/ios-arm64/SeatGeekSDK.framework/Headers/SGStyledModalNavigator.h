//
//  SGStyledModalNavigator.h
//  SeatGeek
//
//  Created by James Van-As on 27/05/16.
//  Copyright © 2016 SeatGeek. All rights reserved.
//

#import "SGModalController.h"
#import "SGNavigatorChildController.h"
#import "SGModalCard.h"

@interface SGStyledModalNavigator : SGModalController <SGNavigatorProtocol, SGModalCardCustomAnimation>

+ (instancetype)navigatorWithInitialVC:(SGNavigatorChildController *)initialController;

@property (readonly, assign) UIEdgeInsets sgSafeAreaInsets;
@property (nonatomic, strong) NSArray <UIViewController *> *viewControllers;

// block that is called after a push transition is completed.
@property (nonatomic, copy) MGBlock afterPushTransition;

// manually override the status bar style (animates if it changes)
@property (nonatomic, assign) UIStatusBarStyle statusBarStyle;

- (void)setBackgroundColor:(UIColor *)color;

@end
