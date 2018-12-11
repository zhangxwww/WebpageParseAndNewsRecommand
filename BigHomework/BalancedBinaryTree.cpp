#include "BalancedBinaryTree.h"
#include <iostream>

BalancedBinaryTree::BalancedBinaryTree()
    : root(nullptr) {
}

BalancedBinaryTree::~BalancedBinaryTree() {
    if (root != nullptr) {
        delete root;
    }
}

bool BalancedBinaryTree::insert(
    BalancedBinaryTreeNode *& root, 
    BalancedBinaryTreeNode * & p,
    const CharString & term, 
    bool & taller) {

    if (root == nullptr) {
        root = new BalancedBinaryTreeNode(term);
        p = root;
        taller = true;
    }
    else {
        if (term == root->getTerm()) {
            taller = false;
            return false;
        }
        if (term < root->getTerm()) {
            if (!insert(root->getLeft(), p, term, taller)) {
                return false;
            }
            if(taller){
                adjust(root, BalancedBinaryTree::LEFT, taller);
            }
        }
        else {
            if (!insert(root->getRight(), p, term, taller)) {
                return false;
            }
            if (taller) {
                adjust(root, BalancedBinaryTree::RIGHT, taller);
            }
        }
    }
    return true;
}

bool BalancedBinaryTree::search(
    BalancedBinaryTreeNode * root, 
    const CharString & key, 
    BalancedBinaryTreeNode * parent, 
    BalancedBinaryTreeNode * & p) {

    if (root == nullptr) {
        p = parent;
        return false;
    }
    else if (key == root->getTerm()) {
        p = root;
        return true;
    }
    else if (key < root->getTerm()) {
        return search(root->getLeft(), key, root, p);
    }
    else return search(root->getRight(), key, root, p);
}

void BalancedBinaryTree::adjust(
    BalancedBinaryTreeNode *& root, 
    const int childType, 
    bool & taller) {

    if (childType == BalancedBinaryTree::LEFT) {
        switch (root->getBalancedFactor()) {
        case LH:
            leftBalance(root);
            taller = false;
            break;
        case EH:
            root->setBalancedFactor(LH);
            taller = true;
            break;
        case RH:
            root->setBalancedFactor(EH);
            taller = false;
            break;
        default:
            break;
        }
    }
    else {
        switch (root->getBalancedFactor()) {
        case LH:
            root->setBalancedFactor(EH);
            taller = false;
            break;
        case EH:
            root->setBalancedFactor(RH);
            taller = true;
            break;
        case RH:
            rightBalance(root);
            taller = false;
            break;
        default:
            break;
        }
    }
}

BalancedBinaryTreeNode *& BalancedBinaryTree::getRoot() {
    return root;
}

void BalancedBinaryTree::L_rotate(
    BalancedBinaryTreeNode * & root) {

    BalancedBinaryTreeNode * rightChild = root->getRight();
    root->setRight(rightChild->getLeft());
    rightChild->setLeft(root);
    root = rightChild;
}

void BalancedBinaryTree::R_rotate(
    BalancedBinaryTreeNode * & root) {

    BalancedBinaryTreeNode * leftChild = root->getLeft();
    root->setLeft(leftChild->getRight());
    leftChild->setRight(root);
    root = leftChild;
}

void BalancedBinaryTree::leftBalance(
    BalancedBinaryTreeNode * & root) {

    BalancedBinaryTreeNode * leftChild = root->getLeft();
    // rd 指向 root 的左孩子的右子树根
    BalancedBinaryTreeNode * rd = nullptr;
    if (leftChild != nullptr) {
        rd = leftChild->getRight();
    }
    switch (leftChild->getBalancedFactor()) {
    case LH:
        root->setBalancedFactor(EH);
        leftChild->setBalancedFactor(EH);
        R_rotate(root);
        break;
    case RH:
        switch (rd->getBalancedFactor()) {
        case LH:
            root->setBalancedFactor(RH);
            leftChild->setBalancedFactor(EH);
            break;
        case EH:
            root->setBalancedFactor(EH);
            leftChild->setBalancedFactor(EH);
            break;
        case RH:
            root->setBalancedFactor(EH);
            leftChild->setBalancedFactor(LH);
            break;
        default:
            break;
        }
        rd->setBalancedFactor(EH);
        L_rotate(root->getLeft());
        R_rotate(root);
        break;
    default:
        break;
    }
}

void BalancedBinaryTree::rightBalance(
    BalancedBinaryTreeNode *& root) {

    BalancedBinaryTreeNode * rightChild = root->getRight();
    // ld 指向 root 的右孩子的左子树根
    BalancedBinaryTreeNode * ld = nullptr;
    if (rightChild != nullptr) {
        ld = rightChild->getLeft();
    }
    switch (rightChild->getBalancedFactor()) {
    case RH:
        root->setBalancedFactor(EH);
        rightChild->setBalancedFactor(EH);
        L_rotate(root);
        break;
    case LH:
        switch (ld->getBalancedFactor()) {
        case RH:
            root->setBalancedFactor(LH);
            rightChild->setBalancedFactor(EH);
            break;
        case EH:
            root->setBalancedFactor(EH);
            rightChild->setBalancedFactor(EH);
            break;
        case LH:
            root->setBalancedFactor(EH);
            rightChild->setBalancedFactor(RH);
            break;
        default:
            break;
        }
        ld->setBalancedFactor(EH);
        R_rotate(root->getRight());
        L_rotate(root);
        break;
    default:
        break;
    }
}

