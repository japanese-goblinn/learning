#import "ArrayCalculator.h"

@implementation ArrayCalculator
+ (NSInteger)maxProductOf:(NSInteger)numberOfItems itemsFromArray:(NSArray *)array {
    NSInteger result = 1;
    NSArray *filteredArray = [array filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(id object, NSDictionary *bindings) {
        return [object isKindOfClass:[NSNumber class]];
    }]];
    if (filteredArray.count == 0) {
        return 0;
    }
    if (filteredArray.count <= numberOfItems) {
        for (NSNumber *num in filteredArray) {
            result *= [num integerValue];
        }
        return result;
    }
    NSArray *sorted = [filteredArray sortedArrayUsingSelector:@selector(compare:)];
    NSInteger n = numberOfItems;
    NSInteger s = 0;
    NSInteger e = sorted.count - 1;
    while (n--) {
        BOOL expr = [sorted[s] integerValue] * [sorted[s + 1] integerValue] <=
        [sorted[e] integerValue] * [sorted[e - 1] integerValue];
        if (expr)
            result *= [sorted[e--] integerValue];
        else
            result *= [sorted[s++] integerValue];
    }
    return result;
}
@end
