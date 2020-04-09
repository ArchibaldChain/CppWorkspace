#include <iostream>

using namespace std;

int main()
{
    int quiz, mid, final;
    double grade;
    cout << "Input the average quiz: ";
    cin >> quiz;
    cout << "Input the average mid-term: ";
    cin >> mid;
    cout << "Input the average final scores: ";
    cin >> final;
    grade = (quiz + mid + final) / 3;

    if (grade >= 90)
        cout << 'A';
    else if (grade >= 70)
        cout << 'B';
    else if (grade >= 50)
        cout << 'C';
    else
        cout << 'F';
    return 0;
}
