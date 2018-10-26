#include "CharStringLinkNode.h"

CharStringLinkNode::CharStringLinkNode() {
    std::cout << "Con" << std::endl;
    next = nullptr;
}

CharStringLinkNode::CharStringLinkNode(const CharString & cs) {
    std::cout << "Con" << std::endl;
    charString = cs;
    next = nullptr;
}

CharStringLinkNode::~CharStringLinkNode() {
    std::cout << "De" << std::endl;
}

CharStringLinkNode * CharStringLinkNode::getNext() const {
    return next;
}

void CharStringLinkNode::setNext(CharStringLinkNode * next) {
    this->next = next;
}

CharString CharStringLinkNode::getCharString() const {
    return charString;
}

void CharStringLinkNode::setCharString(const CharString & cs) {
    this->charString = cs;
}
