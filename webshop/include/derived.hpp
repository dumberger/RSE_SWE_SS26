#pragma once

#include "base.hpp"

class Derived : public Base {
public:
    void whoami() override { std::cout << "I am Derived, my counter is " << internal_counter++ << std::endl;}
    void hello() { std::cout << "Hi " << something << std::endl;}
private:
    int something;
};