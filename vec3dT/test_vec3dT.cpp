#include "vec3dT.h"
#include <iostream>

using namespace std;

int main() {
    Vec3dT<int> a;
    Vec3dT<double> b(4, 5, 6);
    cout << "Test of output b = " << b;
    cout << "Test of input " << endl;
    Vec3dT<double> c;
    Vec3dT<float> k(1, 2, 3);
    Vec3dT<float> kk(2, 1, 3);
    c = Vec3dT<double>(4, 5, 6);
    cout << c << endl;
    cout << "Test of equality b == c? " << (b == c) << endl;
    cout << "Test of unequality of float k(1,2,3) and kk(2,1,3). k == kk? " << (k != kk) << endl;
    cout << "k + kk = " << (k + kk) << endl;
    cout << "k - kk = " << (k - kk) << endl;
    cout << "k * kk = " << (k * kk) << endl;
    cout << "k / kk = " << (k / kk) << endl;
}