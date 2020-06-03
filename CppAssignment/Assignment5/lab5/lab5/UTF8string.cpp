#include <iostream>
#include <string>

#include "UTF8string.hpp"
#include "utf8.h"

using std::string;

size_t UTF8string::length() {
	// Convert std::string m_s to c string char[] pt
	unsigned char *pt = (unsigned char *)m_s.c_str();
    int lenptr = 0;
    int char_sum = 0;
    int codept = 0;
    do
    {
    	// Get the encoding of current character
    	codept = utf8_to_codepoint(pt, &lenptr);
    	pt += lenptr;
    	// Number of character plus 1
    	char_sum++;
    } while (codept != 0);

    // Discard the empty character at the end 
    return char_sum - 1;
}

size_t UTF8string::bytes() {
	// Convert std::string to c string char[] pt
    unsigned char *pt = (unsigned char *)m_s.c_str();
    int lenptr = 0;
    int lenptr_sum = 0;
    int codept = 0;
    do
    {
    	// Get the encoding of current character and its length in bytes
    	codept = utf8_to_codepoint(pt, &lenptr);
    	pt += lenptr;
    	// Number of total bytes plus 1
    	lenptr_sum += lenptr;
    } while (codept != 0);

    // Discard the empty character at the end
    return lenptr_sum - 1;
}

int UTF8string::find(std::string substr) {
	unsigned char *pt = (unsigned char *)m_s.c_str();
	unsigned char *qt = (unsigned char *)substr.c_str();
	int lenptr = 0;
	int codept = 0;

	if (sizeof(pt) < 1 || sizeof(pt) < sizeof(qt))
		return 0;

	int count1 = m_s.length();

	while (*pt != '\0')
	{
		unsigned char *txt = pt;
		unsigned char *pat = qt;
		int lenptr1 = 0;
		int lenptr2 = 0;
		int codept1 = 0;
		int codept2 = 0;

		// Proceed if the character in text string 
		// match the first character of pattern string
		while (*txt == *pat)
		{
			// Move pointer of text to the next character
			codept1 = utf8_to_codepoint(txt, &lenptr1);
			txt += lenptr1;
			// Move pointer of pattern to the next character
			codept2 = utf8_to_codepoint(pat, &lenptr2);
			pat += lenptr2;

			// Pattern string reaches end, found match
			if (*pat == '\0')
			{
				int count2 = 0;
				while (*pt != '\0')
				{
					codept = utf8_to_codepoint(pt, &lenptr);
					pt += lenptr;
					count2++;
				}

				return count1 - count2;
			}
			// Text string reaches end, not found
			if (*txt == '\0')
				return 0;
		}

		// Character in text string doesn't match the first character
		// of pattern string

		// Reset pattern pointer to the first character
		pat = qt;
		// Text pointer moves to the next character
		codept = utf8_to_codepoint(pt, &lenptr);
		pt += lenptr;
	}

	return 0;
}

void UTF8string::replace(UTF8string remove, UTF8string replacement) {
	size_t index = 0;
	while (true)
	{
		// Find the position of the substring to remove
		index = m_s.find(remove.value(), index);
		// If not found, return
		if (index == std::string::npos)
			return;

		// Replace string to remove by string replacement
		m_s.replace(index, remove.bytes(), replacement.value());
		// Move index of the beginning of find to the end of string replacement
		// after replacement, to find in the rest of the string
		index += remove.bytes();
	}
}
