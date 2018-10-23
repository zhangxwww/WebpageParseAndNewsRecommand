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

    int indexOf(const wchar_t w) const;
    int indexOf(const CharString & cstr) const;
    int indexOf(const char c) const;
    int indexOf(const std::wstring & wstr) const;
    CharString subString(const int startPos, 
        const int endPos) const;
    CharString subString(const int startPos) const;
    void concat(const CharString & cstr);
    void concat(const wchar_t w);
    void concat(const wchar_t * pw);
    void operator= (const CharString & cstr);
    void operator= (const std::wstring & wstr);

    wchar_t & operator[] (const int index);
    wchar_t & operator[] (const int index) const;
    const int length() const;
    int * getNext() const;
    const std::wstring wstring() const;
    const wchar_t * wchar() const;
    CharString trim();
    friend std::wostream & operator<< (std::wostream & out,
        const CharString & cs);
    friend bool operator== (const CharString & cs1,
        const CharString & cs2);

private:
    static const int INIT_SIZE = 50;
    static const int INCREMENT = 20;
    wchar_t * items;
    int len;
    int maxSize;

};

#endif // !CHAR_STRING_H
