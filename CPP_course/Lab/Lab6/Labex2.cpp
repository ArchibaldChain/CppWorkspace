#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
const int vn = 5;
const char vowel[vn] = {'a', 'e', 'i', 'o', 'u'};
int main()
{
    cout << "Enter words (q to quit):" << endl;
    int nVowel = 0;
    int nConsonant = 0;
    int nOther = 0;
    char word[30];
    while (cin >> word)
    {
        if (isalpha(word[0]))
        {
            if (strlen(word) == 1 && word[0] == 'q')
            {
                break;
            }
            char x = tolower(word[0]);

            bool flag = x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U';
            if (flag)
            {
                nVowel++;
            }
            else
            {
                nConsonant++;
            }
        }
        else
        {
            nOther++;
        }
    }
    cout << nVowel << " words begining with vowels" << endl
         << nConsonant << " words begining with consonants" << endl
         << nOther << " others" << endl;
    return 0;
}