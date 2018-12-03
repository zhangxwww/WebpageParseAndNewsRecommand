#ifndef INVERTED_FILE_LINK_NODE
#define INVERTED_FILE_LINK_NODE

/* 倒排文档链表结点 */
class InvertedFileLinkNode {
public:
    InvertedFileLinkNode(const int id);
    ~InvertedFileLinkNode();


    /**
     *  获取当前结点对应文章的id
     *  @return: 当前结点的id
     */
    const int getID() const;


    /**
     *  获取当前结点对应文章出现次数
     *  @return: 当前结点文章出现次数
     */
    const int getTimes() const;


    /**
     *  获取当前结点的后继
     *  @return: 当前结点的后继
     */
    InvertedFileLinkNode * getNext() const;


    /**
     *  获取当前结点的前驱
     *  @return: 当前结点的前驱
     */
    InvertedFileLinkNode * getPrev() const;


    /**
     *  设定当前结点的id
     *  @param id: 设定的id
     */
    void setID(const int id);


    /**
     *  单词出现次数加1
     *  @param times: 出现的次数
     */
    void timeIncrease(const int times=1);

    
    /**
     *  单词出现次数减1
     */
    void timeDecrease();


    /**
     *  设定当前结点的后继
     *  @param next: 设定的后继
     */
    void setNext(InvertedFileLinkNode * next);


    /**
     *  设定当前结点的前驱
     *  @param next: 设定的前驱
     */
    void setPrev(InvertedFileLinkNode * prev);

private:
    /* 当前结点的文档的id */
    int docID;

    /* 当前文档中单词出现的次数 */
    int times;

    /* 前驱与后继 */
    InvertedFileLinkNode * next;
    InvertedFileLinkNode * prev;
};

#endif  // !INVERTED_FILE_LINK_NODE
