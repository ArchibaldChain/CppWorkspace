#include <stdio.h>
#include <math.h>

int find(int *a, int n)
{

    int temp = a[0], diff = a[0] - a[1];
    for (int j = 1; j < n; j++)
    {
        if (diff < temp - a[j])
            diff = temp - a[j];
        if (temp <= a[j])
            temp = a[j];
    }
    return diff;
}

int main()
{
    int number;
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        int n = 0;
        scanf("%d", &n);
        int a[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }
        printf("%d\n", find(a, n));
    }
}
