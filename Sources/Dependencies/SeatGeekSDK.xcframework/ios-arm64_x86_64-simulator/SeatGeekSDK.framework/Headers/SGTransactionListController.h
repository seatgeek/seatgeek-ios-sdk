//
//  Created by matt on 10/07/15.
//

#import "SGNavigatorChildController.h"

// This event is triggered on the class, not the controller object, so that
// listeners don't need access to the instance.
//
// At some point, maybe we could move our lists of transfers and tickets out of
// the UI layer to some manager or other class. That object would then host this
// transfers refreshed event. For now, this view controller is the keeper of
// the transfers.
#define SGTransactionListRefreshed @"SGTransactionListRefreshed"

@interface SGTransactionListController : SGNavigatorChildController

@end
