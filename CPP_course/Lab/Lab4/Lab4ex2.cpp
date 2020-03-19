#include <iostream>

using namespace std;
struct CandyBar
{
    string bra_name;
    float weig;
    float numofcal;
};
int main()
{
    CandyBar *p = new CandyBar[3];
    for (short i = 0; i < 3; i++, cin.ignore())
    {
        cout << "please input the company of the CandyBar\n";
        getline(cin, (p + i)->bra_name);
        cout << "input the weight\n";
        cin >> (p + i)->weig;
        cout << "input the number of Calories\n";
        cin >> (p + i)->numofcal;
    }
    for (short i = 0; i < 3; i++)
    {
        cout << "the company of the CandyBar is: " << (p + i)->bra_name << endl
             << "the weight of the CandyBar is:" << (p + i)->weig << endl
             << "the diameter of the CandyBar is:" << (p + i)->numofcal << endl;
    }
    delete[] p;
    return 0;
}