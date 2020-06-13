//main.c
#include <iostream>
#include "encode_decode.h"

int main() {
    int mask[ROW][COL] = {{0}};
    // 随机初始化
    srand(12345);
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++) {
            float temp =  rand() % (COL + 1) / (float)(COL + 1);
            if (temp>0.5)
                mask[i][j] = 0;
            else
                mask[i][j] = 1;
        }
    mask[0][0] = 1;

    printf("Origin array:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            printf("%d ", mask[i][j]);
        printf("\n");
    }

    std::string code;
    code = encode((int **) mask, ROW, COL);
    printf("\nEncode result:\n%s\n", code.data());


    int **array2d;
    array2d = decode(code);
    printf("\nDecode result: \n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            printf("%d ", array2d[i][j]);
        printf("\n");
    }


    for(int i=0;i<ROW;i++)
        delete [] array2d[i];
    delete [] array2d;

    return 0;
}


