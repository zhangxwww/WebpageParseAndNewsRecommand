#include "BuildInvertedFiles.h"
#include "BalancedBinaryTree.h"
#include "InvertedFileLinkList.h"
#include "ExtractInfo.h"
#include "InitDictionary.h"
#include "DivideWords.h"
#include "Stack.h"

#include <sstream>
#include <string>

BalancedBinaryTree * buildInvertedFiles() {
    BalancedBinaryTree * tree = nullptr;
    bool ok = false;
    // ��������Ѿ���ɵĴʵ��뵹���ĵ����ļ�
    tree = fromExistedInvertedfiles(ok);
    if (ok) {
        return tree;
    }
    // ��������ݿ��ж�ȡ���ݽ��н���
    else {
        tree = fromDataBase();
        save(tree);
    }
    return tree;
}

void save(BalancedBinaryTree * tree) {
    std::cout << "saving..." << std::endl;
    CharString fileName;
    fileName = L".\\output\\InvertedFileLink";
    std::wofstream file(fileName.wstring());
    std::locale loc(".936");
    file.imbue(loc);
    Stack<BalancedBinaryTreeNode *> waitingNode;
    BalancedBinaryTreeNode * p = tree->getRoot();

    // �������������
    while (p != nullptr
        || !waitingNode.empty()) {
        
        if (p != nullptr) {
            waitingNode.push(p);
            p = p->getLeft();
        }
        else {
            p = waitingNode.pop();
            saveOneNode(p, file);
            p = p->getRight();
        }
    }
    file.close();
}

void saveOneNode(BalancedBinaryTreeNode * node,
    std::wofstream & file) {

    std::locale loc(".936");
    file.imbue(loc);
    file << node->getTerm() << L" ";
    InvertedFileLinkNode * p = node->getFileLinkList()
        ->getHead()->getNext();
    file << node->getDocs() << L" ";
    while (p != nullptr && p->getID() != -1) {
        file << p->getID() << " " << p->getTimes() << " ";
        p = p->getNext();
    }
    file << std::endl;
}

BalancedBinaryTree * fromExistedInvertedfiles(bool & ok) {
    BalancedBinaryTree * tree = new BalancedBinaryTree;
    CharString fileName;
    fileName = L".\\output\\InvertedFileLink";
    std::wifstream file(fileName.wstring());
    // �����ڸ��ļ�
    if (!file) {
        ok = false;
        return nullptr;
    }
    ok = true;
    std::locale loc(".936");
    file.imbue(loc);
    std::wstring line;
    std::wstringstream sstream;
    sstream.imbue(loc);
    std::wstring word;
    CharString csword;
    BalancedBinaryTreeNode * p = nullptr;
    bool taller;
    while (!file.eof()) {
        std::getline(file, line);
        if (line.empty()) {
            continue;
        }
        sstream << line;
        sstream >> word;
        csword = word;
        tree->insert(tree->getRoot(), p, csword, taller);
        int count;
        sstream >> count;
        for (int i = 0; i < count; i++) {
            int docId;
            int times;
            sstream >> docId >> times;
            p->getFileLinkList()->add(docId, times);
        }
        sstream.clear();
        word.clear();
    }
    file.close();
    return tree;
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
        // ȥ������С��2�ģ�������ȫ��������ɵĵ���
        words->clearShorterThan(2);
        words->clearNumbers();

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
        delete words;
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
        std::wcout << txtFileName << std::endl;
        file >> (*words);
        file.close();
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
        std::wcout << infoFileName << std::endl;
        file.close();
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
        std::wcout << htmlFileName << std::endl;
        file.close();
        const NewsInfo info = extractInfo(htmlFileName.subString(8));
        saveNewsInfo(info, htmlFileName.subString(8));
        (*words) = divideOneLine(*hashTable, info.getContent());
    }
    else {
        return false;
    }
    return true;
}
