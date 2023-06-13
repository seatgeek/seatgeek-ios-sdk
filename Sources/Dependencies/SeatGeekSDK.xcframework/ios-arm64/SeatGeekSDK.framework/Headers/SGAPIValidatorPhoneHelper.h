//
//  SGAPIValidatorPhoneHelper.h
//  Pods
//
//  Created by Brian Maci on 4/7/21.
//

#ifndef SGAPIValidatorPhoneHelper_h
#define SGAPIValidatorPhoneHelper_h

@class NBPhoneNumberUtil;

@interface SGAPIValidatorPhoneHelper : NSObject
+ (NSString *)digitsFrom:(NSString *)phone;
+ (BOOL)isInternational:(NSString *)phone;
+ (BOOL)beginsWithPlusSign:(NSString *)phone;
+ (BOOL)beginsWithOne:(NSString *)phone;
+ (NBPhoneNumberUtil *)phoneUtil;
@end

#endif /* SGAPIValidatorPhoneHelper_h */
