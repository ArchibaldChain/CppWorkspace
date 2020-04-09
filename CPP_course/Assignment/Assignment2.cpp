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
int find_city(string s, vector<int> range);
int input_file(string fileName);
bool KMP(string text, string pat);
void setTheKMPArray(string pat);
string to_lowercase(string s);
double cal_dis(int i, int j);


struct Location
{
    string Country;
    string City;
    double latitude;
    double longitude;
} L[arrayLen];

static vector<int> range_vec;
// give a full range
void set_range_rect(){
    for (int i = 0; i < arrayLen; i++){
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
    } else{
        cout << "file open succeed\n";
    }

    string line,word, temp;
    vector<string> row;
    int i = 0;
    for(i=0; i < arrayLen && inFile.good() ; i++ ){
        row.clear();

        //read entire row, store it into line
        getline(inFile, line);
        // set string into stream so we can split it
        stringstream s(line);
        // put the item into vector
        while(getline(s, word, ',')){
            row.push_back(word);
        }
        s.clear();

        L[i].City = row[0];
        test_length(L[i].City);
        L[i].Country = row[2];
        test_length(L[i].Country);
        L[i].latitude = stoi(row[3]);
        L[i].longitude = stoi(row[4]);
    }

    if(i == 0){
        cout << "no data proceed\n";
        return 0;
    } else if (i == arrayLen && !inFile.eof()){
        cout << "[warning] file reading incomplete\n";
        return 1;
    }

    if(inFile.eof()){
        cout << "End of file reached\n";
        cout << "Loading Complete\n";
        return 1;
    } else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";
    return 0;
}

//test weather the input is too long
void test_length(string s){
    if (s.length() > maxLenName)
       cout << s << "[warning] exceeds max length" << maxLenName << endl;
}

int KMP_array[maxLenName];

string to_lowercase(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 'a' - 'A';
    }
    return s;
}

int find_city(string s, vector<int> range){
    if (s.length() < 3){
        cout << "[warning] input is too short\n";
        cout << "Please input again"<<endl;
        getline(cin, s);
        return find_city(s, range);
    } else if(s.length() > maxLenName){
        cout << "[warning] input is too long\n";
        cout << "Please input again"<<endl;
        getline(cin, s);
        return find_city(s, range);
    }

    bool flag = false;
    vector<int> cities;
    // get all names contains it.
    s = to_lowercase(s);
    for (int i : range){
        if (KMP(to_lowercase(L[i].City), s)){
            flag = true;
            cities.push_back(i);
        }
    }

    // if did not match anything than recurse
    string str;
    if(!flag) {
        cout << "[warning] city not found\n";
        cout << "Please input again:" << endl;
        getline(cin, str);
        return find_city(str, range_vec);
    }

    // if find one city, then return it
    if(cities.size() == 1){
        cout << L[cities[0]].City << endl;
        return cities[0];
    }
    else if(cities.size() > 1){
        // if find more than one cities matched.

        // if there are several matches, with one with equal length
        for (int city : cities){
            if(L[city].City.length() == s.length()){
                cout << L[cities[0]].City << endl;
                return cities[0];
            }
        }

        cout << "\nThere are " << cities.size() << " matches\n";

        for (int city : cities){
            cout << L[city].City << "\t";
        }
        cout << "\nPlease input more detail:" << endl;
        getline(cin, str);
        return find_city(str, cities);
    }
    else return 0;
}

void setTheKMPArray(string pat){
    KMP_array[0] = 0;
    int pre = 0;
    int suf = 1;
    int i = 0;

    while (suf < pat.length()){
        if(pat[pre] == pat[suf]){
            // when the longest suffix still equals longest previous
            KMP_array[suf] = ++i;
            pre++;
            suf++;
        } else {
            while(pre > 0){
                pre = KMP_array[pre - 1];
                if(pat[suf] == pat[pre]){
                    ++pre;
                    break;
                }
            }
            i = pre;
            KMP_array[suf] = i;
            suf ++;
        }
    }
}

bool KMP(string text, string pat){
    setTheKMPArray(pat);
    for (int i = 0,j = 0; i < text.length(); i++) {
        if(text[i] == pat[j]){
            j++;
        } else {
            while(j > 0){
                j = KMP_array[j - 1];
                if(text[i] == pat[j]){
                    j++;
                    break;
                }
            }
        }
        if (j == pat.length()){
            return true;
        }
    }
    return false;
}

double cal_dis(int i, int j){
    // used to calculate the distance
    const double PI = 3.141592653;
    const int R = 6371; // radius of earth
    double fir_lati = L[i].latitude;
    double fir_longi = L[i].longitude;
    double sec_lati = L[j].latitude;
    double sec_longi = L[j].longitude;

    double phi1 = 90 - fir_lati;
    double phi2 = 90 - sec_lati;

    double c = sin(phi1 / 180 * PI) * sin(phi2 / 180 * PI) *
        cos(fir_longi / 180 * PI - sec_longi / 180 * PI) +
        cos(phi1 / 180 * PI) * cos(phi2 / 180 * PI);
    double d = R * acos(c);
    return d;
}


int main() {
    input_file(FILENAME);

    int m,n;
    string fir, sec;
    set_range_rect();

    while(!cin.fail()) {
        cout << "Input the first city: ";
        getline(cin, fir);
        if (0 == strcmp(to_lowercase(fir).c_str(), "bye\0")){
            cout << "program ending" << endl;
            break;
        }
        m = find_city(fir, range_vec);
        cout << "Input the second city: ";
        getline(cin, sec);
        if (0 == strcmp(to_lowercase(fir).c_str(), "bye\0")){
            cout << "program ending" << endl;
            break;
        }
        n = find_city(sec, range_vec);
        cout << "The distance between " << L[m].City << " and "
            << L[n].City << " is " << cal_dis(m, n) << " km"<< endl;
    }
    return 0;
}
