#ifndef CHAR_STRING_H
#define CHAR_STRING_H

#include "Status.h"
#include <string>
#include <iostream>
#include <fstream>

class CharString {
public:
    CharString();
    CharString(const CharString & cs);
    ~CharString();

    /********** ���¼�������Ϊ��ҵ��Ҫ��ʵ�ֵĻ������� **********/

    /**
     *  ��ȡĳ���ַ����ַ����е�һ�γ��ֵ�λ������
     *  @param w: ��Ҫ��ѯ���ַ�
     *  @return : ���ַ����ַ����е�һ�γ��ֵ�λ���������������򷵻�-1
     */
    int indexOf(const wchar_t w) const;


    /**
     *  ��ȡĳ���ַ������ַ����е�һ�γ��ֵ�λ������
     *  @param w: ��Ҫ��ѯ���ַ���
     *  @return : ���ַ������ַ����е�һ�γ��ֵ�λ���������������򷵻�-1
     */
    int indexOf(const CharString & cstr) const;


    /**
     *  ��ȡ�ַ������Ӵ�
     *  @param startPos: �Ӵ��������ԭ�ַ�����λ������
     *  @param endPos  : �Ӵ����յ���ԭ�ַ�����λ������
     *  @return        : �Ӵ�������ԭ�ַ���[startPos, endPos)λ�õ������ַ�
     */
    CharString subString(const int startPos, 
        const int endPos) const;


    /**
     *  ��ȡ�ַ������Ӵ�
     *  @param startPos: �Ӵ��������ԭ�ַ�����λ������
     *  @return        : �Ӵ�������ԭ�ַ�����startPos��ʼ�������������ַ�
     */
    CharString subString(const int startPos) const;


    /**
     *  ƴ���ַ��������ַ���cstrƴ�ӵ�ԭ�ַ�����ĩβ
     *  @param cstr: ����ƴ�ӵ��ַ���
     */
    void concat(const CharString & cstr);


    /**
     *  ƴ���ַ��������ַ�wƴ�ӵ�ԭ�ַ�����ĩβ
     *  @param w: ����ƴ�ӵ��ַ�
     */
    void concat(const wchar_t w);


    /**
     *  ���� = �ţ���CharString���͵��ַ��������и�ֵ����
     *  @param cstr: ���ڸ�ֵ���ַ���
     */
    void operator= (const CharString & cstr);


    /**
     *  ���� = �ţ���std::wstring���͵��ַ��������и�ֵ����
     *  @param wstr: ���ڸ�ֵ���ַ���
     */
    void operator= (const std::wstring & wstr);


    /********** ���¼�������ΪΪ�˷������ӵĺ��� **********/

    /**
     *  ���KMP�㷨�е�next����
     *  @return: ����õ���next����
     */
    int * getNext() const;


    /**
     *  ���� [] �ţ������ַ���indexλ�õ��ַ�
     *  @param index: �����ҵ�λ������
     *  @return     : ��λ������Ӧ���ַ�
     */
    wchar_t & operator[] (const int index);


    /**
     *  ���� [] �ţ������ַ���indexλ�õ��ַ�
     *  @param index: �����ҵ�λ������
     *  @return     : ��λ������Ӧ���ַ�
     */
    wchar_t & operator[] (const int index) const;


    /**
     *  �����ַ����ĳ���
     *  @return: �ַ����ĳ���
     */
    const int length() const;


    /**
     *  ��CharString���͵��ַ���ת��Ϊstd::wstring���͵��ַ���
     *  ��Ҫ����ĳЩ�⺯���ĵ���
     *  @return: std::wstring���͵��ַ���
     */
    const std::wstring wstring() const;


    /**
     *  ��CharString���͵��ַ���ת��Ϊwchar_t���͵��ַ�����
     *  ��Ҫ����ĳЩ�⺯���ĵ���
     *  @return: wchar_t���͵��ַ�����
     */
    const wchar_t * wchar() const;


    /**
     *  ȥ���ַ�����β���˵Ŀհ��ַ�
     */
    CharString trim();


    /**
     *  �ж��ַ����Ƿ�Ϊ�հ�
     *  @return: ����ַ���Ϊ�հף��򷵻�true������false
     */
    bool blank() const;


    /**
     *  ���� << ��
     *  @param out: �������������
     *  @param cs : ����������ַ���
     *  @return   : �������������
     */
    friend std::wostream & operator<< (std::wostream & out,
        const CharString & cs);


    /**
     *  ���� >> ��
     *  @param in: ��������������
     *  @param cs: ���ڽ���������ַ���
     *  @return  : ��������������
     */
    friend std::wifstream & operator>> (std::wifstream & in,
        CharString & cs);


    /**
     *  ���� == ��
     *  @param cs1: ���ڱȽϵ�CharString
     *  @param cs2: ���ڱȽϵ�CharString
     *  @return   : ����������ȫ��ͬ�򷵻�true�����򷵻�false
     */
    friend bool operator== (const CharString & cs1,
        const CharString & cs2);

    /**
     *  ���� < ��
     *  @param cs1: ���ڱȽϵ�CharString
     *  @param cs2: ���ڱȽϵ�CharString
     *  @return   : cs1 < cs2�򷵻�true�����򷵻�false
     */
    friend bool operator< (const CharString & cs1,
        const CharString & cs2);

    /**
     *  ���� <= ��
     *  @param cs1: ���ڱȽϵ�CharString
     *  @param cs2: ���ڱȽϵ�CharString
     *  @return   : cs1 <= cs2�򷵻�true�����򷵻�false
     */
    friend bool operator<= (const CharString & cs1,
        const CharString & cs2);

private:
    /* �ַ�����ʼ����Ŀռ� */
    static const int INIT_SIZE = 50;

     /* ÿ����������ʱ������ */
    static const int INCREMENT = 20;

    /* ���ڱ����ַ����е�ÿһ���ַ� */
    wchar_t * items;

    /* �ַ������� */
    int len;

    /* ��ǰ�ַ����ѷ���ĳ��� */
    int maxSize;
};

#endif // !CHAR_STRING_H
