#include "rational.h"
#include <cmath>

int gcd(int a, int b) {
    while (b) b ^= a ^= b ^= a %= b;
    return abs(a);
}



Rational &Rational::normalize() {
    int nod = gcd(num, den);
    num /= nod;
    den /= nod;
    return *this;
}

bool Rational::operator==(const Rational &a) {
    return num == a.num && den == a.den;
}

bool Rational::operator<(const Rational &a) {

}

bool Rational::operator>(const Rational &a) {

}

bool Rational::operator<=(const Rational &a) {

}

bool Rational::operator>=(const Rational &a) {

}

Rational &Rational::operator-() {
    num = -num;
    return *this;
}

Rational &Rational::operator+=(const Rational &a) {
    int nod = gcd(a.den, den);
    int nok = a.den / nod * den;
    int mult0 = nok / den;
    int mult1 = nok / a.den;
    den = nok;
    num *= mult0;
    num += a.num * mult1;
    normalize();
    return *this;
}

Rational &Rational::operator+=(const int a) {
    return operator+=(Rational(a));
}

Rational &Rational::operator-=(const Rational &a) {
    Rational c(a);
    return operator+=(-c);
}

Rational &Rational::operator-=(const int a) {
    Rational c(a);
    return operator+=(-c);
}

Rational &Rational::operator*=(const Rational &a) {
    num *= a.num;
    den *= a.den;
    normalize();
    return *this;
}

Rational &Rational::operator*=(const int a) {
    return operator*=(Rational(a));
}

Rational &Rational::operator/=(const Rational &a) {
    return operator*=(Rational(a.den, a.num));
}

Rational &Rational::operator/=(const int a) {
    return operator*=(Rational(1, a));
}

Rational operator+(const Rational &a, const Rational &b) {
    Rational c(a);
    c += b;
    return c;
}

Rational operator-(const Rational &a, const Rational &b) {
    Rational c(a);
    c -= b;
    return c;
}

Rational operator*(const Rational &a, const Rational &b) {
    Rational c(a);
    c *= b;
    return c;
}

Rational operator/(const Rational &a, const Rational &b) {
    Rational c(a);
    c /= b;
    return c;
}

Rational operator+(const Rational &a, const int b) {
    return operator+(a, Rational(b));
}

Rational operator-(const Rational &a, const int b) {
    return operator-(a, Rational(b));
}

Rational operator*(const Rational &a, const int b) {
    return operator*(a, Rational(b));
}

Rational operator/(const Rational &a, const int b) {
    return operator/(a, Rational(b));
}

Rational operator+(const int a, const Rational &b) {
    return operator+(Rational(a), b);
}

Rational operator-(const int a, const Rational &b) {
    return operator-(Rational(a), b);
}

Rational operator*(const int a, const Rational &b) {
    return operator*(Rational(a), b);
}

Rational operator/(const int a, const Rational &b) {
    return operator/(Rational(a), b);
}

std::ostream &Rational::writeTo(std::ostream &ost) const {
    ost << num << sep0 << den;
    return ost;
}

std::istream &Rational::readFrom(std::istream &ist) {
    char sep(0);
    int numen(0);
    int denom(0);
    if (ist >> numen >> sep >> denom) {
        if (Rational::sep0 == sep || Rational::sep1 == sep) {
            num = numen;
            den = denom;
        } else
            ist.setstate(std::ios_base::failbit);
    }
    return ist;
}
