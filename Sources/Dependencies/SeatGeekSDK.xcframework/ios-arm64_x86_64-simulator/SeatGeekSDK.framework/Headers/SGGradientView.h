//
//  SGGradientView.h
//  SeatGeek
//
//  Created by James Van-As on 15/07/13.
//  Copyright (c) 2013 SeatGeek. All rights reserved.
//

@import UIKit;

@interface SGGradientView : UIView

@property (weak) SGGradientView *gradientLayer; //for backwards compatibility convenience
/// gradient colours are animateable if there are three of them
@property (strong, nonatomic) NSArray <UIColor *> *colors; // UIColors
/// gradient locations are animateable if there are three of them
@property (strong, nonatomic) NSArray <NSNumber *> *locations;
@property (nonatomic,assign, nonatomic) BOOL horizontal;
@property (nonatomic,assign, nonatomic) CGPoint startPoint;
@property (nonatomic,assign, nonatomic) CGPoint endPoint;
@property (nonatomic,assign, nonatomic) BOOL highQuality;

@end
