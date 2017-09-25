#ifndef RATIONAL_2509
#define RATIONAL_2509
#include <iostream>
class Rational {
public:
	Rational() {};
	Rational(const Rational& a) = default;
	Rational(const int num) : num(num) {};
	~Rational() = default;
	explicit Rational(const int num, const int den) : num(num), den(den) { normalize(); };
	bool operator==(const Rational& a);
	bool operator!=(const Rational& a) { return !operator==(a); }
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
	std::ostream& writeTo(std::ostream& ost)const;
private:
	Rational& normalize();
	int num{ 0 },
		den{ 1 };
	static const char sep0{ '/' };
	static const char sep1{ ':' };
};

Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);

Rational operator+(const Rational& a, const int b);
Rational operator-(const Rational& a, const int b);
Rational operator*(const Rational& a, const int b);
Rational operator/(const Rational& a, const int b);

inline std::ostream& operator<<(std::ostream& ost, const Rational& a) {
	return a.writeTo(ost);
}
inline std::istream& operator>>(std::istream& ist, Rational& a) {
	return a.readFrom(ist);
}
#endif