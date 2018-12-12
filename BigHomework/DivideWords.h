#ifndef DIVIDE_WORDS_H
#define DIVIDE_WORDS_H

#include "CharString.h"
#include "CharStringLink.h"
#include "Stack.h"

class CharStringHashTable;

/**
 *  �ִ��㷨
 *  @param infoFilename: ��Ҫ���зִʵ�.info�ļ���
 *  @param hashTable   : �ɴʿ�õ��Ĺ�ϣ��
 *  @return            : �ַ����������͵ķִʽ��
 */
CharStringLink divideWords(
    const CharString & infoFilename,
    const CharStringHashTable & hashTable);


/*********************Assisted functions*********************/

/**
 *  �����е�.info�ļ����зִ�
 *  @param hashTable: �ɴʿ�õ��Ĺ�ϣ��
 */
void divideWordsInAllFiles(
    const CharStringHashTable & hashTable);


/**
 *  ��ȡoutput�ļ��������е�.info�ļ����ļ���
 *  @return: CharString���͵�ջ����������ȡ�������ļ���
 */
Stack<CharString> getInfoFileList();


/**
 *  ���ļ���ĳһ�н��зִ�
 *  @param hashTable: �ɴʿ�õ��Ĺ�ϣ��
 *  @param line     : ���ĵ�ĳһ��
 *  @return         : �ַ����������͵ķִʽ��
 */
const CharStringLink divideOneLine(
    const CharStringHashTable & hashTable, 
    const CharString & line);


/**
 *  �����һ����
 *  @param line     : ���ĵ�ĳһ��
 *  @param start    : ��ʼλ��
 *  @param hashTable: �ɴʿ�õ��Ĺ�ϣ��
 *  @return         : ��õ���һ����
 */
const CharString getNextWord(
    const CharString & line,
    int start, 
    const CharStringHashTable & hashTable);


/**
 *  �ж�һ�����Ƿ�Ϊ�����ַ�
 *  @param cs: ���жϵĴ�
 *  @return  : �������ַ��򷵻�true�����򷵻�false
 */
bool isChineseCharacter(const CharString & cs);


/**
 *  �ж�һ�����Ƿ�ΪӢ�ĵ���
 *  @param word: ���жϵĴ�
 *  @return    : ��Ӣ�ĵ����򷵻�true�����򷵻�false
 */
bool isEnglishWords(const CharString & word);


/**
 *  �ж�һ�����Ƿ�Ϊһ������
 *  @param cs: ���жϵĴ�
 *  @return  : �������ַ��򷵻�true�����򷵻�false
 */
bool isNumbers(const CharString & cs);


/**
 *  �����ִʽ�������ڶ�Ӧ��.txt�ļ���
 *  @param dividedWords: �ִʽ��
 *  @param infoFilename: .info�ļ����ļ���
 */
void saveDividedWords(
    const CharStringLink & dividedWords,
    const CharString & infoFilename);

#endif // !DIVIDE_WORDS_H
