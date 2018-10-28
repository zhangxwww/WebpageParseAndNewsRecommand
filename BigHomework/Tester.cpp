#include "Tester.h"

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
    /*
    CharString cs;
    cs = L"һ������";
    std::wcout << cs << std::endl;

    CharString cs1;
    CharString cs2;
    cs1 = L"������";
    cs2 = cs1;
    cs1 = cs;
    std::wcout << cs1 << " " << cs1.length() << std::endl;
    std::wcout << cs2 << " " << cs2.length() << std::endl;
    cs1.concat(cs2);
    wchar_t w = L'��';
    cs1.concat(w);
    for (int i = 0; i < 20; i++) {
        cs1.concat(cs2);
    }
    cs2 = cs1;
    std::wcout << cs2 << " " << cs2.length() << std::endl;
    CharString cs3 = cs1.subString(2, 4);

    std::wcout << cs3 << " " << cs3.length() << std::endl;

    CharString cs4;
    cs4 = L"abcac";
    int * next = cs4.getNext();
    int len = cs4.length();
    for (int i = 0; i < len; i++) {
        std::wcout << i << " " << cs4[i] << " " << next[i] << std::endl;
    }

    std::wcout << cs1 << std::endl;
    std::wcout << cs3 << std::endl;
    std::wstring ws = L"����";
    CharString cs5;
    cs5 = L"Ĥԭ��";
    CharString cs6(cs5);
    std::wcout << cs1.indexOf(ws) << std::endl;
    std::wcout << cs1.indexOf(cs5) << std::endl;

    CharString cs7;
    cs7.concat(cs6);
    cs7.concat(cs6);
    std::wcout << cs7 << cs7.length() << std::endl;
    std::wcout << cs7.subString(5) << std::endl;
    */
    CharString cs8;
    cs8 = L"  ����    ";
    /*
    CharString cs9;
    cs9 = L"������";
    CharString cs10;
    cs10 = L"��";
    cs8 = cs9;
    std::wcout << cs8 << std::endl;
    cs8 = cs10;
    std::wcout << cs8 << std::endl;
    */
    std::wcout << cs8.trim() << std::endl;
}

void Tester::testCharStringLink() {
    std::locale loc(".936");
    std::wcout.imbue(loc);

    CharString cs1;
    CharString cs2;
    CharString cs3;
    CharString cs4;
    cs1 = L"һ";
    cs2 = L"��";
    cs3 = L"��";
    cs4 = L"��";

    CharStringLink csl1;

    csl1.add(cs1);
    csl1.add(cs2);
    csl1.add(cs3);
    csl1.add(cs4);
    csl1.remove(1);
    CharStringLinkNode * p = csl1.getHead()->getNext();
    CharString cs5;
    cs5 = p->getCharString();
    std::wcout << cs5 << std::endl;
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
    title = L"����";
    CharString time;
    time = L"2018-10-13 09:36:47";
    CharString source;
    source = L"��Դ";
    CharString content1;
    content1 = L"��һ����";
    CharString content2;
    content2 = L"�ڶ�����";

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
    extractInfo();
}

void Tester::testInitDictionary() {
    CharStringHashTable hashTable = initDictionary();
    // CharStringHashTable hashTable;

    CharString test[10];
    test[0] = L"Ĥԭ��";
    test[1] = L"��֪��";
    test[2] = L"���ڸ���";
    test[3] = L"����������ˮƽ";
    test[4] = L"������ϳ���";
    test[5] = L"�ж�����";
    test[6] = L"������������";
    test[7] = L"��ƫ����";
    test[8] = L"�������ȼ�";
    test[9] = L"����ؽڹ��������ۺ���";

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
