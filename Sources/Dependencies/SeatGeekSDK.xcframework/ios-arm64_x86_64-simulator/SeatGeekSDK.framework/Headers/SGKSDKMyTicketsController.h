//
//  SGKSDKMyTicketsController.h
//  SeatGeekSDK
//
//  Created by Ed Paulosky on 10/16/17.
//  Copyright © 2017 SeatGeek. All rights reserved.
//

@import UIKit;

/**
 A view controller that contains all of SeatGeek's ticket management features and corresponding views.
 If the user is logged out, it will show a view and button to prompt the user to log in. If the user is authenticated,
 it will show a list of the user's tickets and allow the user to progress through the various ticket features:
 - View event details
 - View the transaction history for the tickets
 - Transfer tickets to other users
 - Accept transfers from other users
 - List and delist tickets for sale
 - View the ticket and barcode to scan into an event
 - Add the ticket and barcode to Apple Wallet

 This view controller is very flexible and can be used like any other UIViewController instance.
 - Add as a child view controller
 - Add as a root view controller of a navigation controller
 - Push onto the view stack within a navigation controller
 - Add as a tab bar item's view controller
 - Present as a modal
 */

@interface SGKSDKMyTicketsController : UIViewController

@end
