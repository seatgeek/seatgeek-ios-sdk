//
//  SGPDFViewer.h
//  SeatGeek
//
//  Created by James Van-As on 7/05/15.
//  Copyright (c) 2015 SeatGeek. All rights reserved.
//

@import UIKit;

@import PDFKit;

@class SGLoadingSpinner, SGTicketGroup;

NS_SWIFT_NAME(PDFViewer)
@interface SGPDFViewer : UIViewController <UIWebViewDelegate, UIScrollViewDelegate>

+ (instancetype _Nonnull)viewerForTicketGroup:(SGTicketGroup * _Nonnull )group;

@property (nonatomic, strong, nonnull) SGTicketGroup *ticketGroup;
@property (nonatomic, strong, nonnull) PDFView *pdfView;
@property (nonatomic, strong, nonnull) SGLoadingSpinner *loadingSpinner;
@property (nonatomic, strong, nonnull) UIView *footer;
@property (nonatomic, strong, nonnull) UIButton *closeButton;
@property (nonatomic, strong, nonnull) UIButton *printButton;
@property (nonatomic, assign) BOOL printAfterOpen;
/// If YES, this property will force the screen to brighten.  If NO, the brightness is determined by the event's start time
@property (nonatomic, assign) BOOL brightenScreenOnOpen;

@end
