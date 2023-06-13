//
//  CLPlacemark+SeatGeek.h
//  SeatGeek
//
//  Created by James Van-As on 5/06/13.
//  Copyright (c) 2013 SeatGeek. All rights reserved.
//

@import CoreLocation;

@interface CLPlacemark (SeatGeek)

- (NSString *)abbreviatedState;
+ (BOOL)isUSState:(NSString *)state;

@end
