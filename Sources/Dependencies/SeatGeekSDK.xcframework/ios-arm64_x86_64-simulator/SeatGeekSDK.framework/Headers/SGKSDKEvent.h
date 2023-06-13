//
//  SGKSDKEvent.h
//  SeatGeekSDK
//
//  Created by Ed Paulosky on 12/18/17.
//  Copyright © 2017 SeatGeek. All rights reserved.
//

@import Foundation;

@interface SGKSDKEvent : NSObject

/// The event title.
@property (nonatomic, readonly) NSString *title;

/**
 Either the same as <title> or a shortened event title if one is available.

 title      = "Milwaukee Brewers at New York Mets"
 shortTitle = "Brewers at Mets"
 */
@property (nonatomic, readonly) NSString *shortTitle;

/**
 * The event's UTC date and time. For example  an event advertised as starting at 6pm
 * in NYC will have an 11pm `utcDate` (EST == UTC - 5).
 */
@property (nonatomic, readonly) NSDate *utcDate;


@end
