#ifndef BALANCED_BINARY_TREE
#define BALANCED_BINARY_TREE

#include "BalancedBinaryTreeNode.h"

class BalancedBinaryTree {
private:
    BalancedBinaryTreeNode * root;
public:
    BalancedBinaryTree();
    ~BalancedBinaryTree();
    void insert(const CharString & term);
    BalancedBinaryTreeNode search(const CharString & term);
    void adjust();
};

#endif // !BALANCED_BINARY_TREE
