#include <iostream>
#include <string>

using namespace std;

int Factorial(int num) {
    if (num <= 1) {
        return 1;
    }
    int res = num;
    for (int i = 2; i < num; ++i) {
        res *= i;
    }
    return res;
}

bool IsPalindrom(string s) {
    if (s.empty()) {
        return true;
    }
    int l = s.length();
    for (int i = 0, j = l - 1; i < l / 2 && j >= 0; ++i, --j) {
        if (s[i] == s[j]) {
            continue;
        }
        return false;
    }
    return true;
}


int main(int argc, char const *argv[]) {
    cout << IsPalindrom("X") << "\n";
    return 0;
}
        