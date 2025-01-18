#define CATCH_CONFIG_MAIN

#include <catch2.hpp>

std::string test()
{
    return "TEST";
}

TEST_CASE("TEST", "[TEST]")
{
    REQUIRE(test() == "TEST");
}
