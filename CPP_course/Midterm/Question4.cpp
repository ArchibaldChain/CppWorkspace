//
// Created by Archibald Chain on 2020/4/16.
//
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;
int m, n;

string encode(int const matrix[]){
    string temp = to_string(m)+to_string(n);
    int count = 1;
    for (int i = 1; i < sizeof(matrix); ++i) {
        if (matrix[i] == matrix[i-1])
        {
            count ++;
        }
        else{
            temp += "," + to_string(count);
            count = 1;
        }
    }
    if(count == 1)
        temp += ",1";
    return temp;
}

int str_to_num(const string& s){
    stringstream ss(s);
    int temp;
    ss >> temp;
}

int * decode(const string& str){
    stringstream s(str);
    vector<string> v; // using vector to seperate string
    string temp;
    while(getline(s, temp, ',')){
        v.push_back(temp);
    }
    int *matrix = new int[str_to_num(v[0])* str_to_num(v[1])];
    for (int i = 2, num = 0; i < v.size() && num < sizeof(matrix); ++i, ++num) {
         for(int j=0; j < str_to_num(v[i]);j++){
             matrix[num] = (pow(-1, i) + 1)/2;
         }
    }
    return matrix;
}



int main(){
    cin >> m;
    cin >> n;
    int matrix[m*n];
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i*n + j];
        }
    }
    string B = encode(matrix);
    cout << B << endl;
    int  * A = decode(B);
    delete[] A;
}



