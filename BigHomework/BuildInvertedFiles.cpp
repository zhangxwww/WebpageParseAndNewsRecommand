#include "BuildInvertedFiles.h"
#include "BalancedBinaryTree.h"
#include "InvertedFileLinkList.h"
#include "ExtractInfo.h"
#include "InitDictionary.h"
#include "DivideWords.h"
#include "Stack.h"

BalancedBinaryTree * buildInvertedFiles() {
    BalancedBinaryTree * tree;
    bool ok = false;
    tree = fromExistedInvertedfiles(ok);
    if (ok) {
        return tree;
    }
    else {
        tree = fromDataBase();
        save(tree);
    }
    return tree;
}

void save(BalancedBinaryTree * tree) {
    CharString fileName;
    fileName = L".\\output\\InvertedFileLink";
    std::wofstream file(fileName.wstring(), std::ios::out);
    std::locale loc(".936");
    file.imbue(loc);
    Stack<BalancedBinaryTreeNode *> waitingNode;
    waitingNode.push(tree->getRoot());
    while (!waitingNode.empty()) {
        // TODO �ο�����P130�Ĵ�������дһ��
        if (waitingNode.top()->getLeft() != nullptr) {
            waitingNode.push(waitingNode.top()->getLeft());
        }
        else {
            BalancedBinaryTreeNode * p = waitingNode.pop();
            // TODO visit p
            if (p->getRight() != nullptr) {
                waitingNode.push(p->getRight());
            }
            else {

            }
        }
    }
}

BalancedBinaryTree * fromDataBase() {

    BalancedBinaryTree * tree = new BalancedBinaryTree;

    // �����hash table�����ڷִʵ�
    CharStringHashTable hashTable;
    bool hashTableInited = false;
   
    for (int id = 0; id < BIF::COUNT_FILES; id++) {
        CharStringLink * words = new CharStringLink;
        // .\outputĿ¼�²����ڶ�Ӧ�ķִ��ļ�.txt
        if (!fromTxtFile(id, words)) {
            if (!hashTableInited) {
                hashTable = initDictionary();
                hashTableInited = true;
            }
            // .\outputĿ¼�²����ڶ�Ӧ����Ϣ�ļ�.info
            if (!fromInfoFile(id, words, &hashTable)) {
                // .\inputĿ¼�²����ڶ�Ӧ����ҳ�ļ�.html
                if (!fromHtmlFile(id, words, &hashTable)) {
                    std::wcout << L"������" << id << ".html" << std::endl;
                    continue;
                }
            }
        }
        words->clearShorterThan(2);

        while (words->length() > 0) {
            CharString word = words->pop()->getCharString();
            BalancedBinaryTreeNode * p = nullptr;
            bool taller = false;
            if (tree->search(tree->getRoot(), word, nullptr, p)
                || tree->insert(tree->getRoot(), p, word, taller)) {
                
                p->getFileLinkList()->add(id);
            }
            else {
                continue;
            }
        }
    }
    return tree;
}

bool fromTxtFile(const int order, 
    CharStringLink * words) {

    CharString txtFileName;
    CharString postFix;
    postFix = L".txt";
    txtFileName = L".\\output\\";
    txtFileName.concat(CharString::parseFromInteger(order));
    txtFileName.concat(postFix);
    std::wifstream file;
    std::locale loc(".936");
    file.imbue(loc);
    file.open(txtFileName.wstring(), std::ios::in);
    if (file) {
        file >> (*words);
    }
    else {
        return false;
    }
    return true;
}

bool fromInfoFile(const int order, 
    CharStringLink * words, 
    CharStringHashTable * hashTable) {

    CharString infoFileName;
    CharString postFix;
    postFix = L".info";
    infoFileName = L".\\output\\";
    infoFileName.concat(CharString::parseFromInteger(order));
    infoFileName.concat(postFix);
    std::wifstream file;
    std::locale loc(".936");
    file.imbue(loc);
    file.open(infoFileName.wstring(), std::ios::in);
    if (file) {
        (*words) = divideWords(infoFileName.subString(9), *hashTable);
    }
    else {
        return false;
    }
    return true;
}

bool fromHtmlFile(const int order, 
    CharStringLink * words, 
    CharStringHashTable * hashTable) {

    CharString htmlFileName;
    CharString postFixInfo;
    CharString postFixHtml;
    CharString path;
    path = L".\\input\\";
    postFixInfo = L".info";
    postFixHtml = L".html";
    htmlFileName = path;
    htmlFileName.concat(CharString::parseFromInteger(order));
    htmlFileName.concat(postFixHtml);

    std::wifstream file;
    std::locale loc(".936");
    file.imbue(loc);
    file.open(htmlFileName.wstring(), std::ios::in);
    if (file) {
        const NewsInfo info = extractInfo(htmlFileName.subString(8));
        (*words) = divideOneLine(*hashTable, info.getContent());
    }
    else {
        return false;
    }
    return true;
}
