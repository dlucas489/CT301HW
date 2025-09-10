#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <stdexcept>

namespace gol {

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
