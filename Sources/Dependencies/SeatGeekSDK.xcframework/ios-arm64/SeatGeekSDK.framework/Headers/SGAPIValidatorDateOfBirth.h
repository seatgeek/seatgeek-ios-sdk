//
//  SGAPIValidatorDateOfBirth.h
//  Pods
//
//  Created by James Van-As on 22/10/15.
//
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGAPIValidator.h>
#else
#import <SeatGeekSDK/SGAPIValidator.h>
#endif

@interface SGAPIValidatorDateOfBirth : SGAPIValidator

@end
