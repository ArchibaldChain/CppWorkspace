#include<stdio.h>
#include<math.h>

void part1(int a, int b, int c){
	int i,j,k;
	for (i = 0; i < b; i++)
	{
		for (j = 2*b; j > 2*i ; j--) {
			printf("."); 
			//printf("%d",i);
			}// ��ӡ�Ӻ��еĵ�
				
		for (j = 0; j < a ; j++) 
		{
			printf("+"); 
			printf("-");
		}//	
			printf("+");
		for (j = 0; j < i; j++){
			printf(".+");
		}
			printf("\n");				
        //**************************************************			
			
		for (j = 2*b-1; j > 2*i ; j--) {
			printf("."); }// ��ӡ/././.�еĵ�
		for (j = 0; j < a ; j++) 
		{
			printf("/.");    // print /./././
		}
	    	printf("/");
	    //******************
	    	printf("|");
		for (j = 0; j < i; j++){
			printf("/|");	
		}
			printf("\n");	
	}		
}

void part2(int a,int b,int c){
	for (int i = 0; i < c-b; i++){
		for (int j = 0; j < a; j++){
			printf("+-");
		}
		for (int j = 0; j < b; j++){
			printf("+.");
		}
		printf("+\n");
		//****************
		for (int j = 0; j < a; j++){
			printf("|.");
		}
		for (int j = 0; j < b; j++){
			printf("|/");
		}
		printf("|\n");
	}
	for (int j = 0; j < a; j++){
			printf("+-");
		}
	for (int j = 0; j < b; j++){
		printf("+.");
	}
	printf("+\n");	
}

void part3(int a, int b, int c){
	int i,j,k;
	for (i = b-1; i >= 0; i--)
	{	
		for (j = 0; j < a ; j++) 
		{
			printf("|.");    // print /./././
		}
	    //******************
		for (j = 0; j < i+1; j++){
			printf("|/");	
		}
		for (j = 2*b-1; j > 2*i ; j--) {
			printf("."); }// ��ӡ/././.�еĵ�	
		printf("\n");
	//**********************************
				
		for (j = 0; j < a ; j++) 
		{
			printf("+-"); 
		}
		for (j = 0; j < i; j++){
			printf("+.");
		}
			printf("+");				
        for (j = 2*b; j > 2*i ; j--) {
			printf("."); 
			//printf("%d",i);
			}// ��ӡ�Ӻ��еĵ�		
		printf("\n");
		
	}		
}
/**6,2,4-->3,4,5
........+-+-+-+
......././././|
......+-+-+-+.+
....././././|/|
....+-+-+-+.+.+
..././././|/|/|
..+-+-+-+.+.+.+
././././|/|/|/|
+-+-+-+.+.+.+.+
|.|.|.|/|/|/|/|
+-+-+-+.+.+.+.+
|.|.|.|/|/|/|/.
+-+-+-+.+.+.+..
|.|.|.|/|/|/...
+-+-+-+.+.+....
|.|.|.|/|/.....
+-+-+-+.+......
|.|.|.|/.......
+-+-+-+........


*/
void draw(int a, int b, int c);

int main()
{
	int number;
	scanf("%d",&number);
	for(int i = 0; i < number; i++){
		int a, b, c;// long medium short
		scanf("%d %d %d",&a,&b,&c); // 3,4,5
	///	part1(a,b,c);
	///	part2(a,b,c);
	//	part3(a,b,c);
		draw(a, b, c);
	}	
}

void draw(int a, int b, int c) {
	int i,j,k;
	for (i = 0; i < b + c+1; i++) {
		for (j = 2 * b; j > 2 * i; j--) {
			printf(".");
			//printf("%d",i);
		}// ��ӡ�Ӻ��еĵ�
		//*******************
		for (int j = 0; j < a; j++)
		{
			printf("+-");
		}//	
		
		//�����������׳��ֱ仯 ����
		if (b <= c) {
			for (j = 0; j<i && i<b+1; j++) {
				printf("+.");
			}
			for (j = 0; j < b && i > b && i <= c; j++) {
				printf("+.");
			}
			if (i<=c)
				printf("+\n");
			for (j = 0; j < c+b-i && i > c; j++) {
				printf("+.");
				if(i == c+b-i-1);
					printf("+");
			}
			
		}

		//***************���
		for (j = 0; j > 4 * c-2*i && i>c; j--) {
			printf(".");
			//printf("%d",i);
		}// ��ӡ�Ӻ��еĵ�	
		if (i>c)	printf("\n");
	}
}
/**6,2,4-->3,4,5
........+-+-+- +
......././././|
......+-+-+- +.+
....././././|/|
....+-+-+- +.+.+
..././././|/|/|
..+-+-+- +.+.+.+
././././|/|/|/|
+-+-+- +.+.+.+.+
|.|.|.|/|/|/|/.            5 + 4 - 2x4
+-+-+- +.+.+.+..
|.|.|.|/|/|/...
+-+-+- +.+.+....
|.|.|.|/|/.....
+-+-+- +.+......
|.|.|.|/.......
+-+-+- +........

*/
