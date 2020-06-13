#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Hello World");
    int a(int i, int j);
    printf("%d",a(1, 2 ));
    return 0;
}

typedef struct{
   int i;
   int j;
   char x;
} abc;

int  a(int i, int j){
    abc ds;
    ds.i = i;
    ds.j = j;
    ds.x = 'a';
    return ds.i;
}