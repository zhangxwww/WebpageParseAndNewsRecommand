#include "InvertedFileLinkNode.h"

InvertedFileLinkNode::InvertedFileLinkNode(
    const int id)
    : docID(id), times(0), 
    next(nullptr), prev(nullptr) {

}

InvertedFileLinkNode::~InvertedFileLinkNode() {
    if (next != nullptr) {
        delete next;
    }
}

const int InvertedFileLinkNode::getID() const {
    return docID;
}

const int InvertedFileLinkNode::getTimes() const {
    return times;
}

InvertedFileLinkNode * InvertedFileLinkNode::getNext() const {
    return next;
}

InvertedFileLinkNode * InvertedFileLinkNode::getPrev() const {
    return prev;
}

void InvertedFileLinkNode::setID(const int id) {
    this->docID = id;
}

void InvertedFileLinkNode::timeIncrease(const int times) {
    this->times += times;
}

void InvertedFileLinkNode::timeDecrease() {
    times--;
}

void InvertedFileLinkNode::setNext(
    InvertedFileLinkNode * next) {

    this->next = next;
}

void InvertedFileLinkNode::setPrev(
    InvertedFileLinkNode * prev) {

    this->prev = prev;
}
