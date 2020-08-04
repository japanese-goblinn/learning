#import "MiniMaxArrayConverter.h"

@implementation MiniMaxArrayConverter

// Complete the convertFromArray function below.
- (NSArray<NSNumber*>*)convertFromArray:(NSArray<NSNumber*>*)array {
    
    NSMutableArray *result = [NSMutableArray arrayWithArray:@[ @0, @0 ]];
    
    NSNumber *firstResult = [[[array sortedArrayUsingSelector:@selector(compare:)] subarrayWithRange:NSMakeRange(0, array.count - 1)] valueForKeyPath:@"@sum.self"];

    NSNumber *secondResult = [[[array sortedArrayUsingSelector:@selector(compare:)] subarrayWithRange:NSMakeRange(1, array.count - 1)] valueForKeyPath:@"@sum.self"];
    
    [result replaceObjectAtIndex:0 withObject:firstResult];
    [result replaceObjectAtIndex:1 withObject:secondResult];
    
    return result;
}

@end
