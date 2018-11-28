#ifndef INVERTED_FILE_LINK_NODE
#define INVERTED_FILE_LINK_NODE

class InvertedFileLinkNode {
private:
    int docID;
    int times;
    InvertedFileLinkNode * next;

public:
    InvertedFileLinkNode();
    ~InvertedFileLinkNode();
};

#endif  // !INVERTED_FILE_LINK_NODE
