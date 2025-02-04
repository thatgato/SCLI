

#include <iostream>

#include "SCLICore.h"
#include "SCLIPageBuilder.h"
#include "SCLIUtils.h"

int main() {
    Utils::Log("TEST");

    str ass;
    std::getline(std::cin, ass);

    Builder::BEGIN();

    Core::MAIN(true);
    return 0;
}