#include "cpp_double_list.hpp"

#include <gtest/gtest.h>

/*7

 List();
        ~List();
        bool get(unsigned int index, int &val);
        void push_back(int value);
        void remove(unsigned int index);
        unsigned int length();
        void print();
        void print_reverse();

*/

TEST(LIST, get_on_empty) {
    List list;
    int value;
    ASSERT_FALSE(list.get(0, value));
}

TEST(LIST, push_back) {
    List list;
    int value = 1;
    list.push_back(1);
    ASSERT_EQ(list.length(), 1);
    ASSERT_TRUE(list.get(0, value));
}

TEST(LIST, get) {
    List list;
    int value = 2;
    list.push_back(1);
    list.push_back(2);

    ASSERT_TRUE(list.get(1, value));
}

TEST(LIST, length) {
    List list;
    EXPECT_EQ(list.length(), 0);
    list.push_back(1);
    ASSERT_EQ(list.length(), 1);
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

TEST(LIST, remove) {
    List list;
    list.push_back(123);
    list.remove(0);
    ASSERT_EQ(list.length(), 0);
}


