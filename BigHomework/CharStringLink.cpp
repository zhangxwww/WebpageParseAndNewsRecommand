#include "CharStringLink.h"

CharStringLink::CharStringLink() {
    head = new CharStringLinkNode;
    head->setNext(nullptr);
    curPos = head;
    len = 0;
    curIndex = -1;
}

CharStringLink::CharStringLink(CharStringLink & csl) {

    head = new CharStringLinkNode;
    curPos = head->getNext();
    len = csl.length();
    curIndex = 0;

    CharStringLinkNode * cslPos = csl.getHead()->getNext();
    while (cslPos != nullptr) {
        CharString cs = cslPos->getCharString();
        curPos = new CharStringLinkNode(cs);
        curPos->setNext(nullptr);
        curPos = curPos->getNext();
        curIndex++;
    }
}

CharStringLink::~CharStringLink() {
    delete head;
}

void CharStringLink::add(const CharString cs) {
    CharStringLinkNode * csln = new CharStringLinkNode(cs);
    while (curPos->getNext() != nullptr) {
        curPos = curPos->getNext();
    }
    csln->setNext(nullptr);
    curPos->setNext(csln);
    curPos = curPos->getNext();
    curIndex = len;
    len++;
}

bool CharStringLink::remove(const int index) {
    if (index >= len || index < 0) {
        return false;
    }
    curPos = head;
    curIndex = -1;
    for (; curIndex < index - 1; curIndex++) {
        curPos = curPos->getNext();
    }
    CharStringLinkNode * tmp = curPos->getNext();
    curPos->setNext(tmp->getNext());
    delete tmp;
    len--;
    return true;
}

bool CharStringLink::remove(const CharString & cs) {
    curPos = head;
    curIndex = -1;
    while (curPos->getNext() != nullptr) {
        if (curPos->getNext()->getCharString() == cs) {
            CharStringLinkNode * tmp = curPos->getNext();
            curPos->setNext(tmp->getNext());
            delete tmp;
            len--;
            return true;
        }
        curPos = curPos->getNext();
        curIndex++;
    }
    return false;
}

int CharStringLink::search(const CharString & cs) {
    curPos = head;
    curIndex = -1;
    while (curPos->getNext() != nullptr) {
        if (curPos->getNext()->getCharString() == cs) {
            return curIndex + 1;
        }
        curPos = curPos->getNext();
        curIndex++;
    }
    return -1;
}

int CharStringLink::length() const {
    return len;
}

CharString CharStringLink::getItem(int index) {
    if (index >= len) {
        throw ERROR;
    }
    if (index < curIndex) {
        curIndex = 0;
        curPos = head->getNext();
    }
    for (; curIndex < index; curIndex++) {
        curPos = curPos->getNext();
    }
    return curPos->getCharString();
}

CharStringLinkNode * CharStringLink::getHead() const {
    return head;
}

std::wostream & operator<<(std::wostream & out, CharStringLink & csl) {
    CharStringLinkNode * pos = csl.getHead();
    while (pos->getNext() != nullptr) {
        pos = pos->getNext();
        out << pos->getCharString() << std::endl;
    }
    return out;
}
