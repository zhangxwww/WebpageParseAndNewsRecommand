#ifndef BALANCED_BINARY_TREE
#define BALANCED_BINARY_TREE

#include "BalancedBinaryTreeNode.h"
#include "CharString.h"

class BalancedBinaryTree {

public:
    BalancedBinaryTree();
    ~BalancedBinaryTree();

    /********** ���¼�������Ϊ��ҵ��Ҫ��ʵ�ֵĻ������� **********/

    /**
     *  ƽ��������Ĳ���
     *  @param root  : ��ǰ���ĸ����
     *  @param p     : �������õ��Ľ��
     *  @param term  : ������Ĵ�
     *  @param taller: ��¼���Ƿ񳤸�
     *  @return      : ����ɹ����� true���Ѵ����򷵻� false
     */
    bool insert(BalancedBinaryTreeNode * & root, 
        BalancedBinaryTreeNode * & p,
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
     *  @param change   : ��¼���Ƿ񳤸�
     */
    void adjust(BalancedBinaryTreeNode * & root,
        const int childType,
        const int changeType,
        bool & change);


    /**
     *  ƽ���������ɾ��
     *  @param root   : ��ǰ���ĸ����
     *  @param parent : root�ĸ��ڵ㣬��ʼ����ӦΪ nullptr
     *  @param term   : ��ɾ���Ĵ�
     *  @param shorter: ��¼���Ƿ�䰫
     *  @return       : ɾ���ɹ����� true���������򷵻� false
     */
    bool remove(BalancedBinaryTreeNode * & root,
        BalancedBinaryTreeNode * parent,
        const CharString & term,
        bool & shorter);


    /**
     *  ƽ��������ı༭
     *  @param root   : ��ǰ���ĸ����
     *  @param p      : ����༭��Ľ��
     *  @param oldTerm: ��ɾ���Ĵ�
     *  @param newTerm: ��ɾ���Ĵ�
     *  @return       : �༭�ɹ����� true�������򷵻� false
     */
    bool edit(BalancedBinaryTreeNode * & root,
        BalancedBinaryTreeNode * & p,
        const CharString & oldTerm,
        const CharString & newTerm);


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

    /* ����adjust�������жϷ����仯���������������������� */
    const static int RIGHT = 1;
    const static int LEFT = 0;

    /* ����adjust�������жϷ����ı仯�����߻��ǽ��� */
    const static int TALLER = 1;
    const static int SHORTER = 0;
};

#endif // !BALANCED_BINARY_TREE
