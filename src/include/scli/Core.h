/**
 * ==========================================================
 * @file        Core.h
 * @brief       SCLI Core Functions
 *
 * @author      thatgato
 * @date        2025-02-07
 * ==========================================================
 *
 * @details
 * The core functions of SCLI. Things like controlling which page to show, when
 * to flush the CLI, the main loop and registering top level pages all happen
 * here. This is the magical core of SCLI.
 *
 * ==========================================================
 */

#pragma once

#include "scli/classes/Page.h"
#include "types/general.h"

/* -------------------------------------------------------------------------- */
/*                 Main functions exposed through the SCLICore                */
/* -------------------------------------------------------------------------- */
namespace Core {

void MAIN(bool isFirstLoop);  // Main loop !! keep track of running main loops
                              // if someone calls it twice...

void EXEC_CMD(int cmdIdx);
void DISPLAY_PAGE();
void DISPLAY_PAGE(const Page& pPage);
void DISPLAY_CMDS(const Page& pPage);
void SET_FLAG(const str& flagName, bool val);
void REGISTER_TOP_LEVEL(uptr<Page>&& pPage);

Page* GET_CURRENT_PAGE();
Page* GET_LAST_PAGE();
str GET_VERSION();
bool GET_FLAG(str flagName);

}  // namespace Core
