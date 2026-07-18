#include <gtest/gtest.h>

#include "foo.h"
#include "foo.hpp"

TEST(HelloTest, BasicAssertions) {
    EXPECT_EQ(cpp::foo(2, 2), 4);
    EXPECT_EQ(foo(2, 2), 4);
}
