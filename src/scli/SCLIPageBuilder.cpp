#include "SCLIPageBuilder.h"

#include <iostream>
#include <memory>

#include "SCLICore.h"
#include "classes/Page.h"

void Builder::BEGIN() {
    std::cout << "Thingying" << std::endl;
    uptr<Page> cogeo = std::make_unique<Page>(
        "Coordinate Geometry",
        "Contains categories that are related to coordinate geometry.");

    Core::REGISTER_TOP_LEVEL(cogeo);
}
