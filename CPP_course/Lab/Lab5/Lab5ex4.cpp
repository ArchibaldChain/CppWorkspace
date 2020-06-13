#include <iostream>
int main()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i >= j)
                printf("%d", j + 1);
            else
                printf("*");
        }
        printf("\n");
    }
}