#pragma once

#include <iostream>

class Base {
public:
    virtual void whoami() { std::cout << "i am Base, my counter is " << internal_counter++ << std::endl;}
protected:
    int internal_counter = 0;
};