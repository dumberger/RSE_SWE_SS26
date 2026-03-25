#include "cpp_double_list.hpp"

#include <gtest/gtest.h>

/*
        bool get(unsigned int index, int &val);
        void push_back(int value);
        void remove(unsigned int index);
        unsigned int length();
        void print();
        void print_reverse();
*/

// TEST: get() aufrufen auf eine leere Liste
TEST(LIST, get_on_empty) {
    List list;
    int value;
    ASSERT_FALSE(list.get(0, value));
}

// TEST: get() auf ungültigen Index
TEST(LIST, get_invalid_index) {
    List list;
    int value;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    ASSERT_FALSE(list.get(3, value));  // Index außerhalb
}

// TEST: get() auf gültigen Index
TEST(LIST, get) {
    List list;
    int value = 2;
    list.push_back(1);
    list.push_back(2);

    ASSERT_TRUE(list.get(1, value));
    ASSERT_EQ(value, 2);
}

// TEST: push_back() gültig
TEST(LIST, push_back) {
    List list;
    int value = 1;
    list.push_back(1);
    ASSERT_EQ(list.length(), 1);
    ASSERT_TRUE(list.get(0, value));
}

// TEST: length() gültig
TEST(LIST, length) {
    List list;
    EXPECT_EQ(list.length(), 0);
    list.push_back(1);
    ASSERT_EQ(list.length(), 1);
}

// TEST: insert_element() gültig
TEST(LIST, insert_element) {
    List list;
    EXPECT_EQ(list.length(), 0);
    list.push_back(123);
    EXPECT_EQ(list.length(), 1);
    int value;
    ASSERT_TRUE(list.get(0, value));
    ASSERT_EQ(value, 123);
}

// TEST: remove() first element
TEST(LIST, remove_first_element) {
    List list;
    list.push_back(123);
    list.remove(0);
    ASSERT_EQ(list.length(), 0);
}

// TEST: remove() last element
TEST(LIST, remove_last_element) {
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    list.remove(2);  // Letztes Element löschen
    ASSERT_EQ(list.length(), 2);
    
    int value;
    ASSERT_TRUE(list.get(0, value));
    ASSERT_EQ(value, 1);
    ASSERT_TRUE(list.get(1, value));
    ASSERT_EQ(value, 2);
    ASSERT_FALSE(list.get(2, value));
}

// TEST: remove() on empty list
TEST(LIST, remove_empty_list) {
    List list;
    list.remove(0);
    ASSERT_EQ(list.length(), 0);
}

