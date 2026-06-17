#include "../include/singelton.hpp"
#include <iostream>

int main()
{
    Singelton& s = Singelton::getInstance(); 
    s.set(5);
    const Singelton& a = Singelton::getInstance(); 
    s.set(10);
    
    std::cout << a << std::endl;

    return 0;
}