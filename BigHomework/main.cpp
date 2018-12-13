#include "ExtractInfo.h"
#include "InitDictionary.h"
#include "DivideWords.h"
#include "BuildInvertedFiles.h"
#include "Query.h"
#include "DocIdToTitle.h"
#include "Recommend.h"
#include "BalancedBinaryTree.h"
#include "Tester.h"

#include <iostream>

using namespace std;

int main() {
    /**
     *  Ϊ�˱�����ҵ��չʾ�����������������ͨ��
     *  extractInfoInAllPages����ε���
     *  extractInfo����������������Բμ�
     *  ExtractInfo.h�еĴ���
     */
    extractInfoInAllPages();

    /* �����hashtable�����ڷִʵ� */
    CharStringHashTable dictionary = initDictionary();

    /** 
     *  Ϊ�˱�����ҵ��չʾ�����������������ͨ��
     *  DivideWordInAllFiles����ε���
     *  divideWords����������������Բμ�
     *  DivideWords.h�еĴ���
     */
    divideWordsInAllFiles(dictionary);

    // 
    
    CharString * idToTitle = nullptr;
    idToTitle = getDocIdToTitle();


    BalancedBinaryTree * tree = nullptr;
    tree = buildInvertedFiles(&dictionary);


    // queryAll(tree, &dictionary);

    recommendAll(idToTitle, tree, &dictionary);

    if (idToTitle != nullptr) {
        delete[] idToTitle;
    }
    if (tree != nullptr) {
        delete tree;
    }
    
    // Tester::testCharStringLink();
    return 0;
}