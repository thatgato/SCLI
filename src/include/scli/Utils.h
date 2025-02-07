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
#include <stack>

#include "types/chrono.h"
#include "types/general.h"

class Utils {
   public:
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

    static void Log(const str& msg);
    static void DLog(const str& msg);

    static str GetPageStackDirectory(std::stack<str> stack);
};