#include <iostream>
#include "CandyBar.h"

using namespace std;

int main()
{
    cout << "Please enter the number of Candybar: " << endl;
    int n;
    cin >> n;
    CandyBar *cdb = new CandyBar[n];
    int count;
    int flag = true;
    for (int i = 0; i < n && flag; i++)
    {
        flag = setCandyBar(cdb[i]);
        count = i;
    }

    for (int i = 0; i < count; i++)
    {
        showCandyBar(cdb[i]);
    }
    delete[] cdb;
    return 0;
}