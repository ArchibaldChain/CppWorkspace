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
     int num = scanf("%lf", input);
     cout << num << "here" << endl;
     while (num == 0)
     {
          printf("A number was expected\n");
          cout << num << "here" << endl;
          scanf("%lf", input);
          cout << num << "here" << endl;
     }
}

void input_str(char *input)
{
     do
     {
          fgets(input, INPUT_LEN, stdin);
          setbuf(stdin, NULL);
     } while (sizeof(input) > 20 && printf("Input is too long"));
}

int main(int argc, char const *argv[])
{
     char fir_city[INPUT_LEN], sec_city[INPUT_LEN];
     memset(fir_city, '\0', sizeof(fir_city));
     memset(sec_city, '\0', sizeof(sec_city));
     double fir_longti = 0, fir_lati = 0;
     double sec_longti = 0, sec_lati = 0;
     double c = 0, phi1 = 0, phi2 = 0;
     //Input the first city
     printf("The First city:");
     fgets(fir_city, INPUT_LEN, stdin);

     printf("Input the longtitude:");
     input_num(&fir_longti); // Input the longtitude of the first city
     printf("Input the latitude:");
     scanf("%lf", &fir_lati); // Input the latitude of the first city

     //Input the Second city
     printf("The Second city:");
     setbuf(stdin, NULL);
     fgets(sec_city, INPUT_LEN, stdin); // Input the second city
     printf("Input the longtitude:");
     scanf("%lf", &sec_longti); // Input the longtitude of the first city
     printf("Input the latitude:");
     scanf("%lf", &sec_lati); // Input the latitude of the second city

     phi1 = 90 - fir_lati;
     phi2 = 90 - sec_lati;

     c = sin(phi1 / 180 * PI) * sin(phi2 / 180 * PI) *
             cos(fir_longti / 180 * PI - sec_longti / 180 * PI) +
         cos(phi1 / 180 * PI) * cos(phi2 / 180 * PI);
     double d = R * acos(c);
     printf("The distance between of %s and %s is %.2f km", fir_city, sec_city, d);
     return 0;
}
