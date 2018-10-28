#ifndef CHAR_STRING_LINK_H
#define CHAR_STRING_LINK_H

#include "CharStringLinkNode.h"
#include <iostream>

class CharStringLink {
public:
    CharStringLink();
    CharStringLink(const CharStringLink & csl);
    ~CharStringLink();

    void add(const CharString cs);
    void add(const CharString cs, int index);
    bool remove(const int index);
    bool remove(const CharString & cs);
    int search(const CharString & cs);

    int length() const;
    CharString getItem(int index);
    CharStringLinkNode * getHead() const;
    void operator= (const CharStringLink & csl);
    void append(const CharStringLink & csl);
    friend std::wostream & operator<< (std::wostream & out,
        const CharStringLink & csl);

private:
    CharStringLinkNode * head;
    CharStringLinkNode * curPos;
    int curIndex;
    int len;
};

#endif // !CHAR_STRING_LINK_H
