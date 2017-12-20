#include "rational.h"
#include <sstream>


using namespace std;

void checkerc() 
{
    Rational a;
    if (cin >> a) {
        cout << "Read success: " << a << endl;
    } else{
        cout << "Read error :(" << endl;
    }
    cin.clear();
}

bool checkeriss(const string &str) 
{
    istringstream istrm(str);
    Rational z;
    if (istrm >> z) {
        cout << "Read success: " << str << " -> " << z << endl;
        return true;
    } else {
        cout << "Read error : " << str << " -> " << z << endl;
        return false;
    }
}

int main() 
{
    checkeriss("4/a");
    checkeriss("4 : 5");
    checkeriss("4 :  5");
    checkeriss("4 t 5");
    checkerc();
    checkerc();
    checkerc();
    Rational a(5,6);
    Rational b(7,12);
    Rational c = a + b;
    cout << a << b << c;
    cout << "Zero devision test ";
    cout << Rational(4,0);
}