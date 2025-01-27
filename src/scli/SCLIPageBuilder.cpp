#include "SCLIPageBuilder.h"

#include <iostream>
#include <memory>

#include "SCLICore.h"
#include "classes/Page.h"

void Builder::BEGIN() {
    std::cout << "Thingying" << std::endl;
    uptr<Page> toplevel_test = std::make_unique<Page>("AAAA1", "bbb");

    Core::REGISTER_TOP_LEVEL(toplevel_test);
}
