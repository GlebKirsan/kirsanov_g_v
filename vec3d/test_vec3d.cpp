#include <sstream>
#include <iostream>
#include "vec3d.h"

using namespace std;

int main() {
    Vec3d a;
    Vec3d b(4, 5, 6);
    Vec3d c(b);
    cout << "b = " << b << "c = " << c;
    cout << "b length is " << b.length() << endl;
    cout << "Is b equal c?  " << (b == c) << endl;
    b.normalize();
    cout << "Normalized b length " << b.length() << endl;
    cout << "Input test" << endl;
    Vec3d t;
    cin >> t;
    cout << t;
}