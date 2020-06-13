// ptrstr.cpp -- using pointers to strings
#include <iostream>
#include <cstring> // declare strlen(), strcpy()
int main()
{
    using namespace std;
    char animal[20] = "bear";  // animal holds bear
    const char *bird = "wren"; // bird holds address of string
    char *ps;

    ps = animal;         // set ps to point to string
    cout << ps << "!\n"; // ok, same as using animal
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int *)animal << endl;
    cout << ps << " at " << (int *)ps << endl;
    // amimal and ps has the same address

    ps = new char[strlen(animal) + 1]; // get new storage
    strcpy(ps, animal);                // copy string to new storage
    cout << "After using strcpy():\n";
    cout << animal << " at " << (int *)animal << endl;
    cout << ps << " at " << (int *)ps << endl;
    delete[] ps;
    return 0;
}