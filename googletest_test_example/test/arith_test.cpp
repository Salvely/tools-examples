#include "arith.h"
#include <gtest/gtest.h>

TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);
}

TEST(ArithTest, BasicAddition) {
    EXPECT_EQ(add(1, 2), 3);
}