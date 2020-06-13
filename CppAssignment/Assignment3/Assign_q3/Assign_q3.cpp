// Create by Archibald
// 18th April

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include "utf8.h"

using namespace std;
const int block_length = 300; // The length which the unicode blokcs has
const char file_name[] = "Blocks.txt";

struct uni_block
{
    unsigned int beginpt; // begin block code point
    unsigned int endpt;   // end block code point
    string name;          // block name
    int count = 0;        // appeared times
} blocks[block_length];

//
// @ para: code point
// @ Function match the code point and count it using bisection
// @ return 1 if sucess in finding it, 0 otherwise
//
int count_times(unsigned int codept)
{

    int i = 0, j = block_length;
    int mid = (i + j) / 2;
    while (j - i > 1)
    {
        if (codept < blocks[mid].beginpt)
        {
            j = mid;
            mid = (i + j) / 2;
        }
        else
        {
            i = mid;
            mid = (i + j) / 2;
        }
    }

    if (blocks[i].beginpt <= codept && blocks[i].endpt >= codept)
    {
        blocks[i].count++;
        return 1;
    }
    return 0;
}

//
// @ using code come from provided demo
// Author: unknown
// Changes: parameter(int arg, char ** argv) -> (char *argv)
// @ para: char *  argv provided value
// @ return: int  codepoint
//
int set_utf8_to_codepoint(char *argv)
{
    unsigned char *pt;
    int bytes_in_char;
    int i;
    unsigned int codepoint;

    //cast the char array to unsigned char array
    pt = (unsigned char *)argv;
    while (*pt)
    {
        codepoint = utf8_to_codepoint(pt, &bytes_in_char);
        if (codepoint != 0)
        {
            cout << count_times(codepoint);
            // p += bytes_in_char;  // Same as the line that follows
            _utf8_incr(pt);
        }
        else
        {
            printf("%c Invalid UTF-8\n", *pt);
            pt++; // Try the next character
        }
    }
    return 1;
}

unsigned int hex_str_to_int(const char str[])
{
    unsigned int x;
    stringstream ss;
    ss << std::hex << str;
    ss >> x;
    return x;
    // return std::stou(str, nullptr, 16);
}

//
// @ para: "blocks.txt" file name and path
// @ Function: read blocks and set the struct
// @ return: function nicely return 1, 0 other wise
//
int set_unicode_blocks(const char *file = file_name)
{
    ifstream inFile(file);
    if (!inFile.is_open())
    { //failed to open the file terminating the file
        cout << "Could not open the file " << file << endl;
        cout << "Program Terminating\n";
        return EXIT_FAILURE;
    }

    string line, name, temp, num_part, char_part;
    char startpt[10], endpt[10];
    vector<string> v;
    for (size_t i = 0; i < block_length && inFile.good(); i++)
    {
        getline(inFile, line);
        if (line[0] == '#' || line[0] == '\0')
        { // For the note and empty line
            i--;
            continue;
        }

        stringstream ss(line); // separate the line by ';'
        while (getline(ss, temp, ';'))
        {
            v.push_back(temp);
        }
        num_part = v[0];
        char_part = v[1];
        v.clear();

        bool flag = true;
        for (int i = 0, j = 0; i < num_part.size(); i++)
        {
            if (num_part[i] == '.')
            {
                flag = false;
                continue;
            }
            if (flag)
            {
                startpt[i] = num_part[i];
            }
            else
            {
                endpt[j] = num_part[i];
                j++;
            }
        }
        blocks[i].beginpt = hex_str_to_int(startpt);
        blocks[i].endpt = hex_str_to_int(endpt);
        blocks[i].name = char_part;
    }

    // read file ending
    if (inFile.eof())
    {
        cout << "End of File reached.\n";
        return 1;
    }
    else if (inFile.fail())
    {
        cout << "Input mismatched.\n";
        return 0;
    }
    else
    {
        cout << "Reading File ended for unknown reason.\n";
        return 0;
    }
}

//
// @ para: void
// @ function: find the block with biggest count
// @ return: uni_block
//
uni_block find_block()
{
    int temp = 0;
    for (auto &block : blocks)
    {
        if (block.count > temp)
        {
            temp = block.count;
        }
    }
    return blocks[temp];
}

int main()
{
    cout << set_unicode_blocks(); // cout 1 if succeed, 0 otherwise
    string s;
    const int char_length = 4000;
    char temp[char_length];

    while (cin.getline(temp, char_length))
    {
        if (strcmp(temp, "\n") == 0 || strcmp(temp, "\0") == 0)
        {
            continue;
        }
        char *pt = strtok(temp, " ");
        set_utf8_to_codepoint(pt);
    }

    cout << endl
         << find_block().name;
}