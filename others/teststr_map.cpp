#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

#define FILENAME R"(I:\Programming\CppWorkspace\CPP_course\Assignment\world_cities.csv)"

const int maxLenName = 25; // maximum length name
const int arrayLen = 800;  // array length

using namespace std;
void test_length(string s);
int find_city(const string &s, const vector<int> &range);
int input_file(string fileName);
bool KMP(string text, string pat);
void setTheKMPArray(string pat);

struct Location
{
    string Country;
    string City;
    double latitude;
    double longitude;
} L[arrayLen];

static vector<int> range_vec;
void set_range_rect()
{
    for (int i = 0; i < arrayLen; i++)
    {
        range_vec.push_back(i);
    }
}

int input_file(string fileName)
{
    ifstream inFile;
    inFile.open(fileName, ios::in);
    if (!inFile.is_open())
    {
        cout << "Could not open the file: " << fileName << endl;
        cout << "Program terminating\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "file open succeed\n";
    }

    string line, word, temp;
    vector<string> row;
    int i = 0;
    while (inFile >> temp)
    {
        cout << i << endl; //todo
        row.clear();

        //read entire row, store it into line
        getline(inFile, line);
        // set string into stream so we can split it
        stringstream s(line);

        cout << i << "2"; //todo
        // put the item into vector
        while (getline(s, word, ','))
        {
            row.push_back(word);
            cout << "****" << endl;
        }
        cout << row[0]; //todo

        L[i].City = row[0];

        cout << i << "3"; // todo

        //test_length(L[i].City);
        L[i].Country = row[2];
        //test_length(L[i].Country);
        L[i].latitude = stoi(row[3]);
        L[i].longitude = stoi(row[4]);
        cout << L[i].City << endl;
        i++;
    }

    if (i == 0)
    {
        cout << "no data proceed\n";
        return 0;
    }
    if (!inFile.eof())
    {
        cout << "[warning] file reading incomplete\n";
        return 0;
    }
    else
    {
        cout << "End of file reached\n";
        cout << "Loading Complete\n";
        return 1;
    }
}

int KMP_array[arrayLen];

void setTheKMPArray(string pat)
{
    KMP_array[0] = 0;
    int pre = 0;
    int suf = 1;
    int i = 0;

    while (suf < pat.length())
    {
        if (pat[pre] == pat[suf])
        {
            // when the longest suffix still equals longest previous
            KMP_array[suf] = ++i;
            pre++;
            suf++;
        }
        else
        {
            while (pre > 0)
            {
                pre = KMP_array[pre - 1];
                if (pat[suf] == pat[pre])
                {
                    ++pre;
                    break;
                }
            }
            i = pre;
            KMP_array[suf] = i;
            suf++;
        }
    }
}

bool KMP(string text, string pat)
{
    setTheKMPArray(pat);
    for (int i = 0, j = 0; i < text.length(); i++)
    {
        if (text[i] == pat[j])
        {
            j++;
        }
        else
        {
            while (j > 0)
            {
                j = KMP_array[j - 1];
                if (text[i] == pat[j])
                {
                    j++;
                    break;
                }
            }
        }
        if (j == pat.length())
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "*******************************\n\n\n";
    input_file(FILENAME);
    string x, y;
    x = "ABCD";

    y = "dgdghhABCD";
    cout << KMP(y, x);
}