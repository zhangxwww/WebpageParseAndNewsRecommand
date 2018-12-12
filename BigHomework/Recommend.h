#ifndef RECOMMEND
#define RECOMMEND

#include "CharString.h"

#include <iostream>

class CharString;
class CharStringLink;
class BalancedBinaryTree;
class CharStringHashTable;

/**
 *  ���query2.txt�����еĲ�ѯ�������д��result2.txt
 *  @param map       : ����id������ӳ��
 *  @param tree      : �ʵ��Ӧ�Ķ�����
 *  @param dictionary: ���ڷִʵĹ�ϣ��
 */
void recommendAll(CharString * map,
    BalancedBinaryTree * tree, 
    CharStringHashTable * dictionary);


/**
 *  ���һ�β�ѯ
 *  @param map       : ����id������ӳ��
 *  @param title     : ���±���
 *  @param tree      : �ʵ��Ӧ�Ķ�����
 *  @param dictionary: ���ڷִʵĹ�ϣ��
 *  @return          : ��ѯ�Ľ�������ַ����������ʽ����
 */
CharStringLink * recommend(CharString * map,
    const CharString & title,
    BalancedBinaryTree * tree, 
    CharStringHashTable * dictionary);


/**
 *  ���Ƽ����д���ļ���
 *  @param map          : ����id������ӳ��
 *  @param recommendDocs: �ַ���������ʽ���Ƽ����µı���
 *  @param file         : ��д����ļ�
 */
void saveRecommendResults(CharString * map,
    CharStringLink * recommendDocs,
    std::wofstream & file);


/**
 *  ���Ƽ��Ľ��ת��Ϊ��ĿҪ��ĸ�ʽ���ַ���
 *  @param id   : ����id
 *  @param title: ���±���
 *  @return     : ������ĿҪ��ĸ�ʽ���ַ���
 */
const CharString generateRecommendResultWithCorrectFormat(
    const int id, const CharString & title);

#endif // !RECOMMEND
