//
//  SGViewController.h
//  SeatGeek
//
//  Created by David McNerney on 4/29/16.
//  Copyright © 2016 SeatGeek. All rights reserved.
//

@import UIKit;

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import "MGBlockWrapper.h"
#endif

#import "SGSafeAreaInsetChangeBlockerProtocol.h"

@class SGTransitionHandler;

@interface SGViewController : UIViewController <SGSafeAreaInsetChangeBlocker>

@property (strong, nonatomic) SGTransitionHandler *transitionHandler;

@property (nonatomic) BOOL ignoreSafeAreaInsetChanges;

/// block to be called once on appear
@property (nonatomic, copy) MGBlock onAppear;

- (void)safeAreaInsetsChanged;  // called on safe area inset changes, backward compatible to pre ios 11

@end
