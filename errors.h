
#ifndef ERRORS_H //if not defined - guard, contents only included once per compilation
#define ERRORS_H 

#include <string>

namespace errors { 

    int reportAndReturn(const std::string& message, int lineIndex); // called from main

    int reportFileNotFound(const std::string& filename); // returns code 1

    std::string formatMessage(const std::string& message, int lineIndex); // returns err txt w/o printing

} //namespace errors

#endif //closes header guard