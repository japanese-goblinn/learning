#include <iostream>
#include <exception>
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
        if (!denominator)
            throw invalid_argument("");
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

Rational operator /(const Rational& lhs, const Rational& rhs) {
    if (!rhs.Numerator())
        throw domain_error("");
    return {
        lhs.Numerator() * rhs.Denominator(),
        lhs.Denominator() * rhs.Numerator()
    };
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        // return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
