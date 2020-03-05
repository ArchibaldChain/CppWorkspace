#include <iostream>
#include <stdio.h>

int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    string s1, s2;
    int a;

    cin.getline(name, ArSize);    // using in c++ program
    cin.getline(dessert, ArSize); // using in c++ program

    cout << "1" << name << endl;
    cout << "2" << dessert << endl;
    // getline(cin, s1);
    // cout << "3" << s1 << endl;
    // getline(cin, s2);
    // cout << "4" << s2 << endl;
}

// gets(dessert);             // using in c program
//   puts(dessert);