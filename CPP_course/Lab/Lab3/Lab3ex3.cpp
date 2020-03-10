// Lab3Ex3.cpp
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
    CandyBar snack[3];
    string brand[3] = {"Mocha Munch", "Cholcolate", "Cookie"};
    float weight[3] = {2.3, 2.5, 2.6};
    int numofCal[3] = {350, 400, 280};
    for (int i = 0; i < 3; i++)
    {
        snack[i] = {
            brand[i],
            weight[i],
            numofCal[i],
        };
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "Brand: " << snack[i].name << endl
             << "Weight: " << snack[i].weight << endl
             << "Calories: " << snack[i].numofCalory << endl;
    }
}