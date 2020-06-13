#include <iostream>

int fun(int *a[])
{
    std::cout << ")))))))))))))))))))";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < i; j++)
        {
            *(a[i] + j) = i + j;
            std::cout << *(a[i] + j) << " ";
        }

        std::cout << std::endl;
    }
    return 0;
}
int main()
{
    int **a;
    a = new int *[10];
    for (int i = 0; i < 10; i++)
    {
        a[i] = new int[i];
    }
    fun(a);
}
