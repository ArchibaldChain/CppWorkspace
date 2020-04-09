#include <iostream>

using namespace std;

int main()
{
    int fib_n = 0;
    int fib_n1 = 1;
    int temp;
    int max;
    cout << "Enter a positve number:";
    cin >> max;
    cout << "\nFibonacci Series: " << fib_n1 << " ";
    while (fib_n1 < max)
    {
        cout << fib_n1 << " ";
        temp = fib_n1;
        fib_n1 += fib_n;
        fib_n = temp;
    }

    fib_n = 0;
    fib_n1 = 1;
    cout << "\nFibonacci Series: " << fib_n1 << " ";
    do
    {
        cout << fib_n1 << " ";
        temp = fib_n1;
        fib_n1 += fib_n;
        fib_n = temp;
    } while (fib_n1 < max);
}