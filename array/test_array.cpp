#include <iostream>
#include "array.h"
using namespace std;
int main()
{
    Array<int> a;
    Array<int> b(2);
    cout << "Input test\n";
    for (int i = 0; i < b.length(); i += 1)
        cin >> b[i];
    cout << "Output test: " << b;
    b.resize(3);
    cout << "Resize test: " << b;
    Array<string> c(5, "privet");
    cout << "Ctor with default value: "  << c;
    CopyTo(a, b);
    cout <<"b copy to a: " << a;
    a.push_back(4);
    cout << "Push back 4 into a: " << a;
    a.pop_back();
    cout << "Pop back from a " << a;
}