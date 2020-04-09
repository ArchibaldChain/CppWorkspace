#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    char words[80][10];
    int num = 0;
    cout << "Enter wors (to stop, tpye the word done):\n";
    for (int i = 0; i < 80 && strcmp(words[i - 1], "done\0"); i++)
    {

        cin >> words[i];
        num++;
    }

    cout << "You entered a total of " << num - 1 << "words" << endl;
    return 0;
}
