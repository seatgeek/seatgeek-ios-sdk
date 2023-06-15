//
//  SGNavBarLeftTitleView.h
//  SeatGeek
//
//  Created by Steven Lehrburger on 12/6/17.
//  Copyright © 2017 SeatGeek. All rights reserved.
//

@class SGNavigationBar;

@import UIKit;

NS_SWIFT_NAME(NavBarLeftTitleView)

@interface SGNavBarLeftTitleView : UIView

- (id _Nonnull )initWithNavigationBar:(SGNavigationBar *_Nonnull)navigationBar;

- (void)setTitle:(nonnull NSString *)title subtitle:(nullable NSString *)subtitle;

@end
