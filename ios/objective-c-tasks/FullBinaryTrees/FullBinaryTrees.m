#import "FullBinaryTrees.h"

@interface Node : NSObject

@property (nonatomic, strong) NSString *val;
@property (nonatomic, strong) Node *left;
@property (nonatomic, strong) Node *right;

@end

@implementation Node

- (instancetype)init {
    self = [super init];
    if (self) {
        self.val = @"0";
        self.left = [[Node alloc] initWithNull];
        self.right = [[Node alloc] initWithNull];
    }
    return self;
}

- (instancetype)initWithNull {
    self = [super init];
    if (self) {
        self.val = @"null";
        self.left = nil;
        self.right = nil;
    }
    return self;
}

@end

@interface FullBinaryTrees ()

@property (nonatomic, strong) NSMutableDictionary<NSNumber *, NSArray<Node *> *> *storage;

@end


@implementation FullBinaryTrees

- (NSArray<Node *> *)allPosibleFBT:(NSInteger)n {
    NSNumber *k = [NSNumber numberWithInteger:n];
    if (!self.storage[k]) {
        NSMutableArray<Node *> *answ = [NSMutableArray new];
        for (NSInteger x = 0; x < n; ++x) {
            for (Node *left in [self allPosibleFBT:x]) {
                for (Node *right in [self allPosibleFBT:n - 1 - x]) {
                    Node *node = [Node new];
                    node.left = left;
                    node.right = right;
                    [answ addObject:node];
                }
            }
        }
        self.storage[k] = answ;
    }
    return self.storage[k];
}

- (void)getTreeValuesIn:(NSMutableArray<NSString *> *)strings with:(Node *)node {
    NSMutableArray<Node *> *queue = [NSMutableArray new];
    [queue addObject:node];
    while (queue.count != 0) {
        Node *newNode = [queue firstObject];
        [queue removeObjectAtIndex:0];
        [strings addObject:[NSString stringWithFormat:@"%@", newNode.val]];
        if (newNode.left != nil) {
            [queue addObject:newNode.left];
        }
        if (newNode.right != nil) {
            [queue addObject:newNode.right];
        }
    }
}

- (NSString *)stringForNodeCount:(NSInteger)count {
    if (count == 1)
        return @"[[0]]";
    if (count == 0 || count % 2 == 0)
        return @"[]";
    self.storage = [NSMutableDictionary new];
    self.storage[[NSNumber numberWithInt:0]] = @[];
    self.storage[[NSNumber numberWithInt:1]] = @[[Node new]];
    NSArray<Node *> *tree = [self allPosibleFBT:count];
    NSMutableArray<NSString *> *allStrings = [NSMutableArray new];
    
    for (Node *node in tree) {
        NSMutableArray<NSString *> *strings = [NSMutableArray new];
        [self getTreeValuesIn:strings with:node];
        for (NSInteger i = strings.count - 1; i != 0; --i) {
            if ([strings[i] isEqual:@"null"])
                [strings removeLastObject];
            else
                break;
        }
        [allStrings addObject: [NSString stringWithFormat:@"[%@]", [strings componentsJoinedByString:@","]]];
    }
    return [NSString stringWithFormat:@"[%@]", [allStrings componentsJoinedByString:@","]];
}

@end
