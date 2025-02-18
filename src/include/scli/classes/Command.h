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

#pragma once
#include "types/general.h"

enum ECommandResult { SUCCESS, FAIL };

class Command {
   protected:
    str name;
    str desc;
    str help_desc;

   public:
    Command(const str& cName, const str& cDesc, const str& cHelpDesc);

    virtual ~Command() = default;
    virtual ECommandResult Run(bool isFirst) = 0;

    str GetName() const;
    str GetDesc() const;
    str GetHelpDesc() const;
};