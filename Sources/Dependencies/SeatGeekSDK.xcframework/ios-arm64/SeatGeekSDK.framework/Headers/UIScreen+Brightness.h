//
//  UIScreen+Brightness.h
//  SeatGeekSDK
//
//  Created by Ed Paulosky on 11/2/17.
//  Copyright © 2017 SeatGeek. All rights reserved.
//

@import UIKit;

@interface UIScreen (Brightness)

// Convienece, will run on UIScreen.mainScreen instance
+ (void)brightenScreen;
+ (void)restoreScreenBrightness;

- (void)brightenScreen;
- (void)restoreScreenBrightness;

@end
