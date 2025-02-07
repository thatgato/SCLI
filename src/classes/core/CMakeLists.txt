add_library(CORE_CLASSES STATIC
    Page.cpp
    Command.cpp
)

target_include_directories(CORE_CLASSES PRIVATE "${PROJECT_SOURCE_DIR}/src/include")
