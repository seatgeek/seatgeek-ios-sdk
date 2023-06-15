//
//  Created by matt on 22/12/14.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

@interface SGAddress : SGPItem <NSCopying>

@property (nonatomic, copy) NSString *firstName;
@property (nonatomic, copy) NSString *lastName;
/// combined comma separated address
@property (nonatomic, copy, readonly) NSString *combinedAddress;
@property (nonatomic, copy, readonly) NSString *combinedStreetAddress;
@property (nonatomic, copy) NSString *streetAddress1;
@property (nonatomic, copy) NSString *streetAddress2;
@property (nonatomic, copy) NSString *city;
@property (nonatomic, copy) NSString *state;
@property (nonatomic, copy) NSString *country;
@property (nonatomic, copy) NSString *zip;
@property (nonatomic, copy) NSString *phone;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, assign) BOOL isDefault;

- (BOOL)isEqualToAddress:(SGAddress *)other;

/// Currently returns a US formatted phone number on the account screen; international elsewhere
+ (NSString *)displayStringForPhoneNumber:(NSString *)phone supportsIntl:(BOOL)supportsIntl;

/// Currently returns an .e164 format phone number
+ (NSString *)normalizedPhoneNumber:(NSString *)phone supportsIntl:(BOOL)supportsIntl;

+ (BOOL)isPossiblePhoneNumber:(NSString *)phone;

/// Returns if two phone number strings are equivalent
+ (BOOL)phoneNumber:(NSString *)phone1 isEqualTo:(NSString *)phone2;

- (BOOL)addressFieldsAreEmpty;

@end
