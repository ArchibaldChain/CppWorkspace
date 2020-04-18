#include <iostream>

using namespace std;

struct box
{
    int n;
};
int main()
{

    box a = {1};
    box b = a;
    box c;
    cout << "a " << &a << endl;
    cout << "b " << &b << endl;
    cout << "c " << &c << endl;
}