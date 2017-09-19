#include <iostream>
#include <sstream>
using namespace std;
double eps(1e-14);
struct Complex {
	Complex() {}
	explicit Complex(const double real);
	~Complex() = default;
	Complex(const double real, const double imaginary);
	bool operator==(const Complex& rhs) const { return (abs(re - rhs.re) < eps) && (abs(im - rhs.im) < eps); }
	bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
	Complex& operator+=(const Complex& rhs) {
		re += rhs.re;
		im += rhs.im;
		return *this;
	}
	Complex& operator=(const Complex& rhs) {
		re = rhs.re;
		im = rhs.im;
		return *this;
	}
	Complex& operator-=(const Complex& rhs) {
		re += rhs.re;
		im += rhs.im;
		return *this;
	}
	Complex& operator*=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	Complex& operator*=(const double rhs) { return operator*=(rhs); }
	Complex& operator/=(const Complex& rhs) {
	if (abs(rhs.im) < eps && abs(rhs.re) < eps) {
		cout << "division by zero";
	}
	double ansr(0.0);
	double ansi(0.0);
	double den = rhs.re * rhs.re + rhs.im * rhs.im;
	ansr = (rhs.re * this->re + rhs.im * this->im) / den;
	ansi = (rhs.re * this->im - rhs.im * this->re) / den;
	re = ansr;
	im = ansi;
	return *this;
}
	Complex& operator-() {
		return Complex(-re, -im);
	}
	ostream& writeTo(ostream& ostrm) const;
	istream& readFrom(istream& istrm);
	double re{ 0.0 };
	double im{ 0.0 };
	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
	double length() {
		return sqrt(re * re + im * im);
	}
};
inline ostream& operator<<(ostream& ostrm, const Complex& rhs) {
	return rhs.writeTo(ostrm);
}
inline istream& operator>>(istream& istrm, Complex& rhs) {
	return rhs.readFrom(istrm);
}
Complex operator+(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}
Complex operator-(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}
Complex operator*(const Complex& lhs, const Complex& rhs) {
	double a = lhs.re * rhs.re - lhs.im * rhs.im;
	double b = lhs.re * rhs.im + lhs.im * rhs.re;
	return Complex(a, b);
}
Complex& Complex::operator*=(const Complex& rhs) {
	return operator*(*this, rhs);
}
Complex operator/(const Complex& lhs, const Complex& rhs) {
	Complex newone(lhs);
	newone /= rhs;
	return newone;
}
bool testParse(const string& str) {
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read succsess: " << str << " -> " << z << endl;
	}
	else {
		cout << "Read error: " << str << " -> " << z << endl;
	}
	return istrm.good();
}
int main() {
	Complex z, v, b(4, 5);
	z += Complex(8.0);
	z = -z;
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");
	v = z / b;
	cout << v.re << " " << v.im;
	return 0;
}
Complex::Complex(const double real) : Complex(real, 0.0) {}
Complex::Complex(const double real, const double imaginary) : re(real), im(imaginary) {}
ostream& Complex::writeTo(ostream& ostrm) const {
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}
istream& Complex::readFrom(istream& istrm) {
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaginary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaginary;
		}
		else {
			istrm.setstate(ios_base::failbit);
		}
	}
	return istrm;
}