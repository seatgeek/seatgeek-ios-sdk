//
//  UIView+SizeClasses.h
//  SeatGeek
//
//  Created by Hunter Mask on 7/11/19.
//  Copyright © 2019 SeatGeek. All rights reserved.
//

@import UIKit;

@interface UIView (SizeClasses)

@property (nonatomic, readonly, assign) BOOL isInterfaceShortHeight;
@property (nonatomic, readonly, assign) BOOL isInterfaceTallHeight;
@property (nonatomic, readonly, assign) BOOL isInterfaceLongHeight;
@property (nonatomic, readonly, assign) BOOL isInterfaceExtendedHeight;
@property (nonatomic, readonly, assign) BOOL isInterfaceWide;
@property (nonatomic, readonly, assign) BOOL isInterfaceThin;
@property (nonatomic, readonly, assign) BOOL isPadInterface;

@end
