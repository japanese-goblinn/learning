#import "PalindromeSolver.h"

@implementation PalindromeSolver

// Complete the highestValuePalindrome function below.
- (NSString *) highestValuePalindrome:(NSString *)s n:(NSNumber *)n k:(NSNumber *)k {
    
    NSString *result = [NSString stringWithString:s];
    NSInteger kk = [k integerValue];
    NSInteger nn = [n integerValue];
    
    for (NSInteger i = 0, j = nn - 1; i != nn / 2; i++, j--) {
        if (kk < 0) {
            return @"-1";
        }
        NSInteger left = [[s substringWithRange:NSMakeRange(i, 1)] integerValue];
        NSInteger right = [[s substringWithRange:NSMakeRange(j, 1)] integerValue];
        if (left != right) {
            if (kk - 2 >= 0) {
                result = [result stringByReplacingCharactersInRange:NSMakeRange(i, 1) withString:[NSString stringWithFormat:@"%i", 9]];
                result = [result stringByReplacingCharactersInRange:NSMakeRange(j, 1) withString:[NSString stringWithFormat:@"%i", 9]];
                kk -= 2;
            } else {
                NSInteger replace = MAX(left, right);
                result = [result stringByReplacingCharactersInRange:NSMakeRange(i, 1) withString:[NSString stringWithFormat:@"%li", replace]];
                result = [result stringByReplacingCharactersInRange:NSMakeRange(j, 1) withString:[NSString stringWithFormat:@"%li", (long)replace]];
                kk--;
            }
        }
    }
    
    return result;
}

@end
