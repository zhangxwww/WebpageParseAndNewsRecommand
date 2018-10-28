#ifndef CHAR_STRING_LINK_NODE_H
#define CHAR_STRING_LINK_NODE_H

#include "CharString.h"

/** 
 * ��������ַ�������Ľ�㣬
 * ���ַ�����ָ����һ������ָ���װ����һ��
 * ͬʱʵ����һЩ����
 */
class CharStringLinkNode {
public:
    CharStringLinkNode();
    CharStringLinkNode(const CharString & cs);
    ~CharStringLinkNode();

    /**
     *  ��ȡ��һ�����
     *  @return: ָ����һ������ָ��
     */
    CharStringLinkNode * getNext() const;


    /**
     *  ��nextָ��Ľ������Ϊ��һ�����
     *  @param next: ָ�����ָ��
     */
    void setNext(CharStringLinkNode * next);


    /**
     *  ��ȡ�ַ���
     *  @return: �ýڵ���ӵ�е��ַ���
     */
    CharString getCharString() const;


    /**
     *  ��cs����Ϊ�ýڵ���ַ���
     *  @param cs: ԭ�ַ���
     */
    void setCharString(const CharString & cs);

private:
    /* �ýڵ㱣����ַ��� */
    CharString charString;

    /* ָ����һ������ָ�� */
    CharStringLinkNode * next;
};

#endif // !CHAR_STRING_LINK_NODE_H
