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

TEST(LIST, get_last_index) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    int value;
    ASSERT_TRUE(list.get(2, value));
    EXPECT_EQ(value, 30);
}

TEST(LIST, get_false_index) {
    List<int> list;
    list.push_back(20);
    list.push_back(30);
    int value;
    ASSERT_FALSE(list.get(2, value));
}

TEST(LIST, remove_element) {
    List<int> list;
    list.push_back(22);
    list.remove(0);
    EXPECT_EQ(list.length(), 0);
    int value;
    ASSERT_FALSE(list.get(0, value));
}

TEST(LIST, remove_first) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    list.remove(0);
    EXPECT_EQ(list.length(), 2);

    int value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 20);

    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 30);

    ASSERT_FALSE(list.get(2, value));

}

TEST(LIST, remove_middle) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    list.remove(1);
    EXPECT_EQ(list.length(), 2);

    int value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 10);

    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 30);

    ASSERT_FALSE(list.get(2, value));

}

TEST(LIST, remove_last) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    list.remove(2);
    EXPECT_EQ(list.length(), 2);

    int value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 10);

    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 20);

    ASSERT_FALSE(list.get(2, value));
}

TEST(LIST, remove_empty_index) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list.length(), 3);
    list.remove(5);
    EXPECT_EQ(list.length(), 3);

    int value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 10);

    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 20);

    ASSERT_TRUE(list.get(2, value));
    EXPECT_EQ(value, 30);

    ASSERT_FALSE(list.get(3, value));
}

TEST(LIST, push_back_after_remove) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);

    list.remove(0);
    EXPECT_EQ(list.length(), 1);
    list.push_back(30);
    EXPECT_EQ(list.length(), 2);

    int value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 20);

    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 30);

    ASSERT_FALSE(list.get(2, value));
}

TEST(LIST, push_back_after_empty) {
    List<int> list;
    list.push_back(10);

    list.remove(0);
    EXPECT_EQ(list.length(), 0);
    list.push_back(20);

    EXPECT_EQ(list.length(), 1);

    int value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 20);

    ASSERT_FALSE(list.get(1, value));
}

TEST(LIST, remove_one_by_one) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list.length(), 3);
    list.remove(0);
    EXPECT_EQ(list.length(), 2);
    list.remove(0);
    EXPECT_EQ(list.length(), 1);
    list.remove(0);

    EXPECT_EQ(list.length(), 0);

    int value;
    ASSERT_FALSE(list.get(0, value));
}

TEST(LIST, print_output) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    //von Konsole lesen laut ChatGpt mit CaptureStdout
    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10\n20\n30\n");
}

TEST(LIST, print_reverse_output) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    testing::internal::CaptureStdout();
    list.print_reverse();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "30\n20\n10\n");
}