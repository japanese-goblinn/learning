#import "TelephoneFinder.h"

@implementation TelephoneFinder
- (NSArray <NSString*>*)findAllNumbersFromGivenNumber:(NSString*)number {
    if ([number containsString:@"-"])
        return nil;
    NSDictionary *neibs = @{
        @"1": @"24",
        @"2": @"135",
        @"3": @"26",
        @"4": @"157",
        @"5": @"2468",
        @"6": @"359",
        @"7": @"48",
        @"8": @"7590",
        @"9": @"68",
        @"0": @"8",
    };
    NSMutableArray<NSString *> *res = [NSMutableArray new];
    for (NSInteger i = 0; i < number.length; ++i) {
        NSString *ch = [number substringWithRange:NSMakeRange(i, 1)];
        NSString *chars = neibs[ch];
        for (NSInteger j = 0; j < chars.length; ++j) {
            NSString *str = [[number mutableCopy]
             stringByReplacingCharactersInRange:NSMakeRange(i, 1)
             withString:[chars substringWithRange:NSMakeRange(j, 1)]];
            [res addObject:str];
        }
    }
    return [res copy];
}
@end
