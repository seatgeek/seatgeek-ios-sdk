//
//  SGAPIValidator.h
//  SeatGeek
//
//  Created by James Van-As on 9/06/14.
//  Copyright (c) 2014 SeatGeek. All rights reserved.
//

@import Foundation;

@interface SGAPIValidator : NSObject

// returns an error string, or nil for acceptable values
+ (NSString *)validationErrorFor:(NSString *)value;
+ (NSString *)validationErrorFor:(NSString *)value context:(id)context compact:(BOOL)compact;

@end
