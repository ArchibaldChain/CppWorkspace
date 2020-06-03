//
// Created by Archibald Chain on 2020/5/9.
//

#include "Complex.h"
#include <iostream>
using namespace std;

int main()
{
    Complex a(3.0, 4.0);
    Complex b(2.0, 6.0);
    cout << "b is " << b << endl;
    cout << "~b is " << ~b << endl;
    cout << "a is " << a << endl;
    cout << "a + b is " << a + b << endl;
    cout << "a - b is " << a - b << endl;
    cout << "a * b is " << a * b << endl;
    cout << "2 * b is " << 2 * b << endl;
    cout << "2 + b is " << 2 + b << endl;
    Complex c = b;
    cout << "b==c is " << (b == c) << endl;
    cout << "b!=c is " << (b != c) << endl;
    cout << "a==c is " << (a == c) << endl
         << endl;
    Complex d(2);
    cout << "Enter a complex number : " << endl;
    cin >> d;
    cout << "d is " << d << endl;
    return 0;
}
