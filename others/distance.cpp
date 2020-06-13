#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

int main()
{
    char first_city[6];

    first_city[3] = getchar();
    char second_city[] = "Beijing";
    double phi1 = 22.55;
    double theta1 = 114.1;
    double phi2 = 39.9139;
    double theta2 = 116.3917;

    double c = sin(phi1) * sin(phi2) * cos(theta1 - theta2) + cos(phi1) * cos(phi2);
    double d = 6371 * acos(c) * PI / 180.0;

    printf("The distance between %s and %s is %f", first_city, second_city, d);
    return 0;
}

int *abc()
{
    int a[] = {1, 2, 3};
    return a;
}
