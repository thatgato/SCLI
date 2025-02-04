#pragma once
#include "Typedefs.h"

enum ECommandResult { SUCCESS, FAIL };

class Command {
   protected:
    str name;
    str desc;
    str help_desc;

   public:
    Command(const str& cName, const str& cDesc, const str& cHelpDesc);

    virtual ~Command() = default;
    virtual ECommandResult Run() = 0;

    str GetName();
    str GetDesc();
};