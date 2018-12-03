#ifndef BUILD_INVERTED_FILES
#define BUILD_INVERTED_FILES

#include <fstream>
#include <iostream>

class BalancedBinaryTree;
class CharStringLink;
class CharStringHashTable;

namespace BIF {
    /* ��ҳ���� */
    static const int COUNT_FILES = 781;
}

BalancedBinaryTree * buildInvertedFiles();


// TODO frominvertedfiles

bool fromTxtFile(const int order,
    CharStringLink * words);

bool fromInfoFile(const int order,
    CharStringLink * words,
    CharStringHashTable * hashTable);

bool fromHtmlFile(const int order,
    CharStringLink * words,
    CharStringHashTable * hashTable);

#endif // !BUILD_INVERTED_FILES
