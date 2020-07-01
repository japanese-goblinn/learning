#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define print(x) cout << x << "\n";

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

int main(int argc, char const *argv[]) {	
	AbsCompare();
	return 0;
}
