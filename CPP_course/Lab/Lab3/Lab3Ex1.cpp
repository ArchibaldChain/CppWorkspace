// Lab3Ex1.cpp
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
    CandyBar snack = {
        "Mocha Munch",
        2.3,
        350};
    cout << "Brand: " << snack.name << endl
         << "Weight: " << snack.weight << endl
         << "Calories: " << snack.numofCalory << endl;
}