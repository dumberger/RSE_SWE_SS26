#include "base.hpp"
#include "derived.hpp"

int main() {
    Derived derived;
    Derived *p_derived = &derived;

    p_derived->whoami();
    p_derived->hello();

    Base *p_base = new Base(); 

    p_base->whoami();

    Derived *maybe = dynamic_cast<Derived*>(p_base);
    if(maybe == nullptr) {
        std::cout << "can't convert\n";
    } else {
        maybe->hello();
    }
    
    return 0;
}

/*class Person; Name, Age, ..., getIdentification
class Student : public Person; getIdentification -> Matrickelnummer

verify(const Person& p)*/

/*
Webshop -> Produkte
Produkte:
    - FixedPricedProducts -> price per piece
    - WeightBasedProduct -> price per kg
    - LengthBasedProduct -> price per meter

user can select multiple objects from a catalog and put them into his basked
at checkout shipping costs will be calculated based on weight: 5€ + 0.20€ per kg
*/