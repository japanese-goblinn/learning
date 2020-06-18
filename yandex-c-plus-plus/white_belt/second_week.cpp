#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

#define print(x) cout << x << "\n";

void printVector(std::vector<int> v) {
    for (auto e : v) 
        cout << e << " ";
    cout << "\n";
}

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

void AverageTemperature(int n, const vector<int>& days_temperature) {
    auto average = accumulate(days_temperature.begin(), days_temperature.end(), 0) / n;
    vector<int> greater_than_average_indexes;
    for (int i = 0; i < days_temperature.size(); ++i) {
        if (days_temperature[i] <= average)
            continue;
        greater_than_average_indexes.emplace_back(i);
    }
    cout << greater_than_average_indexes.size() << "\n";
    for (auto e : greater_than_average_indexes)
        cout << e << " ";
}

void Worry(vector<int>& q, int i) {
    q[i] = 1;
}

void Quiet(vector<int>& q, int i) {
    q[i] = 0;
}

void Come(vector<int>& q, int k) {
    if (!k)
        return;
    if (k > 0) {
        vector<int> quiet_people(k);
        q.insert(q.end(), quiet_people.begin(), quiet_people.end());
    } else {
        for (int i = -k; i > 0; --i)
            q.pop_back();
    }
}

void WorryCount(const vector<int>& q) {
    int count = 0;
    for (auto e : q) {
        if (!e)
            continue;
        count++;
    }
    print(count);
}

void QueueTask() {
    // 0 - for quiet; 1 - for worried
    vector<int> queue;
    int operations_amount;
    string command;
    int operand;

    cin >> operations_amount;

    while (operations_amount--) {
        cin >> command;
        if (command == "WORRY_COUNT") {
            WorryCount(queue);
        } else {
            cin >> operand;
            if (command == "COME")
                Come(queue, operand);
            else if (command == "QUIET")
                Quiet(queue, operand);
            else if (command == "WORRY")
                Worry(queue, operand);
        }
    }
}

int main(int argc, char const *argv[]) {
    QueueTask();
    return 0;
}
        