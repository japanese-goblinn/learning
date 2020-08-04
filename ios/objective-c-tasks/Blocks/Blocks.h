#import <Foundation/Foundation.h>

typedef void (^BlockA)(NSArray *);
typedef void (^BlockB)(Class);
typedef void (^BlockC)(NSObject *result);

@interface Blocks : NSObject

@property (nonatomic, copy) BlockA blockA;
@property (nonatomic, copy) BlockB blockB;
@property (nonatomic, copy) BlockC blockC;

@end
