#pragma once

class List
{
    private:
        struct ListNode {
            int value;
            struct ListNode* next;
            struct ListNode* prev;
        };

        ListNode* first;
        ListNode* last;

    public:
        List();
        ~List();
        ListNode* getFirst();
        ListNode* getLast();
        bool get(unsigned int index, int& val);
        void push_back(int value);
        void remove(unsigned int index);
        int print(); // returns how many items are written
        int print(int* array);
        int printReversed();
        int printReversed(int* array);
        unsigned int length();
};
