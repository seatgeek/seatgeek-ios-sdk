//
//  Created by matt on 7/02/15.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGAPIValidator.h>
#else
#import <SeatGeekSDK/SGAPIValidator.h>
#endif

@interface SGAPIValidatorNotEmpty : SGAPIValidator

@end
