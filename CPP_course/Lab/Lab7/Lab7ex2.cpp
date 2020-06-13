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

box set_box(box b)
{
    b.height = 3.4;
    b.width = 4.5;
    b.length = 5.6;
    b.volume = 0;
    strcpy(b.maker, "Jinan University");

    cout << "Maker:" << b.maker << endl;
    cout << "Height:" << b.height << endl;
    cout << "Length:" << b.length << endl;
    cout << "Width:" << b.width << endl;
    cout << "volume:" << b.volume << endl;

    return b;
}

void change_box(box *b)
{
    b->volume = b->length * b->height * b->width;
}

int main()
{
    cout << "before setting valume:" << endl;
    box b;
    b = set_box(b);

    cout << "After setting valume:" << endl;
    change_box(&b);

    cout << "Maker:" << b.maker << endl;
    cout << "Height:" << b.height << endl;
    cout << "Length:" << b.length << endl;
    cout << "Width:" << b.width << endl;
    cout << "volume:" << b.volume << endl;

    return 0;
}