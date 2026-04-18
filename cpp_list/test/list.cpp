#include "../include/list.hpp"
#include <gtest/gtest.h>

// get() Tests
TEST(LIST, get_on_empty) {
  List<int> list;
  int value;
  ASSERT_FALSE(list.get(0, value));
}

TEST(LIST, get_single_element) {
  List<int> list;
  list.push_back(123);
  int value;
  ASSERT_TRUE(list.get(0, value));
  ASSERT_EQ(value, 123);
}

TEST(LIST, get_multiple_elements) {
  List<int> list;
  list.push_back(123);
  list.push_back(456);
  int value;
  ASSERT_TRUE(list.get(0, value));
  ASSERT_EQ(value, 123);
  ASSERT_TRUE(list.get(1, value));
  ASSERT_EQ(value, 456);
}

TEST(LIST, get_out_of_bounds) {
  List<int> list;
  list.push_back(123);
  int value;
  ASSERT_FALSE(list.get(1, value));
}

// length() Tests
TEST(LIST, length_on_empty) {
  List<int> list;
  ASSERT_EQ(list.length(), 0);
}

TEST(LIST, length_after_inserts) {
  List<int> list;
  list.push_back(123);
  list.push_back(456);
  ASSERT_EQ(list.length(), 2);
}

// push_back() Tests
TEST(LIST, insert_element) {
  List<int> list;
  EXPECT_EQ(list.length(), 0);
  list.push_back(123);
  EXPECT_EQ(list.length(), 1);
  int value;
  ASSERT_TRUE(list.get(0, value));
  ASSERT_EQ(value, 123);
}

TEST(LIST, insert_multiple_elements) {
  List<int> list;
  EXPECT_EQ(list.length(), 0);
  list.push_back(123);
  list.push_back(456);
  EXPECT_EQ(list.length(), 2);
  int value;
  ASSERT_TRUE(list.get(0, value));
  ASSERT_EQ(value, 123);
  ASSERT_TRUE(list.get(1, value));
  ASSERT_EQ(value, 456);
}

// remove() Tests
TEST(LIST, remove_single_element) {
  List<int> list;
  list.push_back(123);
  EXPECT_EQ(list.length(), 1);
  list.remove(0);
  ASSERT_EQ(list.length(), 0);
}

TEST(LIST, remove_multiple_elements) {
  List<int> list;
  list.push_back(123);
  list.push_back(456);
  EXPECT_EQ(list.length(), 2);
  list.remove(0);
  EXPECT_EQ(list.length(), 1);
  int value;
  ASSERT_TRUE(list.get(0, value));
  ASSERT_EQ(value, 456);
  list.remove(0);
  EXPECT_EQ(list.length(), 0);
}

TEST(LIST, remove_out_of_bounds) {
  List<int> list;
  list.push_back(123);
  EXPECT_EQ(list.length(), 1);
  list.remove(1);
  EXPECT_EQ(list.length(), 1);
  int value;
  ASSERT_TRUE(list.get(0, value));
  ASSERT_EQ(value, 123);
  ASSERT_TRUE(list.length() == 1);
}

TEST(LIST, remove_from_empty) {
  List<int> list;
  EXPECT_EQ(list.length(), 0);
  list.remove(0);
  ASSERT_EQ(list.length(), 0);
}

// print() Tests
TEST(LIST, print_empty) {
  List<int> list;
  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "");
}

TEST(LIST, print_single_element) {
  List<int> list;
  list.push_back(123);
  testing::internal::CaptureStdout();
  list.print();
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "123, ");
}

// printReverse() Tests
TEST(LIST, print_reverse_empty) {
  List<int> list;
  testing::internal::CaptureStdout();
  list.printReverse();
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "");
}

TEST(LIST, print_reverse_single_element) {
  List<int> list;
  list.push_back(123);
  testing::internal::CaptureStdout();
  list.printReverse();
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "123, ");
}