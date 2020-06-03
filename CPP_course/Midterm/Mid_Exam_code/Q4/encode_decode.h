//
// Created by jyh on 2020/4/22.
//

#ifndef MIDEXAM_ENCODE_DECODE_H
#define MIDEXAM_ENCODE_DECODE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define ROW 5
#define COL 6
#define LENGTH (ROW*COL)
std::string encode(int **mask, int m, int n);
int **decode(std::string code);
#endif //MIDEXAM_ENCODE_DECODE_H
