add_library(classes
    Page.cpp
    Command.cpp
)

add_subdirectory(cmds)
add_subdirectory(static)
target_include_directories(classes PUBLIC "${PROJECT_SOURCE_DIR}/src/include")
