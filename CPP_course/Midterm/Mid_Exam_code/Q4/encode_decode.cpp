//
// Created by jyh on 2020/4/22.
//
#include "encode_decode.h"
#include <iostream>
#include <vector>
using namespace std;

//static char *ArrayToString(int array[], int length) {
//
//    char *str;
//    str = (char *) malloc(LENGTH);
//    char str_temp[LENGTH] = {'\0'}; //总字符串临时结果
//    char num_temp[20]; //数字转换得到字符串
//    for (int i = 0; i <= length; i++) {
//        sprintf(num_temp, "%d", array[i]);
//        strcat(str_temp, num_temp);
//        if (i != length)
//            strcat(str_temp, ",");
//    }
//    strcpy(str, str_temp);
//
//
//
//
//    return str;
//}


static string ArrayToString(int array[], int length) {

    string str;
    for (int i = 0; i <= length; i++) {
        str.append(std::to_string(array[i])+",");
    }
    return str;
}

/**
 * This function is to split the string by a certain string
 * @param s The initial string
 * @param c The split string
 * @return A vector that store the strings after splitting
 */
vector<string> split(const string &s, const string &c) {
    vector<string> v;
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (string::npos != pos2) {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length()) {
        v.push_back(s.substr(pos1));
    }
    return v;
}

string encode(int **mask, int m, int n) {
    int result[LENGTH] = {m, n};


    int index = 2; //前两位记录数组尺寸
    int repeat_count = 1;
    int previous = 0;
    int current = 0;

    // 记录每个数字重复的次数
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (i + j == 0) { //跳过第一个元素
                previous = 1;
            }
            else { //判断接下来的元素

                current = *((int *) mask + n * i + j);
                if (current == previous) { //元素与上一个相同
                    repeat_count++;
                    previous = current;
                } else { //元素与上一个不同
                    previous = current;
                    result[index] = repeat_count;
                    index++;
                    repeat_count = 1;
                }
            }
        }
    result[index] = repeat_count; //补全末尾

    // 将 result 数组转为字符串

    return ArrayToString(result, index);
}



int **decode(string code) {
    vector<string> v1 = split(code, ",");
    int row = atoi(v1[0].c_str());
    int col = atoi(v1[1].c_str());
    int**  maxtrix =  new int *[row];
    for(int i =0;i<row;i++){
        maxtrix[i] = new int[col];

    }
    int t_row=0,t_col = 0;
    int curValue = 1;
    for (int i=2;i<v1.size();i++)
    {
        int len = atoi(v1[i].c_str());
        for(int j=0;j<len;j++)
        {
            maxtrix[t_row][t_col]=curValue;
            t_col++;
            if(t_col>(col-1)){
                t_col = t_col%col;
                t_row++;
            }

        }
        curValue= curValue?0:1;
    }

    return maxtrix;
}


