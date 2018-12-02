#include "BalancedBinaryTreeNode.h"
#include "InvertedFileLinkList.h"

BalancedBinaryTreeNode::BalancedBinaryTreeNode(const CharString & term)
    : term(term), countOfRelatedDocs(0), totalOccur(0),
    left(nullptr), right(nullptr), list(nullptr), bf(EH) {

    list = new InvertedFileLinkList(this);
}

BalancedBinaryTreeNode::~BalancedBinaryTreeNode() {
    delete list;
    if (left != nullptr) {
        delete left;
    }
    if (right != nullptr) {
        delete right;
    }
}

BalancedBinaryTreeNode * & BalancedBinaryTreeNode::getLeft() {
    return left;
}

BalancedBinaryTreeNode * & BalancedBinaryTreeNode::getRight() {
    return right;
}

BalancedFactor BalancedBinaryTreeNode::getBalancedFactor() const {
    return bf;
}

void BalancedBinaryTreeNode::setLeft(BalancedBinaryTreeNode * p) {
    left = p;
}

void BalancedBinaryTreeNode::setRight(BalancedBinaryTreeNode * p) {
    right = p;
}

void BalancedBinaryTreeNode::setBalancedFactor(BalancedFactor bf) {
    this->bf = bf;
}

const CharString & BalancedBinaryTreeNode::getTerm() const {
    return term;
}

void BalancedBinaryTreeNode::docIncrease() {
    countOfRelatedDocs++;
}

void BalancedBinaryTreeNode::totalIncrease() {
    totalOccur++;
}
