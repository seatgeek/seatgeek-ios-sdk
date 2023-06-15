//
//  SGLogging.h
//  SeatGeek
//
//  Created by James Van-As on 4/04/14.
//  Copyright (c) 2014 SeatGeek. All rights reserved.
//

@import Foundation;

typedef NS_OPTIONS(NSInteger, SGLoggingTypes) {
    SGLoggingTypeNone      = 1 << 0,
    SGLoggingTypeGeneric   = 1 << 1,
    SGLoggingTypeAnalytics = 1 << 2,
    SGLoggingTypeAPI       = 1 << 3
};


@protocol SGLoggingTracker
- (void)sgLoggingCrashlyticsLogWithFormat:(nonnull NSString *)format, ... NS_FORMAT_FUNCTION(1,2);
@end

// Debug Logging. SGLog to log, SGDebugLog to log only in Debug builds.
#define SGLog(s, ...) NSLog(@"%@",[NSString stringWithFormat:(s), ##__VA_ARGS__])

// Logging to crashlytics
#define SGLoggingCrashlyticsLog(__FORMAT__, ...) [[SGLogging loggingTracker] sgLoggingCrashlyticsLogWithFormat:@"%s line %d $ " __FORMAT__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__];


#if !defined(DEBUG)

// Release build only
    #define SGDebugLog(...) do {} while (0)
    #define SGDebugTypedLog(type, ...) do {} while (0)
    #define SGDebugAssert(condition, desc, ...) \
        if (!(condition)) { \
            SGLoggingCrashlyticsLog(@"%@",[NSString stringWithFormat:(desc), ##__VA_ARGS__]); \
        }
#else

    // Debug build only logging
    bool AmIBeingDebugged(void);

    #define SGDebugLog(...) \
        if ([SGLogging shouldLog:SGLoggingTypeGeneric]) { SGLog(__VA_ARGS__); }

    #define SGDebugTypedLog(type, ...) \
        if ([SGLogging shouldLog:type]) { SGLog(__VA_ARGS__); }

    #define SGDebugAssert(condition, desc, ...) \
    if (!(condition)) { \
        NSLog(@"%@",[NSString stringWithFormat:(desc), ##__VA_ARGS__]); \
        if (AmIBeingDebugged()) \
            kill (getpid(), SIGSTOP); \
        else { \
            NSLog(@"%s, %d: could not break into debugger.", __FILE__, __LINE__); \
            SGLoggingCrashlyticsLog(@"%@",[NSString stringWithFormat:(desc), ##__VA_ARGS__]); \
        } \
    }

#endif

@interface SGLogging : NSObject

+ (SGLoggingTypes)loggingMask;
+ (void)setLoggingMask:(SGLoggingTypes)types;
+ (BOOL)shouldLog:(SGLoggingTypes)types;

@property (class, nonatomic, weak) id<SGLoggingTracker> _Nullable loggingTracker;

@end
