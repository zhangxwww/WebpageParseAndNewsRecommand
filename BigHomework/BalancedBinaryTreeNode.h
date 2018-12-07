#ifndef BALANCED_BINARY_TREE_NODE
#define BALANCED_BINARY_TREE_NODE

#include "CharString.h"
#include "BalancedFactor.h"

class InvertedFileLinkList;

/* ƽ��������Ľ�� */
class BalancedBinaryTreeNode {
public:
    BalancedBinaryTreeNode(const CharString & term);
    ~BalancedBinaryTreeNode();


    /**
     *  ��ȡ����
     *  @return: ��ǰ��������
     */
    BalancedBinaryTreeNode * & getLeft();


    /**
     *  ��ȡ�Һ���
     *  @return: ��ǰ�����Һ���
     */
    BalancedBinaryTreeNode * & getRight();


    /**
     *  ��ȡ�Ե�ǰ����ƽ������
     *  @return: ƽ������
     */
    BalancedFactor getBalancedFactor() const;


    /**
     *  �趨��ǰ��������
     *  @param p: ����
     */
    void setLeft(BalancedBinaryTreeNode * p);


    /**
     *  �趨��ǰ�����Һ���
     *  @param p: �Һ���
     */
    void setRight(BalancedBinaryTreeNode * p);


    /**
     *  �ı䵱ǰ����ƽ������
     *  @param bf: ƽ������
     */
    void setBalancedFactor(BalancedFactor bf);


    /**
     *  ��ȡ�Ե�ǰ���ı�����ַ���
     *  @return: ��ǰ��㱣����ַ���
     */
    const CharString & getTerm() const;


    /**
     *  ��ȡ�Ե�ǰ���ı���ĵ����ĵ�����
     *  @return: ��ǰ��㱣��ĵ����ĵ�����
     */
    InvertedFileLinkList * getFileLinkList() const;


    /**
     *  ����ĵ���������
     */
    void docIncrease();


    /**
     *  �ܳ��ִ�������
     */
    void totalIncrease();


    /**
     *  ��ȡ�Ե�ǰ��㵥�ʳ��ֹ������´�����Ҳ��������ĳ���
     *  @return: ��ǰ��������
     */
    const int getDocs() const;


    /**
     *  ��ȡ�Ե�ǰ��㵥���ܳ��ִ���
     *  @return: ��ǰ��㵥���ܳ��ִ���
     */
    const int getTotal() const;

private:
    /* ��ǰ��㱣����ַ��� */
    CharString term;

    /* ����ĵ����� */
    int countOfRelatedDocs;

    /* ������ֵ��ܴ��� */
    int totalOccur;

    /* �����Ӧ�ĵ����ĵ� */
    InvertedFileLinkList * list;

    /* ���� */
    BalancedBinaryTreeNode * left;

    /* �Һ��� */
    BalancedBinaryTreeNode * right;

    /* ƽ������ */
    BalancedFactor bf;
};

#endif // !BALANCED_BINARY_TREE_NODE
