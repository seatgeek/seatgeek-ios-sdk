//
//  SGAPICustomValidator.h
//  Pods
//
//  Created by Matt Baron on 6/27/18.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

@interface SGAPICustomValidator : SGPItem
@property (nonatomic, copy) NSString *errorMessage;
@property (nonatomic, copy) NSString *regexString;
@end
