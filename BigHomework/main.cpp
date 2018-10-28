#include "ExtractInfo.h"
#include "InitDictionary.h"
#include "DivideWords.h"

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

    CharStringHashTable hashTable = initDictionary();

    /** 
     *  为了本次作业的展示方便起见，我在这里通过
     *  DivideWordInAllFiles来多次调用
     *  divideWords函数，具体情况可以参见
     *  DivideWords.h中的代码
     */
    divideWordsInAllFiles(hashTable);

    return 0;
}