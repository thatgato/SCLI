set(IS_RELEASE_BUILD ON)

# Configure different settings based on build type
if(NOT IS_RELEASE_BUILD)
    message("Configuring Debug mode")

    # This is some msvc library? Im not sure, my exe just wouldnt work without this
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL")

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Debug)

    add_compile_definitions(DEBUG)
    add_compile_options(-g)

else() # Assume Release mode
    message("Configuring Release mode")

    # This is some msvc library? Im not sure, my exe just wouldnt work without this
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Release)

    add_compile_definitions(NDEBUG)
    add_compile_options(-O3)
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Minimum required version of CMake
cmake_minimum_required(VERSION 3.20)

# Project name and version
project(SCLI VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add directories for source, tests, and vendor dependencies
add_subdirectory(src)

# add_subdirectory(tests)