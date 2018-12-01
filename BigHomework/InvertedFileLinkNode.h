#ifndef INVERTED_FILE_LINK_NODE
#define INVERTED_FILE_LINK_NODE

class InvertedFileLinkNode {

public:
    InvertedFileLinkNode();
    ~InvertedFileLinkNode();

private:
    int docID;
    int times;
    InvertedFileLinkNode * next;

};

#endif  // !INVERTED_FILE_LINK_NODE
