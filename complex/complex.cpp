#include <iostream>
#include "complex.h"
#include <cmath>
double eps(1e-7);
double pi(3.1415926);
bool Complex::operator==(const Complex a) { 
	double compre = fabs(re - a.re);
	double compim = fabs(im - a.im);
	return compre < eps && compim < eps;
}
Complex& Complex::operator-() {
	re = -re;
	im = -im;
	return *this;
}
Complex& Complex::operator+=(const Complex& a) {
	re += a.re;
	im += a.im;
	return *this;
}
Complex& Complex::operator+=(const double a) { 
	return operator+=(Complex(a)); 
}
Complex& Complex::operator-=(const Complex& a) {
	re -= a.re;
	im -= a.im;
	return *this;
}
Complex& Complex::operator-=(const double a) { 
	return operator-=(Complex(a));
}
Complex& Complex::operator*=(const Complex& a) {
	double resr = re * a.re + -im * a.im;
	double resi = im * a.im + a.im * a.re;
	re = resr;
	im = resi;
	return *this;
}
Complex& Complex::operator*=(const double a) { 
	return operator*=(Complex(a)); 
}
Complex& Complex::operator/=(const Complex& a) {
	if (abs(a.re) < eps && abs(a.im) < eps) {
		std::cout << "zero division" << std::endl;
	}
	double den = a.re * a.re + a.im * a.im;
	double ren = (re * a.re + im * a.im) / den;
	double imn = (im * a.re - re * a.im) / den;
	re = ren;
	im = imn;
	return *this;
}
Complex& Complex::operator/=(const double a) { 
	return operator/=(Complex(a));
}
Complex& Complex::operator=(const Complex& a) {
	re = a.re;
	im = a.im;
	return *this;
}
Complex operator+(const Complex& a, const Complex& b) {
	Complex c(a);
	c += b;
	return c;
}
Complex operator/(const Complex& a, const Complex& b) {
	Complex c(a);
	c /= b;
	return c;
}
Complex operator/(const Complex& a, const double b) {
	return a / Complex(b);
}
Complex operator*(const Complex& a, const Complex& b) {
	Complex c(a);
	c *= b;
	return c;
}
Complex operator*(const Complex& a, const double b) {
	return a * Complex(b);
}
Complex operator+(const Complex& a, const double b) { return operator+(a, Complex(b)); }
Complex operator-(const Complex& a, Complex b) { return operator+(a, -b); }
Complex operator-(const Complex& a, const double b) { return a + Complex(-b); }
double Complex::length() {
	return sqrt(re * re + im * im);
}
void Complex::exponentialForm() {
	double phi(0.0);
	double length(0.0);
	phi = atan(im / re);
	length = this->length();
	std::cout << '|' << length << '|' << "e^(i" << phi << ") = " << \
		(length > 0 ? length : -length) << "e^(i" << phi << ')' << std::endl;
}
std::ostream& Complex::writeTo(std::ostream& ostr) const {
	ostr << lBrace << re << separator << im << rBrace;
	return ostr;
}
std::istream& Complex::readFrom(std::istream& istr) {
	char lBrace(0);
	double r(0.0);
	char separator(0);
	double i(0.0);
	char rBrace(0);
	istr >> lBrace >> r >> separator >> i >> rBrace;
	if (istr.good()) {
		if (Complex::lBrace == lBrace &&
			Complex::separator == separator &&
			Complex::rBrace == rBrace) {
			re = r;
			im = i;
		}
		else
			istr.setstate(std::ios_base::failbit);
	}
	return istr;
}