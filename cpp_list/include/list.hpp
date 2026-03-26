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

    bool get(unsigned int index, int& val);
    void push_back(int value);
    void remove(unsigned int index);
    void print();
    unsigned int length();
    void print_reverse();
};
