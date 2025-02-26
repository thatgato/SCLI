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
#include <cstring>
#include <format>
#include <functional>
#include <string>
#include <unordered_map>

#include "scli/Utils.h"
#include "scli/classes/Command.h"
#include "scli/classes/Page.h"
#include "types/general.h"

// Pages
std::vector<uptr<Page>> TOP_LEVEL_PAGES;
std::deque<Page*> PAGE_DEQUE;

std::unordered_map<int, Page*>
    CurrentlyListedPages;  // Which pages are being displayed right now, by
                           // index?

std::unordered_map<int, Command*> CurrentlyListedCommands;

bool IS_COMMAND_MODE = false;

// CLI things
const str VERSION = "INDEV";

std::unordered_map<str, bool> FLAGS;

static Utils::Logger Logger("Core");

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

// Displays the current directory, the info about the current page, etc.
void displayTopInfo(str carriedOverMsg = "") {
    Logger.Out(SStyle::Quick::note +
               std::format("SCLI Version {}{}\n", VERSION, SStyle::reset));
    Logger.Out(SStyle::Quick::note + "Current page directory:" + SStyle::reset);
    Logger.Out(SStyle::Quick::note + Utils::GetPageDequeStr(PAGE_DEQUE) +
               SStyle::reset + "\n");

    if (carriedOverMsg != "") {
        Logger.Out("Last message: " + carriedOverMsg);
    }
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
    if (IS_COMMAND_MODE) {
        Logger.Out(SStyle::Quick::note +
                   "To select a command, type the index of the page, which "
                   "is shown in the [] brackets before the page name." +
                   SStyle::reset);
        Logger.Out(
            std::format("{}To exit the command loop, type {}{}\"{}\"{}{} or "
                        "{}{}\"{}\"{}.\n\n",
                        SStyle::Quick::note, SStyle::reset, SStyle::white,
                        "exit", SStyle::reset, SStyle::Quick::note,
                        SStyle::reset, SStyle::white, "e", SStyle::reset));
    } else {
        Logger.Out(SStyle::Quick::note +
                   "To select a page, type the index of the page, which "
                   "is shown in the [] brackets before the page name." +
                   SStyle::reset);
        // Drastic situations call for drastic measures...
        Logger.Out(std::format(
            "{}To exit the application, type {}{}\"{}\"{}{} or {}{}\"{}\"{}.{} "
            "To "
            "return to the root directory, type {}{}\"{}\"{}{} or "
            "{}{}\"{}\"{}{}.{}\n\n",
            SStyle::Quick::note, SStyle::reset, SStyle::white, "exit",
            SStyle::reset, SStyle::Quick::note, SStyle::reset, SStyle::white,
            "e", SStyle::reset, SStyle::Quick::note, SStyle::reset,
            SStyle::white, "root", SStyle::reset, SStyle::Quick::note,
            SStyle::reset, SStyle::white, "r", SStyle::reset,
            SStyle::Quick::note, SStyle::reset));
    }
}

// ? Tries to get an input that is not just a newline...
str getValidInput() {
    str inp = Logger.In();
    if (strlen(inp.c_str()) == 0) {
        inp = getValidInput();
    }
    return inp;
}

std::pair<bool, int> GetSelectedOption(str& inp) {
    std::pair<bool, int> res = Utils::TryConvertStrToInt(inp);
    int inputtedIdx = res.second;

    // ? Is the input even convertable into a number?
    if (!res.first) {
        Logger.Log(
            "Failed to convert your input into a number! Are you sure you "
            "typed it correctly?",
            LogLevel::WARN);
        Logger.In();
        return std::pair<bool, int>(false, 0);
    }

    // ? Is the inputted index not resolving to an actual page that is being displayed?
    if (IS_COMMAND_MODE) {
        if (CurrentlyListedCommands.find(inputtedIdx) ==
            CurrentlyListedCommands.end()) {
            Logger.Log("There is no command option with this index!",
                       LogLevel::WARN);
            Logger.In();
            return std::pair<bool, int>(false, 0);
        }
    } else {
        if (CurrentlyListedPages.find(inputtedIdx) ==
            CurrentlyListedPages.end()) {
            Logger.Log("There is no page with this index!", LogLevel::WARN);
            Logger.In();
            return std::pair<bool, int>(false, 0);
        }
    }

    return std::pair<bool, int>(true, inputtedIdx);
}

bool isRootPageActive() { return PAGE_DEQUE.empty(); }

// ? Internal commands

EPostCmdAction Exit() { return EXIT; }
EPostCmdAction ExitCmd() { return EXIT_CMD_CTX; }
EPostCmdAction Root() { return RERUN_FIRST_LOOP; }
EPostCmdAction Back() {
    if (PAGE_DEQUE.size() >= 1) {
        PAGE_DEQUE.pop_back();
        return RERUN;
    } else {
        return RERUN;
    }
}

std::unordered_map<str, std::function<EPostCmdAction()>> CmdFuncMap;

/* -------------------------------------------------------------------------- */
/*                      Core functions exposed through .h                     */
/* -------------------------------------------------------------------------- */

EPostCmdAction Core::GET_INTERNAL_CMD_RESULT(const str& cmd) {
    EPostCmdAction ret = CONTINUE;
    if (CmdFuncMap.contains(cmd)) {
        ret = CmdFuncMap[cmd]();
    }
    return ret;
}

void Core::MAIN(bool isFirstLoop, str carryOverMsg) {
    system("cls");
    CurrentlyListedPages.clear();

    if (isFirstLoop) {
        // ? Set the internal commands up
        CmdFuncMap["e"] = Exit;
        CmdFuncMap["exit"] = Exit;
        CmdFuncMap["!e"] = ExitCmd;
        CmdFuncMap["b"] = Back;
        CmdFuncMap["back"] = Back;
        CmdFuncMap["r"] = Root;
        CmdFuncMap["root"] = Root;

        IS_COMMAND_MODE =
            false;  // this should probably be here, remove later if weird shit happens

        std::deque<Page*> emptyDeq;
        PAGE_DEQUE.swap(emptyDeq);
    }

    displayTopInfo();
    if (isFirstLoop) firstLoopSetup();

    for (auto& pair : CurrentlyListedPages) {
        Logger.Out(std::to_string(pair.first) + "-->" + pair.second->getName());
    }

    // If this is not the first loop (root dir) then display all the child pages
    // of the current page

    if (!isFirstLoop) {
        if (!isRootPageActive()) {
            IS_COMMAND_MODE = PAGE_DEQUE.back()->isCommandPage();
            if (IS_COMMAND_MODE) {
                DISPLAY_CMDS(*PAGE_DEQUE.back());
            } else {
                DISPLAY_PAGE(*PAGE_DEQUE.back());
            }
        }
    }

    // Handle the case where we backtrack from a page to the root page
    if (isRootPageActive() && !isFirstLoop) {
        Core::DISPLAY_PAGE();
    }

    /* ------------------------ Get the input here ------------------------ */

    str inp;

    // ? Is the input empty? (ie: enter pressed) just rerun the loop
    inp = getValidInput();

    EPostCmdAction res = Core::GET_INTERNAL_CMD_RESULT(inp);

    bool shouldExit = false;
    switch (res) {
        case CONTINUE:
            break;
        case RERUN:
            Core::MAIN(isFirstLoop);
            break;
        case RERUN_FIRST_LOOP:
            Core::MAIN(true);
            break;
        case EXIT:
            shouldExit = true;  // lol
            break;
        case EXIT_CMD_CTX:  // We dont have to do anything with this cuz we are not in command context
            break;
    }

    if (shouldExit) {
        return;
    }

    // ? Check for the validity of the input, ie: Is there a page like this? Is it a number? etc
    std::pair<bool, int> result = GetSelectedOption(inp);
    if (!result.first) {
        MAIN(isFirstLoop);
        return;
    }

    int inputtedIdx = result.second;

    if (IS_COMMAND_MODE) {
        EXEC_CMD(inputtedIdx);
        MAIN(false);
        return;
    }

    Logger.Out("All checks passed, should enter page now!!!!");

    // ? Entering the page
    // Listed pages val gets cleared when the function is reinvoked..!
    PAGE_DEQUE.push_back(CurrentlyListedPages[inputtedIdx]);

    MAIN(false);
}

void Core::EXEC_CMD(int cmdIdx) {
    Logger.Out("Should be executing the command now?\n\n");

    CurrentlyListedCommands[cmdIdx]->Run(true);
}

void Core::DISPLAY_CMDS(const Page& pPage) {
    // Control notice bla bla
    Logger.Out(std::format("{}Displaying commands of the \"{}\" page.{}",
                           SStyle::green, PAGE_DEQUE.back()->getName(),
                           SStyle::reset));

    logControlNotice();

    u8 cmdIdx = 0;
    if (IS_COMMAND_MODE) {
        for (auto& pCommand : PAGE_DEQUE.back()->getChildCommands()) {
            //<WhiteBold> [idx] Name <reset> --> <GrayItalic> description <reset>
            Logger.Out(std::format(
                "{}[{}] {}{} -> {}{}{}", SStyle::white + SStyle::bold, cmdIdx,
                pCommand->GetName(), SStyle::reset, SStyle::Quick::note,
                pCommand->GetDesc(), SStyle::reset));

            CurrentlyListedCommands[cmdIdx] = pCommand.get();
            cmdIdx++;
        }
        return;
    }
    Logger.Out("\n\n");
}

void Core::DISPLAY_PAGE(const Page& pPage) {
    Logger.Out(std::format("{}Displaying sub-pages of \"{}\"{}", SStyle::green,
                           PAGE_DEQUE.back()->getName(), SStyle::reset));

    logControlNotice();

    u8 pageIdx = 1;
    for (auto& loopedPage : PAGE_DEQUE.back()->getChildPages()) {
        //<WhiteBold> [pageIdx] Name <reset> --> <GrayItalic> description <reset>
        Logger.Out(std::format(
            "{}[{}] {}{} -> {}{}{}", SStyle::white + SStyle::bold, pageIdx,
            loopedPage->getName(), SStyle::reset, SStyle::Quick::note,
            loopedPage->getDesc(), SStyle::reset));

        CurrentlyListedPages[pageIdx] =
            loopedPage
                .get();  // Get raw pointer to the page... I hope no pointer
                         // fuckeries will happen in the future lol
        pageIdx++;
    }
    Logger.Out("\n\n");
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

void Core::REGISTER_TOP_LEVEL(uptr<Page>&& pPage) {
    TOP_LEVEL_PAGES.push_back(std::move(pPage));
}

void SET_FLAG(const str& flagName, bool val) {
    assert(!FLAGS.empty());
    FLAGS[flagName] = val;
}

Page* Core::GET_CURRENT_PAGE() {
    if (isRootPageActive()) {
        return nullptr;
    }
    return PAGE_DEQUE.back();
}
Page* Core::GET_LAST_PAGE() { return PAGE_DEQUE[PAGE_DEQUE.size() - 2]; }
str Core::GET_VERSION() { return VERSION; }
bool Core::GET_FLAG(str flagName) { return FLAGS.at(flagName); }
