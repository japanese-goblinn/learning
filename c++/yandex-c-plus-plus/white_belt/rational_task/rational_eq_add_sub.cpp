#include <iostream>
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

// Реализуйте для класса Rational операторы ==, + и -

Rational operator +(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator())
        return {
            lhs.Numerator() + rhs.Numerator(), 
            rhs.Denominator()
        };
    return {
        lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), 
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator -(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator())
        return {
            lhs.Numerator() - rhs.Numerator(), 
            rhs.Denominator()
        };
    return {
        lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), 
        lhs.Denominator() * rhs.Denominator()
    };
}

bool operator ==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
