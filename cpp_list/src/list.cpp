#include <iostream>
#include <cstdio>
#include <cstdlib>

template<typename T>
List<T>::List() {
    first = nullptr;
    last = nullptr;
    count_ = 0;
}

/**
 * maybe should be called getValue ?
 * @param index of node requested value
 * @param value contains value of the node with index
 * @return true if index is valid and node found, false when index not in list
 */
template<typename T>
bool List<T>::get(unsigned int index, T& val) const {
    if (count_ == 0) {
        return false;
    }
    if (index >= count_) {
        return false;
    }
    ListNode<T> *node = nullptr;
    this->getNode(index, node);
    val = node->value;
    return true;
}

/**
 *
 * @param index of node requested
 * @param node contains node with index requested
 * @return true if index is valid and node found, false when index not in list
 */
template<typename T>
bool List<T>::getNode(unsigned int index, ListNode<T> *&node) const {
    if (index > this->count() - 1) {
        return false;
    }
    unsigned int currentSize = this->count();
    ListNode<T> *currentNode = first;
    if (index < currentSize / 2) {
        //split search by looking into index then search from first or from last
        for (unsigned int i = 0; i < index; i++) {
            if (currentNode == nullptr) {
                return false;
            }
            currentNode = currentNode->next;
        }
    } else {
        currentNode = last;;
        for (unsigned int i = currentSize - 1; i > index; i--) {
            if (currentNode == nullptr) {
                return false;
            }
            currentNode = currentNode->prev;
        }
    }
    node = currentNode;
    return true;
}

/**
 * gets count_ property
 * @return count of nodes in list
 */
template<typename T>
unsigned int List<T>::count() const {
    return count_;
}

/**
 *
 * @param value to be added at end of list
 */
template<typename T>
void List<T>::push_back(T value) {
    if (this->first == nullptr) {
        this->first = new ListNode<T>{value, nullptr, nullptr};
        this->last = this->first;
        count_ = 1;
        return;
    }
    ListNode<T> *newNode = new ListNode<T>{value, nullptr, this->last};
    this->last->next = newNode;
    this->last = newNode;
    count_++;
}


/**
 *
 * @param value to be added at beginning of list
 */
template<typename T>
void List<T>::push_front(T value) {
    if (this->first == nullptr) {
        this->first = new ListNode<T>{value, nullptr, nullptr};
        this->last = this->first;
        count_ = 1;
        return;
    }
    ListNode<T> *newNode = new ListNode<T>{value, this->first, nullptr};
    this->first->prev = newNode;
    this->first = newNode;
    count_++;
}

template<typename T>
List<T>::~List() {
    while(length() > 0) {
        remove(0);
    }
}

/**
 *
 * @param index where node shall be inserted
 * @param value to be inserted at position of index
 */
template<typename T>
void List<T>::insert(unsigned int index, T& value) {
    if (this->first == nullptr) {
        this->first = new ListNode<T>{value, nullptr, nullptr};
        this->last = this->first;
        count_ = 1;
        return;
    }
    if (index == 0) {
        //add at the beginning
        push_front(value);
        return;
    }
    if (index == count_) {
        //add at the end -> should be out of index but implemented anyway
        push_back(value);
        return;
    }
    //insert in the middle
    ListNode<T> *insertionNode = nullptr;
    if (this->getNode(index - 1, insertionNode)) {
        if (insertionNode != nullptr) {
            ListNode<T> *newNode = new ListNode<T>{value, insertionNode->next, insertionNode};
            insertionNode->next->prev = newNode;
            insertionNode->next = newNode;
            count_++;
        }
    }
}

/**
 *
 * @param index of node to be removed from the list
 */
template<typename T>
void List<T>::remove(unsigned int index) {
    //no list nodes or index invalid
    if (!first || index >= count_) {
        //no node to remove
        return;
    }
    //get node
    ListNode<T> *node = nullptr;
    if (!getNode(index, node) || !node) {
        //no node or node is null
        return;
    }
    if (node->prev != nullptr) {
        node->prev->next = node->next; //might be nullptr if last element is removed
    } else {
        first = node->next; //first node
    }
    if (node->next != nullptr) {
        node->next->prev = node->prev;
    } else {
        last = node->prev; //last node
    }
    delete node;
    node = nullptr;
    count_--;
}


/**
 *
 * @param stream prints values to stream
 */
template<typename T>
void List<T>::printToStream(std::ostream &stream) const {
    for (ListNode<T> *currentNode = this->first; currentNode != nullptr; currentNode = currentNode->next) {
        stream << currentNode->value << "\n";
    }
}

/**
 *
 * @param stream as print but reversed
 */
 template<typename T>
void List<T>::printReverseToStream(std::ostream &stream) const {
    for (ListNode<T> *currentNode = this->last; currentNode != nullptr; currentNode = currentNode->prev) {
        stream << currentNode->value << "\n";
    }
}

template<typename T>
void List<T>::print() const {
    printToStream(std::cout);
}

template<typename T>
void List<T>::printReverse() const {
    printReverseToStream(std::cout);
}

template<typename T>
unsigned int List<T>::length() {
    unsigned int len = 0;
    for (ListNode<T>* i = this->first; i != nullptr; i = i->next) {
        len++;
    }
    return len;
}

template<typename T>
ListIterator<T> List<T>::begin() {
    return ListIterator(first);
}

template<typename T>
ListIterator<T> List<T>::end() {
    return ListIterator<T>(nullptr);
}

template<typename T>
ListReverse_Iterator<T> List<T>::rbegin() {
    return ListReverse_Iterator<T>(last);
}

template<typename T>
ListReverse_Iterator<T> List<T>::rend() {
    return ListReverse_Iterator<T>(nullptr);
}
