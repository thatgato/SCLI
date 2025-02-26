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

#include "scli/Core.h"
#include "scli/PageBuilder.h"
#include "scli/Utils.h"

int main() {
    Utils::Logger Logger("main");

    // Utils::Logger::Out(
    //     "This is a test of the logging functions! Remove later..!:3");
    // Logger.Log("Test message! Am I working? I hope so...");
    // Logger.Log("Test message! Am I working? I hope so...",
    //            LogLevel::DEBUG_INFO);
    // Logger.Log("Test message! Am I working? I hope so...",
    //            LogLevel::DEBUG_WARN);
    // Logger.Log("Test message! Am I working? I hope so...",
    //            LogLevel::DEBUG_ERROR);
    // Logger.Log("Test message! Am I working? I hope so...", LogLevel::INFO);
    // Logger.Log("Test message! Am I working? I hope so...", LogLevel::WARN);
    // Logger.Log("Test message! Am I working? I hope so...", LogLevel::ERROR);
    Logger.Log("Calling page builder!");

    Builder::BEGIN();

    Core::MAIN(true);
    return 0;
}