#ifndef CHAR_STRING_H
#define CHAR_STRING_H

#include "Status.h"
#include <string>
#include <iostream>

class CharString {
public:
    CharString();
    CharString(const CharString & cs);
    ~CharString();

    int indexOf(const wchar_t w);
    int indexOf(const CharString & cstr);
    int indexOf(const char c);
    int indexOf(const std::wstring & wstr);
    CharString subString(const int startPos, const int endPos);
    void concat(const CharString & cstr);
    void concat(const wchar_t w);
    void operator= (const CharString & cstr);
    void operator= (const std::wstring & wstr);

    wchar_t & operator[] (const int index);
    wchar_t & operator[] (const int index) const;
    const int length() const;
    int * getNext() const;
    friend std::wostream & operator<< (std::wostream & out, 
        const CharString & cs);
    friend bool operator== (const CharString & cs1
        ,const CharString & cs2);

private:
    static const int INIT_SIZE = 50;
    static const int INCREMENT = 20;
    wchar_t * items;
    int len;
    int maxSize;

};

#endif // !CHAR_STRING_H
