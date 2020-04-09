#include <iostream>

const double *f1(const double ar[], int n);
const double *f2(const double[], int);
const double *f3(const double *, int);

int main()
{
    const double *(*p1)(const double *, int) = f1;

    auto p2 = f2; // C++11 automatic type deduction
    const double *(*pa[3])(const double *, int) = {f1, f2, f3};
}