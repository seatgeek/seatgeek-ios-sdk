//
//  SGAPIError.h
//  SeatGeek
//
//  Created by James Van-As on 8/01/15.
//  Copyright (c) 2015 SeatGeek. All rights reserved.
//

@import Foundation;

@class SGHTTPRequest, SGQuery;

@interface SGAuth : NSObject

@property (nonatomic, strong) NSString *accessToken;
@property (nonatomic, strong) NSString *ID;
@property (nonatomic, strong) NSString *userName;

+ (SGAuth *)currentUser;
+ (void)authorizeRequest:(SGHTTPRequest *)request;
+ (void)authorizeRequest:(SGHTTPRequest *)request withToken:(NSString *)userAuthToken;
+ (void)authorizeQuery:(SGQuery *)query;
+ (NSDictionary *)authRequestDict;

@end
