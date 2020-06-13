#include <iostream>
#include <cstring>

using namespace std;

struct CandyBar
{
    char brand[30];
    double weight;
    int calorie;
};

void set(CandyBar &cb);
void set(CandyBar *const cb);
void show(const CandyBar &cb);
void show(const CandyBar *cb);

int main()
{
    CandyBar cb;
    set(&cb);
    printf("\n");
    show(&cb);
    printf("\n");

    set(cb);
    printf("\n");
    show(cb);
    printf("\n");

    return 0;
}

void set(CandyBar &cb)
{
    cout << "Call the set function of Passing by reference: " << endl;
    cout << "Enter brand name of a Candy bar: ";
    cin.get();
    cin.getline(cb.brand, 30);
    cout << "Enter weight of a Candy bar: ";
    cin >> cb.weight;
    cout << "Enter caloires of a Candy bar: ";
    cin >> cb.calorie;
}

void set(CandyBar *const cb)
{
    cout << "Call the set function of Passing by pointer: " << endl;
    cout << "Enter brand name of a Candy bar: ";
    cin.clear();
    cin.getline(cb->brand, 30);
    cout << "Enter weight of a Candy bar: ";
    cin >> cb->weight;
    cout << "Enter caloires of a Candy bar: ";
    cin >> cb->calorie;
}

void show(const CandyBar &cb)
{
    cout << "Call the show funciton of passing by reference" << endl;
    cout << "Brand: " << cb.brand << endl;
    cout << "Weight: " << cb.weight << endl;
    cout << "Calories: " << cb.calorie << endl;
}

void show(const CandyBar *cb)
{
    cout << "Call the show funciton of passing by reference" << endl;
    cout << "Brand: " << cb->brand << endl;
    cout << "Weight: " << cb->weight << endl;
    cout << "Calories: " << cb->calorie << endl;
}