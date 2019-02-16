#include<stdio.h>
#include<math.h>
#define LAMADA 10

long Y;
double minmum = 0;
//double x = 50;

double derivative(double x) {
	return 35 * pow(x, 6) + 36 * pow(x, 5) + 9 * pow(x, 2) + 8*x - 2 * Y;
}

double function(double x) {
	return 5 * pow(x, 7) + 6 * pow(x, 6) + 3 * pow(x, 3)+ 4*pow(x,2) - 2 * Y*x;
}

void find_minmum(double x) {
	
	double der = derivative(x);
	x -= LAMADA * 100000000.0/ der;
	printf("1/der = %f, 1/50=%f, der = %f\n",100000000.0/der,1.0/50,der);
	double f = function(x);
	printf("x = %f, f = %f, minmum = %f\n",x,f,minmum);//////////
	if (f - minmum >= 0.00005 || f - Y <= -0.00005) {
		
		minmum = function(x);
	
		find_minmum(x);
	}
	
		return;
}

int main() {
	int number;
	scanf("%d", &number);
	for (int i = 0; i < number; i++)
	{
		scanf("%d", &Y);
		find_minmum(50);
		printf("Case %d: %.4f\n", i+1, minmum);
		//printf("x = %d\n",x);
	}

}
