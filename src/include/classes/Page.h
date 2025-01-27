#pragma once

#include "Typedefs.h"

class Page {
   private:
    str name;
    str desc;
    vec<uptr<Page>> child_pages;
    wptr<Page> parent_page;

   public:
    Page(const str& pageName, const str& descStr)
        : name(pageName), desc(descStr) {}

    void LinkChild(Page& cPage);
    void LinkParent(Page& pPage);

    str getName() const;
    str getDesc() const;
};
