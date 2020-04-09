#include <iostream>

using namespace std;

int Fill_array(double arr[], int size)
{
    bool flag = true;
    int i;
    for (i = 0; i < size && flag; i++)
    {
        cout << "Enter the value #" << i + 1 << ":";
        cin >> arr[i];
        flag = cin.good();
    }
    return i;
}

void Show_array(double *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void Reverse_array(double *arr, int size, int i_0)
{
    double temp;
    for (int i = i_0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    double array[n];
    Fill_array(array, n);
    cout << "The output is as follow:" << endl;
    Show_array(array, n);
    Reverse_array(array, n, 0);
    Show_array(array, n);
    Reverse_array(array, n, 1);
    Show_array(array, n);
}