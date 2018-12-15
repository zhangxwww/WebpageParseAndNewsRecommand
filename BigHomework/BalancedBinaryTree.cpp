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

    // û�ж�Ӧ�Ľ�㣬�򴴽�
    if (root == nullptr) {
        root = new BalancedBinaryTreeNode(term);
        p = root;
        taller = true;
    }
    else {
        // �ҵ��˶�Ӧ��㣬����false
        if (term == root->getTerm()) {
            taller = false;
            return false;
        }
        if (term < root->getTerm()) {
            // ���������в���
            if (!insert(root->getLeft(), p, term, taller)) {
                return false;
            }
            // ƽ��
            if(taller){
                adjust(root, BalancedBinaryTree::LEFT,
                    BalancedBinaryTree::TALLER, taller);
            }
        }
        else {
            // ���������в���
            if (!insert(root->getRight(), p, term, taller)) {
                return false;
            }
            // ƽ��
            if (taller) {
                adjust(root, BalancedBinaryTree::RIGHT,
                    BalancedBinaryTree::TALLER, taller);
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
    const int changeType,
    bool & change) {

    if (changeType == BalancedBinaryTree::TALLER) {
        if (childType == BalancedBinaryTree::LEFT) {
            switch (root->getBalancedFactor()) {
            case LH:
                leftBalance(root);
                change = false;
                break;
            case EH:
                root->setBalancedFactor(LH);
                change = true;
                break;
            case RH:
                root->setBalancedFactor(EH);
                change = false;
                break;
            default:
                break;
            }
        }
        else {
            switch (root->getBalancedFactor()) {
            case LH:
                root->setBalancedFactor(EH);
                change = false;
                break;
            case EH:
                root->setBalancedFactor(RH);
                change = true;
                break;
            case RH:
                rightBalance(root);
                change = false;
                break;
            default:
                break;
            }
        }
    }
    else {
        if (childType == BalancedBinaryTree::LEFT) {
            switch (root->getBalancedFactor()) {
            case LH:
                root->setBalancedFactor(EH);
                change = true;
                break;
            case EH:
                root->setBalancedFactor(RH);
                change = false;
                break;
            case RH:
                if (root->getRight()->getBalancedFactor() == EH) {
                    change = false;
                }
                else {
                    change = true;
                }
                rightBalance(root);
                break;
            default:
                break;
            }
        }
        else {
            switch (root->getBalancedFactor()) {
            case LH:
                if (root->getLeft()->getBalancedFactor() == EH) {
                    change = false;
                }
                else {
                    change = true;
                }
                leftBalance(root);
                break;
            case EH:
                root->setBalancedFactor(LH);
                change = false;
                break;
            case RH:
                root->setBalancedFactor(EH);
                change = true;
                break;
            default:
                break;
            }
        }
    }
}

bool BalancedBinaryTree::remove(
    BalancedBinaryTreeNode *& root, 
    BalancedBinaryTreeNode * parent,
    const CharString & term, 
    bool & shorter) {

    // û���ҵ���Ӧ���
    if (root == nullptr) {
        return false;
    }
    if (term < root->getTerm()) {
        // ����������ɾ��
        if (!remove(root->getLeft(), root, term, shorter)) {
            return false;
        }
        // ƽ��
        if (shorter) {
            adjust(root, BalancedBinaryTree::LEFT, 
                BalancedBinaryTree::SHORTER, shorter);
        }
    }
    else if (root->getTerm() < term) {
        // ����������ɾ��
        if (!remove(root->getRight(), root, term, shorter)) {
            return false;
        }
        // ƽ��
        if (shorter) {
            adjust(root, BalancedBinaryTree::RIGHT,
                BalancedBinaryTree::SHORTER, shorter);
        }
    }
    // �ҵ���Ӧ�Ľ��root
    else {
        // ��������������
        if (root->getLeft() != nullptr
            && root->getRight() != nullptr) {
            BalancedBinaryTreeNode * p = root->getLeft();
            while (p->getRight() != nullptr) {
                p = p->getRight();
            }
            // ����ǰ���滻��ɾ��ǰ��
            root->setTerm(p->getTerm());
            remove(root->getLeft(), root, p->getTerm(), shorter);
        }
        // ��������
        else if (root->getLeft() == nullptr) {
            BalancedBinaryTreeNode * q = root;
            if (parent == nullptr) {
                getRoot() = root->getRight();
            }
            else {
                if (root == parent->getLeft()) {
                    parent->setLeft(root->getRight());
                }
                else {
                    parent->setRight(root->getRight());
                }
            }
            shorter = true;
            q->setLeft(nullptr);
            q->setRight(nullptr);
            delete q;
        }
        // ��������
        else if (root->getRight() == nullptr) {
            BalancedBinaryTreeNode * q = root;
            if (parent == nullptr) {
                getRoot() = root->getLeft();
            }
            else {
                if (root == parent->getLeft()) {
                    parent->setLeft(root->getLeft());
                }
                else {
                    parent->setRight(root->getLeft());
                }
            }
            shorter = true;
            q->setLeft(nullptr);
            q->setRight(nullptr);
            delete q;
        }       
    }
    return true;
}

bool BalancedBinaryTree::edit(
    BalancedBinaryTreeNode *& root, 
    BalancedBinaryTreeNode *& p, 
    const CharString & oldTerm, 
    const CharString & newTerm) {

    // ɾ���ɽ�㣬�����½��
    bool shorter = false;
    if (remove(root, nullptr, oldTerm, shorter)) {
        BalancedBinaryTreeNode * p = nullptr;
        bool taller = false;
        if (insert(root, p, newTerm, taller)) {
            return true;
        }
    }
    // ��� oldTerm �����ڻ��� newTerm �Ѵ��ھ���ʧ��
    return false;
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
    // rd ָ�� root �����ӵ���������
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
    case EH:
        leftChild->setBalancedFactor(RH);
        root->setBalancedFactor(LH);
        R_rotate(root);
        break;
    default:
        break;
    }
}

void BalancedBinaryTree::rightBalance(
    BalancedBinaryTreeNode *& root) {

    BalancedBinaryTreeNode * rightChild = root->getRight();
    // ld ָ�� root ���Һ��ӵ���������
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
    case EH:
        rightChild->setBalancedFactor(LH);
        root->setBalancedFactor(RH);
        L_rotate(root);
        break;
    default:
        break;
    }
}
