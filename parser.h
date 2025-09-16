#ifndef PARSER_H // "if not defined." header guard, avoids duplicate-definition errors
#define PARSER_H // find and replace tool - tells preprocesser to change code before compiler sees it

#include <string> //java "import" equivalences
#include <vector> 
#include <stdexcept> // standard exception classes for err handling

namespace gol { // NAMESPACE is a box to put related code in - prevents naming conflicts. GOL = Game of Life

struct ParseResult { // composite data type allowing uncommon variable grouping (public by default). 
    //describes successful parse output
    
    std::string grid1D; // for 1 line version of grid
    std::vector<std::string> grid2D; //dynamic array for 2d version of grid
    int width  = 0; 
    int height = 0;
};

class ParserError : public std::runtime_error { // something went wrong while processing input file
public:
    explicit ParserError(const std::string& msg, int lineIndex = -1) // -1 means file not found (no specific line)
        : std::runtime_error(msg), lineIndex_(lineIndex) {} // fwd msg to base class

    int lineIndex() const noexcept { return lineIndex_; } //noexcept promises err never throws - safe to call

private:
    int lineIndex_; 
};

ParseResult parseFile(const std::string& filename); //declares main parsing API. Given filoe path, returns ParseResult or ParserError. Main calls this

char convertCellChars(char c, int lineIndex); // converts X to 0 and O to 1

std::string whitespaceRemover(const std::string& line, int expectedWidth, int lineIndex); // rm whitespace

} 

#endif 
