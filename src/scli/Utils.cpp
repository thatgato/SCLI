
/**
 * ==========================================================
 * @file        Utils.h
 * @brief       Handles all SCLI Utility functionality, such as StrStyles and
 * the Clock class for benchmarking.
 *
 * @author      thatgato
 * @date        2025-02-07
 * ==========================================================
 *
 * @details
 * Any SCLI related utility functions and classes should be defined here and in
 * src/scli/Utils.cpp
 *
 * ==========================================================
 */

#include "scli/Utils.h"

#include <format>
#include <iostream>

#include "types/general.h"

/* -------------------------------------------------------------------------- */
/*                                Utils::Logger                               */
/* -------------------------------------------------------------------------- */

Utils::Logger::Logger(const str& fileName) : _identifier(fileName) {}

void Utils::Logger::Log(const str& msg) {
    // We default to LogLevel.Info in this overload
    str out = std::format("{}{}[{}] [{}]: {}{}", SStyle::italic, SStyle::white,
                          _identifier, "INFO", msg, SStyle::reset);

    std::cout << out << "\n";
}

// Expanded overload, with different log levels
// TODO: Make this print messages marked with debug type log levels only when
// debugging is defined..!
void Utils::Logger::Log(const str& msg, LogLevel level) {
    str logTypeStr;
    str beginningStyleStr;
    // Set the beginning style format and the log type for formatting later

    // BUG: For some reason SStyle::bold does not work as of writing this
    // function. Atleast, I don't see a difference between bold and non-bold
    // text in the command prompt or powershell...
    switch (level) {
        case LogLevel::DEBUG_INFO:
            logTypeStr = "DEBUG-INFO";
            beginningStyleStr = SStyle::white;
            break;
        case LogLevel::DEBUG_WARN:
            logTypeStr = "DEBUG-WARN";
            beginningStyleStr = SStyle::bold + SStyle::orange;
            break;
        case LogLevel::DEBUG_ERROR:
            logTypeStr = "DEBUG-ERROR";
            beginningStyleStr = SStyle::bold + SStyle::bright_red;
            break;
        case LogLevel::INFO:
            logTypeStr = "INFO";
            beginningStyleStr = SStyle::white;
            break;
        case LogLevel::WARN:
            logTypeStr = "WARN";
            beginningStyleStr = SStyle::bold + SStyle::orange;
            break;
        case LogLevel::ERROR:
            logTypeStr = "ERROR";
            beginningStyleStr = SStyle::bold + SStyle::bright_red;
            break;
    }

    str out = std::format("{}[{}] [{}]: {}{}", beginningStyleStr, _identifier,
                          logTypeStr, msg, SStyle::reset);

    std::cout << out << "\n";
}

void Utils::Logger::Out(const str& msg) { std::cout << msg << "\n"; }

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

str Utils::StrStyle::orange = "\033[38;5;214m";
str Utils::StrStyle::red = "\033[31m";
str Utils::StrStyle::bright_red = "\033[38;5;196m";
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
