//
//  SGOtherUserSearchResult.h
//  SeatGeek
//
//  Created by David McNerney on 7/31/15.
//  Copyright (c) 2015 SeatGeek. All rights reserved.
//

@import Foundation;

@class SGTransferPerson;

/**
 * SGOtherUserSearchResult objects represent other SeatGeek users that were searched
 * for by the this user, for example because the user wants to transfer their tickets
 * to someone else.
 *
 * These search results can come from our server, or from the device (from the user’s address
 * book, or a user entered phone/email string. If they come from the device,
 * -transferPerson still returns a SGTransferPerson object, but it's not a server object,
 * won't have an ID, and will return false from -isSeatGeekUser.
 *
 * These search result objects map to the rows in SGOtherUserSearchController.
 */
@interface SGOtherUserSearchResult : NSObject

#pragma mark - Initializers

+ (instancetype)resultWithServerSearchResultDict:(NSDictionary *)dict;                                            // may return nil
+ (instancetype)resultWithPhone:(NSString *)phone firstName:(NSString *)firstName lastName:(NSString *)lastName;  // names optional
+ (instancetype)resultWithEmail:(NSString *)email firstName:(NSString *)firstName lastName:(NSString *)lastName;  // names optional

#pragma mark - Properties

@property (readonly) SGTransferPerson *transferPerson;

@end
