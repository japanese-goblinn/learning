#import "Combinator.h"

@implementation Combinator
- (NSNumber*)chechChooseFromArray:(NSArray <NSNumber*>*)array {
    NSUInteger m = array[0].integerValue;
    NSUInteger n = array[1].integerValue;
    NSUInteger x = 1;
    
    if (m == n) {
        return [NSNumber numberWithInteger:x];
    }
    
    while (true) {
        if (++x > n)
            return nil;
        NSUInteger check = (NSUInteger)tgamma(n + 1) / ((NSUInteger)tgamma(x + 1) * (NSUInteger)tgamma(n - x + 1));
        if (check >= m)
            break;
    }
    return [NSNumber numberWithInteger:x];
}
@end
