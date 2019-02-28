#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#define INPUT_LEN 20
#define R 6371
#define PI 3.141592653

using namespace std;

int main(int argc, char const *argv[])
{
    char fir_city[INPUT_LEN], sec_city[INPUT_LEN];
    memset(fir_city, '\0', sizeof(fir_city));
    memset(sec_city, '\0', sizeof(sec_city));

    float fir_longti = 0, fir_lati = 0;
    float sec_longti = 0, sec_lati = 0;
    float c = 0, phi1 = 0, phi2 = 0;
    //Input the first city
    printf("The First city:");
    fgets(fir_city, INPUT_LEN, stdin);
    printf("Input the longtitude:");
    scanf("%f", &fir_longti);
    printf("Input the latitude:");
    scanf("%f", &fir_lati);

    //Input the Second city
    printf("The Second city:\n");
    fgets(sec_city, INPUT_LEN, stdin);
    printf("\nInput the longtitude:");
    scanf("%f", &sec_longti);
    printf("Input the latitude:");
    scanf("%f", &sec_lati);

    phi1 = 90 - fir_lati;
    phi2 = 90 - sec_lati;

    c = sin(phi1 / 180 * PI) * sin(phi2 / 180 * PI) * cos(fir_longti / 180 * PI - sec_longti / 180 * PI) + cos(phi1 / 180 * PI) * cos(phi2 / 180 * PI);
    double d = R * acos(c) * PI / 180;
    cout << "The distance between " << fir_city << " and " << sec_city
         << " is " << d;
    return 0;
}
