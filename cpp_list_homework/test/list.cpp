#include <gtest/gtest.h>
#include "../include/list.hpp"



// Test 1: Länge der Liste
TEST(ListTest, pushAndGetLenght){
    List list;
    list.push(10);
    list.push(20);
    list.push(30);

    EXPECT_EQ(list.length(), 3);
}

// Test 2: Abrufen von Werten (Get) und Out-of-Bounds
TEST(ListTest, getNumber){
    List list;
    list.push(10);
    list.push(20);
    list.push(30);

    int value;
    // Erste Zahl am Index 0
    list.get(0, &value);
    EXPECT_EQ(value, 10);
    // Zweite Zahl am Index 1
    list.get(1, &value);
    EXPECT_EQ(value, 20);

    // Werte außerhalb der Liste
    EXPECT_FALSE(list.get(3, &value)); // Index existiert nicht

}

// neues Kommentar



// Test 3: Löschen von Elementen (Remove)
TEST(ListTest, RemoveElements) {
    List list;
    list.push(1);
    list.push(2);
    list.push(3);
    
    list.remove(1); // Lösche die die Zahl mit Index 1
    EXPECT_EQ(list.length(), 2);

}

//Test 4: Testen der Print-Funktion
TEST(ListTest, printList){
    List list;
    list.push(1);
    list.push(2);
    list.push(3);
    
    
    testing::internal::CaptureStdout(); // damit wird der Text nicht an das Terminal sondern in einen zwischenspeicher geschrieben
    list.print(); 
    // Den Text aus dem Speicher holen
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1, 2, 3, \n");
}

//Test 5: Testen der ReversePrint-Funktion
TEST(ListTest, printReverseList){
    List list;
    list.push(1);
    list.push(2);
    list.push(3);

    testing::internal::CaptureStdout();
    list.printReverse();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "3, 2, 1, \n");
}





