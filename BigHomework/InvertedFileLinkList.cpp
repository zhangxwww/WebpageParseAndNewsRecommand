#include "InvertedFileLinkList.h"
#include "BalancedBinaryTreeNode.h"

InvertedFileLinkList::InvertedFileLinkList(
    BalancedBinaryTreeNode * node)
    : head(nullptr), bbtNode(node) {

    head = new InvertedFileLinkNode(-1);
    tail = new InvertedFileLinkNode(-1);

    head->setNext(tail);
    tail->setPrev(head);
}

InvertedFileLinkList::~InvertedFileLinkList() {
    if (head != nullptr) {
        delete head;
    }
}

void InvertedFileLinkList::add(const int docID) {
    bbtNode->totalIncrease();
    InvertedFileLinkNode * p = search(docID);
    // 当前链表中没有对应文档
    if (p->getID == -1) {  
        InvertedFileLinkNode * doc = new InvertedFileLinkNode(docID);
        doc->setNext(p);
        doc->setPrev(p->getPrev());
        p->getPrev()->setNext(doc);
        p->setPrev(doc);

        bbtNode->docIncrease();
    }
    // 找到了对应文档
    else {  
        p->timeIncrease();
        InvertedFileLinkNode * pre = p->getPrev();
        // 将出现次数更多的文档前提
        while (pre->getID() != -1
            && pre->getTimes() < p->getTimes()) {  

            p->setPrev(pre->getPrev());
            p->getPrev()->setNext(p);
            pre->setNext(p->getNext());
            pre->getNext()->setPrev(pre);
            p->setNext(pre);
            pre->setPrev(p);

            pre = p->getPrev();
        }
    }
}

InvertedFileLinkNode * InvertedFileLinkList::search(
    const int docID) const {

    InvertedFileLinkNode * p = head->getNext();
    while (p->getID != -1) {
        if (p->getID == docID) {
            break;
        }
        p = p->getNext();
    }
    return p;
}

bool InvertedFileLinkList::edit(
    const int preID, const int newID) {

    InvertedFileLinkNode * p = search(preID);
    // 没有找到
    if (p->getID == -1) {
        return false;
    }
    else {
        p->setID(newID);
        return true;
    }
}

bool InvertedFileLinkList::remove(const int docID) {
    InvertedFileLinkNode * p = search(docID);
    // 没有找到
    if (p->getID == -1) {
        return false;
    }
    else {
        InvertedFileLinkNode * pre = p->getPrev();
        InvertedFileLinkNode * nxt = p->getNext();
        pre->setNext(nxt);
        nxt->setPrev(pre);
        p->setNext(nullptr);
        p->setPrev(nullptr);

        delete p;
        return true;
    }
}
