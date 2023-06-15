//
//  SGAnimatedMessageBox.h
//  SeatGeek
//
//  Created by James Van-As on 21/03/14.
//  Copyright (c) 2014 SeatGeek. All rights reserved.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import "MGBox.h"
#endif

#import "SGAnimatedIconList.h"

@class SGAnimatedMessageBoxIcon, SGActionButton;

typedef NS_ENUM(NSInteger, SGAnimatedMessageBoxStyle) {
    SGAnimatedMessageBoxStyleSmall,
    SGAnimatedMessageBoxStyleMedium,    // default
    SGAnimatedMessageBoxStyleLarge
};

NS_SWIFT_NAME(AnimatedMessageBox)
@interface SGAnimatedMessageBox : MGBox

@property (nonatomic, assign) SGAnimatedMessageBoxStyle style;

@property (nullable, nonatomic, copy) NSString *label1Text;
@property (nullable, nonatomic, copy) NSString *label2Text;
@property (nullable, nonatomic, copy) NSString *buttonText;
@property (nullable, nonatomic, copy) NSString *secondaryButtonText;

/** Specify one of the icon names defined above, or an image name,
  * or an image URL to display full-width at the top of the message box
  * (note that this image is assumed to have a 4:3 aspect ratio)
 */
@property (nullable, nonatomic, copy) NSString *iconName;
@property (nullable, nonatomic, copy) NSString *imageURL;
@property (nullable, nonatomic, readonly, strong) SGAnimatedMessageBoxIcon *iconView;

@property (nullable, nonatomic, strong) SGActionButton *button;
@property (nullable, nonatomic, strong) SGActionButton *secondaryButton;
@property (nonatomic, assign) CGFloat buttonGap;
@property (nonatomic, assign) CGFloat underIconGap;
@property (nonatomic, assign) CGFloat underLabel1Gap;

- (void)setButtonText:(nullable NSString *)buttonText withIcon:(nullable NSString *)iconName;
- (void)setSecondaryButtonText:(nullable NSString *)buttonText withIcon:(nullable NSString *)iconName;

@end
