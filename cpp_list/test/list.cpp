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

TEST(LIST, push_back_multiple) {
    List list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list.length(), 3u);

    int value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 10);

    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 20);

    ASSERT_TRUE(list.get(2, value));
    EXPECT_EQ(value, 30);
}

TEST(LIST, get_out_of_range) {
    List<int> list;
    list.push_back(5);

    int value;
    EXPECT_FALSE(list.get(1, value));
    EXPECT_FALSE(list.get(100, value));
}

TEST(LIST, remove_from_empty_list) {
    List<int> list;
    list.remove(0);
    EXPECT_EQ(list.length(), 0u);
}

TEST(LIST, remove_only_element) {
    List<int> list;
    list.push_back(99);

    list.remove(0);

    EXPECT_EQ(list.length(), 0u);

    int value;
    EXPECT_FALSE(list.get(0, value));
}

TEST(LIST, remove_first_element) {
    List<int> list;
    list.push_back(11);
    list.push_back(22);
    list.push_back(33);

    list.remove(0);

    EXPECT_EQ(list.length(), 2u);

    int value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 22);

    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 33);
}

TEST(LIST, remove_middle_element) {
    List<int> list;
    list.push_back(11);
    list.push_back(22);
    list.push_back(33);

    list.remove(1);

    EXPECT_EQ(list.length(), 2u);

    int value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 11);

    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 33);
}

TEST(LIST, remove_last_element) {
    List<int> list;
    list.push_back(11);
    list.push_back(22);
    list.push_back(33);

    list.remove(2);

    EXPECT_EQ(list.length(), 2u);

    int value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 11);

    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 22);
}

TEST(LIST, remove_out_of_range) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    list.remove(10);

    EXPECT_EQ(list.length(), 2u);

    int value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 1);

    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 2);
}

TEST(LIST, length_after_multiple_operations) {
    List<int> list;
    EXPECT_EQ(list.length(), 0u);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list.length(), 3u);

    list.remove(1);
    EXPECT_EQ(list.length(), 2u);

    list.remove(0);
    EXPECT_EQ(list.length(), 1u);

    list.remove(0);
    EXPECT_EQ(list.length(), 0u);
}

TEST(LIST, print_output) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1, 2, 3, ");
}

TEST(LIST, print_reverse_output) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    testing::internal::CaptureStdout();
    list.print_reverse();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "3, 2, 1, ");
}

TEST(LIST, print_on_empty_list) {
    List<int> list;

    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "");
}

TEST(LIST, print_reverse_on_empty_list) {
    List<int> list;

    testing::internal::CaptureStdout();
    list.print_reverse();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "");
}