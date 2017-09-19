#include <iostream>
using namespace std;
int gcd(int a, unsigned int b) {
	return b ? gcd(b, a % b) : a;
}
class Rational {
public:
	Rational() = default;
	Rational(const int numerator) :num(numerator) {}
	Rational(const int numerator, const unsigned int denominator):
		num(numerator),
		den(denominator) {
		if (den == 0) {
			throw std::runtime_error("zero division error");
		}
		int nod = gcd(num, den);
		num /= nod;
		den /= nod;
	}
	~Rational() = default;
	void print() {
		cout << num << "/" << den << endl;
		return;
	}
	Rational& operator+(const Rational& r) {
		Rational ans;
		ans.den = this->den / gcd(this->den, r.den) * r.den;
		int numer1 = this->den / ans.den * this->num;
		int numer2 = r.den / ans.den * r.num;
		ans.num = numer1 + numer2;
		return ans;
	}
	Rational& operator=(const Rational& a) {
		this->den = a.den;
		this->num = a.num;
		return *this;
	}
	Rational& operator*(const Rational& r) {
		return Rational(r.num * this->num, r.den * this->den);
	}
	Rational& operator*(const int r) {
		return Rational(this->num * r, this->den);
	}
	Rational& operator-(const Rational& a)  {
		Rational b(a.num, a.den);
		b.num *= -1;
		return b;
	}
	Rational& operator-(const Rational& r) {
		return (this + (-r));
	}
	Rational& operator+(const double a) {
		return Rational
	}
private:
	int num{ 0 };
	unsigned int den{ 1 };
	
};
int main() {
	Rational a(4, 5);
	Rational b(8, 4);
	a.print();
	b.print();
	a.print();
	return 0;
}