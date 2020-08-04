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

bool operator ==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

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

Rational operator *(const Rational& lhs, const Rational& rhs) {
    return {
        lhs.Numerator() * rhs.Numerator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator /(const Rational& lhs, const Rational& rhs) {
    if (!rhs.Numerator())
        throw domain_error("");
    return {
        lhs.Numerator() * rhs.Denominator(),
        lhs.Denominator() * rhs.Numerator()
    };
}

istream& operator >>(istream& input, Rational& r) {
    int p, q;
    if (!(input >> p, input.ignore(1), input >> q))
        return input;
    r = {p, q};
    return input;
}

ostream& operator <<(ostream& output, const Rational& r) {
    output << r.Numerator() << "/" << r.Denominator();
    return output;
}

int main() {
    string command;
    Rational r1, r2;
    try {
        cin >> r1 >> command >> r2;
        if (command == "+")
            cout << r1 + r2;
        else if (command == "-")
            cout << r1 - r2;
        else if (command == "*")
            cout << r1 * r2;
        else if (command == "/")
            cout << r1 / r2;
    } catch (invalid_argument&) {
        cout << "Invalid argument" << endl;
    } catch (domain_error&) {
        cout << "Division by zero" << endl;
    }
    return 0;
}