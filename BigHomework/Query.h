#ifndef QUERY
#define QUERY

class CharStringLink;
class CharStringHashTable;
class BalancedBinaryTree;
class InvertedFileLinkList;

void queryAll(BalancedBinaryTree * tree,
    const CharStringHashTable * hashTable);

InvertedFileLinkList * query(
    BalancedBinaryTree * tree, 
    CharStringLink * queryWords);

#endif // !QUERY
