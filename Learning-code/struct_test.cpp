#include <iostream>

using namespace std;

struct box
{
    int n;
};
int m, n;
void fun(int (*m)[4])
{
}
int main()
{

    int array[][4] = {{1, 2, 3}, {3, 4, 5}};
    fun(array);
    box a = {1};
    box b = a;
    box c;
    cout << "a " << &a << endl;
    cout << "b " << &b << endl;
    cout << "c " << &c << endl;
}