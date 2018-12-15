#include "Tester.h"
#include "Stack.h"
#include "CharString.h"
#include "CharStringLinkNode.h"
#include "CharStringLink.h"
#include "NewsInfo.h"
#include "ExtractInfo.h"
#include "InitDictionary.h"
#include "DivideWords.h"
#include "BalancedBinaryTree.h"
#include "DocIdToTitle.h"

#include <iostream>

void Tester::testStack() {
    Stack<int> stack;
    std::cout << stack.empty() << std::endl;
    for (int i = 0; i < 100; i++) {
        stack.push(i);
    }
    std::cout << stack.empty() << std::endl;
    std::cout << stack.top() << std::endl;
    for (int i = 0; i < 100; i++) {
        int j = stack.pop();
        std::cout << j << std::endl;
    }
    std::cout << std::endl;
    std::cout << stack.empty() << std::endl;
    try {
        stack.pop();
    }
    catch (Status s) {
        std::cout << s << std::endl;
    }
}

void Tester::testCharString() {
    std::locale loc(".936");
    std::wcout.imbue(loc);
    
    CharString cs1;
    CharString cs2;
    CharString cs3;
    CharString cs4;
    cs1 = L"律师事务所";
    cs2 = L"盲目";
    cs3 = L"啊";
    cs4 = L"啊啊";

    CharString result;
    CharString title;
    title = L"清流 |吴秀波《军师联盟》收益法院不予认可 或波及当代东方业绩对赌失败";
    result = L"(";
    CharString id;
    id = L"351";
    result.concat(id);
    result.concat(L',');
    result.concat(title);
    result.concat(L')');
    result.concat(L' ');
}

void Tester::testCharStringLink() {
    std::locale loc(".936");
    std::wcout.imbue(loc);

    CharString cs1;
    CharString cs2;
    CharString cs3;
    CharString cs4;
    cs1 = L"一";
    cs2 = L"二";
    cs3 = L"三";
    cs4 = L"四";

    CharStringLink csl1;

    
    for (int i = 0; i < 10; i++) {
        csl1.add(cs1);
        csl1.add(cs2);
        csl1.add(cs3);
        csl1.add(cs4);
    }
    csl1.slice(50);
    std::wcout << csl1 << std::endl;
    std::cout << csl1.length() << std::endl;
    /*
    for (int i = 0; i < 4; i++) {
        std::wcout << csl1.getItem(i) << std::endl;
    }
    std::cout << csl1.length() << std::endl;

    std::cout << csl1.remove(1) << std::endl;
    std::cout << csl1.remove(4) << std::endl;
    for (int i = 0; i < 3; i++) {
        std::wcout << csl1.getItem(i) << std::endl;
    }
    std::cout << csl1.length() << std::endl;

    std::cout << csl1.remove(cs1) << std::endl;
    std::cout << csl1.remove(cs2) << std::endl;
    for (int i = 0; i < 2; i++) {
        std::wcout << csl1.getItem(i) << std::endl;
    }
    std::cout << csl1.length() << std::endl;

    csl1.add(cs1);
    for (int i = 0; i < 3; i++) {
        std::wcout << csl1.getItem(i) << std::endl;
    }
    std::cout << csl1.length() << std::endl;
    std::cout << csl1.search(cs1) << std::endl;
    std::cout << csl1.search(cs2) << std::endl;
    std::cout << csl1.search(cs3) << std::endl;

    csl1.add(cs1);
    csl1.add(cs1);
    std::cout << csl1.length() << std::endl;
    std::wcout << csl1 << std::endl;
    std::cout << csl1.search(cs1) << std::endl;

    for (int i = 0; i < 100; i++) {
        csl1.add(cs1);
    }
    std::wcout << csl1 << std::endl;
    */

}

void Tester::testNewsInfo() {
    CharString title;
    title = L"标题";
    CharString time;
    time = L"2018-10-13 09:36:47";
    CharString source;
    source = L"来源";
    CharString content1;
    content1 = L"第一部分";
    CharString content2;
    content2 = L"第二部分";

    NewsInfo info;
    info.setTitle(title);
    info.appendContent(content1);
    info.appendContent(content2);

    std::wcout << info.getTitle() << std::endl;
    std::wcout << info.getTime() << std::endl;
    std::wcout << info.getSource() << std::endl;
    std::wcout << info.getContent() << std::endl;
}

void Tester::testExtractInfo() {
    extractInfoInAllPages();
}

void Tester::testInitDictionary() {
    CharStringHashTable hashTable = initDictionary();
    // CharStringHashTable hashTable;

    CharString test[10];
    test[0] = L"膜原妈";
    test[1] = L"哪知道";
    test[2] = L"层内干扰";
    test[3] = L"居世界领先水平";
    test[4] = L"故障诊断程序";
    test[5] = L"敌对势力";
    test[6] = L"敏于事慎于言";
    test[7] = L"救偏补弊";
    test[8] = L"程序优先级";
    test[9] = L"颞下颌关节功能紊乱综合征";

    for (int i = 0; i < 9; i++) {
        // hashTable.add(test[i]);
    }

    for (int i = 0; i < 10; i++) {
        std::cout << hashTable.find(test[i]) << std::endl;
    }


}

void Tester::testDivideWords() {
    CharStringHashTable hashTable = initDictionary();
    divideWordsInAllFiles(hashTable);
}

void Tester::testBalancedBinaryTree() {

    BalancedBinaryTree * tree = new BalancedBinaryTree;
    CharString words[10];
    words[0] = L"0";
    words[1] = L"1";
    words[2] = L"2";
    words[3] = L"3";
    words[4] = L"4";
    words[5] = L"5";
    words[6] = L"6";
    words[7] = L"7";
    words[8] = L"8";
    words[9] = L"9";
    
    CharString newwords[10];
    newwords[0] = L"a";
    newwords[1] = L"b";
    newwords[2] = L"c";
    newwords[3] = L"d";
    newwords[4] = L"e";
    newwords[5] = L"f";
    newwords[6] = L"g";
    newwords[7] = L"h";
    newwords[8] = L"i";
    newwords[9] = L"j";

    for (int i = 0;; i++) {
        for (int i = 0; i < 10; i++) {
            bool taller = false;
            BalancedBinaryTreeNode * p = nullptr;
            tree->insert(tree->getRoot(), p, words[i], taller);
        }
        for (int i = 0; i < 10; i++) {
            BalancedBinaryTreeNode * p = nullptr;
            tree->edit(tree->getRoot(), p, words[i], newwords[i]);
        }
        for (int i = 9; i >= 0; i--) {
            bool shorter = false;
            tree->remove(tree->getRoot(), nullptr, newwords[i], shorter);
        }
        if (i % 10000 == 0) {
            std::cout << i << std::endl;
        }
    }
    
}

void Tester::testDocIdTOTitle() {
    CharString * map = getDocIdToTitle();
    std::locale loc(".936");
    std::wcout.imbue(loc);
    for (int i = 0; i < 781; i++) {
        std::wcout << i << L'\t' << map[i] << std::endl;
    }
}
