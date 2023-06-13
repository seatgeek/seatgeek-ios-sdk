//
//  NSString+SeatGeek.h
//  SeatGeek
//
//  Created by Eric Waller on 9/13/12.
//  Copyright (c) 2012 Devin7 Software. All rights reserved.
//

@import Foundation;

@interface NSString (SeatGeek)
// NOTE: Don't call this method with full URLs, since it's manually replacing & with %26
- (NSString *)URLEncodedQueryString;
- (NSString *)stringByTrimmingTrailingCharactersInSet:(NSCharacterSet *)characterSet;
- (NSString *)stringByTrimmingLeadingCharactersInSet:(NSCharacterSet *)characterSet;
- (NSString *)stringByTrimmingEndWhitespace;
- (NSString *)stringByRemovingHTML;
- (NSString *)stringByRemovingPrefixes:(NSArray *)prefixes;
- (NSString *)stringByRemovingLeadingArticles;
- (NSString *)stringByReplacingOccurrencesOfString:(NSString *)target safelyWithString:(NSString *)replacement;
- (NSString *)stringWithNonBreakingSpaces;
- (NSString *)capitalizedFirstLetterString;

#pragma mark URL based string helper methods

- (NSString *)stringByAppendingURLParameter:(NSString *)parameter value:(NSString *)value;
- (NSString *)stringByReplacingURLParameter:(NSString *)parameter with:(NSString *)newParameter;
- (NSString *)stringByForcingURLParameter:(NSString *)parameter toValue:(NSString *)value;
- (BOOL)containsURLParameter:(NSString *)parameter;
- (NSString *)parameterPortionOfURL;
/// Returns an array of parameters.  Parameters are dictionaries with key = arg, value = value
- (NSArray <NSDictionary *>*)parametersFromURL;
/// Return a copy of the string without any trailing path slashes
- (NSString *)pathWithoutTrailingSlash;
/// Return each component of the path in an array (ie. seatgeek://james/is/cool returns [james, is, cool]
- (NSArray *)pathBits;

// Return a version of this given url which requests a specific size of the image from our api at 1x display scale
- (NSString *)dynamicImageURLForSize:(CGSize)size;

// Return a version of this given url which requests a specific point size of the image from our api, at the given display scale
- (NSString *)dynamicImageURLForSize:(CGSize)size displayScale:(CGFloat)displayScale;

#pragma mark Comparison and search

- (BOOL)stringMatchesRegex:(NSString *)regex;
- (BOOL)containsAnySubstring:(NSArray <NSString *> *)substrings;
- (BOOL)sg_hasSignificantContents;
- (BOOL)isAllDigits;

/**
 Evaluates whether or nto the string represents a valid hex color.

 @return YES if the string represents a valid hex color.
 */
- (BOOL)isHexColorString;

/**
 Returns YES if the string is equal to another string ignoring case.

 @param aString The string to compare to this one
 @return YES if the string is equal to another string ignoring case.
 */
- (BOOL)caseInsensitiveIsEqualToString:(NSString *)aString;

/**
 Returns YES if the string is equal to another string ignoring the current locale's case notation.

 @param aString The string to compare to this one
 @return YES if the string is equal to another string ignoring the current locale's case notation.
 */
- (BOOL)localizedCaseInsensitiveIsEqualToString:(NSString *)aString;

#pragma mark Ticket information display helpers

+ (NSString *)quantityStringForQuantity:(int)quantity isEticket:(BOOL)eTicket showE:(BOOL)showE;
+ (NSString *)lowerQuantityStringForQuantity:(int)quantity  isEticket:(BOOL)eTicket showE:(BOOL)showE;

- (BOOL)sg_stringIsGeneralAdmission;
// These return @"" rather than nil
+ (NSString *)sg_prettySectionName:(NSString *)rawSectionName;
+ (NSString *)sg_prettyRowName:(NSString *)rawRowName;
+ (NSString *)sg_dotSeparateFirstString:(NSString *)firstString secondString:(NSString *)secondString;
+ (NSString *)dotSeparatedStrings:(NSArray <NSString *> *)strings;

#pragma mark Combine strings

/** Combines the two strings using the separator, behaving sensibly when any argument is nil. */
NSString * sg_combineTwoStrings(NSString *string1, NSString *string2, NSString *separator);

#pragma mark Version numbers

/** For comparing app version numbers, like 3.2 or 3.11.1 etc */
- (BOOL)sg_isGreaterThanVersion:(NSString *)otherVersion;

/** For comparing app version numbers, like 3.2 or 3.11.1 etc */
- (BOOL)sg_isLessThanVersion:(NSString *)otherVersion;

@end

