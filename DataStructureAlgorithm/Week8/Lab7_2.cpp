#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>



void encoding(char *t, char *p, int *code);
void decoding(int *t, char *p, char *code);
int plus_Char(int a, int b);
int minus_char(int a, int b);


int main(){
    printf("Input the text:\n");
    
	char text[1000];
    char key[1000];
    fgets(text, 999, stdin);
    printf("Input the Key: \n");
    fgets(key, 999, stdin);
    
    
    int secretCode[1000];
    memset(secretCode,0,sizeof(secretCode));
    char outCode[1000];
    memset(outCode, 0, 1000);

    encoding(text, key, secretCode);

    printf("The secret code:\n");
    
    for(size_t i = 0; secretCode[i] != 0; i++)
    {
        printf("%d ", secretCode[i]);
    }
    
    printf("\nText after decode:\n");
    decoding(secretCode, key, outCode);
    printf("%s\n", outCode);
    
    return 0;
}




void encoding(char *t, char *p, int *code){
    int i = 0;
    int j = 0;
    for(i = 0, j = 0; t[i] != 0; i++, j++)
    {
        if(p[j] == '\0'){
            j = 0;
        }
        char a = *(t+i);
        char b = *(p+j);
        
        code[i] = plus_Char(a, b);
    }
    code[i+1] = '\0';
}

int plus_Char(int a, int b){
    return a + b;
}

void decoding(int *t, char *p, char *code){
    
    int i = 0;
    int j = 0;
    for(i = 0, j = 0; t[i] != 0; i++, j++)
    {
        if(p[j] == '\0'){
            j = 0;
        }
        char a = t[i];
        char b = p[j];
        code[i] = minus_char(a, b);
    }
    code[i+1] = '\0';
}

int minus_char(int a, int b){
    return a-b;
}