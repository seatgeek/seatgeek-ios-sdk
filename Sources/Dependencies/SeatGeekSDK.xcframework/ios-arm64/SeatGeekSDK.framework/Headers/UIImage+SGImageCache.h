//
//  UIImage+SGImageCache.h
//  SeatGeek
//
//  Created by Ed Paulosky on 8/6/18.
//  Copyright © 2018 SeatGeek. All rights reserved.
//

@import UIKit;

/// This category exists so we can import SGImageCache into swift files in the SDK target without needing to deal the crazy dependancy chain of PromiseKit

@interface UIImage (SGImageCache)

+ (BOOL)sgImageCacheHaveImageForURL:(NSString *)url;
+ (UIImage *)sgImageCacheImageForURL:(NSString *)url;

+ (void)sgImageCacheGetImageForURL:(NSString *)url then:(void (^)(UIImage *))thenBlock;

+ (void)sgImageCacheSlowGetImageForURL:(NSString *)url;

@end
