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
    cs = L"匯屈眉膨";
    std::wcout << cs << std::endl;

    CharString cs1;
    CharString cs2;
    cs1 = L"込込込";
    cs2 = cs1;
    cs1 = cs;
    std::wcout << cs1 << " " << cs1.length() << std::endl;
    std::wcout << cs2 << " " << cs2.length() << std::endl;
    cs1.concat(cs2);
    wchar_t w = L'亜';
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
    std::wstring ws = L"屈眉";
    CharString cs5;
    cs5 = L"弔圻第";
    CharString cs6(cs5);
    std::wcout << cs1.indexOf(ws) << std::endl;
    std::wcout << cs1.indexOf(cs5) << std::endl;

    CharString cs7;
    cs7.concat(cs6);
    cs7.concat(cs6);
    std::wcout << cs7 << cs7.length() << std::endl;
    std::wcout << cs7.subString(5) << std::endl;
    */
    int count = 0;
    CharString cs8;
    cs8 = L"込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込"
        "込込込込込込込込込込込込込込込込込込込込込込";
    CharString cs;
    cs = L"123";
    while (true) {
        cs8.indexOf(cs);
        count++;
        if (count % 10000 == 0) {
            std::cout << count << std::endl;
        }
    }
    /*
    CharString cs9;
    cs9 = L"込込込";
    CharString cs10;
    cs10 = L"込";
    cs8 = cs9;
    std::wcout << cs8 << std::endl;
    cs8 = cs10;
    std::wcout << cs8 << std::endl;
    */
    // std::wcout << cs8.trim() << std::endl;
}

void Tester::testCharStringLink() {
    std::locale loc(".936");
    std::wcout.imbue(loc);

    CharString cs1;
    CharString cs2;
    CharString cs3;
    CharString cs4;
    cs1 = L"匯";
    cs2 = L"屈";
    cs3 = L"眉";
    cs4 = L"膨";

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
    title = L"炎籾";
    CharString time;
    time = L"2018-10-13 09:36:47";
    CharString source;
    source = L"栖坿";
    CharString content1;
    content1 = L"及匯何蛍";
    CharString content2;
    content2 = L"及屈何蛍";

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
    test[0] = L"弔圻第";
    test[1] = L"陳岑祇";
    test[2] = L"蚊坪孤氾";
    test[3] = L"肖弊順糟枠邦峠";
    test[4] = L"絞嬾寶僅殻會";
    test[5] = L"黍斤米薦";
    test[6] = L"樗噐並風噐冱";
    test[7] = L"照陶温益";
    test[8] = L"殻會單枠雫";
    test[9] = L"鬥和鬆購准孔嬬良岱忝栽尢";

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
