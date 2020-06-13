#include<stdio.h>        // COMPRASION TO Test2
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
		printf("%d ", a[i]);
	
	}
}   


void fun(int array[]){
	int temp;
	temp=array[2];
	array[2]=array[3];
	array[3] = temp;
	
	for( int i; i<10 ; i++ ){
		printf(" %d ",array[i]);
	}
}
