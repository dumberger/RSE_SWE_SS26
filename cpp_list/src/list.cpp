#include <stdlib.h>
#include <iostream>

template<typename T>
List<T>::List() 
{
    first = nullptr;
    last = nullptr;
}

template<typename T>
bool List<T>::get(unsigned int index, T& val) {
    unsigned int len = length();

    if(index >= len)
    {
        return false;
    }

    if(index <= (len / 2)){
        ListNode<T>* node = first;
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
        ListNode<T>* node = last;
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

template<typename T>
void List<T>::push_back(T value) {
    ListNode<T>* node = this->last;

    if (node == nullptr) {
        ListNode<T>* newNode = new ListNode<T>;
        
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

    ListNode<T>* newNode = new ListNode<T>;

    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = node;
    node->next = newNode;
    this->last = newNode;
    return;
}

template<typename T>
List<T>::~List() {
    ListNode<T>* node = this->first;
    ListNode<T>* tmp;

    while(node != nullptr){
        tmp = node->next;
        delete node;
        node = tmp;  
    }
    first = nullptr;
    last = nullptr;
}

template<typename T>
void List<T>::remove(unsigned int index){

    unsigned int len = length();

    if (this->first == nullptr || this->last == nullptr ||index >= len) {
        return;
    }

    ListNode<T>* node;
    ListNode<T>* tmp;

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

template<typename T>
void List<T>::print(){
    for(auto i = begin(); i != end(); ++i)
    {
        printf("%i, ", *i);
    }

    printf("\n");
}
template<typename T>
void List<T>::printReverse(){

    for(auto i = ListIterator(last); i != end(); --i)
    {
        printf("%i, ", *i);
    }
    
    printf("\n");
}

template<typename T>
unsigned int List<T>::length() {
    unsigned int len = 0;
    for (auto i = begin(); i != end(); ++i) {
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
