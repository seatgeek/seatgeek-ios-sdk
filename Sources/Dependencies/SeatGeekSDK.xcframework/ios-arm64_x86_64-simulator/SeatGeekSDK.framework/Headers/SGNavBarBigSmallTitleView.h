//
//  SGNavBarBigSmallTitleView.h
//  SeatGeek
//
//  Created by James Van-As on 7/12/17.
//  Copyright © 2017 SeatGeek. All rights reserved.
//

@import UIKit;

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import "MGBlockWrapper.h"
#endif

@class SGNavigationBar;

@interface SGNavBarBigSmallTitleView : UIView

- (id _Nonnull )initWithNavigationBar:(SGNavigationBar *_Nonnull)navigationBar;

- (void)setTitle:(nonnull NSString *)title subtitle:(nullable NSString *)subtitle;

@property (nonatomic, copy) _Nullable MGBlock onTap;

@end
