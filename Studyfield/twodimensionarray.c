#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    double array[3][4] = {
        {1, 2, 3, 3},
        {1, 3, 4, 5},
        {3, 5, 3, 5}};
    double(*ptr_array)[4] = array;
    int i, j;

    {
        for (j = 0; j < 4; j++)
        {
            printf("%.2lf\t", *(*(ptr_array + i) + j));
        }
        printf("**\n");
    }
    return 0;
}
