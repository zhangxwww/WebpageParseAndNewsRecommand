#ifndef CHAR_STRING_LINK_H
#define CHAR_STRING_LINK_H

#include "CharStringLinkNode.h"
#include <iostream>

class CharStringLink {
public:
    CharStringLink();
    CharStringLink(const CharStringLink & csl);
    ~CharStringLink();

    /********** ���¼�������Ϊ��ҵ��Ҫ��ʵ�ֵĻ������� **********/

    /**
     *  �ڵ�ǰ����ĩβ����µĽ�㣬����е��ַ���Ϊcs
     *  @param cs: ����ӵ�ĩβ���ַ���
     */
    void add(const CharString cs);


    /**
     *  �ڵ�ǰ����index������µĽ�㣬����е��ַ���Ϊcs
     *  @param cs   : ����ӵ��ַ���
     *  @param index: ��Ӻ��Ԫ������λ������
     */
    void add(const CharString cs, int index);


    /**
     *  ɾ����indexλ���ϵĽ��
     *  @param index: ��Ҫɾ���Ľ�������
     *  @return     : ɾ���ɹ��򷵻�true�����򷵻�false
     */
    bool remove(const int index);


    /**
     *  ɾ��������cs�Ľ��
     *  @param cs: Ҫɾ���Ľ����Ӧ�ñ����ŵ��ַ���
     *  @return  : ɾ���ɹ��򷵻�true�����򷵻�false
     */
    bool remove(const CharString & cs);


    /**
     *  ��������������Ӧ�ַ���Ϊcs�Ľ��
     *  @param cs: Ҫ�������ַ���
     *  @return  : ���ַ������ڽ���λ�ã��������򷵻�-1
     */
    int search(const CharString & cs);


    /********** ���¼�������ΪΪ�˷������ӵĺ��� **********/

    /**
     *  �������ĳ���
     *  @return: ����ĳ���
     */
    int length() const;


    /**
     *  ��������ͷ���
     *  @return: �����ͷ���
     */
    CharStringLinkNode * getHead() const;


    /**
     *  ���� = �ţ���csl��ֵ����ǰ����
     *  @param csl: ���ڸ�ֵ������
     */
    void operator= (const CharStringLink & csl);


    /**
     *  ��csl�����ڵ�ǰ����֮��
     *  @param csl: �������ӵ�����
     */
    void append(const CharStringLink & csl);


    /**
     *  ��������ĵ�һ�����
     *  @return: �����Ľ��
     */
    CharStringLinkNode * pop();

    /**
     *  ��ɾ�����ʳ���С��threshold�Ľ��
     *  @param threshold: ��ֵ
     */
    void clearShorterThan(const int threshold);


    /**
     *  ���� << ��
     *  @param out: �������������
     *  @param csl: �������������
     *  @return   : �������������
     */
    friend std::wostream & operator<< (std::wostream & out,
        const CharStringLink & csl);


    /**
     *  ���� >> ��
     *  @param in : ��������������
     *  @param csl: �������������
     *  @return   : ��������������
     */
    friend std::wistream & operator>> (std::wifstream & in,
        CharStringLink & csl);

private:
    /* ����ͷ��� */
    CharStringLinkNode * head;

    /* ����ǰ�����Ľ�� */
    CharStringLinkNode * curPos;

    /* ��ǰ����λ������ */
    int curIndex;

    /* ������ */
    int len;
};

#endif // !CHAR_STRING_LINK_H
