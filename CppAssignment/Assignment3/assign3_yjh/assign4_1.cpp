#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "utf8.h"
using namespace std;
const string fileName = "Blocks.txt";
struct block{
    int begin;
    int end;
    string name;
    int times;
};
#define arrayLength 300
block block[arrayLength];
void openFile();
void checkCodePoint(int);
int showLanguage();
int openSuccess = 1;

int main(){
    openFile();
    if(openSuccess) {
        string str;
        string temp;
        unsigned char *p;
        int bytes_in_char;
        int i;
        unsigned int codepoint;
        char *ptr;

        //find codepoint
        while (getline(cin, str)) {
            stringstream sstr(str);
            while (getline(sstr, temp, ' ')) {
                for (i = 0; i < temp.length(); i++) {
                    ptr = &temp[i];
                    p = (unsigned char *) ptr;
                    while (*p) {
                        codepoint = utf8_to_codepoint(p, &bytes_in_char);
                        if (codepoint) {
                            checkCodePoint(codepoint);
                            _utf8_incr(p);
                        } else {
                            p++;
                        }
                    }
                }
            }
        }
        cout << block[showLanguage()].name;
    }
    return 0;
}

//input data in Blocks.txt
void openFile(){
    ifstream fin(fileName);
    if (fin.is_open()){
        string str;
        string temp = "0x";
        int i = 0;
        int dot = 0;
        int comma = 0;
        getline(fin, str);
        while(str != "# EOF"){
            if (str[0] != '#' && str != "\0"){
                for (dot = 0; dot < str.length(); dot ++){
                    if(str[dot] == '.'){
                        break;
                    }
                }
                for(int j = 0; j < dot; j++){
                    temp += str[j];
                }
                block[i].begin = stoi(temp,nullptr,16);
                temp = "0x";
                for(comma = dot + 2; comma < str.length(); comma++){
                    if(str[comma] == ';')
                        break;
                }
                for (int j = dot + 2; j < comma; j++){
                    temp += str[j];
                }
                block[i].end = std::stoi (temp,nullptr,16);
                temp = "";
                for (int j = comma + 2; j < str.length(); j++){
                    temp += str[j];
                }
                block[i].name = temp;
                ++i; dot = 0; comma = 0; temp = "0x";
            }
            getline(fin, str);
        }
    }
    else {
        cout << "Fail to input blocks.txt";
        openSuccess = 0;
    }
}

//find which language is the code
void checkCodePoint(int ptr){
    for(int i = 0; i<arrayLength; i++){
        if(block[i].begin <= ptr && block[i].end >= ptr){
            block[i].times += 1;
        }
    }
}

//find out the language that appears most frequently
int showLanguage(){
    int highest = 0; int address;
    for (int i = 0; i < arrayLength; i++){
        if (block[i].times > highest){
            highest = block[i].times;
            address = i;
        }
    }
    return address;
}