#include "parser.h"
#include "errors.h"
#include <iostream>

int main(int argc, char* argv[]) {

    if (argc < 2) { 
  
        return errors::reportAndReturn("No input file provided", -1);
    }

    const std::string filename = argv[1]; //first user supplied arg is file path to parse

    try { //anything throwing parsererror handled below
   
        gol::ParseResult result = gol::parseFile(filename); //core parsing/validation function!

        std::cout << result.grid1D << '\n'; 
        for (const auto& row : result.grid2D) { //current row of grid by reference
            std::cout << row << '\n'; 
        }

        return 0; //success exit code

    } catch (const gol::ParserError& e) { // catch any errors signalled by ParserError
       
        return errors::reportAndReturn(e.what(), e.lineIndex());

    } catch (const std::exception& e) {
       
        return errors::reportAndReturn(std::string("Unexpected error: ") + e.what(), -1);
    }
}

