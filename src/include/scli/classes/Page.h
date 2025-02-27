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

#include "scli/classes/Command.h"
#include "types/general.h"

class Page {
   private:
    str name;
    str desc;

    vec<uptr<Page>> child_pages;
    Page* parent_page;
    vec<uptr<Command>> child_commands;

   public:
    Page(const str& pageName, const str& descStr);

    void LinkChild(uptr<Page>&& pPage);
    void LinkParent(Page& pPage);

    void AddCommand(uptr<Command>&& pCommand);

    str getName() const;
    str getDesc() const;
    vec<uptr<Page>>& getChildPages();
    Page* getParentPage();
    vec<uptr<Command>>& getChildCommands();

    bool isCommandPage();
};
