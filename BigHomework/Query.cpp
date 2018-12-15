#include "Query.h"
#include "CharStringLink.h"
#include "CharStringLinkNode.h"
#include "BalancedBinaryTree.h"
#include "BalancedBinaryTreeNode.h"
#include "InvertedFileLinkList.h"
#include "InvertedFileLinkNode.h"
#include "DivideWords.h"

#include <string>

void queryAll(BalancedBinaryTree * tree,
    const CharStringHashTable * dictionary) {

    std::cout << "Start to query" << std::endl;

    CharString queryFileName;
    CharString resultFileName;
    queryFileName = L"query1.txt";
    resultFileName = L"result1.txt";
    std::wifstream queryFile(queryFileName.wstring());
    std::wofstream resultFile(resultFileName.wstring());
    std::locale loc(".936");
    queryFile.imbue(loc);
    resultFile.imbue(loc);

    std::wstring line;
    CharString csline;

    // 每次读入的一行，就是一次查询
    while (!queryFile.eof()) {
        std::getline(queryFile, line);
        CharStringLink queryWords;
        csline = line;
        // 分词
        queryWords.append(divideOneLine(*dictionary, csline));
        // 用文档链表的形式保存查询的结果
        // 这实际上是对几个单词对应的倒排文档进行了合并
        InvertedFileLinkList * fileList = query(tree, &queryWords);
        // 保存结果
        saveQueryResults(resultFile, fileList);
        delete fileList;
        line.clear();
    }
    queryFile.close();
    resultFile.close();

    std::cout << "Finish querying!" << std::endl;
    std::cout << std::endl;
}

InvertedFileLinkList * query(
    BalancedBinaryTree * tree, 
    CharStringLink * queryWords, 
    bool excludeCommonWords) {

    InvertedFileLinkList * result = 
        new InvertedFileLinkList(nullptr);

    while (queryWords->length() > 0) {
        CharString word = queryWords->pop()->getCharString();
        BalancedBinaryTreeNode * p = nullptr;        
        bool taller = false;
        if (tree->search(tree->getRoot(), word, nullptr, p)           
            && (!excludeCommonWords 
                // 如果选择了排除常用词，那么会去掉在超过100篇文章中出现过的词
                || (excludeCommonWords && p->getDocs() < 50))) {

            InvertedFileLinkNode * docNode = 
                p->getFileLinkList()->getHead()->getNext();
            while (docNode != nullptr && docNode->getID() != -1) {
                result->add(docNode->getID(), docNode->getTimes());
                docNode = docNode->getNext();
            }
        }
    }
    return result;
}

void saveQueryResults(std::wofstream & file, 
    const InvertedFileLinkList * fileList) {

    InvertedFileLinkNode * p = fileList->getHead()->getNext();
    while (p != nullptr && p->getID() != -1) {            
        file << generateQueryResultWithCorrectFormat(
            p->getID(), p->getTimes());
        p = p->getNext();
    }
    file << std::endl;
}

const CharString generateQueryResultWithCorrectFormat(
    const int id, const int times) {

    CharString result;
    result = L"(";
    result.concat(CharString::parseFromInteger(id));
    result.concat(L',');
    result.concat(CharString::parseFromInteger(times));
    result.concat(L')');
    result.concat(L' ');
    return result;
}
