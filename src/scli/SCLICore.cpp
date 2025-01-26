/*
    This file manages the core interactions in the CLI. Here is where the page switching, loading and clearing happens.
    We also execute commands from there. main.cpp calls this main function which is basically our main loop.
    We only break out if the user chooses to exit the app.

    ? For any future-comers no I do not plan adding macOS / Linux support.
    ? This is my first project anyway, and I use windows and have windows at
    ? my school too, which is where this program is mainly targeted, due to the
    ? amount of retarded repetitive schoolwork i have to do on calculators while
    ? my math classes are in the IT classroom...
*/

#include "SCLICore.h"

#include <windows.h>

#include <format>
#include <iostream>

#include "Typedefs.h"


Page* LAST_PAGE = nullptr;
Page* CURRENT_PAGE = nullptr;
const str VERSION = "INDEV";

void Core::MAIN() {
  system("cls");
  SetConsoleTitleA(std::format("SCLI Version {}", VERSION).c_str());

  // TODO: Display top level categories
  str inp;
  std::cin >> inp;

  if (inp != "e" && inp != "exit") {  // just for testing, delete later and rework
    MAIN();
  }
}