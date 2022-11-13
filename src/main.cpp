#include <iostream>
#include "testDoxygen.h"

/** \file */
int main() {
    std::cout << "Hello, sure World!" << std::endl;
    testDoxygen a;
    a.testDoxy();
    return 0;
}
