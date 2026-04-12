#include "list.hpp"
#include <gtest/gtest.h>

// helper function to check the value at the given index
void expectValue(const List<int>& list, int index, int expected)
{
    int value;
    ASSERT_TRUE(list.get(index, value));
    EXPECT_EQ(value, expected);
}

    /* ***** */
    /* TESTS */
    /* ***** */

// length of an empty list should be 0
TEST(LIST, length_on_empty)
{
    List<int> list;
    EXPECT_EQ(list.length(), 0);
}

// get on empty list should return false
TEST(LIST, get_on_empty) 
{
    List<int> list;
    int value;
    EXPECT_FALSE(list.get(0, value));
}

// get on out of bounds index should return false
TEST(LIST, get_out_of_bounds)
{
    List<int> list;
    list.push_back(1);

    int value;
    EXPECT_FALSE(list.get(1, value));
    EXPECT_FALSE(list.get(10, value));
}

// insert an element and check if it is there
TEST(LIST, insert_element) 
{
    List<int> list;
    EXPECT_EQ(list.length(), 0);
    list.push_back(123);
    EXPECT_EQ(list.length(), 1);
    expectValue(list, 0, 123);
}

// insert multiple elements and check if they are there
TEST(LIST, insert_multiple_elements)
{
    List<int> list;
    EXPECT_EQ(list.length(), 0);
    for (int i = 0; i < 10; i++) 
    {
        list.push_back(i);
    }
    EXPECT_EQ(list.length(), 10);
    for (int i = 0; i < 10; i++) 
    {
        expectValue(list, i, i);
    }
}

// remove the first element and check if the list is correct
TEST(LIST, remove_first_element)
{
    List<int> list;
    list.push_back(1);   
    list.push_back(2);

    EXPECT_TRUE(list.remove(0));

    EXPECT_EQ(list.length(), 1);

    expectValue(list, 0, 2);
    int value;
    EXPECT_FALSE(list.get(1, value));
}

// remove the last element and check if the list is correct
TEST(LIST, remove_last_element)
{
    List<int> list;
    list.push_back(1);   
    list.push_back(2);

    EXPECT_TRUE(list.remove(1));

    EXPECT_EQ(list.length(), 1);
   
    expectValue(list, 0, 1);
    int value;
    EXPECT_FALSE(list.get(1, value));
}

// remove a middle element and check if the list is correct
TEST(LIST, remove_middle_element)
{
    List<int> list;
    list.push_back(1);   
    list.push_back(2);
    list.push_back(3);

    EXPECT_TRUE(list.remove(1));

    EXPECT_EQ(list.length(), 2);
    
    expectValue(list, 0, 1);
    expectValue(list, 1, 3);
    int value;
    EXPECT_FALSE(list.get(2, value));
}

// remove the last remaining element and check if the list is correct
TEST(LIST, remove_last_remaining_element)
{
    List<int> list;
    list.push_back(1);   

    EXPECT_TRUE(list.remove(0));

    EXPECT_EQ(list.length(), 0);
    
    int value;
    EXPECT_FALSE(list.get(0, value));   
}

// remove on empty list should return false
TEST(LIST, remove_on_empty)
{
    List<int> list;
    
    EXPECT_FALSE(list.remove(0));

    EXPECT_EQ(list.length(), 0);
    int value;
    EXPECT_FALSE(list.get(0, value));
}

// remove out of index should return false
TEST(LIST, remove_out_of_index)
{
    List<int> list;
    list.push_back(1);

    EXPECT_FALSE(list.remove(1));

    EXPECT_EQ(list.length(), 1);
    expectValue(list, 0, 1);    
}

// print an empty list should print nothing
TEST(LIST, print_empty)
{
    List<int> list;

    std::stringstream ss;
    list.print(ss);

    EXPECT_EQ(ss.str(), "");
}

// print a list with multiple elements should print the correct values
TEST(LIST, print_list)
{
    List<int> list;
    for (int i = 0; i < 5; i++)
    {
        list.push_back(i);
    }

    std::stringstream ss;
    list.print(ss);

    EXPECT_EQ(ss.str(), "0, 1, 2, 3, 4");
}

// print a list after removing an element should print the correct values
TEST(LIST, print_after_remove)
{
    List<int> list;
    for (int i = 0; i < 5; i++)
    {
        list.push_back(i);
    }

    list.remove(1);

    std::stringstream ss;
    list.print(ss);

    EXPECT_EQ(ss.str(), "0, 2, 3, 4");
}

// print an empty list in reverse should print nothing
TEST(LIST, print_reverse_empty)
{
    List<int> list;

    std::stringstream ss;
    list.printReverse(ss);

    EXPECT_EQ(ss.str(), "");
}

// print a list in reverse should print the correct values
TEST(LIST, print_reverse)
{
    List<int> list;
    for (int i = 0; i < 5; i++)
    {
        list.push_back(i);
    }

    std::stringstream ss;
    list.printReverse(ss);

    EXPECT_EQ(ss.str(), "4, 3, 2, 1, 0");
}

// print a list after removing an element in reverse should print the correct values
TEST(LIST, print_reverse_after_remove)
{
    List<int> list;
    for (int i = 0; i < 5; i++)
    {
        list.push_back(i);
    }

    list.remove(1);

    std::stringstream ss;
    list.printReverse(ss);

    EXPECT_EQ(ss.str(), "4, 3, 2, 0");
}

// print forward and backward should be consistent
TEST(LIST, print_forward_backward_consistency)
{
    List<int> list;

    for (int i = 0; i < 5; i++)
        list.push_back(i);

    list.remove(2);

    std::stringstream forward;
    std::stringstream backward;

    list.print(forward);
    EXPECT_EQ(forward.str(), "0, 1, 3, 4");

    list.printReverse(backward);    
    EXPECT_EQ(backward.str(), "4, 3, 1, 0");
}




