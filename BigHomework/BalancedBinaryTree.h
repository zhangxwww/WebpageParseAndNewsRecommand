#ifndef BALANCED_BINARY_TREE
#define BALANCED_BINARY_TREE

#include "BalancedBinaryTreeNode.h"
#include "CharString.h"

class BalancedBinaryTree {

public:
    BalancedBinaryTree();
    ~BalancedBinaryTree();

    /********** 以下几个函数为作业中要求实现的基本操作 **********/

    /**
     *  平衡二叉树的插入
     *  @param root  : 当前树的根结点
     *  @param p     : 保存插入得到的结点
     *  @param term  : 待插入的词
     *  @param taller: 记录树是否长高
     *  @return      : 插入成功返回 true，已存在则返回 false
     */
    bool insert(BalancedBinaryTreeNode * & root, 
        BalancedBinaryTreeNode * & p,
        const CharString & term, 
        bool & taller);


    /**
     *  平衡二叉树的搜索
     *  @param root  : 当前查找的树的根结点
     *  @param key   : 关键字
     *  @param parent: root的父结点，初始调用应为 nullptr
     *  @param p     : 保存结果的指针，查找成功则指向该结点，否则指向父结点
     *  @return      : 查找成功返回 true，否则 false
     */
    bool search(BalancedBinaryTreeNode * root,
        const CharString & key, 
        BalancedBinaryTreeNode * parent, 
        BalancedBinaryTreeNode * & p);


    /**
     *  调整平衡二叉树使其平衡
     *  @param root     : 当前树的根结点
     *  @param childType: 用于判断被插入并长高的是左子树还是右子树
     *  @param change   : 记录树是否长高
     */
    void adjust(BalancedBinaryTreeNode * & root,
        const int childType,
        const int changeType,
        bool & change);


    /**
     *  平衡二叉树的删除
     *  @param root   : 当前树的根结点
     *  @param parent : root的父节点，初始调用应为 nullptr
     *  @param term   : 待删除的词
     *  @param shorter: 记录树是否变矮
     *  @return       : 删除成功返回 true，不存在则返回 false
     */
    bool remove(BalancedBinaryTreeNode * & root,
        BalancedBinaryTreeNode * parent,
        const CharString & term,
        bool & shorter);


    /**
     *  平衡二叉树的编辑
     *  @param root   : 当前树的根结点
     *  @param p      : 保存编辑后的结点
     *  @param oldTerm: 待删除的词
     *  @param newTerm: 待删除的词
     *  @return       : 编辑成功返回 true，否则则返回 false
     */
    bool edit(BalancedBinaryTreeNode * & root,
        BalancedBinaryTreeNode * & p,
        const CharString & oldTerm,
        const CharString & newTerm);


    /********** 以下几个函数为为了方便而添加的函数 **********/

    /**
     *  获得树的根结点
     *  @return: 返回树的根结点
     */
    BalancedBinaryTreeNode * & getRoot();

private:

    /**
     *  对以 *root 为根的平衡二叉树做左旋处理，处理之后指向新的树的根节点
     *  @param root: 旋转前后的根节点
     */
    void L_rotate(BalancedBinaryTreeNode * & root);


    /**
     *  对以 *root 为根的平衡二叉树做右旋处理，处理之后指向新的树的根节点
     *  @param root: 旋转前后的根节点
     */
    void R_rotate(BalancedBinaryTreeNode * & root);


    /**
     *  对以 *root 为根的平衡二叉树做左旋平衡处理，处理之后指向新的树的根节点
     *  @param root: 旋转平衡前后的根节点
     */
    void leftBalance(BalancedBinaryTreeNode * & root);


    /**
     *  对以 *root 为根的平衡二叉树做右旋平衡处理，处理之后指向新的树的根节点
     *  @param root: 旋转平衡前后的根节点
     */
    void rightBalance(BalancedBinaryTreeNode * & root);


    /* 树的根节点 */
    BalancedBinaryTreeNode * root;

    /* 用于adjust函数中判断发生变化的树是左子树还是右子树 */
    const static int RIGHT = 1;
    const static int LEFT = 0;

    /* 用于adjust函数中判断发生的变化是增高还是降低 */
    const static int TALLER = 1;
    const static int SHORTER = 0;
};

#endif // !BALANCED_BINARY_TREE
