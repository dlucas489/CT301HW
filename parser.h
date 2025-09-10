#ifndef PARSER_H // "if not defined." header guard, avoids duplicate-definition errors
#define PARSER_H // find and replace tool - tells preprocesser to change code before compiler sees it

#include <string> //java "import" equivalences
#include <vector>
#include <stdexcept> // standard exception classes for err handling

namespace gol { // NAMESPACE is a box to put related code in - prevents naming conflicts. GOL = Game of Life


struct ParseResult {
    
    std::vector<std::string> grid2D;
    std::string grid1D;
    int width  = 0;
    int height = 0;
};

class ParserError : public std::runtime_error {
public:
    explicit ParserError(const std::string& msg, int lineIndex = -1)
        : std::runtime_error(msg), lineIndex_(lineIndex) {}

    int lineIndex() const noexcept { return lineIndex_; }

private:
    int lineIndex_; 
};

ParseResult parseFile(const std::string& filename);

char normalizeCellChar(char c, int lineIndex);

std::string stripSpacesValidateWidth(const std::string& line,
                                     int expectedWidth,
                                     int lineIndex);

} 

#endif 
