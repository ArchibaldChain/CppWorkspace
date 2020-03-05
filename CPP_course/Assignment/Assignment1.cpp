//
// Created by Archibald Chain on 2019/2/28.
//

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
    string firs_city = "", seco_city = "";

    float fir_longti = 114.1 , fir_lati = 22.55;
    float sec_longti = 116.9139, sec_lati = 39.9139;
    float c = 0, phi1 = 0, phi2 = 0;
    //Input the first city
    printf("The First city:");
    cin >> firs_city;
    printf("Input the longtitude:");
    //scanf("%f", &fir_longti);
    printf("Input the latitude:");
    //scanf("%f", &fir_lati);

    //Input the Second city
    printf("The Second city:");
    cin >> seco_city;
    printf("Input the longtitude:");
    //scanf("%f", &sec_longti);
    printf("Input the latitude:");
    //scanf("%f", &sec_lati);

    phi1 = 90 - fir_lati;
    phi2 = 90 - sec_lati;

    c = sin(phi1 / 180 * PI) * sin(phi2 / 180 * PI) *
        cos(fir_longti / 180 * PI - sec_longti / 180 * PI) +
        cos(phi1 / 180 * PI) * cos(phi2 / 180 * PI);
    double d = R * acos(c) ;
    cout << "The distance between " << firs_city << " and " << seco_city
         << " is " << d;
    return 0;
}
