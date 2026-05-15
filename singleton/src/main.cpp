#include "singleton.hpp"
#include <iostream>

int main() {
    Singleton s;

    s.set(5);
    std::cout << s.get() << std::endl;

    return 0;
}