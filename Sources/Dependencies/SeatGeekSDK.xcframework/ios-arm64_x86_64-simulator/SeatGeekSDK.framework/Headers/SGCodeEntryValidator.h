//
//  SGCodeEntryValidator.h
//  Pods
//
//  Created by Hunter Mask on 11/20/18.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGAccessCode.h>
#import <SeatGeekCore/SGPromoCode.h>
#import <SeatGeekCore/SGCodeValidationResponse.h>
#else
#import <SeatGeekSDK/SGAccessCode.h>
#import <SeatGeekSDK/SGPromoCode.h>
#import <SeatGeekSDK/SGCodeValidationResponse.h>
#endif

NS_SWIFT_NAME(CodeEntryValidator)
@interface SGCodeEntryValidator : NSObject

+ (void)validateCode:(nonnull NSString *)code
         withEventID:(nullable NSString *)eventID
          marketName:(nullable NSString *)marketName
          completion:(void (^ _Nonnull)(SGCodeValidationResponse * _Nonnull response))completion;

@end
