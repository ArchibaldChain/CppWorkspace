#include <iostream>

int main()
{
    using namespace std;
    char ch;
    int count = 0;
    cin.get(ch);                // attempt to read a char
    while (cin.fail() == false) // test for EOF
    {
        cout << ch; // echo character
        ++count;
        cin.get(ch); // attempt to read another char
    }
    cout << endl
         << count << " characters read\n";
    return 0;
}
// When type <ctrl> + <Z> <ENTER> exit the input while in windows
// in other OS, it's <ctrl> + <D>