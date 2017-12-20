#include <iostream>
#include "quat.h"
using namespace std;

int main()
{
	Quat a;
	Quat b(4,5,6,7);
	cout << "Output test \n" << b << endl;
	cout << "Input test" << endl;
	cin >> a;
	cout
			<< "Comparison test\na = b ?" << (a == b)
			<< "\na < b? " << (a < b)
			<< "\na > b? " << (a > b)
			<< "\na!= b? " << (a != b) << endl;
	cout << -a;
	cout << "a * b\n" << (a * b);
	cout << "a + b\n" << (a + b);
	cout << "a - b\n" << (a - b);
	cout << "b * 0.5\n" << (b * 0.5);
	cout << "0.5 * b\n" << (0.5 * b);
	cout << "b = a\n" << (b = a);
    Quat ctorCopy(a);
    cout << "Constructor of copy\n" << ctorCopy;
}