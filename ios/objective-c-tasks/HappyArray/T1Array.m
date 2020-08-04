#import "T1Array.h"

@implementation T1Array

// Complete the following fuction
- (NSArray *)convertToHappy:(NSArray *)sadArray {
    
    if (!sadArray.count) {
         return @[];
    }
    
    NSMutableArray *happyArray = [NSMutableArray new];
    [happyArray addObject: sadArray[sadArray.count - 1]];
    
    for (NSInteger i = sadArray.count - 2; i > 0; i--) {
        NSInteger leftValue = [sadArray[i - 1] integerValue];
        NSInteger rightValue = [happyArray[0] integerValue];
        NSInteger currentValue = [sadArray[i] integerValue];
        if (leftValue + rightValue > currentValue) {
            [happyArray insertObject:[NSNumber numberWithInteger:currentValue] atIndex:0];
        }
    }
    
    [happyArray insertObject:sadArray[0] atIndex:0];
    
    return happyArray;
}

@end
