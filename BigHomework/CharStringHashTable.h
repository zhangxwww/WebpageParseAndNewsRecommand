#ifndef CHAR_STRING_HASH_TABLE_H
#define CHAR_STRING_HASH_TABLE_H

#include "CharString.h"
#include "CharStringLink.h"

class CharStringHashTable {
public:
    CharStringHashTable();
    ~CharStringHashTable();
    void add(const CharString & cs);
    bool find(const CharString & cs);

private:
    int hash(const CharString & cs);

    static const int HASH_SIZE = 1000003;
    CharStringLink cslink[HASH_SIZE];
};

#endif // !CHAR_STRING_HASH_TABLE_H
