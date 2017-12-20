#include "rational.h"
#include <cmath>


static int gcd(int lhs, int rhs)
{
    while (rhs) {
        rhs ^= lhs ^= rhs ^= lhs %= rhs;
    }
    return abs(rhs);
}

Rational& Rational::normalize() 
{
    int nod = gcd(num, den);
    num /= nod;
    den /= nod;
    return *this;
}

bool Rational::operator==(const Rational& rhs)
{
    return num == rhs.num && den == rhs.den;
}

bool Rational::operator!=(const Rational& rhs)
{
    return !operator==(rhs);
}

bool Rational::operator<(const Rational& rhs)
{
    return num * rhs.den < den * rhs.num;
}

bool Rational::operator>(const Rational& rhs)
{
    return num * rhs.den > den * rhs.num;
}

bool Rational::operator<=(const Rational& rhs) 
{
    return operator<(rhs) || operator==(rhs);
}

bool Rational::operator>=(const Rational& rhs) 
{
    return operator>(rhs) || operator==(rhs);
}

Rational& Rational::operator-() 
{
    num = -num;
    return *this;
}

Rational& Rational::operator+=(const Rational& rhs) 
{
    int nod = gcd(rhs.den, den);
    int nok = rhs.den / nod * den;
    int mult0 = nok / den;
    int mult1 = nok / rhs.den;
    den = nok;
    num *= mult0;
    num += rhs.num * mult1;
    normalize();
    return *this;
}

Rational& Rational::operator+=(const int rhs) 
{
    return operator+=(Rational(rhs));
}

Rational& Rational::operator-=(const Rational& rhs) 
{
    Rational c(rhs);
    return operator+=(-c);
}

Rational& Rational::operator-=(const int rhs) 
{
    Rational c(rhs);
    return operator+=(-c);
}

Rational& Rational::operator*=(const Rational& rhs) 
{
    num *= rhs.num;
    den *= rhs.den;
    normalize();
    return *this;
}

Rational& Rational::operator*=(const int rhs) 
{
    return operator*=(Rational(rhs));
}

Rational& Rational::operator/=(const Rational& rhs) 
{
    return operator*=(Rational(rhs.den, rhs.num));
}

Rational& Rational::operator/=(const int rhs) 
{
    return operator*=(Rational(1, rhs));
}

Rational operator+(const Rational& lhs, const Rational& rhs) 
{
    Rational c(lhs);
    c += rhs;
    return c;
}

Rational operator-(const Rational& lhs, const Rational& rhs) 
{
    Rational c(lhs);
    c -= rhs;
    return c;
}

Rational operator*(const Rational& lhs, const Rational& rhs) 
{
    Rational c(lhs);
    c *= rhs;
    return c;
}

Rational operator/(const Rationa& lhs, const Rational& rhs) 
{
    Rational c(lhs);
    c /= rhs;
    return c;
}

Rational operator+(const Rational& lhs, const int rhs) 
{
    return operator+(lhs, Rational(rhs));
}

Rational operator-(const Rational& lhs, const int rhs) 
{
    return operator-(lhs, Rational(rhs));
}

Rational operator*(const Rational& lhs, const int rhs) 
{
    return operator*(lhs, Rational(rhs));
}

Rational operator/(const Rational& lhs, const int rhs) 
{
    return operator/(lhs, Rational(rhs));
}

Rational operator+(const int lhs, const Rational& rhs) 
{
    return operator+(Rational(lhs), rhs);
}

Rational operator-(const int lhs, const Rational &rhs) 
{
    return operator-(Rational(lhs), rhs);
}

Rational operator*(const int lhs, const Rational& rhs) 
{
    return operator*(Rational(lhs), rhs);
}

Rational operator/(const int lhs, const Rational& rhs) 
{
    return operator/(Rational(lhs), rhs);
}

std::ostream& Rational::writeTo(std::ostream& ost) const 
{
    ost << num << sep0 << den;
    return ost;
}

std::istream& Rational::readFrom(std::istream& ist) 
{
    char sep(0);
    int numen(0);
    int denom(0);
    ist >> numen >> sep >> denom;
    if (ist && 0 != den) {
        if (Rational::sep0 == sep || Rational::sep1 == sep) {
            num = numen;
            den = denom;
        } 
    } else {
        ist.setstate(std::ios_base::failbit);
    }    
    return ist;
}