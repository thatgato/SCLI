#pragma once

#include "types/general.h"
namespace Commands::Internal {

class InternalCommand {
   protected:
    vec<str> mp_aliases;

   public:
    InternalCommand(vec<str>& aliases) : mp_aliases(aliases) {};
    virtual void Run();
    vec<str> GetAliases();
};

class Exit : public InternalCommand {
   private:
    vec<str> m_aliases;

   public:
    void Run() override;
};

};  // namespace Commands::Internal