#ifndef TESTER_H
#define TESTER_H

#include "Stack.h"
#include "CharString.h"
#include "CharStringLinkNode.h"
#include "CharStringLink.h"
#include "NewsInfo.h"
#include "ExtractInfo.h"
#include "InitDictionary.h"
#include "DivideWords.h"
#include "BalancedBinaryTree.h"

#include <iostream>

class Tester {
public:
    static void testStack();
    static void testCharString();
    static void testCharStringLink();
    static void testNewsInfo();
    static void testExtractInfo();
    static void testInitDictionary();
    static void testDivideWords();
    static void testBalancedBinaryTree();
private:
    explicit Tester() {};
};

#endif // !TESTER_H



