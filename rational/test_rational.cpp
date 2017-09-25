#include "rational.h"
#include <iostream>
#include <sstream>
using namespace std;
bool checkerc(){
	Rational a;
	cin >> a;
	if (cin.good())
		cout << a << endl;
	else
		cout << "Read error :(" << endl;
	return cin.good();
}
bool checkeriss(const string& str) {
	istringstream iss(str);
	Rational a;
	iss >> a;
	if (iss.good())
		cout << "Read success: " << str << " -> " << a << endl;
	else
		cout << "Read error: " << str << " -> " << a << endl;
	return iss.good();
}
int main() {
	checkeriss("4/5");
	checkeriss("4 : 5");
	checkeriss("4 :  5");
	checkeriss("4 t 5");
	checkerc();
}