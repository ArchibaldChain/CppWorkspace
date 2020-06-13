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
    gets(dessert);                // using in c program
    puts(dessert);
    cout
        << "1" << name << endl;
    cout << "2" << dessert << endl;
    getline(cin, s1);
    cout << "3" << s1 << endl;
    getline(cin, s2);
    cout << "4" << s2 << endl;


    cin >> a;
    cin.get();// cin.get(ch)
    
    (cin>>a).get();// or get(ch)
    // Another way by using concatenate of get
    cin.get(name, ArSize).get(); //if excuetive is empty, then it sets something failbit
    cin.clear();
    cin.get(dessert, ArSize).get();


}
