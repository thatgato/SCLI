#pragma once

#include "Typedefs.h"

namespace SCLI {
  class Page {
    private:
      str name;
      vec<uptr<Page>> child_pages;
      Page* parent_page;


    public:
      Page(const str &pageName) : name(pageName) {}

      void LinkChild(Page& cPage);
      void LinkParent(Page& pPage);

      str getName() const;
  };
}  // namespace SCLI