#ifndef QUERY
#define QUERY

#include "CharString.h"

#include <fstream>

class CharStringLink;
class CharStringHashTable;
class BalancedBinaryTree;
class InvertedFileLinkList;

void queryAll(BalancedBinaryTree * tree,
    const CharStringHashTable * hashTable);

InvertedFileLinkList * query(
    BalancedBinaryTree * tree, 
    CharStringLink * queryWords);

void saveResults(std::wofstream & file,
    const InvertedFileLinkList * fileList);

const CharString generateResultWithCorrectFormat(
    const int id, const int times);

#endif // !QUERY
