
#include "parser.h"
#include <cassert>
#include <iostream>

#ifdef RUN_PARSER_TESTS //check if RUN_PARSER_TESTS is defined, if so, all code between here and #endif is compiled
int main() { 
    using namespace gol;

    try {
        char a = convertCellChars('X', -1);
        char b = convertCellChars('O', -1);
        assert(a == '0' && b == '1');
    } catch (...) { // if err thrown, print err msg and exit w/ code 1
        std::cerr << "convertCellChars basic test failed\n";
        return 1;
    }

    std::cout << "All tests passed.\n";
    return 0;
}
#endif
