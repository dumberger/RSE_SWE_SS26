#include "list.hpp"

#include <gtest/gtest.h>

TEST(LIST, insert_element) {
  List list;
  EXPECT_EQ(list.length(), 0);
  list.push_back(123);
  EXPECT_EQ(list.length(), 1);
  int value;
  list.get(0, value);
  ASSERT_EQ(value, 123); // Expect überprüft es aber bricht nicht ab wenns fehl
                         // schlägt, ASSERT bricht ab wenns fehlschlägt
}

TEST(LIST, get_on_empty) {
  List list;
  int value;
  ASSERT_FALSE(list.get(0, value));
}