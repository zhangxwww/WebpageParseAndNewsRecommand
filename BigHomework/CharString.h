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

    /********** 以下几个函数为作业中要求实现的基本操作 **********/

    /**
     *  获取某个字符在字符串中第一次出现的位置索引
     *  @param w: 所要查询的字符
     *  @return : 该字符在字符串中第一次出现的位置索引，不存在则返回-1
     */
    int indexOf(const wchar_t w) const;


    /**
     *  获取某个字符串在字符串中第一次出现的位置索引
     *  @param w: 所要查询的字符串
     *  @return : 该字符串在字符串中第一次出现的位置索引，不存在则返回-1
     */
    int indexOf(const CharString & cstr) const;


    /**
     *  获取字符串的子串
     *  @param startPos: 子串的起点在原字符串的位置索引
     *  @param endPos  : 子串的终点在原字符串的位置索引
     *  @return        : 子串，包含原字符串[startPos, endPos)位置的所有字符
     */
    CharString subString(const int startPos, 
        const int endPos) const;


    /**
     *  获取字符串的子串
     *  @param startPos: 子串的起点在原字符串的位置索引
     *  @return        : 子串，包含原字符串从startPos开始到结束的所有字符
     */
    CharString subString(const int startPos) const;


    /**
     *  拼接字符串，将字符串cstr拼接到原字符串的末尾
     *  @param cstr: 用于拼接的字符串
     */
    void concat(const CharString & cstr);


    /**
     *  拼接字符串，将字符w拼接到原字符串的末尾
     *  @param w: 用于拼接的字符
     */
    void concat(const wchar_t w);


    /**
     *  重载 = 号，用CharString类型的字符串来进行赋值操作
     *  @param cstr: 用于赋值的字符串
     */
    void operator= (const CharString & cstr);


    /**
     *  重载 = 号，用std::wstring类型的字符串来进行赋值操作
     *  @param wstr: 用于赋值的字符串
     */
    void operator= (const std::wstring & wstr);


    /********** 以下几个函数为为了方便而添加的函数 **********/

    /**
     *  获得KMP算法中的next数组
     *  @return: 计算得到的next数组
     */
    int * getNext() const;


    /**
     *  重载 [] 号，返回字符串index位置的字符
     *  @param index: 所查找的位置索引
     *  @return     : 该位置所对应的字符
     */
    wchar_t & operator[] (const int index);


    /**
     *  重载 [] 号，返回字符串index位置的字符
     *  @param index: 所查找的位置索引
     *  @return     : 该位置所对应的字符
     */
    wchar_t & operator[] (const int index) const;


    /**
     *  返回字符串的长度
     *  @return: 字符串的长度
     */
    const int length() const;


    /**
     *  将CharString类型的字符串转化为std::wstring类型的字符串
     *  主要用于某些库函数的调用
     *  @return: std::wstring类型的字符串
     */
    const std::wstring wstring() const;


    /**
     *  将CharString类型的字符串转化为wchar_t类型的字符数组
     *  主要用于某些库函数的调用
     *  @return: wchar_t类型的字符数组
     */
    const wchar_t * wchar() const;


    /**
     *  去除字符串首尾两端的空白字符
     */
    CharString trim();


    /**
     *  判断字符串是否为空白
     *  @return: 如果字符串为空白，则返回true，否则false
     */
    bool blank() const;


    /**
     *  重载 << 号
     *  @param out: 宽输出流的引用
     *  @param cs : 用于输出的字符串
     *  @return   : 宽输出流的引用
     */
    friend std::wostream & operator<< (std::wostream & out,
        const CharString & cs);


    /**
     *  重载 >> 号
     *  @param in: 宽输入流的引用
     *  @param cs: 用于接收输入的字符串
     *  @return  : 宽输入流的引用
     */
    friend std::wifstream & operator>> (std::wifstream & in,
        CharString & cs);


    /**
     *  重载 == 号
     *  @param cs1: 用于比较的CharString
     *  @param cs2: 用于比较的CharString
     *  @return   : 二者内容完全相同则返回true，否则返回false
     */
    friend bool operator== (const CharString & cs1,
        const CharString & cs2);

    /**
     *  重载 < 号
     *  @param cs1: 用于比较的CharString
     *  @param cs2: 用于比较的CharString
     *  @return   : cs1 < cs2则返回true，否则返回false
     */
    friend bool operator< (const CharString & cs1,
        const CharString & cs2);

    /**
     *  重载 <= 号
     *  @param cs1: 用于比较的CharString
     *  @param cs2: 用于比较的CharString
     *  @return   : cs1 <= cs2则返回true，否则返回false
     */
    friend bool operator<= (const CharString & cs1,
        const CharString & cs2);

private:
    /* 字符串初始分配的空间 */
    static const int INIT_SIZE = 50;

     /* 每次扩充容量时的增量 */
    static const int INCREMENT = 20;

    /* 用于保存字符串中的每一个字符 */
    wchar_t * items;

    /* 字符串长度 */
    int len;

    /* 当前字符串已分配的长度 */
    int maxSize;
};

#endif // !CHAR_STRING_H
