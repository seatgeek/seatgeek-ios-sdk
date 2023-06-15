//
//  SGScreenshotsViewer.h
//  SeatGeek
//
//  Created by Steven Lehrburger on 9/19/17.
//  Copyright © 2017 SeatGeek. All rights reserved.
//

@import UIKit;

@class SGTicketGroup;

@interface SGScreenshotsViewer : UIViewController <UIPageViewControllerDataSource, UIPageViewControllerDelegate>

+ (instancetype)viewerForTicketGroup:(SGTicketGroup *)group;

/**
 * Set this property start at a specific screenshot when the view controller loads.
 */
@property (nonatomic) NSInteger initialPage;

@end
