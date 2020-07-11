#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define print(x) cout << x << "\n";

template <typename T>
void PrintVector(const vector<T>& v) {
    for (const auto& e : v) 
        cout << e << " ";
    cout << "\n";
}

int main(int argc, char const *argv[]) {  
  vector<int> v = {1, 2, 3};
  PrintVector(v);  
  return 0;
}