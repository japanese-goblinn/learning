#include <iostream>

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


int main(int argc, char const *argv[]) {
    cout << Factorial(4) << "\n";
    return 0;
}
