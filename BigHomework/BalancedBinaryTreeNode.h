#ifndef BALANCED_BINARY_TREE_NODE
#define BALANCED_BINARY_TREE_NODE

#include "CharString.h"
#include "BalancedFactor.h"

class InvertedFileLinkList;

/* 平衡二叉树的结点 */
class BalancedBinaryTreeNode {
public:
    BalancedBinaryTreeNode(const CharString & term);
    ~BalancedBinaryTreeNode();


    /**
     *  获取左孩子
     *  @return: 当前结点的左孩子
     */
    BalancedBinaryTreeNode * & getLeft();


    /**
     *  获取右孩子
     *  @return: 当前结点的右孩子
     */
    BalancedBinaryTreeNode * & getRight();


    /**
     *  获取以当前结点的平衡因子
     *  @return: 平衡因子
     */
    BalancedFactor getBalancedFactor() const;


    /**
     *  设定当前结点的左孩子
     *  @param p: 左孩子
     */
    void setLeft(BalancedBinaryTreeNode * p);


    /**
     *  设定当前结点的右孩子
     *  @param p: 右孩子
     */
    void setRight(BalancedBinaryTreeNode * p);


    /**
     *  改变当前结点的平衡因子
     *  @param bf: 平衡因子
     */
    void setBalancedFactor(BalancedFactor bf);


    /**
     *  获取以当前结点的保存的字符串
     *  @return: 当前结点保存的字符串
     */
    const CharString & getTerm() const;


    /**
     *  获取以当前结点的保存的倒排文档链表
     *  @return: 当前结点保存的倒排文档链表
     */
    InvertedFileLinkList * getFileLinkList() const;


    /**
     *  相关文档总数增加
     */
    void docIncrease();


    /**
     *  总出现次数增加
     */
    void totalIncrease();


    /**
     *  获取以当前结点单词出现过的文章次数，也就是链表的长度
     *  @return: 当前文章数量
     */
    const int getDocs() const;


    /**
     *  获取以当前结点单词总出现次数
     *  @return: 当前结点单词总出现次数
     */
    const int getTotal() const;

private:
    /* 当前结点保存的字符串 */
    CharString term;

    /* 相关文档总数 */
    int countOfRelatedDocs;

    /* 词语出现的总次数 */
    int totalOccur;

    /* 词语对应的倒排文档 */
    InvertedFileLinkList * list;

    /* 左孩子 */
    BalancedBinaryTreeNode * left;

    /* 右孩子 */
    BalancedBinaryTreeNode * right;

    /* 平衡因子 */
    BalancedFactor bf;
};

#endif // !BALANCED_BINARY_TREE_NODE
