#include<stdio.h>
#include<math.h>

int main(){
	int number;
	scanf("%d",&number);
	for(int i = 0; i < number; i++){
		int a, b;
		scanf("%d %d",&a,&b);
		if(a==1 && b == 1)
			printf("Bob\n");
		else
			printf("Alice\n");
	}	
}
