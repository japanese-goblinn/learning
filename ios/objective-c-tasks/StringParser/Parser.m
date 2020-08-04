#import "Parser.h"

@implementation Parser

// Complete the parseString function below.
- (NSArray <NSString*>*)parseString:(NSString*)string {
    NSDictionary *charDict = @{ @"[": @"]", @"(": @")", @"<": @">" };
    NSMutableArray<NSString *> *result = [NSMutableArray new];
    
     for (NSInteger i = 0; i < [string length]; i++) {
         unichar ch = [string characterAtIndex:i];
         if (ch == '[' || ch == '(' || ch == '<') {
             NSMutableString *newString = [NSMutableString new];
             NSInteger j = i + 1;
             NSInteger skiped = 0;
             unichar nextChar = [string characterAtIndex:j];
             NSString *opositeChar = [NSString stringWithCharacters:&ch length:1];
             unichar closingChar = [charDict[opositeChar] characterAtIndex:0];
             while (nextChar != closingChar) {
                 [newString appendFormat:@"%C", nextChar];
                 nextChar = [string characterAtIndex:++j];
                 if (nextChar == ch)
                     skiped++;
                 if (nextChar == closingChar && skiped) {
                     [newString appendFormat:@"%C", nextChar];
                     nextChar = [string characterAtIndex:++j];
                     skiped--;
                 }
             }
             [result addObject:newString];
         }
     }
    return result;
}

@end
