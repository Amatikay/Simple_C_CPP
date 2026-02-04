#include <gtest/gtest.h>
#include "foo.hpp"

TEST(HelloTest, BasicAssertions) {
  EXPECT_EQ(foo(2, 2), 4);
}
