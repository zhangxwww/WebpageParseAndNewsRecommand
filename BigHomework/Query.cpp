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

    // ÿ�ζ����һ�У�����һ�β�ѯ
    while (!queryFile.eof()) {
        std::getline(queryFile, line);
        CharStringLink queryWords;
        csline = line;
        // �ִ�
        queryWords.append(divideOneLine(*dictionary, csline));
        // ���ĵ��������ʽ�����ѯ�Ľ��
        // ��ʵ�����ǶԼ������ʶ�Ӧ�ĵ����ĵ������˺ϲ�
        InvertedFileLinkList * fileList = query(tree, &queryWords);
        // ������
        saveResults(resultFile, fileList);
        delete fileList;
        line.clear();
    }
    queryFile.close();
    resultFile.close();
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
                result->add(docNode->getID(), docNode->getTimes());
                docNode = docNode->getNext();
            }
        }
    }
    return result;
}

void saveResults(std::wofstream & file, 
    const InvertedFileLinkList * fileList) {

    InvertedFileLinkNode * p = fileList->getHead()->getNext();
    while (p != nullptr && p->getID() != -1) {            
        file << generateResultWithCorrectFormat(
            p->getID(), p->getTimes());
        p = p->getNext();
    }
    file << std::endl;
}

const CharString generateResultWithCorrectFormat(
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
