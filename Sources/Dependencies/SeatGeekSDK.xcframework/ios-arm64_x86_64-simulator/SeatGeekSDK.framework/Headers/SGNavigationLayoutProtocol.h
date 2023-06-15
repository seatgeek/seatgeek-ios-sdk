//
//  SGNavigationLayoutProtocol.h
//  SeatGeek
//
//  Created by James Van-As on 6/12/13.
//  Copyright (c) 2013 SeatGeek. All rights reserved.
//

@import Foundation;

@protocol SGNavigationLayoutProtocol <NSObject>

@optional
/// whether the navigation bar should show or hide when this view controller is shown
- (BOOL)hideNavBarOnShow;
/// whether the navigation bar should animate hideNavBarOnShow. Defaults to YES
- (BOOL)animateHideNavBarOnShow;
/// whether the bottom bar should hide when this view controller is shown. Defaults to NO.
- (BOOL)hidesBottomBarWhenPushed;
/// whether the tool bar should hide when this view controller is shown. Defaults to YES.
- (BOOL)hideToolBarOnShow;
/// whether the this view controller uses a tall Nav Bar. Defaults to NO.
- (BOOL)usesTallNavBar;

@end
