#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

#define print(x) cout << x << "\n";

void printVector(vector<string>& v) {
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

void Add(vector<vector<string>>& tasks, string task, int day) {
    tasks[day - 1].emplace_back(task);
}

void Dump(const vector<vector<string>>& tasks, int day) {
    cout << tasks[day - 1].size() << " ";
    for (auto task : tasks[day - 1])
        cout << task << " ";
    cout << "\n";
}

void Next(const vector<int>& days_in_months, vector<vector<string>>& tasks, int& current_month) {
    if (++current_month >= days_in_months.size())
        current_month = 0;
    int current_amount_of_days = tasks.size();
    int new_amount_of_days = days_in_months[current_month];
    if (new_amount_of_days < current_amount_of_days) {
        auto diff = current_amount_of_days - new_amount_of_days;
        for (int i = tasks.size() - diff; i < tasks.size(); ++i)
            tasks[new_amount_of_days - 1].insert(tasks[new_amount_of_days - 1].end(), tasks[i].begin(), tasks[i].end());
    }
    tasks.resize(new_amount_of_days);
}

void MonthlyTasks() {
    vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int current_month = 0;
    vector<vector<string>> current_month_tasks(days_in_months[current_month]);

    string command;

    int day;
    string task;

    int operations_count;
    cin >> operations_count;
    while (operations_count--) {
        cin >> command;
        if (command == "NEXT") {
            Next(days_in_months, current_month_tasks, current_month);
        } else if (command == "DUMP") {
            cin >> day;
            Dump(current_month_tasks, day);
        } else if (command == "ADD") {
            cin >> day;
            cin >> task;
            Add(current_month_tasks, task, day);
        }
    }
}

int main(int argc, char const *argv[]) {
    MonthlyTasks();
    return 0;
}
        