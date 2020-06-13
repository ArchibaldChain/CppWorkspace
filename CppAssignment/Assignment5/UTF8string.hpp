//
// Created by Archibald Chain on 2020/5/9.
//

#include <iostream>
#include "utf8.h"

#ifndef ASSIGNMENT5_UTF8STRING_H
#define ASSIGNMENT5_UTF8STRING_H

using namespace std;
class UTF8string {
private:
    string string_;
public:
    /**
     * constructor
     */
    UTF8string();
    UTF8string(char const * str);
    explicit UTF8string(string str);
    string getValue()const {return string_;};

    //length in character for s implement
    int length();
    // length in bytes for s
    int bytes();
/**
 * Find the postion of substring in string
 * @param substr
 * @return the code_point of the str
 */
    int find(const string& substr);
    /**
    * repleace to_remove contents to replacement
    * @param to_remove
    * @param replacement
    * @return
    */
    void replace(UTF8string to_remove, const UTF8string& replacement);

/**
 * Combine two string
 * @param s
 * @return
 */
    UTF8string operator+(UTF8string const & s) const;

    /**
     * concave string to itself.
     * @param s
     */
    void operator+=(UTF8string const & s);
    //repeat the string
    UTF8string operator*(int n) const;
    friend UTF8string operator*(int n, UTF8string const & s);
    //reverse the string
    UTF8string operator!() const;

    friend ostream & operator<<(ostream & os, const UTF8string & s);


};

#endif //ASSIGNMENT5_UTF8STRING_H
