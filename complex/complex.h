#ifndef COMPLEX_2209
#define COMPLEX_2209

#include <iostream>
#include <vector>

struct Complex 
{
    Complex() {}

    Complex(const Complex& a) = default;

    ~Complex() = default;

    explicit Complex(const double re) : re(re) {};

    Complex(const double re, const double im) : re(re), im(im) {};

    bool operator==(const Complex a);

    bool operator!=(const Complex a) { return !operator==(a); }

    Complex& operator=(const Complex& a);

    Complex& operator+=(const Complex& a);

    Complex& operator+=(const double a);

    Complex& operator-=(const Complex& a);

    Complex& operator-=(const double a);

    Complex& operator*=(const Complex& a);

    Complex& operator*=(const double a);

    Complex& operator/=(const Complex& a);

    Complex& operator/=(const double a);

    Complex& operator-();

    std::vector<Complex> roots(int poW);

    void exponentialForm();

    std::ostream &writeTo(std::ostream &ostr) const;

    std::istream &readFrom(std::istream &istr);

    double re{0.0};
    double im{0.0};
    static const char lBrace{'{'};
    static const char separator{','};
    static const char rBrace{'}'};

    double length();
};

Complex operator+(const Complex &a, const Complex &b);

Complex operator+(const Complex &a, const double b);

Complex operator+(const double a, const Complex &b);

Complex operator-(const Complex &a, Complex b);

Complex operator-(const Complex &a, const double b);

Complex operator-(const double a, const Complex &b);

Complex operator/(const Complex &a, const Complex &b);

Complex operator/(const Complex &a, const double b);

Complex operator/(const double a, const Complex &b);

Complex operator*(const Complex &a, const Complex &b);

Complex operator*(const Complex &a, const double b);

Complex operator*(const double a, const Complex &b);

inline std::ostream &operator<<(std::ostream &ostr, const Complex &a) 
{
    return a.writeTo(ostr);
}

inline std::istream &operator>>(std::istream &istr, Complex &a) 
{
    return a.readFrom(istr);
}

#endif