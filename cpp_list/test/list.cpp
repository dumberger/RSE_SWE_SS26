#include "list.hpp"
#include <gtest/gtest.h>

TEST(LIST, insert_element) {
    List list;

    EXPECT_EQ(list.length(), 0);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.length(), 3); //EXPECT I expect this value but if something else is returned, the test go futher 

    int value = 0;
    ASSERT_TRUE(list.get(2, value)); 
    ASSERT_EQ(value, 3); //ASSERT I expect this value but if something else is returned, the test will stop here
}