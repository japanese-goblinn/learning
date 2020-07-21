#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

#define print(x) cout << x << "\n";

template <typename T>
void PrintVector(const vector<T>& v) {
    for (const auto& e : v) 
        cout << e << " ";
    cout << "\n";
}

struct Specialization {
    string value;

    explicit Specialization(string v) {
        value = v;
    }
};

struct Course {
    string value;

    explicit Course(string v) {
        value = v;
    }
};

struct Week {
    string value;

    explicit Week(string v) {
        value = v;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(Specialization s, Course c, Week w) {
        specialization = s.value;
        course = c.value;
        week = w.value;
    }
};

struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

class FunctionPart {
    char operation;
    double value;

    public:
      FunctionPart(char operation, double value) {
          this->operation = operation;
          this->value = value;
      }

      double Apply(double v) const {
          if (operation == '+')
            v += value;
          else if (operation == '-')
            v -= value;
          else if (operation == '*')
            v *= value;
          else if (operation == '/')
            v /= value;
          return v;
      }

      void Invert() {
          if (operation == '+')
            operation = '-';
          else if (operation == '-')
            operation = '+';
          else if (operation == '*')
            operation = '/';
          else if (operation == '/')
            operation = '*';
      }
};

class Function {
    vector<FunctionPart> parts;

    public:
      double Apply(double value, double kek) const {
          for (const auto& part : parts) {
              value = part.Apply(value);
          }
          return value;
      }

      void Invert() {
          for (auto& part : parts) {
              part.Invert();
          }
          reverse(parts.begin(), parts.end());
      }

      void AddPart(char operation, double value) {
          parts.emplace_back(FunctionPart{operation, value});
      }
};

void ReadFromFile(string file_name) {
  ifstream input(file_name);
  string file_string;
  while (getline(input, file_string, '\n')) {
    cout << file_string << "\n";
  }
}

void ReadFromFileAndWriteToFile(string r_file, string w_file) {
  ifstream input(r_file);
  string file_string;
  ofstream output(w_file);
  while (getline(input, file_string, '\n')) {
    output << file_string + "\n";
  }
}

void FloatPrint() {
  ifstream reader("input.txt");
  float s;
  cout << fixed << setprecision(3);
  while (reader >> s) {
    cout << s << "\n";
  }
}

void Table() {
  ifstream r("input.txt");
  if (!r.is_open())
    cout << "Fail!" << endl;
  int n, m;
  int num;
  r >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      r >> num;
      r.ignore(1);
      cout << setw(10) << num;
      if (j == m - 1)
        break;
      cout << " ";
    }
    if (i == n - 1)
        break;
    cout << endl;
  }
}

struct Strudent {
  string first_name;
  string last_name;
  int birth_day;
  int birth_month;
  int birth_year;
};

void StrudentsList() {
  vector<Strudent> students;
  int students_amount;
  cin >> students_amount;
  int n = students_amount - 1;
  string first_name, last_name;
  int day, month, year;
  while (students_amount--) {
    cin >> first_name >> last_name >> day >> month >> year;
    students.emplace_back(Strudent{first_name, last_name, day, month, year});
  }
  int requests_amount;
  cin >> requests_amount;
  string command;
  int num = 0;
  while (requests_amount--) {
    cin >> command >> num;
    if (command == "name") {
      --num;
      if (num < 0 || num > n) {
        cout << "bad request\n";
        continue;
      } 
      auto s = students[num];
      cout << s.first_name << " " << s.last_name << endl;
    } else if (command == "date") {
      --num;
      if (num < 0 || num > n) {
        cout << "bad request\n";
        continue;
      } 
      auto s = students[num];
      cout << s.birth_day << "." << s.birth_month << "." << s.birth_year << endl;
    } else {
      cout << "bad request\n";
    }
  }
}

int main() {
  StrudentsList();
  return 0;
}
