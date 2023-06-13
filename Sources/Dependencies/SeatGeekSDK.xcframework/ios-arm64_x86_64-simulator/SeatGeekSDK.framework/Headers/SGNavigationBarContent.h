//
//  SGNavigationBarContent.h
//  SeatGeek
//
//  Created by James Van-As on 18/09/17.
//  Copyright © 2017 SeatGeek. All rights reserved.
//

@import UIKit;

@interface SGNavigationBarContent : UIView

@property (nonatomic) UINavigationItem *navigationItem;

@property (nonatomic, readonly) UIStackView *leftStackView;
@property (nonatomic, readonly) UIView *leftSpacerView;
@property (nonatomic, readonly) UIView *middleView;
@property (nonatomic, readonly) UIView *rightSpacerView;
@property (nonatomic, readonly) UIStackView *rightStackView;

@end
