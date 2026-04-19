#include "list.hpp"
#include <vector> 
#include <gtest/gtest.h>



TEST(LIST, get_on_empty) {

    List<int> list;
    int value;
    ASSERT_FALSE(list.get(0, value)); 
}

TEST(LIST, get_first_and_last) {
    List<int> list;
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);

    int value;

    // erstes Element
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 100);

    // letztes Element
    ASSERT_TRUE(list.get(2, value));
    EXPECT_EQ(value, 300);
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

TEST(LIST, remove_head_last_and_middle) {

    List<int> list;
    std::vector<int> ref; 

    // liste füllen
    for(int i = 1; i <= 10; i++) {
        list.push_back(i);
        ref.push_back(i);
    }
    // mehrere kritische Operationen
    list.remove(0);              // remove head
    ref.erase(ref.begin());  
    
    list.remove(list.length()-1); // remove tail
    ref.pop_back();

    list.remove(3);                // remove middle
    ref.erase(ref.begin() + 3);

    list.remove(1);                 // nochmal middle
    ref.erase(ref.begin() + 1);

    // 🔍 1. Länge prüfen
    ASSERT_EQ(list.length(), ref.size());

    // 🔍 2. komplette Traversierung prüfen
    int value;
    for (int i = 0; i < ref.size(); i++) {
        ASSERT_TRUE(list.get(i, value));
        EXPECT_EQ(value, ref[i]);
    }

    // 🔍 3. keine "Geisterelemente"
    EXPECT_FALSE(list.get(ref.size(), value));

    // 🔍 4. mehrfaches Durchlaufen (findet instabile Verkettung)
    for (int round = 0; round < 3; round++) {
        for (int i = 0; i < ref.size(); i++) {
            ASSERT_TRUE(list.get(i, value));
            EXPECT_EQ(value, ref[i]);
        }
    }
    
}
