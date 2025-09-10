
#ifndef ERRORS_H
#define ERRORS_H

#include <string>

namespace errors {

    int reportAndReturn(const std::string& message, int lineIndex);

    int reportFileNotFound(const std::string& filename);

    std::string formatMessage(const std::string& message, int lineIndex);

} //namespace errors

#endif 