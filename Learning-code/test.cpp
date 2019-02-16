#include <iostream>
#define ARRAY_SZ 10

using namespace std;

int main(int argc, char const *argv[])
{
    int val = 3;
    
    cout << "val = "<< val << " \n" << "Hello world"<<endl ;

    int *ip;
    int i;
    ip = (int *)malloc(sizeof(int)*ARRAY_SZ);
    
    for( i = 0; i < ARRAY_SZ; i++)
    {
        ip[i] = i;
    }
    free(ip);
    cout << *ip << endl;
    delete[] ip;

    return 0;
    
}
    