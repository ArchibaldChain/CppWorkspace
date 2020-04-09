#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    ifstream infile;
    infile.open("world_cities.csv", ios::in);

    ifstream fin;

    // Open an existing file
    fin.open("world_cities.csv", ios::in);

    // Get the roll number
    // of which the data is required
    int rollnum, roll2, count = 0;
    cout << "Enter the roll number "
         << "of the student to display details: ";
    cin >> rollnum;

    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word, temp;

    while (fin >> temp)
    {

        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);
        cout << line;

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'

        getline(s, word, ',');
        cout << "work" << word << endl;
        cout << "DDDDDDDDDDDDDDDDDDDDDD";
        while (printf("Here:") && getline(s, word, ','))
        {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        // convert string to integer for comparision
        roll2 = stoi(row[0]);

        // Compare the roll number
        if (roll2 == rollnum)
        {

            // Print the found data
            count = 1;
            cout << "1 " << row[0] << " : \n";
            cout << "2: " << row[1] << "\n";
            cout << "3: " << row[2] << "\n";
            cout << "4: " << row[3] << "\n";
            cout << "5: " << row[4] << "\n";
            break;
        }
    }
    if (count == 0)
        cout << "Record not found\n";
}