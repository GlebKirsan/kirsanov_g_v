#include "rational.h"
#include <sstream>
using namespace std;
void checkerc(){
	Rational a;
	if (cin >> a) {
        a.normalize();
        cout << "Read success: " << a << endl;
    }
    else
		cout << "Read error :(" << endl;
	cin.clear();
}
bool checkeriss(const string& str) {
	istringstream istrm(str);
	Rational z;
	if (istrm >> z) {
        z.normalize();
		cout << "Read success: " << str << " -> " << z << endl;
		return true;
	}
	else {
		cout << "Read error : " << str << " -> " << z << endl;
		return false;
	}
}
int main() {
	checkeriss("4/a");
	checkeriss("4 : 5");
	checkeriss("4 :  5");
	checkeriss("4 t 5");
	checkerc();
	checkerc();
	checkerc();
	checkerc();
}