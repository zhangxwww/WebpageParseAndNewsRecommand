#include "CharStringHashTable.h"

CharStringHashTable::CharStringHashTable() {
    cslinks = new CharStringLink[HASH_SIZE];
}

CharStringHashTable::CharStringHashTable(const CharStringHashTable & csht) {
    cslinks = new CharStringLink[HASH_SIZE];
    for (int i = 0; i < HASH_SIZE; i++) {
        cslinks[i] = csht.at(i);
    }
}

CharStringHashTable::~CharStringHashTable() {
    delete[] cslinks;
}

void CharStringHashTable::add(const CharString & cs) {   
    if(!find(cs)) {
        int index = hash(cs);
        cslinks[index].add(cs);
    }
}

bool CharStringHashTable::find(const CharString & cs) {
    int index = hash(cs);
    CharStringLinkNode * p = cslinks[index].getHead();
    while (p->getNext() != nullptr) {
        p = p->getNext();
        if (cs == p->getCharString()) {
            return true;
        }
    }
    return false;
}

const CharStringLink CharStringHashTable::at(const int index) const {
    return cslinks[index];
}

int CharStringHashTable::hash(const CharString & cs) const {
    int len = cs.length();
    int hash = 0;
    for (int i = 0; i < len; i++) {
        hash = hash * 33 + (int)cs[i];
        hash %= HASH_SIZE;
    }
    return hash;
}
 