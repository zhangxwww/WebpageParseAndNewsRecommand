#ifndef BALANCED_BINARY_TREE_NODE
#define BALANCED_BINARY_TREE_NODE

#include "CharString.h"
#include "InvertedFileLinkNode.h"
#include "BalancedFactor.h"

class BalancedBinaryTreeNode {

public:
    BalancedBinaryTreeNode(const CharString & term);
    ~BalancedBinaryTreeNode();
    BalancedBinaryTreeNode * & getLeft();
    BalancedBinaryTreeNode * & getRight();
    BalancedFactor getBalancedFactor() const;
    void setLeft(BalancedBinaryTreeNode * p);
    void setRight(BalancedBinaryTreeNode * p);
    void setBalancedFactor(BalancedFactor bf);
    const CharString & getTerm() const;

private:
    CharString term;
    int countOfRelatedDocs;
    int totalOccur;
    BalancedBinaryTreeNode * left;
    BalancedBinaryTreeNode * right;
    InvertedFileLinkNode * head;
    BalancedFactor bf;
};

#endif // !BALANCED_BINARY_TREE_NODE
