#pragma once

#include "base.hpp"

class Derived : public Base {
public:
    void whoami() override { std::cout << "i am Derived, my counter is " << internal_counter++ << std::endl;}
    void hello() {std::cout << something << std::endl;}
private:
    int something = 0;
};