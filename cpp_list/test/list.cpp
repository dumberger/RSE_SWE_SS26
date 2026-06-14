#include "list.hpp"
#include "gtest/gtest.h"

TEST(LIST, insert_element) { // was done in the class
    List<int> list;

    EXPECT_EQ(list.length(), 0);

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    EXPECT_EQ(list.length(), 3); //EXPECT I expect this value but if something else is returned, the test will go further

    int value = 0;
    ASSERT_TRUE(list.get(0, value)); 
    ASSERT_EQ(value, 1); //ASSERT I expect this value but if something else is returned, the test will be stopped here
    ASSERT_TRUE(list.get(1, value)); 
    ASSERT_EQ(value, 2);
    ASSERT_TRUE(list.get(2, value)); 
    ASSERT_EQ(value, 3);

    // check all elements in the list to be sure that they are correct
}

TEST(LIST, remove_element) {
    List<int> list;

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    EXPECT_EQ(list.length(), 3);

    list.remove(1);

    int value = 0;
    EXPECT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 1);
    EXPECT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 3);
    EXPECT_EQ(list.length(), 2);

}

TEST(LIST, remove_element_empty_list) {
    List<int> list;

    EXPECT_EQ(list.length(), 0);

    list.remove(1);
    EXPECT_EQ(list.length(), 0);

    int value = 0;
    EXPECT_FALSE(list.get(0, value)); // got failed with exit code 1 -> get() function corrected
}

TEST(LIST, remove_element_out_of_bounds) {
    List<int> list;

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    EXPECT_EQ(list.length(), 3);

    list.remove(5); // should not do anything

    EXPECT_EQ(list.length(), 3); // should still be 3
}

TEST(LIST, get_element_out_of_bounds) {
    List<int> list;

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    int value = 0;
    EXPECT_FALSE(list.get(5, value)); // should return false
    EXPECT_TRUE(list.get(2, value)); // should return true
    EXPECT_EQ(value, 3);

}

TEST(LIST, remove_get_negative_index) {
    List<int> list;

    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);

    EXPECT_EQ(list.length(), 3);

    list.remove(-1); // should not do anything

    EXPECT_EQ(list.length(), 3); 

    int value = 0;
    EXPECT_FALSE(list.get(-1, value)); // should return false   
}

TEST(LIST, remove_first_element) {
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.remove(0); 

    int value = 0;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 2); 
    EXPECT_EQ(list.length(), 1);
}

TEST(LIST, remove_last_element) {
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.remove(2); 

    int value = 0;
    EXPECT_EQ(list.length(), 2);
    EXPECT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 1);
    EXPECT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 2);
    EXPECT_FALSE(list.get(2, value));
}

TEST(LIST, remove_one_element) {
    List<int> list;
    list.pushBack(100);
    list.remove(0);

    EXPECT_EQ(list.length(), 0);
    int value = 0;
    EXPECT_FALSE(list.get(0, value));
}

TEST(LIST, delete_list) {
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);

    list._delete();

    EXPECT_EQ(list.length(), 0);
}

