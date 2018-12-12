#ifndef RECOMMEND
#define RECOMMEND

#include "CharString.h"

#include <iostream>

class CharString;
class CharStringLink;
class BalancedBinaryTree;
class CharStringHashTable;

/**
 *  完成query2.txt中所有的查询，将结果写入result2.txt
 *  @param map       : 文章id与标题的映射
 *  @param tree      : 词典对应的二叉树
 *  @param dictionary: 用于分词的哈希表
 */
void recommendAll(CharString * map,
    BalancedBinaryTree * tree, 
    CharStringHashTable * dictionary);


/**
 *  完成一次查询
 *  @param map       : 文章id与标题的映射
 *  @param title     : 文章标题
 *  @param tree      : 词典对应的二叉树
 *  @param dictionary: 用于分词的哈希表
 *  @return          : 查询的结果，以字符串链表的形式保存
 */
CharStringLink * recommend(CharString * map,
    const CharString & title,
    BalancedBinaryTree * tree, 
    CharStringHashTable * dictionary);


/**
 *  将推荐结果写入文件中
 *  @param map          : 文章id与标题的映射
 *  @param recommendDocs: 字符串链表形式的推荐文章的标题
 *  @param file         : 待写入的文件
 */
void saveRecommendResults(CharString * map,
    CharStringLink * recommendDocs,
    std::wofstream & file);


/**
 *  将推荐的结果转化为题目要求的格式的字符串
 *  @param id   : 文章id
 *  @param title: 文章标题
 *  @return     : 按照题目要求的格式的字符串
 */
const CharString generateRecommendResultWithCorrectFormat(
    const int id, const CharString & title);

#endif // !RECOMMEND
