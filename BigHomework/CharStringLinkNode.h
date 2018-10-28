#ifndef CHAR_STRING_LINK_NODE_H
#define CHAR_STRING_LINK_NODE_H

#include "CharString.h"

/** 
 * 这个类是字符串链表的结点，
 * 将字符串与指向下一个结点的指针封装到了一起，
 * 同时实现了一些操作
 */
class CharStringLinkNode {
public:
    CharStringLinkNode();
    CharStringLinkNode(const CharString & cs);
    ~CharStringLinkNode();

    /**
     *  获取下一个结点
     *  @return: 指向下一个结点的指针
     */
    CharStringLinkNode * getNext() const;


    /**
     *  将next指向的结点设置为下一个结点
     *  @param next: 指向结点的指针
     */
    void setNext(CharStringLinkNode * next);


    /**
     *  获取字符串
     *  @return: 该节点所拥有的字符串
     */
    CharString getCharString() const;


    /**
     *  将cs设置为该节点的字符串
     *  @param cs: 原字符串
     */
    void setCharString(const CharString & cs);

private:
    /* 该节点保存的字符串 */
    CharString charString;

    /* 指向下一个结点的指针 */
    CharStringLinkNode * next;
};

#endif // !CHAR_STRING_LINK_NODE_H
