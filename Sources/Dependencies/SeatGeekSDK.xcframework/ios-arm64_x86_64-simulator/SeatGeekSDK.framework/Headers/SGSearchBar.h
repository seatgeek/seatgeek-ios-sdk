//
//  SGSearchBar.h
//  SeatGeek
//
//  Created by David Mazza on 12/10/13.
//  Copyright (c) 2013 SeatGeek. All rights reserved.
//

@class SGSearchActivityIndicator, SGBrowseFilter, SGNavigationBar;
@protocol SGSearchBarDelegate;

@interface SGSearchBar : UIView <UITextFieldDelegate>

@property (nonatomic, weak) id<SGSearchBarDelegate> delegate;
@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) NSString *placeholder;
@property (nonatomic, strong) UITextField *searchField;
@property (nonatomic) SGSearchActivityIndicator *activityIndicator;
@property (nonatomic, strong) UIButton *cancelButton;
@property (nonatomic, assign) BOOL showsCancelButton;
@property (nonatomic, assign) BOOL lockFirstResponder;
@property (nonatomic, assign) BOOL hideBottomKeyline;
@property (nonatomic, strong) SGBrowseFilter *filter;

/// Search bars have an extra bottom padding.  Use this to place content below the safe area inset
@property (nonatomic, readonly, assign) CGFloat extraBottomMargin;

/// Search bars have a defined searchField height, vertically-centered, regardless of SGSearchBar.height
@property (nonatomic, readonly, assign) CGFloat searchFieldHeight;

/// By default, Search bars inset the bottom keyline by HorizontalMargin. This allows users to remove this margin.
@property (nonatomic, assign) BOOL extendBottomKeylineToEdges;

- (void)styleDefaultColors;

- (void)startActivityIndicator;
- (void)stopActivityIndicator;

- (void)setButtonTitle:(NSString *)title;

- (void)setIconTintColor:(UIColor *)tintColor;

@end


@protocol SGSearchBarDelegate <NSObject>

@optional

- (BOOL)searchBarShouldBeginEditing:(SGSearchBar *)searchBar;                      // return NO to not become first responder
- (void)searchBarTextDidBeginEditing:(SGSearchBar *)searchBar;                     // called when text starts editing
- (BOOL)searchBarShouldEndEditing:(SGSearchBar *)searchBar;                        // return NO to not resign first responder
- (void)searchBarTextDidEndEditing:(SGSearchBar *)searchBar;                       // called when text ends editing
- (void)searchBar:(SGSearchBar *)searchBar textDidChange:(NSString *)searchText;   // called when text changes (including clear)
- (BOOL)searchBar:(SGSearchBar *)searchBar shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text NS_AVAILABLE_IOS(3_0); // called before text changes

- (BOOL)textFieldShouldReturn:(UITextField *)textField;                            // return YES if return should dismiss
- (void)searchBarCancelButtonClicked:(SGSearchBar *) searchBar;                    // called when cancel button pressed

@end
