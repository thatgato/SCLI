add_library(classes STATIC
    Page.cpp
    Command.cpp
)

file(GLOB_RECURSE CMD_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/cmds/*.cpp)

add_library(cmds STATIC ${CMD_SOURCES})

add_subdirectory(static)

target_include_directories(classes PUBLIC "${PROJECT_SOURCE_DIR}/src/include")
target_include_directories(cmds PUBLIC "${PROJECT_SOURCE_DIR}/src/include")