//
//  Created by matt on 30/07/15.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGItem.h>
#import <SeatGeekCore/SGAPIError.h>
#import <SeatGeekCore/MGBlockWrapper.h>
#else
#import <SeatGeekSDK/SGItem.h>
#import <SeatGeekSDK/SGAPIError.h>
#import <SeatGeekSDK/MGBlockWrapper.h>
#endif

@class SGFileCache;

@interface SGPItem : SGItem
@property (nonatomic, strong) NSString *ID;
@property (nonatomic, strong) NSMutableDictionary *previousValues;
@property (nonatomic, strong) NSDictionary *customValidators;

// undo management
- (BOOL)hasChanged;
- (void)undoChanges;
- (BOOL)willChangeField:(NSString *)field toValue:(id)value;

// saving updates
- (void)saveChanges;
- (void)saveChangesThenDo:(MGBlock)success onFail:(SGAPIFailBlock)fail;

// local validation
+ (NSDictionary *)validators;
- (NSArray *)validationErrors;
- (NSArray *)validationErrorsFor:(NSDictionary *)validators;
- (SGAPIError *)validationErrorForField:(NSString *)field;
+ (NSString *)categoryForValidationErrors;  // defaults to unknown

// custom local validation
// These methods expect a dictionary with the structure {fieldName: [SGAPIValidator subclass]}
- (NSArray *)validationErrorsForCustomValidators:(NSDictionary *)validators;
- (SGAPIError *)validationErrorForField:(NSString *)field withCustomValidators:(NSDictionary *)customValidators;

@end
