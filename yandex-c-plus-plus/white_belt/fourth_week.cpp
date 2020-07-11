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

int main(int argc, char const *argv[]) {  
    LectureTitle title = {
      Specialization("C++"),
      Course("White belt"),
      Week("4th")
    }; 
    return 0;
}