#include "Tester.h"

void Tester::testStack()
{
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

void Tester::testCharString()
{
    CharString cs;
    cs = L"一二三四";
    // std::wcout << cs << std::endl;

    CharString cs1;
    CharString cs2;
    cs1 = L"哈哈哈";
    cs2 = cs1;
    cs1 = cs;
    // std::wcout << cs1 << " " << cs1.length() << std::endl;
    // std::wcout << cs2 << " " << cs2.length() << std::endl;
    cs1.concat(cs2);
    wchar_t w = L'啊';
    cs1.concat(w);
    for (int i = 0; i < 20; i++) {
        cs1.concat(cs2);
    }
    // cs2 = cs1;
    // std::wcout << cs2 << " " << cs2.length() << std::endl;
    CharString cs3 = cs1.subString(2, 4);
    
    // std::wcout << cs3 << " " << cs3.length() << std::endl;
    /*
    CharString cs4;
    cs4 = L"abcac";
    int * next = cs4.getNext();
    int len = cs4.length();
    for (int i = 0; i < len; i++) {
        std::wcout << i << " " << cs4[i] << " " << next[i] << std::endl;
    }
    */
    // std::wcout <<cs1[]
    std::wcout << cs1 << std::endl;
    // std::wcout << cs3 << std::endl;
    std::wstring ws = L"二三";
    CharString cs5;
    cs5 = L"膜原妈";
    std::wcout << cs1.indexOf(ws) << std::endl;
    std::wcout << cs1.indexOf(cs5) << std::endl;
}

void Tester::testCharStringLink()
{
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

    csl1.add(cs1);
    csl1.add(cs2);
    csl1.add(cs3);
    csl1.add(cs4);
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
}


Tester::Tester()
{
}



