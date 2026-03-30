#include "list.hpp"

#include <gtest/gtest.h>

TEST(LIST, insert_element)
{
    List list;
    EXPECT_EQ(list.length(), 0);
    list.push_back(123);
    EXPECT_EQ(list.length(),1);
    int value;
    ASSERT_TRUE(list.get(0, value));
    ASSERT_EQ(value, 123);
}

TEST(LIST, get_on_empty)
{
    List list;
    int value;
    ASSERT_FALSE(list.get(0, value));
}

// HOMEWORK 5-6 Tests
//  get(unsigned int index, int& val);
//  push_back(int value);
//  remove(unsigned int index);
//  print();
//  printReverse();
//  length();

// Insert 5 values then remove the middle, first and last
TEST(LIST, remove_first_middle_last)
{
    List list;
    int value;

    EXPECT_EQ(list.length(), 0);

    // Insert values from 1-5
    for(int i = 1; i<=5; i++)
    {
        list.push_back(i);
        ASSERT_EQ(list.length(), i);
    }

    // Remove middle, 1st and last
    list.remove(2);
    list.remove(0);
    list.remove(list.length()-1);

    ASSERT_EQ(list.length(), 2);
    ASSERT_EQ(list.get(0, value), 1);
}

// pushback a value, get it then remove it and repeat
TEST(LIST, pushback_rmv_get_repeat)
{
    List list;
    EXPECT_EQ(list.length(), 0);

    int value = 0;

    for(int i = 0; i<10; i++)
    {
        list.push_back(100*i);
        ASSERT_EQ(list.length(), 1);

        ASSERT_TRUE(list.get(0, value));
        ASSERT_EQ(value, 100*i); 

        list.remove(0);
        ASSERT_EQ(list.length(), 0);
    }

}

// See if the captured console print matches
TEST(LIST, print_rmv_list)
{
    List list;
    for(int i = 1; i <= 5; i++)
        list.push_back(100 * i);

    // Used CLAUDE Sonnet 4.6 here for capturing print-Buffer of console (same version for test printRev_rmv_list)
    // -----------------------------------------------------------------
    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();
    // -----------------------------------------------------------------

    EXPECT_EQ(output, "100, 200, 300, 400, 500, \n");
}

// See if the captured console printReverse matches
TEST(LIST, printRev_rmv_list)
{
    List list;
    for(int i = 1; i <= 5; i++)
        list.push_back(100 * i);

    // Used CLAUDE Sonnet 4.6 here for capturing print-Buffer of console (same version for test printRev_rmv_list)
    // -----------------------------------------------------------------
    testing::internal::CaptureStdout();
    list.printReverse();
    std::string output = testing::internal::GetCapturedStdout();
    // -----------------------------------------------------------------

    EXPECT_EQ(output, "500, 400, 300, 200, 100, \n");
}

// Testing the borders of the list
TEST(LIST, border_test)
{
    List list;
    EXPECT_EQ(list.length(), 0);

    int value;

    // Border at start - no elements in list
    ASSERT_FALSE(list.get(1, value));
    ASSERT_FALSE(list.get(0, value));
    ASSERT_FALSE(list.get(-1, value));

    for(int i = 0; i<100; i++)
    {
        list.push_back(i);
    }

    ASSERT_EQ(list.length(), 100);

    ASSERT_FALSE(list.get(100, value));
    ASSERT_TRUE(list.get(99, value));
    ASSERT_TRUE(list.get(98, value));
}