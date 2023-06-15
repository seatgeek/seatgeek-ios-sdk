//
//  SGCheckoutTextField.h
//  SeatGeek
//
//  Created by James Van-As on 9/06/14.
//  Copyright (c) 2014 SeatGeek. All rights reserved.
//

#import "SGFloatTextField.h"

@interface SGCheckoutTextField : SGFloatTextField

@property (nonatomic, weak) id observedObject;
@property (nonatomic, copy) NSString *observedKey;
@property (nonatomic, copy) NSString *errorParameter; //is same as observedKey unless you change this after
@property (nonatomic, copy) NSArray <NSString *> *errorParameters; //is same as observedKey unless you change this after
@property (nonatomic, assign) BOOL hasChanged;
@property (nonatomic, assign) BOOL doCursorFixing;
@property (nonatomic, assign) BOOL forceCapitalization;
/// Defaults to YES
@property (nonatomic, assign) BOOL underlineWhenFocused;
// Defaults to NO
@property (nonatomic, assign) BOOL persistUnderlineColor;
@property (nonatomic, strong) UIView *underlineView;
@property (nonatomic, strong) UIColor *underlineOverrideColor;

@property (nonatomic, assign) BOOL showsCursor;

// convenience that this edit field has passed validation
// eg.  You might want to disallow moving to the next screen until all visible fields have been validated
- (void)showErrorMessage:(NSString *)message;   //defaults to animated = YES
- (void)showErrorMessage:(NSString *)message animated:(BOOL)animated;
- (void)showErrorMessageOnTextChange:(NSString *)message; //show this error message on next "text changed" event
- (BOOL)hasErrorMessage;

- (void)showRightHelperTextOnTextChange:(NSString *)text; //show this message on next "text changed" event
- (void)toggleUnderlineView:(BOOL)hidden;

- (void)showLoadingSpinner;
- (void)hideLoadingSpinner;

@end
