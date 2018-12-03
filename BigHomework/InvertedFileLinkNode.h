#ifndef INVERTED_FILE_LINK_NODE
#define INVERTED_FILE_LINK_NODE

/* �����ĵ������� */
class InvertedFileLinkNode {
public:
    InvertedFileLinkNode(const int id);
    ~InvertedFileLinkNode();


    /**
     *  ��ȡ��ǰ����Ӧ���µ�id
     *  @return: ��ǰ����id
     */
    const int getID() const;


    /**
     *  ��ȡ��ǰ����Ӧ���³��ִ���
     *  @return: ��ǰ������³��ִ���
     */
    const int getTimes() const;


    /**
     *  ��ȡ��ǰ���ĺ��
     *  @return: ��ǰ���ĺ��
     */
    InvertedFileLinkNode * getNext() const;


    /**
     *  ��ȡ��ǰ����ǰ��
     *  @return: ��ǰ����ǰ��
     */
    InvertedFileLinkNode * getPrev() const;


    /**
     *  �趨��ǰ����id
     *  @param id: �趨��id
     */
    void setID(const int id);


    /**
     *  ���ʳ��ִ�����1
     *  @param times: ���ֵĴ���
     */
    void timeIncrease(const int times=1);

    
    /**
     *  ���ʳ��ִ�����1
     */
    void timeDecrease();


    /**
     *  �趨��ǰ���ĺ��
     *  @param next: �趨�ĺ��
     */
    void setNext(InvertedFileLinkNode * next);


    /**
     *  �趨��ǰ����ǰ��
     *  @param next: �趨��ǰ��
     */
    void setPrev(InvertedFileLinkNode * prev);

private:
    /* ��ǰ�����ĵ���id */
    int docID;

    /* ��ǰ�ĵ��е��ʳ��ֵĴ��� */
    int times;

    /* ǰ������ */
    InvertedFileLinkNode * next;
    InvertedFileLinkNode * prev;
};

#endif  // !INVERTED_FILE_LINK_NODE
