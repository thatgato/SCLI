#include "classes/Command.h"

Command::Command(const str& cName, const str& cDesc, const str& cHelpDesc)
    : name(cName), desc(cDesc), help_desc(cHelpDesc) {}

str Command::GetDesc() { return desc; }
str Command::GetName() { return name; }