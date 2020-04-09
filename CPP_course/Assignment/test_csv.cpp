#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    // ifstream infile;
    // infile.open("world_cities.csv", ios::in);
    // string item;
    // string line;
    // getline(infile, line);

    // getline(infile, item, ',');
    // while (infile)
    // {
    //     cout << item << "^^";
    //     getline(infile, item, ',');
    // }
    // cout << "line" << line << endl;

    // File pointer
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

    if (!fin.is_open())
    {
        cout << "Could not open the file" << endl;
        cout << "Program terminating\n";
        exit(EXIT_FAILURE);
    }

    while (fin)
    {
        cout << "555555555555";
        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ','))
        {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        // convert string to integer for comparision
        roll2 = stoi(row[0]);

        // Compare the roll number

            // Print the found data
            count = 1;
            cout << "1 " << row[0] << " : \n";
            cout << "2: " << row[1] << "\n";
            cout << "3: " << row[2] << "\n";
            cout << "4: " << row[3] << "\n";
            cout << "5: " << row[5] << "\n";
    }
    if (count == 0)
        cout << "Record not found\n";
}