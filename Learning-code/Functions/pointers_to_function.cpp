#include <iostream>

const double *f1(const double ar[], int n);
const double *f2(const double[], int);
const double *f3(const double *, int);

double pam(int);

int main()
{
    double (*pf)(int);
    pf = pam;            // pf now points to the pam() function
    double x = pam(4);   // call pam() using the function name
    double y = (*pf)(5); // call pam() using the pointer pf
    y = pf(4);

    const double *(*p1)(const double *, int) = f1;
    auto p2 = f2; // C++11 automatic type deduction
    const double *(*pa[3])(const double *, int) = {f1, f2, f3};

    const double *(*(*pd)[3])(const double *, int) = &pa;

    auto pb = pa;

    double *av;
    pb[0](av, 4);
    (*pa[0])(av, 4);
    const double *px = pa[0](av, 3);
    const double *py = (*pb[1])(av, 3);

    const double px = *pa[0](av, 3);
    const double py = *(*pb[1])(av, 3);
    return 0;
}