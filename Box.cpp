#include<stdio.h>
#include<math.h>


int compare(int a,int b, int c, int n, int m){
	//printf("a%d,b%d,c%d,n%d,m%d\n",a,b,c,n,m);
	if(a+2*c<=n && b+b+c+c<=m)//
		return 1;
	else if (a+b+c<=n && b+b+c+c<=m)//
		return 2;
	else if (2*c+b+a<=n && a+b+c<=m)//
		return 4;
	else if (2*a+b+c<=n && 2*c+b<=m)//
		return 5;
	else if (3*a+b+c<=n && b+c<=m)//
		return 6;
	else 
		return 0;
}

int main(){
	int number;
	scanf("%d",&number);
	for(int i = 0; i < number; i++){
		int a,b,c,m,n,temp = 0;
		scanf("%d %d %d\n%d %d",&a,&b,&c,&n,&m);
//		if (a<b){
//			temp = b;
//			b = a;
//			a = temp;
//		}
//		if (b<c){
//			temp = b;
//			b = c;
//			c = temp;
//		}
//		if (a<b){
//			temp = b;
//			b = a;
//			a = temp;
//		}
		
		int yes = 0;
		yes += compare(b,a,c,n,m);
		yes += compare(a,b,c,n,m);
		yes += compare(a,c,b,n,m);
		yes += compare(c,a,b,n,m);
		yes += compare(c,b,a,n,m);
		yes += compare(b,c,a,n,m);
		if (yes != 0){
			printf("Yes\n");
			continue;
		} else 
		yes += compare(b,a,c,m,n);
		yes += compare(a,b,c,m,n);
		yes += compare(a,c,b,m,n);
		yes += compare(c,a,b,m,n);
		yes += compare(c,b,a,m,n);
		yes += compare(b,c,a,m,n);
		if (yes != 0){
			printf("Yes\n");
		} else 
		printf("No\n");
	}	
}