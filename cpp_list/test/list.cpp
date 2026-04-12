#include "../include/list.hpp"
#include <gtest/gtest.h>



TEST(List, get_on_emty){
    List<int> list;
    int value;
    ASSERT_FALSE(list.get(0,value));
}


TEST(list, insert_element){
    List<int> list;
    EXPECT_EQ(list.length(), 0); // Expect erwarten und wenns nicht funktioniert mache ich weiter
    list.push_back(123);
    EXPECT_EQ(list.length(), 1);
    int value;
    ASSERT_TRUE(list.get(0,value)) ;
    ASSERT_EQ(value, 123); // Assert erwarten und wenns nicht funktioniert bricht er ab
}

//#include "list.hpp"

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
