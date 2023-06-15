//
//  SGPAccessCode.h
//  Pods
//
//  Created by Ed Paulosky on 4/13/17.
//
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

@class SGPEvent;

@interface SGAccessCode : SGPItem

@property (nonatomic, copy) NSString *code;
@property (nonatomic, strong) SGPEvent *event;
@property (nonatomic, assign, readonly) BOOL isValid;
@property (nonatomic, copy) NSString *codeDescription;

@end
