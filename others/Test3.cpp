#include<stdio.h>
#include<stdlib.h>

// the function will return the grade of who has at least one grade less than 60

int main(){
	float score[][4] = { {60,78,80,90},{56,89,67,88},{34,78,90,66}};
	float *search(float (*pointer)[4]);//(*pointer)[4] is the pointer point to the row
	float *p;
	int i,j;
	for ( i = 0 ; i<3; i++ ){
		p = search(score+i);
		/* ''score' is the pointer who point to the ROW
		     'score+i' points the ith ROW*/ 
		if (p==*(score+i))  //if p equals the first address of the ith row
		{
			printf("No.%d score is: ",i+1);
			
			for(j=0;j<4;j++) printf("%5.0f  ",*(p+j));//*(p+J)is not address, it's the value
			
			printf("\n");
		}
	}
}

float *search(float (*pointer)[4]){
	int i=0;
	float *pt;
	pt = NULL;
	for (;i<4;i++)
	   if (*(*pointer+i)<60) pt = *pointer;
	return (pt);
}
