#include<stdio.h>
#include<stdlib.h>

int main(){
    unsigned int a = 1, b = 7, c,d;
    
    c = a ^ b;
    d = a ^ c;
    a = ~(b ^ (~ c));
    a = ~ b;
    printf("c = %d, a = %d\n", c, d);
    return 0;
}