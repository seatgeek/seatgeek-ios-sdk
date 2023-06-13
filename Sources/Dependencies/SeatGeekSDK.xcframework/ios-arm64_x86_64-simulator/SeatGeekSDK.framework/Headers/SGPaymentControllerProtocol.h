//
//  SGPaymentControllerProtocol.h
//  SeatGeek
//
//  Created by James Van-As on 13/11/14.
//  Copyright (c) 2014 SeatGeek. All rights reserved.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
@import SeatGeekCore;
#else
#import <SeatGeekSDK/SGAPIError.h>
#import <SeatGeekSDK/MGBlockWrapper.h>
#endif

@class SGCheckoutPurchase;

@protocol SGPaymentControllerProtocol <NSObject>

@property (nonatomic, strong) SGCheckoutPurchase *purchase;
@property (nonatomic, assign) BOOL saveChangesOnBack;
@property (nonatomic, assign) BOOL hasChanged;

- (void)undoChanges;
- (void)saveChangesThenDo:(MGBlock)success fail:(SGAPIFailBlock)fail;

- (CGFloat)contentHeight;

@end
