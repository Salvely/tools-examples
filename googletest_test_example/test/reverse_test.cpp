#include "arith.h"
#include "reverse.h"
#include <gtest/gtest.h>

TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);
}

TEST(ReverseTest, BasicReverse) {
    EXPECT_EQ(reverse("hello"), "olleh");
}

TEST(ReverseTest, EmptyTest) {
    EXPECT_EQ(reverse(""), "");
}

TEST(ReverseTest, SingleCharTest) {
    EXPECT_EQ(reverse("a"), "a");
}

TEST(ReverseTest, CaseSensitiveTest) {
    EXPECT_NE(reverse("a"), "A");
}