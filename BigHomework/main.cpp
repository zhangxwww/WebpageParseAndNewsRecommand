#include "ExtractInfo.h"
#include "InitDictionary.h"
#include "DivideWords.h"
#include "BuildInvertedFiles.h"
#include "Query.h"
#include "DocIdToTitle.h"
#include "Recommend.h"
#include "BalancedBinaryTree.h"
#include "Tester.h"

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

    
    /* ��ȡ����id�����֮���ӳ�䣬����֮����Ƽ� */
    CharString * idToTitle = nullptr;
    idToTitle = getDocIdToTitle();

    /* �����ʵ������뵹���ĵ����� */
    BalancedBinaryTree * tree = nullptr;
    tree = buildInvertedFiles(&dictionary);

    /* ������ѯ */
    queryAll(tree, &dictionary);

    /* �����Ƽ� */
    recommendAll(idToTitle, tree, &dictionary);

    if (idToTitle != nullptr) {
        delete[] idToTitle;
    }
    if (tree != nullptr) {
        delete tree;
    }
    
    return 0;
}