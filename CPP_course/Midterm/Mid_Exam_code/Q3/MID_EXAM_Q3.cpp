#include <fstream>
#include <iostream>
#include "maxtrix.h"
using namespace std;
// Construct a struct of Matrix.

Matrix matrix1, matrix2;
// Read from the specific filename
void ReadFromTXT(Matrix &matrix, const char *filename)
{
    ifstream f(filename);
    string str;
    getline(f, str);
    int col = 0;
    int row = 1;
    char *pc = (char *)malloc(sizeof(char) * str.size() * 2);
    strcpy(pc, str.c_str());
    char *token = strtok(pc, " ");
    while (token != NULL)
    {
        col += 1;
        token = strtok(NULL, " ");
    }
    free(pc);
    while (!f.eof())
    {
        getline(f, str);
        if (str != "")
            row += 1;
    }
    f.close();
    f.clear();
    f.open(filename);
    matrix.n_cols = col;
    matrix.n_rows = row;
    matrix.data = (double *)malloc(sizeof(double) * col * row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            f >> matrix.data[i * row + j];
    }
}


void ShowMatrix(Matrix &m)
{
    for (int i = 0; i < m.n_rows; i++)
    {
        for (int j = 0; j < m.n_cols; j++)
            cout << m.data[i * m.n_rows + j] << " ";
        cout << endl;
    }
}
int main()
{
    Matrix m1, m2;
    ReadFromTXT(m1, "../Matrix1.txt");
    ReadFromTXT(m2, "../Matrix2.txt");
    cout << "The first matrix is:" << endl;
    ShowMatrix(m1);
    cout << "The second matrix is:" << endl;
    ShowMatrix(m2);
    Matrix m;
    if (Add(m, m1, m2))
        cout << "The shapes of two matrices is not equal so they can't be added" << endl;
    else
    {
        cout << "The addition of the two matrices is:" << endl;
        ShowMatrix(m);
        free(m.data);
    }
    if (Subtract(m, m1, m2))
        cout << "The shapes of two matrices is not equal so they can't be  subtracted" << endl;
    else
    {
        cout << "The subtraction of the two matrices is:" << endl;
        ShowMatrix(m);
        free(m.data);
    }
    if (Products(m, m1, m2))
        cout << "The first matrix's col is not equal to the second's row, so   they can't be multiplied" << endl;
    else
    {
        cout << "The matrix multiplication of the two matrices is:" << endl;
        ShowMatrix(m);
        free(m.data);
    }
    if (EleProducts(m, m1, m2))
        cout << "The shapes of two matrices is not equal so they can't be  element-wise multiplied" << endl;
    else
    {
        cout << "The element-wise multiplication of the two matrices is:" <<
             endl;
        ShowMatrix(m);
        free(m.data);
    }
    double result;
    if (Determinant(result, m1))
        cout << "The first matrix is not square!" << endl;
    else
    {
        cout << "The first matrix is square!" << endl;
        cout << "The determinant of the first matrix is: " << result << endl;
        Trace(result, m1);
        cout << "The trace of the first matrix is: " << result << endl;
    }
    if (Determinant(result, m2))
        cout << "The second matrix is not square!" << endl;
    else
    {
        cout << "The second matrix is square!" << endl;
        cout << "The determinant of the second matrix is: " << result << endl;
        Trace(result, m2);
        cout << "The trace of the second matrix is: " << result << endl;
    }
    free(m1.data);
    free(m2.data);
}