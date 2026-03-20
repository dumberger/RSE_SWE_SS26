//
// Created by madtic on 19.03.26.
//
#include "list.hpp"
#include <gtest/gtest.h>

//test lenght and size
TEST(LIST, list_elements) {
    List list;
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);
    EXPECT_EQ(list.length(), 3);
    EXPECT_EQ(list.length(), list.size());
}

//Testing insert of list node
TEST(LIST, insert_element) {
    List list;
    EXPECT_EQ(list.length(), 0);
    list.push_back(123);
    EXPECT_EQ(list.length(), 1);
    int value;
    ASSERT_TRUE(list.get(0, value));
    ASSERT_EQ(value, 123);
}

//Testing insert and remove at zero
TEST(LIST, remove_element) {
    List list;
    EXPECT_EQ(list.length(), 0);
    list.push_back(123);
    EXPECT_EQ(list.length(), 1);
    list.remove(0);
    EXPECT_EQ(list.length(), 0);

    //adding more than one
    list.push_back(0);
    list.push_back(1);
    list.push_back(3);
    EXPECT_EQ(list.length(), 3);
    list.remove(0);
    EXPECT_EQ(list.length(), 2);
}