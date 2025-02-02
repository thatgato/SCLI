add_subdirectory(classes)
add_subdirectory(scli)

add_executable(scli_main main.cpp)

# do target link libraries here i guess... for example the pages library lol
target_link_libraries(scli_main PRIVATE classes)
target_link_libraries(scli_main PRIVATE scli)
target_link_libraries(scli_main PRIVATE cmds)
target_link_libraries(scli_main PRIVATE utils)