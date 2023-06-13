//
//  SGTransferCheckoutController.h
//  SeatGeek
//
//  Created by James Van-As on 27/10/15.
//  Copyright © 2015 SeatGeek. All rights reserved.
//

#import "SGNavigatorChildController.h"

#define SGOpenTransferHelpInController  @"SGOpenTransferHelpInController"

@class SGTransfer;

@interface SGTransferCheckoutController : SGNavigatorChildController

+ (instancetype)controllerWithTransfer:(SGTransfer *)transfer;

@property (nonatomic,assign) BOOL showLocalValidationErrors;

@end
