#include<stdio.h>
#include<stdlib.h>

void fun(int array[]);


int main(){
	int a[10];
	for(int i=0 ; i<10 ; i++ ) {
		a[i] = i;                             //½«a¡¾¡¿¸³Öµ³É 0£¬1£¬2£¬3£¬4£¬5£¬6£¬7£¬8£¬9 
	}
	fun(a);
	printf("\n");
	for( int i=0 ; i < 10 ; i++ ) {
		printf("%d ", *(a+i));
	
	}
	
	char a[10] = "a\0d\\n";
	printf("%d",a);
}   



