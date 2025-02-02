#include "SCLIUtils.h"

#include <iostream>

void Utils::Log(const str& msg) { std::cout << msg << "\n"; };

void Utils::DLog(const str& msg) {
#ifdef DEBUG_LOGGING
    std::cout << msg << std::endl;
#else
    if (true) {
        std::cout << msg << std::endl;
    }
#endif
}