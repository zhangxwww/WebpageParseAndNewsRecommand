#ifndef BALANCED_BINARY_TREE_NODE
#define BALANCED_BINARY_TREE_NODE

#include "CharString.h"
#include "InvertedFileLinkNode.h"

class BalancedBinaryTreeNode {

private:
    CharString term;
    int countOfRelatedDocs;
    int totalOccur;
    InvertedFileLinkNode * head;

public:
    BalancedBinaryTreeNode(const CharString & term);
    ~BalancedBinaryTreeNode();
};

#endif // !BALANCED_BINARY_TREE_NODE
