#include <iostream>
#include <cstring>
#define ARRAY_SZ 10

using namespace std;

int main(int argc, char const *argv[])
{
    int val = 3;

    cout << "val = " << val << " \n"
         << "Hello world" << endl;

    int *ip;
    int i;
    ip = (int *)malloc(sizeof(int) * ARRAY_SZ);

    for (i = 0; i < ARRAY_SZ; i++)
    {
        ip[i] = i;
    }
    free(ip);
    cout << *ip << endl;
    delete[] ip;
    cout << "ttest" << endl;
    char x[5];
    cin.getline(x, 5);
    cout
        << "test" << strcmp(x, "\n") << "**" << strcmp(x, "\0") << "**" << strcmp(x, "")
        << "**" << strcmp(x, "abcd");

    return 0;
}
