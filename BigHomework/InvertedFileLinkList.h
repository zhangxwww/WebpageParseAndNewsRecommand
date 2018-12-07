#ifndef INVERTED_FILE_LINK_LIST
#define INVERTED_FILE_LINK_LIST

#include "InvertedFileLinkNode.h"

class BalancedBinaryTreeNode;

/* 倒排文档链表 */
class InvertedFileLinkList {
public:
    InvertedFileLinkList(
        BalancedBinaryTreeNode * node);
    ~InvertedFileLinkList();


    /********** 以下几个函数为作业中要求实现的基本操作 **********/

    /**
     *  在文档链表中插入对应id的结点
     *  @param docID: 待插入的文档id
     *  @param times: 文档中单词出现的次数
     */
    void add(const int docID, const int times=1);


    /**
     *  在文档链表中搜索对应id的结点
     *  @param docID: 待搜索的文档id
     *  @return     : 搜索成功返回指向对应结点的指针，否则返回尾结点
     */
    InvertedFileLinkNode * search(
        const int docID) const;


    /**
     *  将链表中preID对应的文档的id改为newID
     *  @param preID: 修改之前的id
     *  @param newID: 修改之后的id
     *  @return     : 修改成功返回true, 否则false
     */
    bool edit(const int preID, const int newID);


    /**
     *  在文档链表中删除对应id的结点
     *  @param docID: 待删除的文档id
     *  @return     : 删除成功返回true, 否则false
     */
    bool remove(const int docID);


    /**
     *  返回链表头结点
     *  @return: 链表头结点
     */
    InvertedFileLinkNode * getHead() const;

private:
    /* 链表的头尾结点 */
    InvertedFileLinkNode * head;
    InvertedFileLinkNode * tail;

    /* 指向二叉树上对应的结点 */
    BalancedBinaryTreeNode * bbtNode;
};

#endif // !INVERTED_FILE_LINK_LIST
