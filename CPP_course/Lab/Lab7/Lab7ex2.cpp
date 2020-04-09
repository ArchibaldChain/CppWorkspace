#include <iostream>
#include <cstring>

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
using namespace std;

box fun1()
{
    box b = {
        "", 3.4, 4.5, 5.6, 0
    };
    strcpy(b.maker,"Jinan University" );


    return b;
}

box fun2(box b)
{
    b.volume = b.length * b.height * b.width;
    strcpy(b.maker, "Jinan University" );
    return b;
}

int main()
{
    cout << "before setting valume:" << endl;
    box b = fun1();
    cout << b.maker << endl;
    cout << b.height << endl;
    cout << b.length << endl;
    cout << b.width << endl;
    cout << b.volume << endl;

    cout << "After setting valume:" << endl;
    box b2 = fun2(b);

    cout << b2.maker << endl;
    cout << b2.height << endl;
    cout << b2.length << endl;
    cout << b2.width << endl;
    cout << b2.volume << endl;
}