#ifndef TESTER_H
#define TESTER_H

#include <iostream>

#include "Stack.h"
#include "CharString.h"
#include "CharStringLinkNode.h"
#include "CharStringLink.h"

class Tester {
public:
    static void testStack();
    static void testCharString();
    static void testCharStringLink();
private:
    explicit Tester();
};

#endif // !TESTER_H



