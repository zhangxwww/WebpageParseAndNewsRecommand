#include "ExtractInfo.h"
#include "InitDictionary.h"
#include "DivideWords.h"

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

    CharStringHashTable hashTable = initDictionary();

    /** 
     *  Ϊ�˱�����ҵ��չʾ�����������������ͨ��
     *  DivideWordInAllFiles����ε���
     *  divideWords����������������Բμ�
     *  DivideWords.h�еĴ���
     */
    divideWordsInAllFiles(hashTable);

    return 0;
}