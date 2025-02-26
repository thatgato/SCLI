
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

#include <exception>
#include <format>
#include <iostream>
#include <string>
#include <utility>

#include "scli/classes/Command.h"
#include "types/general.h"

/* -------------------------------------------------------------------------- */
/*                                Utils::Logger                               */
/* -------------------------------------------------------------------------- */

Utils::Logger::Logger(const str& fileName) : _identifier(fileName) {}

void Utils::Logger::Log(const str& msg) {
    // We default to LogLevel.Info in this overload
    str out = std::format("{}[{}] [{}]: {}{}", SStyle::white, _identifier,
                          "INFO", msg, SStyle::reset);

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
void Utils::Logger::Out(const str& msg, bool noNewline) {
    std::cout << msg << (noNewline ? "" : "\n");
}

str Utils::Logger::In() {
    Utils::Logger::Out(">> ", true);
    str res;
    std::getline(std::cin, res);
    return res;
}

Utils::Logger ULOGGER("Utils");

/* -------------------------------------------------------------------------- */
/*                                    Other                                   */
/* -------------------------------------------------------------------------- */

str Utils::GetPageDequeStr(std::deque<Page*> deq) {
    std::string result = "root";
    for (size_t i = 0; i < deq.size(); ++i) {
        result += deq[i]->getName();
        if (i != deq.size() - 1) {
            result += "/";
        }
    }
    result +=
        SStyle::reset;  // Reset the style so we don't fuck up other things
                        // being printed after this
    return result;
}

std::pair<bool, int> Utils::TryConvertStrToInt(const str& convert) {
    bool success = false;
    int conv = 0;
    try {
        conv = std::stoi(convert);
        success = true;
    } catch (std::exception& e) {
        ULOGGER.Log(e.what(), Logger::LogLevel::DEBUG_WARN);
    }
    return std::pair<bool, int>(success, conv);
}
std::pair<bool, double> Utils::TryConvertStrToDouble(const str& convert) {
    bool success = false;
    double conv = 0;
    try {
        conv = std::stod(convert);
        success = true;
    } catch (std::exception& e) {
        ULOGGER.Log(e.what(), Logger::LogLevel::DEBUG_WARN);
    }
    return std::pair<bool, double>(success, conv);
}

vec<str> Utils::SplitStrByDelimiter(str inp, char delim) {
    std::vector<std::string> result;
    std::istringstream sstream(inp);
    std::string token;

    while (std::getline(sstream, token, delim)) {
        result.push_back(token);
    }

    return result;
}

void Utils::DisplayCmdDataOnRun(const Command& cmd) {
    ULOGGER.Out(std::format(
        "{}Command: {}{}{}{}\n\n{}Command description: {}{}{}{}\n\n{}To "
        "exit the command context, type {}{}\"!e\"{}\n\n",
        SStyle::white, SStyle::reset, SStyle::orange, cmd.GetName(),
        SStyle::reset, SStyle::white, SStyle::reset, SStyle::Quick::note,
        cmd.GetHelpDesc(), SStyle::reset, SStyle::Quick::note, SStyle::reset,
        SStyle::white, SStyle::reset));
}

// void Utils::DisplayDetailedCommandData(Command& cmd) {
//     ULOGGER.Out(SStyle::Quick::note +
//                 std::format("Command: {}\n", cmd.GetName()));
//     ULOGGER.Out(SStyle::Quick::note +
//                 "Current page directory:" + SStyle::reset);
//     ULOGGER.Out(SStyle::Quick::note + Utils::GetPageStackDirectory(layer) +
//                 SStyle::reset + "\n");
// }

/* -------------------------------------------------------------------------- */
/*                                Utils::Clock                                */
/* -------------------------------------------------------------------------- */

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
str Utils::StrStyle::gray = "\033[1;30m";
str Utils::StrStyle::light_gray = "\033[0;37m";

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

str Utils::StrStyle::Quick::note =
    Utils::StrStyle::italic + Utils::StrStyle::gray;
str Utils::StrStyle::Quick::warn =
    Utils::StrStyle::orange + Utils::StrStyle::bold + Utils::StrStyle::italic;