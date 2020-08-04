#import "AbbreviationMaker.h"

@implementation AbbreviationMaker
// Complete the abbreviation function below.
- (NSString *) abbreviationFromA:(NSString *)a toB:(NSString *)b {
    NSInteger j = 0;
    for (NSInteger i = 0; i < a.length; i++) {
        NSString *ach = [NSString stringWithFormat:@"%c", [a characterAtIndex:i]];
        NSString *bch = [NSString stringWithFormat:@"%c", [b characterAtIndex:j]];
        if ([ach caseInsensitiveCompare:bch] == NSOrderedSame)
            if (++j == b.length)
                return [NSString stringWithFormat:@"%@", @"YES"];
    }
    return [NSString stringWithFormat:@"%@", @"NO"];
}
@end
