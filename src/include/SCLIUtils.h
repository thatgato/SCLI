#pragma once
#include "Typedefs.h"

class Utils {
   public:
    Utils() = delete;

    static void Log(const str& msg);
    static void DLog(const str& msg);
};