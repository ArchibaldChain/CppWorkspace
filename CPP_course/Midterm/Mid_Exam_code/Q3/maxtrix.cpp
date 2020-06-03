//
// Created by jyh on 2020/4/22.
//

#include "maxtrix.h"
// Matrix addition:
// return m = m1 + m2
// Expected: m1 shares the same shape with m2
int Add(Matrix &m, Matrix &m1, Matrix &m2)
{
    if (m1.n_cols != m2.n_cols || m1.n_rows != m2.n_rows)
        return 1;
    m.data = (double *)malloc(sizeof(double) * m1.n_cols * m1.n_rows);
    m.n_cols = m1.n_cols;
    m.n_rows = m1.n_rows;
    for (int i = 0; i < m1.n_rows; i++)
    {
        for (int j = 0; j < m1.n_rows; j++)
            m.data[i * m1.n_rows + j] = m1.data[i * m1.n_rows + j] + m2.data[i
                                                                             * m1.n_rows + j];
    }
    return 0;
}



// Matrix subtract:
// return m = m1 - m2
// Expected: m1 shares the same shape with m2
int Subtract(Matrix &m, Matrix &m1, Matrix &m2)
{
    if (m1.n_cols != m2.n_cols || m1.n_rows != m2.n_rows)
        return 1;
    m.data = (double *)malloc(sizeof(double) * m1.n_cols * m1.n_rows);
    m.n_cols = m1.n_cols;
    m.n_rows = m1.n_rows;
    for (int i = 0; i < m1.n_rows; i++)
    {
        for (int j = 0; j < m1.n_rows; j++)
            m.data[i * m1.n_rows + j] = m1.data[i * m1.n_rows + j] - m2.data[i
                                                                             * m1.n_rows + j];
    }
    return 0;
}

// Matrix products:
// return m = m1 * m2
// Expected: the ncol of m1 should be the same as the nrow of m2
// Note: this function is about the Matrix multiplication
int Products(Matrix &m, Matrix &m1, Matrix &m2)
{
    if (m1.n_cols != m2.n_rows)
        return 1;
    m.data = (double *)malloc(sizeof(double) * m1.n_rows * m2.n_cols);
    m.n_rows = m1.n_rows;
    m.n_cols = m2.n_cols;
    for (int i = 0; i < m1.n_rows; i++)
    {
        for (int j = 0; j < m2.n_rows; j++)
        {
            int temp = i * m1.n_cols + j;
            m.data[temp] = 0;
            for (int k = 0; k < m1.n_rows; k++)
                m.data[temp] += m1.data[i * m1.n_rows + k] * m2.data[k *
                                                                     m2.n_rows + j];
        }
    }
    return 0;
}
//Matrix element-wise products:
// return m1 .* m2
// Expected: m1 shares the same shape with m2
int EleProducts(Matrix &m, Matrix &m1, Matrix &m2)
{
    if (m1.n_cols != m2.n_cols || m1.n_rows != m2.n_rows)
        return 1;
    m.data = (double *)malloc(sizeof(double) * m1.n_cols * m1.n_rows);
    m.n_cols = m1.n_cols;
    m.n_rows = m1.n_rows;
    for (int i = 0; i < m1.n_rows; i++)
    {
        for (int j = 0; j < m1.n_rows; j++)
            m.data[i * m1.n_rows + j] = m1.data[i * m1.n_rows + j] * m2.data[i
                                                                             * m1.n_rows + j];
    }

    return 0;
}


// Matrix determinant
// return the determinant of the Matrix
// Expected: m should be the square.
double D(Matrix &m, int size)
{
    if (size == 1)
        return m.data[0];
    else
    {
// from left to right calculate algebraic cofactor
        double *temp = (double *)malloc(sizeof(double) * (size - 1) * (size -
                                                                       1));
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                int mov = i > j ? 0 : 1;
                for (int k = 0; k < size - 1; k++)
                    temp[j * (size - 1) + k] = m.data[(mov + j) * size + k +
                                                      1];
            }
            Matrix ma{temp, size - 1, size - 1};
            sum += (!(i % 2) ? 1 : -1) * m.data[i * size] * D(ma, size - 1);
        }
        free(temp);
        return sum;
    }
}
int Determinant(double &result, Matrix &m)
{
    if (m.n_cols != m.n_rows)
        return 1;
    result = D(m, m.n_cols);
    return 0;
}
// get the trace of Matrix
// Expected: m should be the square
int Trace(double &result, Matrix &m)
{
    if (m.n_cols != m.n_rows)
        return 1;
    result = 0.0;
    for (int i=0; i < m.n_rows; i++)
    {
        for (int j = 0; j < m.n_cols; j++)
            if(i == j)
            {
                result += m.data[i * m.n_rows + j];
                break;
            }
    }
    return 0;
}