#include <iostream>

#include "SCLICore.h"
#include "SCLIPageBuilder.h"
#include "classes/Page.h"

int main() {
    std::cout << "TEST" << std::endl;

    Page wow("AOIFJEUDIOKDLFH", " ASddf");

    std::cout << wow.getName();
    std::cin.get();

    Builder::BEGIN();

    Core::MAIN(true);
    return 0;
}