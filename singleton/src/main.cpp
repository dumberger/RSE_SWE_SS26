#include "singleton.hpp"

#include <iostream>

int main() {
    Singleton& s = Singleton::getInstance();
    s.set(5);

    const Singleton& a = Singleton::getInstance();

    s.set(10);
    //s.item() = 5;
    std::cout << a << std::endl;

    return 0;
}