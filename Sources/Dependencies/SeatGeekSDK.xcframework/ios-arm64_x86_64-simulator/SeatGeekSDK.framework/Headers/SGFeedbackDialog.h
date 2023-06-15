//
//  Created by matt on 25/11/12.
//

@import MessageUI;
#import "SGAlertView.h"

@interface SGFeedbackDialog : UIView
      <MFMailComposeViewControllerDelegate>

@property (nonatomic, weak) UIViewController *controller;
@property (nonatomic, strong) NSString *emailSubject;
@property (nonatomic, strong) NSString *emailBody;
@property (nonatomic, strong) NSString *emailFooter;

+ (void)openInController:(UIViewController *)controller;
+ (void)openInController:(UIViewController *)controller
            emailSubject:(NSString *)emailSubject
               emailBody:(NSString *)emailBody;

- (void)sendToAppStore;
- (void)openEmailForm;
- (void)openEmailFormTo:(NSString *)emailAddress;
- (void)showCallAlert;
- (void)done;

- (BOOL)shouldShowCallOption;

+ (void)openInController:(UIViewController *)controller
            emailAddress:(NSString *)emailAddress
            emailSubject:(NSString *)emailSubject
               emailBody:(NSString *)emailBody;

+ (void)openInController:(UIViewController *)controller
            emailAddress:(NSString *)emailAddress
            emailSubject:(NSString *)emailSubject
               emailBody:(NSString *)emailBody
             emailFooter:(NSString *)emailFooter;

@end
