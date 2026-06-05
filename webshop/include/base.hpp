#pragma once

#include <iostream>

class Base {
public:
    virtual void whoami() { std::cout << "I am Base, my counter is " << internal_counter++ << std::endl;} //virtual let's to override in derivated. "Override" is not neededs
protected: 
    int  internal_counter = 0;
};