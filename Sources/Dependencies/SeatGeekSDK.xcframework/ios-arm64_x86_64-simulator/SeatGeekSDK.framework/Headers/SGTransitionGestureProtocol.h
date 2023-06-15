//
//  SGTransitionGestureProtocol.h
//  SeatGeek
//
//  Created by James Van-As on 14/07/16.
//  Copyright © 2016 SeatGeek. All rights reserved.
//


@protocol SGTransitionGestureProtocol <NSObject>

/// return YES if you want this view controller to allow swipe to go back gestures
- (BOOL)allowSwipeToGoBack;

@end
