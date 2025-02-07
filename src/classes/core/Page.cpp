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

#include "classes/core/Page.h"

Page::Page(const str& pageName, const str& descStr)
    : name(pageName), desc(descStr) {};
str Page::getName() const { return name; }
str Page::getDesc() const { return desc; }