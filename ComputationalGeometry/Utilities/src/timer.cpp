#include "timer.hpp"

namespace utilities {

    // Timer class implementation
    timer::timer() : start_time(std::chrono::high_resolution_clock::now())
    {

    }

    void timer::tick() {
        start_time = std::chrono::high_resolution_clock::now();
    }

    void timer::tock() {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        long minutes = std::chrono::duration_cast<std::chrono::minutes>(duration).count();
        long seconds = std::chrono::duration_cast<std::chrono::seconds>(duration).count() % 60;
        long milliseconds = duration.count() % 1000;

        logger("Elapsed time: ", minutes, " minutes, ", seconds, " seconds, ", milliseconds, " milliseconds.");
    }
}
