#include "list.hpp"
#include <gtest/gtest.h>

TEST(d_linked_list, length){
    List list;
    ASSERT_EQ(list.length(), 0);
    list.push_back(1);
    ASSERT_EQ(list.length(), 1);
}

TEST(d_linked_list, get){
    List list;
    int value;
    ASSERT_FALSE(list.get(0,value));
    list.push_back(1);
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 1);
    ASSERT_FALSE(list.get(4, value));
}

TEST(d_linked_list, pushBack){
    int value;
    List list;
    list.push_back(1);
    list.get(0, value);
    ASSERT_EQ(value, 1);
    list.push_back(22);
    list.get(1, value);
    ASSERT_EQ(value, 22);
}

TEST(d_linked_list, remove){
    List list;
    int value;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.get(1, value);
    EXPECT_EQ(value, 2);
    EXPECT_EQ(list.length(), 3);

    list.remove(1);
    list.get(1, value);
    EXPECT_EQ(value, 3);
    EXPECT_EQ(list.length(), 2);

    list.remove(1);
    list.remove(0);
    EXPECT_EQ(list.length(), 0);
}

TEST(d_linked_list, print){
    List list;

    // list is empty
    ASSERT_EQ(list.print(), 0);


    list.push_back(1);
    int arr1[list.length()];
    
    //tests if holding only 1 element works
    ASSERT_EQ(list.print(arr1), 1);
    EXPECT_EQ(arr1[0], 1);


    list.push_back(2);
    list.push_back(3);
    int arr2[list.length()];
    

    //tests if more than 1 elements works
    ASSERT_EQ(list.print(arr2), 3);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr2[2], 3);
}

TEST(d_linked_list, printReverse){
    List list;

    // list is empty
    ASSERT_EQ(list.printReversed(), 0);


    list.push_back(1);
    int arr1[list.length()];
    
    //tests if holding only 1 element works
    ASSERT_EQ(list.printReversed(arr1), 1);
    EXPECT_EQ(arr1[0], 1);


    list.push_back(2);
    list.push_back(3);
    int arr2[list.length()];
    

    //tests if more than 1 elements works
    ASSERT_EQ(list.printReversed(arr2), 3);
    EXPECT_EQ(arr2[0], 3);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr2[2], 1);
}