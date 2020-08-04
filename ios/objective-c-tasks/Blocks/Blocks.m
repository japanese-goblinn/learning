#import "Blocks.h"

@interface Blocks () {
    NSArray *arrayStore;
}
@end

@implementation Blocks

- (BlockA)blockA {
    return [^(NSArray *array) {
        arrayStore = array;
    } copy];
}

- (BlockB)blockB {
    return [^(Class class) {
        if (class == NSString.class) {
            NSArray<NSString *> *strings = [arrayStore filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(id element, NSDictionary<NSString *, id> *bindings) {
                return [element isKindOfClass: [NSString class]];
            }]];
            self.blockC([strings componentsJoinedByString:@""]);
        } else if (class == NSNumber.class) {
            NSArray<NSNumber *> *nums = [arrayStore filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(id element, NSDictionary<NSString *, id> *bindings) {
                return [element isKindOfClass: [NSNumber class]];
            }]];
            self.blockC([nums valueForKeyPath:@"@sum.self"]);
        } else if (class == NSDate.class) {
            NSArray<NSDate *> *nums = [[arrayStore filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(id element, NSDictionary<NSString *, id> *bindings) {
                return [element isKindOfClass: [NSDate class]];
            }]] sortedArrayUsingSelector:@selector(compare:)] ;
            NSDateFormatter *f = [NSDateFormatter new];
            [f setDateFormat:@"dd.MM.yyyy"];
            self.blockC([f stringFromDate:nums.lastObject]);
        }
    } copy];
}

@end

