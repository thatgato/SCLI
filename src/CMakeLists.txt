add_subdirectory(pages)

add_executable(scli_main main.cpp)

# do target link libraries here i guess... for example the pages library lol
target_link_libraries(scli_main PRIVATE pages)