#import "SquareDecomposer.h"

@implementation SquareDecomposer
- (NSArray <NSNumber*>*)decomposeNumber:(NSNumber*)number {
    if ([number integerValue] <= 0)
        return nil;
    NSInteger goal = 0;
    NSMutableArray<NSNumber *> *result = [NSMutableArray arrayWithArray:@[number]];
    while (result.count != 0) {
        NSInteger cur = [[result lastObject] integerValue];
        [result removeLastObject];
        goal += pow(cur, 2);
        for (NSInteger i = --cur; i != 0; --i) {
            if (goal - pow(i, 2) >= 0) {
                goal -= pow(i, 2);
                [result addObject:[NSNumber numberWithInteger:i]];
                if (goal == 0) {
                    return [result sortedArrayUsingSelector:@selector(compare:)];
                }
            }
        }
    }
    return nil;
}
@end
