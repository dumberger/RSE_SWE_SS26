#pragma once

template<typename T>
struct ListNode {
    int value;
    struct ListNode* next;
    struct ListNode* prev;
};