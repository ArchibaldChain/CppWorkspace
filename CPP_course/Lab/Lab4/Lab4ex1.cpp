#include <iostream>

using namespace std;
struct pizza
{
    string comp;
    float diam;
    float weig;
};
int main()
{
    pizza *p1 = new pizza;
    cout << "please input the company of the pizza\n";
    getline(cin, p1->comp);
    cout << "input the diameter\n";
    cin >> p1->diam;
    cout << "input the weight\n";
    cin >> p1->weig;
    cout << "the company of the pizza is: " << p1->comp << endl
         << "the diameter of the pizza is:" << p1->diam << endl
         << "the weight of the pizza is:" << p1->weig << endl;
    delete p1;
    return 0;
}