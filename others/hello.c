#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592653

int main(int argc, char const *argv[])
{
     printf("Hello world*************\n");
     printf("%f\n", cos(90 / 180 * PI));
     printf("%f", acos(0));
     int a = printf("input is too long");
     printf("\n%d", a);

     return 0;
}
