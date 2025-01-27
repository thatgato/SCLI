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
#include <chrono>
#include <format>
#include <iostream>
#include <stack>
#include <thread>
#include <unordered_map>

#include "Typedefs.h"


sptr<Page> LAST_PAGE;
sptr<Page> CURRENT_PAGE;

vec<uptr<Page>> TOP_LEVEL_PAGES;

const str VERSION = "INDEV";

std::unordered_map<str, bool> FLAGS;

// Basically the value storing the names of the loaded pages in a LIFO manner;
// used for displaying the current page path
std::stack<str> layer;

void Core::Log(str msg) { std::cout << msg << std::endl; }

void Core::DLog(str msg) {
#ifdef DEBUG_LOGGING
    std::cout << msg << std::endl;
#else
    if (true) {
        std::cout << msg << std::endl;
    }
#endif
}

void Core::MAIN(bool isFirstLoop) {
    system("cls");
    std::this_thread::sleep_for(std::chrono::seconds(1));

    if (isFirstLoop) {
        SetConsoleTitleA(std::format("SCLI Version {}", VERSION).c_str());
        layer.push("root");

        //! FLAGS
        FLAGS["FDebugLogging"] = false;

        Core::DISPLAY_PAGE();
    }

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
    Core::Log("Displaying top-level pages");

    for (auto& pPage : TOP_LEVEL_PAGES) {
        Core::Log(std::format("{} -> {}", pPage->getName(), pPage->getDesc()));
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