#import "BillCounter.h"

@implementation BillCounter

// Complete the following fuction
- (NSString*)compareResultForBill:(NSArray<NSNumber*>*)bill notIncludingElementWithIndex:(NSInteger)index withGivenSum:(NSNumber*)sum {
    
    NSMutableArray *array = [NSMutableArray arrayWithArray:bill];
    [array removeObjectAtIndex:index];
    NSInteger shouldBeCharged = [[array valueForKeyPath:@"@sum.self"] integerValue] / 2;
    
    if (shouldBeCharged < sum.integerValue) {
        return [NSString stringWithFormat:@"%ld", sum.integerValue - shouldBeCharged];
    } else {
        return @"Bon Appetit";
    }
}

@end
