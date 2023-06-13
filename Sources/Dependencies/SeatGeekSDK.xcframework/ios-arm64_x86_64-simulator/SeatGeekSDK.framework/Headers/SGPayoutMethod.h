//
//  SGPayoutMethod.h
//  Pods
//
//  Created by James Van-As on 19/10/15.
//
//
#define SGPayoutMethodAddedSuccessfully @"SGPayoutMethodAddedSuccessfully"

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/MGBlockWrapper.h>
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/MGBlockWrapper.h>
#import <SeatGeekSDK/SGPItem.h>
#endif

typedef NS_ENUM(NSUInteger, SGTrackerUserPayoutEditType);
typedef NS_ENUM(NSUInteger, SGTrackerUserPayoutMethod);
typedef NS_ENUM(NSUInteger, SGTrackerUserPayoutUIOrigin);

typedef NS_CLOSED_ENUM(NSUInteger, SGPayoutMethodSellerType) {
    SGPayoutMethodSellerTypePersonal,
    SGPayoutMethodSellerTypeBusiness
};

@class SGPayoutMethodAddress, SGFunding, SGKPayoutBusinessAddress;
@class SGFundingBank, SGFundingSROCredit;

@interface SGPayoutMethod : SGPItem

@property (class, nonatomic, assign) BOOL requires1099DataCollection;
@property (class, nonatomic, copy) NSArray<NSString *>* bankSupportedCountries;

@property (nonatomic, strong) NSString *status;
@property (nonatomic, strong) NSString *firstName;
@property (nonatomic, strong) NSString *lastName;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSDate *dateOfBirth;
@property (nonatomic, strong) NSString *localizedDateOfBirthString;
@property (nonatomic, strong) NSString *dateOfBirthString;
@property (nonatomic, strong) NSString *ssn;
@property (nonatomic, strong) SGKPayoutBusinessAddress *businessAddress;

@property (nonatomic, assign) BOOL acceptedStripeTermsOfService;
@property (nonatomic, assign) BOOL assertedNotUSTaxable;

@property (nonatomic, assign) SGPayoutMethodSellerType sellerType;

@property (nonatomic, strong) SGPayoutMethodAddress *address;
@property (nonatomic, strong) SGFunding *funding;   // api terminology here.  venom / bank account details
@property (nonatomic, strong) SGFunding *previousFunding;   // preivously selected funding, used for undo

@property (nonatomic, strong) SGFundingBank *bankFunding;   // for convenience
@property (nonatomic, strong) SGFundingSROCredit *sroCreditFunding;   // for convenience

@property (nonatomic, strong, readonly) NSString *spreedlyToken;

@property (nonatomic, strong) NSArray *errors;  // list of parameter errors
@property (nonatomic, assign) BOOL hasChanged;

@property (nonatomic) SGTrackerUserPayoutEditType trackerEditType;
@property (nonatomic) SGTrackerUserPayoutMethod trackerMethod;
@property (nonatomic) SGTrackerUserPayoutUIOrigin trackerUIOrigin;

@property (nonatomic, strong) NSString *displayName;
@property (nonatomic, strong) NSString *imageURL;
@property (nonatomic, strong) NSString *summary;

- (void)saveChangesThenDo:(MGBlock)success onFail:(SGAPIFailBlock)fail;
- (void)saveIdentityThenDo:(MGBlock)success onFail:(SGAPIFailBlock)fail;

- (BOOL)isEqualToPayoutMethod:(SGPayoutMethod *)other;

- (BOOL)hasRequiredPersonalInformation;

@end
