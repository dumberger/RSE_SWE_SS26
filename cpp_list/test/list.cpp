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
    EXPECT_EQ(list.length(), 3);    //3 elements
    EXPECT_EQ(list.length(), list.size());  //lenght same as size
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

//Testing get value of list node
TEST(LIST, get_value) {
    List list;
    int value;
    //get from no elements
    ASSERT_FALSE(list.get(0, value));
    //get from list
    int insertion_value = 9999;
    list.push_back(insertion_value);
    ASSERT_TRUE(list.get(0, value));
    ASSERT_EQ(value, insertion_value);

    //add more
    list.push_back(100);
    list.push_back(100);
    ASSERT_TRUE(list.get(0, value));
    ASSERT_EQ(value, insertion_value);
}

TEST(LIST, get_node) {
    List list;
    //empty list
    NodeList* node;
    ASSERT_FALSE(list.getNode(100, node));

    //list element
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);
    ASSERT_TRUE(list.getNode(1, node));

    //check node
    ASSERT_EQ(node.Value, 200);
    ASSERT_EQ(node.prev, list.first);
    ASSERT_EQ(node.next, list.last);
}

//Testing insert and remove at zero
TEST(LIST, remove_element) {
    List list;
    //insert no elements
    list.remove(0);
    EXPECT_EQ(list.length(), 0);

    //insert exactly one element
    list.push_back(123);
    EXPECT_EQ(list.length(), 1);
    list.remove(0);
    EXPECT_EQ(list.length(), 0);

    //adding more than one then remove
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);
    EXPECT_EQ(list.length(), 3);
    list.remove(0);
    EXPECT_EQ(list.length(), 2);
    int value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 200);
    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 200);
}