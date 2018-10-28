#ifndef INIT_DICTIONARY_H
#define INIT_DICTIONARY_H

#include "CharStringHashTable.h"

#include <fstream>

/**
 *  初始化词库，生成哈希表
 *  @return: 由词库生成的哈希表
 */
CharStringHashTable initDictionary();

#endif // !INIT_DICTIONARY_H
