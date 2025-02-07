/**
 * ==========================================================
 * @file        Command.cpp
 * @brief       The Command class. Core functionality of SCLI!
 *
 * @author      thatgato
 * @date        2025-02-07
 * ==========================================================
 *
 * @details
 * The base command class. All SCLI commands should inherit from this!
 *
 * ==========================================================
 */

#include "scli/classes/Command.h"

Command::Command(const str& cName, const str& cDesc, const str& cHelpDesc)
    : name(cName), desc(cDesc), help_desc(cHelpDesc) {}

str Command::GetDesc() { return desc; }
str Command::GetName() { return name; }