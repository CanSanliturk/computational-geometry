#ifndef _LOGGING_H
#define _LOGGING_H

#include <string>
#include <iostream>
#include <sstream>
#include <chrono>

namespace utilities
{
    template<typename... Args>
    inline void logger(const Args&... args) {
        std::ostringstream oss;
        (oss << ... << args);
        std::cout << oss.str() << std::endl;
    }

} // namespace utilities




#endif

