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
    void FormatData(string& output, const vector<string>& v) {
        if (v.size() == 1) {
            output = v.front();
            return;
        }
        if (v.size() == 2) {
            output = v[0] + " (" + v[1] + ")";
            return;
        }
        output = v[0] + " (";
        for (int i = 1; i < v.size() - 1; ++i) {
            output += v[i] + ", ";
        }
        output += v.back() + ")";
    }
    void NamesAdd(const string& name, vector<string>& v) {
        if (name.empty())
            return;
        if (v.empty()) {
            v.emplace_back(name);
            return;
        }
        if (v.back() == name)
            return;
        v.emplace_back(name);
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
    string GetFullNameWithHistory(int year) {
        vector<string> first_names, last_names;
        for (const auto& kv : data) {
            if (kv.first > year)
                break;
            this->NamesAdd(kv.second.first_name, first_names);
            this->NamesAdd(kv.second.last_name, last_names);
        }
        if (first_names.empty() && last_names.empty())
            return "Incognito";
        reverse(first_names.begin(), first_names.end());
        reverse(last_names.begin(), last_names.end());
        if (first_names.empty()) {
            string last_name;
            this->FormatData(last_name, last_names);
            return last_name + " with unknown first name";
        } else if (last_names.empty()) {
            string first_name;
            this->FormatData(first_name, first_names);
            return first_name + " with unknown last name";
        } else {
            string first_name, last_name;
            this->FormatData(first_name, first_names);
            this->FormatData(last_name, last_names);
            return first_name + " " + last_name;
        }
    }
};

int main(int argc, char const *argv[]) {    
    Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
    return 0;
}
