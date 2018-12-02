#ifndef BALANCED_BINARY_TREE
#define BALANCED_BINARY_TREE

#include "BalancedBinaryTreeNode.h"

class BalancedBinaryTree {

public:
    BalancedBinaryTree();
    ~BalancedBinaryTree();

    /********** ���¼�������Ϊ��ҵ��Ҫ��ʵ�ֵĻ������� **********/

    /**
     *  ƽ��������Ĳ���
     *  @param root  : ��ǰ���ĸ����
     *  @param term  : ������Ĵ�
     *  @param taller: ��¼���Ƿ񳤸�
     *  @return      : ����ɹ����� true���Ѵ����򷵻� false
     */
    bool insert(BalancedBinaryTreeNode * & root,
        const CharString & term,
        bool & taller);


    /**
     *  ƽ�������������
     *  @param root  : ��ǰ���ҵ����ĸ����
     *  @param key   : �ؼ���
     *  @param parent: root�ĸ���㣬��ʼ����ӦΪ nullptr
     *  @param p     : ��������ָ�룬���ҳɹ���ָ��ý�㣬����ָ�򸸽��
     *  @return      : ���ҳɹ����� true������ false
     */
    bool search(BalancedBinaryTreeNode * root,
        const CharString & key, 
        BalancedBinaryTreeNode * parent, 
        BalancedBinaryTreeNode * & p);


    /**
     *  ����ƽ�������ʹ��ƽ��
     *  @param root     : ��ǰ���ĸ����
     *  @param childType: �����жϱ����벢���ߵ�������������������
     *  @param taller   : ��¼���Ƿ񳤸�
     */
    void adjust(BalancedBinaryTreeNode * & root,
        const int childType,
        bool & taller);


    /********** ���¼�������ΪΪ�˷������ӵĺ��� **********/

    /**
     *  ������ĸ����
     *  @return: �������ĸ����
     */
    BalancedBinaryTreeNode * & getRoot();

private:

    /**
     *  ���� *root Ϊ����ƽ���������������������֮��ָ���µ����ĸ��ڵ�
     *  @param root: ��תǰ��ĸ��ڵ�
     */
    void L_rotate(BalancedBinaryTreeNode * & root);


    /**
     *  ���� *root Ϊ����ƽ���������������������֮��ָ���µ����ĸ��ڵ�
     *  @param root: ��תǰ��ĸ��ڵ�
     */
    void R_rotate(BalancedBinaryTreeNode * & root);


    /**
     *  ���� *root Ϊ����ƽ�������������ƽ�⴦������֮��ָ���µ����ĸ��ڵ�
     *  @param root: ��תƽ��ǰ��ĸ��ڵ�
     */
    void leftBalance(BalancedBinaryTreeNode * & root);


    /**
     *  ���� *root Ϊ����ƽ�������������ƽ�⴦������֮��ָ���µ����ĸ��ڵ�
     *  @param root: ��תƽ��ǰ��ĸ��ڵ�
     */
    void rightBalance(BalancedBinaryTreeNode * & root);


    /* ���ĸ��ڵ� */
    BalancedBinaryTreeNode * root;

    /* ����adjust�������жϲ��벢���ߵ��������������������� */
    const static int RIGHT = 1;
    const static int LEFT = 0;
};

#endif // !BALANCED_BINARY_TREE
