/**
 * ==========================================================
 * @file        PageBuilder.h
 * @brief       Builds and registers the pages using scli/Core.h
 *
 * @author      thatgato
 * @date        2025-02-07
 * ==========================================================
 *
 * @details
 * Just a file that contains the definitions of every single page and command in
 * SCLI. This file registers pages and links them together along with commands.
 *
 * ==========================================================
 */

#include "scli/PageBuilder.h"

#include <memory>
#include <thread>

#include "scli/Core.h"
#include "scli/Utils.h"
#include "scli/classes/Page.h"

Utils::Logger Logger("PageBuilder");

void Builder::BEGIN() {
    Logger.Log("Building commands and pages...");

    Utils::Clock clock;
    clock.START();

    sptr<Page> cogeo = std::make_shared<Page>(
        "Coordinate Geometry",
        "Contains categories that are related to coordinate geometry.");

    uptr<Page> vectors =
        std::make_unique<Page>("Vectors", "THIS IS TESTING, Do later!!");

    cogeo->LinkChild(vectors);
    Core::REGISTER_TOP_LEVEL(cogeo);

    auto dur = clock.END();
    Logger.Log(
        std::format("Done! Building pages and commands took approximately "
                    "{:.4f}ms! Starting in a second...",
                    dur.count()));

    std::this_thread::sleep_for(std::chrono::seconds(2));
}
