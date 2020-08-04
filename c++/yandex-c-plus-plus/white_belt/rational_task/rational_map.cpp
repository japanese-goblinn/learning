#include <iostream>
#include <numeric>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
private:
    int p;
    int q;
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        if (!numerator) {
            p = 0;
            q = 1;
            return;
        }
        p = abs(numerator);
        q = abs(denominator);
        auto d = gcd(p, q);
        p /= d;
        q /= d;
        if (denominator < 0 && numerator < 0)
            return;
        if (denominator < 0 || numerator < 0)
            p *= -1;
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }
};

ostream& operator <<(ostream& output, const Rational& r) {
    output << r.Numerator() << "/" << r.Denominator();
    return output;
}

bool operator ==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

bool operator <(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator())
        return lhs.Numerator() < rhs.Numerator();
    return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            // return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            // return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            // return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
