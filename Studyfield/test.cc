#include <stdio.h>
#include <math.h>
#define INPUT_LEN 80

int main()
{
    char input[INPUT_LEN];
    double val;
    printf("Please enter a value: ");
    fgets(input, INPUT_LEN, stdin);
    sscanf(input, " %lf ", &val);
    printf("Log value:  %.2lf\n", log(val));
    return 0;
}