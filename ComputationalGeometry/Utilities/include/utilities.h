#ifndef _UTILITIES_H
#define _UTILITIES_H

#include <string>
#include <iostream>
#include <sstream>
#include <chrono>

namespace utilities
{
    // Logger function using variadic templates
    template<typename... Args>
    void logger(const Args&... args) {
        std::ostringstream oss;
        (oss << ... << args);
        std::cout << oss.str() << std::endl;
    }

    class timer {

    public:

        timer();
        timer(const timer&) = delete;
        timer(timer&&) = delete;
        ~timer() = default;

        void tick();
        void tock();

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    };

} // namespace utilities




#endif

