//
//  Created by matt on 31/08/15.
//

#import "SGModalController.h"
#import "SGModalCard.h"

@class MGBox;

/**
 * Slides whatever is in containerView up from the bottom, screening the UI
 * behind in typical modal presentation style. You can use this class directly
 * without subclassing if you like, just add what you like to containerView
 * and set its height.
 */
@interface SGBottomModalController : SGModalController <SGModalCardCustomAnimation>

@property (nonatomic, strong) UIView *outerContainer;
@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) MGBox *containerView;

/** Defaults to YES */
@property (nonatomic) BOOL allowTapBehindToDismiss;

/**
 * Set to YES if you are going to use auto layout constraints in
 * the containerView to drive its height automatically. This property needs to
 * be set before the view is loaded, so set it right away after
 * object construction.
 */
@property (nonatomic) BOOL useAutoLayout;

- (CGFloat)cardWidth;
- (CGFloat)cardWidthForContainerWidth:(CGFloat)containerWidth;
- (CGFloat)cardXPos;

@end
