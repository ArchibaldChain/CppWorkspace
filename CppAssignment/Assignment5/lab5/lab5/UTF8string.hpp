#ifndef UTF8STRING_HPP
#define UTF8STRING_HPP

#include <cstring>
#include <iostream>
#include <string>
#include "utf8.h"

// THIS FILE DOESN'T NEED TO BE MODIFIED
// YOU NEED TO WRITE UTF8string.cpp

class UTF8string {
    std::string m_s;

  public:
    // Constructors - No code required
    UTF8string(){};
    UTF8string(const char *s) { m_s = std::string(s); };
    UTF8string(std::string s) { m_s = s; };
    //
    // The four following functions need to be coded
    // in UTF8string.cpp
    //
    size_t length(); // Number of UTF-8 characters in the string
    size_t bytes();  // Number of bytes in the string
    // IMPORTANT: for find(), 1st character = 1 (not zero)
    // Return 0 if not found
    int find(std::string substr);
    void replace(UTF8string remove, UTF8string replacement);
    // ---------------------------------------
    // value() is for checking what was done
    // No code required
    std::string value() const { return m_s; };

    UTF8string operator+(const UTF8string &str) {
        std::string output;
        output += this->m_s;
        output += str.value();
        return UTF8string(output);
    }

    void operator+=(const UTF8string &str) { this->m_s += str.value(); }

    UTF8string operator*(const int n) const {
        std::string str = "";
        if (n == 0)
            return str;

        // Append the string to repeat to the end of the output string n times
        for (int i = 0; i < n; ++i) {
            str.append(this->value());
        }
        return UTF8string(str);
    }

    friend UTF8string operator*(const int n, const UTF8string &str) { return str * n; }

    UTF8string operator!() const {
        // Convert the std::string m_s to c string pt
        unsigned char *pt = (unsigned char *)this->m_s.c_str();
        int length = strlen(this->m_s.c_str());
        // The target c string which will become reverse original string
        char *c_str = new char(length + 1);
        // Fill the last character of c string c_str with '\0'
        c_str[length] = 0;
        while (*pt != '\0') {
            // Get the byte length of the current character of the original string
            int lenptr = isutf8(pt);
            // Fill the current character in the desired position of the target string byte by byte
            for (int j = 0; j < lenptr; ++j) {
                c_str[length - lenptr + j] = pt[j];
            }
            length -= lenptr;
            // Move the pointer to original string to the next character
            pt += lenptr;
        }
        // Return the UTF8string constructed by the target string
        return UTF8string(std::string(c_str));
    }

    // Overload << to directly output the value of the UTF8string when called on a UTF8string
    friend std::ostream &operator<<(std::ostream &output, UTF8string const &u) {
        output << u.value();
        return output;
    }
};

#endif
