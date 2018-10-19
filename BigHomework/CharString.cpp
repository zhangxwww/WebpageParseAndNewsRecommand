#include "CharString.h"

CharString::CharString() {
    maxSize = INIT_SIZE;
    items = new wchar_t[maxSize];
    len = 0;
}

CharString::CharString(const CharString & cs)
{
    len = cs.length();
    maxSize = len + INCREMENT;
    items = new wchar_t[maxSize];
    for (int i = 0; i < len; i++) {
        items[i] = cs[i];
    }
}

CharString::~CharString() {
    delete[] items;
}

int CharString::indexOf(const wchar_t w)
{
    for (int i = 0; i < len; i++) {
        if (items[i] == w) {
            return i;
        }
    }
    return -1;
}

int CharString::indexOf(const CharString & cstr)
{
    int cLen = cstr.length();
    if (cLen > len) {
        return -1;
    }
    int i = 0;
    int j = 0;
    int * next = cstr.getNext();
    while (i < len && j < cLen) {
        if (j == -1 || items[i] == cstr[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }
    if (j >= cLen) {
        return i - cLen;
    }
    else {
        return -1;
    }   
}

int CharString::indexOf(const char c)
{
    const wchar_t w = c;
    return indexOf(w);
}

int CharString::indexOf(const std::wstring & wstr)
{
    CharString cs;
    cs = wstr;
    return indexOf(cs);
}

const int CharString::length() const
{
    return len;
}

int * CharString::getNext() const
{
    int * next = new int[len];
    int j = 0;
    next[0] = -1;
    int k = -1;
    while (j < len) {
        if (k == -1 || items[j] == items[k]) {
            k++;
            j++;
            next[j] = k;
        }
        else {
            k = next[k];
        }
    }
    return next;
}

CharString CharString::subString(const int startPos, const int endPos)
{
    if (startPos < 0 || endPos > len) {
        throw ERROR;
    }
    if (startPos >= endPos) {
        throw ERROR;
    }
    int newLen = endPos - startPos;
    CharString sub;
    for (int i = 0; i < newLen; i++) {
        sub.concat(items[startPos + i]);
    }
    return sub;
}

void CharString::concat(const CharString & cstr)
{
    int cstrLen = cstr.length();
    int newSize = maxSize;
    if (cstrLen + len >= newSize) {
        while (cstrLen + len >= newSize) {
            newSize += INCREMENT;
        }
        wchar_t * newItems = new wchar_t[newSize];
        for (int i = 0; i < len; i++) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
    }
    for (int i = 0; i < cstrLen; i++) {
        items[i + len] = cstr[i];
    }
    len += cstrLen;
}

void CharString::concat(const wchar_t w)
{
    if (len == maxSize) {
        maxSize += INCREMENT;
        wchar_t * newItems = new wchar_t[maxSize];
        for (int i = 0; i < len; i++) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
    }
    items[len] = w;
    len++;
}

void CharString::operator=(const CharString & cstr)
{
    int cLen = cstr.length();
    maxSize = cLen + INCREMENT;
    if (len) {
        delete[] items;
        items = new wchar_t[maxSize];
    }    
    len = cLen;
    
    for (int i = 0; i < cLen; i++) {
        items[i] = cstr[i];
    }
}

void CharString::operator=(const std::wstring & wstr)
{
    int sLen = wstr.length();
    maxSize = sLen + INCREMENT;
    if (len) {
        delete[] items;
        items = new wchar_t[maxSize];
    }
    len = sLen;
    
    for (int i = 0; i < len; i++) {
        items[i] = wstr[i];;
    }
}

wchar_t & CharString::operator[](const int index)
{
    if (index >= len) {
        throw ERROR;
    }
    return items[index];
}

wchar_t & CharString::operator[](const int index) const
{
    if (index >= len) {
        throw ERROR;
    }
    return items[index];
}

std::wostream & operator<<(std::wostream & out, const CharString & cs)
{
    std::locale loc(".936");
    out.imbue(loc);
    for (int i = 0; i < cs.length(); i++) {
        out << cs[i];
    }
    return out;
}

bool operator==(const CharString & cs1, const CharString & cs2)
{
    int len1 = cs1.length();
    int len2 = cs2.length();
    if (len1 != len2) {
        return false;
    }
    for (int i = 0; i < len1; i++) {
        if (cs1[i] != cs2[i]) {
            return false;
        }
    }
    return true;
}
