/*
    This file manages the core interactions in the CLI. Here is where the page
   switching, loading and clearing happens. We also execute commands from there.
   main.cpp calls this main function which is basically our main loop. We only
   break out if the user chooses to exit the app.

    ? For any future-comers no I do not plan adding macOS / Linux support.
    ? This is my first project anyway, and I use windows and have windows at
    ? my school too, which is where this program is mainly targeted, due to the
    ? amount of retarded repetitive schoolwork i have to do on calculators while
    ? my math classes are in the IT classroom...
*/

#include "SCLICore.h"

#include <windows.h>

#include <cassert>
#include <format>
#include <iostream>
#include <stack>
#include <unordered_map>

#include "SCLIUtils.h"
#include "Typedefs.h"
#include "classes/cmds/cogeo/vectors/CVecLen.h"

sptr<Page> LAST_PAGE = nullptr;
sptr<Page> CURRENT_PAGE = nullptr;

vec<uptr<Page>> TOP_LEVEL_PAGES;

const str VERSION = "INDEV";

std::unordered_map<str, bool> FLAGS;

// Basically the value storing the names of the loaded pages in a LIFO manner;
// used for displaying the current page path
std::stack<str> layer;

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

// Displays the current directory, the info about the current page, etc.
void displayTopInfo() {
    Utils::Log(Utils::StrStyle::red + "Test!" + Utils::StrStyle::reset);
}

/* -------------------------------------------------------------------------- */
/*                      Core functions exposed through .h                     */
/* -------------------------------------------------------------------------- */

void Core::MAIN(bool isFirstLoop) {
    system("cls");

    if (isFirstLoop) {
        SetConsoleTitleA(std::format("SCLI Version {}", VERSION).c_str());
        layer.push("root");

        //! FLAGS
        FLAGS["FDebugLogging"] = false;

        Core::DISPLAY_PAGE();
    }

    displayTopInfo();

    // Utils::Log("");

    auto* aaaaa = new Commands::CoGeo::Vectors::CVecLen();

    aaaaa->Run();

    delete aaaaa;

    str inp;
    std::cin >> inp;

    if (inp != "e" &&
        inp != "exit") {  // just for testing, delete later and rework
        MAIN(false);
    }
}

void Core::PROCESS_CMD(str cmdInputString) {}

void Core::DISPLAY_PAGE(const sptr<Page>& pPage) {}

void Core::DISPLAY_PAGE() {
    Utils::Log("Displaying top-level pages");

    for (auto& pPage : TOP_LEVEL_PAGES) {
        Utils::Log(std::format("{} -> {}", pPage->getName(), pPage->getDesc()));
    }
}

void Core::REGISTER_TOP_LEVEL(uptr<Page>& pPage) {
    TOP_LEVEL_PAGES.push_back(std::move(pPage));
}

void SET_FLAG(const str& flagName, bool val) {
    assert(!FLAGS.empty());
    FLAGS[flagName] = val;
}

sptr<Page> Core::GET_CURRENT_PAGE() { return CURRENT_PAGE; }
sptr<Page> Core::GET_LAST_PAGE() { return LAST_PAGE; }
str Core::GET_VERSION() { return VERSION; }
bool Core::GET_FLAG(str flagName) { return FLAGS.at(flagName); }
