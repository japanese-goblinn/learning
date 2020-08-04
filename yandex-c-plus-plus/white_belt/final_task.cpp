#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <exception>
#include <iomanip>
#include <algorithm>
using namespace std;

#define print(x) std::cout << x << std::endl;

template <typename T>
void PrintVector(const vector<T>& v) {
    for (int i = 0; i < v.size() - 1; ++i)
      cout << v[i] << " ";
    cout << v[v.size() - 1] << endl;
}

class Date {
private:
  int year;
  int month;
  int day;
public:
  Date() {}

  Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
  }

  int GetYear() const {
    return year;
  }

  int GetMonth() const {
    return month;
  }

  int GetDay() const {
    return day;
  }
};

bool operator <(const Date& lhs, const Date& rhs) {
  if (lhs.GetYear() != rhs.GetYear())
    return lhs.GetYear() < rhs.GetYear();
  if (lhs.GetMonth() != rhs.GetMonth())
    return lhs.GetMonth() < rhs.GetMonth();
  return lhs.GetDay() < rhs.GetDay();
}

int ParseDateComponent(istringstream& input) {
  int c;
  if (!(input >> c))
    throw invalid_argument("");
  if (input.peek() != '-' && input.peek() != -1)
    throw invalid_argument("");
  input.ignore(1);
  return c;
}

istream& operator >>(istream& input, Date& date) {
  string raw_string;
  input >> raw_string;
  int y, m, d;
  try {
    istringstream ss(raw_string);
    y = ParseDateComponent(ss);
    m = ParseDateComponent(ss);
    d = ParseDateComponent(ss);
    date = {y, m, d};
  } catch (invalid_argument&) {
    throw invalid_argument("Wrong date format: " + raw_string);
  }
  if (m < 1 || m > 12)  
    throw invalid_argument("Month value is invalid: " + to_string(m));
  if (d < 1 || d > 31)
    throw invalid_argument("Day value is invalid: " + to_string(d));
  return input;
}

class Database {
private:
  map<Date, vector<string>> db;
public:
  void AddEvent(const Date& date, const string& event) {
    auto& events = db[date];
    if (find(events.begin(), events.end(), event) != events.end())
      return;
    events.emplace_back(event);
  } 

  bool DeleteEvent(const Date& date, const string& event) {
    if (!db.count(date))
      return false;
    auto& events = db[date];
    if (find(events.begin(), events.end(), event) == events.end())
      return false;
    events.erase(remove(events.begin(), events.end(), event));
    return true;
  }

  int DeleteDate(const Date& date) {
    if (!db.count(date))
      return 0;
    auto res = db[date].size();
    db.erase(date);
    return res;
  }

  void Find(const Date& date) const {
    if (!db.count(date))
      return;
    auto v = db.at(date);
    if (!v.size())
      return;
    sort(v.begin(), v.end());
    for (auto& e : v) {
      print(e);
    }
  }

  void PrintDate(const Date& date) const {
    cout << setfill('0') 
           << setw(4) << date.GetYear() << "-"
           << setw(2) << date.GetMonth() << "-"
           << setw(2) << date.GetDay() << " ";
  }
  
  void Print() const {
    for (const auto& kv : db) {
      if (kv.first.GetYear() < 0)
        continue;
      const auto& date = kv.first;
      auto events = kv.second;
      if (!events.size())
        return;
      sort(events.begin(), events.end());
      for (auto& e : events) {
        this->PrintDate(date);
        print(e);
      }
    }
  }
};

int main() {
  Database db;
  string raw_command;
  while (getline(cin, raw_command)) {
    string command, event;
    Date date;
    istringstream s(raw_command);
    s >> command;
    if (command.empty())
      continue;
    if (command == "Add") {
      try {
        s >> date >> event;
        db.AddEvent(date, event);
      } catch (invalid_argument& e) {
        print(e.what());
      }
    } else if (command == "Del") {
      try {
        s >> date;
        if (s >> event) {
          if (db.DeleteEvent(date, event)) {
            print("Deleted successfully");
          } else {
            print("Event not found");
          }
        } else {
          auto num = db.DeleteDate(date);
          print("Deleted " + to_string(num) + " events");
        }
      } catch (invalid_argument& e) {
        print(e.what());
      }
    } else if (command == "Find") {
      try {
        s >> date;
        db.Find(date);
      } catch (invalid_argument& e) {
        print(e.what());
      }
    } else if (command == "Print") {
      db.Print();
    } else {
      cout << "Unknown command: " << command << endl;
    }
  }
  return 0;
}