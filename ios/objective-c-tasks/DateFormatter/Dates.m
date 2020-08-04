#import "Dates.h"

@implementation Dates

- (NSString *)textForDay:(NSString *)day month:(NSString *)month year:(NSString *)year {
    NSDateFormatter *dateFormatter = [NSDateFormatter new];
    dateFormatter.locale = [NSLocale localeWithLocaleIdentifier:@"ru"];
    dateFormatter.dateFormat = @"dd-MM-yyyy";
    NSDate *date = [dateFormatter dateFromString:[NSString stringWithFormat:@"%@-%@-%@", day, month, year]];
    
    if (!date) {
        return @"Такого дня не существует";
    }
    
    NSString *localeDayString = [NSDateFormatter dateFormatFromTemplate:@"EEEE" options:0 locale:dateFormatter.locale];
    dateFormatter.dateFormat = localeDayString;
    NSString *localizedDay = [dateFormatter stringFromDate:date];
    
    NSString *localeDateString = [NSDateFormatter dateFormatFromTemplate:@"ddMMMM" options:0 locale:dateFormatter.locale];
    dateFormatter.dateFormat = localeDateString;
    NSString *localizedDate = [dateFormatter stringFromDate:date];
    
    return [NSString stringWithFormat:@"%@, %@", localizedDate, localizedDay];
}

@end
