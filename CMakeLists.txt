option(BUILD_TESTS "Build tests" ON)


cmake_minimum_required(VERSION 3.10)
enable_testing()
# Set project name and version
project(SCLI VERSION 1.0)

# Specify the C++ standard and Clang as the compiler
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "clang++")

# Specify include directories (e.g., for headers)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/vendor)

# Collect all source files
file(GLOB SOURCES "src/*.cpp")

# Add executable with the collected source files
add_executable(SCLI ${SOURCES})

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()