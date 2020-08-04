#include <iostream>
#include <vector>

int gcd(int a, int b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void PrintBinary(int number) {
    std::vector<int> v;
    while (number > 0) {
        v.emplace_back(number % 2);
        number /= 2;
    }
    for (int i = v.size() - 1; i >= 0; --i) {
        std::cout << v[i];
    }
}

int main() {
    std::cout << gcd(10, 25) << "\n";
    PrintBinary(32);
    std::cout << std::endl;
    return 0;
}
