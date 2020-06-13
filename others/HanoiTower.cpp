#include <stdio.h>
#include <math.h>

int main()
{
    int number;
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        int n = 0;
        scanf("%d", &n);
        double c = 1;
        for (int j = 0; j < n; j++)
        {
            c = c * 3;
            if (c >= 1000000007)
            {
                c -= 1000000007;
            }
        }
        char a = 'l', b = 'o', d = 'v', e = 'e';
        printf("%f.0\n", (c - 1));
    }
}
