#include "SCLIUtils.h"

#include <iostream>

#include "Typedefs.h"

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

str Utils::GetPageStackDirectory(std::stack<str> stack) {
    std::stack<str> temp;
    while (!stack.empty()) {
        temp.push(stack.top());
        stack.pop();
    }

    str path;
    while (!temp.empty()) {
        path += temp.top();
        temp.pop();
        if (!temp.empty()) path += "/";
    }

    return path;
}

void Utils::Clock::START() { start = high_res_clock::now(); }

duration_t<double, std::milli> Utils::Clock::END() {
    return high_res_clock::now() - start;
}

/* -------------------------------------------------------------------------- */
/*                               StrStyle things                              */
/* -------------------------------------------------------------------------- */

str Utils::StrStyle::orange = "\033[91m";
str Utils::StrStyle::red = "\033[31m";
str Utils::StrStyle::green = "\033[32m";
str Utils::StrStyle::yellow = "\033[33m";
str Utils::StrStyle::cyan = "\033[36m";
str Utils::StrStyle::white = "\033[37m";

str Utils::StrStyle::on_red = "\033[41m";
str Utils::StrStyle::on_green = "\033[42m";
str Utils::StrStyle::on_yellow = "\033[43m";
str Utils::StrStyle::on_white = "\033[47m";

str Utils::StrStyle::bold = "\033[1m";
str Utils::StrStyle::dark = "\033[2m";
str Utils::StrStyle::italic = "\033[3m";
str Utils::StrStyle::underline = "\033[4m";
str Utils::StrStyle::blink = "\033[5m";

str Utils::StrStyle::reset = "\033[00m";
