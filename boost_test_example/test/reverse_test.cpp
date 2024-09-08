#define BOOST_TEST_MODULE MyTestSuite
#include "reverse.h"
#include <boost/test/included/unit_test.hpp>
#include <string>
using std::string;

BOOST_AUTO_TEST_CASE(MyTestCase) {
    BOOST_CHECK(reverse("hello") == "olleh");
}