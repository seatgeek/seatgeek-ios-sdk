//
//  SGLoadingSpinner.h
//  SeatGeek
//
//  Created by James Van-As on 30/08/13.
//  Copyright (c) 2013 SeatGeek. All rights reserved.
//
@import UIKit;
@class SGTypestyle;

NS_SWIFT_NAME(LoadingSpinner)

@interface SGLoadingSpinner : UIView

@property (nonatomic, copy) NSString * _Nullable labelText;
@property (nonatomic) SGTypestyle * _Nullable labelTypestyle;
@property (nonatomic, assign) CGFloat speedMultiplier;
/// If true, you need to call startSpinning and StopSpinning manually.  Defaults to false
@property (nonatomic, assign) BOOL manualStartStop;
@property (nonatomic, strong) UIImageView * _Nullable imageView;
@property (nonatomic, assign, readonly) BOOL isSpinning;

#pragma mark - New Style Spinners
NS_ASSUME_NONNULL_BEGIN

+ (instancetype)biggerSpinner;
+ (instancetype)bigSpinner;
+ (instancetype)smallSpinner;
+ (instancetype)smallerSpinner;

#pragma mark - Old Style Spinners
+ (instancetype)oldStyleSpinner;
+ (instancetype)tinySpinner;

NS_ASSUME_NONNULL_END

/// You only need to call startSpinning if manualStartStop is true
- (void)startSpinning;
/// You only need to call stopSpinning if manualStartStop is true
- (void)stopSpinning;

#pragma mark - Custom spinners
- (id _Nonnull)initWithImage:(UIImage *_Nullable)image;
- (id _Nonnull)initWithImage:(UIImage *_Nullable)image andColor:(UIColor *_Nonnull)color;

@end
