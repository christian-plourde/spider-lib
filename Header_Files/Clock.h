#include <iostream>
#include <chrono>
#include <ctime>

namespace SpiderLib::Utilities
{
    #ifndef SPIDERLIB_CLOCK_H
    #define SPIDERLIB_CLOCK_H

    class Clock
    {
        public:
            Clock();
            ~Clock();
            friend std::ostream& operator<<(std::ostream& os, SpiderLib::Utilities::Clock& clock);
    };

    #endif
}

