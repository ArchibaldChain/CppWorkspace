#include <iostream>

int main()
{
    int *p = new int[5];
    for (short i = 0; i < 5; i++)
    {
        std::cin >> p[i];
    }
    for (short i = 4; i >= 0; i--)
    {
        std::cout << *(p + i) << " ";
    }
    delete[] p;
}