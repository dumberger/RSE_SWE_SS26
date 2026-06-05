#include "singleton.hpp"
#include <iostream>

const int& Singleton::get() const
{
    //item = 5; const members can not be changed
    return _item;
}
// void Singleton::set(const int& value)
// {
//     _item = value;
// }

int& Singleton::item(){
    return _item;
}

const int& Singleton::item() const{
    return _item;
}

Singleton& Singleton::getInstance(){
    static Singleton s{}; // static means  here (not the same as in hpp) that it exists only once. 
    // This means, it can not be created twice. It will return always the first created 
    return s;
}

std::iostream& operator<<(std::iostream& os, const Singleton& s){
// const because we don't want to change anything in Singleton, but we are changing iostream
    os << s._item;
    return os;

}