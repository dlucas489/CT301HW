#include "parser.h"
#include <fstream>
#include <sstream>
#include <cctype>

namespace gol {

static void parseHeader(std::istream& in, int& height, int& width) {
    height = 0; //iunitialize
    width  = 0;
    std::string line;
    int lineIndex = 0;
    while (std::getline(in, line)) {
        bool nonblank = false;
        for (char c : line) {
            if (!std::isspace(static_cast<unsigned char>(c))) { nonblank = true; break; }
        }
        if (!nonblank) { ++lineIndex; continue; }
        std::istringstream iss(line);
        int h, w;
        if (!(iss >> h) || !(iss >> w)) {
            throw ParserError("Invalid or missing header", lineIndex);
        }
        std::string extra;
        if (iss >> extra) {
            throw ParserError("Invalid or missing header", lineIndex);
        }
        if (h <= 0 || w <= 0) {
            throw ParserError("Invalid or missing header", lineIndex);
        }
        height = h;
        width = w;
        return;
    }
    throw ParserError("Invalid or missing header", lineIndex);
}

char convertCellChars(char c, int lineIndex) {
    if (c == 'X') return '0';
    if (c == 'O') return '1';
   
    throw ParserError("Invalid character", lineIndex);
}

std::string whitespaceRemover(const std::string& line,
                                     int expectedWidth,
                                     int lineIndex) {
    std::string out;
    out.reserve(line.size());
    for (char c : line) {
        if (std::isspace(static_cast<unsigned char>(c))) continue;

        out.push_back(convertCellChars(c, lineIndex));
    }
    if (expectedWidth >= 0 && static_cast<int>(out.size()) != expectedWidth) {
        throw ParserError("Invalid row length", lineIndex);
    }
    return out;
}

ParseResult parseFile(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin) {
        throw ParserError("File not found: " + filename, -1);
    }

    ParseResult result;

    parseHeader(fin, result.height, result.width);

    return result;
}

}
