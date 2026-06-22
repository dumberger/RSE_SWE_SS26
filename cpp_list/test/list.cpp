#include "list.hpp"

#include <gtest/gtest.h>

TEST(LIST, insert_element)
{
    List<int> list;
    EXPECT_EQ(list.length(), 0);
    list.push_back(123);
    EXPECT_EQ(list.length(),1);
    int value;
    ASSERT_TRUE(list.get(0, value));
    ASSERT_EQ(value, 123);
}

TEST(LIST, get_on_empty)
{
    List<int> list;
    int value;
    ASSERT_FALSE(list.get(0, value));
}

// Insert 5 values then remove the middle, first and last
// Change: Test is more atomic
TEST(LIST, remove_first_middle_last)
{
    List<int> list;
    int value;

    // Insert values from 1-5
    for(int i = 1; i<=5; i++)
    {
        list.push_back(i);
    }

    // Remove middle, 1st and last
    list.remove(2);
    list.remove(0);
    list.remove(list.length()-1);

    // Check remaining values [must be 2 and 4]
    // Change: Remaining values are checked
    list.get(0, value);
    ASSERT_TRUE(value == 2);

    list.get(1, value);
    ASSERT_TRUE(value == 4);
}

// pushback a value, get it then remove it
TEST(LIST, pushback_rmv_get)
{
    List<int> list;
    int value = 0;

    // Change: Deleted unnecessary repetition
    list.push_back(100);
    ASSERT_EQ(list.length(), 1);

    ASSERT_TRUE(list.get(0, value));
    ASSERT_EQ(value, 100); 

    list.remove(0);
    ASSERT_EQ(list.length(), 0);
}

// See if the captured console print matches
TEST(LIST, print_rmv_list)
{
    List<int> list;
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
    List<int> list;
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
    List<int> list;
    int value;

    // Border at start - no elements in list
    ASSERT_FALSE(list.get(1, value));
    ASSERT_FALSE(list.get(0, value));
    ASSERT_FALSE(list.get(-1, value));

    for(int i = 0; i<10; i++)
    {
        list.push_back(i);
    }

    ASSERT_EQ(list.length(), 10);

    // Change: Check last values at border
    list.get(10, value);
    ASSERT_FALSE(value == 10);

    list.get(9, value);
    ASSERT_TRUE(value == 9);

    list.get(8, value);
    ASSERT_TRUE(value == 8);
}