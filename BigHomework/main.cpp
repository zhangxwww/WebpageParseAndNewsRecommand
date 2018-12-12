#include "ExtractInfo.h"
#include "InitDictionary.h"
#include "DivideWords.h"
#include "BuildInvertedFiles.h"
#include "Query.h"
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



    BalancedBinaryTree * tree = buildInvertedFiles(&dictionary);


    queryAll(tree, &dictionary);

    return 0;
}