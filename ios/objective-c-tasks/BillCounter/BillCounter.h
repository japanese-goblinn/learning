#import <Foundation/Foundation.h>

@interface BillCounter : NSObject

// The output could be "Bon appetit" or the string with number(e.g "10")
- (NSString*)compareResultForBill:(NSArray<NSNumber*>*)bill notIncludingElementWithIndex:(NSInteger)index withGivenSum:(NSNumber*)sum;

@end

