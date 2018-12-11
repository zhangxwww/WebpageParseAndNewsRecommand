#include "Query.h"
#include "CharString.h"
#include "CharStringLink.h"
#include "CharStringLinkNode.h"
#include "BalancedBinaryTree.h"
#include "BalancedBinaryTreeNode.h"
#include "InvertedFileLinkList.h"
#include "InvertedFileLinkNode.h"
#include "DivideWords.h"

#include <fstream>
#include <string>

void queryAll(BalancedBinaryTree * tree,
    const CharStringHashTable * hashTable) {

    CharString queryFileName;
    queryFileName = L"query1.txt";
    std::wifstream queryFile(queryFileName.wstring());
    std::locale loc(".936");
    queryFile.imbue(loc);

    std::wstring line;
    CharString csline;

    while (!queryFile.eof()) {
        std::getline(queryFile, line);
        CharStringLink queryWords;
        csline = line;
        queryWords.append(divideOneLine(*hashTable, csline));
        InvertedFileLinkList * fileList = query(tree, &queryWords);
        // print
        // delete filelist
        line.clear();
    }
}

InvertedFileLinkList * query(
    BalancedBinaryTree * tree, 
    CharStringLink * queryWords) {

    InvertedFileLinkList * result = 
        new InvertedFileLinkList(nullptr);

    while (queryWords->length() > 0) {
        CharString word = queryWords->pop()->getCharString();
        BalancedBinaryTreeNode * p = nullptr;        
        bool taller = false;
        if (tree->search(tree->getRoot(), word, nullptr, p)) {
            InvertedFileLinkNode * docNode = 
                p->getFileLinkList()->getHead()->getNext();
            while (docNode != nullptr && docNode->getID() != -1) {
                int id = docNode->getID();
                int times = docNode->getTimes();
                result->add(id, times);
            }
        }
    }
    return result;
}
