#include <iostream>

int main()
{
    using namespace std;
    int *p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[3] = 3;
    std::cout << p[0] << endl;
    std::cout << p << endl;
    cout << (int)p << endl;
    cout << (int *)p << endl;
    cout << "*******************" << endl;
    delete[] p;
    std::cout << p[0] << endl;
    cout << p << endl;
    //p = NULL;
    cout << p[0] << endl;
    cout << p << endl;

    int x[8];
    int(*pt)[8] = &x;
    cout << ((int)(pt + 1) - (int)pt) << endl;
}