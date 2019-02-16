#include<stdio.h>
#include<stdlib.h>

int main() {
	int number;// the number of the test cases
	scanf("%d", &number);
	int n, m, yes;
	for (int i = 0; i < number; i++)
	{
		yes = 0;
		scanf("%d %d", &n, &m);
		int a[n];
		for (int j = 0; j < n; j++)
		{
			
			//printf("%d\n",j);
			scanf("%d", &a[j]);
			if (m == a[j]) {
				yes = 1;
				
				//printf("*********%d\n",yes);
			}
		}
		if (yes == 0)
			printf("NO");
		else
			printf("YES");
		printf("\n");
	}


}
