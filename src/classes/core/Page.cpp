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

#include "scli/classes/Page.h"

#include "scli/Utils.h"

static Utils::Logger Logger("Core::Page");

Page::Page(const str& pageName, const str& descStr)
    : name(pageName), desc(descStr) {};

void Page::LinkChild(Page& pPage) {};
void Page::LinkParent(Page& pPage) {};

void Page::AddCommand(Command& pCommand) {};

str Page::getName() const { return name; }
str Page::getDesc() const { return desc; }

/**
 * @brief Whether this page functions as a command page. Command pages don't
 * contain child pages, only commands.
 *
 * @return true
 * @return false
 */
bool Page::isCommandPage() {
    if (child_commands.empty() && child_pages.empty())
        Logger.Log(
            "isCommandPage() -> This specific page has child commands, but "
            "also child pages! This should not happen! Please fix this "
            "immediately...",
            LogLevel::DEBUG_ERROR);
    return !child_commands.empty() && child_pages.empty();
};