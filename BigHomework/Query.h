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
 *  @param tree      : �ʵ��Ӧ�Ķ�����
 *  @param queryWords: ����ѯ�Ĵ�
 *  @return          : ��ѯ�Ľ�������ĵ��������ʽ����
 */
InvertedFileLinkList * query(
    BalancedBinaryTree * tree, 
    CharStringLink * queryWords);


/**
 *  ����ѯ�õ��Ľ��д���ļ���
 *  @param file    : ��д����ļ�
 *  @param fileList: ���������ĵ�����
 */
void saveResults(std::wofstream & file,
    const InvertedFileLinkList * fileList);


/**
 *  ����ѯ�Ľ��ת��Ϊ��ĿҪ��ĸ�ʽ���ַ���
 *  @param id   : ����id
 *  @param times: ��һ�����в�ѯ�Ĵʳ��ֵ��ܴ���
 *  @return     : ������ĿҪ��ĸ�ʽ���ַ���
 */
const CharString generateResultWithCorrectFormat(
    const int id, const int times);

#endif // !QUERY
