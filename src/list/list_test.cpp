#include <gtest/gtest.h>

#include "list/list.h"

TEST(some_test, test1)
{
    EXPECT_EQ(1, 1);
}

int
main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
