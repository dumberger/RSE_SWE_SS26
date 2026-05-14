#pragma once

template<typename T>
struct ListNode{
    T value;
    struct ListNode* next;
    struct ListNode* prev;
};
