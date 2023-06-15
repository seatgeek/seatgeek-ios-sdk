//
//  SGKSDKLoginButton.h
//  SeatGeekSDK
//
//  Created by Ed Paulosky on 10/11/17.
//  Copyright © 2017 SeatGeek. All rights reserved.
//

@import UIKit;

/// The Log In with SeatGeek button styles
typedef NS_ENUM(NSInteger, SGKSDKLoginButtonStyle) {
    /// A style with an actionPrimary background and textAltPrimary text
    SGKSDKLoginButtonStyleDark,
    /// A style with an actionAltPrimary background and textPrimary text
    SGKSDKLoginButtonStyleLight
};

@interface SGKSDKLoginButton : UIButton

/// The UIViewController from which to present the authentication flow from.
@property (nonatomic, weak, nullable) UIViewController *viewController;

/**
 * Returns a Log In with SeatGeek button. When tapped it will present the SeatGeek authentication flow.
 *
 * @param style The style used to draw the button.
 * @param viewController The UIViewController from which to present the authentication flow from.
 *
 * @return A Log In with SeatGeek button.
 */
+ (nonnull SGKSDKLoginButton *)buttonWithStyle:(SGKSDKLoginButtonStyle)style
                           inViewController:(nonnull UIViewController *)viewController;

@end
