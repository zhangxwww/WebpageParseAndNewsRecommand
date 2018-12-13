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
     *  为了本次作业的展示方便起见，我在这里通过
     *  extractInfoInAllPages来多次调用
     *  extractInfo函数，具体情况可以参见
     *  ExtractInfo.h中的代码
     */
    extractInfoInAllPages();

    /* 这里的hashtable是用于分词的 */
    CharStringHashTable dictionary = initDictionary();

    /** 
     *  为了本次作业的展示方便起见，我在这里通过
     *  DivideWordInAllFiles来多次调用
     *  divideWords函数，具体情况可以参见
     *  DivideWords.h中的代码
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