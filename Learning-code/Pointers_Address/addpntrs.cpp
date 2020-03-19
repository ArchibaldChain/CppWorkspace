// addpntrs.cpp -- pointer addition
#include <iostream>
int main()
{
    using namespace std;
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};
    // Here are two ways to get the address of an array
    short *ps = &stacks[0]; // or use address operator
    double *pw = wages;     // name of an array = address

    // with array element
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";
    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps = ps + 1;
    cout << "add 1 to the ps pointer:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";
    cout << "access two elements with array notation\n";
    cout << "stacks[0] = " << stacks[0]
         << ", stacks[1] = " << stacks[1] << endl;
    cout << "access two elements with pointer notation\n";
    cout << "*stacks = " << *stacks
         << ", *(stacks + 1) = " << *(stacks + 1) << endl;
    cout << sizeof(wages) << " = size of wages array\n";
    cout << sizeof(pw) << " = size of pw pointer\n";

    cout << "\nThe address of array and arrayname\n";
    cout << wages << sizeof(*wages) << endl;   // displays &wages[0]
    cout << &wages << sizeof(*&wages) << endl; // displays address of whole array
    short(*pas)[3] = &stacks;                  //pointer that point to an array of 20 shorts
    return 0;
}