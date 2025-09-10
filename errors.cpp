#include "errors.h"
#include <iostream>
#include <sstream>

namespace errors {

int reportAndReturn(const std::string& message, int lineIndex) {
    // Line numbers shown to the user should be 1-based.
    if (lineIndex >= 0) {
        int displayLine = lineIndex + 1;
        std::cerr << "Error: " << message << " on line " << displayLine << '\n';
        std::cerr << "Return Code: " << (displayLine + 1 - 1) << '\n'; // same as displayLine
        return displayLine; // exit code = lineIndex + 1
    } else {
        std::cerr << "Error: " << message << '\n';
        std::cerr << "Return Code: 1\n";
        return 1;
    }
}

int reportFileNotFound(const std::string& filename) {
    return reportAndReturn("File not found: " + filename, -1);
}

std::string formatMessage(const std::string& message, int lineIndex) {
    std::ostringstream oss;
    if (lineIndex >= 0) {
        oss << "Error: " << message << " on line " << (lineIndex + 1);
    } else {
        oss << "Error: " << message;
    }
    return oss.str();
}

} // namespace errors
