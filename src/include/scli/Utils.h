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

#pragma once
#undef ERROR  // Weird wingdi.h shit? This conflicts with LogLevel::ERROR :3
#include <stack>

#include "types/chrono.h"
#include "types/general.h"

class Utils {
   public:
    class Logger {
       private:
        str _identifier;

       public:
        enum class LogLevel {
            DEBUG_INFO,
            DEBUG_WARN,
            DEBUG_ERROR,
            INFO,
            WARN,
            ERROR,
        };
        Logger(const str& fileName);
        void Log(const str& msg);  // Defaults to LogLevel.Info
        void Log(const str& msg, LogLevel level);
        static void Out(
            const str& msg);  // basically a shorthand for std::cout << msg
                              // << "\n";
    };

    class Clock {  // Handles simple "x amount of time has passed" benchmarking
       private:
        time_point_t<high_res_clock> start;

       public:
        void START();
        duration_t<double, std::milli> END();
    };

    class StrStyle {
       public:
        static str orange;
        static str red;
        static str bright_red;
        static str green;
        static str yellow;
        static str cyan;
        static str white;

        static str on_red;
        static str on_green;
        static str on_yellow;
        static str on_white;

        static str bold;
        static str dark;
        static str italic;
        static str underline;
        static str blink;

        static str reset;
    };

    Utils() = delete;

    static str GetPageStackDirectory(std::stack<str> stack);
};

// Utils specific type definitions, for easier typing
using SStyle = Utils::StrStyle;
using LogLevel = Utils::Logger::LogLevel;