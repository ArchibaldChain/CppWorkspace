#include <iostream>

enum spectrum
{
    red,
    orange,
    yellow,
    green,
    blue,
    violet,
    indigo,
    ultraviolet
};
int main()
{
    spectrum color1 = violet;
    std::cout << color1;
    // color1 += 3;  invalid
    // color1 = 3 + color1;  invalid
    // color1 =  3+red; invalid , intager cannot be converted into enumeration
    int a = yellow + blue;
    std::cout << a;
    spectrum color2 = spectrum(3), color3 = spectrum(10);
    std::cout << "\n"
              << color2 << "\t" << color3;
    enum bits
    {
        one = 1,
        two = 2,
        four = 4,
        eight = 8
    };
    bits myflag;
    myflag = bits(6);
    std::cout << myflag;
}