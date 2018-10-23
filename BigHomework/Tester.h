#ifndef TESTER_H
#define TESTER_H

#include <iostream>

#include "Stack.h"
#include "CharString.h"
#include "CharStringLinkNode.h"
#include "CharStringLink.h"
#include "NewsInfo.h"
#include "Algorithm.h"

class Tester {
public:
    static void testStack();
    static void testCharString();
    static void testCharStringLink();
    static void testNewsInfo();
    static void testAlgorithm();
private:
    explicit Tester() {};
};

#endif // !TESTER_H



