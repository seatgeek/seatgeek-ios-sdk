//
//  Created by matt on 1/12/14.
//

#import "SGNavigatorChildController.h"

@class SGCheckoutPurchase;

NS_ASSUME_NONNULL_BEGIN
@interface SGCheckoutBaseScreen : SGNavigatorChildController

@property (nonatomic, strong) SGCheckoutPurchase *purchase;

@end
NS_ASSUME_NONNULL_END
