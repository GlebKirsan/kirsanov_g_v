#include <iostream>
#include "complex.h"
#include <sstream>
using namespace std;
void checker(double re0, double im0, double re1, double im1) {
	Complex a(re0, im0), b(re1, im1);
	Complex zeroTest(0, 0);
	cout << "Test" << endl;
	cout << "== check: a = " << a << " b = " << b << "; a == b? " << (a == b) << endl;
	cout << "== check: a = " << a << " b = " << b << "; a != b? " << (a != b) << endl;
	cout << "+ check: " << a << " + " << b << " = " << (a + b) << endl;
	cout << "- check: " << a << " - " << b << " = " << (a - b) << endl;
	cout << "* check: " << a << " * " << b << " = " << (a * b) << endl;
	cout << "/ check: " << a << " / " << b << " = " << (a / b) << endl;
	a += b;
	cout << "+= check: a += b = " << a << endl;
	a -= b;
	cout << "-= check: a -= b = " << a << endl;
	a *= b;
	cout << "*= check: a *= b = " << a << endl;
	a /= b;
	cout << "+= check: a /= b = " << a << endl;
	cout << "Zero division check " <<  endl;
	cout << a << " / " << zeroTest << " = " << (a / zeroTest) << endl;
	cout << "Exponential form – ";
	a.exponentialForm();
	cout << "\n\n";
    vector<Complex> t;
    t = Complex(1, 4).roots(6);
    for (auto &p: t)
        cout << p << " ";
    cout << endl;
}
bool testParse(const string& str) {
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good())
		cout << "Read success: " << str << " -> " << z << endl;
	else
		cout << "Read error : " << str << " -> " << z << endl;
	return istrm.good();
}
int main() {
	Complex z;
	z += Complex(8.0);
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9, 9");
	checker(4, 2, 4, 5);
	checker(0, -4, 0, -4);
	checker(-10, 1, 1, 1);
	return 0;
}