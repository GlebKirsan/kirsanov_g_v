#include <iostream>
#include "array.h"
using namespace std;
int main(){
    Array a;
    Array b(5);
    int c = a.length();
    cout << b.length() << endl;
    return 0;
}