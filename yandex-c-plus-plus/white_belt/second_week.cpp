#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define print(x) cout << x << "\n";

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
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == s[s.length() - 1 - i]) {
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

void UpdateIfGreater(int first, int& second) {
    if (first <= second) {
        return;
    }
    second = first;
}

void MoveStrings(vector<string>& source, vector<string>& destination) {
    destination.insert(destination.end(), source.begin(), source.end());
    source.clear();
}

void Reverse(vector<int>& v) {
    auto v_copy = v;
    v.clear();
    for (int i = v_copy.size() - 1; i >= 0; --i) {
        v.emplace_back(v_copy[i]);
    }
}

vector<int> Reversed(const vector<int>& v) {
    vector<int> v_reversed;
    for (int i = 0; i < v.size(); ++i) {
        v_reversed.emplace_back(v[v.size() - 1 - i]);
    }
    return v_reversed;
}

int main(int argc, char const *argv[]) {
    std::vector<int> a = {1, 2, 3, 5, 4};
    auto c = Reversed(a);
    for (auto e : c)
        print(e);
    return 0;
}
        