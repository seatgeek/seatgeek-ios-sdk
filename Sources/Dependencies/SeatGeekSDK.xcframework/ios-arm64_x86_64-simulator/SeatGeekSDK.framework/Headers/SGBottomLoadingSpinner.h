//
//  Created by matt on 22/02/14.
//

@import UIKit;

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import "MGBlockWrapper.h"
#endif

#define SGBottomLoadingSpinnerFinishedShowing @"SGBottomLoadingSpinnerFinishedShowing"
#define SGBottomLoadingSpinnerFinishedHiding @"SGBottomLoadingSpinnerFinishedHiding"

NS_SWIFT_NAME(BottomLoadingSpinner)
@interface SGBottomLoadingSpinner : UIView

+ (instancetype)spinner;

//Delay between hiding and showing the spinner. Defaults to 0.2
- (void)setHideShowDelay:(NSTimeInterval)hideShowDelay;
@property (nonatomic, assign) NSTimeInterval showDelay;
@property (nonatomic, assign) NSTimeInterval hideDelay;

- (void)show;
- (void)hide;
- (void)hide:(MGBlock)then;

@end
