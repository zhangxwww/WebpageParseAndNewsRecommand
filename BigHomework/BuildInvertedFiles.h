#ifndef BUILD_INVERTED_FILES
#define BUILD_INVERTED_FILES

#include <fstream>
#include <iostream>

class BalancedBinaryTree;
class BalancedBinaryTreeNode;
class CharStringLink;
class CharStringHashTable;

namespace BIF {
    /* ��ҳ���� */
    static const int COUNT_FILES = 781;
}


/**
 *  �����ʵ估�䵹���ĵ�
 *  @return: �ʵ��Ӧ��ƽ��������ĸ����
 */
BalancedBinaryTree * buildInvertedFiles();


/**
 *  ����ʵ估�䵹���ĵ�
 *  @param tree: �ʵ��Ӧ��ƽ��������ĸ����
 */
void save(BalancedBinaryTree * tree);


/**
 *  ����ʵ��һ����㼰��㱣��ĵ����ĵ�
 *  @param node: ��Ҫ����Ľ��
 *  @param file: ��д����ļ�
 */
void saveOneNode(BalancedBinaryTreeNode * node,
    std::wofstream & file);


/**
 *  �����еĴʵ估�����ĵ��ļ��ж��룬�����ʵ��뵹���ĵ�
 *  @param ok: �Ƿ�������еĴʵ�
 *  @return  : ����������㣬���û�ж�Ӧ�ļ��򷵻�nullptr
 */
BalancedBinaryTree * fromExistedInvertedfiles(bool & ok);


/**
 *  �����ݿ��ж������ݣ������ʵ��뵹���ĵ�
 *  @return: �������ĸ����
 */
BalancedBinaryTree * fromDataBase();


/**
 *  ��txt�ִ��ļ��ж������ݣ��������������еĵ��ʹ��ɵ��ַ�������
 *  @param order: ��ҳ���
 *  @param words: �ӷִ��ļ��ж�����ַ�������
 *  @return     : ���ڶ�Ӧ�ķִ��ļ��򷵻�true, ����false
 */
bool fromTxtFile(const int order,
    CharStringLink * words);


/**
 *  ��info�ļ��ж������ݣ��������������еĵ��ʹ��ɵ��ַ�������
 *  @param order    : ��ҳ���
 *  @param words    : ��info�ļ��о��ִʵõ����ַ�������
 *  @param hashTable: �ɴʿ�õ��Ĺ�ϣ�����ڷִ�
 *  @return         : ���ڶ�Ӧ��info�ļ��򷵻�true, ����false
 */
bool fromInfoFile(const int order,
    CharStringLink * words,
    CharStringHashTable * hashTable);


/**
 *  ��html�ļ��ж������ݣ������������������еĵ��ʹ��ɵ��ַ�������
 *  @param order    : ��ҳ���
 *  @param words    : ��html�ļ��о���Ϣ��ȡ���ִʵõ����ַ�������
 *  @param hashTable: �ɴʿ�õ��Ĺ�ϣ�����ڷִ�
 *  @return         : ���ڶ�Ӧ��html�ļ��򷵻�true, ����false
 */
bool fromHtmlFile(const int order,
    CharStringLink * words,
    CharStringHashTable * hashTable);

#endif // !BUILD_INVERTED_FILES
