#include <iostream>
using namespace std;
void displaymenu()
{
    cout << "===================================================" << endl;
    cout << "                       MENU" << endl;
    cout << "===================================================" << endl;
    cout << "\t1.Add" << endl;
    cout << "\t2.Subtract" << endl;
    cout << "\t3.Multiply" << endl;
    cout << "\t4.Divide" << endl;
    cout << "\t5.Modulus" << endl;
}
int Add(int a, int b)
{
    return (a + b);
}
int Substract(int a, int b)
{
    return a - b;
}
int Multiply(int a, int b)
{
    return a * b;
}
float Divide(int a, int b)
{
    return a / b;
}

int Modulus(int a, int b)
{
    return a % b;
}
int main(int argc, char *argv[])
{
    displaymenu();
    int yourchoice;
    int a;
    int b;
    char confirm;
    do
    {
        cout << "Enter your choice(1-5):";
        cin >> yourchoice;
        cout << "Enter your two integer numbers:";
        cin >> a >> b;
        cout << "\n";
        switch (yourchoice)
        {
        case 1:
            cout << Add(a, b);
            break;
        case 2:
            cout << Substract(a, b);
            break;
        case 3:
            cout << Multiply(a, b);
            break;
        case 4:
            cout << Divide(a, b);
            break;
        case 5:
            cout << Modulus(a, b);
            break;
        }
        cout << "\nPress y or Y to continue:";
        cin >> confirm;
    } while (confirm == 'y' || confirm == 'Y');

    return EXIT_SUCCESS;
}