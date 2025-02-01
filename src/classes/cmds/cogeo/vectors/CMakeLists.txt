add_library(vectors OBJECT
    CVecLen.cpp
)

target_include_directories(vectors PRIVATE "${PROJECT_SOURCE_DIR}/src/include")
