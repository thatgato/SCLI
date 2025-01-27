#pragma once

#include "Typedefs.h"
#include "classes/Page.h"

/* -------------------------------------------------------------------------- */
/*                 Main functions exposed through the SCLICore                */
/* -------------------------------------------------------------------------- */
namespace Core {

void MAIN(bool isFirstLoop);  // Main loop !! keep track of running main loops
                              // if someone calls it twice...

void PROCESS_CMD(str cmdInputString);
void DISPLAY_PAGE();
void DISPLAY_PAGE(const sptr<Page>& pPage);
void SET_FLAG(const str& flagName, bool val);
void REGISTER_TOP_LEVEL(uptr<Page>& pPage);

sptr<Page> GET_CURRENT_PAGE();
sptr<Page> GET_LAST_PAGE();
str GET_VERSION();
void DLog(str msg);
void Log(str msg);
bool GET_FLAG(str flagName);

}  // namespace Core
