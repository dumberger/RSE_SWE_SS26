#include "list.hpp"


#include <gtest/gtest.h>

TEST(LIST, get_on_empty) {
    List list;
    int value;
    ASSERT_FALSE(list.get(0, value));
}

TEST(LIST, insert_element) {
    List list;
    EXPECT_EQ(list.length(), 0);
    list.push_back(123);
    EXPECT_EQ(list.length(), 1);
    int value;
    ASSERT_TRUE(list.get(0, value));
    ASSERT_EQ(value, 123);
}

