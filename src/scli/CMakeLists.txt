add_library(SCLI
    Core.cpp
    PageBuilder.cpp
    Utils.cpp
)

target_include_directories(SCLI PRIVATE "${PROJECT_SOURCE_DIR}/src/include")
target_include_directories(SCLI PRIVATE "${PROJECT_SOURCE_DIR}/vendor")
