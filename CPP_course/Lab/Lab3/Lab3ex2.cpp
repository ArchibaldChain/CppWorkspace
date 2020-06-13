// Lab3Ex2.cpp
#include <iostream>

using namespace std;

struct CandyBar
{
    string name;
    float weight;
    int numofCalory;
};
int main()
{
    CandyBar snack;
    cout << "Enter brand name of a Candy bar: ";
    getline(cin, snack.name);
    cout << "Enter weight of the candy bar: ";
    cin >> snack.weight;
    cout << "Enter calories (an intager value)\
    in the cady bar: ";
    cin >> snack.numofCalory;
    cout << "Brand: " << snack.name << endl
         << "Weight: " << snack.weight << endl
         << "Calories: " << snack.numofCalory << endl;
}