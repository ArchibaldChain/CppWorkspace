//
// Created by Archibald Chain on 2020/4/16.
//
#include <iostream>
#include <cstring>

using namespace std;

struct Student
{
    string name;
    long id;
    int num_books;
    int bor_days[];
};

double compute_cost(Student const &s)
{
    double total = 0;
    for (int i = 0; i < s.num_books; i++)
    {
        if ((s.bor_days)[i] > 60)
        {
            total += (s.bor_days)[i] - 60 + (60 - 30) * 0.5;
        }
        else if (s.bor_days[i] > 30)
        {
            total += 0.5 * (s.bor_days[i] - 30);
        }
    }
    return total;
}

int main()
{
    string name;
    cout << "Please input the name of student: ";
    getline(cin, name);
    cout << "Please input the Student ID of this student: ";
    int id;
    cin >> id;
    cout << "Number of books this student borrowed: ";
    int num_books;
    cin >> num_books;
    cout << "The borrowing days are: ";
    int t[4];
    for (int i = 0; i < num_books; i++)
    {
        cin >> t[i];
    }
    Student s = {
        name,
        id,
        num_books};

    memcpy(s.bor_days, t, s.num_books);
    cout << "If the student returns all the books today, he should pay:"
         << compute_cost(s) << "RMB" << endl;
}
