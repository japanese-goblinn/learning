#import "NSString+Transform.h"

@implementation NSString (Transform)

-(NSString*)transform {
    NSArray *words = [[self componentsSeparatedByString:@" "] filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(id element, NSDictionary<NSString *, id> *bindings) {
        NSString *s = element;
        return ![s isEqualToString:@""];
    }]];
    
    NSString *vowels = @"aeiouy";
    NSMutableString *alphabet = [NSMutableString new];
    for (int i = 0; i < 26; i++) [alphabet appendFormat:@"%c", 'a' + i];
    NSMutableString *pangramCheckString = [NSMutableString new];
    for (int i = 0; i < self.length; i++) {
        NSString *ch = [[NSString stringWithFormat:@"%c", [self characterAtIndex:i]] lowercaseString];
        if (![pangramCheckString containsString:ch] && [alphabet containsString:ch]) {
            [pangramCheckString appendString:ch];
        }
    }
    
    NSMutableArray<NSString *> *resultArray = [NSMutableArray new];
    if (pangramCheckString.length == alphabet.length) {
        for (NSString *word in words) {
            NSMutableString *resultString = [NSMutableString stringWithString:word];
            NSInteger vowelCount = 0;
            for (NSInteger i = 0; i < resultString.length; i++){
                NSString *ch = [[NSString stringWithFormat:@"%c", [word characterAtIndex:i]] lowercaseString];
                if ([vowels containsString:ch]) {
                    vowelCount++;
                    [resultString replaceCharactersInRange:NSMakeRange(i, 1) withString:[ch uppercaseString]];
                }
            }
            [resultArray addObject:[NSString stringWithFormat:@"%lu%@", vowelCount, resultString]];
        }
    } else {
        for (NSString *word in words) {
            NSMutableString *resultString = [NSMutableString stringWithString:word];
            NSInteger consonantsCount = 0;
            for (NSInteger i = 0; i < resultString.length; i++){
                NSString *ch = [[NSString stringWithFormat:@"%c", [word characterAtIndex:i]] lowercaseString];
                if (![vowels containsString:ch] && [alphabet containsString:ch]) {
                    consonantsCount++;
                    [resultString replaceCharactersInRange:NSMakeRange(i, 1) withString:[ch uppercaseString]];
                }
            }
            [resultArray addObject:[NSString stringWithFormat:@"%lu%@", consonantsCount, resultString]];
        }
    }
    resultArray = [[resultArray sortedArrayUsingComparator:^NSComparisonResult(id l, id r) {
        NSInteger ln = [[NSString stringWithFormat:@"%c", [l characterAtIndex:0]] intValue];
        NSInteger rn = [[NSString stringWithFormat:@"%c", [r characterAtIndex:0]] intValue];
        return ln > rn;
    }] mutableCopy];
    return [NSString stringWithFormat:@"%@", [resultArray componentsJoinedByString:@" "]];
}

@end
