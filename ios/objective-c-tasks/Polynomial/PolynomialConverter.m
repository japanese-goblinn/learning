#import "PolynomialConverter.h"

@implementation PolynomialConverter
- (NSString*)convertToStringFrom:(NSArray <NSNumber*>*)numbers {
    if (numbers.count == 0) {
        return nil;
    }
    NSMutableString *result = [NSMutableString new];
    for (NSInteger i = 0, pow = numbers.count - 1; i < numbers.count; i++, pow--) {
        NSInteger number = numbers[i].integerValue;
        if (i == 0) {
            if (pow == 0) {
                if (number > 0) {
                    if (number != 1)
                        [result appendFormat:@"%ld", (long)number];
                    else
                        [result appendFormat:@"1"];
                } else if (number < 0) {
                    if (number != -1)
                        [result appendFormat:@"%ld", (long)(-1 * number)];
                    else
                        [result appendFormat:@"-1"];
                }
            } else if (pow == 1) {
                if (number > 0) {
                    if (number != 1)
                        [result appendFormat:@"%ldx", (long)number];
                    else
                        [result appendFormat:@"x"];
                } else if (number < 0) {
                    if (number != -1)
                        [result appendFormat:@"%ldx", (long)(-1 * number)];
                    else
                        [result appendFormat:@"-x"];
                }
            } else {
                if (number > 0) {
                    if (number != 1)
                        [result appendFormat:@"%ldx^%ld ", (long)number, (long)pow];
                    else
                        [result appendFormat:@"x^%ld ", (long)pow];
                } else if (number < 0) {
                    if (number != -1)
                        [result appendFormat:@"%ldx^%ld ", (long)(-1 * number), (long)pow];
                    else
                        [result appendFormat:@"x^%ld ", (long)pow];
                }
            }
        } else if (pow == 1) {
            if (number > 0) {
                if (number != 1)
                    [result appendFormat:@"+ %ldx ", (long)number];
                else
                    [result appendFormat:@"+ x "];
            } else if (number < 0) {
                if (number != -1)
                    [result appendFormat:@"- %ldx ", (long)(-1 * number)];
                else
                    [result appendFormat:@"- x "];
            }
        } else if (pow == 0) {
            if (number > 0) {
                [result appendFormat:@"+ %ld", (long)number];
            } else if (number < 0) {
                [result appendFormat:@"- %ld", (long)(-1 * number)];
            }
        } else {
            if (number > 0) {
                if (number != 1)
                    [result appendFormat:@"+ %ldx^%ld ", (long)number, (long)pow];
                else
                    [result appendFormat:@"+ x^%ld ", (long)pow];
            } else if (number < 0) {
                if (number != -1)
                    [result appendFormat:@"- %ldx^%ld ", (long)(-1 * number), (long)pow];
                else
                    [result appendFormat:@"- x^%ld ", (long)pow];
            }
        }
    }
    return [NSString stringWithFormat:@"%@", result];
}
@end
