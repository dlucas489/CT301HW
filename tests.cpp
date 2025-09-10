
#include "parser.h"
#include <cassert>
#include <iostream>

#ifdef RUN_PARSER_TESTS
int main() {
    using namespace gol;

    try {
        char a = normalizeCellChar('X', 5);
        char b = normalizeCellChar('O', 5);
        assert(a == '0' && b == '1');
    } catch (...) {
        std::cerr << "normalizeCellChar basic test failed\n";
        return 1;
    }

    std::cout << "All tests passed.\n";
    return 0;
}
#endif
