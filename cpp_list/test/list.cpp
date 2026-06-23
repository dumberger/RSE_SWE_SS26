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
    List<int> list;
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);
    EXPECT_EQ(list.length(), 3);    //3 elements
    EXPECT_EQ(list.length(), list.count());  //lenght same as count
}

//Testing insert of list node
TEST(LIST, list_push_back) {
    List<int> list;
    EXPECT_EQ(list.length(), 0);
    list.push_back(123);
    EXPECT_EQ(list.length(), 1);
    int value;
    ASSERT_TRUE(list.get(0, value));
    ASSERT_EQ(value, 123);
}

//Tesing prepend and append
TEST(LIST, list_push_front_multi) {
    List<int> list;
    int values[4] = {0, 0, 0, 0};
    list.push_front(100);
    list.push_front(200);
    list.push_front(300);
    list.push_front(-9999);
    EXPECT_EQ(list.length(), 4);
    list.get(0, values[0]);
    ASSERT_TRUE(values[0] == -9999);
    list.get(1, values[1]);
    ASSERT_TRUE(values[1] == 300);
    list.get(2, values[2]);
    ASSERT_TRUE(values[2] == 200);
    list.get(3, values[3]);
    ASSERT_TRUE(values[3] == 100);
}

//Tesing prepend and append
TEST(LIST, list_push_back_multi) {
    List<int> list;
    int values[4] = {0, 0, 0, 0};
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);
    list.push_back(9999);
    EXPECT_EQ(list.length(), 4);
    list.get(0, values[0]);
    ASSERT_TRUE(values[0] == 100);
    list.get(1, values[1]);
    ASSERT_TRUE(values[1] == 200);
    list.get(2, values[2]);
    ASSERT_TRUE(values[2] == 300);
    list.get(3, values[3]);
    ASSERT_TRUE(values[3] == 9999);
}

//Testing get value stored in list node
TEST(LIST, get_value) {
    List<int> list;
    int value;
    //get from list
    int insertion_value = 9999;
    list.push_back(insertion_value);
    ASSERT_TRUE(list.get(0, value));
    ASSERT_EQ(value, insertion_value);
}

TEST(LIST, get_value_empty) {
    List<int> list;
    int value;
    //get from no elements
    ASSERT_FALSE(list.get(0, value));
}

//Testing insert and remove at zero
TEST(LIST, remove_element_empty) {
    List<int> list;
    //remove no elements
    list.remove(0);
    EXPECT_EQ(list.length(), 0);
}

//Testing insert and remove at zero
TEST(LIST, remove_element_last_node) {
    List<int> list;
    //insert exactly one element
    list.push_back(123);
    EXPECT_EQ(list.length(), 1);
    list.remove(0);
    EXPECT_EQ(list.length(), 0);
}

//Testing insert and remove multiple
TEST(LIST, remove_element) {
    int value;
    List<int> list;
    //adding more
    list.push_front(100);
    list.push_back(99);
    list.push_back(98);
    list.push_back(97);
    list.push_back(96);
    EXPECT_EQ(list.length(), 5);

    list.remove(0); //first
    EXPECT_EQ(list.length(), 4);
    //check values
    list.get(0, value);
    ASSERT_TRUE(value == 99);
    list.get(1, value);
    ASSERT_TRUE(value == 98);
    list.get(2, value);
    ASSERT_TRUE(value == 97);
    list.get(3, value);
    ASSERT_TRUE(value == 96);

    list.remove(list.length()-1); //last
    EXPECT_EQ(list.length(), 3);
    value = 0;
    //check values
    list.get(0, value);
    ASSERT_TRUE(value == 99);
    list.get(1, value);
    ASSERT_TRUE(value == 98);
    list.get(2, value);
    ASSERT_TRUE(value == 97);

    list.remove(1); //middle
    EXPECT_EQ(list.length(), 2);
    value = 0;
    //check values
    list.get(0, value);
    ASSERT_TRUE(value == 99);
    list.get(1, value);
    ASSERT_TRUE(value == 97);
}

//Testing of print
TEST(ListTest, PrintToStream) {
    List<int> list;
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);

    std::ostringstream oss;
    list.printToStream(oss);

    EXPECT_EQ(oss.str(), "100\n200\n300\n");
}

//Testing of printReverse
TEST(ListTest, PrintReverseToStream) {
    List<int> list;
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);

    std::ostringstream oss;
    list.printReverseToStream(oss);

    EXPECT_EQ(oss.str(), "300\n200\n100\n");
}