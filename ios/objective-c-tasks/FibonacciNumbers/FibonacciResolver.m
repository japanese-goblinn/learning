#import "FibonacciResolver.h"

@implementation FibonacciResolver
- (NSArray*)productFibonacciSequenceFor:(NSNumber*)number {
    NSNumber *prev = @0;
    NSNumber *cur = @1;
    while (number.integerValue >= prev.integerValue * cur.integerValue) {
        if (prev.integerValue * cur.integerValue == number.integerValue) {
            return @[prev, cur, @1];
        }
        NSNumber *next = [NSNumber numberWithInteger:prev.integerValue + cur.integerValue];
        prev = cur;
        cur = next;
    }
   return @[prev, cur, @0];
}
@end
