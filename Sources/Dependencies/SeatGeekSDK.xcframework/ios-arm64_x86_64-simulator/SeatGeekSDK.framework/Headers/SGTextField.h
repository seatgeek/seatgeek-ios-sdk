//
//  SGTextField.h
//  SeatGeek
//
//  Created by David McNerney on 8/31/15.
//  Copyright © 2015 SeatGeek. All rights reserved.
//

@import UIKit;

@interface SGTextField : UITextField

/**
 * Allows client code to customize positioning of the placeholder, for example
 * to vertically center it when using a small placeholder font size compared
 * to the main font used for the text field.
 */
@property (nonatomic, copy) CGRect (^placeholderRectForBoundsBlock)(CGRect bounds);

@end
