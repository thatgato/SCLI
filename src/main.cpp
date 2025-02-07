/**
 * ==========================================================
 * @file        main.cpp
 * @brief       Main entry point! All paths lead to here...
 *
 * @author      thatgato
 * @date        2025-02-07
 * ==========================================================
 *
 * @details
 * Its just the main entry point. What did you expect? Not much is done here, we
 * instantly jump to scli/Core.cpp from here... This is a place for pre-startup
 * things.
 *
 * ==========================================================
 */

#include <iostream>

#include "scli/Core.h"
#include "scli/PageBuilder.h"
#include "scli/Utils.h"

int main() {
    Utils::Log("TEST");

    str ass;
    std::getline(std::cin, ass);

    Builder::BEGIN();

    Core::MAIN(true);
    return 0;
}