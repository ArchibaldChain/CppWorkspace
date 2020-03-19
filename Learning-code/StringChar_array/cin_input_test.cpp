#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    char a[30];
    cin >> a; // you won't get the '\0'
    cout << strlen(a);
    cout << a;
}