cmake_minimum_required(VERSION 3.2)
project(TaskManager LANGUAGES CXX)

option(BUILD_TESTS "Build tests" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(tm-lib
        include/task.h
        include/cli.h
        include/storage.h
        include/manager.h

        src/cli.cpp
        src/manager.cpp
        src/storage.cpp
        src/task.cpp
)

target_include_directories(tm-lib PUBLIC include)

add_executable(TaskManager src/main.cpp)
target_link_libraries(TaskManager PRIVATE tm-lib)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()