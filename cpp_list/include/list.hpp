// defines the list class

#pragma once
#include <stdbool.h> 

class List
{
private:

    struct ListNode {
        int value;
        struct ListNode* prev;
        struct ListNode* next; // star says that this is a pointer
    };

// typedef needs 2 elements. First part is with {} and the second is List
// alias -> means we can use already declared typedef just by writing the name (for example ListNode instead of struct ListNode_t)

    ListNode* first;
    ListNode* last;

public:
    List();
    ~List();


    bool get(unsigned int index, int& out_value);

    // unsigned is a type modifier that changes how integer values are stored and interpreted. 
    // Signed (default): Can represent both positive and negative numbers. Uses one bit for the sign, leaving fewer bits for the value.
    // Unsigned: Can only represent non-negative numbers (0 and positive). All bits are used for the value, so it can store larger positive numbers.

    void pushBack(int value);
    void _delete();
    void remove(unsigned int index);
    void print();
    void printReverse();
    unsigned int length();
};
