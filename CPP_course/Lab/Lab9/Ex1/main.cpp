#include "fun.h"
#include <iostream>

int main()
{
    double source[5] = {1, 2, 3, 4, 5}, t1[5], t2[5], t3[5];
    CopyArray(t1, source);
    CopyArray(t2, source, 5);
    CopyArray(t3, source, source + 5);
    PrintArray(t1, t2, t3, 5);
}