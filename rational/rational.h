#ifndef RATIONAL_2509
#define RATIONAL_2509

#include <iostream>
#include <stdexcept>


class Rational 
{
public:
    Rational() = default;

    Rational(const Rational &a) = default;

    explicit Rational(const int num) : num(num) {};

    ~Rational() = default;

    explicit Rational(const int num, const int den) : num(num), den(den)
    {
        if (den == 0)
            throw std::invalid_argument("Zero division");
    };

    bool operator==(const Rational& a);

    bool operator!=(const Rational& a);

    bool operator<(const Rational& a);

    bool operator>(const Rational& a);

    bool operator<=(const Rational& a);

    bool operator>=(const Rational& a);

    Rational& operator+=(const Rational& a);

    Rational& operator+=(const int a);

    Rational& operator-=(const Rational& a);

    Rational& operator-=(const int a);

    Rational& operator*=(const Rational& a);

    Rational& operator*=(const int a);

    Rational& operator/=(const Rational& a);

    Rational& operator/=(const int a);

    Rational& operator-();

    std::istream& readFrom(std::istream& ist);

    std::ostream& writeTo(std::ostream& ost) const;

    Rational& normalize();

private:
    int num{0},
            den{1};
    static const char sep0{'/'};
    static const char sep1{':'};
};

Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);
Rational operator+(const Rational& a, const int b);
Rational operator-(const Rational& a, const int b);
Rational operator*(const Rational& a, const int b);
Rational operator/(const Rational& a, const int b);
Rational operator+(const int a, const Rational& b);
Rational operator-(const int a, const Rational& b);
Rational operator*(const int a, const Rational& b);
Rational operator/(const int a, const Rational& b);

inline std::ostream& operator<<(std::ostream& ost, const Rational& a) 
{
    return a.writeTo(ost);
}

inline std::istream& operator>>(std::istream& ist, Rational& a) 
{
    return a.readFrom(ist);
}

#endif