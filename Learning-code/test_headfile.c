#include <stdio.h>
#include <stdlib.h>
#define A 1
#if A == 1
int X = 1;
#elif A == 2
int X = 2;
#endif

int main(){
    printf("%d", X);
}