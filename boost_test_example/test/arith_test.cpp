#include "arith.h"
#define BOOST_TEST_MODULE ArithTestSuite
#include <boost/test/included/unit_test.hpp>
BOOST_AUTO_TEST_CASE(addTestCase) {
    BOOST_CHECK_EQUAL(add(1, 2), 3);
}