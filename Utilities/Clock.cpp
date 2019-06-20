#include "../Header_Files/Clock.h"

SpiderLib::Utilities::Clock::Clock() {}

SpiderLib::Utilities::Clock::~Clock()
{
    std::cout << "Deleting clock." << std::endl;
}

namespace SpiderLib::Utilities
{
    std::ostream& operator<<(std::ostream& os, SpiderLib::Utilities::Clock& clock)
    {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        std::time_t t;
        t = std::chrono::system_clock::to_time_t(now);
        os << std::ctime(&t);
        return os;
    }
}


