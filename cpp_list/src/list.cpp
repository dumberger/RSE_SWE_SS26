#include "list.hpp"
#include "ListIterator.hpp"
#include <stdlib.h>
#include <stdio.h>


List::List() 
{
    first = nullptr;
    last = nullptr;
}

bool List::get(unsigned int index, int& val) {
    unsigned int len = length();

    if(index >= len)
    {
        return false;
    }

    if(index <= (len / 2)){
        ListNode* node = first;
        for (int i = 0; i < index; i++) {
            if (node == nullptr) {
                return false;
            }
            node = node->next;
        }
        val = node->value;
        return true;
    }

    else if(index > (len / 2)) {
        ListNode* node = last;
        for (int i = len - 1; i > index; i--) {
            if (node == nullptr) {
                return false;
            }
            node = node->prev;
        }
        val = node->value;
        return true;
    }

    else{
        return false;
    }
}

void List::push_back(int value) {
    ListNode* node = this->last;

    if (node == nullptr) {
        ListNode* newNode = new ListNode;
        
        // !!! In Cpp new cannot return a nullptr, will notice std::bad_alloc
        // unless exceptions are turned off 
        // https://stackoverflow.com/questions/3389420/will-new-operator-return-null#:~:text=On%20a%20standards-conforming%20C%2B%2B,return%20NULL%20if%20allocation%20fails).
        // Segment removed everywhere else !!!

        /*
        if (newNode == nullptr) {
            exit(1);
        }
        */
        newNode->value = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        this->first = newNode;
        this->last = newNode;
        return;
    }

    ListNode* newNode = new ListNode;

    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = node;
    node->next = newNode;
    this->last = newNode;
    return;
}

List::~List() {
    ListNode* node = this->first;
    ListNode* tmp;

    while(node != nullptr){
        tmp = node->next;
        delete node;
        node = tmp;  
    }
    first = nullptr;
    last = nullptr;
}

void List::remove(unsigned int index){

    unsigned int len = length();

    if (this->first == nullptr || this->last == nullptr ||index >= len) {
        return;
    }

    ListNode* node;
    ListNode* tmp;

    if(index == 0) {
        node = this->first;
        this->first = node->next;
        if (this->first != nullptr) {
            this->first->prev = nullptr;
        }
        delete node; 
        node = nullptr;

        if(this->first == nullptr){
            this->last = nullptr;
        }

        return;
    }

    if(index == len-1) {
        node = this->last;
        this->last = node->prev;
        if (this->last != nullptr) {
            this->last->next = nullptr;
        }
        delete node;
        node = nullptr;

        if(this->last == nullptr){
            this->first = nullptr;
        }

        return;
    }

    node = this->first;
    for (int i = 0; i < index - 1; i++) {
        node = node->next;
        if (node->next == nullptr) {
            return;
        }
    }
    tmp = node->next;
    node->next = tmp->next;
    node->next->prev = tmp->prev;
    delete tmp;
    tmp = nullptr;
    return;
}

void List::print(){
    for(auto i = begin(); i != end(); ++i)
    {
        printf("%i, ", *i);
    }

    printf("\n");
}

void List::printReverse(){

    for(auto i = ListIterator(last); i != end(); --i)
    {
        printf("%i, ", *i);
    }
    
    printf("\n");
}

unsigned int List::length() {
    unsigned int len = 0;
    for (auto i = begin(); i != end(); ++i) {
        len++;
    }
    return len;
}

ListIterator List::begin(){
    return ListIterator(first);
}

ListIterator List::end(){
    return ListIterator(nullptr);
}