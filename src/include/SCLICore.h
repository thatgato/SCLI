#pragma once

#include "Typedefs.h"
#include "classes/Page.h"

/* -------------------------------------------------------------------------- */
/*                 Main functions exposed through the SCLICore                */
/* -------------------------------------------------------------------------- */
namespace Core {

void MAIN();  // Main loop !! keep track of running main loops if someone calls it twice...

void PROCESS_CMD(str cmdInputString);
void DISPLAY_PAGE(Page& pPage);

Page* GET_CURRENT_PAGE();
Page* GET_LAST_PAGE();
str GET_VERSION();

}  // namespace Core