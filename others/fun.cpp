#include<stdio.h>

void fun(int array[]){
	int temp, *a=array;
	temp=*(array+2);
	*(array+2) = *(array+3);
	*(array+3) = temp;
	
	for( ; array< a+10 ; array++ ){
		printf(" %d ",*array);
	}
}

