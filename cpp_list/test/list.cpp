#include <gtest/gtest.h>
#include "list.hpp"

// Test 1: Leere Liste
TEST(ListTest, EmptyListHasLengthZero) {
    List myList;
    EXPECT_EQ(0, myList.length());
}

// Test 2: Gleiche Zahlen
TEST(ListTest, IdenticalNumbers) {
    List myList;
    myList.push_back(42);
    myList.push_back(42);
    myList.push_back(42);
    
    EXPECT_EQ(3, myList.length()); 
    
    int val = 0;
    myList.get(0, val);
    EXPECT_EQ(42, val);
}

// Test 3: Verschiedene Zahlen
TEST(ListTest, DifferentNumbers) {
    List myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    
    int val = 0;
    myList.get(1, val);
    EXPECT_EQ(20, val); 
}

// Test 4: Element entfernen
TEST(ListTest, RemoveElement) {
    List myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    
    myList.remove(1); 
    
    EXPECT_EQ(2, myList.length());
    
    int val = 0;
    myList.get(1, val);
    EXPECT_EQ(3, val); 
}

// Test 5: Aus leerer Liste entfernen
TEST(ListTest, RemoveFromEmptyList) {
    List myList;
    myList.remove(0); 
    EXPECT_EQ(0, myList.length());
}