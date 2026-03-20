//
// Created by madtic on 06.03.26.
//

#include <cstdio>
#include <cstdlib>
#include "list.hpp"


List::List() {
    first = nullptr;
    last = nullptr;
    count_ = 0;
}

List::~List() = default;

/**
 * maybe should be called getValue ?
 * @param index of node requested value
 * @param value contains value of the node with index
 * @return true if index is valid and node found, false when index not in list
 */
bool List::get(unsigned int index, int& value) const {
    if (index > this->count() -1) {
        return false;
    }
    ListNode* node = nullptr;
    this->getNode(index, node);
    value = node ->value;
    return true;
}

/**
 *
 * @param index of node requested
 * @param node contains node with index requested
 * @return true if index is valid and node found, false when index not in list
 */
bool List::getNode(unsigned int index, ListNode *&node) const {
    if (index > this->count() -1) {
        return false;
    }
    unsigned int currentSize = this->count();
    ListNode* currentNode = first;
    if (index < currentSize/2) {                    //split search by looking into index then search from first or from last
        for (unsigned int i = 0; i < index; i++) {
            if(currentNode == nullptr) {
                return false;
            }
            currentNode = currentNode -> next;
        }
    }
    else {
        currentNode = last;;
        for (unsigned int i = currentSize -1; i > index; i--) {
            if(currentNode == nullptr) {
                return false;
            }
            currentNode = currentNode -> prev;
        }
    }
    node = currentNode;
    return true;
}

/**
 * gets size_ property
 * @return size of list
 */
unsigned int List::count() const {
    return count_;
}

/**
 *
 * @param value to be added at end of list
 */
void List::append(int value) {
    if (this -> first == nullptr) {
        this -> first = new ListNode{value, nullptr, nullptr};
        this -> last = this -> first;
        count_ = 1;
        return;
    }
    ListNode* newNode = new ListNode{value, nullptr, this -> last};
    this -> last -> next = newNode;
    this -> last = newNode;
    count_ = count_ + 1;
}

/**
 *
 * @param value to be added at beginning of list
 */
void List::prepend(int value) {
    if (this -> first == nullptr) {
        this -> first = new ListNode{value, nullptr, nullptr};
        this -> last = this -> first;
        count_ = 1;
        return;
    }
    ListNode* newNode = new ListNode{value, this -> first, nullptr};
    this -> first -> prev = newNode;
    this -> first = newNode;
    count_ = count_ + 1;
}

/**
 *
 * @param index where node shall be inserted
 * @param value to be inserted at position of index
 */
void List::insert(unsigned int index, int value) {
    if (this -> first == nullptr) {
        this -> first = new ListNode {value, nullptr, nullptr};
        this -> last = this -> first;
        count_ = 1;
        return;
    }
    if (index == 0) {   //add at the beginning
        prepend(value);
        return;
    }
    if (index == count_) {   //add at the end -> should be out of index but implemented anyway
        append(value);
        return;
    }
    //insert in the middle
    ListNode* insertionNode = nullptr;
    if (this -> getNode(index-1, insertionNode)) {
        if (insertionNode != nullptr) {
            ListNode* newNode = new ListNode {value, insertionNode -> next, insertionNode};
            insertionNode -> next -> prev = newNode;
            insertionNode -> next = newNode;
            count_ = count_ + 1;
        }
    }
}

/**
 *
 * @param index of node to be removed from the list
 */
void List::remove(unsigned int index) {
    //no list nodes
    if (this -> first == nullptr) {
        //no node to remove
        return;
    }

    ListNode* node = nullptr;
    //only one node
    if (index == 0) {
        node = this -> first;
        this -> first = node -> next;
        node -> next -> prev = nullptr;
        delete(node); node = nullptr;
        count_ = count_ -1;
        return;
    }
    if (index == count_ -1) {
        node = this -> last;
        this -> last = node -> prev;
        node -> prev -> next = nullptr;
        delete(node); node = nullptr;
        count_ = count_ -1;
        return;
    }
    if (getNode(index, node)) {
        if (node != nullptr) {
            if (node -> prev != nullptr) {
                node -> prev -> next =  node -> next;    //might be nullptr if last element is removed
            }
            if (node -> next != nullptr) {
                 node -> next -> prev = node -> prev;
            }
            delete node; node = nullptr;
            count_ = count_ -1;
        }
    }
}

void List::print() const {
    for(ListNode* currentNode = this->first;currentNode != nullptr; currentNode = currentNode->next) {
        printf("%i\n", currentNode -> value);
    }
}



void List::printReverse() const {
    for(ListNode* currentNode = this->last;currentNode != nullptr; currentNode = currentNode->prev) {
        printf("%i\n", currentNode -> value);
    }
}

void List::push_back(int value) {
    append(value);
}

unsigned int List::length() {
    unsigned int len = 0;
    for (ListNode* i = this->first; i != nullptr; i = i->next) {
        len++;
    }
    return len;
}