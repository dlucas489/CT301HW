#include "errors.h"
#include <iostream>
#include <sstream> // formatted msg string in memory

namespace errors { 

int reportAndReturn(const std::string& message, int lineIndex) { //main err printer and return code helper definition
    
    if (lineIndex >= 0) {
        int displayLine = lineIndex + 1; // Line nums shown to user are 1-based
        std::cerr << "Error: " << message << " on line " << displayLine << '\n'; //print err msg
        std::cerr << "Return Code: " << displayLine +1 << '\n'; 
        return displayLine; // returns exit code to caller (main)
    } else { // error but no line
        std::cerr << "Error: " << message << '\n';
        std::cerr << "Return Code: 1\n"; // generic errs use code 1
        return 1;
    }
}

int reportFileNotFound(const std::string& filename) { // convenience wrapper for missing files
    return reportAndReturn("File not found: " + filename, -1); //passes in -1 to reuse logic
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

}
