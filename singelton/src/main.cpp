#include "singelton.hpp"
#include <iostream>
#include <ostream>

int main(){
    Singelton& s = Singelton::getInstance(); //Wenn eine Constante const (darf nicht verändert werden) -> muss ein Konstruktor {} hinzugefügt werden
    //Konstruktor {} initialisiert variablen standardmäßig mit 0 -> default Konstruktor

    s.set(5);
    Singelton& a = Singelton::getInstance();
    
    s.set(10);
    //s.item = 5;
    std::cout<<a<<std::endl;
    return 0;
}