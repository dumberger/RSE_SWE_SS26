#include "../include/list.hpp"

#include <gtest/gtest.h>
#include <string>

// Eine neue Liste sollte am Anfang leer sein.
TEST(LIST, starts_empty) {
    List<int> list;

    EXPECT_EQ(list.length(), 0u);
}

// Auf einer leeren Liste darf get nichts liefern.
TEST(LIST, get_on_empty) {
    List<int> list;
    int value;
    ASSERT_FALSE(list.get(0, value));
}

// Nach einem Einfügen sollte das Element wieder auslesbar sein.
TEST(LIST, insert_element) {
    List<int> list;

    EXPECT_EQ(list.length(), 0);
    list.push_back(123);
    EXPECT_EQ(list.length(), 1);

    int value;
    ASSERT_TRUE(list.get(0, value));
    ASSERT_EQ(value, 123);
}

// Die Reihenfolge beim Anhängen mehrerer Werte muss erhalten bleiben.
TEST(LIST, insert_multiple_elements_preserves_order) {
    List<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list.length(), 3u);

    int value = 0;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 10);
    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 20);
    ASSERT_TRUE(list.get(2, value));
    EXPECT_EQ(value, 30);
}

// Ein Remove auf leerer Liste darf nichts kaputt machen.
TEST(LIST, remove_on_empty_keeps_list_empty) {
    List<int> list;

    list.remove(0);

    EXPECT_EQ(list.length(), 0u);
}

// Wenn nur ein Element da ist, muss die Liste danach wieder leer sein.
TEST(LIST, remove_first_element_from_single_element_list) {
    List<int> list;

    list.push_back(123);
    list.remove(0);

    EXPECT_EQ(list.length(), 0u);

    int value = 0;
    EXPECT_FALSE(list.get(0, value));
}

// Beim Entfernen des ersten Elements muss der Kopf korrekt weiterrutschen.
TEST(LIST, remove_first_element_updates_head) {
    List<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.remove(0);

    EXPECT_EQ(list.length(), 2u);

    int value = 0;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 20);
    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 30);
}

// Ein Element in der Mitte entfernen sollte die Lücke sauber schließen.
TEST(LIST, remove_middle_element_closes_gap) {
    List<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.remove(1);

    EXPECT_EQ(list.length(), 2u);

    int value = 0;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 10);
    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 30);
}

// Beim Entfernen des letzten Elements müssen die restlichen Werte erhalten bleiben.
TEST(LIST, remove_last_element_keeps_previous_elements) {
    List<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.remove(2);

    EXPECT_EQ(list.length(), 2u);

    int value = 0;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, 10);
    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, 20);
}

// Die Länge soll sich nach Einfügen und Entfernen korrekt ändern.
TEST(LIST, length_changes_with_insert_and_remove) {
    List<int> list;

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

// Die Liste soll als Template auch mit anderen Typen funktionieren.
TEST(LIST, works_with_string_type) {
    List<std::string> list;

    list.push_back("alpha");
    list.push_back("beta");

    std::string value;
    ASSERT_TRUE(list.get(0, value));
    EXPECT_EQ(value, "alpha");
    ASSERT_TRUE(list.get(1, value));
    EXPECT_EQ(value, "beta");
}

