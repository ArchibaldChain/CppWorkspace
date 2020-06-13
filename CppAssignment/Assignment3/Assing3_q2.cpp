#include <iostream>

using namespace std;
int m, n;
void left(int mat[], int x, int y);
void down(int mat[], int x, int y);
void up(int mat[], int x, int y);
void right(int mat[], int x, int y);

/**
 The funciton return the matrix in the current number
 If the index is out of bound, return -1
**/
int matrix(int matrix[], int x, int y)
{
    if (x >= 0 && y >= 0 && x < m && y < n)
        return matrix[x * n + y];
    else
        return -1;
}

/*
The function let the left element + 1
*/
void left(int mat[], int x, int y)
{
    if (matrix(mat, x, y) == m * n)
        return;

    if (matrix(mat, x, y - 1) == 0)
    {
        mat[x * n + y - 1] = matrix(mat, x, y) + 1;
        left(mat, x, y - 1);
    }
    else
        down(mat, x, y);
}

/*
The function let the down element + 1
*/
void down(int mat[], int x, int y)
{
    if (matrix(mat, x, y) == m * n)
        return;
    if (matrix(mat, x + 1, y) == 0)
    {
        mat[(x + 1) * n + y] = matrix(mat, x, y) + 1;
        down(mat, x + 1, y);
    }
    else
    {
        right(mat, x, y);
    }
}

/*
The function let the right element + 1
*/
void right(int mat[], int x, int y)
{
    if (matrix(mat, x, y) == m * n)
        return;
    if (matrix(mat, x, y + 1) == 0)
    {
        mat[x * n + y + 1] = matrix(mat, x, y) + 1;
        right(mat, x, y + 1);
    }
    else
        up(mat, x, y);
}

/*
The function let the up element + 1
*/
void up(int mat[], int x, int y)
{
    if (matrix(mat, x, y) == m * n)
        return;
    if (matrix(mat, x - 1, y) == 0)
    {
        mat[(x - 1) * n + y] = matrix(mat, x, y) + 1;
        up(mat, x - 1, y);
    }
    else
        left(mat, x, y);
}

/*
Dispaly the matrix
*/
void show_matrix(int matrix[])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i * n + j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> m >> n;
    int matrix[m * n] = {0};
    matrix[n - 1] = 1;
    left(matrix, 0, n - 1);
    show_matrix(matrix);
}
