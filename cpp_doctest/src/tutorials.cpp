/**
 * @file tutorials.cpp
 * @author your name (you@domain.com)
 * @brief the test script for https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md
 * @version 0.1
 * @date 2024-09-12
 * s
 * @copyright Copyright (c) 2024
 * 
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <vector>

int factorial(int number) {
    return number <= 1 ? number : factorial(number - 1) * number;
}

TEST_CASE("testing the factorial function") {
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(4) == 24);
}

TEST_CASE("vectors can be sized and resized") {
    std::vector<int> v(5);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 5);

    SUBCASE("adding to the vector increases its size") {
        v.push_back(1);

        CHECK(v.size() == 6);
        CHECK(v.capacity() >= 6);
    }
    SUBCASE("reserving increases just the capacity") {
        v.reserve(6);

        CHECK(v.size() == 5);
        CHECK(v.capacity() >= 6);
    }
}