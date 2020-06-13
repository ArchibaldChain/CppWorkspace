// usestck0.cpp -- the client program
// compile with stock00.cpp
#include <iostream>
#include "stock00.h"

void fun(int **x, int y[][3])
{
}
int main()
{
    int x[2][3];
    fun((int **)x, x);
    int **c;
    fun(new int *[3], (int(*)[3])c);
    Stock fluffy_the_cat;
    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();
    return 0;
}