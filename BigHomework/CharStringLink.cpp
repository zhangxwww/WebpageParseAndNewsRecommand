#include "CharStringLink.h"

CharStringLink::CharStringLink() {
    head = new CharStringLinkNode;
    head->setNext(nullptr);
    curPos = head;
    len = 0;
    curIndex = -1;
}

CharStringLink::CharStringLink(const CharStringLink & csl) {

    head = new CharStringLinkNode;
    curPos = head;
    len = csl.length();
    curIndex = 0;

    CharStringLinkNode * cslPos = csl.getHead()->getNext();
    while (cslPos != nullptr) {
        CharString cs = cslPos->getCharString();      
        CharStringLinkNode * temp = new CharStringLinkNode(cs);
        temp->setNext(nullptr);
        curPos->setNext(temp);
        curPos = curPos->getNext();
        cslPos = cslPos->getNext();
        curIndex++;
    }
}

CharStringLink::~CharStringLink() {
    curPos = head->getNext();
    while (curPos!= nullptr) {
        delete head;       
        head = curPos;
        curPos = curPos->getNext();
    }
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

void CharStringLink::add(const CharString cs, int index) {
    if (index<0 || index>len) { // 非法参数
        throw ERROR;
    }
    CharStringLinkNode * csln = new CharStringLinkNode(cs);
    curPos = head;
    for (int i = 0; i < index; i++) {
        curPos = curPos->getNext();
    }
    csln->setNext(curPos->getNext());
    curPos->setNext(csln);
    len++;
}

bool CharStringLink::remove(const int index) {
    if (index >= len || index < 0) { // 非法参数
        return false;
    }
    curPos = head;
    curIndex = -1;
    for (; curIndex < index - 1; curIndex++) {
        curPos = curPos->getNext();
    }
    CharStringLinkNode * tmp = curPos->getNext();
    curPos->setNext(tmp->getNext());
    tmp->setNext(nullptr);
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

CharStringLinkNode * CharStringLink::getHead() const {
    return head;
}

void CharStringLink::operator=(const CharStringLink & csl) {
    // 首先清空当前链表  
    curPos = head->getNext();
    while (curPos != nullptr) {
        delete head;
        head = curPos;
        curPos = curPos->getNext();
    }
    delete head;

    head = new CharStringLinkNode;
    curPos = head;
    len = csl.length();
    curIndex = 0;

    // 然后利用csl中的每一个结点的信息构造新的结点，并添加在链表末尾
    CharStringLinkNode * cslPos = csl.getHead()->getNext();
    while (cslPos != nullptr) {
        CharString cs = cslPos->getCharString();
        CharStringLinkNode * temp = new CharStringLinkNode(cs);
        temp->setNext(nullptr);
        curPos->setNext(temp);
        curPos = curPos->getNext();
        cslPos = cslPos->getNext();
        curIndex++;
    }
}

void CharStringLink::append(const CharStringLink & csl) {
    CharStringLinkNode * cslPos = csl.getHead()->getNext();
    while (cslPos != nullptr) {
        add(cslPos->getCharString());
        cslPos = cslPos->getNext();
    }
}

std::wostream & operator<<(std::wostream & out, 
    const CharStringLink & csl) {

    CharStringLinkNode * pos = csl.getHead();
    while (pos->getNext() != nullptr) {
        pos = pos->getNext();
        out << pos->getCharString() << std::endl;
    }
    return out;
}
