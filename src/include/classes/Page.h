#pragma once

#include "Typedefs.h"
#include "classes/Command.h"

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
