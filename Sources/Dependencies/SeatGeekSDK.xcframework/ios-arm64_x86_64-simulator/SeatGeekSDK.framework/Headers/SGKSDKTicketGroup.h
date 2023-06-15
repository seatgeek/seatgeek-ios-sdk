//
//  SGKSDKTicketGroup.h
//  SeatGeekSDK
//
//  Created by Ed Paulosky on 12/18/17.
//  Copyright © 2017 SeatGeek. All rights reserved.
//

@import Foundation;

@class SGKSDKEvent;

@interface SGKSDKTicketGroup : NSObject

/// A unique identifier for the ticket group
@property (nonatomic, readonly) NSString *ID;

/// The section that all tickets in the ticket group are in
@property (nonatomic, readonly) NSString *section;

/// The row that all tickets in the ticket group are in
@property (nonatomic, readonly) NSString *row;

/// The event for this ticket group
@property (nonatomic, readonly) SGKSDKEvent *event;

@end
