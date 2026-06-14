#include "singleton.hpp"
#include <iostream>

int main(){
    Singleton& s = Singleton::getInstance(); // if const here then s.item() takes also const. Otherwise not const
    s.set(5);
    const Singleton& a = Singleton::getInstance();
    //s.set(5);
    //s.item() = 5;
    s.set(10);
    //std::cout << a << std::endl;

    return 0;
}