#import "ViewController.h"

@interface ViewController ()<UITextFieldDelegate>

@property(nonatomic, weak) UILabel *labelRed;
@property(nonatomic, weak) UILabel *labelGreen;
@property(nonatomic, weak) UILabel *labelBlue;
@property(nonatomic, weak) UILabel *labelResultColor;

@property(nonatomic, weak) UITextField *textFieldRed;
@property(nonatomic, weak) UITextField *textFieldGreen;
@property(nonatomic, weak) UITextField *textFieldBlue;

@property(nonatomic, weak) UIButton *buttonProcess;

@property(nonatomic, weak) UIView *viewResultColor;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupLabels];
    [self setupTextFields];
    [self setupButton];
    [self setupResultView];
    [self setupIdentifiers];
}

- (void)setupTextFields {
    self.textFieldRed = [UITextField alloc];
    [self setupTextField:self.textFieldRed withPlaceholder:@"0..255" andPosition:CGRectMake(self.view.frame.origin.x + 140, self.view.frame.origin.y + 130, self.view.frame.size.width - 170, 40)];
    self.textFieldGreen = [UITextField alloc];
    [self setupTextField:self.textFieldGreen withPlaceholder:@"0..255" andPosition:CGRectMake(self.view.frame.origin.x + 140, self.view.frame.origin.y + 190, self.view.frame.size.width - 170, 40)];
    self.textFieldBlue = [UITextField alloc];
    [self setupTextField:self.textFieldBlue withPlaceholder:@"0..255" andPosition:CGRectMake(self.view.frame.origin.x + 140, self.view.frame.origin.y + 250, self.view.frame.size.width - 170, 40)];
}

- (void)setupLabels {
    self.labelResultColor = [UILabel alloc];
    [self setupLabel:self.labelResultColor withText:@"Color" andPosition:CGRectMake(self.view.frame.origin.x + 40, self.view.frame.origin.y + 80, 100, 20)];
    self.labelRed = [UILabel alloc];
    [self setupLabel:self.labelRed withText:@"RED" andPosition:CGRectMake(self.view.frame.origin.x + 40, self.view.frame.origin.y + 140, 100, 20)];
    self.labelGreen = [UILabel alloc];
    [self setupLabel:self.labelGreen withText:@"GREEN" andPosition:CGRectMake(self.view.frame.origin.x + 40, self.view.frame.origin.y + 200, 100, 20)];
    self.labelBlue = [UILabel alloc];
    [self setupLabel:self.labelBlue withText:@"BLUE" andPosition:CGRectMake(self.view.frame.origin.x + 40, self.view.frame.origin.y + 260, 100, 20)];
}

- (void)setupButton {
    self.buttonProcess = [UIButton buttonWithType:UIButtonTypeSystem];
    self.buttonProcess.frame = CGRectMake(self.view.bounds.size.width / 2 - 50, self.view.bounds.origin.y + 350, 100, 20);
    [self.buttonProcess setTitle:@"Process" forState:UIControlStateNormal];
    [self.buttonProcess addTarget:self action:@selector(processPress) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.buttonProcess];
}

- (void)setupResultView {
    self.viewResultColor = [[UIView alloc] initWithFrame:CGRectMake(self.view.frame.origin.x + 160, self.view.frame.origin.y + 70, self.view.frame.size.width - 190, 40)];
    self.viewResultColor.backgroundColor = [UIColor grayColor];
    [self.view addSubview:self.viewResultColor];
}

- (void)setupLabel:(UILabel *)label withText:(NSString *)name andPosition:(CGRect)rect {
    label = [label initWithFrame:rect];
    label.text = name;
    [self.view addSubview:label];
}

- (void)setupTextField:(UITextField *)textFiled withPlaceholder:(NSString *)placeholder andPosition:(CGRect)rect {
    textFiled = [textFiled initWithFrame:rect];
    textFiled.delegate = self;
    textFiled.placeholder = placeholder;
    textFiled.layer.borderColor = [UIColor lightGrayColor].CGColor;
    textFiled.layer.cornerRadius = 4;
    textFiled.layer.borderWidth = 2;
    textFiled.leftView = [[UIView alloc] initWithFrame:CGRectMake(rect.origin.x, rect.origin.y, 10, rect.size.height)];
    textFiled.leftViewMode = UITextFieldViewModeAlways;
    [self.view addSubview:textFiled];
}

- (void)processPress {
    NSString *redString = [self.textFieldRed text];
    NSString *greenString = [self.textFieldGreen text];
    NSString *blueString = [self.textFieldBlue text];
    if (![self isNumericString:redString] || ![self isNumericString:greenString] || ![self isNumericString:blueString]) {
        [self showError];
        return;
    }
    int r = redString.intValue;
    int g = greenString.intValue;
    int b = blueString.intValue;
    switch (r) {
        case 0 ... 255:
            break;
        default:
            [self showError];
            return;
    }
    switch (g) {
        case 0 ... 255:
            break;
        default:
            [self showError];
            return;
    }
    switch (b) {
        case 0 ... 255:
            break;
        default:
            [self showError];
            return;
    }
    [self.labelResultColor setText:[self rgbToStringWithR:r g:g b:b]];
    self.viewResultColor.backgroundColor = [UIColor colorWithRed:r / 255.0 green:g / 255.0 blue:b / 255.0 alpha:1];
    [self clearFields];
    [self.view endEditing:YES];
}

- (void)showError {
    [self clearFields];
    self.labelResultColor.text = @"Error";
    [self.view endEditing:YES];
}

- (void)clearFields {
    self.textFieldRed.text = nil;
    self.textFieldGreen.text = nil;
    self.textFieldBlue.text = nil;
}

- (void)setupIdentifiers {
    self.view.accessibilityIdentifier = @"mainView";
    self.textFieldRed.accessibilityIdentifier = @"textFieldRed";
    self.textFieldGreen.accessibilityIdentifier = @"textFieldGreen";
    self.textFieldBlue.accessibilityIdentifier = @"textFieldBlue";
    self.buttonProcess.accessibilityIdentifier = @"buttonProcess";
    self.labelRed.accessibilityIdentifier = @"labelRed";
    self.labelGreen.accessibilityIdentifier = @"labelGreen";
    self.labelBlue.accessibilityIdentifier = @"labelBlue";
    self.labelResultColor.accessibilityIdentifier = @"labelResultColor";
    self.viewResultColor.accessibilityIdentifier = @"viewResultColor";
}

- (NSString *)rgbToStringWithR:(CGFloat)red g:(CGFloat)green b:(CGFloat)blue {
    return [NSString stringWithFormat:@"0x%02X%02X%02X",
            (uint)red,
            (uint)green,
            (uint)blue];
}

- (BOOL)isNumericString:(NSString *)string {
    if (string.length == 0)
        return NO;
    NSCharacterSet *s = [NSCharacterSet characterSetWithCharactersInString:@"1234567890"];
       s = [s invertedSet];
       NSRange r = [string rangeOfCharacterFromSet:s];
       if (r.location != NSNotFound)
           return NO;
       else
           return YES;
}

- (void)textFieldDidBeginEditing:(UITextField *)textField {
    self.labelResultColor.text = @"Color";
}

@end
