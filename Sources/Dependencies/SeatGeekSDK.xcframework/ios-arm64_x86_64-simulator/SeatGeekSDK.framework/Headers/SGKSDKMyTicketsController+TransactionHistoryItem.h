//
//  SGKSDKMyTicketsController+TransactionHistoryItem.h
//  SeatGeekSDK
//
//  Created by Ed Paulosky on 11/1/17.
//  Copyright © 2017 SeatGeek. All rights reserved.
//

#import "SGKSDKMyTicketsController.h"

/**
 This extension provides a bar button item that can be added to a navigation bar.
 When tapped the button will present the transaction history list of the user.
 */
@interface SGKSDKMyTicketsController (STransactionHistoryItem)

- (UIBarButtonItem *)transactionHistoryBarButtonItem;

@end
