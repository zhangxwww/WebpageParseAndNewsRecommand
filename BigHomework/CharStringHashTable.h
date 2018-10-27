#ifndef CHAR_STRING_HASH_TABLE_H
#define CHAR_STRING_HASH_TABLE_H

#include "CharString.h"
#include "CharStringLink.h"

class CharStringHashTable {
public:
    CharStringHashTable();
    CharStringHashTable(const CharStringHashTable & csht);
    ~CharStringHashTable();
    void add(const CharString & cs);
    bool find(const CharString & cs) const;

    const CharStringLink & at(const int index) const;

private:
    int hash(const CharString & cs) const;

    static const int HASH_SIZE = 1000003;
    CharStringLink * cslinks;
};

#endif // !CHAR_STRING_HASH_TABLE_H
