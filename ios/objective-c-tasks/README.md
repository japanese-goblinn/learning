# objective-c-tasks

* `HappyArray`

    An array of integers is "sad" while it contains bad elements. Element of an array is bad if the sum of nearest elements is less than its value.

    Example:

    Sad array: 1, 5, 2, 7, 93, 8, 9, 3

    Happy array: 1, 2, 7, 8, 9, 3

    5 is bad element: 1 + 2 < 5

    93 is bad element: 7 + 8 < 93

    Let's make the array happy!

* `MiniMaxSum`

    Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers. Then print the respective minimum and maximum values as a single line of two space- separated long integers.

    Input Format

    An array(NSArray) of integers(NSInteger).

    Output Format

    An array(NSArray) of integers(NSInteger) denoting the respective minimum and maximum values that can be calculated by summing exactly four of the five integers.

    Sample Input

    12345

    Sample Output

    10 14

* `PalindromeSolver`

    Palindromes are strings that read the same from the left or right, for example madam or 0110.

    You will be given a string representation of a number and a maximum number of changes you can make. Alter the string, one digit at a time, to create the string representation of the largest number possible given the limit to the number of changes. The length of the string may not be altered, so you must consider 's left of all higher digits in your tests. For example is valid, is not.

    Given a string representing the starting number and a maximum number of changes allowed, create the largest palindromic string of digits possible or the string -1 if it's impossible to create a palindrome under the contstraints.
    Note: Treat the integers as numeric strings. Leading zeros are permitted and can't be ignored so 0011 is not a palindrome, but 0110 is. A digit can be modified more than once.

    Input Format

    The first line contains two space-separated integers, (the number of digits in the number) and (the maximum number of changes allowed), respectively.
    The second line contains an -digit string of numbers that Sandy must attempt to make palindromic.

    Constraints

    0 < n <= 10^5

    0 <= k <= 10^5

    Each character in the number is an integer where.

    Output Format

    Print a single line with the largest number that can be made by changing no more than k digits; if this in not possible, print -1.

* `StringParser`

    Given a string with open-close brackets, which are [], <> or (). Find all the substrings, that are met between the brackets.

    Note that substring must be located between first met open and close bracket. As an example, for «(here is) some text)» the input would be «here is», not «(here is) some text)» due the second «)» bracket.

    Input Format

    NSString that might contain the following brackets: [], <>, ()

    Output Format

    An array(NSArray) of strings(NSString). Each element of array must contain substring between the open-close bracket.

* `BillCounter`

    Anna and Brian are sharing a meal at a restaurant and they agree to split the bill equally. Brian wants to order something that Anna is allergic to though, and they agree that Anna won't pay for that item. Brian gets the check and calculates Anna's portion. You must determine if his calculation is correct. For example, assume the bill has the following prices: bill = [2, 4, 6] . Anna declines to eat item k = bill[2] which costs 6. If Brian calculates the bill correctly, Anna will pay (2 + 4)/2 = 3. If he includes the cost of , he will calculate (2 + 4 + 6)/2 = 6. In the second case, he should refund 3 to Anna.

    Function Description

    Complete the function in the editor below. It should print Bon Appetit if the bill is fairly split. Otherwise, it should print the integer amount of money that Brian owes Anna.

    bonAppetit has the following parameter(s):

    • bill: an array of integers representing the cost of each item ordered

    • k: an integer representing the zero-based index of the item Anna doesn't eat

    • b: the amount of money that Anna contributed to the bill

    Input Format

    N space-separated integers bill[i](NSArray of NSNumbers) where 0 <= i < n, the 0-based index of the item that Anna did not eat and an NSNumber, b, the amount of money that Brian charged Anna for her share of the bill ().

    Output Format

    If Brian did not overcharge Anna, return @«Bon Appetit»; otherwise, return the difference (i.e., bcharged - bactual) that Brian must refund to Anna. This will always be a string (e.g. @«10»).

* `DateFormatter`

    Робот Генадий, умный робот. Он умеет говорить на правильном русском языке и по дате, определяет день недели.

    Будь как Генадий.

    Задача:

    Реализуйте метод, который по числу, месяцу и году определяет день недели и возвращает его в правильном падеже.

    Пример:

    Входные данные: 17 11 2020

    Выходная строка: 17 ноября, вторник

    Входные данные: 18 3 2019

    Выходная строка: 18 марта, понедельник

    Входные данные: 29 2 2017

    Выходная строка: Такого дня не существует

* `TimeInWords`

    At minutes = 0, use o' clock. For 1 <= minutes <= 30, use past, and for 30 < minutes use to. Note the space between the apostrophe and clock in o' clock. Write a program which prints the time in words for the input given in the format described.

    Function Description

    Complete the timeInWords function in the editor below. It should return a time string as described.

    timeInWords has the following parameter(s):

    • h: an string representing hour of the day

    • m: an string representing minutes after the hour

    Input Format

    The first line contains h, the hours portion. The second line contains m, the minutes portion

    Note: You must not use any native classes such as NSDateFormatter and NSNumberFormatter, only your own implementation! Also function must return an empty string in case input parameters are invalid («89» in minutes e.g.)

* `Abbreviation`

    You can perform the following operations on the string, a:

    1. Capitalize zero or more of a's lowercase letters.

    2. Delete all of the remaining lowercase letters in a.

    Given two strings, a and b, determine if it's possible to make a  equal to b as described. If so, print YES on a new line. Otherwise, print NO.

    For example, given a=AbcDE and b=ABDE, in a we can convert b and delet c to match b. If a=AbcDE and b=AFDE, matching is not possible because letters may only be capitalized or discarded, not changed.

* `Panagram`

    Pangram - a sentence that contains each letter of the alphabet at least one time
    Pangram example: "Farmer jack realized that big yellow quilts were expensive"
    Сonvert method should transform string according to the
    following rules:

    a. if the given string is pangram :

  * all words of a given string should be sorted by count of
    vowels; notes: (vowels: a,e,i,o,u,y), (words: all substrings of a given string separated by space), words shouldn't have 0 lengths, a word may contain a punctuation character ("someWord," or even ",").

  * all vowels should be capitalized (no need to change letters that are already capitalized)

  * each word should begin with a count of vowels (before: name, after: 2name)

    b. if the given string is not pangram

  * all words of a given string should be sorted by count of
    consonants; notes: (consonants: all letters of English alphabet excluding vowels), (words: all substrings of a given string separated by space), words shouldn't have 0 lengths, a word may contain a punctuation character ("someWord," or even ",").

  * all consonants should be capitalized (no need to change letters that are already capitalized)

  * each word should begin with a count of consonants (before: name, after: 2name)
    newline characters should be replaced with spaces

    EXAMPLE:

    pangrams

    [@"The five boxing wizards jump quickly." convert] should return "1ThE 1jUmp 2fIvE 2bOxIng 2wIzArds 3qUIcklY."

    [@"A mad boxer shot a quick, gloved jab to the jaw of his dizzy opponent." convert] should return "1A 1mAd 1shOt 1A 1jAb 1tO 1thE 1jAw 1Of 1hIs 2bOxEr 2qUIck, 2glOvEd 2dIzzY 3OppOnEnt."

    no pangrams

    [@"Even the most complicated sentences start with a simple structure." convert] should return "0a 2EVeN 2THe 3MoST 3WiTH 4STaRT 4SiMPLe 6SeNTeNCeS 6STRuCTuRe. 7CoMPLiCaTeD"

* `Blocks`

    Робот Пафнутий узнал про блоки. И теперь он отказывается работать как-то по другому.
    Помоги Пафнутию выполнить простейшие операции с разными типами объектов.
    blockA — принимает данные. В блок передается массив разных объектов. Числа, строки, даты. Массив без данных Пафнутий не принимает.

    blockB — принимает данные. В блок передается класс объекта, с которым нужно работать.

    blockC — возвращает данные на основе тех, которые были получены в блоках A и B.

    В зависимости от принимаемого массива в блоке A и класса в блоке B в блок C возвращается:

    1. Для чисел — сумма всех чисел

    2. Для строк — конкатенация всех строк

    3. Для дат — самая позняя дата в виде строки в формате
    dd.MM.yyyy

    blockC вызывается, когда у Пафнутия хватает данных для вычисления

    Пример:

    В blockA передаем массив @[@1, @"4", @2, @"3"]

    В blockB передаем класс NSString

    В blockC возвращает "43”, так как из массива в блоке А берутся элементы типа NSString (из блока B) - @"4" и @“3” - и происходит их конкатенация

* `FibonacciNumbers`

    The Fibonacci numbers are the numbers in the following integer
    sequence (Fn):

    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...

    such as

    F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1.

    Given a number, say product, we search two Fibonacci numbers F(n) and F(n+1) verifying

    F(n) * F(n+1) = prod.

    Your function productFib takes an NSNumber (prod) and returns an
    array of NSNumbers:

    [F(n), F(n+1), (@0 or @1))]

    @1 if F(n) *F(n+1) = prod and @0 if F(n)* F(n+1) is not equal to prod

    Example:

    productFibonacciSequenceFor(@15) # should return (@3, @5, @1), #since F(4) = 3, F(5) = 5 and 15 = 3 * 5

    productFib(30) # should return (@5, @8, @0), #since F(4) = 3, F(5) = 5, F(6) = 8 and 3 *5 < 30 < 5* 8

* `Polynomial`

    A polynomial function can be represented by a vector of its coefficients. For instance p(x) = 5x^3 + 2x + 3 can be described as (5, 0, 2, 3). The latter representation is more 'computational friendly', while the first representation is more human readable.

    Your task is to create function, which converts array of coefficients to equation. The function takes an array with the NSNumber coefficients as a parameter. The coefficients array starts with the highest degree. The function should return the polynomial in a simple human readable form. This means you skip 0 coefficient terms completely and you do not write down 1 coefficients.

    Please note that numbers could be negative. In case the input array is empty, return nil.

    Here is the example:

    Input array [@4, @, @5, @20] should return @"4x^3 + 5x + 20"

* `Combinator`

    You know combinations: for example, if you take 5 cards from a 52 cards deck you have 2,598,960 different combinations.

    In mathematics the number of x combinations you can take from a set of n elements is called the binomial coefficient of n and x, or more often n choose x.
    HINT: one of formulas(for m = n choose x) from combinatorics could help you with solution.

    You are a renowned poster designer and painter. You are asked to provide 6 posters all having the same design each in 2 colors. Posters must all have a different color combination and you have the choice of 4 colors: red, blue, yellow, green. How many colors can you choose for each poster?

    The answer is two since 4 choose 2 = 6. The combinations will be: {red, blue}, {red, yellow}, {red, green}, {blue, yellow}, {blue, green}, {yellow, green}.
    Now same question but you have 35 posters to provide and 7 colors available. How many colors for each poster? If you take combinations 7 choose 2 you will get 21 with the above formula. But 21 schemes aren't enough for 35 posters. If you take 7 choose 5 combinations you will get 21 too. Fortunately if you take 7 choose 3 or 7 choose 4 combinations you get 35 and so each poster will have a different combination of 3 colors or 5 colors. You will take 3 colors because it's less expensive.

    Hence the problem is:

    knowing m (number of posters to design), knowing n (total number of available colors), let us search x (number of colors for each poster so that each poster has a unique combination of colors and the number of combinations is exactly the same as the number of posters). In other words you should create a function which takes m(NSNumber) and n(NSNumber) and returns x(NSNumber).
    Some more conditions: m >= 0 and n > 0. If many x are solutions give as result the smallest x. It can happen that when m is given at random there are no x satisfying equation (1) then return nil.

    Here's the examples :

    @[@6, @4] would return @2

    @[@4, @4] would return @1

    @[@4, @2] would return nil

* `GreatMixer`

    А вы знаете, что с помощью цветовой схемы RGB можно получить 16777216 вариантов цветов?

    В рамках задачи нужно реализовать всего один экран со следующими элементами:

  * четыре UILabel

  * три UITextView

  * одна UIButton

  * одно UIView

    Для всех элементов нужно добавить accessibilityIdentifier, чтобы работали тесты:

    ```objc
    view.accessibilityIdentifier = @"mainView"
    textFieldRed.accessibilityIdentifier = @"textFieldRed" textFieldGreen.accessibilityIdentifier = @"textFieldGreen" textFieldBlue.accessibilityIdentifier = @"textFieldBlue"
    buttonProcess.accessibilityIdentifier = @"buttonProcess"
    labelRed.accessibilityIdentifier = @"labelRed" labelGreen.accessibilityIdentifier = @"labelGreen" labelBlue.accessibilityIdentifier = @"labelBlue" labelResultColor.accessibilityIdentifier = @"labelResultColor"
    viewResultColor.accessibilityIdentifier = @"viewResultColor"
    ```

    От программы требуется две вещи. Она должна нормально выглядеть и она должна правильно работать.

* `ArrayCalculator`

    Your task is to implement the method, which calculates a product of N integers in array.

    Example:

    If we have an array: [1,2,3,4,5,6,7,8,9,0] and N = 3, the result of the function should be equal 504 (7 *8* 9).

    If we have an array: [-1, 2, -3, 4, -5, 6, -7] and N = 5, the result should be equal to 1680 (2 *4* -5 *6* -7).

    • Positive, negative and zero integers are calculated.

    • Non-integer values (string, etc.) should not be included in calculation.

    • If N is higher than number of integers in array, include all available integers.

* `SquareDecomposer`

    My younger sister came back home from school with the following task: given a squared sheet of paper she has to cut it in pieces which, when assembled, give squares the sides of which form an increasing sequence of numbers. At the beginning it was lot of fun but little by little we were tired of seeing the pile of torn paper. So we decided to write a program that could help us and protects trees.

    Task

    Given a positive integral number n, return a strictly increasing sequence (array) of numbers, so that the sum of the squares is equal to n2.
    If there are multiple solutions (and there will be), return as
    far as possible the result with the largest possible values:

    Examples

    decompose(@11) must return [@1,@2,@4,@10]. Note that there are actually two ways to decompose 112, 112 = 121 = 1 + 4 + 16 + 100 = 12 + 22 + 42 + 102 but don't return [2,6,9], since 9 is smaller than 10.

    For decompose(@50) don't return [@1, @1, @4, @9, @49] but [@1, @3, @5, @8, @49] since [@1, @1, @4, @9, @49] doesn't form a strictly increasing sequence.

    Note

    Neither [n] nor [1,1,1,...,1] are valid solutions. If no valid solution exists, return nil.

    The function "decompose" will take a positive NSNumber n and return the decomposition of N = n2 as [x1 ... xk]

    If n is negative, return nil as well.

    Examples:

    decompose 50 returns "1,3,5,8,49"

    decompose 4  returns nil

* `TelephoneFinder`

    Started in 2008 and recently resurging in popularity, a game known as Number Neighbour or Text Door Neighbor has people sending a text message to phone numbers near their own. Traditionally this was done for numbers ±1, so someone with the phone number 555-555-5555 has neighbors 555-555-5554 and 555- 555-5556.
    We're going to take this a step further and think about neighbors based on a classic phone keypad.

    First, let's take a look at the classic phone keypad:

    123 456 789 0

    We can consider certain numbers adjacent if they appear directly next to or above/below each other. For example, 1 is adjacent to 2 and 4 (and nothing else), while 5 is adjacent to 2, 4, 6, and 8.

    Let's look for phone numbers that are "neighbors" of a given phone number by having any one (and only one) of their digits be off-by-one as a number adjacent to the original.

    By this definition, 555-555-5555 has both its original neighbors but also, e.g., 554-555-5555 and 555-555-5558.

    Problem

    Given a phone number of string from integers length N (1 ≤ N ≤ 10) as a number string (e.g. 555-555-5555 would be passed as "5555555555"), return an array of all phone numbers as number strings that would be considered neighbors of that phone number.

    Examples

    Given: "1"

    Return: ["2", "4"]

    Given: "8675309"

    Return:
    ["5675309", "7675309", "9675309", "0675309", "8375309",
    "8575309", "8975309",
    "8645309", "8685309", "8672309", "8674309", "8676309",
    "8678309", "8675209",
    "8675609", "8675389", "8675306", "8675308"]

    Notes

    Do not wrap around a side of the keypad when finding adjacent numbers. That is, do not consider 6 adjacent to 4 nor 0 adjacent to 2.
    Do not consider numbers that are diagonal to each other adjacent In case input number is negative return nil
    Do not worry about the order of number strings in the array
    being returned

* `FullBinaryTrees`

    A full binary tree is a binary tree where each node has exactly 0 or 2 children.
    Return a list of all possible full binary trees with N nodes.
    Each node of each tree in the answer must have its value set to 0. You may return the final list of trees in any order.

    Example:

    Input: 7

    Output:

    [[0,0,0,null,null,0,0,null,null,0,0], [0,0,0,null,null,0,0,0,0], [0,0,0,0,0,0,0], [0,0,0,0,0,null,null,null,null,0,0], [0,0,0,0,0,null,null,0,0] ]

    Note: trailing null nodes are omitted from the output.
