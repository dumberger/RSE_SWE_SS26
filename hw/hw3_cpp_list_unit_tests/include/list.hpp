/* list.hpp */
#pragma once

/// @brief This file contains the declaration of the List class, which implements a doubly linked list data structure.
class List
{
private:
    /// @brief The ListNode struct represents a node in the doubly linked list, containing an integer value and pointers to the next and previous nodes.
    struct ListNode
    {
        int value;
        struct ListNode* next;
        struct ListNode* prev;
    };

    /// @brief Pointer to first node (nullptr if list is empty)
    ListNode* first;
    /// @brief Pointer to last node (nullptr if list is empty)
    ListNode* last;

public:
    /// @brief Constructs a new List object, initializing the first and last pointers to nullptr.
    List();
    /// @brief Destroys the List object, deallocating all nodes in the list to prevent memory leaks.
    ~List();

    /// @brief Retrieves the value at the specified index.
    /// @param index The index of the element to retrieve.
    /// @param value A reference to store the retrieved value.
    /// @return True if the index is valid, false otherwise.
    bool get(unsigned int index, int& value);

    /// @brief Adds a new element to the end of the list.
    /// @param value The value to add.
    void push_back(int value);

    /// @brief Removes the element at the specified index.
    /// @param index The index of the element to remove.
    void remove(unsigned int index);

    /// @brief Prints the values in the list from first to last.
    void print();

    /// @brief Prints the values in the list from last to first.
    void printReverse();

    /// @brief Returns the number of elements in the list.
    /// @return The number of elements in the list.
    unsigned int length();
};