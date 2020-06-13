#include "fun.h"
#include <iostream>

// copy with reference notation
void CopyArray(double (&target)[5], double (&source)[5])
{
    for (short i = 0; i < 5; i++)
    {
        target[i] = source[i];
    }
}

// copy with pointer notation
void CopyArray(double *target, double *source, int len)
{
    for (int i = 0; i < len; i++)
    {
        target[i] = source[i];
    }
}

// copy with two pointers
void CopyArray(double *target, double *source_start, double *source_end)
{
    for (double *p = source_start; p != source_end; p++, target++)
    {
        *target = *p;
    }
}

//Print the values of three arrays in format
void PrintArray(double *target1, double *target2, double *target3, int len)
{
    using namespace std;
    cout << " target1| target2| target3" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << "\t" << target1[i]
             << "|\t" << target2[i]
             << "|\t" << target3[i] << endl;
    }
}
