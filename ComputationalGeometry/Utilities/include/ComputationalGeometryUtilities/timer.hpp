#ifndef _TIMER_H
#define _TIMER_H

#include "logging.hpp"

#include <chrono>

namespace computationalgeometry::utilities
{
    class timer {

    public:

        timer();
        timer(const timer&) = delete;
        timer(timer&&) = delete;
        ~timer() = default;

        void tick() const;
        void tock() const;

    private:
        mutable std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    };

} // namespace utilities




#endif

