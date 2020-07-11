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

struct PersonData {
    string first_name;
    string last_name;
};

class Person {
private:
    map<int, PersonData> data;
    void FindData(string& first_name, string& last_name, int year) {
        for (const auto& kv : data) {
            if (kv.first > year)
                break;
            if (!kv.second.first_name.empty()) 
                first_name = kv.second.first_name;
            if (!kv.second.last_name.empty())
                last_name = kv.second.last_name;
        }
    }
public:
    void ChangeFirstName(int year, const string& first_name) {
        data[year].first_name = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        data[year].last_name = last_name;
    }
    string GetFullName(int year) {
        string first_name, last_name;
        this->FindData(first_name, last_name, year);
        if (first_name.empty() && last_name.empty())
            return "Incognito";
        if (first_name.empty())
            return last_name + " with unknown first name";
        else if (last_name.empty())
            return first_name + " with unknown last name";
        else
            return first_name + " " + last_name;
    }
};

class SortedStrings {
private:
    vector<string> strings;
public:
    void AddString(const string& s) {
        strings.emplace_back(s);
    }
    vector<string> GetSortedStrings() {
        sort(strings.begin(), strings.end());
        return strings;
    }
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {    
  SortedStrings strings;
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);
  strings.AddString("second");
  PrintSortedStrings(strings);
  return 0;
}
