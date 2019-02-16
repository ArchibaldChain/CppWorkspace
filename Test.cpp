#include<stdio.h>

int main(){
	int *a,*b;
	int c=1,d=2;
	int x[7],*p;
	a=&c,b=&d;
	for(int i=2;i<=7;i++)  x[i]=i;
	p=x;
	printf("%d  %d\n",x[0],x[1]);
	for(int i=0;i<7;i++){
		printf("%d\n",*p);
		p++;
	}
	
}
