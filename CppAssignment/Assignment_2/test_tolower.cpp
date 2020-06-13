#include <iostream>
#include <cstring>
using namespace std;

string to_lowercase(string s);

int main()
{
    string s = "SASds";
    s[2] = 'a';
    // cout << s;
    getline(cin, s);
    cout << strcmp(to_lowercase(s).c_str(), "abcd\0");

    cout << endl;
    if (0 == strcmp(to_lowercase(s).c_str(), "bye"))
    {
        cout << "program ending" << endl;
        cout << strcmp(to_lowercase(s).c_str(), "bye\n");
        cout << strcmp(to_lowercase(s).c_str(), "bye\0");
        cout << strcmp(to_lowercase(s).c_str(), "bye");
    }
    else
    {
        cout << "wrong";
        cout << strcmp(to_lowercase(s).c_str(), "bye\n");
    }
}

string to_lowercase(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 'a' - 'A';
    }
    cout << s;
    return s;
}