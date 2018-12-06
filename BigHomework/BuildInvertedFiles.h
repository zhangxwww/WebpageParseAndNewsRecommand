#ifndef BUILD_INVERTED_FILES
#define BUILD_INVERTED_FILES

#include <fstream>
#include <iostream>

class BalancedBinaryTree;
class CharStringLink;
class CharStringHashTable;

namespace BIF {
    /* ÍøÒ³×ÜÊý */
    static const int COUNT_FILES = 781;
}

BalancedBinaryTree * buildInvertedFiles();

void save(BalancedBinaryTree * tree);

BalancedBinaryTree * fromExistedInvertedfiles(bool & ok);

BalancedBinaryTree * fromDataBase();

bool fromTxtFile(const int order,
    CharStringLink * words);

bool fromInfoFile(const int order,
    CharStringLink * words,
    CharStringHashTable * hashTable);

bool fromHtmlFile(const int order,
    CharStringLink * words,
    CharStringHashTable * hashTable);

#endif // !BUILD_INVERTED_FILES
