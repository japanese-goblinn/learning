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

void AbsCompare() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (auto& num : nums)
		cin >> num;
	sort(nums.begin(), nums.end(), [](auto lhs, auto rhs) { return abs(lhs) < abs(rhs); });
	for (const auto& num : nums)
		cout << num << " ";
	cout << "\n";
}

string ToLower(string str) {
	transform(str.begin(), str.end(), str.begin(), [](auto ch) { return tolower(ch); });
	return str;
}

void NoCaseSort() {
	int n;
	cin >> n;
	vector<string> strs(n);
	for (auto& str : strs)
		cin >> str;
	sort(strs.begin(), strs.end(), [](auto lhs, auto rhs) { return ToLower(lhs) < ToLower(rhs); });
	PrintVector(strs);
}

int main(int argc, char const *argv[]) {	
	NoCaseSort();
	return 0;
}
