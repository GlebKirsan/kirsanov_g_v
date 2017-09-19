#include <iostream>
#define eps 1e-12
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
		if (den == 1) {
			cout << num << endl;
			return;
		}
		if (num > den) {
			int integ = num / den;
			num -= integ * den;
			cout << integ << " "; 
		}
		cout << num << "/" << den << endl;
		return;
	}
	Rational& operator=(const Rational& a) {
		this->den = a.den;
		this->num = a.num;
		return *this;
	}
	Rational& operator+(const Rational& r) {
		Rational ans;
		int nod = gcd(this->den, r.den);
		ans.den = this->den / (nod == 1 ? (fabs(this->den - r.den) < eps ? this->den : r.den) : nod) * r.den;
		int numer1 = ans.den / this->den * this->num;
		int numer2 = ans.den / r.den * r.num;
		ans.num = numer1 + numer2;
		return ans;
	}
	Rational& operator+(const double a) {
		return (*this + Rational(a));
	}
	Rational& operator*(const Rational& r) {
		return Rational(r.num * this->num, r.den * this->den);
	}
	Rational& operator*(const int r) {
		return Rational(this->num * r, this->den);
	}
	Rational& operator-()  {
		num *= -1;
		return *this;
	}
	Rational& operator-(Rational& r) {
		return (*this + (-r));
	}
private:
	int num{ 0 };
	unsigned int den{ 1 };
	
};
int main() {
	Rational a{ 4, 5 };
	Rational b{ 8, 4 };
	a.print();
	b.print();
	Rational newone{ a + b };
	newone.print();
	return 0;
}