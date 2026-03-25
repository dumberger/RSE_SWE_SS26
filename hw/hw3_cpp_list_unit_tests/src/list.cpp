/* list.cpp */
#include "../include/list.hpp"
#include <stdlib.h>

    /* *********** */
    /* constructor */
    /* *********** */
List::List()
{
    first = nullptr;
    last = nullptr;
}


    /* ********** */
    /* destructor */
    /* ********** */
List::~List()
{
    // get the first node
    ListNode* node = this->first;
    // delete all nodes
    while (node != nullptr)
    {
        ListNode* next = node->next;
        delete node;
        node = next;
    }

    // set first and last to nullptr
    this->first = nullptr;
    this->last = nullptr;

    return;
}


    /* **************** */
    /* public functions */
    /* **************** */

// get the value at the given index
bool List::get(unsigned int index, int& val) const
{    
    ListNode* node = this->first;
    // get the node at the given index
    for (unsigned int i = 0; i < index; i++)
    {
        if (node == nullptr)
        {
            return false;
        }

        node = node->next;
    }

    // if the index is equal the length of the list the node is nullptr
    if (node == nullptr)
    {
        return false;
    }

    // return the value of the node
    val = node->value;
    return true;
}

// add a new value to the end of the list
void List::push_back(int value)
{
    // create a new node
    ListNode* newNode = new ListNode;
    // check if malloc succeeded
    if (newNode == nullptr)
    {
        exit(1);
    }

    // get the actual last node
    ListNode* nodeLastAct = this->last;
    // set new node values
    newNode->value = value;
    newNode->next = nullptr;

    // if the list is empty the first node is the new node
    if (nodeLastAct == nullptr)
    {                    
        this->first = newNode;
        newNode->prev = nullptr;
    }
    else // the next node of the actual last node is the new node
    {
        nodeLastAct->next = newNode;
        newNode->prev = nodeLastAct;
    }

    this->last = newNode;

    return;
}

// remove the node at the given index
bool List::remove(unsigned int index)
{
    ListNode* node = this->first;
    // if the first node is nullptr the list is empty
    if (node == nullptr)
    {        
        return false;
    }
    
    // if the first node is the one to remove
    if (index == 0)
    {
        this->first = node->next;
        if (this->first != nullptr)
        {
            this->first->prev = nullptr;
        }
        else 
        {
            this->last = nullptr;        
        }

        delete node; node = nullptr;
        return true;
    }

    // get the node before the one to remove
    for (unsigned int i = 0; i < index - 1; i++)
    {
        if (node->next == nullptr) 
        {           
            return false;
        }
        node = node->next;
    }

    // get the next node which one is the one to remove
    ListNode* tmp = node->next;
    //if temp is a nullptr -> out of index and return
    if (tmp == nullptr)
    {
        return false;
    }
    node->next = tmp->next;
    if (tmp->next != nullptr)
    {
        tmp->next->prev = node;
    }
    else
    {
        this->last = node;
    }
    delete tmp; tmp = nullptr;

    return true;
}

// print the list from first to last
void List::print(std::ostream& os) const
{
    for (ListNode* i = this->first; i != nullptr; i = i->next)
    {
        if (i->next == nullptr)
        {
            os << i->value;
        }
        else
        {
            os << i->value << ", ";
        }        
    }
    return;
}

// print the list from last to first
void List::printReverse(std::ostream& os) const
{
    for (ListNode* i = this->last; i != nullptr; i = i->prev)
    {
        if (i->prev == nullptr)
        {
            os << i->value;
        }
        else
        {
            os << i->value << ", ";
        }        
    }
    return;
}

// return the number of elements in the list
unsigned int List::length() const
{
    unsigned int len = 0;
    for (ListNode* i = this->first; i != nullptr; i = i->next)
    {
        len++;
    }
    return len;
}