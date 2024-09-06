/**
 * @file reverse_test.cpp
 * @author Wen Gao (iamgwen9@gmail.com)
 * @brief test for reverse and palidrome function
 * @version 0.1
 * @date 2024-09-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "palidrome.h"
#include "reverse.h"
#include <string>

#define BOOST_TEST_MODULE VsidCommonTest
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(reverse_tests)

BOOST_AUTO_TEST_CASE(simple) {
    std::string toRev = "Hello";

    toRev = reverse(toRev);

    BOOST_CHECK_EQUAL(toRev, "olleH");
}

BOOST_AUTO_TEST_CASE(empty) {
    std::string toRev;

    toRev = reverse(toRev);

    BOOST_CHECK_EQUAL(toRev, "");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(palindrome_tests)

BOOST_AUTO_TEST_CASE(is_palindrome) {
    std::string pal = "mom";

    BOOST_CHECK_EQUAL(palidrome(pal), true);
}

BOOST_AUTO_TEST_SUITE_END()
