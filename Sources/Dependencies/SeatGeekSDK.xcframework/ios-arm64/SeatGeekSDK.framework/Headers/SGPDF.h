//
//  Created by matt on 14/10/15.
//

#if !SEATGEEK_SDK && __has_include(<SeatGeekCore/SeatGeekCore.h>)
#import <SeatGeekCore/SGItem.h>
#else
#import <SeatGeekSDK/SGItem.h>
#endif

@interface SGPDF : SGItem

@property (nullable, nonatomic, strong, readonly) NSData *data;

- (nullable UIImage *)imageWithMaxSize:(CGSize)size;

- (BOOL)canShowOrDownloadPDFData;

@end
