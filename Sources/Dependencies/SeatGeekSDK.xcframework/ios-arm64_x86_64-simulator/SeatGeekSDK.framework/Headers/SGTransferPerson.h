//
//  Created by matt on 17/07/15.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGItem.h>
#import <SeatGeekCore/SGPerson.h>
#else
#import <SeatGeekSDK/SGItem.h>
#import <SeatGeekSDK/SGPerson.h>
#endif

@interface SGTransferPerson : SGPerson

@property (nonatomic, copy) NSString *shortFullName;
@property (nonatomic, strong) NSDictionary *images;
@property (nonatomic, copy) NSString *iMessageUUID;
@property (nonatomic, copy) NSData *imageData;
@property (nonatomic, assign) BOOL isLocalContact;

- (NSString *)identifyingString;    // Display string that favours username over full name

- (BOOL)isSeatGeekUser;

@end
