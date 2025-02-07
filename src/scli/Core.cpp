/**
 * ==========================================================
 * @file        Core.h
 * @brief       SCLI Core Functions
 *
 * @author      thatgato
 * @date        2025-02-07
 * ==========================================================
 *
 * @details
 * The core functions of SCLI. Things like controlling which page to show, when
 * to flush the CLI, the main loop and registering top level pages all happen
 * here. This is the magical core of SCLI.
 *
 * ==========================================================
 */

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

#include "scli/Core.h"

#include <windows.h>

#include <cassert>
#include <format>
#include <iostream>
#include <stack>
#include <unordered_map>

#include "scli/Utils.h"
#include "scli/classes/cmds/cogeo/vectors/CVecLen.h"  // remove later, only here for testing
#include "types/general.h"

sptr<Page> LAST_PAGE = nullptr;
sptr<Page> CURRENT_PAGE = nullptr;

vec<uptr<Page>> TOP_LEVEL_PAGES;

const str VERSION = "INDEV";

std::unordered_map<str, bool> FLAGS;

// Basically the value storing the names of the loaded pages in a LIFO manner;
// used for displaying the current page path
std::stack<str> layer;

static Utils::Logger Logger("Core");

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

// Displays the current directory, the info about the current page, etc.
void displayTopInfo() { Logger.Log("Test"); }

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
    Logger.Log("Displaying top-level pages");

    for (auto& pPage : TOP_LEVEL_PAGES) {
        Logger.Log(std::format("{} -> {}", pPage->getName(), pPage->getDesc()));
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
