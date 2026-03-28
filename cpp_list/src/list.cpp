#include <ostream>
#include <cstdio>
#include <cstdlib>
#include "list.hpp"

#include <iostream>


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
    if (count_ == 0) {
        return false;
    }
    if (index >= count_) {
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
 * gets count_ property
 * @return count of nodes in list
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
    count_++;
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
    count_++;
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
            count_++;
        }
    }
}

/**
 *
 * @param index of node to be removed from the list
 */
void List::remove(unsigned int index) {
    //no list nodes or index invalid
    if (!first || index >= count_) {
        //no node to remove
        return;
    }
    //get node
    ListNode* node = nullptr;
    if (!getNode(index, node) || !node) {
        //no node or node is null
        return;
    }
        if (node -> prev != nullptr) {
            node -> prev -> next =  node -> next;    //might be nullptr if last element is removed
        } else {
            first = node->next;  //first node
        }
        if (node -> next != nullptr) {
             node -> next -> prev = node -> prev;
        } else {
            last = node -> prev;    //last node
        }
        delete node; node = nullptr;
        count_--;
}

/**
 *
 * @param stream prints values to stream
 */
void List::print(std::ostream& stream) const {
    for(ListNode* currentNode = this->first;currentNode != nullptr; currentNode = currentNode->next) {
        stream << currentNode -> value << "\n";
    }
}

/**
 *
 * @param stream as print but reversed
 */
void List::printReverse(std::ostream& stream) const {
    for(ListNode* currentNode = this->last;currentNode != nullptr; currentNode = currentNode->prev) {
        stream << currentNode -> value << "\n";
    }
}

void List::print() const {
    print(std::cout);
}

void List::printReverse() const {
    printReverse(std::cout);
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

ListIterator List::begin() {
    return ListIterator(first);
}

ListIterator List::end() {
    return ListIterator(nullptr);
}

ListReverse_Iterator List::rbegin() {
    return ListReverse_Iterator(last);
}
ListReverse_Iterator List::rend() {
    return ListReverse_Iterator(nullptr);
}