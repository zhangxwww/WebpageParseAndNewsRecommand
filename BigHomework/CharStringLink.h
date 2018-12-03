#ifndef CHAR_STRING_LINK_H
#define CHAR_STRING_LINK_H

#include "CharStringLinkNode.h"
#include <iostream>

class CharStringLink {
public:
    CharStringLink();
    CharStringLink(const CharStringLink & csl);
    ~CharStringLink();

    /********** 以下几个函数为作业中要求实现的基本操作 **********/

    /**
     *  在当前链表末尾添加新的结点，结点中的字符串为cs
     *  @param cs: 被添加到末尾的字符串
     */
    void add(const CharString cs);


    /**
     *  在当前链表index处添加新的结点，结点中的字符串为cs
     *  @param cs   : 被添加的字符串
     *  @param index: 添加后该元素所在位置索引
     */
    void add(const CharString cs, int index);


    /**
     *  删除第index位置上的结点
     *  @param index: 所要删除的结点的索引
     *  @return     : 删除成功则返回true，否则返回false
     */
    bool remove(const int index);


    /**
     *  删除保存着cs的结点
     *  @param cs: 要删除的结点中应该保存着的字符串
     *  @return  : 删除成功则返回true，否则返回false
     */
    bool remove(const CharString & cs);


    /**
     *  在链表中搜索对应字符串为cs的结点
     *  @param cs: 要搜索的字符串
     *  @return  : 该字符串所在结点的位置，不存在则返回-1
     */
    int search(const CharString & cs);


    /********** 以下几个函数为为了方便而添加的函数 **********/

    /**
     *  获得链表的长度
     *  @return: 链表的长度
     */
    int length() const;


    /**
     *  获得链表的头结点
     *  @return: 链表的头结点
     */
    CharStringLinkNode * getHead() const;


    /**
     *  重载 = 号，将csl赋值给当前链表
     *  @param csl: 用于赋值的链表
     */
    void operator= (const CharStringLink & csl);


    /**
     *  将csl连接在当前链表之后
     *  @param csl: 用于连接的链表
     */
    void append(const CharStringLink & csl);


    /**
     *  弹出链表的第一个结点
     *  @return: 弹出的结点
     */
    CharStringLinkNode * pop();

    /**
     *  将删掉单词长度小于threshold的结点
     *  @param threshold: 阈值
     */
    void clearShorterThan(const int threshold);


    /**
     *  重载 << 号
     *  @param out: 宽输出流的引用
     *  @param csl: 用于输出的链表
     *  @return   : 宽输出流的引用
     */
    friend std::wostream & operator<< (std::wostream & out,
        const CharStringLink & csl);


    /**
     *  重载 >> 号
     *  @param in : 宽输入流的引用
     *  @param csl: 用于输入的链表
     *  @return   : 宽输入流的引用
     */
    friend std::wistream & operator>> (std::wifstream & in,
        CharStringLink & csl);

private:
    /* 链表头结点 */
    CharStringLinkNode * head;

    /* 链表当前遍历的结点 */
    CharStringLinkNode * curPos;

    /* 当前所在位置索引 */
    int curIndex;

    /* 链表长度 */
    int len;
};

#endif // !CHAR_STRING_LINK_H
