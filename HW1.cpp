#include "parser.h"
#include "errors.h"
#include <iostream>

int main(int argc, char* argv[]) {

    if (argc < 2) {
  
        return errors::reportAndReturn("No input file provided", -1);
    }

    const std::string filename = argv[1];

    try {
   
        gol::ParseResult result = gol::parseFile(filename);

        std::cout << result.grid1D << '\n';
        for (const auto& row : result.grid2D) {
            std::cout << row << '\n';
        }

        return 0;
    } catch (const gol::ParserError& e) {
       
        return errors::reportAndReturn(e.what(), e.lineIndex());
    } catch (const std::exception& e) {
       
        return errors::reportAndReturn(std::string("Unexpected error: ") + e.what(), -1);
    }
}

