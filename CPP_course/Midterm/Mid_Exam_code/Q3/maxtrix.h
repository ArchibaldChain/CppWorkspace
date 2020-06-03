//
// Created by jyh on 2020/4/22.
//

#ifndef MIDEXAM_MAXTRIX_H
#define MIDEXAM_MAXTRIX_H
#include <cmath>
#include <cstring>

typedef struct Matrix
{
    double *data = NULL;
    int n_rows = 0;
    int n_cols = 0;
} Matrix;

int Add(Matrix &m, Matrix &m1, Matrix &m2);
int Subtract(Matrix &m, Matrix &m1, Matrix &m2);
int Products(Matrix &m, Matrix &m1, Matrix &m2);
int EleProducts(Matrix &m, Matrix &m1, Matrix &m2);

double D(Matrix &m, int size);
int Determinant(double &result, Matrix &m);
int Trace(double &result, Matrix &m);
#endif //MIDEXAM_MAXTRIX_H
