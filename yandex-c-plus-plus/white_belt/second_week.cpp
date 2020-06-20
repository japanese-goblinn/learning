#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <map>
#include <set>

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

string IsAnagrams(string a, string b) {
    if (a.size() != b.size())
        return "NO";
    map<char, int> a_count, b_count;
    for (int i = 0; i < a.size(); ++i) {
        a_count[a[i]]++;
        b_count[b[i]]++;
    }
    return a_count == b_count ? "YES" : "NO";
}

void Dump(map<string, string>& capitals) {
    if (!capitals.size()) {
        print("There are no countries in the world");
        return;
    }
    for (auto& kv : capitals) {
        cout << kv.first << "/" << kv.second << " ";
    }
    cout << "\n";
}

void About(map<string, string>& capitals, string country) {
    if (capitals[country].empty()) {
        capitals.erase(country);
        cout << "Country " << country << " doesn't exist" << "\n";
        return;
    }
    cout << "Country " << country << " has capital " << capitals[country] << "\n";
}

void ChangeCapital(map<string, string>& capitals, string country, string new_capital) {
    if (capitals[country].empty()) {
        capitals[country] = new_capital;
        cout << "Introduce new country " << country << " with capital " << new_capital << "\n";
        return;
    }
    if (capitals[country] == new_capital) {
        cout << "Country " << country << " hasn't changed its capital\n";
        return;
    }
    auto old_capital = capitals[country];
    capitals[country] = new_capital;
    cout << "Country " << country << " has changed its capital from " << old_capital << 
        " to " << new_capital << "\n";
}

void Rename(map<string, string>& capitals, string old_country_name, string new_country_name) {
    if (capitals[old_country_name].empty()) {
        capitals.erase(old_country_name);
        print("Incorrect rename, skip");
        return;
    }
    if (new_country_name == old_country_name || !capitals[new_country_name].empty()) {
        print("Incorrect rename, skip");
        return;
    }
    auto capital = capitals[old_country_name];
    capitals.erase(old_country_name);
    capitals[new_country_name] = capital;
    cout << "Country " << old_country_name << " with capital " << 
        capital << " has been renamed to " << new_country_name << "\n";
}

void CapitalsInfo() {
    map<string, string> capitals;

    int queries_amount;
    cin >> queries_amount;

    string command;
    string country;

    while (queries_amount--) {
        cin >> command;
        if (command == "DUMP") {
            Dump(capitals);
        } else if (command == "ABOUT") {
            cin >> country;
            About(capitals, country);
        } else if (command == "RENAME") {
            cin >> country;
            string new_country_name;
            cin >> new_country_name;
            Rename(capitals, country, new_country_name);
        } else if (command == "CHANGE_CAPITAL") {
            cin >> country;
            string new_capital;
            cin >> new_capital;
            ChangeCapital(capitals, country, new_capital);
        }
    }
}

void AllBused(const map<string, vector<string>>& bus_stops) {
    if (!bus_stops.size()) {
        print("No buses");
        return;
    }
    for (auto& kv : bus_stops) {
        cout << "Bus " << kv.first << ": ";
        for (auto stop : kv.second)
            cout << stop << " ";
        cout << "\n";
    }
}

void StopsForBus(map<string, vector<string>>& bus_stops, map<string, vector<string>>& buses, string bus) {
    if (!bus_stops.count(bus)) {
        print("No bus");
        return;
    }
    auto stops = bus_stops[bus];
    for (auto stop : stops) {
        if (buses[stop].size() == 1) {
            cout << "Stop " << stop << ": no interchange" << "\n";
            continue;
        }
        cout << "Stop " << stop << ": ";
        for (auto bus_i : buses[stop]) {
            if (bus_i == bus)
                continue;
            cout << bus_i << " ";
        }
        cout << "\n";
    }
}

void BusesForStop(map<string, vector<string>>& bus_stops, map<string, vector<string>>& buses, string stop) {
    if (!buses.count(stop)) {
        print("No stop");
        return;
    }
    auto stop_buses = buses[stop];
    for (auto bus : stop_buses)
        cout << bus << " ";
    cout << "\n";
}

void NewBus(map<string, vector<string>>& bus_stops, map<string, vector<string>>& buses, string bus, int bus_count) {
    string stop_name;
    while (bus_count--) {
        cin >> stop_name;
        bus_stops[bus].emplace_back(stop_name);
        buses[stop_name].emplace_back(bus);
    }
}

void BusStopsOne() {
    map<string, vector<string>> bus_stops;
    map<string, vector<string>> buses;
    
    int queries_amount;
    cin >> queries_amount;

    string command;

    while (queries_amount--) {
        cin >> command;
        if (command == "ALL_BUSES") {
            AllBused(bus_stops);
        } else if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            StopsForBus(bus_stops, buses, bus);
        } else if (command == "NEW_BUS") {
            string bus;
            cin >> bus;
            int bus_count;
            cin >> bus_count;
            NewBus(bus_stops, buses, bus, bus_count);
        } else if (command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            BusesForStop(bus_stops, buses, stop);
        }
    }
}

void BusStopsTwo() {
    map<vector<string>, int> routes;
    int queries_amount;
    cin >> queries_amount;
    int routes_count = 0;
    int stops_amount;
    string stop;
    while (queries_amount--) {
        cin >> stops_amount;
        vector<string> stops;
        while (stops_amount--) {
            cin >> stop;
            stops.emplace_back(stop);
        }
        if (!routes.count(stops)) {
            routes[stops] = ++routes_count;
            cout << "New bus " << routes_count << "\n";
        } else {
            cout << "Already exists for " << routes[stops] << "\n";
        }
    }
}

void UniqueStrings() {
    int amount;
    cin >> amount;
    string str;
    set<string> unique_strings;
    while (amount--) {
        cin >> str;
        unique_strings.insert(str);
    }
    print(unique_strings.size());
}

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> uq_values;
    for (auto& kv : m)
        uq_values.insert(kv.second);
    return uq_values;
}

void Synonyms() {
    map<string, set<string>> synonyms;
    int queries_amount;
    cin >> queries_amount;
    string command;
    while (queries_amount--) {
        cin >> command;
        if (command == "ADD") {
            string first, second;
            cin >> first;
            cin >> second;
            synonyms[first].insert(second);
            synonyms[second].insert(first);
        } else if (command == "COUNT") {
            string word;
            cin >> word;
            print(synonyms[word].size());
        } else if (command == "CHECK") {
            string first, second;
            cin >> first;
            cin >> second;
            if (synonyms[first].count(second)) {
                print("YES");
            } else {
                print("NO");
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    Synonyms();
    return 0;
}
        