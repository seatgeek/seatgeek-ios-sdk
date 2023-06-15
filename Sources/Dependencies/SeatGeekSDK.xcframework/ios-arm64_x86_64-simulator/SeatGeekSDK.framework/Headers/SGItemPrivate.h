//
//  Created by matt on 31/08/14.
//

@import Foundation;

@protocol SGItemPrivate <NSObject>

- (NSString *)dataKey;
/// placeholder artwork
- (NSString *)placeHolderImageName;
- (NSString *)imageURLForSize:(CGSize)size;

@end
