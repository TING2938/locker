#include <gtest/gtest.h>

#include "example.h"

TEST(example, add1)
{
    auto ret = mysum_int(1, 2);
    ASSERT_EQ(ret, 3);
}

TEST(example, add32)
{
    auto ret2 = mysum_double(1.0, 2.0);
    ASSERT_NEAR(ret2, 3.0, 1.0e-11);
}