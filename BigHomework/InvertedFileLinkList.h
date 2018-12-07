#ifndef INVERTED_FILE_LINK_LIST
#define INVERTED_FILE_LINK_LIST

#include "InvertedFileLinkNode.h"

class BalancedBinaryTreeNode;

/* �����ĵ����� */
class InvertedFileLinkList {
public:
    InvertedFileLinkList(
        BalancedBinaryTreeNode * node);
    ~InvertedFileLinkList();


    /********** ���¼�������Ϊ��ҵ��Ҫ��ʵ�ֵĻ������� **********/

    /**
     *  ���ĵ������в����Ӧid�Ľ��
     *  @param docID: ��������ĵ�id
     *  @param times: �ĵ��е��ʳ��ֵĴ���
     */
    void add(const int docID, const int times=1);


    /**
     *  ���ĵ�������������Ӧid�Ľ��
     *  @param docID: ���������ĵ�id
     *  @return     : �����ɹ�����ָ���Ӧ����ָ�룬���򷵻�β���
     */
    InvertedFileLinkNode * search(
        const int docID) const;


    /**
     *  ��������preID��Ӧ���ĵ���id��ΪnewID
     *  @param preID: �޸�֮ǰ��id
     *  @param newID: �޸�֮���id
     *  @return     : �޸ĳɹ�����true, ����false
     */
    bool edit(const int preID, const int newID);


    /**
     *  ���ĵ�������ɾ����Ӧid�Ľ��
     *  @param docID: ��ɾ�����ĵ�id
     *  @return     : ɾ���ɹ�����true, ����false
     */
    bool remove(const int docID);


    /**
     *  ��������ͷ���
     *  @return: ����ͷ���
     */
    InvertedFileLinkNode * getHead() const;

private:
    /* �����ͷβ��� */
    InvertedFileLinkNode * head;
    InvertedFileLinkNode * tail;

    /* ָ��������϶�Ӧ�Ľ�� */
    BalancedBinaryTreeNode * bbtNode;
};

#endif // !INVERTED_FILE_LINK_LIST
