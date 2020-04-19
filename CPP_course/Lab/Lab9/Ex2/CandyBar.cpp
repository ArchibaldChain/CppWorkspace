#include <iostream>
#include <cstring>
#include "CandyBar.h"

using namespace std;

int setCandyBar(CandyBar &snack)
{
    cin.get();
    cout << "Enter brand name of a Candy bar:";
    char temp[Len];
    cin.getline(temp, Len);
    strcpy(snack.brand, temp);
    if (strcmp(snack.brand, "\0") == 0)
    {
        return 0;
    }
    cout << "Enter weight of the candy bar: ";
    cin >> snack.weight;
    cout << "Enter calories (an integer value) of the candy bar: ";
    cin >> snack.calorie;
    return 1;
}

void showCandyBar(const CandyBar &snack)
{
    cout << "\nCandybar brand is " << snack.brand << endl;
    cout << "Candybar weight is " << snack.weight << endl;
    cout << "Candybar caloires is " << snack.calorie << endl;
}
