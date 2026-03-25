#include "list.hpp"

#include <gtest/gtest.h>

TEST(LIST, get_on_empty) {
    List list;
    int value;
    ASSERT_FALSE(list.get(0, value));
}

TEST(LIST, get_first_and_last) {
    List list;
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);

    int value;

    // erstes Element
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 100);

    // letztes Element
    ASSERT_TRUE(list.get(2, value));
    EXPECT_EQ(value, 300);
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


TEST(LIST, remove_last_and_middle) {
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    list.remove(3);
    EXPECT_EQ(list.length(), 3);
    int value;
    ASSERT_TRUE(list.get(2, value));
    EXPECT_EQ(value, 3);

    list.remove(1);
    EXPECT_EQ(list.length(), 2);
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 1);
    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 3);
}