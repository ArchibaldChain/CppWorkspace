#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#define INPUT_LEN 20
#define R 6371
#define PI 3.141592653

using namespace std;

void input_num(double *input)
{
    int flag = scanf("%lf", input);
    while (flag == 0)
    {
        setbuf(stdin, NULL);
        printf("A number was expected\n");
        flag = scanf("%lf", input);
    }
}

double input_longti()
{
    double longti = 0;
    input_num(&longti);

    while (longti < -180 || longti > 180)
    {
        cout << "Out of boundary, please input longtitude between -180 and 180" << endl;
        input_num(&longti);
    }
    return longti;
}

double input_lati()
{
    double lati = 0;
    input_num(&lati);
    while (lati < -90 || lati > 90)
    {
        cout << "Out of boundary, please input latitude between -90 and 90" << endl;
        input_num(&lati);
    }
    return lati;
}

int main(int argc, char const *argv[])
{
    string fir_city = "", sec_city = "";
    double fir_longti = 0, fir_lati = 0;
    double sec_longti = 0, sec_lati = 0;
    double c = 0, phi1 = 0, phi2 = 0;
    //Input the first city
    printf("The First city:");
    getline(cin, fir_city);

    printf("Input the latitude:");
    fir_lati = input_lati();
    printf("Input the longtitude:");
    fir_longti = input_longti();

    //Input the Second city
    printf("The Second city:");
    cin.get(); // omit the space;
    getline(cin, sec_city);

    printf("Input the latitude:");
    sec_lati = input_lati();
    printf("Input the longtitude:");
    sec_longti = input_longti();

    phi1 = 90 - fir_lati;
    phi2 = 90 - sec_lati;

    c = sin(phi1 / 180 * PI) * sin(phi2 / 180 * PI) *
            cos(fir_longti / 180 * PI - sec_longti / 180 * PI) +
        cos(phi1 / 180 * PI) * cos(phi2 / 180 * PI);
    double d = R * acos(c);
    cout << "The distance between " << fir_city << " and " << sec_city << " is " << d << " km" << endl;

    return 0;
}
