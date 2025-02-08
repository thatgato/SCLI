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
#include <stack>
#include <string>
#include <unordered_map>

#include "scli/Utils.h"
#include "types/general.h"

// Pages
Page* LAST_PAGE = nullptr;
Page* CURRENT_PAGE = nullptr;

vec<sptr<Page>> TOP_LEVEL_PAGES;
std::unordered_map<int, Page*>
    CurrentlyListedPages;  // Which pages are being displayed right now, by
                           // index?

// CLI things
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
void displayTopInfo() {
    Logger.Out(SStyle::Quick::note +
               std::format("SCLI Version {}{}\n", VERSION, SStyle::reset));
    Logger.Out(SStyle::Quick::note + "Current page directory:" + SStyle::reset);
    Logger.Out(SStyle::Quick::note + Utils::GetPageStackDirectory(layer) +
               SStyle::reset + "\n");
}

// Runs the first loop setup, like changing the console window title
void firstLoopSetup() {
    SetConsoleTitleA(std::format("SCLI Version {}", VERSION).c_str());

    //! FLAGS
    FLAGS["FDebugLogging"] = false;

    Core::DISPLAY_PAGE();
}

// Basically logs to the console telling the user how they can use the app.
void logControlNotice() {
    Logger.Out(SStyle::Quick::note +
               "To select a page / command, type the index of the page, which "
               "is shown in the [] brackets before the page name." +
               SStyle::reset);
    // Drastic situations call for drastic measures...
    Logger.Out(std::format(
        "{}To exit the application, type {}{}\"{}\"{}{} or {}{}\"{}\"{}.{} To "
        "return to the root directory, type {}{}\"{}\"{}{} or "
        "{}{}\"{}\"{}{}.{}\n\n",
        SStyle::Quick::note, SStyle::reset, SStyle::white, "exit",
        SStyle::reset, SStyle::Quick::note, SStyle::reset, SStyle::white, "e",
        SStyle::reset, SStyle::Quick::note, SStyle::reset, SStyle::white,
        "root", SStyle::reset, SStyle::Quick::note, SStyle::reset,
        SStyle::white, "r", SStyle::reset, SStyle::Quick::note, SStyle::reset));
}

/* -------------------------------------------------------------------------- */
/*                      Core functions exposed through .h                     */
/* -------------------------------------------------------------------------- */

void Core::MAIN(bool isFirstLoop) {
    system("cls");
    CurrentlyListedPages.clear();

    if (isFirstLoop) {
        std::stack<str> emptyStack;
        layer.swap(emptyStack);
        layer.push("root");  // This is needed so we can display the root
                             // directory before displaying the top level pages
    }

    displayTopInfo();
    if (isFirstLoop) firstLoopSetup();

    for (auto& pair : CurrentlyListedPages) {
        Logger.Out(std::to_string(pair.first) + "-->" + pair.second->getName());
    }

    // If this is not the first loop (root dir) then display all the child pages
    // of the current page
    if (!isFirstLoop) {
        DISPLAY_PAGE(*CURRENT_PAGE);
    }

    /* ------------------------ Get the input here ------------------------ */
    str inp = Logger.In();

    //* Check for which page we selected and if it is even valid
    std::pair<bool, int> res = Utils::TryConvertStrToInt(inp);
    int inputtedIdx = res.second;

    // ? Is the input even convertable into a number?
    if (!res.first) {
        Logger.Log(
            "Failed to convert your input into a number! Are you sure you "
            "typed it correctly?",
            LogLevel::WARN);
        Logger.In();
        MAIN(isFirstLoop);
        return;
    }

    // ? Is the inputted index not resolving to an actual page that is being
    // displayed?
    if (CurrentlyListedPages.find(inputtedIdx) == CurrentlyListedPages.end()) {
        Logger.Log("There is no page with this index!", LogLevel::WARN);
        Logger.In();
        MAIN(isFirstLoop);
        return;
    }

    Logger.Out("All checks passed, should enter page now!!!!");

    // ? Entering the page
    layer.push(CurrentlyListedPages[inputtedIdx]->getName());
    // Listed pages val gets cleared when the function is reinvoked..!

    CURRENT_PAGE = CurrentlyListedPages[inputtedIdx];
    if (inp != "e" &&
        inp != "exit") {  // just for testing, delete later and rework
        MAIN(false);
        return;
    }
}

void Core::PROCESS_CMD(str cmdInputString) {}

void Core::DISPLAY_PAGE(const Page& pPage) {
    Logger.Out(std::format("{}Displaying sub-pages of \"{}\"{}", SStyle::green,
                           CURRENT_PAGE->getName(), SStyle::reset));

    logControlNotice();

    u8 idx = 1;
    for (auto& pPage : CURRENT_PAGE->getChildPages()) {
        //<WhiteBold> [idx] Name <reset> --> <GrayItalic> description <reset>
        Logger.Out(
            std::format("{}[{}] {}{} -> {}{}{}", SStyle::white + SStyle::bold,
                        idx, pPage->getName(), SStyle::reset,
                        SStyle::Quick::note, pPage->getDesc(), SStyle::reset));
        CurrentlyListedPages[idx] =
            pPage.get();  // Get raw pointer to the page... I hope no pointer
                          // fuckeries will happen in the future lol
        idx++;
    }
}

void Core::DISPLAY_PAGE() {
    Logger.Out(SStyle::green + "Displaying top-level pages" + SStyle::reset);
    logControlNotice();

    u8 idx = 1;
    for (auto& pPage : TOP_LEVEL_PAGES) {
        //<WhiteBold> [idx] Name <reset> --> <GrayItalic> description <reset>
        Logger.Out(
            std::format("{}[{}] {}{} -> {}{}{}", SStyle::white + SStyle::bold,
                        idx, pPage->getName(), SStyle::reset,
                        SStyle::Quick::note, pPage->getDesc(), SStyle::reset));
        CurrentlyListedPages[idx] = pPage.get();
        idx++;
    }

    Logger.Out("\n");
}

void Core::REGISTER_TOP_LEVEL(sptr<Page>& pPage) {
    TOP_LEVEL_PAGES.push_back(std::move(pPage));
}

void SET_FLAG(const str& flagName, bool val) {
    assert(!FLAGS.empty());
    FLAGS[flagName] = val;
}

Page* Core::GET_CURRENT_PAGE() { return CURRENT_PAGE; }
Page* Core::GET_LAST_PAGE() { return LAST_PAGE; }
str Core::GET_VERSION() { return VERSION; }
bool Core::GET_FLAG(str flagName) { return FLAGS.at(flagName); }
