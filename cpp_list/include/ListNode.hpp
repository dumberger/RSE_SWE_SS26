#pragma once

template <typename T>

struct ListNode {
    T value;
    ListNode<T>* next;
    ListNode<T>* prev;
};  
