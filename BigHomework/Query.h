#ifndef QUERY
#define QUERY

#include "CharString.h"

#include <fstream>

class CharStringLink;
class CharStringHashTable;
class BalancedBinaryTree;
class InvertedFileLinkList;


/**
 *  完成query1.txt中所有的查询，将结果写入result1.txt
 *  @param tree      : 词典对应的二叉树
 *  @param dictionary: 用于分词的哈希表
 */
void queryAll(BalancedBinaryTree * tree,
    const CharStringHashTable * dictionary);


/**
 *  完成一次查询
 *  @param tree              : 词典对应的二叉树
 *  @param queryWords        : 待查询的词
 *  @param excludeCommonWords: 是否排除常用词，如果是，则除掉出现在100篇以上文章中的词后再查询
 *  @return                  : 查询的结果，以文档链表的形式保存
 */
InvertedFileLinkList * query(
    BalancedBinaryTree * tree,
    CharStringLink * queryWords, 
    bool excludeCommonWords=false);


/**
 *  将查询得到的结果写入文件中
 *  @param file    : 待写入的文件
 *  @param fileList: 保存结果的文档链表
 */
void saveQueryResults(std::wofstream & file,
    const InvertedFileLinkList * fileList);


/**
 *  将查询的结果转化为题目要求的格式的字符串
 *  @param id   : 文章id
 *  @param times: 这一文章中查询的词出现的总次数
 *  @return     : 按照题目要求的格式的字符串
 */
const CharString generateQueryResultWithCorrectFormat(
    const int id, const int times);

#endif // !QUERY
