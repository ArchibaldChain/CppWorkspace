//
// Created by Archibald Chain on 2020/5/9.
//

#include "UTF8string.hpp"
#include <iostream>
#include "utf8.h"
#include <cstring>

using namespace std;
UTF8string::UTF8string() : string_("") {}

UTF8string::UTF8string(string str) : string_(std::move(str)) {}

UTF8string::UTF8string(const char *str)
{
    string_ = str;
}

//length in character for s implement
int UTF8string::length()
{
    auto pt = (unsigned char *)string_.c_str();
    return utf8_charlen(pt);
}

// length in bytes for s
int UTF8string::bytes()
{
    return string_.size();
}

/**
 * Find the postion of substring in string
 * @param substr
 * @return the code_point of the str
 */
int UTF8string::find(const string &substr)
{
    if (substr.empty() || substr.size() > string_.size())
        return 0;
    auto *text = (unsigned char *)string_.c_str();
    auto *pattern = (unsigned char *)substr.c_str();
    int count = 0; // count in the whole line
    while (*text)
    {
        auto pt = text;
        auto qt = pattern;
        // while matched a character
        while (*pt == *qt)
        {
            _utf8_incr(pt);
            _utf8_incr(qt);
            // till the end of substr is still equal
            if (*qt == '\0')
            {
                return count;
            }
            // pt reached end at first
            if (*pt == '\0')
            {
                return 0;
            }
        }
        // if the pattern didn't match to the current position let the current text move to next one
        _utf8_incr(text);
        count++;
    }
    return 0;
}

/**
 * repleace to_remove contents to replacement
 * @param to_remove
 * @param replacement
 * @return
 */
void UTF8string::replace(UTF8string to_remove, const UTF8string &replacement)
{
    string_.replace(string_.find(to_remove.getValue()), to_remove.bytes(), replacement.getValue());
}

/**
 * Combine two string
 * @param s
 * @return
 */
UTF8string UTF8string::operator+(const UTF8string &s) const
{
    return UTF8string(string_ + s.getValue());
}

void UTF8string::operator+=(const UTF8string &s)
{
    string_ += s.getValue();
}

/**
 * repeat the current string n times
 * @param n
 * @return new object
 */
UTF8string UTF8string::operator*(int n) const
{
    string temp = string_;
    for (int i = 0; i < n - 1; ++i)
    {
        temp.append(string_);
    }
    return UTF8string(temp);
}

/**
 * repeat the current string
 * @param n repeat time
 * @param s string that needed to repeat
 * @return new string
 */
UTF8string operator*(int n, UTF8string const &s)
{
    return s * n;
}

/**
 * inverse the current string by character
 * @return  a new object
 */
UTF8string UTF8string::operator!() const
{
    string temp;
    auto pt = (unsigned char *)string_.c_str();
    while (*pt)
    {
        // insert at the first place of the temp
        temp.insert(0, (char *)pt, (size_t)isutf8(pt));
        _utf8_incr(pt)
    }
    return UTF8string(temp);
}

ostream &operator<<(ostream &os, UTF8string const &s)
{
    os << s.string_;
    return os;
}