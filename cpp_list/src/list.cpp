#include "list.hpp"
#include "ListIterator.hpp"
#include <stdlib.h>
#include <stdio.h>

template<typename T>

List<T>::List()
{
    first = nullptr;
    last = nullptr;
}


template<typename T>
bool List<T>::get(unsigned int index, T& val)
{
    ListNode<T>* node = this->first;
    for(int i=0; i<index; i++)
    {
        if(node==nullptr){
            return false;
        }
        node = node->next;
    }
    val=node->value;
    return true;
}
template<typename T>
void List<T>::push_back(T value)
{
    ListNode<T>* node = this->first;
    if(node==nullptr)
    {
        //ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        ListNode<T>* newNode = new ListNode<T>;
        if(newNode==nullptr) exit(1);
        newNode->value = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        this->last = newNode;
        this->first = newNode;
        return;
    }
    while(node->next!=nullptr)
    {
        node=node->next;
    }
    
    //ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    ListNode<T>* newNode = new ListNode<T>;
    if(newNode==nullptr) exit(1);
    newNode->value = value;
    newNode->prev = this->last;
    newNode->next=nullptr;
    this->last->next = newNode;
    this->last = newNode;
    return;
}
template<typename T>
List<T>::~List()
{
    while(length() > 0)
    {
        remove(0);
    }
}
template<typename T>
void List<T>::remove(unsigned int index)
{
    ListNode<T>* node = this->first;
    if(this->first == nullptr){
    return;
    }

    if(index == 0)
    {
        this->first = node->next;
        if(this->first != nullptr)
        {
            this->first->prev = nullptr;
        }  
        else
        {
            this->last = nullptr;
        }
        //free(node);
        delete node;
        node = nullptr;
        return;
    }


    for(int i=0;i<index-1;i++)
    {
        if(node->next==nullptr) return;
        node = node->next;
    }
    if(node->prev!=nullptr){
        node->prev->next=node->next;
    }
    else {
        this->first = node->next;
    }

    if(node->next==nullptr)
    {
        this->last=node->prev;
    }
    else {
        node->next->prev=node->prev;
    }
    delete node;
    node = nullptr;
    return;
}
template<typename T>
void List<T>::print()
{
    for(ListNode<T>* node = this->first; node!=nullptr; node = node->next)
    {
        int value; 
        printf("%i, ",node->value);
    }
}
template<typename T>
void List<T>::print_reverse()
{
    for(ListNode<T>* node = this->last; node!=nullptr; node = node->prev)
    {
        int value; 
        printf("%i, ",node->value);
    }
}
template<typename T>
unsigned int List<T>::length()
{
    unsigned int len=0;
    for(ListNode<T>* i=this->first; i!=nullptr; i=i->next)
    {
        len++;
    }
    return len;
}
template<typename T>
ListIterator<T> List<T>::begin(){
    return ListIterator<T>(first);
}
template<typename T>
ListIterator<T> List<T>::end(){
    return ListIterator<T>(nullptr);
}

template class List<int>;