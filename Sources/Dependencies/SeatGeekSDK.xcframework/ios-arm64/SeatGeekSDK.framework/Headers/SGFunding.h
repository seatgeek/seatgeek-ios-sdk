//
//  SGFunding.h
//  Pods
//
//  Created by James Van-As on 19/10/15.
//
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGPItem.h>
#else
#import <SeatGeekSDK/SGPItem.h>
#endif

typedef NS_ENUM(NSInteger, SGFundingType) {
    SGFundingTypeBank,
    SGFundingTypeSROCredit,
    SGFundingTypeUnknown
};

typedef NS_ENUM(NSInteger, SGFundingBankType) {
    SGFundingBankTypeUS,
    SGFundingBankTypeCA,
    SGFundingBankTypeUnknown
};

@interface SGFunding : SGPItem

+ (instancetype)fundingItemForDict:(NSDictionary *)dict;

+ (SGFundingType)fundingTypeForString:(NSString *)typeString;
+ (NSString *)stringForFundingType:(SGFundingType)fundingType;
+ (SGFundingBankType)fundingBankTypeForString:(NSString *)typeString;

@property (nonatomic, assign) SGFundingType type;
@property (nonatomic, assign) SGFundingBankType country;
@property (nonatomic, copy) NSString *currencyCode;

- (NSString *)shortDisplayString;
- (NSString *)longDisplayString;
- (UIImage *)image;
- (UIImage *)smallImage;

- (NSDictionary *)payload;  // used for sending to the server

@end
