#include "ExtractInfo.h"
#include "InitDictionary.h"
#include "DivideWords.h"
#include "BuildInvertedFiles.h"
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
    // extractInfoInAllPages();

    /* �����hashtable�����ڷִʵ� */
    CharStringHashTable hashTable = initDictionary();

    /** 
     *  Ϊ�˱�����ҵ��չʾ�����������������ͨ��
     *  DivideWordInAllFiles����ε���
     *  divideWords����������������Բμ�
     *  DivideWords.h�еĴ���
     */
    // divideWordsInAllFiles(hashTable);


    // Tester::testCharString();
    BalancedBinaryTree * tree = buildInvertedFiles(&hashTable);
    // Tester::testBalancedBinaryTree();
    
    return 0;
}