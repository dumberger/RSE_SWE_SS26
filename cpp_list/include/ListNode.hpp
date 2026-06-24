#pragma once

template<typename T> 
struct ListNode
{
    T value;
    ListNode<T>* prev;
    ListNode<T>* next;
};
