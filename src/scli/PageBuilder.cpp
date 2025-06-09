/**
 * ==========================================================
 * @file        PageBuilder.h
 * @brief       Builds and registers the pages using scli/Core.h
 *
 * @author      thatgato
 * @date        2025-02-07
 * ==========================================================
 *
 * @details
 * Just a file that contains the definitions of every single page and command in
 * SCLI. This file registers pages and links them together along with commands.
 *
 * ==========================================================
 */

#include "scli/PageBuilder.h"

#include <memory>
#include <thread>

#include "scli/Core.h"
#include "scli/Utils.h"
#include "scli/classes/Page.h"
#include "scli/classes/cmds/cogeo/vectors/CVecLen.h"
#include "scli/classes/cmds/cogeo/vectors/CVecLerp.h"

Utils::Logger Logger("PageBuilder");

void Builder::BEGIN() {
  Logger.Log("Building commands and pages...");

  Utils::Clock clock;
  clock.START();

  /* --------------------------- Coordinate geometry --------------------------
   */

  // ? CoGeo
  uptr<Page> cogeo = std::make_unique<Page>(
      "Coordinate Geometry",
      "Contains categories that are related to coordinate geometry.");

  // ? Vectors
  uptr<Page> vectors = std::make_unique<Page>("Vectors", "Math with vectors!");

  /* ----------------------------- Vector commands ----------------------------
   */

  // ? CVecLen
  auto CVecLen = std::make_unique<Commands::CoGeo::Vectors::CVecLen>();
  vectors->AddCommand(std::move(CVecLen));

  // ? CVecLerp
  auto CVecLerp = std::make_unique<Commands::CoGeo::Vectors::CVecLerp>();
  vectors->AddCommand(std::move(CVecLerp));
  //
  //
  //

  cogeo->LinkChild(std::move(vectors));

  Core::REGISTER_TOP_LEVEL(std::move(cogeo));

  // ? END

  auto dur = clock.END();

  Logger.Log(std::format("Done! Building pages and commands took approximately "
                         "{:.4f}ms! Starting in a second...",
                         dur.count()));

  // Ha! You got bamboozled! it actually starts in 2 seconds, not one >:)
  std::this_thread::sleep_for(std::chrono::seconds(2));
}
