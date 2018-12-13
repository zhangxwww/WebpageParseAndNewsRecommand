#ifndef QUERY
#define QUERY

#include "CharString.h"

#include <fstream>

class CharStringLink;
class CharStringHashTable;
class BalancedBinaryTree;
class InvertedFileLinkList;


/**
 *  ���query1.txt�����еĲ�ѯ�������д��result1.txt
 *  @param tree      : �ʵ��Ӧ�Ķ�����
 *  @param dictionary: ���ڷִʵĹ�ϣ��
 */
void queryAll(BalancedBinaryTree * tree,
    const CharStringHashTable * dictionary);


/**
 *  ���һ�β�ѯ
 *  @param tree              : �ʵ��Ӧ�Ķ�����
 *  @param queryWords        : ����ѯ�Ĵ�
 *  @param excludeCommonWords: �Ƿ��ų����ôʣ�����ǣ������������100ƪ���������еĴʺ��ٲ�ѯ
 *  @return                  : ��ѯ�Ľ�������ĵ��������ʽ����
 */
InvertedFileLinkList * query(
    BalancedBinaryTree * tree,
    CharStringLink * queryWords, 
    bool excludeCommonWords=false);


/**
 *  ����ѯ�õ��Ľ��д���ļ���
 *  @param file    : ��д����ļ�
 *  @param fileList: ���������ĵ�����
 */
void saveQueryResults(std::wofstream & file,
    const InvertedFileLinkList * fileList);


/**
 *  ����ѯ�Ľ��ת��Ϊ��ĿҪ��ĸ�ʽ���ַ���
 *  @param id   : ����id
 *  @param times: ��һ�����в�ѯ�Ĵʳ��ֵ��ܴ���
 *  @return     : ������ĿҪ��ĸ�ʽ���ַ���
 */
const CharString generateQueryResultWithCorrectFormat(
    const int id, const int times);

#endif // !QUERY
