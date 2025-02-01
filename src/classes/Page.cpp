#include "classes/Page.h"

Page::Page(const str& pageName, const str& descStr)
    : name(pageName), desc(descStr) {};
str Page::getName() const { return name; }
str Page::getDesc() const { return desc; }