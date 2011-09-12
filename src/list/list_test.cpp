#include <gtest/gtest.h>

#include "list_node.c"
#include "list.c"

int
main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(list, new_list_is_empty)
{
    list_t *list = list_alloc();

    EXPECT_TRUE(list_is_empty(list));

    list = list_free(list);
}

TEST(list, new_list_has_zero_length)
{
    list_t *list = list_alloc();

    EXPECT_EQ(list_length(list), 0);

    list = list_free(list);
}

TEST(list, add_one_to_empty)
{
    list_t *list = list_alloc();

    char *data = (char *)"data";
    list_add_first(list, data);
    EXPECT_EQ(list_get_first(list), data);

    list = list_free(list);
}

TEST(list, add_and_remove_one)
{
    list_t *list = list_alloc();

    char *data = (char *)"data";
    list_add_first(list, data);
    list_remove_first(list);
    EXPECT_TRUE(list_is_empty(list));

    list = list_free(list);
}
