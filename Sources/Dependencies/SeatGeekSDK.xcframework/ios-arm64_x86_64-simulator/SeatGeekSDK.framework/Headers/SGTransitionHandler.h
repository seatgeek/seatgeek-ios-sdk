//
//  SGTransitionHandler.h
//  SeatGeek
//
//  Created by James Van-As on 25/10/13.
//  Copyright (c) 2013 SeatGeek. All rights reserved.
//

@import UIKit;

@class SGNavigationController;

@interface SGTransitionHandler : UIPercentDrivenInteractiveTransition <UINavigationControllerDelegate,
                                                                       UIGestureRecognizerDelegate,
                                                                       UIViewControllerTransitioningDelegate>


- (id)initWithNavigationController:(SGNavigationController *)controller;

@end
