//We test between two sacanf, if first goes wrong, what will happen the second one.
#include <iostream>

int main()
{
    using namespace std;
    int a;
    int b = scanf("%d", &a);
    cout << b;
    setbuf(stdin, NULL); // This is important, when you make scanf returns 0, you need to clear the beff.
    b = scanf("%d", &a);

    cout << b;
}