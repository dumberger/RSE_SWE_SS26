#include "list.hpp"

#include <gtest/gtest.h>

TEST(LIST, get_on_empty) {
    List<int> list;
    int value;
    ASSERT_FALSE(list.get(0, value));
}

TEST(LIST, insert_element) {
    List<int> list;
    EXPECT_EQ(list.length(), 0);
    list.push_back(123);
    EXPECT_EQ(list.length(), 1);
    int value;
    ASSERT_TRUE(list.get(0, value));
    ASSERT_EQ(value, 123);
}

//test lenght and count
TEST(LIST, list_elements) {
    List list;
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);
    EXPECT_EQ(list.length(), 3);    //3 elements
    EXPECT_EQ(list.length(), list.count());  //lenght same as count
}

//Testing insert of list node
TEST(LIST, list_push_back) {
    List list;
    EXPECT_EQ(list.length(), 0);
    list.push_back(123);
    EXPECT_EQ(list.length(), 1);
    int value;
    ASSERT_TRUE(list.get(0, value));
    ASSERT_EQ(value, 123);
}

//Tesing prepend and append
TEST(LIST, list_prepend) {
    List list;
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);
    list.push_front(-9999);
    EXPECT_EQ(list.length(), 4);
    int value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, -9999);
}

//Tesing prepend and append
TEST(LIST, list_append) {
    List list;
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);
    list.push_back(9999);
    EXPECT_EQ(list.length(), 4);
    int value;
    ASSERT_TRUE(list.get(3, value));
    EXPECT_EQ(value, 9999);
}

//Testing get value stored in list node
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

//Testing insert and remove at zero
TEST(LIST, remove_element_last_node) {
    List list;
    //remove no elements
    list.remove(0);
    EXPECT_EQ(list.length(), 0);

    //insert exactly one element
    list.push_back(123);
    EXPECT_EQ(list.length(), 1);
    list.remove(0);
    EXPECT_EQ(list.length(), 0);
}

//Testing insert and remove multiple
TEST(LIST, remove_element) {
    List list;
    // remove no elements
    list.remove(0);
    EXPECT_EQ(list.length(), 0);

    //adding more than one then remove
    list.push_front(100);
    list.push_back(200);
    list.push_back(300);
    list.push_back(400);
    list.push_back(500);

    EXPECT_EQ(list.length(), 5);
    list.remove(0); //first
    list.remove(list.length()-1); //last
    list.remove(1);
    EXPECT_EQ(list.length(), 2);
    int value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 200);
    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 400);
}

//Testing of print
TEST(ListTest, PrintToStream) {
    List list;
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);

    std::ostringstream oss;
    list.printToStream(oss);

    EXPECT_EQ(oss.str(), "100\n200\n300\n");
}

//Testing of printReverse
TEST(ListTest, PrintReverseToStream) {
    List list;
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);

    std::ostringstream oss;
    list.printReverseToStream(oss);

    EXPECT_EQ(oss.str(), "300\n200\n100\n");
}