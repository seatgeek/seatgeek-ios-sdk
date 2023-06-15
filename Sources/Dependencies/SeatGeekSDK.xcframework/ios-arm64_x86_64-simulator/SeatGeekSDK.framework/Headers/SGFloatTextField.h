//
//  SGFloatTextField.h
//  SeatGeek
//
//  Created by James Van-As on 9/06/14.
//  Copyright (c) 2014 SeatGeek. All rights reserved.
//

@import UIKit;
#import "SGTextField.h"

@class SGTypestyle;

@interface SGFloatTextField : SGTextField

// extra label positioning offsets (additional)
@property (nonatomic,assign) CGFloat topLabelOffset;
@property (nonatomic,assign) CGPoint leftFloatLabelOffset;
@property (nonatomic,assign) CGPoint rightFloatLabelOffset;
@property (nonatomic,strong) UIColor *leftFloatTextColor;
@property (nonatomic,strong) UIColor *rightFloatTextColor;
@property (nonatomic,strong) UIColor *rightHelperTextColor;
@property (nonatomic,strong) UIColor *placeholderTextColor;
@property (nonatomic,assign) UIEdgeInsets textInsets;

// A height value to expose across the app
+ (CGFloat)inputFieldHeight;

// Conveniences to expose typestyle usage
- (CGFloat)inputLineHeight;
- (SGTypestyle *)textfieldTypestyle;

// A convenience to set a 24x24 icon as LeftView
- (void)setLeftIcon:(UIImage *)image;

- (void)setLeftFloatText:(NSString *)text;  //this will default to the placeholder text
- (void)setRightFloatText:(NSString *)text;
- (void)setRightHelperText:(NSString *)text;

- (NSString *)leftFloatText;
- (NSString *)rightFloatText;
- (NSString *)rightHelperText;

- (void)setRightFloatVisible:(BOOL)visible animated:(BOOL)animated;
- (void)setRightHelperVisible:(BOOL)visible;

- (void)setText:(NSString *)text animateChange:(BOOL)animate;

// text editing notifications.  You might want to override in a subclass and then call super
- (void)textDidChange:(NSNotification *)notification;
- (void)didStartEditingText:(NSNotification *)notification;
- (void)didFinishEditingText:(NSNotification *)notification;

@end
