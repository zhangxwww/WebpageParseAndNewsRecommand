#include "BalancedBinaryTreeNode.h"

BalancedBinaryTreeNode::BalancedBinaryTreeNode(const CharString & term)
    : term(term), countOfRelatedDocs(0), totalOccur(0), head(nullptr) {

}

BalancedBinaryTreeNode::~BalancedBinaryTreeNode() {
}
