#ifndef CHAR_STRING_HASH_TABLE_H
#define CHAR_STRING_HASH_TABLE_H

#include "CharString.h"
#include "CharStringLink.h"

/**
 *  这是我自己实现的哈希表，hash算法采用的是time33算法
 *  哈希冲突用链地址法解决
 */
class CharStringHashTable {
public:
    CharStringHashTable();
    CharStringHashTable(const CharStringHashTable & csht);
    ~CharStringHashTable();

    /**
     *  在哈希表中添加新的key
     *  @param cs: 要添加的key
     */
    void add(const CharString & cs);


    /**
     *  在哈希表中搜索key
     *  @param cs: 要搜索的字符串
     *  @return  : 如果存在这个key，则返回true，否则返回false
     */
    bool find(const CharString & cs) const;


    /**
     *  返回哈希表中index位置的链表，只在构造函数中被调用
     *  @param index: 需要查找的链表的索引
     *  @return     : 对应位置的链表
     */
    const CharStringLink & at(const int index) const;

private:
    /**
     *  哈希算法，采用time33
     *  @param cs: key
     *  @return  : key对应的哈希值
     */
    int hash(const CharString & cs) const;

    /* 哈希表大小，根据词库大小所选择的1E6附近的质数 */
    static const int HASH_SIZE = 1000003;

    /* 所有的链表 */
    CharStringLink * cslinks;
};

#endif // !CHAR_STRING_HASH_TABLE_H
