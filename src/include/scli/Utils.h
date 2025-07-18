// This file is part of SCLI
// Copyright (c) 2025 @thatgato
// Licensed under the GNU General Public License v3.0
// See LICENSE file for more details.

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
#include <deque>

#include "scli/classes/Command.h"
#include "scli/classes/Page.h"

#undef ERROR  // Weird wingdi.h shit? This conflicts with LogLevel::ERROR :3

#include "types/chrono.h"
#include "types/general.h"

class Utils {
    public:
        class Logger {
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

                Logger(const str &fileName);

                void Log(const str &msg); // Defaults to LogLevel.Info
                void Log(const str &msg, LogLevel level);

                static void Out(
                    const str &msg); // basically a shorthand for std::cout << msg
                // << "\n";
                static void Out(const str &msg, bool noNewLine);

                static str In();
        };

        class Clock {
            // Handles simple "x amount of time has passed" benchmarking
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
                static str gray;
                static str light_gray;

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

                class Quick {
                    public:
                        static str note;
                        static str warn;
                };
        };

        Utils() = delete;

        static str GetPageDequeStr(std::deque<Page *> deq);

        //static void DisplayDetailedCommandData(Command& cmd);
        // Tries to convert the provided string into an integer. Returns (true, int)
        // if it succeeded, otherwise (false, 0)
        static std::pair<bool, int> TryConvertStrToInt(const str &convert);

        static std::pair<bool, double> TryConvertStrToDouble(const str &convert);

        static vec<str> SplitStrByDelimiter(str inp, char delim);

        static void DisplayCmdDataOnRun(const Command &cmd);

        template<typename T>
        static str RemoveTrailingZeroesFromNum(T source) {
            std::string formatted = std::format("{:.4f}", source);

            formatted.erase(formatted.find_last_not_of('0') + 1, std::string::npos);
            if (formatted.back() == '.') { formatted.pop_back(); }

            return formatted;
        };
};

// Utils specific type definitions, for easier typing
using SStyle   = Utils::StrStyle;
using LogLevel = Utils::Logger::LogLevel;
