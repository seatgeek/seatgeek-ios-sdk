//
//  SGPublicSaleMarketCodesController.h
//  SeatGeek
//
//  Created by James Van-As on 15/03/18.
//  Copyright © 2018 SeatGeek. All rights reserved.
//

#import "SGNavigatorChildController.h"

@class SGPublicListing;

@interface SGPublicSaleMarketCodesController : SGNavigatorChildController

+ (instancetype)controllerForSale:(SGPublicListing *)sale;

@end
