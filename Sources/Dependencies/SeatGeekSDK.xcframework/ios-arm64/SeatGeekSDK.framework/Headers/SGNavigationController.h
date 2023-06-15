//
//  Created by matt on 29/07/13.
//
@import UIKit;

#if __has_include(<SeatGeekSDK/SGNavigatorProtocol.h>)
#import <SeatGeekSDK/SGNavigatorProtocol.h>
#else
#import "SGNavigatorProtocol.h"
#endif

#import "SGNavigationBar.h"
#import "SGSafeAreaInsetChangeBlockerProtocol.h"

#define SGDidShowViewController @"SGDidShowViewController" // context is the view controller in question

@interface SGNavigationController : UINavigationController <SGNavigatorProtocol, SGSafeAreaInsetChangeBlocker>

+ (instancetype)navWithRoot:(UIViewController *)root title:(NSString *)title
      image:(UIImage *)image selectedImage:(UIImage *)selectedImage;

+ (instancetype)navWithRoot:(UIViewController *)root;

- (NSArray *)popToViewControllerOfClass:(Class)class animated:(BOOL)animated;
- (UIViewController *)popViewControllerAnimatedFromDrag:(BOOL)animated;

#pragma mark - Navigation Bar
@property (strong, nonatomic) SGNavigationBar *sgNavigationBar;

@property (nonatomic, assign) BOOL sgNavigationBarHidden;
- (void)setSGNavigationBarHidden:(BOOL)hidden animated:(BOOL)animated;
- (void)setSGNavigationBarHidden:(BOOL)hidden animated:(BOOL)animated edge:(UIRectEdge)edge;

- (void)updateSafeAreaInsets;

@property (nonatomic, assign) BOOL sgNavigationBarTall;
- (void)setSGNavigationBarTall:(BOOL)tall animated:(BOOL)animated;
- (void)setSGNavigationBarTallProgress:(CGFloat)progress;
/// called when finished transitioning between tall / normal heights.  Returns the distance it moves to not end in an inbetween state
- (void)endChangingNavigationBarHeight:(void (^)(CGFloat heightChange))onHeightChanging then:(MGBlock)then;

@property (nonatomic) BOOL ignoreSafeAreaInsetChanges;
@property (readonly, assign) UIEdgeInsets sgSafeAreaInsets;
@property (nonatomic, copy) MGBlock onClose;
@property (nonatomic, copy) MGBlock afterClose;

@end
