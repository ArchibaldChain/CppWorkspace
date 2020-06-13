//
// testException.cpp
// Created by Archibald Chain on 2020/5/31.
//
#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

class OutOfRangeException : public exception
{
    int order;
    int number;

public:
    const char *what() const noexcept override
    {
        string s;
        stringstream ss;
        s = "The parameter " + to_string(order) + " is " + to_string(number) + " which is our of range 0-100 \n";
        return s.c_str();
    }

    OutOfRangeException(int x, int o) : number(x), order(o) {}
};
double calculateAverage(int a1, int a2, int a3, int a4)
{
    if (0 > a1 || 100 < a1)
        throw OutOfRangeException(a1, 1);
    else if (0 > a2 || 100 < a2)
        throw OutOfRangeException(a2, 2);
    else if (0 > a3 || 100 < a3)
        throw OutOfRangeException(a3, 3);
    else if (0 > a4 || 100 < a4)
        throw OutOfRangeException(a4, 4);
    return (a1 + a2 + a3 + a4) / 4.0;
}

int main()
{
    // cout << "test exception" << endl;
    try
    {
        calculateAverage(90, -80, 70, 100);
    }
    catch (OutOfRangeException &e)
    {
        cout << e.what();
    };
    try
    {
        calculateAverage(90, 80, 170, 100);
    }
    catch (OutOfRangeException &e)
    {
        cout << e.what();
    }
    return 0;
}
