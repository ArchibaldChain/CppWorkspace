#include <iostream>

using namespace std;

int main()
{
    int num;
    int sum = 0;
    do
    {
        cout << "Enter integer number: ";
        while (!(cin >> num))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "A number is expected" << endl;
        }
        sum += num;
        cout << "The cumulative sum of the entries to data is: " << sum << endl;
    } while (num != 0);
}