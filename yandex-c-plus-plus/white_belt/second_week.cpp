#include <iostream>
#include <string>
#include <vector>

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

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> res;
    for (auto w : words) {
        if (!IsPalindrom(w) || w.length() < minLength) {
            continue;
        }
        res.emplace_back(w);
    }
    return res;
} 


int main(int argc, char const *argv[]) {
    auto res = PalindromFilter({"abacaba", "aba"}, 5);
    for (auto w : res) {
        cout << w << "\n";
    }
    return 0;
}
        