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
    Tester::testCharStringLink();
    // Tester::testNewsInfo();
       
    // Tester::testAlgorithm();

    
    locale loc(".936");
    wcout.imbue(loc);
    int a = L'°¡';
    
    
    return 0;
}