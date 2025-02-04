add_library(scli
    SCLICore.cpp
    SCLIPageBuilder.cpp
)

target_include_directories(scli PUBLIC "${PROJECT_SOURCE_DIR}/src/include")
target_include_directories(scli PUBLIC "${PROJECT_SOURCE_DIR}/vendor")
