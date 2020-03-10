#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

string input_str();
int main()
{
    string x = input_str();
    cout << x;
}

string input_str()
{
    string s;
    bool flag = true;
    int size;
    do
    {
        flag = true;     // set flag to be default ture
        getline(cin, s); // input the string
        char *chars = new char[s.length() + 1];
        // declare new char array to check each character seperately
        strcpy(chars, s.c_str());

        for (int i = 0; i < s.size() && flag; i++)
        {
            flag = (chars[i] >= 'A' && chars[i] <= 'Z') ||
                   (chars[i] >= 'a' && chars[i] <= 'z') ||
                   chars[i] == ',' || chars[i] == '\'' ||
                   chars[i] == ' ' || chars[i] == '.';
        }
        delete[] chars; // clear the memory
    } while (!flag && printf("Unexpected character, input again:\n"));

    return s;
}