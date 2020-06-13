#include <iostream>

using namespace std;

template <class T>
T max5(T t[])
{
    T temp = *t;
    for (int i = 0; i < 5; i++)
    {
        if (*(t + i) > temp)
            temp = *(t + i);
    }
    return temp;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    double b[] = {1.1, 2.0, 3.0, 4.0, 5.1};

    cout << "Max int = " << max5(a) << endl;
    cout << "Max double = " << max5(b) << endl;
    return 0;
}