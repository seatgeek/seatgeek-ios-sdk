//
//  SGModalNavigatorTransition.h
//  SeatGeek
//
//  Created by James Van-As on 21/06/18.
//  Copyright © 2018 SeatGeek. All rights reserved.
//

#import "SGBaseTransition.h"

@class SGModalNavigatorTransition;

@protocol SGModalNavigatorTransitionProtocol
    /// Just make this property available and SGModalNavigatorTransition will do the rest
    @property (nonatomic, strong, nullable) SGModalNavigatorTransition *transition;
    @property (nonatomic, readonly, nullable) UIView *navBarUnderlay;
@end

@interface SGModalNavigatorTransition : SGBaseTransition

@end
