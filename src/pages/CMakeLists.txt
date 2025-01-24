add_library(pages
    Page.cpp
    CoGeo.cpp
)

target_include_directories(pages PUBLIC "${PROJECT_SOURCE_DIR}/src/include")
