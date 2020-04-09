#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

int main()
{

    ifstream fin;
    // Open an existing file
    fin.open("world_cities.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    while (fin.good())
    {
        row.clear();
        getline(fin, line);
        cout << line;

        // used for breaking words
        stringstream s(line);
        int count = 0;
        cout << count << " " << line << endl;
        getline(s, word, ',');
        while (getline(s, word, ','))
        {

            row.push_back(word);
        }

        cout << "1 " << row[0] << " : \n";
        cout << "2: " << row[1] << "\n";
        cout << "3: " << row[2] << "\n";
        cout << "4: " << row[3] << "\n";
        cout << "5: " << row[4] << "\n";
    }

    if (fin.eof()) // 3 ways to terminate the read the file
        cout << "End of file reached.\n";
    else if (fin.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";
}