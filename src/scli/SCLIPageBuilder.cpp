#include "SCLIPageBuilder.h"

#include <chrono>
#include <memory>
#include <thread>

#include "SCLICore.h"
#include "SCLIUtils.h"
#include "classes/Page.h"

void Builder::BEGIN() {
    Utils::Log("Building commands and pages...");

    Utils::Clock clock;
    clock.START();

    uptr<Page> cogeo = std::make_unique<Page>(
        "Coordinate Geometry",
        "Contains categories that are related to coordinate geometry.");

    Core::REGISTER_TOP_LEVEL(cogeo);

    auto dur = clock.END();
    Utils::Log(
        std::format("Done! Building pages and commands took approximately "
                    "{:.4f}ms! Starting in a second...",
                    dur.count()));

    std::this_thread::sleep_for(std::chrono::seconds(1));
}
