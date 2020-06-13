//
// Created by Archibald Chain on 2020/5/3.
//
#include <iostream>
#include <cstring>
#include "CandyBar.h"

using namespace std;
void CandyBar::setCandyBar() {
    cout << "Enter brand name of a Candy bar: ";
    getline(cin, name);
    cout << "Enter weight of the candy bar:";
    cin >> weight;
    cout << "Enter calories in the candy bar:";
    cin >> num_calories;
}

void CandyBar::showCandyBar() {
    cout << "Brand: " << name << endl;
    cout << "Weight: " << weight<<endl;
    cout << "Calorie: " << num_calories << endl;
}
