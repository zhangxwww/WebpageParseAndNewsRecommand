#ifndef DIVIDE_WORDS_H
#define DIVIDE_WORDS_H

#include "CharString.h"
#include "CharStringLink.h"
#include "Stack.h"

class CharStringHashTable;

/**
 *  分词算法
 *  @param infoFilename: 所要进行分词的.info文件名
 *  @param hashTable   : 由词库得到的哈希表
 *  @return            : 字符串链表类型的分词结果
 */
CharStringLink divideWords(
    const CharString & infoFilename,
    const CharStringHashTable & hashTable);


/*********************Assisted functions*********************/

/**
 *  对所有的.info文件进行分词
 *  @param hashTable: 由词库得到的哈希表
 */
void divideWordsInAllFiles(
    const CharStringHashTable & hashTable);


/**
 *  获取output文件夹下所有的.info文件的文件名
 *  @return: CharString类型的栈，保存所获取的所有文件名
 */
Stack<CharString> getInfoFileList();


/**
 *  对文件中某一行进行分词
 *  @param hashTable: 由词库得到的哈希表
 *  @param line     : 正文的某一行
 *  @return         : 字符串链表类型的分词结果
 */
const CharStringLink divideOneLine(
    const CharStringHashTable & hashTable, 
    const CharString & line);


/**
 *  获得下一个词
 *  @param line     : 正文的某一行
 *  @param start    : 起始位置
 *  @param hashTable: 由词库得到的哈希表
 *  @return         : 获得的下一个词
 */
const CharString getNextWord(
    const CharString & line,
    int start, 
    const CharStringHashTable & hashTable);


/**
 *  判断一个字是否为中文字符
 *  @param cs: 待判断的词
 *  @return  : 是中文字符则返回true，否则返回false
 */
bool isChineseCharacter(const CharString & cs);


/**
 *  判断一个词是否为英文单词
 *  @param word: 待判断的词
 *  @return    : 是英文单词则返回true，否则返回false
 */
bool isEnglishWords(const CharString & word);


/**
 *  判断一个词是否为一串数字
 *  @param cs: 待判断的词
 *  @return  : 是中文字符则返回true，否则返回false
 */
bool isNumbers(const CharString & cs);


/**
 *  将所分词结果保存在对应的.txt文件中
 *  @param dividedWords: 分词结果
 *  @param infoFilename: .info文件的文件名
 */
void saveDividedWords(
    const CharStringLink & dividedWords,
    const CharString & infoFilename);

#endif // !DIVIDE_WORDS_H
