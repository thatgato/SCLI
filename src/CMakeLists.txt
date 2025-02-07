add_subdirectory(classes/cmds)
add_subdirectory(classes/core)
add_subdirectory(scli)
add_subdirectory(mathlib)

add_executable(scli_main main.cpp)

# do target link libraries here i guess... for example the pages library lol
target_link_libraries(scli_main PRIVATE CORE_CLASSES)
target_link_libraries(scli_main PRIVATE SCLI)
target_link_libraries(scli_main PRIVATE COMMANDS)

target_include_directories(scli_main PRIVATE "${PROJECT_SOURCE_DIR}/src/include")
target_include_directories(scli_main PRIVATE "${PROJECT_SOURCE_DIR}/vendor")