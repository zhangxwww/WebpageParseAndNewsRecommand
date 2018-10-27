#include "Stack.h"
#include "CharString.h"
#include "CharStringLinkNode.h"
#include "CharStringLink.h"
#include "Tester.h"

#include <iostream>

using namespace std;

int main() {

    // Tester::testStack();
    // Tester::testCharString();
    // Tester::testCharStringLink();
    // Tester::testNewsInfo();
       
    // Tester::testExtractInfo();
    // Tester::testInitDictionary();
    
    locale loc(".936");
    wcout.imbue(loc);
    int a = L'°¡';
    wchar_t b = 0x4e00;
    wchar_t c = 0x9fa5;
    wcout << b << endl;
    wcout << c << endl;
    // cout << (L'¹þ' > 0x4e00) << endl;

    return 0;
}