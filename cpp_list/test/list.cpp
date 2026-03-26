#include "../include/list.hpp"

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

TEST(LIST, push_back_multiple) {
    List list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    EXPECT_EQ(list.length(), 3);
    int value;
    ASSERT_TRUE(list.get(1, value));
    ASSERT_EQ(value, 20);
}

TEST(LIST, get_out_of_bounds) {
    List list;
    list.push_back(42);
    int value;
    ASSERT_FALSE(list.get(5, value));
}

TEST(LIST, get_negative_index) {
    List list;
    list.push_back(42);
    int value;
    ASSERT_FALSE(list.get(-1, value));
}