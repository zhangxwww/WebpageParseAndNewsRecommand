#include "CharStringLinkNode.h"

CharStringLinkNode::CharStringLinkNode()
{
    next = nullptr;
}

CharStringLinkNode::CharStringLinkNode(const CharString & cs)
{
    charString = cs;
    next = nullptr;
}

CharStringLinkNode::~CharStringLinkNode()
{
}

CharStringLinkNode * CharStringLinkNode::getNext() const
{
    return next;
}

void CharStringLinkNode::setNext(CharStringLinkNode * next)
{
    this->next = next;
}

CharString CharStringLinkNode::getCharString() const
{
    return charString;
}

void CharStringLinkNode::setCharString(const CharString & cs)
{
    this->charString = cs;
}
