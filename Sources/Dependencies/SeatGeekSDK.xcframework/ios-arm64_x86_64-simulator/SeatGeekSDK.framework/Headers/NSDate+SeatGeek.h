//
//  NSDate+SeatGeek.h
//  SeatGeek
//
//  Created by James Van-As on 26/05/13.
//  Copyright (c) 2013 SeatGeek. All rights reserved.
//

@import Foundation;

@interface NSDate (SeatGeek)

#pragma mark - Date Comparisons

- (BOOL)isAfter:(NSDate *)date;
- (BOOL)isBefore:(NSDate *)date;
- (BOOL)isSameDayAs:(NSDate *)date;
- (BOOL)isSameMonthAs:(NSDate *)date;
- (BOOL)isSameYearAs:(NSDate *)date;
- (int)monthsUntil:(NSDate *)toDate;
- (int)daysUntil:(NSDate *)toDate;
- (BOOL)isSunday;

- (NSTimeInterval)sg_timeIntervalUntilNow;
- (NSTimeInterval)sg_timeIntervalUntilDate:(NSDate *)futureDate;

#pragma mark - Modified Dates

- (NSDate *)dateWithoutDayComponent;
/// returns a sanitized version of today's date without any hour / sections etc components.
+ (NSDate *)today;
/// returns a date by adding N Caledar days to the date
- (NSDate *)dateByAddingDays:(NSInteger)numDays;
/// returns a date by adding N hours to the date
- (NSDate *)dateByAddingHours:(NSInteger)numHours;

#pragma mark - Decorations

/// Whether this date is ambiguous enough that we should display the year
- (BOOL)shouldShowYear;
- (BOOL)isToday;
- (BOOL)isTomorrow;
- (BOOL)isTonight; // We define "tonight" as: after 5pm today or before 3am tomorrow
- (BOOL)dateHasPassed;   //ie. yesterday or beyond
- (int)daysAgo;
- (NSString *)vagueString;
- (NSString *)colloquialString;
- (NSString *)trackerString;


+ (NSDate *)dateFromDateStringFoundInAnURL:(NSString *)dateString;

@end
