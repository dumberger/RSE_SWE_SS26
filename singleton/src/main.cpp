#include "singleton.hpp"

#include<iostream>

int main(){
    Singleton& s = Singleton::getInstance();

    s.set(5);
    //std::cout << s.get() << std::endl;
    const Singleton& a = Singleton::getInstance();

    std::cout << s << std::endl;
    std::cout << a << std::endl;
    s.set(10);
    std::cout << a << std::endl;   

    return 0;
}