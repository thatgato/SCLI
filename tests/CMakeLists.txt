add_executable(tm-test
        # you can add more testfiles here
        # no need to provide main()

        test.cpp

        # dont remove this because test
        ${CMAKE_SOURCE_DIR}/vendor/catch2.cpp
)

target_include_directories(tm-test PRIVATE
        ${CMAKE_SOURCE_DIR}/vendor
)

target_link_libraries(tm-test PRIVATE
        tm-lib
)