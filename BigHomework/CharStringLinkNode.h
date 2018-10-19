#ifndef CHAR_STRING_LINK_NODE_H
#define CHAR_STRING_LINK_NODE_H

#include "CharString.h"

class CharStringLinkNode {
public:
    CharStringLinkNode();
    CharStringLinkNode(const CharString & cs);
    ~CharStringLinkNode();

    CharStringLinkNode * getNext() const;
    void setNext(CharStringLinkNode * next);
    CharString getCharString() const;
    void setCharString(const CharString & cs);

private:
    CharString charString;
    CharStringLinkNode * next;
};

#endif // !CHAR_STRING_LINK_NODE_H
