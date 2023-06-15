//
//  UIView+Hairlines.h
//  Pods
//
//  Created by James Van-As on 17/06/15.
//
//

@import UIKit;

@interface UIView (Hairlines)

#pragma mark Hairlines for use manually set frames or autoresizing masks

- (UIView *)addHairlineWithColor:(UIColor *)color width:(CGFloat)width edges:(UIRectEdge)edges;

- (UIView *)addHairlineWithColor:(UIColor *)color width:(CGFloat)width margin:(CGFloat)margin
      edges:(UIRectEdge)edges;

- (UIView *)addHairlineWithColor:(UIColor *)color width:(CGFloat)width margin:(CGFloat)margin
                       edges:(UIRectEdge)edges marginEdges:(UIRectEdge)marginEdges;

#pragma mark Hairlines for use with autolayout views

- (UIView *)addAutolayoutHairlineWithColor:(UIColor *)color
                                     width:(CGFloat)width
                                     edges:(UIRectEdge)edges
                                     NS_SWIFT_NAME(addAutolayoutHairline(withColor:width:edges:));

- (UIView *)addAutolayoutHairlineWithColor:(UIColor *)color
                                     width:(CGFloat)width
                                    margin:(CGFloat)margin
                                     edges:(UIRectEdge)edges
                                     NS_SWIFT_NAME(addAutolayoutHairline(withColor:width:margin:edges:));

- (UIView *)addAutolayoutHairlineWithColor:(UIColor *)color
                                     width:(CGFloat)width
                                    margin:(CGFloat)margin
                                 edges:(UIRectEdge)edges
                               marginEdges:(UIRectEdge)marginEdges
                                     NS_SWIFT_NAME(addAutolayoutHairline(withColor:width:margin:edges:marginEdges:));

@end
