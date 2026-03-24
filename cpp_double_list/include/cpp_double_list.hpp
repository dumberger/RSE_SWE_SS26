#pragma once
#include <stdlib.h>

class List
{
    public:
        List();
        ~List();
        bool get(unsigned int index, int &val);
        void push_back(int value);
        void remove(unsigned int index);
        unsigned int length();
        void print();
        void print_reverse();
    private:
        struct ListNode {
            int value;
            struct ListNode* next;
            struct ListNode* prev;
        };

        ListNode* first;
        ListNode* last;
};
