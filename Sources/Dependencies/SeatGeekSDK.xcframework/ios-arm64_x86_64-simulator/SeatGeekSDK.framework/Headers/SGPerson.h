//
//  Created by matt on 30/07/15.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

@interface SGPerson : SGPItem

@property (nonatomic, copy) NSString *username;
@property (nonatomic, copy) NSString *fullName;
@property (nonatomic, copy) NSString *firstName;
@property (nonatomic, copy) NSString *lastName;
@property (nonatomic, copy) NSString *mobilePhone;
@property (nonatomic, copy) NSString *prettyMobilePhone;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, copy) NSString *profileImageUrl;

- (NSString *)displayName;
- (NSString *)shortDisplayName;
- (NSString *)initials;

@end
