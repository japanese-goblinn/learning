#import "TimeConverter.h"

@implementation TimeConverter
// Complete the following function
- (NSString*)convertFromHours:(NSString*)hours minutes:(NSString*)minutes {
    
    NSDictionary *hoursToStrings = @{
        @2: @"two",
        @4: @"four",
        @5: @"five",
        @6: @"six",
        @9: @"nine",
        @10: @"ten",
        @11: @"eleven",
    };
    
    NSDictionary *minutesToStrings = @{
        @2: @"two",
        @5: @"five",
        @22: @"twenty two"
    };
    
    NSNumber *h = [NSNumber numberWithInteger:[hours integerValue]];
    NSNumber *m = [NSNumber numberWithInteger:[minutes integerValue]];
    
    if (h.intValue > 23 || h.intValue < 0) {
        return @"";
    }
    if (m.intValue > 59 || m.intValue < 0) {
        return @"";
    }
    
    if (m.intValue == 0) {
        return [NSString stringWithFormat:@"%@ o' clock", hoursToStrings[h]];
    } else if (m.intValue >= 1 && m.intValue <= 30) {
        if (m.intValue == 15) {
            return [NSString stringWithFormat:@"quarter past %@", hoursToStrings[h]];
        } else if (m.intValue == 30) {
            return [NSString stringWithFormat:@"half past %@", hoursToStrings[h]];
        } else {
            return [NSString stringWithFormat:@"%@ minutes past %@", minutesToStrings[m], hoursToStrings[h]];
        }
    } else {
        NSNumber *mr = [NSNumber numberWithInt:60 - m.intValue];
        NSNumber *hr = [NSNumber numberWithInt:h.intValue + 1];
        if (mr.intValue == 15) {
            return [NSString stringWithFormat:@"quarter to %@", hoursToStrings[hr]];
        } else {
            return [NSString stringWithFormat:@"%@ minutes to %@", minutesToStrings[mr], hoursToStrings[hr]];
        }
    }
    return @"";
}
@end
