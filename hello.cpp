#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("Hello world*************\n");
    int i, j;
    for (i = 0; i < 100; i++)
    {
        printf("i=%d\n", i);
        j = i + 8;
    }

    return 0;
}
