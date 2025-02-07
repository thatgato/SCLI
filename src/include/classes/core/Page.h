/**
 * ==========================================================
 * @file        Page.cpp
 * @brief       The Page class. Core functionality of SCLI, too!
 *
 * @author      thatgato
 * @date        2025-02-07
 * ==========================================================
 *
 * @details
 * Base Page class. Pages in SCLI are defined through the use of this class.
 *
 * ==========================================================
 */

#pragma once

#include "classes/core/Command.h"
#include "types/general.h"

class Page {
   private:
    str name;
    str desc;

    vec<uptr<Page>> child_pages;
    wptr<Page> parent_page;
    vec<uptr<Command>> child_commands;

   public:
    Page(const str& pageName, const str& descStr);

    void LinkChild(Page& cPage);
    void LinkParent(Page& pPage);

    void AddCommand(Command& pCommand);

    str getName() const;
    str getDesc() const;
};
