#include <iostream>

#include "SCLICore.h"
#include "SCLIPageBuilder.h"
#include "SCLIUtils.h"
#include "classes/Page.h"

int main() {
    std::cout << "TEST" << std::endl;

    Page wow("AOIFJEUDIOKDLFH", " ASddf");

    std::cout << wow.getName();
    std::cin.get();

    Builder::BEGIN();

    // for testing purposes; remove later
    auto* a = new Commands::CoGeo::Vectors::CVecLen();
    Core::MAIN(true);
    return 0;
}