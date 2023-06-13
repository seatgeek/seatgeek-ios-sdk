//
//  SGPayoutMethodBankController.h
//  SeatGeek
//
//  Created by James Van-As on 21/10/15.
//  Copyright © 2015 SeatGeek. All rights reserved.
//

#import "SGNavigatorChildController.h"
#import "SGPublicListing.h"

@class SGPayoutMethod;

@interface SGPayoutMethodBankController : SGNavigatorChildController <UITextFieldDelegate>

@property (nonatomic, copy) MGBlock onTappedDone;

+ (instancetype)controllerWithPayoutMethod:(SGPayoutMethod *)payoutMethod listing:(SGPublicListing *)listing;

@end
