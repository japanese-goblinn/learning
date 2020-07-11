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
        return v;
    }
    void Invert() {
        if (operation == '+')
          operation = '-';
        else if (operation == '-')
          operation = '+';
    }
};

class Function {
  vector<FunctionPart> parts;

  public:
    double Apply(double value) const {
        for (const auto& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert() {
        for (auto& part : parts) {
            part.Invert();
        }
    }
    void AddPart(char operation, double value) {
        parts.push_back({operation, value});
    }
};

int main() {
    return 0;
}
