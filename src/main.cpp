

#include <iostream>

#include "SCLICore.h"
#include "SCLIPageBuilder.h"
#include "SCLIUtils.h"
#include "classes/Page.h"

int main() {
    Utils::Log("TEST");

    Page wow("AOIFJEUDIOKDLFH", " ASddf");

    Utils::Log(wow.getName());
    str ass;
    std::getline(std::cin, ass);

    Builder::BEGIN();

    Core::MAIN(true);
    return 0;
}