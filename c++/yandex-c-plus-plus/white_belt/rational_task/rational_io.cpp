#include <iostream>
#include <sstream>
#include <numeric>
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

bool operator ==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

// Реализуйте для класса Rational операторы << и >>

istream& operator >>(istream& input, Rational& r) {
    int p, q;
    if (!(input >> p, input.ignore(1), input >> q)) {
        return input;
    }
    r = {p, q};
    return input;
}

ostream& operator <<(ostream& output, const Rational& r) {
    output << r.Numerator() << "/" << r.Denominator();
    return output;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            // return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            // return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            // return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            // return 4;
        }
    }
    cout << "OK" << endl;
    return 0;
}
