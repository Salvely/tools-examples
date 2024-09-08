#define BOOST_TEST_MODULE MyTestSuite
#include "reverse.h"
#include <boost/test/included/unit_test.hpp>
#include <string>
using std::string;

BOOST_AUTO_TEST_CASE(MyTestCase) {
    BOOST_CHECK(reverse("hello") == "olleh");
}

BOOST_AUTO_TEST_CASE(check_reverse) {
    BOOST_TEST(reverse("abcd") == "dcba");
    BOOST_TEST(reverse("12345") == "54321");
    BOOST_TEST(reverse("Even") == "nevE");

    // Add a failure case
    BOOST_TEST(reverse("Odd") == "ddO");
    BOOST_TEST(reverse("a") == "a");
    BOOST_TEST(reverse("") == "");
}