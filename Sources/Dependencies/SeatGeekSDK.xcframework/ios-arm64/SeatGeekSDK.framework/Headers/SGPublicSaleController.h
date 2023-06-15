//
//  SGPublicSaleController.h
//  SeatGeek
//
//  Created by James Van-As on 11/11/15.
//  Copyright © 2015 SeatGeek. All rights reserved.
//

@import UIKit;
#import "SGNavigatorChildController.h"

@class SGPublicListing, SGTicket;

@interface SGPublicSaleController : SGNavigatorChildController <UIScrollViewDelegate>

@property (nonatomic, strong) NSArray <SGTicket *>*ticketsToSell;

+ (instancetype)controllerForListing:(SGPublicListing *)listing;

@end
