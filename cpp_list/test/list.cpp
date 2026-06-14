#include "list.hpp"

#include <gtest/gtest.h>

TEST(LIST, insert_element)
{
    List<int> list;
    EXPECT_EQ(list.length(), 0);
    list.push_back(123);
    EXPECT_EQ(list.length(), 1);
    int val;
    ASSERT_TRUE(list.get(0,val));
    ASSERT_EQ(val, 123);
}

TEST(LIST, remove_element)
{
    List<int> list;
    list.push_back(123);
    list.push_back(35);
    list.push_back(63);
    list.push_back(4);
    EXPECT_EQ(list.length(), 4);
    int val;
    ASSERT_TRUE(list.get(1,val));
    ASSERT_EQ(val, 35);
    list.remove(1);
    ASSERT_TRUE(list.get(1,val));
    ASSERT_EQ(val, 63);
    ASSERT_TRUE(list.get(2,val));
    ASSERT_EQ(val, 4);
    list.push_back(677);
    ASSERT_TRUE(list.get(3,val));
    ASSERT_EQ(val, 677);
}