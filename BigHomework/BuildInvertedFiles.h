#ifndef BUILD_INVERTED_FILES
#define BUILD_INVERTED_FILES

#include <fstream>
#include <iostream>

class BalancedBinaryTree;
class BalancedBinaryTreeNode;
class CharStringLink;
class CharStringHashTable;

namespace BIF {
    /* 网页总数 */
    static const int COUNT_FILES = 781;
}


/**
 *  建立词典及其倒排文档
 *  @return: 词典对应的平衡二叉树的根结点
 */
BalancedBinaryTree * buildInvertedFiles();


/**
 *  保存词典及其倒排文档
 *  @param tree: 词典对应的平衡二叉树的根结点
 */
void save(BalancedBinaryTree * tree);


/**
 *  保存词典的一个结点及结点保存的倒排文档
 *  @param node: 所要保存的结点
 *  @param file: 待写入的文件
 */
void saveOneNode(BalancedBinaryTreeNode * node,
    std::wofstream & file);


/**
 *  从已有的词典及倒排文档文件中读入，建立词典与倒排文档
 *  @param ok: 是否存在已有的词典
 *  @return  : 二叉树根结点，如果没有对应文件则返回nullptr
 */
BalancedBinaryTree * fromExistedInvertedfiles(bool & ok);


/**
 *  从数据库中读入数据，建立词典与倒排文档
 *  @return: 二叉树的根结点
 */
BalancedBinaryTree * fromDataBase();


/**
 *  从txt分词文件中读入数据，返回文章中所有的单词构成的字符串链表
 *  @param order: 网页序号
 *  @param words: 从分词文件中读入的字符串链表
 *  @return     : 存在对应的分词文件则返回true, 否则false
 */
bool fromTxtFile(const int order,
    CharStringLink * words);


/**
 *  从info文件中读入数据，返回文章中所有的单词构成的字符串链表
 *  @param order    : 网页序号
 *  @param words    : 从info文件中经分词得到的字符串链表
 *  @param hashTable: 由词库得到的哈希表，用于分词
 *  @return         : 存在对应的info文件则返回true, 否则false
 */
bool fromInfoFile(const int order,
    CharStringLink * words,
    CharStringHashTable * hashTable);


/**
 *  从html文件中读入数据，返回文章内容中所有的单词构成的字符串链表
 *  @param order    : 网页序号
 *  @param words    : 从html文件中经信息提取、分词得到的字符串链表
 *  @param hashTable: 由词库得到的哈希表，用于分词
 *  @return         : 存在对应的html文件则返回true, 否则false
 */
bool fromHtmlFile(const int order,
    CharStringLink * words,
    CharStringHashTable * hashTable);

#endif // !BUILD_INVERTED_FILES
