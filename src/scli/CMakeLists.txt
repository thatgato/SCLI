add_library(SCLI STATIC
        Core.cpp
        PageBuilder.cpp
        Utils.cpp
        sda.cpp
        ggfd.cpp
)

target_include_directories(SCLI PRIVATE "${PROJECT_SOURCE_DIR}/src/include")
target_include_directories(SCLI PRIVATE "${PROJECT_SOURCE_DIR}/vendor")
